import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class A {
//	static String file = "A";
	static String file = "A-small-attempt0";

	static long[] solve(int[] mush) {
		long[] min = new long[2];
//		System.out.println(Arrays.toString(mush));
		
		for (int i = 0; i < mush.length - 1; i++) {
			if (mush[i+1] < mush[i]) {
				min[0] += mush[i] - mush[i+1];
			}
		}
		
		int rate = 0;
		for (int i = 0; i < mush.length - 1; i++) {
			if (mush[i+1] < mush[i]) {
				rate = Math.max(rate, mush[i] - mush[i+1]);
			}
		}
		
		for (int i = 0; i < mush.length - 1; i++) {
			min[1] += Math.min(mush[i], rate);
		}
		
		return min;
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
			String line2 = lines.get(currentIndex++);
			long[] min = solve(intArray(line2));
			String r = "Case #" + (i + 1) + ": " + min[0] + " " + min[1];

//			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
	}
}
