public class Punct {
    private int x, y, label;

    public Punct(int x, int y, int label) {
        this.x = x;
        this.y = y;
        this.label = label;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getLabel() {
        return label;
    }

    public static double distance(Punct p1, Punct p2) {
        return Math.sqrt((p2.getX() - p1.getX()) * (p2.getX() - p1.getX()) +
                (p2.getY() - p1.getY()) * (p2.getY() - p1.getY()));
    }
}
