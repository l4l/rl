package org;

import java.io.IOException;

/**
 * Created by kitsu.
 * This file is part of LoginServer in package org.
 */
public class LoginServer {

    public static void main(String[] args) throws Exception {
        while (true) {
            try {
                Server server = new Server();
                server.launch();
            } catch (IOException e) {
                Logger.INSTANCE.log("LoginServer", e);
            }
        }
    }


}