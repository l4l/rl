package org;

import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.sql.*;

/**
 * Created by kitsu.
 * This file is part of LoginServer in package org.
 */
public final class DB {
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
        String user = "", pas = "";
        try (DataInputStream in = new DataInputStream(
                new FileInputStream(new File(System.getProperty("user.dir") +
                        File.separator + "data")))) {

            while (in.available() > 0) {
                String tmp = in.readLine();
                if (tmp.matches("^([Nn]ame)|([Uu]ser).*"))
                    user = tmp.split("=", 2)[1];
                else if (tmp.matches("^[Pp]assword.*"))
                    pas = tmp.split("=", 2)[1];
            }
            con = DriverManager.getConnection("jdbc:mysql://localhost/test?" +
                    "user=" + user + "&password=" + pas + "&database=users");
            con.prepareStatement("use users;").execute();
        } catch (Exception e) {
            Logger.INSTANCE.log("DB", e);
            System.exit(-1);
        }
    }

    public boolean insert(String user, String password) {
        try {
            return con.prepareStatement("INSERT INTO accounts " +
                    "(User, Password) VALUES(\"" +
                    user + "\", \"" + password + "\")").execute();
        } catch (SQLException e) {
            return false;
        }
    }

    public boolean addToken(int id, String token) {
        try {
            return !con.prepareStatement("INSERT INTO token " +
                    "(Token, ID, Expiry) VALUES(\"" +
                    token + "\", " +
                    id + ", " +
                    (3600L + System.currentTimeMillis() / 1000L) + ")")
                    .execute();
        } catch (SQLException e) {
            return false;
        }
    }

    public int getId(String user, String pass) {
        try {
            ResultSet set = con.prepareStatement("SELECT ID FROM accounts " +
                    "WHERE User=\"" + user + "\" AND Password=\"" + pass + "\"").executeQuery();
            if (set.next())
                return set.getInt("ID");
            else
                return -1;
        } catch (SQLException e) {
            return -1;
        }
    } 
}
