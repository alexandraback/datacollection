import java.util.Scanner;


public class GCJ2014QualA {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: %s%n", i, new GCJ2014QualA().solve(sc));
        }
    }

    private String solve(Scanner sc) throws Exception {
        int n = 4;
        int row1 = sc.nextInt() - 1;
        int[][] arr1 = new int[4][4];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr1[i][j] = sc.nextInt();
            }
        }
        int row2 = sc.nextInt() - 1;
        int[][] arr2 = new int[4][4];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr2[i][j] = sc.nextInt();
            }
        }
        
        int theCard = -1;
        for (int c1 : arr1[row1]) {
            for (int c2 : arr2[row2]) {
                if (c1 == c2) {
                    if (theCard != -1) return "Bad magician!";
                    theCard = c1;
                }
            }
        }
        if (theCard == -1) return "Volunteer cheated!";
        
        return Integer.toString(theCard);
    }
}
