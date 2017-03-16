package round1A;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem1 {

	private static String inputFile = "/Users/Tuan/workspace/CodeJam/A-large.in";
	private static String outputFile = "/Users/Tuan/workspace/CodeJam/problem1_out.txt";
	
	public static void main(String[] args) throws Exception{
		PrintWriter pw = new PrintWriter(outputFile);
		File file = new File(inputFile);
		Scanner scan = new Scanner(file);
		int t = scan.nextInt();
		for(int z = 0; z < t; z++){
			int n = scan.nextInt();
			int[] a = new int[n];
			for(int i = 0; i < n; i++){
				a[i] = scan.nextInt();
			}
			//System.out.printf("Case #%d: %d %d\n",(z+1),method1(a),method2(a));
			pw.printf("Case #%d: %d %d\n",(z+1),method1(a),method2(a));
		}
		scan.close();
		pw.close();
		
	}
	private static int method1(int[] a){
		int sum = 0;
		for(int i = 0; i < a.length - 1; i++){
			if (a[i] > a[i + 1]){
				sum += a[i] - a[i + 1];
			}
		}
		
		return sum;
	}
	
	private static int method2(int[] a){
		int sum = 0;
		//every 10s, eat with this rate		
		int rate = a[a.length - 2] - a[a.length - 1];
		for(int i = 0; i < a.length - 1; i++){
			if (a[i] - a[i + 1] > rate){
				rate = a[i] - a[i + 1];
			}
		}
		if (rate <= 0){
			return 0;
		}
		
		for(int i = 0; i < a.length - 1; i++){
			if (a[i] <= rate ){
				sum += a[i];
			}else{
				sum += rate;
			}
		}
		return sum;
	}
}
