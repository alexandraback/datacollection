import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class TheRepeater2 {
	public static void main(String[] args) {
        String base = "/home/stefan/";
        String input = base + "A-large.in";
        String output = base + "A-large.out";
        
		try {
			Scanner scan = new Scanner(new FileReader(input));
			PrintWriter write = new PrintWriter(output);
			
			int n = scan.nextInt();
			scan.nextLine();
			
			for (int i = 1; i <= n; i++) {
				write.write("Case #" + i + ": ");
				test(scan, write);
			}
			
			scan.close();
			write.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void test(Scanner scan, PrintWriter write) {
		int N;
		N = scan.nextInt();
		String[] words = new String[N];
		scan.nextLine();
		for(int i=0;i<N;i++){
			words[i] = scan.nextLine();
		}
		boolean b = false;
		String A = removeDuplicates(words[0]);
		for(int i=1;i<N;i++){
			if(! (A.equals(removeDuplicates(words[i]))) ){
				b = true;
				break;
			}
		}
		
		if(b){
			write.write("Fegla Won\n");
			return;
		} else {
			int[][] W = new int[N][];
			for(int i=0;i<N;i++){
				W[i] = repeat(words[i], A.length());
			}
			
			int r = 0;
			
			for(int i=0;i<A.length();i++){
				r+=diff(W, i);
			}
			
			write.write(Integer.toString(r) + "\n");
		}
	}
	
	private static int diff(int[][] W, int c){
		int r = Integer.MAX_VALUE;
		int a = Integer.MAX_VALUE, b=Integer.MIN_VALUE;
		for(int i=0;i<W.length;i++){
			if(W[i][c] < a)
				a = W[i][c];
			if(W[i][c] > b)
				b = W[i][c];
		}
		
		for(int i=a;i<=b;i++){
			int tmp = 0;
			for(int j=0;j<W.length;j++){
				tmp += Math.abs(W[j][c] - i);
			}
			if(tmp < r)
				r = tmp;
		}
		
		return r;
	}
	
	private static int[] repeat(String s, int k){
		int[] r = new int[k];
		for(int i=0;i<k;i++)
			r[i] = 1;
		int c = 0;
		char[] arr = s.toCharArray();
		for (int i=1;i<arr.length;i++) {
			if(arr[i] == arr[i-1]){
				r[c] = r[c]+1;
			} else {
				c++;
			}
		}
		return r;
	}
	
	private static String removeDuplicates(String s){
		StringBuilder sb = new StringBuilder();
		char[] arr = s.toCharArray();
		sb.append(arr[0]);
		for (int i=1;i<arr.length;i++) {
			if(arr[i] != arr[i-1])
				sb.append(arr[i]);
		}
		return sb.toString();
	}
}
