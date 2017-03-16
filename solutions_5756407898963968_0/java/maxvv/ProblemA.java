
import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemA {

    public static void main(String[] args) throws Exception {

        String inFile = "A-small-attempt0.in";
        String outFile = "A-small-attempt0.out";

        Scanner sc = new Scanner(new File(inFile));
        PrintWriter writer = new PrintWriter(outFile);
        int numTest = sc.nextInt();
        for (int test = 1; test <= numTest; test++) {
            writer.println("Case #" + test + ": " + solution(sc));
        }
        writer.close();
    }

    private static String solution(Scanner sc) {
        String res = "";
        int firstRow = sc.nextInt();
        HashSet<Integer> firstArrangement = new HashSet<>();
        sc.nextLine();
        for (int i = 1; i < firstRow; i++) {
            sc.nextLine();
        }
        for (int i = 0; i < 4; i++) {
            firstArrangement.add(sc.nextInt());
        }
        sc.nextLine();
        for (int i = firstRow + 1; i <= 4; i++) {
            sc.nextLine();
        }

        int secondRow = sc.nextInt();
        HashSet<Integer> secondArrangement = new HashSet<>();
        sc.nextLine();
        for (int i = 1; i < secondRow; i++) {
            sc.nextLine();
        }
        for (int i = 0; i < 4; i++) {
            secondArrangement.add(sc.nextInt());
        }
        sc.nextLine();
        for (int i = secondRow + 1; i <= 4; i++) {
            sc.nextLine();
        }

        int n = 0;
        int last=0;
        for (Integer c : firstArrangement) {
            if (secondArrangement.contains(c)) {
                n++;
                last=c;
            }
        }
        if (n==1) {
            res=""+last;            
        } else if (n==0) {
            res="Volunteer cheated!";
        } else {
            res="Bad magician!";
        }
        return res;
    }

}
