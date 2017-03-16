import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class TheRepeater {
	public static void main(String[] args) {
        String base = "/home/stefan/";
        String input = base + "A-small-attempt4.in";
        String output = base + "A-small-attempt4.out";
        
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
		
		String A = removeDuplicates(words[0]);
		String B = removeDuplicates(words[1]);
		
		if(! (A.equals(B))){
			write.write("Fegla Won\n");
			return;
		} else {
			int[] c = repeat(words[0], A.length());
			int[] d = repeat(words[1], B.length());
			
			int r = 0;
			
			for(int i=0;i<c.length;i++){
				r+=Math.abs(c[i]-d[i]);
			}
			
			write.write(Integer.toString(r) + "\n");
		}
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
