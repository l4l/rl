/**
 * Created by kitsu.
 * This file is part of mapgen in package PACKAGE_NAME.
 */
public enum Tile {
    Rock( 33,  33,  33, '$'),
    Sand(255,  87,   0, '-'),
    Dirt(255, 136,   0, '#'),
    Snow(255, 255, 255, '*'),
    Grass( 0, 255,   0, '^'),
    Tree( 36,  64,   0, '&'),
    Water( 0, 153, 255, '0'),
    River( 0,   0, 255, 'O');

    public final int r, g, b;
    public final char sym;
    Tile (int r, int g, int b, char c) {
        this.r = r;
        this.g = g;
        this.b = b;
        sym = c;
    }

    public static Tile getByColor(int r, int g, int b) {
        Tile tiles[] = Tile.values();

        int j = 0, min = 255*255*255;
        for (int i = 0; i < tiles.length; i++) {
            Tile t = tiles[i];
            int d = Math.abs(t.r - r) + Math.abs(t.g - g) + Math.abs(t.b - b);
            if (d < min) {
                min = d;
                j = i;
            }
        }

        return tiles[j];
    }

    public static Tile getBySym(char c) {
        Tile tiles[] = Tile.values();

        for (Tile t: tiles)
            if (t.sym == c)
                return t;

        return tiles[0];
    }
}
