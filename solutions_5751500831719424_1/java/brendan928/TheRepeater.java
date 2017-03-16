package therepeater;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class TheRepeater {

	static Scanner in=null;
	static PrintWriter out=null;
	
	public static void main(String[] args) {
		
		try {
		File file = new File("therepeaterin.txt");
		File file2=new File("therepeaterout.txt");
		in = new Scanner(file);
		out = new PrintWriter(file2);
		int testCases = Integer.parseInt(in.nextLine());
		for (int i=0;i<testCases;i++) {
			solveCase(i+1);
		}
		out.close();
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void solveCase(int caseNum) throws Exception {
		int totalSteps=0;
		int n = Integer.parseInt(in.nextLine());
		String[] strings = new String[n];
		for (int i=0;i<n;i++) {
			strings[i]=in.nextLine();
		}
		while (strings[0].length()!=0) {
			char firstChar = strings[0].charAt(0);
			int[] occurancesOfFirstChar = new int[n];
			for (int i=0;i<n;i++) {
				occurancesOfFirstChar[i]=-1;
			}
			for (int i=0;i<n;i++) {
				int count=0;
				while (strings[i].length()>0 && strings[i].charAt(0)==firstChar) {
					count++;
					strings[i]=strings[i].substring(1);
				}
				occurancesOfFirstChar[i]=count;
			}
			for (int i=0;i<=n/2;i++) {
				int indexOfSmallest = i;
				int smallest = occurancesOfFirstChar[i];
				for (int j=i;j<n;j++) {
					if (occurancesOfFirstChar[j]<smallest) {
						indexOfSmallest=j;
						smallest=occurancesOfFirstChar[j];
					}
				}
				occurancesOfFirstChar[indexOfSmallest]=occurancesOfFirstChar[i];
				occurancesOfFirstChar[i]=smallest;
			}
			if (occurancesOfFirstChar[0]==0) {
				out.println("Case #"+caseNum+": Fegla Won");
				return;
			}
			for (int i=0;i<n;i++) {
				totalSteps+=Math.abs(occurancesOfFirstChar[i]-occurancesOfFirstChar[n/2]);
			}
		}
		for (int i=0;i<n;i++) {
			if (strings[i].length()>0) {
				out.println("Case #"+caseNum+": Fegla Won");
				return;
			}
		}
		out.println("Case #"+caseNum+": "+totalSteps);
	}
}