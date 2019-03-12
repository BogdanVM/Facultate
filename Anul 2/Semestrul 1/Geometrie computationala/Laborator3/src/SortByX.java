import java.util.Comparator;

public class SortByX implements Comparator<Punct> {

    @Override
    public int compare(Punct punct, Punct t1) {
        return punct.getX() - t1.getX();
    }
}
