import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class A {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE = !true;
	static final boolean _SMALL = true;
	static final String _PROBLEM = "A";

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();

		for (int k = 1; k <= testCase; k++) {
			String answer = "Fegla Won";
			System.out.printf("Case #%d: ", k);
			System.err.printf("Case #%d: ", k);

			int n = sc.nextInt();
			String[] str = new String[n];

			for (int i = 0; i < n; i++) {
				str[i] = sc.next();
				System.err.println(str[i]);
			}

			String idstr = "";
			char idc = 0;
			for (int j = 0; j < str[0].length(); j++) {
				char c = str[0].charAt(j);
				if (idc == 0) {
					idc = c;
					idstr += idc;
					System.err.println("idstr = " + idstr);
				} else {
					if (c == idc) {
						continue;
					} else {
						idc = c;
						idstr += idc;
						System.err.println("idstr = " + idstr);
					}
				}
			}

			int[] action = new int[idstr.length()];
			int[] action2 = new int[idstr.length()];
			for (int i = 0; i < action.length; i++) {
				action[i] = 0;
				action2[i] = 999; // enough large
			}

			String[] newstr = new String[n];
			newstr[0] = idstr;
			boolean possible = true;

			for (int i = 0; i < n; i++) {
				newstr[i] = "";
				char tmpidc = 0;
				int[] tmpaction = new int[idstr.length()];
				for (int j = 0; j < tmpaction.length; j++) {
					tmpaction[j] = 0;
				}
				for (int j = 0; j < str[i].length(); j++) {
					if (newstr[i].length() > idstr.length()) {
						possible = false;
						break;
					}
					char tmpc = str[i].charAt(j);
					if (tmpidc == 0) {
						tmpidc = tmpc;
						newstr[i] += tmpidc;
						System.err.println("newstr[" + i + "] = " + newstr[i]);
					} else {
						if (tmpc == tmpidc) {
							tmpaction[newstr[i].length() - 1] += 1;
							continue;
						} else {
							tmpidc = tmpc;
							newstr[i] += tmpidc;
							System.err.println("newstr[" + i + "] = "
									+ newstr[i]);
						}
					}
				}
				if (!possible) {
					break;
				}
				if (!newstr[i].equals(idstr)) {
					possible = false;
					break;
				}
				for (int j = 0; j < action.length; j++) {
					action[j] = Math.max(action[j], tmpaction[j]);
					action2[j] = Math.min(action2[j], tmpaction[j]);
				}
			}

			if (possible) {
				int count = 0;
				for (int i = 0; i < action.length; i++) {
					if(action2[i] == 999) {
						count += action[i];
					} else {
						count += (action[i] - action2[i]);
					}
					System.err.println("action[" + i + "] = " + action[i]);
					System.err.println("action2[" + i + "] = " + action2[i]);
				}
				answer = String.valueOf(count);
			}
			System.out.println(answer);
			System.err.println(answer);
		}
	}

	public static void main(String... args) throws IOException {
		if (!_SAMPLE) {
			if (_SMALL) {
				int i = 0;
				while (new File(_SMALLNAME(i) + ".in").exists())
					i++;
				i--;
				boolean test = false;
				if (new File(_SMALLNAME(i) + ".out").exists()) {
					System.err.println("overwrite?(y/n)");
					char c = (char) System.in.read();
					test = c != 'y';
				}
				if (test) {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_PROBLEM + "-small-test.out"));
					new A().run();
					FileReader f1 = new FileReader(_PROBLEM + "-small-test.out");
					FileReader f2 = new FileReader(_SMALLNAME(i) + ".out");
					BufferedReader br1 = new BufferedReader(f1);
					BufferedReader br2 = new BufferedReader(f2);
					for (int j = 1;; j++) {
						String s1 = br1.readLine();
						String s2 = br2.readLine();
						if (s1 == null && s2 == null) {
							System.err.println("OK!");
							break;
						}
						if (s1 == null || s2 == null || !s1.equals(s2)) {
							System.err.println("failed at line " + j);
							System.err.println("expected " + s2);
							System.err.println("but " + s1);
							break;
						}
					}
				} else {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_SMALLNAME(i) + ".out"));
					new A().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new A().run();
			}
		} else
			new A().run();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small"
				+ (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}
