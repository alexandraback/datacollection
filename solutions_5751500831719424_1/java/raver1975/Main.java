import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	static PrintWriter writer;

	public static void main(String[] args) {
		try {
			writer = new PrintWriter("out.txt", "UTF-8");
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		} catch (UnsupportedEncodingException e1) {
			e1.printStackTrace();
		}
		Scanner sc = null;
		try {
			sc = new Scanner(new File("in.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int T = sc.nextInt();
		top: for (int t = 0; t < T; t++) {
			// ----------------------------------------------------------
			int N = sc.nextInt();
			String[] str = new String[N];
			String[] str1 = new String[N];
			for (int i = 0; i < N; i++) {
				str[i] = sc.next();
			}
			
			for (int i=0;i<N;i++){
				char nowat=str[i].charAt(0);
				String temp=""+nowat;
				for (int j=1;j<str[i].length();j++){
					if (str[i].charAt(j)==nowat){
						continue;
					}
					else{
						nowat=str[i].charAt(j);
						temp+=nowat;
					}
				}
//				System.out.println(str[i]+"\t"+temp);
				str1[i]=temp;
			}
			
			// check for integrity
			for (int i=1;i<N;i++){
				if (!str1[i].equals(str1[i-1])){
					out(t,"Fegla Won");
					continue top;
				}
			}
			
//			// check for integrity
//			HashSet<Character>[] hs = new HashSet[N];
//			for (int i = 0; i < N; i++) {
//				hs[i] = new HashSet<Character>();
//				for (int j = 0; j < str[i].length(); j++) {
//					hs[i].add(str[i].charAt(j));
//				}
//			}
//			for (int i = 1; i < N; i++) {
//				if (!hs[i - 1].equals(hs[i])) {
//					out(t, "Fegla Won");
//					continue top;
//				}
//			}
//
			int[] counts = new int[N];
			int outtotal = 0;
			for (char c : str1[0].toCharArray()) {
				int minstart = Integer.MAX_VALUE;
				int maxstart = Integer.MIN_VALUE;
				for (int i = 0; i < N; i++) {
                    counts[i]=0;
                    while(str[i].length()>0 && str[i].charAt(0)==c){
                    	str[i]=str[i].substring(1);
                    	counts[i]++;
                    	
                    }

//					counts[i] = str[i].length() - str[i].replace(c + "", "").length();
					if (counts[i] < minstart)
						minstart = counts[i];
					if (counts[i] > maxstart)
						maxstart = counts[i];
				}

				int best = Integer.MAX_VALUE;
				for (int i = minstart; i <= maxstart; i++) {
					int total = 0;
					for (int j = 0; j < N; j++) {
						total += Math.abs(counts[j] - i);
					}
					if (total < best)
						best = total;
				}

				outtotal += best;
			}
			out(t, outtotal + "");

			// ----------------------------------------------------------
		}
		writer.close();
	}

	public static void out(int t, String s) {
		String g = "Case #" + (t + 1) + ": " + s;
		System.out.println(g);
		writer.write(g + "\n");

	}
}

