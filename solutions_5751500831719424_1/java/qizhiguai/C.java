import java.util.Arrays;
import java.util.Scanner;


public class C {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for (int test = 1; test <= testNum; test++) {
			boolean success = true;
			scan.nextLine();
			int strings = scan.nextInt();
			String[] s = new String[strings];
			for (int i = 0; i < strings; i++) {
				scan.nextLine();
				s[i] = scan.next();
			}
			int distinctchar = 0;
			char[] alpha = new char[100];
			char charptr = 0;
			for (int i = 0; i < s[0].length(); i++) {
				if (s[0].charAt(i) != charptr) {
					charptr = s[0].charAt(i);
					alpha[distinctchar] = charptr;
					distinctchar++;
				}
			}
			int[][] count = new int[strings][distinctchar];
			for (int i = 0; i < count.length; i++) {
				Arrays.fill(count[i], 0);
			}
			for (int r = 0; r < count.length; r++) {
				int ptr = 0;
				for (int i = 0; i < s[r].length(); i++) {
					if (s[r].charAt(i) != alpha[ptr]) {
						if (i == 0 || ptr+1 == distinctchar || s[r].charAt(i) != alpha[ptr+1]) {
							success = false;
							break;
						} else {
							count[r][ptr+1]++;
							ptr++;
						}
					} else {
						count[r][ptr]++;
					}
				}
				if (ptr+1 != distinctchar) {
					success = false;
				}
				if (!success) {
					break;
				}
			}
			if (!success) {
				System.out.println("Case #" + test + ": Fegla Won");
				continue;
			}
			long res = 0;
			for (int i = 0; i < distinctchar; i++) {
				int[] a = new int[count.length];
				for (int j = 0; j < count.length; j++) {
					a[j] = count[j][i];
				}
				Arrays.sort(a);
				int m = 0;
				int n = a.length - 1;
				while (m < n) {
					res += (a[n] - a[m]);
					n--;
					m++;
				}
			}
			System.out.println("Case #" + test + ": " + res);
		}
		scan.close();
	}
	
}
