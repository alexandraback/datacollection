import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;


public class Round1B_A {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			int T = Integer.parseInt(line);

			for (int i=1; i<=T; i++) {
				line = br.readLine();
				int n = Integer.parseInt(line);
				String[] str = new String[n];
				for (int j=0; j<n; j++) {
					str[j] = br.readLine();
				}
				//String result = solve_small(n, str);
				String result = solve(n, str);

				System.out.println("Case #"+i+": "+result);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static String solve_small(int n, String[] str) {
		int ret = 0;
		int index0 = 0;
		int index1 = 0;
		char c0 = str[0].charAt(0);
		char c1 = str[1].charAt(0);
		
		while (index0 != str[0].length() && index1 != str[1].length()) {
			//System.out.println(c0+" "+c1);
			int num0 = 0;
			while (c0 == str[0].charAt(index0)) {
				index0++;
				num0++;
				if (index0 == str[0].length()) {
					break;
				}
			}
			int num1 = 0;
			while (c1 == str[1].charAt(index1)) {
				index1++;
				num1++;
				if (index1 == str[1].length()) {
					break;
				}
			}
			ret += Math.abs(num0 - num1);
			if (index0 != str[0].length()) {
				c0 = str[0].charAt(index0);
			}
			if (index1 != str[1].length()) {
				c1 = str[1].charAt(index1);
			}
			if (c0 != c1) {
				return "Fegla Won";
			}
		}
		return ""+ret;
	}
	
	private static String solve(int n, String[] str) {
		int ret = 0;
		int[] index = new int[n];
		char[] ch = new char[n];
		int[] num = new int[n];
		for (int i=0; i<n; i++) {
			ch[i] = str[i].charAt(0);
		}
		while (true) {
			//System.out.println(Arrays.toString(ch));
			for (int i=1; i<n; i++) {
				if (ch[0] != ch[i]) {
					return "Fegla Won";
				}
			}
			for (int i=0; i<n; i++) {
				num[i] = 0;
				while (ch[i] == str[i].charAt(index[i])) {
					index[i]++;
					num[i]++;
					if (index[i] == str[i].length()) {
						break;
					}
				}
			}

			Arrays.sort(num);
//			System.out.println(Arrays.toString(num));
			int h = num[n/2];
			//System.out.println(h);
			for (int i=0; i<n; i++) {
				ret += Math.abs(h - num[i]);

			}
			
//			System.out.println(Arrays.toString(index));
//			System.out.println(Arrays.toString(ch));
//			System.out.println(Arrays.toString(num));
			boolean f = true;
			for (int i=0; i<n; i++) {
				if (index[i] != str[i].length()) {
					f = false;
					ch[i] = str[i].charAt(index[i]);
				}
			}
			if (f) {
				break;
			}
		}
		return ""+ret;
	}
			
}
