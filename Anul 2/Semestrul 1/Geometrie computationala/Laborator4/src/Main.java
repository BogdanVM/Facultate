import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
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

    public static void checkPointPosition(List<Punct> puncte) {
        Vector A2A3 = new Vector(puncte.get(1), puncte.get(2));
        Vector A2A1 = new Vector(puncte.get(1), puncte.get(0));
        Vector A4A3 = new Vector(puncte.get(3), puncte.get(2));
        Vector A4A1 = new Vector(puncte.get(3), puncte.get(0));

        double angleA2Rad = Math.acos((Vector.scalarProduct(A2A3, A2A1) / Vector.moduleProduct(A2A3, A2A1)));
        double angleA4Rad = Math.acos((Vector.scalarProduct(A4A3, A4A1) / Vector.moduleProduct(A4A3, A4A1)));

        double angleA2 = Math.toDegrees(angleA2Rad);
        double angleA4 = Math.toDegrees(angleA4Rad);

        System.out.println("Unghiul A2 are valoarea " + angleA2);
        System.out.println("Unghiul A4 are valoarea " + angleA4);
        System.out.println();
        //System.out.println(A4A3.scalarProduct(A4A1) + " " + A2A3.scalarProduct(A2A1));

        if (angleA2 + angleA4 > 179 && angleA2 + angleA4 < 181) {
            System.out.println("Punctul A4 se afla pe cercul circumscris triunghiului A1A2A3");
        } else if (angleA2 + angleA4 > 180) {
            System.out.println("Punctul A4 se afla in interiorul cercului circumscris triunghiului A1A2A3");
        } else {
            System.out.println("Punctul A4 se afla in exteriorul cercului circumscris triunghiului A1A2A3");
        }
    }

    public static boolean isCircumscriptible(List<Punct> puncte) {
        /* A1A2 + A3A4 */
        double leftSide = Punct.distance(puncte.get(0), puncte.get(1)) +
                Punct.distance(puncte.get(2), puncte.get(3));

        /* A2A3 + A1A4 */
        double rightSide = Punct.distance(puncte.get(1), puncte.get(2)) +
                Punct.distance(puncte.get(0), puncte.get(3));

        return leftSide == rightSide;
    }

    public static void main(String[] args) throws IOException {
        List<Punct> puncte = readPoints();

        /* Check the fourth point's position relative to the triangle formed by the other three */
        checkPointPosition(puncte);

        /* Check if the quadrilateral formed by the four points is circumscriptible */
        if (isCircumscriptible(puncte)) {
            System.out.println("Patrulaterul format de punctele A1, A2, A3 si A4 este circumscriptibil");
        } else {
            System.out.println("Patrulaterul format de punctele A1, A2, A3 si A4 nu este circumscriptibil");
        }
    }
}
