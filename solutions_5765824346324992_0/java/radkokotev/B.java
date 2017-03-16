import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;


public class B {
	public static long gcd(long a, long b) {
		if (b == 0)	{
			return a;
		}
		return gcd(b, a % b);
	}
	

	public static long lcm(long a, long b) {
	    return a * b / gcd(a, b);
	}

	public static long lcm(long arr[], int i) {
		if (i == arr.length - 2) return lcm(arr[i], arr[i + 1]);
	    return lcm(arr[i], lcm(arr, i + 1));
	}
	
	public static long countPeople(long arr[], long lcm) {
		long count = 0;
		for (long l : arr) {
			count += lcm / l;
		}
		return count;
	}
	
	public static int freeSpot(long arr[]) {
		for (int i = 0; i < arr.length; i++) 
			if (arr[i] <= 0) return i;
		return -1;
	}
	
	public static void cut(long arr[]) {
		long min = Long.MAX_VALUE;
		for (long l : arr) min = Math.min(min, l);
		for (int i = 0; i < arr.length; i++) arr[i] -= min;
	}

	public static void main(String[] args) throws IOException {
//		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
//		BufferedReader in = new BufferedReader(new FileReader("b_test.in"));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			String s[] = in.readLine().split(" ");
			int b =  Integer.parseInt(s[0]);
			long n =  Long.parseLong(s[1]);
			long arr[] = new long[b];
			int i = 0;
			for (String ss : in.readLine().split(" ")) {
				arr[i++] = Long.parseLong(ss);
			}
			if (b > 1) {
				long countPeople = countPeople(arr, lcm(arr, 0));
				n = n % countPeople;
				if (n == 0) {
					n = countPeople;
				}
			} else {
				n = 1;
			}
//			System.out.println("n = " + n);
			long newarr[] = new long[b];
			i = 0;
			while (n > 0) {
				i = freeSpot(newarr);
//				System.out.println(Arrays.toString(newarr) + " " + i);
				if (i < 0) {
					cut(newarr);
					continue;
				} else {
					n--;
					newarr[i] = arr[i];
				}
			}
			
			pw.format("Case #%d: %d\n", t, i + 1);
			pw.flush();
		}
		pw.close();
		in.close();
	}

}
