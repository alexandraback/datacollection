package gcj.y2016.R1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class MainA {

	static final int INF = 10000000;
	static final int[] flg = {1,2,4,8,16,32,64,128,256,512};
	static final char[] A = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	public static void main(String[] args) throws FileNotFoundException {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/A-small-practice.in"));
		//		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int t=1; t<T+1; t++) {
			int N = sc.nextInt();

			List<Vec> P = new ArrayList<Vec>();

			for (int i=0; i<N; i++) {
				P.add(new Vec(i,sc.nextInt()));
			}

			output(t, solve(N,P));

		}
		sc.close();

	}

	static String solve(int N, List<Vec> P) {
		String ret = "";

		while(true) {
			Collections.sort(P, new YComparator());

			Vec p1 = P.get(0);
			Vec p2 = P.get(1);
			Vec p3 = null;

			if (N>2) {
				p3 = P.get(2);
			}

			if (p1.y == 0) {
				break;
			}

			//第一政党と第二政党が同数の場合
			if (p1.y == p2.y) {
				//第三政党が存在しない場合
				if (N==2 || p3.y==0) {
					ret = ret + " " + p1.a + p2.a;
					p1.y -= 1;
					p2.y -= 1;
				}
				//第三政党がいる場合１
				else {
					ret = ret + " " + p3.a;
					p3.y -= 1;
				}
			}

			//第一政党が単独最大の場合
			else {
				ret = ret + " " + p1.a;
				p1.y -= 1;
			}

		}

		return ret.substring(1);
	}

	static String trim(String S, String target) {
		int i = S.indexOf(target);
		S = S.substring(0, i) + S.substring(i+1, S.length());
		return S;
	}

	static class Vec {
		public int x;
		public int y;
		public char a;

		Vec(int x, int y) {
			this.x = x;
			this.y = y;
			this.a = A[x];
		}
	}

	static class YComparator implements Comparator<Vec> {
		public int compare(Vec v1, Vec v2) {
			if (v1.y < v2.y) return 1;
			else if (v1.y > v2.y) return -1;
			else return 0;
		}
	}

	static void output(int i, String a) {
		System.out.println("Case #" + i + ": " + a);
	}

}