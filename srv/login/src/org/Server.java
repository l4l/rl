package org;

import com.sun.xml.internal.messaging.saaj.util.ByteOutputStream;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;
import java.util.UUID;

/**
 * Created by kitsu.
 * This file is part of Servers in package org.
 */
class Server {

    ServerSocket serverSocket;
    Socket listener;

    private static final int TIMEOUT = 10;

    public Server() {
        try {
            serverSocket = new ServerSocket(Consts.LOGIN_PORT);
        } catch (IOException e) {
            Logger.INSTANCE.log("LoginServer", e);
            System.err.println("Port wrong bind");
            System.exit(-1);
        }
    }

    public void launch() {

        while(true) {
            try {
                listener = serverSocket.accept();
            } catch (IOException e) {
                Logger.INSTANCE.log("LoginServer", e);
                System.err.println("Socket wrong bind");
                System.exit(-1);
            }
            byte b[] = read(Consts.LOGIN_MSG_SND);
            if (b == null)
                continue;

            for (byte c: b)
                System.out.print((char) c);
            System.out.println();

            String nick = new String(Arrays.copyOfRange(b, 1,
                    Consts.LOGIN_NICK_SIZE));
            nick = nick.substring(0, nick.indexOf("\0"));
            String pass = new String(Arrays.copyOfRange(b,
                    Consts.LOGIN_NICK_SIZE + 1,
                    Consts.LOGIN_NICK_SIZE + Consts.LOGIN_PASS_SIZE + 1));
            pass = pass.substring(0, pass.indexOf("\0"));


            StringBuilder builder = new StringBuilder("");

            if (b[0] == Consts.LOGIN_FLAG) {
                int id = DB.getInstance().getId(nick, pass);
                String token = UUID.randomUUID().toString();

                if (id != -1 && DB.getInstance().addToken(id, token))
                    builder.append((Consts.LOGIN_OK | Consts.IS_TOKEN))
                           .append(token);
                else
                    builder.append(Consts.LOGIN_BAD);

            } else
                builder.append(DB.getInstance().insert(nick, pass) ?
                        Consts.LOGIN_OK : Consts.LOGIN_BAD);

            write(builder.toString());
        }
    }

    private byte[] read(int size) {

        byte data[] = new byte[size];
        try {
            InputStream in = listener.getInputStream();
            for (int i = 0; i < TIMEOUT; i++) {
                try {
                    if (in.available() >= size)
                        break;
                    else
                        Thread.sleep(50);
                } catch (InterruptedException e) {
                    Logger.INSTANCE.log("LoginServer", e);
                }
                if (i == TIMEOUT - 1) {
                    Logger.INSTANCE.log("LoginServer", "Time Exceed");
                    return null;
                }
            }
            in.read(data);
        } catch (IOException e) {
            Logger.INSTANCE.log("LoginServerInput", e);
            return null;
        }

        return data;
    }

    private boolean write(String msg) {
        try (OutputStream out = listener.getOutputStream()) {

            out.write(msg.getBytes("UTF-8"));
            return true;
        } catch (IOException e) {
            Logger.INSTANCE.log("LoginServerOutput", e);
            return false;
        }
    }
}
