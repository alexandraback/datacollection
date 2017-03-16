import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class B {
	
	public static void main(String[] args) throws FileNotFoundException {

		Scanner in = new Scanner(new File("c:\\codejam2015\\b\\B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File(
				"c:\\codejam2015\\b\\small.out"));
		int numTests = in.nextInt();
		for (int i = 1; i <= numTests; i++) {
			solve(i, in, out);
		}

		out.close();
	}

	private static void solve(int testNum, Scanner in, PrintWriter out) {

		int r = in.nextInt();
		int c = in.nextInt();
		int n = in.nextInt();
//		System.out.println(r + ":" + c + ":" + n);
		
		List<boolean[]> allCombs = resursivelyCombine( r * c, n);
//		for(boolean[] comb : allCombs) {
//			System.out.println(Arrays.toString(comb));
//		}
		
		int soln = Integer.MAX_VALUE;
		
		for(boolean[] comb : allCombs) {
			soln = Math.min(soln, solve(comb, r, c));
		}
		
		out.println("Case #" + testNum + ": " + soln);
	}

	private static int solve(boolean[] comb, int r, int c) {
		int u = 0;
		
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				int cell = j * r + i;
				int rowMax = (j + 1) * r;
				if(comb[cell] && rowMax > cell + 1 && comb[cell + 1]) {
					u++;
				}
				if(comb[cell] && comb.length > cell + r && comb[cell + r]) {
					u++;
				}
			}
		}
		return u;
	}

	private static List<boolean[]> resursivelyCombine(int l, int numTrue) {
		if(l == 0) {
			return Collections.emptyList();
		}
		
		List<boolean[]> result = new ArrayList<boolean[]>();
		if(l == numTrue) {
			result.add(trueArr(l));
		} else if(numTrue == 0) {
			result.add(falseArr(l));
			
		} else {
			List<boolean[]> cildren1 = resursivelyCombine(l -1 , numTrue -1);
			List<boolean[]> cildren2 = resursivelyCombine(l -1 , numTrue);
			
			for(boolean[] a : cildren1) {
				
				result.add(combine(true, a));
			}
			for(boolean[] a : cildren2) {
				
				result.add(combine(false, a));
			}
		}
		return result;
	}
	
	private static boolean[] combine(boolean b, boolean[] a) {
		boolean[] arr = new boolean[a.length + 1];
		arr[0] = b;
		for(int i = 0 ; i < a.length; i++) {
			arr[i + 1] = a[i];
		}
		return arr;
	}

	private static boolean[] trueArr(int l){
		
		boolean[] arr = new boolean[l];
		Arrays.fill(arr, true);
		
		return arr;
		
	}
	
private static boolean[] falseArr(int l){
		
		boolean[] arr = new boolean[l];
		Arrays.fill(arr, false);
		
		return arr;
		
	}
	
	private static int solve(int[] plates) {
		Arrays.sort(plates);
		return solveSorted(plates);
	}
	
	private static int solveSorted(int[] plates) {
		
		int max = plates[plates.length - 1];

		if(max <= 3) {
			return max;
		}
		
		int[] newPlates = splitAndadd(plates);
		max = Math.min(max, 1 + solve(newPlates));
		
		newPlates = split3Andadd(plates);
		return Math.min(max, 2 + solve(newPlates));
	}

	private static int[] splitAndadd(int[] plates) {
		
		int len = plates.length;
		int max = plates[len - 1];
		
		int[] newPlates = new int[len + 1];
		System.arraycopy(plates, 0, newPlates, 0, len - 1);
		
		int half = max/2;
		newPlates[len -1] = half;
		newPlates[len] = max - half;
		
		return newPlates;
		
	}
	
	private static int[] split3Andadd(int[] plates) {
		
		int len = plates.length;
		int max = plates[len - 1];
		
		int[] newPlates = new int[len + 2];
		System.arraycopy(plates, 0, newPlates, 0, len - 1);
		
		int third = max/3;
		newPlates[len -1] = third;
		int half = (max - third) / 2;
		newPlates[len] = half;
		newPlates[len + 1] = max - (third + half);
		
		return newPlates;
		
	}
}
