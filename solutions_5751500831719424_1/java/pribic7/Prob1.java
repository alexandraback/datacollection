package Y2014.Round1B;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
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
	Scanner sc = new Scanner(new File("E:\\A-large(1).in"));
	// Scanner sc = new Scanner(System.in);
	copy = sc.nextInt();
	int N = 1;
	T = copy;
	while (T-- > 0) {
	    int n = sc.nextInt();
	    char[][] in = new char[n][];
	    for (int i = 0; i < n; i++)
		in[i] = sc.next().toCharArray();
	    solve(N, n, in);
	    N++;
	}
	// TODO Auto-generated method stub
	sc.close();
	bw.close();

    }

    private void solve(int N, int n, char[][] in) throws IOException {
	int ans = 0;
	int[] startIndex = new int[n];
	Arrays.fill(startIndex, 0);
	boolean isOver = false;
	while (!isOver) {
	    char c = in[0][startIndex[0]];
	    int[] curLen = new int[n];
	    for (int i = 0; i < n; i++) {
		int t = startIndex[i];
		while (t < in[i].length && in[i][t] == c)
		    t++;
		if (i == 0 && !isOver && t == in[0].length) {
		    isOver = true;
		}
		if (i > 0 && isOver && t != in[i].length) {
		    resultPrint(N, fwin);
		    return;
		}
		curLen[i] = t - startIndex[i];
		if (curLen[i] == 0) {
		    resultPrint(N, fwin);
		    return;
		}
		startIndex[i] = t;
	    }
	    ans += fun(curLen);
	}
	resultPrint(N, ans);
    }

    private int fun(int[] curLen) {
	Arrays.sort(curLen);
	int median = -1;
	if (curLen.length % 2 == 1)
	    median = curLen[curLen.length / 2];
	else {
	    int a = curLen[curLen.length / 2 - 1];
	    int b = curLen[curLen.length / 2];
	    median = (int) Math.floor((a + b) / 2);
	}
	int ans = 0;
	for (int i : curLen)
	    ans += Math.abs(i - median);
	return ans;
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
