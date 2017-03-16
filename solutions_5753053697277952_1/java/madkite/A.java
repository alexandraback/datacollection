package gcj2016r1c;

import java.util.*;

import com.google.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class A extends SingleThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(br -> {
			int n = Integer.parseInt(br.readLine());
			String[] s = br.readLine().split("\\s+");
			assert n == s.length;
			int[] a = new int[n];
			for(int i = 0; i < n; i++) {
				a[i] = Integer.parseInt(s[i]);
			}
			return new A(a);
		}, "google/src/" + A.class.getPackage().getName() + "/" + "A-large.in");
	}

	private final int[] data;
	private A(int[] data) {
		this.data = data;
	}

	public String call() throws Exception {
		return solve(data);
	}

	private static class Senator {
		final char party;
		int count;
		Senator(char party, int count) {
			this.party = party;
			this.count = count;
		}
	}

	private static String solve(int[] data) {
		int n = data.length;
		Senator[] senators = new Senator[n];
		for(int i = 0; i < n; i++) {
			senators[i] = new Senator((char)('A' + i), data[i]);
		}
		StringBuilder result = new StringBuilder();
		for(;;) {
			Arrays.sort(senators, (o1, o2) -> o2.count - o1.count);
			if(senators[0].count == 0)
				break;
			if(senators[0].count == senators[1].count && (n < 3 || senators[1].count != senators[2].count)) {
				result.append(' ').append(senators[0].party).append(senators[1].party);
				senators[0].count--;
				senators[1].count--;
			} else {
				result.append(' ').append(senators[0].party);
				senators[0].count--;
			}
		}
		return result.substring(1);
	}
}
