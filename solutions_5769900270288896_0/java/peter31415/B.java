import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class B {
//	static String file = "B";
	static String file = "B-small-attempt0";

	static long solve(int r, int c, int n) {
		long min = Long.MAX_VALUE;
		
		for (int i = 0; i < Math.pow(2, r*c); i++) {
			if (ones(i) == n) {
				long cmin = eval(i, r, c);
				min = Math.min(min, cmin);
			}
		}
		
		return min;
	}
	
	static long eval(int o, int r, int c) {
		
		long un = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				
				if (!isOcc(o, r, c, i, j)) continue;
				
				int[][] nei = new int[][] { 
					{ i+1, j },
					{ i-1, j },
					{ i, j+1 },
					{ i, j-1 }
				};
				
				for (int k = 0; k < nei.length; k++) {
					if (!isValid(nei[k], r, c)) continue;
					if(isOcc(o, r, c, nei[k][0], nei[k][1]))
						un++;
				}
			}
		}
		
		
		return un / 2;
	}
	
	static boolean isOcc(int o, int rows, int cols, int r, int c) {
		
		int i = r * cols + c;
		
		return (((o >> i) & 1) == 1);
	}
	
	static boolean isValid(int[] n, int r, int c) {
		return n[0] >= 0 && n[1] >= 0 && n[0] < r && n[1] < c;
	}
	
	static int ones(int n) {
		int cnt = 0;
		
		for (int i = 0; i < 30; i++) {
			if (((n >> i) & 1) == 1) cnt++;
		}
		
		return cnt;
	}

	static int[] intArray(String l) {
		String[] vals = l.split(" ");
		int[] ans = new int[vals.length];
		for (int i = 0; i < vals.length; i++) {
			ans[i] = Integer.valueOf(vals[i]);
		}
		return ans;
	}
	
	static long[] longArray(String l) {
		String[] vals = l.split(" ");
		long[] ans = new long[vals.length];
		for (int i = 0; i < vals.length; i++) {
			ans[i] = Long.valueOf(vals[i]);
		}
		return ans;
	}

	public static void main(String[] args) throws IOException {
		FileInputStream fis = new FileInputStream(file + ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 1;
		for (int i = 0; i < problemCount; i++) {
			String line1 = lines.get(currentIndex++);
			int[] a = intArray(line1);
			
			String r = "Case #" + (i + 1) + ": " + solve(a[0], a[1], a[2]);

			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
	}
}
