import java.util.ArrayList;

public class Main {

    public static int BinarySearch(ArrayList<Integer> l, int left, int right, int x) {

        int mid;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (x == l.get(mid)) {
                return mid;
            } else if (x < l.get(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {

        ArrayList<Integer> l1 = new ArrayList<>();
        ArrayList<Integer> l2 = new ArrayList<>();

        l1.add(2);
        l1.add(4);
        l1.add(6);
        l1.add(7);
        l1.add(9);

        l2.add(2);
        l2.add(5);
        l2.add(6);
        l2.add(8);
        l2.add(9);

        ArrayList<Integer> l3 = new ArrayList<>(5);
        for (Integer l : l1) {
            int pos;
            if ((pos = BinarySearch(l2, 0, l2.size() - 1, l)) != -1) {
                l3.add(l);
            }
        }

        for (Integer l : l3) {
            System.out.println(l);
        }
    }
}
