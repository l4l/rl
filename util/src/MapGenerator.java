import javax.imageio.ImageIO;
import java.awt.image.Raster;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Vector;

/**
 * Created by kitsu.
 * This file is part of mapgen in package PACKAGE_NAME.
 */
public class MapGenerator {

    public static void main(String[] args) throws IOException {
        File f = new File(System.getProperty("user.dir"));
        for (File s : f.listFiles()) {
            if (!s.isDirectory() && s.getName().matches(".*\\.((png)|(jp[e]?g)|(gif)(bmp))$"))
                generate(s);
        }

    }

    public static void generate(File image) throws IOException {
        final Raster raster = ImageIO.read(image).getData();
        Vector<Tile> tiles = new Vector<Tile>();

        final int size = raster.getWidth();

        int a[] = new int[4];
        for (int i = raster.getHeight() - 1; i >= 0; i--) {
            for (int j = size - 1; j >= 0; j--) {
                raster.getPixel(j, i, a);
                tiles.add(Tile.getByColor(a[0], a[1], a[2]));
            }
        }

        int i = size;
        DataOutputStream dos = new DataOutputStream(new FileOutputStream(new File(image.getName() + ".map")));

        for (int j = tiles.size() - 1; j >= 0; j--) {
            dos.writeChar(tiles.get(j).sym);
            if (--i == 0) {
                i = size;
                dos.writeChar('\n');
            }
        }
    }
}
