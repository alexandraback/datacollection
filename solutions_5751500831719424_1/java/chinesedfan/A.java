import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int total = s.nextInt();
		int current = 1;
		while (current <= total) {
			int n = s.nextInt();
			String str[] = new String[n];
			int p[] = new int[n];
			int c[] = new int[n];
			for (int i = 0; i < n; i++) {
				str[i] = s.next();
				p[i] = 0;
			}
			
			int count = 0;
			boolean flag = false;
			while (true) {
				char cur = str[0].charAt(p[0]);
				for (int i = 0; i < str.length; i++) {
					if (str[i].charAt(p[i]) != cur){
						flag = true;
						break;
					}
				}
				if (flag) break;
				
				//int min = 100;
				boolean stop = false;
				for (int i = 0; i < str.length; i++) {
					c[i] = getCount(str[i], p[i]);
					//if (c[i] < min) min = c[i];
					p[i] += c[i];
					if (p[i] >= str[i].length()) stop = true;
				}
				
				Arrays.sort(c);
				for (int i = 0; i < str.length; i++) {
					count += Math.abs(c[i]-c[c.length/2]);
				}
				
				if (stop) break;
			}
			
			for (int i = 0; i < str.length; i++) {
				if (p[i] != str[i].length()){
					flag = true;
					break;
				}
			}
			
			if (flag) {
				System.out.printf("Case #%d: Fegla Won\n", (current++));
				continue;
			}
			
			System.out.printf("Case #%d: %d\n", (current++), count);			
		}
	}
	
	static int getCount(String s, int start) {
		int count = 0;
		char c = s.charAt(start);
		while(start+count < s.length()) {
			if (s.charAt(start+count) != c) break;
			count++;
		}
		return count;
	}
}
