public class Vector {
    private int A, B;
    private double module;

    public Vector(int a, int b) {
        A = a;
        B = b;
        module = Math.sqrt(A * A + B * B);
    }

    public Vector(Punct p1, Punct p2) {
        A = p2.getX() - p1.getX();
        B = p2.getY() - p1.getY();
        module = Math.sqrt(A * A + B * B);

    }

    public int getA() {
        return A;
    }

    public int getB() {
        return B;
    }

    public double getModule() {
        return module;
    }

    public static int scalarProduct(Vector v1, Vector v2) {
        return v1.getA() * v2.getA() + v1.getB() * v2.getB();
    }

    public static double moduleProduct(Vector v1, Vector v2) {
        return v1.getModule() * v2.getModule();
    }
}
