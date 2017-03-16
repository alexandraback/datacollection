package codeJam.competition2014.round1B;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;

public class A {

	public static void main(String[] args) throws IOException {
		System.setIn(new FileInputStream("A-small-attempt2.in"));
//		System.setIn(new FileInputStream("A.in"));
		
		System.setOut(new PrintStream(new FileOutputStream("A-small-attempt2.out")));
		BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));

		int noCases = Integer.parseInt(bfr.readLine());
		
		String strA;
		String strB;
		
		Cases:
		for (int i = 1; i <= noCases; i++) {
			
			int noStr = Integer.parseInt(bfr.readLine());
			
			int a[][][] = new int[noStr][2][100];
			
			int result = 0;
			
			for (int j = 0; j < noStr; j++) {
				strA = bfr.readLine();
//				System.out.println(strA);
				
				int charC = 0;
				
				int count = 1;
				char c = strA.charAt(0);
				for (int jj = 1; jj < strA.length(); jj++) {
					if (c == strA.charAt(jj)){
						count++;
					}else{
						a[j][0][charC] = c;
						a[j][1][charC] = count;
						
//						System.out.println("ref char c="+c+" count="+count);
						
						c = strA.charAt(jj);
						count = 1;
						charC++;
					}
				}
				
				a[j][0][charC] = c;
				a[j][1][charC] = count;
//					System.out.println("ref char c="+c+" count="+count);
			}
			
			
			for (int j = 0; j < 100; j++) {
				int refChar = a[0][0][j];
				
//				if (refChar == 0){
//					break;
//				}
//				System.err.println("ref char "+refChar);
				
				int [] counts = new int[noStr];
				for (int k = 0; k < noStr; k++) {
					if (a[k][0][j] != refChar){
						System.out.println("Case #" + i + ": Fegla Won");
						continue Cases;
					}
					counts[k] = a[k][1][j];
				}
				
				Arrays.sort(counts);
				int refC = counts[noStr/2];
				
				for (int k = 0; k < noStr; k++) {
					result += Math.abs(refC - a[k][1][j]);
				}
			}
			
			
			
			
			
			
//			strA = bfr.readLine();
//			strB = bfr.readLine();
//			
//			int count = 1;
//			char c = strA.charAt(0);
//			for (int j = 1; j < strA.length(); j++) {
//				if (c == strA.charAt(j)){
//					count++;
//				}else{
//					lA.add(new Char(c, count));
////					System.out.println("A add "+c+ " count "+count);
//					c = strA.charAt(j);
//					count = 1;
//				}
//			}
//			
//			
//			count = 1;
//			c = strB.charAt(0);
//			for (int j = 1; j < strB.length(); j++) {
//				if (c == strB.charAt(j)){
//					count++;
//				}else{
////					System.out.println("B add "+c+ " count "+count);
//					lB.add(new Char(c, count));
//					
//					c = strB.charAt(j);
//					count = 1;
//				}
//			}
//			
//			
////			System.out.println("sizes"+ lA.size()+" "+lB.size());
//			if (lA.size() != lB.size()){
//				System.out.println("Case #" + i + ": Fegla Won1");
//				continue;
//			}
//			
//			for (int j = 0; j < lA.size(); j++) {
//				if (lA.get(j).c != lB.get(j).c){
//					System.out.println("Case #" + i + ": Fegla Won2");
//					continue Cases;
//				}
//				
//				result += Math.abs(lA.get(j).count - lB.get(j).count);
//			}
			
			
			System.out.println("Case #" + i + ": "+ result);
		}
		
		bfr.close();
	}
}

