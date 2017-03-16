import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("A-small-attempt0.in"));
        //Scanner in = new Scanner(new File("A-small.in"));
        PrintWriter out = new PrintWriter("out.txt");
        int t = in.nextInt();
        for (int cases = 1; cases <= t; cases++) {
            int n = in.nextInt();
            Pair[] a = new Pair[n];
            int sum = 0;
            for (int i = 0; i < n; i++) {
                a[i] = new Pair(in.nextInt(), (char)((int)'A' + i));
                sum += a[i].number;
            }
            out.print("Case #" + cases + ": ");
            Arrays.sort(a);
            int ind = n - 1;
            while (sum > 0) {
                String res = "";
                if (a[0].number == sum / 2 && sum % 2 == 0) {
                    a[0].number--;
                    sum--;
                    res += a[0].party;
                    if (a.length > 1 && a[1].number == a[0].number + 1) {
                        a[1].number--;
                        sum--;
                        res += a[1].party;
                    }
                } else {
                    while (a[ind].number == 0) {
                        ind--;
                    }
                    sum--;
                    a[ind].number--;
                    res += a[ind].party;
                }
                out.print(res + " ");
            }
            out.println();
        }
        out.close();
    }
}

class Pair implements Comparable<Pair> {
    int number;
    char party;

    Pair(int number, char party) {
        this.number = number;
        this.party = party;
    }

    @Override
    public int compareTo(Pair pair) {
        return -Integer.compare(this.number, pair.number);
    }
}