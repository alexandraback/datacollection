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
	static String file = "B-small-attempt1";

	static long solve(long[] line, long[] barbers) {
		long myPlace = line[1];
		long myBarber = -1;
	
		long max = 1000000000000000l;
		long min = 0;
		while(max >= min) {
			long time = min + (max - min) / 2;
			long[] state = new long[barbers.length];
			long alreadyCut = 0;
			for (int i = 0; i < state.length; i++) {
				state[i] = (time / barbers[i]);
				alreadyCut += state[i];
				if (time % barbers[i] != 0)
					alreadyCut++;
			}
			if (alreadyCut < myPlace) {
				List<Integer> firstFreeBarbers = new ArrayList<Integer>();
				long minFinish = Long.MAX_VALUE;
				for (int i = 0; i < state.length; i++) {
					long finish = 0;
					if (time % barbers[i] != 0)
						finish = (state[i]+1)*barbers[i]-time;
		
					minFinish = Math.min(minFinish, finish);
				}
				for (int i = 0; i < state.length; i++) {
					long finish = 0;
					if (time % barbers[i] != 0)
						finish = (state[i]+1)*barbers[i]-time;
		
					if (finish == minFinish) {
						firstFreeBarbers.add(i);
					}
				}
				long dist = myPlace - alreadyCut;
				if (firstFreeBarbers.size() >= dist) {
					myBarber = firstFreeBarbers.get((int)(dist - 1)) + 1;
					break;
				} else {
					min = time + 1;
				}
			} else {
				max = time - 1;
			}
			
		}
		
		return myBarber;
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
			
			String r = "Case #" + (i + 1) + ": " + solve(longArray(line1), longArray(line2));

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
