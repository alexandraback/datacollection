package QB;

import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));

//		System.out.println(getMedian(new int[] {1, 2}));
//		System.out.println(getMedian(new int[] {1, 3}));
//		System.out.println(getMedian(new int[] {1, 4}));
//		System.out.println(getMedian(new int[] {6, 2, 3}));
//		System.out.println(getMedian(new int[] {6, 2, 1}));
		
		int T =	sc.nextInt();
		for (int t = 1; t <= T; ++t) {
			int N = sc.nextInt();
			String [] str = new String[N];
			for (int n = 0; n < N; n++) {
				str[n] = sc.next();
			}
			System.out.println("Case #" + t + ": " + solve(str));
		}
		
	}

	private static String solve(String[] str) {
		// first check if each string has the same sequence of letters, and keep track of counts
		int [][] counts = new int[str.length][];
		// first is special: get the sequence of characters
		CharSeq first = getSequenceOfChars(str[0]);
		counts[0] = first.count;
		
		// now all other sequences of characters must be identical, we keep track of counts
		for (int s = 1; s < str.length; s++) {
			CharSeq t = getSequenceOfChars(str[s]);
			// check if same letter sequence
			int len = Math.min(first.letters.length, t.letters.length);
			for (int i = 0; i < len; i++) {
				if (first.letters[i] != t.letters[i]) return "Fegla Won";
			}
			// now store count:
			counts[s] = t.count;
		}
		
		// finally, for each letter we found the l_1 distance minimizer <-- median
		int nMoves = 0;
		int ind = 0;
		while ( counts[0][ind] != 0 ) {
			int [] temp = new int [str.length];
			for (int i = 0; i < str.length; i++) {
				temp[i] = counts[i][ind];
			}
			int med = getMedian(temp); // always integer! (when average 2 points, any ok)
			// now sum up the differences
			for (int i = 0; i < str.length; i++) {
				nMoves += Math.abs(temp[i] - med);
			}
			ind++;
		}
		
		return Integer.toString(nMoves);
	}

	private static int getMedian(int[] temp) {
		Arrays.sort(temp);
		int mid = temp.length / 2;
		if (temp.length % 2 == 1) {
			return temp[mid];
		} else {
			return (temp[mid-1]+temp[mid])/2;
		}
	}

	private static CharSeq getSequenceOfChars(String str) {
		int len = str.length()+1;
		int [] count = new int[len];
		char [] letters = new char[len]; // upper bound -- end with 0s (at least one always!) 

		char lastChar = 0;
		int indInCount = -1;
		for (int c = 0; c < str.length(); c++) {
			char curCh = str.charAt(c);
			if (lastChar == curCh) {
				count[indInCount]++;
			} else {
				indInCount++;
				letters[indInCount] = curCh;
				lastChar = curCh;
				count[indInCount]++;
			}
		}

		return new CharSeq(count, letters);
	}

	final static class CharSeq {
		final int [] count;
		final char [] letters;
		public CharSeq (int [] count, char [] letters) {
			this.count = count;
			this.letters = letters;
		}
		// we allow acces to members, but kinda bad since array contents can change
	}
}
