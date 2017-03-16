package runda1C2016;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class SenateEvacuation {

	private String solve(Scanner in) {
		int noOfParties = in.nextInt();
		
		int[] senators = new int[noOfParties];
		
		for (int i=0; i<noOfParties; i++) {
			senators[i] = in.nextInt();
		}
		
		int max1 = 0;
		int i1 = -1;
		int max2 = 0;
		int i2 = -1;
		for (int i=0; i<noOfParties; i++) {
			if (senators[i] > max1) {
				max2 = max1;
				max1 = senators[i];
				i2 = i1;
				i1 = i;
			} else if (senators[i] > max2) {
				max2 = senators[i];
				i2 = i;
			}
		}
		
		
		StringBuilder sb = new StringBuilder();
		
		while (max1 > max2) {
			sb.append((char)(i1 + 'A') + " ");
			max1--;
		}
		senators[i1] = senators[i2];
		// wyrownane
		
		for (int i=0; i<noOfParties; i++) {
			if (i != i1 && i!= i2) {
				for (int s = 0; s < senators[i]; s++) {
					sb.append((char)(i + 'A') + " ");
				}
			}
		}
		
		for (int i=0; i<max2; i++) {
			sb.append((char)(i1 + 'A') + "" + (char)(i2 + 'A') + " ");
		}
		
		return sb.toString();
	}

	
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner in = new Scanner(new File("dane\\in"));
		PrintWriter out = new PrintWriter("dane\\out");
		
		in.useLocale(Locale.US);
		int T = in.nextInt();
		in.nextLine();
		System.out.println("T " + T);
		for (int i = 0; i < T; i++) {
			String s = "Case #" + (i + 1) + ": " + new SenateEvacuation().solve(in);
			out.println(s);
			System.out.println(s);
		}
		out.close();
	}
}
