public class Segment {
    private Punct capat1, capat2;

    private int a, b, c;
    private int maxX, minX;
    private int maxY, minY;

    public Segment(Punct capat1, Punct capat2) {
        this.capat1 = capat1;
        this.capat2 = capat2;

        a = capat2.getY() - capat1.getY();
        b = capat1.getX() - capat2.getX();
        c = (capat2.getX() * capat1.getY()) - (capat2.getY() * capat1.getX());

        maxX = Math.max(capat1.getX(), capat2.getX());
        minX = Math.min(capat1.getX(), capat2.getX());
        maxY = Math.max(capat1.getY(), capat2.getY());
        minY = Math.min(capat1.getY(), capat2.getY());
    }

    public Punct getCapat1() {
        return capat1;
    }

    public void setCapat1(Punct capat1) {
        this.capat1 = capat1;
    }

    public Punct getCapat2() {
        return capat2;
    }

    public void setCapat2(Punct capat2) {
        this.capat2 = capat2;
    }

    public int getA() {
        return a;
    }

    public int getB() {
        return b;
    }

    public int getC() {
        return c;
    }

    public int getMaxX() {
        return maxX;
    }

    public int getMinX() {
        return minX;
    }

    public int getMaxY() {
        return maxY;
    }

    public int getMinY() {
        return minY;
    }


}
