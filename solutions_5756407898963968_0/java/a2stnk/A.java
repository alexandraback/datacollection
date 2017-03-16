package cj2014.q;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc;
	PrintWriter pw;
	int[] ans;
	int[][][] cards;
	
	public static void main(String[] args) throws Exception{
		String filePrefix = args.length>0?args[0]:"A-small-attempt0";

		try {
			new A().run(filePrefix);
		} catch(Exception e) {
			System.err.println(e);
		}
	}
	
	public void run(String filePrefix) throws Exception {
		sc = new Scanner(new FileReader(filePrefix + ".in"));
		pw = new PrintWriter(new FileWriter(filePrefix + ".out"));
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			read(sc);
			pw.print("Case #" + test + ": ");
			System.out.print("Case #" + test + ": ");
			solve();
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
		
	}
	
	void read(Scanner sc) {
		ans = new int[2];
		cards = new int[2][4][4];
		for(int i=0; i<2; i++) {
			ans[i] = sc.nextInt()-1;
			for(int j=0; j<4; j++)
				for(int k=0; k<4; k++)
					cards[i][j][k] = sc.nextInt();
		}
	}
	
	void print(Object s) {
		pw.print(s);
		System.out.print(s);
	}
	
	void println(Object s) {
		pw.println(s);
		System.out.println(s);
	}	
	
	public void solve() {
		HashSet<Integer> first = new HashSet<Integer>();
		for(int i=0; i<4; i++)
			first.add(cards[0][ans[0]][i]);
		ArrayList<Integer> second = new ArrayList<Integer>();
		for(int i=0; i<4; i++)
			if(first.contains(cards[1][ans[1]][i]))
				second.add(cards[1][ans[1]][i]);

		if(second.size()==0)
			println("Volunteer cheated!");
		else if(second.size()==1)
			println(second.get(0));
		else
			println("Bad magician!");
	}
}
