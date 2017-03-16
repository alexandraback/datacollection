package rounds.qualification.Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B {

    long n;
    int[] input;

    static Scanner in;
    static PrintStream out;

    public static void main(String[] args) throws FileNotFoundException {
        out = new PrintStream("out.txt");
        in = new Scanner(new File(args[0]));

        int N = in.nextInt();
        in.nextLine();

        for (int i = 0; i < N; i++) {
            runTestCase(i + 1);
        }
    }

    private static void runTestCase(int id) {
        int B = in.nextInt();
        long N = in.nextLong();

        int[] barbers = new int[B];

        for (int i = 0; i < B; i++) {
            barbers[i] = in.nextInt();
        }

        int solution = new B(barbers, N).solve();

        out.printf("Case #%d: %d\n", id, solution);
    }

    public B(int[] input, long n) {
        this.input = input;
        this.n = n;
    }

    int solve() {
        int[] sums = new int[input.length];
        int lcm = lcmofarray(input, 0, input.length);

        int totalPeoplePerLoop = 0;

        for (int in : input) {
            totalPeoplePerLoop += lcm / in;
        }

        n = (n - 1) % totalPeoplePerLoop + 1;

        for (int i = 0; i < n; i++) {
            int lowest = 0;
            for (int j = 1; j < sums.length; j++) {
                if (sums[j] < sums[lowest]) {
                    lowest = j;
                }
            }
            if (i == n-1) {
                return lowest + 1;
            }
            sums[lowest] += input[lowest];
        }
        return 1;
    }

    public static int gcd(int a, int b){
        if (a<b) return gcd(b,a);
        if (a%b==0) return b;
        else return gcd(b, a%b);
    }


    public static int lcm(int a, int b){
        return ((a*b)/gcd(a,b));

    }
    public static int lcmofarray(int[] arr, int start, int end){
        if ((end-start)==1) return lcm(arr[start],arr[end-1]);
        else return (lcm (arr[start], lcmofarray(arr, start+1, end)));
    }

}