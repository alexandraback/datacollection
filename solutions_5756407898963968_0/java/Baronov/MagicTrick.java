import java.io.File;
import java.io.FileWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class MagicTrick {

	public static void main(String []args) {
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		String ans[] = new String[tests];
		for (int k = 0;k < tests;k++) {
			int f = in.nextInt();
		    int a [][] = new int[4][4];
		    for (int i = 0;i < 4;i++) {
		    	for (int j = 0;j < 4;j++) {
		    		a[i][j] = in.nextInt();
		    	}
		    }
		    int s = in.nextInt();
		    int b[][] = new int[4][4];
		    for (int i = 0;i < 4;i++) {
		    	for (int j = 0;j < 4;j++) {
		    		b[i][j] = in.nextInt();
		    	}
		    }
		    ans[k] = MagicTrick.solveTest(f, a, s, b);
		}

		for (int i = 0;i < tests;i++) {
			System.out.println("Case #" + String.valueOf(i+1) + ": " + ans[i]);
		}
	}
	
	private static String solveTest(int f, int[][]a, int s, int [][]b) {
	  --f;
	  --s;
	  int ans = -1;
	  for (int i = 0;i < 4;i++) {
		  for (int j = 0;j < 4;j++) {
			  if (a[f][i] == b[s][j]) {
				  if (ans != -1) {
					  return "Bad magician!";
				  }
				  ans = a[f][i];
			  }
		  }
	  }
	  if (ans == -1) {
		  return "Volunteer cheated!";
	  }
	  
      return String.valueOf(ans);		
	}
}
