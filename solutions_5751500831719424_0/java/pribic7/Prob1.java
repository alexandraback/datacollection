package Y2014.Round1B;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Prob1 {
    private static final String fwin = "Fegla Won";
    private static final String newLine = System.getProperty("line.separator");
    int T;
    int copy;
    BufferedWriter bw;
    {
	try {
	    bw = new BufferedWriter(new FileWriter(new File("E:\\out"
		    + System.currentTimeMillis() + ".t")));
	} catch (IOException e) {
	    // TODO Auto-generated catch block
	    e.printStackTrace();
	}
    }

    public static void main(String[] args) throws IOException {
	long b = System.currentTimeMillis();
	Prob1 f = new Prob1();
	f.do1();
	long a = System.currentTimeMillis();
	System.out.println(a - b);

    }

    private void do1() throws IOException {
	Scanner sc = new Scanner(new File("E:\\A-small-attempt0(1).in"));
	// Scanner sc = new Scanner(System.in);
	copy = sc.nextInt();
	int N = 1;
	T = copy;
	while (T-- > 0) {
	    int n = sc.nextInt();
	    String[] s = new String[n];
	    for (int i = 0; i < n; i++)
		s[i] = sc.next();
	    solve(N, n, s);
	    N++;
	}
	// TODO Auto-generated method stub
	sc.close();
	bw.close();

    }

    private void solve(int N, int n, String[] s) throws IOException {
	String a = s[0];
	String b = s[1];
	if (a.charAt(0) != b.charAt(0)) {
	    resultPrint(N, fwin);
	    return;
	}
	char c = a.charAt(0);
	int i1 = 0;
	int j1 = 0;
	int ans = 0;
	while (true) {
	    int j = i1;
	    while (j < a.length() && a.charAt(j) == c)
		j++;
	    int k = j1;
	    while (k < b.length() && b.charAt(k) == c)
		k++;
	    ans += Math.abs((j - i1) - (k - j1));
	    i1 = j;
	    j1 = k;
	    if ((i1 < a.length() && j1 < b.length() && a.charAt(i1) != b
		    .charAt(j1))
		    || (i1 >= a.length() && j1 < b.length())
		    || (i1 < a.length() && j1 >= b.length())) {
		resultPrint(N, fwin);
		return;
	    }
	    if (i1 >= a.length() || j1 > b.length())
		break;
	    c = a.charAt(i1);
	}
	resultPrint(N, ans);
    }

    public void resultPrint(int n, Object res) throws IOException {
	System.out.print("Case #" + n + ": " + res + newLine);

	/*
	 * if (n == copy) // for last output ,we don't need newLine.
	 * bw.write("Case #" + n + ": " + res); else
	 */
	bw.write("Case #" + n + ": " + res + newLine);

    }

}
