package org;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;
import java.util.Comparator;
import java.util.UUID;

/**
 * Created by kitsu.
 * This file is part of Servers in package org.
 */
class Server {

    public void launch() throws IOException {
        ServerSocket serverSocket = new ServerSocket(Consts.LOGIN_PORT);

        while(true) {
            Socket clientSocket = serverSocket.accept();
            DataInputStream in = new DataInputStream(clientSocket.getInputStream());

            for (int i = 0; i < 10; i++) {
                try {
                    if (in.available() == Consts.LOGIN_MSG_SND)
                        break;
                    else
                        Thread.sleep(50);
                } catch (InterruptedException e) {
                    Logger.INSTANCE.log("LoginServer", e);
                }
                if (i == 9) {
                    Logger.INSTANCE.log("LoginServer", "Time Exceed");
                    in.close();
                    return;
                }
            }

            byte[] b = new byte[Consts.LOGIN_MSG_SND];
            in.read(b);
            String nick = new String(Arrays.copyOfRange(b, 1,
                    Consts.LOGIN_NICK_SIZE));
            String pass = new String(Arrays.copyOfRange(b,
                    Consts.LOGIN_NICK_SIZE + 1,
                    Consts.LOGIN_NICK_SIZE + Consts.LOGIN_PASS_SIZE + 1));

            PrintWriter writer = new PrintWriter(clientSocket.getOutputStream());

            if (b[0] == Consts.LOGIN_FLAG) {
                int id = DB.getInstance().getId(nick, pass);
                String token = UUID.randomUUID().toString();

                if (id != -1 && DB.getInstance().addToken(id, token))
                    writer.write((Consts.LOGIN_OK | Consts.IS_TOKEN) + token);
                else
                    writer.write(Consts.LOGIN_BAD);
            } else
                writer.write(DB.getInstance().insert(nick, pass) ?
                        Consts.LOGIN_OK : Consts.LOGIN_BAD);

            writer.close();
            in.close();
        }
    }
}
