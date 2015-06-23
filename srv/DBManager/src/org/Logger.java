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
public final class Logger {

    public boolean log(String prep, Exception e) {
        StringBuilder builder = new StringBuilder(
                "\tException: " + e.getCause() +
                "\n\tMessage: " + e.getMessage() +
                "\n\tStack trace:\n");
        for (StackTraceElement element: e.getStackTrace())
            builder.append(element.toString());
        return log(prep, builder.toString());
    }

    public boolean log(String prep, String msg) {
        String file = prep + ".log";
        File f = new File(file);
        if (!f.exists())
            try {
                f.createNewFile();
            } catch (IOException e) {
                return false;
            }
        try (FileOutputStream stream = new FileOutputStream(f)) {
            stream.write(("**********\n**********\n" +
                    "\t Time:" +
                    new SimpleDateFormat("yyyy/MM/dd HH:mm:ss")
                            .format(Calendar.getInstance().getTime()) +
                    "\n\n" + msg).getBytes());
        } catch (IOException e) {
            return false;
        }
        return true;
    }

    public static final Logger INSTANCE = new Logger();

    private Logger() {}

}
