package gcj.y2014r1b;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Q1 {

	static int solve(String arr[]) {
		int len = arr.length;
		char current = (char) -1;
		int[] pointer = new int[len];
		int clens[] = new int[len];
		// Arrays.fill(pointer, -1);
		int ret = 0;
		while (true) {
			Arrays.fill(clens, 0);
			for (int i = 0; i < len; i++) {

				if (i == 0) {
					if (pointer[i] == arr[i].length()) {
						for (int k = 1; k < len; k++) {
							if (pointer[k] != arr[k].length()) {
								return -1;
							}
						}
						return ret;
					}
					current = arr[i].charAt(pointer[i]);
					pointer[i]++;
					clens[i]++;
					while (pointer[i] < arr[i].length()) {
						if (arr[i].charAt(pointer[i]) == current) {
							pointer[i]++;
							clens[i]++;
						} else {
							break;
						}
					}
				}

				else {
					while (pointer[i] < arr[i].length()) {
						if (arr[i].charAt(pointer[i]) == current) {
							pointer[i]++;
							clens[i]++;
						} else {
							break;
						}
					}
					if (clens[i] == 0) {
						return -1;
					}
				}

			}
			int tmp = doSolve(clens);
			//System.err.println(tmp);
			ret += tmp;
		}
	}

	private static int doSolve(int[] clens) {
		for (int i = 0; i < clens.length; i++) {
			//System.err.format("%d.", clens[i]);
		}
		//System.err.println("");
		// System.out.println("solved");
		Arrays.sort(clens);
		int len = clens.length;
		int ret = 0;
		if (len % 2 == 1) {
			int mid = len / 2;
			for (int i = 0; i < len; i++) {
				ret += Math.abs(clens[i] - clens[mid]);
			}
			return ret;

		} else {
			int ret1 = 0;
			int ret2 = 0;
			int vmid1 = (clens[len / 2] + clens[len / 2 - 1]) / 2;
			int vmid2 = vmid1 + 1;
			for (int i = 0; i < len; i++) {
				ret1 += Math.abs(clens[i] - vmid1);
				ret2 += Math.abs(clens[i] - vmid2);
			}
			return Math.min(ret1, ret2);
		}

	}

	static class Node {
		ArrayList<Integer> nb = new ArrayList<Integer>();

		public Node() {
		};
	}

	private static String resultString(int i) {
		if (i >= 0) {
			return String.valueOf(i);
		}
		return "Fegla Won";
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int nCase = s.nextInt();
		for (int i = 1; i <= nCase; i++) {
			int nString = s.nextInt();
			s.nextLine();
			String[] arr = new String[nString];
			for (int j = 0; j < nString; j++) {
				arr[j] = s.nextLine();
				// System.out.format("line %d: %s\n", j, arr[j]);
			}

			System.out.format("Case #%d: %s\n", i, resultString(solve(arr)));
		}

	}

}
