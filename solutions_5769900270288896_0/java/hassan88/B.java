import java.io.*;
import java.util.*;

public class B {
	static int [][] temp;
	public static void main(String[] args) throws IOException {
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("B-small-attempt0.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter(new File("B-small.out"));
		StringTokenizer st;
		int cases = Integer.parseInt(br.readLine().trim()), R, C, N, MAX;
		for (int c = 1; c <= cases; c++) {
			st = new StringTokenizer(br.readLine());
			R = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			temp = new int [R][C];
			N = Integer.parseInt(st.nextToken());
			MAX = 1<<(R*C);
			int res = Integer.MAX_VALUE;
			for(int i = 0;i < MAX;i++) {
				res = Math.min(res, evaluate(i, N));
			}
			out.println("Case #" + c + ": " + res);
		}
		out.close();
	}
	public static int evaluate(int mask, int N) {
		int rows = temp.length, cols = temp[0].length;
		int res = 0, len = rows*cols, tenants = 0;
		for(int i = 0;i < len;i++) {
			int row = i/cols, col = i%cols;
			if(((1<<i) & mask) != 0) {
				tenants++;
				temp[row][col] = 1;
			}else {
				temp [row][col] = 0;
			}
		}
		if(tenants != N)return Integer.MAX_VALUE;
		for(int i = 0;i < rows;i++) {
			for(int j = 0;j < cols;j++) {
				if(temp[i][j] == 0)continue;
				if(i != rows-1 && temp[i+1][j] == 1)res++;
				if(j != cols-1 && temp[i][j+1] == 1)res++;
			}
		}
		return res;
	}
}