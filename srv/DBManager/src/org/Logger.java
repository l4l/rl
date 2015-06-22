package org;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Calendar;

/**
 * Created by kitsu.
 * This file is part of Servers in package org.
 */
public class Logger {

    public boolean log(String prep, Exception e) {
        return log(prep,
                "\tException: " + e.getCause() +
                "\n\tMessage: " + e.getMessage() +
                "\n\tStack trace:\n" + e.getStackTrace());
    }

    public boolean log(String prep, String msg) {
        String file = prep + ".log";
        File f = new File(file);
        try {
            if (!f.exists())
                f.createNewFile();
            new FileOutputStream(f).write(("**********\n**********\n" +
                    "\t Time:" +
                    new SimpleDateFormat("yyyy/MM/dd HH:mm:ss")
                    .format(Calendar.getInstance().getTime()) +
                    "\n\n" + msg).getBytes());
        } catch (IOException e) {
            return false;
        }
        return true;
    }

    public final static Logger INSTANCE = new Logger();

    private Logger() {}

}
