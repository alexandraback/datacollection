import java.io.*;
import java.util.Scanner;

public class CodeJamR1A2015A {
    public static Scanner in;
    public static PrintWriter out;

    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter(new BufferedOutputStream(new FileOutputStream(
                new File("output.txt"))));
        int totalCases = in.nextInt();
        in.nextLine();
        for (int i = 1; i <= totalCases; i++) findSolution(i);
        out.close();
        System.err.println("Completed");
    }

    static void findSolution(int caseNumber) {
        int n = in.nextInt();
        int oldM=0;
        int sum1=0;
        int sum2=0;
        int mostDiff=0;
        int[] a = new int[n];
        a[0] = in.nextInt();
        oldM=a[0];
        for (int i=1; i<n-1; i++){
            a[i] = in.nextInt();
            if (a[i]<oldM) sum1+=(oldM-a[i]);
            if ((oldM-a[i])>mostDiff) mostDiff=(oldM-a[i]);
            oldM=a[i];
        }
        int m = in.nextInt();
        if (m<oldM) sum1 += (oldM - m);
        if ((oldM-m)>mostDiff) mostDiff=(oldM-m);
        for (int i=0;i<n-1;i++){
            if (a[i]<mostDiff) sum2+=a[i];
            else sum2+=mostDiff;
        }
        out.println("Case #" + caseNumber + ": "+ sum1+" "+sum2);
    }
}