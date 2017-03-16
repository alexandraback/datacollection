import java.io.*;
import java.util.*;

public class A {
	public static void main(String args[]) {
		try {
			InputStreamReader isr = null;
			try {
				isr = new InputStreamReader(System.in, "UTF-8");
				BufferedReader br = null;
				try {
					br = new BufferedReader(isr);
					new A().go(br);
				} finally {
					if (br != null) br.close();
				}
			} finally {
				if (isr != null) isr.close();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	public void go(BufferedReader br) throws Exception {
		int num = Integer.parseInt(br.readLine());
		for (int n = 1; n <= num; n++)
			solve(n, br);
	}

	public void solve(int num, BufferedReader br) throws Exception {
		int N = Integer.parseInt(br.readLine());
		String Ss[] = new String[N];
		for (int i = 0; i < N; i++)
			Ss[i] = br.readLine();

		String Cs[] = new String[N];
		// ArrayList<Integer> As[] = new ArrayList<Integer>[N];
		Object As[] = new Object[N];
		for (int i = 0; i < N; i++) {
			StringBuffer sb = new StringBuffer();
			char nowc = Ss[i].charAt(0);
			sb.append(nowc);
			ArrayList<Integer> A = new ArrayList<Integer>();
			A.add(1);
			int idx = 0;
			int nowi;
			for (int j = 1; j < Ss[i].length(); j++) {
				char c = Ss[i].charAt(j);
				if (nowc == c) {
					nowi = A.get(idx);
					A.set(idx, nowi + 1);
				} else {
					sb.append(c);
					nowc = c;
					A.add(1);
					idx++;
				}
			}
			Cs[i] = sb.toString();
			As[i] = A;
//			System.out.println(Cs[i]);
//			System.out.println(A);
		}
		boolean win = isEquals(Cs);
		if (!win)
			System.out.println("Case #" + num + ": Fegla Won");
		else {
			int M = Cs[0].length();

// System.out.println(N + "," + M);

			long C = 0;
			for (int i = 0; i < M; i++) {
				int Ms[] = new int[N];
				for (int j = 0; j < N; j++) {
					ArrayList<Integer> A = (ArrayList<Integer>)(As[j]);
					Ms[j] = A.get(i);
				}
				C += minC(Ms);
			}
			System.out.println("Case #" + num + ": " + C);
		}
	}

	public long minC(int Ms[]) {
		long C[] = new long[Ms.length];
		int sa;
		long min = 999999999999999L;
		for (int i = 0; i < Ms.length; i++) {
			C[i] = 0;
			for (int j = 0; j < Ms.length; j++) {
				sa = Ms[i] - Ms[j];
				if (sa < 0)
					sa = -sa;
				C[i] += sa;
			}
			if (C[i] < min)
				min = C[i];
		}
		return min;
	}

	public boolean isEquals(String ss[]) {
		for (int i = 1; i < ss.length; i++)
			if (!ss[0].equals(ss[i]))
				return false;
		return true;
	}
}
