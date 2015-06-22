package org;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 * Created by kitsu.
 * This file is part of LoginServer in package org.
 */
public class DB {
    static {
        try {
            Class.forName("com.mysql.jdbc.Driver").newInstance();
        } catch (Exception e) {
            System.err.print("Error driver loading.");
            System.exit(-1);
        }
    }

    private Connection con;

    private static DB instance;

    public static DB getInstance() {
        if (instance == null)
            instance = new DB();
        return instance;
    }

    private DB() {
        try {
            String user = "", pas = "";
            DataInputStream in = new DataInputStream(
                    new FileInputStream(new File(System.getProperty("user.dir") +
                            File.separator + "data")));

            while (in.available() > 0) {
                String tmp = in.readLine();
                if (tmp.matches("^([Nn]ame)|([Uu]ser).*"))
                    user = tmp.split("=", 2)[1];
                else if (tmp.matches("^[Pp]assword.*"))
                    pas = tmp.split("=", 2)[1];
            }
            con = DriverManager.getConnection("jdbc:mysql://localhost/test?" +
                    "user=" + user + "&password=" + pas + "&database=users");
        } catch (Exception e) {
            System.err.println(e.getMessage());
            System.err.println(e.getStackTrace());
            System.exit(-1);
        }
    }

    public boolean insert(String user, String password) {
        try {
            return con.prepareStatement("INSERT INTO users.accounts (Nick, Password) " +
                    "VALUES(\"" + user + "\", \"" + password + "\")").execute();
        } catch (SQLException e) {
            return false;
        }
    }

    public boolean addToken(String user, char token[]) {

    }
}
