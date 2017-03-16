import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SenateEvacuation {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());

			Senetor s[] = new Senetor[n];
			int sum = 0;
			for (int j = 0; j < n; j++) {
				int x = Integer.parseInt(st.nextToken());
				Senetor temp = new Senetor((char) (j + 65), x);
				s[j] = temp;
				sum += x;
			}

			Arrays.sort(s);
			System.out.print("Case #" + (i + 1) + ": ");
			while (sum != 0) {
				if (n > 2 && s[0].no == 1 && s[1].no == 1 && s[2].no == 1) {
					s[0].no--;
					sum -= 1;
					System.out.print(s[0].party);
				} else if (s[0].no == s[1].no) {
					s[0].no--;
					s[1].no--;
					sum -= 2;

					System.out.print(s[0].party);
					System.out.print(s[1].party);
				} else {
					s[0].no--;
					sum -= 1;
					System.out.print(s[0].party);
				}

				System.out.print(" ");
				Arrays.sort(s);
			}
			System.out.println();

		}
	}
}
