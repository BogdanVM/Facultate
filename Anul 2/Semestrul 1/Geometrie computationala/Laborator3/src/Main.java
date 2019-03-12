import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {


    public static List<Punct> readPoints() throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new FileReader("points.txt"));
        String line = null;

        List<Punct> points = new ArrayList<>();
        int label = 1;

        while ((line = bufferedReader.readLine()) != null) {
            String[] values = line.split(" ");

            int x = Integer.parseInt(values[0]);
            int y = Integer.parseInt(values[1]);
            points.add(new Punct(x, y, label++));
        }

        return points;
    }

    public static void computeIntersection() throws IOException {
        List<Punct> puncte = readPoints();

        Segment A1A2, A3A4;
        A1A2 = new Segment(puncte.get(0), puncte.get(1));
        A3A4 = new Segment(puncte.get(2), puncte.get(3));

        int[] determinanti = new int[3];
        determinanti[0] = A1A2.getA() * A3A4.getB() - A3A4.getA() * A1A2.getB(); // determinantul principal
        determinanti[1] = A1A2.getB() * A3A4.getC() - A3A4.getB() * A1A2.getC(); // minorul 1
        determinanti[2] = A1A2.getA() * A3A4.getC() - A3A4.getA() * A1A2.getC(); // minorul 2

        if (determinanti[0] == 0) {
            /* Daca determinantul principal e 0, fie dreptele coincid, fie intersectia segmentelor e vida */

            if (determinanti[1] == 0 && determinanti[2] == 0) {
                Collections.sort(puncte, new SortByX());

                /*for (Punct pct : puncte) {
                    System.out.println(pct.getX() + " " + pct.getY() + " " + pct.getLabel());
                }*/

                if (puncte.get(1).getX() < puncte.get(2).getX()) {
                    System.out.format("Dreptele coincid. Intersectia segmentelor este [A%dA%d]%n",
                            puncte.get(1).getLabel(), puncte.get(2).getLabel());
                } else {
                    System.out.println("Dreptele coincid, dar intersectia segmentelor este vida");
                }
            } else {
                System.out.println("Intersectia segmentelor este vida.");
            }

        } else {
            double xIntersect = (double)((-A1A2.getC() * A3A4.getB()) - (A1A2.getB() * (-A3A4.getC()))) / determinanti[0];
            double yIntersect = (double)((A1A2.getA() * (-A3A4.getC())) - ((-A1A2.getC()) * A3A4.getA())) / determinanti[0];

            boolean check = false;

            if (xIntersect > A1A2.getMinX() && xIntersect > A3A4.getMinX() && xIntersect < A1A2.getMaxX() &&
                    xIntersect < A3A4.getMaxX()) {

                if (yIntersect > A1A2.getMinY() && yIntersect > A3A4.getMinY() && yIntersect < A1A2.getMaxY()
                    && yIntersect < A3A4.getMaxY()) {

                    check = true;
                }
            }

            if (!check) {
                System.out.println("Dreptele se intersecteaza, dar segmentele nu");
            } else {
                System.out.format("Intersectia segmentelor este punctul: (%.2f, %.2f)%n", xIntersect, yIntersect);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        computeIntersection();
    }
}
