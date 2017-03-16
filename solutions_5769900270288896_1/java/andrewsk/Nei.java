import java.util.Scanner;

public class Nei {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int n = sc.nextInt();

            int unh;
            unh = Math.min(unh1(x, y, n), unh2(x, y, n));
            if (x * y == n) {
                unh = ((x - 1) * y + (y - 1) * x);
                if (unh != Math.min(unh1(x, y, n), unh2(x, y, n))) {
                    System.out.println("FAIL! Case " + (i + 1));
                }

            }

            System.out.println("Case #" + (i + 1) + ": " + unh);
        }
    }

    private static int unh1(int x, int y, int n) {
        int sum = 0;
        int s = x * y;
        int half = (s + 1) / 2;
        if (n <= half) {
            return 0;
        }

        n -= half;

        int min = Math.min(x, y);
        int max = Math.max(x, y);

        if (min == 1) { // small
            sum += n * 2;
            if (max % 2 == 0) {
                sum--;
            }
            return sum;
        } else { // normal
            int edges;
            if ((x % 2 == 1) && (y % 2 == 1)) {
                edges = 0;
            } else {
                edges = 2;
            }

            if (n > edges) {
                n -= edges;
                sum += edges * 2;
            } else {
                sum += n * 2;
                return sum;
            }

            int sides;
            if ((x % 2 == 1) && (y % 2 == 1)) {
                sides = x / 2 + x / 2 + y / 2 + y / 2 - edges - edges;
            } else {
                sides = x + y - edges - edges;
            }
            if (n > sides) {
                n -= sides;
                sum += sides * 3;
            } else {
                sum += n * 3;
                return sum;
            }

            sum += n * 4;
            return sum;
        }
    }

    private static int unh2(int x, int y, int n) {
        if (((x % 2 == 1) && (y % 2 == 1)) && x > 2 && y > 2) {
            int sum = 0;
            int s = x * y;
            int half = s / 2;
            if (n <= half) {
                return 0;
            }
            n -= half;
            int edges = 4;
            if (n > edges) {
                n -= edges;
                sum += edges * 2;
            } else {
                sum += n * 2;
                return sum;
            }

            int sides = ((x + 1) / 2) + ((x + 1) / 2) + ((y + 1) / 2)
                    + ((y + 1) / 2) - edges - edges;
            if (n > sides) {
                n -= sides;
                sum += sides * 3;
            } else {
                sum += n * 3;
                return sum;
            }

            sum += n * 4;
            return sum;

        } else {
            return Integer.MAX_VALUE;
        }

    }
}
