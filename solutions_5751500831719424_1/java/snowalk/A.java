/**
 * 
 */
package google.codejam.fourteen.oneB;

import google.codejam.tools.QuestionFile;

import java.io.IOException;

/**
 * @author ya
 * 
 */
public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		QuestionFile file = new QuestionFile(
				A.class.getResourceAsStream("A-large.in"), "A.out");
		int queNum = file.getLength();
		try {
			for (int t = 0; t < queNum; t++) {
				String line = file.getLine();
				int strn = Integer.parseInt(line);
				String[] strings = new String[strn];
				for (int i = 0; i < strn; i++) {
					strings[i] = file.getLine();
				}

				int result = solve(strings, strn);
				if (result == -1)
					file.writeAns(t, "Fegla Won");
				else
					file.writeAns(t, result);
			}
			file.end();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public static int solve(String[] str, int n) {

		char[][] chars = new char[n][];
		for (int i = 0; i < n; i++) {
			chars[i] = str[i].toCharArray();
		}

		int count = 0;
		char last = chars[0][0];
		for (int i = 0; i < n; i++)
			if (chars[i][0] != last)
				return -1;

		for (int i = 1;; i++) {
			int same = 0;
			int diff = 0;
			char thischar = '\0';
			int end = 0;
			for (int j = 0; j < n; j++) {
				if (chars[j].length > i && last == chars[j][i])
					same++;
				else if (chars[j].length <= i) {
					if (thischar == '\0')
						thischar = '\n';
					else if (thischar != '\n')
						return -1;
					end++;
					if (end == n)
						return count;
					diff++;
				} else {
					if (thischar == '\0')
						thischar = chars[j][i];
					else if (thischar != chars[j][i])
						return -1;
					diff++;
				}
			}

			if (diff == n)
				last = thischar;
			else if (diff != 0) {
				if (same >= diff) {
					count += diff;
					addchar(chars, last, i, n);
				} else {
					count += same;
					delchar(chars, last, i, n);
					i--;
				}
			}
		}

	}

	public static void addchar(char[][] matrix, char ch, int p, int n) {
		for (int i = 0; i < n; i++) {
			if (matrix[i].length <= p || matrix[i][p] != ch) {
				char[] newch = new char[matrix[i].length + 1];
				for (int j = 0; j < newch.length; j++) {
					if (j < p) {
						newch[j] = matrix[i][j];
					} else if (j == p) {
						newch[j] = ch;
					} else {
						newch[j] = matrix[i][j - 1];
					}
				}
				matrix[i] = newch;
			}
		}
	}

	public static void delchar(char[][] matrix, char ch, int p, int n) {
		for (int i = 0; i < n; i++) {
			if (matrix[i].length > p && matrix[i][p] == ch) {
				char[] newch = new char[matrix[i].length - 1];
				for (int j = 0; j < newch.length; j++) {
					if (j < p) {
						newch[j] = matrix[i][j];
					} else {
						if (j + 1 < matrix[i].length)
							newch[j] = matrix[i][j + 1];
					}
				}
				matrix[i] = newch;
			}
		}
	}

}
