public class Punct {
    private int x, y;
    private int label;

    public Punct(int x, int y, int label) {
        this.x = x;
        this.y = y;
        this.label = label;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getLabel() {
        return label;
    }

    public void setLabel(int label) {
        this.label = label;
    }

}
