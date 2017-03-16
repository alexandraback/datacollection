package y2015.Round1B;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.Scanner;

public class ProbB {

	private static Reader in;
	private static PrintWriter out;	
	public static final String NAME = "B-small-practice.in";		
	public static final String OUTNAME = "B-output.out";
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader(NAME));
		BufferedWriter bw = new BufferedWriter(new FileWriter(OUTNAME));
		
		int[][] a = new int[4][1];
		/*
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				a[i][j]=1;
			}
		}
		
		a[0][0] = 1;
		a[3][0] = 1;
		System.out.println(unhappiness(a));*/
		
		String output = "";
		int cases = Integer.valueOf(sc.nextLine());
		for (int c = 1; c <= cases; c++) {
			output += "Case #" + c + ": ";
			
			int R = sc.nextInt();
			int C = sc.nextInt();
			int N = sc.nextInt();
			
			int[][] apartment = new int[R][C];
			
			int result = recurse(apartment, N, 0, 0);
			output += result + "\n";
			
			if (sc.hasNext()) sc.nextLine();
		}		
		bw.write(output);
		bw.close();
	}
	
	public static int recurse(int[][] apartment, int tenants, int i, int j) {
		
		if (tenants > 0 && (i >= apartment.length)) {
			return Integer.MAX_VALUE;
		}
		
		if (tenants == 0) {
			int re = unhappiness(apartment);
			//System.out.println("total: " + re);
			return re;
		} else {
			
			int result = Integer.MAX_VALUE;
			
			int newJ = (j+1) % apartment[0].length;
			int newI = (newJ == 0) ? i+1 : i;
			
			int newTenants = tenants-1;

			int[][] nAp = new int[apartment.length][apartment[0].length];
			for (int a = 0; a < apartment.length; a++) {
				for (int b = 0; b < apartment[0].length; b++) {
					nAp[a][b] = apartment[a][b];
				}
			}	
			
			int[][] nAp2 = new int[apartment.length][apartment[0].length];
			for (int a = 0; a < apartment.length; a++) {
				for (int b = 0; b < apartment[0].length; b++) {
					nAp2[a][b] = apartment[a][b];
				}
			}					
			
			nAp[i][j] = 1;
			result = recurse(nAp, newTenants, newI, newJ);
			int resultSkip = recurse(nAp2, tenants, newI, newJ);
			//System.out.println(result + "  " + resultSkip);
			return Math.min(result, resultSkip);
		}

	}
	
	public static int unhappiness(int[][] apartment) {
		int total = 0;
		for (int i = 0; i < apartment.length; i++) {
			for (int j = 0; j < apartment[0].length; j++) {
					if (j-1 >= 0 && apartment[i][j-1] == 1) {
						if (apartment[i][j] == 1)
							total++;
					}
					
					if (i+1 < apartment.length && apartment[i+1][j] == 1) {
						if (apartment[i][j] == 1)	
							total++;
					}
			}
		}
		return total;
	}

	public static class ArrayUtil {
		
		public static void printArray(int[] arr, int size) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < arr.length; i++) {
				if (i > 0) {
					sb.append(",");
				}
				
				int padding = size - String.valueOf(arr[i]).length();
				while (padding > 0) {
					sb.append(" ");
				}				
				sb.append(arr[i]);
			}
			System.out.println(sb);
		}
		
		public static void printArray(float[] arr, int size) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < arr.length; i++) {
				if (i > 0) {
					sb.append(",");
				}
				
				int padding = size - String.valueOf(arr[i]).length();
				while (padding > 0) {
					sb.append(" ");
					padding--;
				}				
				sb.append(arr[i]);
			}
			System.out.println(sb);
		}		
		
		public static int bitToInt(String num) {
			int result = 0;
			int length = num.length();
			for (int i = 0; i < length; i++) {
				int pow = length - 1 -i;
				if (i == length - 1) {
					result += Integer.valueOf(String.valueOf(num.charAt(length - 1)));
				} else {
					result += (int) Math.pow(2, length - 1 - i);	
				}
			}
			return result;
		}		
		
	}	
}
