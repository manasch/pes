import java.util.*;

class Main {
    private static ArrayList<Integer> a1 = new ArrayList<Integer>();
    private static ArrayList<Integer> a2 = new ArrayList<Integer>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < m; ++i) {
            a1.add(scanner.nextInt());
        }

        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; ++i) {
            a2.add(scanner.nextInt());
        }

        scanner.nextLine();
        int target = scanner.nextInt();

        Collections.sort(a1);
        Collections.sort(a2);

        int[][] diff = new int[m][n];

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diff[i][j] = Math.abs(a1.get(i) + a2.get(j) - target);
            }
        }

        int min = diff[0][0];
        int x = 0;
        int y = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (diff[i][j] < min) {
                    min = diff[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        System.out.println("Closest pair : (" + a1.get(x) + "," + a2.get(y) + ")");
    }
}

/*
import java.util.*;

class Main {
    private static ArrayList<Integer> a1 = new ArrayList<Integer>();
    private static ArrayList<Integer> a2 = new ArrayList<Integer>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < m; ++i) {
            a1.add(scanner.nextInt());
        }

        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; ++i) {
            a2.add(scanner.nextInt());
        }

        scanner.nextLine();
        int target = scanner.nextInt();

        Collections.sort(a1);
        Collections.sort(a2);

        int res_l = 0;
        int res_r = 0;

        int l = 0;
        int r = n - 1;

        System.out.println(a1);
        System.out.println(a2);

        int diff = Integer.MAX_VALUE;
        while (l < m && r >= 0) {
            System.out.printf("Before: %d %d %d %d\n", l, r, a1.get(l), a2.get(r));
            if (Math.abs(a1.get(l) + a2.get(r) - target) < diff) {
                res_l = l;
                res_r = r;
                diff = Math.abs(a1.get(l) + a2.get(r) - target);
            }
            System.out.println(diff);
            // System.out.printf("After: %d %d %d %d\n", l, r, a1.get(l), a2.get(r));

            if (a1.get(l) + a2.get(r) > target)
                r--;
            else
                l++;
        }

        System.out.println("Closest pair : (" + a1.get(res_l) + "," + a2.get(res_r) + ")");
    }
}
*/
