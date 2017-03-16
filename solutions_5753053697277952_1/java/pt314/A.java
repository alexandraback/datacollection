import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class A {

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			int n = Integer.parseInt(in.readLine());
			String[] data = in.readLine().split(" ");
			int[] senators = new int[n];
			for (int i = 0; i < senators.length; i++)
				senators[i] = Integer.parseInt(data[i]);
			out.println("Case #" + t + ":" + plan(senators));
		}
		out.close();
	}
	
	private static String plan(int[] senators) throws Exception {
		StringBuffer plan = new StringBuffer();
		
		int max1 = -1;
		int count1 = 0;
		for (int i = 0; i < senators.length; i++) {
			if (senators[i] > count1) {
				max1 = i;
				count1 = senators[i];
			}
		}
		int max2 = -1;
		int count2 = 0;
		for (int i = 0; i < senators.length; i++) {
			if (i == max1)
				continue;
			if (senators[i] > count2) {
				max2 = i;
				count2 = senators[i];
			}
		}
		
		while (senators[max1] > senators[max2]) {
			plan.append(" ");
			plan.append((char) ('A' + max1));
			senators[max1]--;
		}
		for (int i = 0; i < senators.length; i++) {
			if (i != max1 && i != max2) {
				while (senators[i] > 0) {
					plan.append(" ");
					plan.append((char) ('A' + i));
					senators[i]--;
				}
			}
		}
		while (senators[max1] > 0) {
			plan.append(" ");
			plan.append((char) ('A' + max1));
			plan.append((char) ('A' + max2));
			senators[max1]--;
			senators[max2]--;
		}
		
		return plan.toString();
	}
}
