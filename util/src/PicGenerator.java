import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.image.WritableRaster;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Vector;

/**
 * Created by kitsu.
 * This file is part of mapgen in package PACKAGE_NAME.
 */
public class PicGenerator {

    public static void main(String[] args) throws IOException {
        File f = new File(System.getProperty("user.dir"));
        for (File s : f.listFiles()) {
            if (!s.isDirectory() && s.getName().matches(".*\\.(map)$"))
                generate(s);
        }
    }

    public static void generate(File map) throws IOException {

        DataInputStream dis = new DataInputStream(new FileInputStream(map));

        int width = 0, k = 0;
        Vector<Tile> tiles = new Vector<Tile>();
        boolean isDefinedSize = false;

        while (dis.available() > 0) {
            char c = dis.readChar();
            if (c == '\n') {
                if (!isDefinedSize) {
                    width = k;
                    isDefinedSize = true;
                }
            } else
                tiles.add(Tile.getBySym(c));

            if (!isDefinedSize) k++;
        }
        int height = tiles.size() / width;

        final BufferedImage bufferedImage = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        final WritableRaster raster = bufferedImage.getRaster();
        int[] a = new int[3];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                Tile t = tiles.get(j + i*width);
                a[0] = t.r; a[1] = t.g; a[2] = t.b;
                raster.setPixel(j, i, a);
            }
        }
        bufferedImage.setData(raster);

        ImageIO.write(bufferedImage, "png", new File(map.getName() + ".png"));
    }
}
