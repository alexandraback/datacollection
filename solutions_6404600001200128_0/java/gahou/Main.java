import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

class Main
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Scanner sc = new Scanner(new InputStreamReader(System.in));

	public static void main (String[] args) throws java.lang.Exception {
		int T = Integer.parseInt(br.readLine());
		for (int i=0; i<T; i++){
			solve(i);
		}
	}

	public static void solve(int num) throws IOException{
		int N = Integer.parseInt(br.readLine());
		int[] ms = new int[1000];
		StringTokenizer data = new StringTokenizer(br.readLine(), " ");
		for (int i=0; i<N; i++) {
			ms[i] = Integer.parseInt(data.nextToken());
		}

		int ansY = 0;
		int angle = 0;
		for (int i=1; i<N; i++) {
			ansY += Math.max(0, ms[i-1] - ms[i]);
			angle = Math.max(angle, ms[i-1] - ms[i]);
		}

		int ansZ = 0;
		for (int i=1; i<N; i++) {
			ansZ += Math.min(ms[i-1], angle);
		}

		System.out.println("Case #" + (num+1) + ": " + ansY + " " + ansZ);
	}
}
