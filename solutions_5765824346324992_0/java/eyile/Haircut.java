import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Haircut {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("/home/e/Downloads/B-small-attempt0.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("/home/e/Documents/Haircut.out"));
		int times = Integer.parseInt(br.readLine());
		for(int t = 1; t <= times; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int b = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			int[] m = new int[b];
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < b; i++) {
				m[i] = Integer.parseInt(st.nextToken());
			}
			n %= loops(m);
			int time = 0;
			if(n == 0) {
				bw.write("Case #" + t + ": " + minIndex(m) + "\n");
			}
			while(n>0) {
				for(int mk = 0; mk < m.length; mk++) {
					if(time%m[mk] == 0) {
						n--;
						if(n == 0) {
							bw.write("Case #" + t + ": " + (mk+1) + "\n");
						}
					}
				}
				time++;
			}
		}
		br.close();
		bw.close();
	}
	
	private static int gcd(int a, int b) {
		while(b>0) {
			int temp = b;
			b = a%b;
			a = temp;
		}
		return a;
	}
	
	private static int lcmOfTwo(int a, int b) {
		return (a*b)/gcd(a,b);
	}
	
	private static int loops(int[] arr) {
		int lcm = 1;
		for(int a : arr) {
			lcm = lcmOfTwo(lcm, a);
		}
		int sum = 0;
		for(int a : arr) {
			sum += lcm/a;
		}
		return sum;
	}
	
	private static int minIndex(int[] arr) {
		int min = Integer.MAX_VALUE;
		int index = 0;
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] < min) {
				index = i;
				min = arr[i];
			}
			if(arr[i] == min) {
				index = i;
			}
		}
		return index+1;
	}
}
