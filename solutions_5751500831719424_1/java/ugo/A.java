package gcj2014.R1B;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.deepToString;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.*;

public class A {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2014/R1B/";
		String READ_FILE = null;
		String WRITE_FILE = null;

//				READ_FILE = "asmall.in";
//				WRITE_FILE = "asmall.out";
		READ_FILE = "alarge.in";
		WRITE_FILE = "alarge.out";

		if(READ_FILE != null){
			System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR+READ_FILE))));
		}
		if(WRITE_FILE != null){
			System.setOut(new PrintStream(new File(DIR+WRITE_FILE)));
		}
		precalc();
		new A().run();
	}

	Scanner sc;

	void debug(Object... o){
		System.out.println(deepToString(o));
	}

	
	static void precalc(){}

	void run(){
		sc = new Scanner(System.in);
		int caseCnt = sc.nextInt();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			System.out.print("Case #" + caseNum + ": ");
			solve();
			System.out.flush();
		}
	}
	
	void solve(){
		int n = sc.nextInt();
		
		String[] strs = new String[n];
		for (int i = 0 ; i < n ; i++)
			strs[i] = sc.next();
		int m = 0;
		char[] chars = new char[100];
		Arrays.fill(chars, '-');
		for (int i = 0 ; i < strs[0].length() ; i++) {
			if (i == 0) {
				chars[m] = strs[0].charAt(i);
				m++;
			} else if(strs[0].charAt(i) != strs[0].charAt(i-1)) {
				chars[m] = strs[0].charAt(i);
				m++;
			}
		}
//		debug(chars);

		int[][] cnts = new int[n][m];
		for (int i = 0 ; i < n ; i++) {
			int index = 0;
			for (int j = 0 ; j < strs[i].length() ; j++) {
				if (j == 0 || strs[i].charAt(j) != strs[i].charAt(j-1)) {
					if (index >= m || chars[index] != strs[i].charAt(j)) {
						System.out.println("Fegla Won");
						return;
					}
					index++;
				}
				cnts[i][index-1]++;
			}
			if (index != m) {
				System.out.println("Fegla Won");
				return;
			}
		}
//		debug(cnts);
		
		int ret = 0;
		for (int j = 0 ; j < m ; j++) {
			int min = Integer.MAX_VALUE;
			for (int k = 0 ; k <= 100 ; k++) {
				int sum = 0;
				for (int i = 0 ; i < n ; i++) {
					sum += Math.abs(cnts[i][j] - k);
				}
				min = Math.min(min, sum);
			}
			ret += min;
		}
		System.out.println(ret);
		
	}
	
}

/*
5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc

Case #1: 1
Case #2: Fegla Won
Case #3: 4
Case #4: 0
Case #5: 3



*/