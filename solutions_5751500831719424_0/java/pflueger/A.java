import java.io.IOException;
import java.util.*;
// 5/3/14 in competition.

public class A extends CodeJammer {

	@Override
	public void process() throws IOException {
		int n = reader.readInt();
		
		String[] strings = new String[n];
		for (int i=0; i<n; i++) {
			strings[i] = reader.readString();
		}
		
		String s = strings[0];
		char[] chars = chars(s);
		int l = chars.length;
		int[][] mults = new int[l][n];
		
		for (int i=0; i<n; i++) {
			char[] these = chars(strings[i]);
			//output(these);
			if (!matches(these,chars)) {
				output("Fegla Won");
				return;
			}
			int[] lengths = mults(strings[i],l);
			for (int j=0; j<l; j++) {
				mults[j][i] = lengths[j];
			}
		}
		
		int cost = 0;
		for (int i=0; i<l; i++) {
			cost += costOf(mults[i],n);
		}
		
		output(cost);
		
	}
	
	public int costOf(int[] a, int n) {
		Arrays.sort(a);
		int median =  a[n/2];
		int result = 0;
		for (int i=0; i<n; i++) {
			result += Math.abs(median - a[i]);
		}
		return result;
	}
	
	public boolean matches(char[] a, char[] b) {
		if (a.length != b.length) return false;
		for (int i=0; i<a.length; i++) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}
	
	public char[] chars(String s) {
		ArrayList<Character> arr = new ArrayList<Character>();
		for (int i=0; i<s.length(); i++) {
			if (i==0 || s.charAt(i) != s.charAt(i-1)) {
				arr.add(s.charAt(i));
			}
		}
		char[] result = new char[arr.size()];
		for (int i=0; i<arr.size(); i++) {
			result[i] = arr.get(i);
		}
		return result;
	}
	
	public int[] mults(String s, int num) {
		int[] result = new int[num];
		int j=0;
		int i=0;
		while (j < num) {
			int count = 0;
			char c = s.charAt(i);
			while (i<s.length() && s.charAt(i) == c) {
				i++;
				count++;
			}
			result[j] = count;
			j++;
		}
		return result;
	}
	


	public static void main(String[] args) {
		new A().run(args);
	}

}
