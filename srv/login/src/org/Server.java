package org;

import java.io.DataInputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Arrays;

/**
 * Created by kitsu.
 * This file is part of Servers in package org.
 */
class Server {

    public void launch() throws IOException {
        ServerSocket serverSocket = new ServerSocket(Consts.LoginPort);

        while(true) {
            Socket clientSocket = serverSocket.accept();
            DataInputStream in = new DataInputStream(clientSocket.getInputStream());
            for (int i = 0; i < 10; i++) {
                try {
                    if (in.available() == Consts.LoginMsgSnd)
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

            byte[] b = new byte[Consts.LoginMsgSnd];
            in.read(b);
            String nick = new String(Arrays.copyOfRange(b, 1, Consts.LoginNickSize));
            String pass = new String(Arrays.copyOfRange(b, 129, Consts.LoginMsgSnd));
            if (b[0] == Consts.LoginFlag) {
                DB.getInstance().
            }
            in.close();
        }
    }
}
