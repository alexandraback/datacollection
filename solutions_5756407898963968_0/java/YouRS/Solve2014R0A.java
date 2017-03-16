
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.text.DecimalFormat;

public class Solve2014R0A {
	private static String filePath = "";
	public static final int  imax = 2147483647;
	public static final long lmax = 9223372036854775807l;
	public static final DecimalFormat NUMBER_FORMAT = new DecimalFormat();

	private static int T = 0;  // 1 ≤ T ≤ 100
	private static int[] Ns = null; // [T] 1 ≤ N ≤ 10^6

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//NUMBER_FORMAT.setMaximumFractionDigits(1);  // <-4,5->
		long startDatetime = System.currentTimeMillis();
		try {
			input();

			StringBuffer answer = new StringBuffer();
			for (int x = 0; x < T; x++) {
				answer.append("Case #" + (x+1) + ": ");
				System.out.print("Case #" + (x+1) + ": ");

				// TODO
				int y = 0;
				answer.append(y).append("\n");
				System.out.println(y);
			}
			output(answer);
		} catch (Exception e) {
			e.printStackTrace();
		}
		long tm = System.currentTimeMillis() - startDatetime;
		long tms = tm / 1000;
		System.out.println("The process time: " + tms + "s " + (tm%1000) + "ms");
	}

	/**
	 * read data from a file
	 * @param path : the data file's path
	 */
	private static void input() throws Exception {
		BufferedReader br = null;
		String line = null;
		if (filePath == null) br = new BufferedReader(new InputStreamReader(System.in));
		else br = new BufferedReader(new InputStreamReader(new FileInputStream(filePath)));

		T = Integer.parseInt(br.readLine());

//		Ns = new int[T];
//		Ms = new int[T];
//		aij = new ArrayList<int[][]>();
		for (int x = 0; x < T; x++) {
//			if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + (x+1)); }
//			if (line.equals("")) continue;
//			String[] sts = line.split(" ");
//			Ns[x] = Integer.parseInt(sts[0]);
//			Ms[x] = Integer.parseInt(sts[1]);
//			int[][] inData = new int[N[x]][M[x]];
//
//			for (int i = 0; i < Ns[x]; i++) {
//				if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + (x+1)); }
//				sts = line.split(" ");
//				for (int j = 0; j < Ms[x]; j++) {
//					inData[i][j] = Integer.parseInt(sts[j]);
//				}
//			}
//			aij.add(inData);
		}
		br.close();
		br = null;

		// Confirm
//		System.out.println(T);
//		for (int x = 0; x < T; x++) {
//			System.out.println(Ns[x] + " " + Ms[x]);
//			for (int i = 0; i < Ns[x]; i++) {
//				for (int j = 0; j < Ms[x]; j++) System.out.print(aij.get(x)[i][j] + " ");
//				System.out.println();
//			}
//		}
	}

	private static void output(StringBuffer answer) throws Exception {
		String outPath = "answer.out";
		if (filePath != null) outPath = filePath.substring(0, filePath.length()-2) + "out";
		FileOutputStream fos = new FileOutputStream(outPath, false);
		fos.write(answer.toString().getBytes());
		fos.close();
		fos = null;
	}
}
