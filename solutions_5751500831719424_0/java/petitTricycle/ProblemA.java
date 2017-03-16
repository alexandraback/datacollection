import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class ProblemA {

	public static int getNextInt() throws IOException {
		int current = 0, res = 0;
		while (current < 48 || current > 57)
			current = System.in.read();
		;
		while (current >= 48 && current <= 57) {
			res = (current - 48) + res * 10;
			current = System.in.read();
		}
		return res;
	}

	public static int getNextLine(int[] chars, int[] quant) throws IOException {
		int current = 0, last;
		int i = 0;
		chars[i] = 0;
		while (current < 97 || current > 122)
			current = System.in.read();
		;
		last = current;
		chars[0] = current;
		quant[0] = 1;
		while (current >= 97 && current <= 122) {
			current = System.in.read();
			if (current == last)
				quant[i]++;
			else {
				i++;
				quant[i] = 1;
				chars[i] = current;
			}
			last = current;
		}
		return i;
	}

	public static void main(String[] args) throws IOException {
		int cases = getNextInt();
		PrintWriter PW = new PrintWriter(System.out);
		String cas = "Case #";
		String dot = ": ";
		String fegla = "Fegla Won";
		int[][] quants = new int[100][100];
		int[][] chars = new int[100][100];
		int[] len = new int[100];
		int N;
		boolean feg;
		int length;
		int res;

		for (int c = 1; c <= cases; c++) {
			N = getNextInt();
			PW.print(cas);
			PW.print(c);
			PW.print(dot);

			for (int i = 0; i < N; i++)
				len[i] = getNextLine(chars[i], quants[i]);

			feg = false;
			length = len[0];
			for (int i = 1; i < N; i++)
				if (length != len[i]) {
					feg = true;
					i = N;
				}
			if (feg) {
				PW.println(fegla);
				continue;
			}
			for (int i = 1; i < N; i++)
				for (int j = 0; j < length; j++)
					if (chars[i][j] != chars[0][j]) {
						i = N;
						j = length;
						feg = true;
					}

			if (feg) {
				PW.println(fegla);
				continue;
			}

			res = 0;
			for (int j = 0; j < length; j++) {
				for (int i = 0; i < N; i++) {
					len[i] = quants[i][j];
				}
				Arrays.sort(len,0,N);
				for(int k = 0;2*k<N-1;k++)
					res+=len[N-1-k]-len[k];
			}

			PW.println(res);
		}
	PW.close();
	}
}
