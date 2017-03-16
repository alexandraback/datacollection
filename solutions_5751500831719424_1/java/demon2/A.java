import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner=new Scanner(new File("E:\\A-large.in"));
		PrintWriter printWriter=new PrintWriter(new File("E:\\A.txt"));
		int T=scanner.nextInt();
		for (int i = 1; i <= T; i++) {	
			int N=scanner.nextInt();
			scanner.nextLine();
			String[] strings=new String[N];
			for (int j = 0; j < N; j++) {
				strings[j]=scanner.nextLine();
			}
			
			int[] s=new int[N];
			int[] index=new int[N];
			int res=0;
			boolean f=true,f1=true;
			for (int j = 0; j < strings[0].length(); j++) {				
				if(j>0 && strings[0].charAt(j)==strings[0].charAt(j-1)){
					continue;
				}
				char ch=strings[0].charAt(j);
				Arrays.fill(s, 0);
				for (int k = 0; k < N; k++) {
					for (int k2 = index[k]; k2 < strings[k].length(); k2++) {
						if (strings[k].charAt(k2)==ch) {
							s[k]++;
							index[k]++;
						}
						else {
							break;
						}
					}
				}
				for (int k = 0; k < N; k++) {
					if (s[k]==0) {
						f=false;
						f1=false;
						break;
					}					
				}
				if (!f) {
					
					break;
				}
				if (f) {
					int sum=0,min=Integer.MAX_VALUE;
					for (int k = 1; k < 101; k++) {
						int p=k;
						sum=0;
						for (int l = 0; l < N; l++) {
							sum+=Math.abs(p-s[l]);
						}
						min=Math.min(min, sum);
					}
					res+=min;
				}
			}
			for (int j = 0; j < N; j++) {
				if (index[j]!=strings[j].length()) {
					f1=false;
					break;
				}
			}
			if (!f1) {
				printWriter.println("Case #"+i+": "+"Fegla Won");
				continue;
			}
			printWriter.println("Case #"+i+": "+res);
		}
		scanner.close();
		printWriter.close();
	}
	
}
