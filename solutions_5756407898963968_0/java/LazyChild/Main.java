import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int firstAnswer = in.nextInt() - 1;
        int[][] firstCards = new int[4][4];
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                firstCards[i][j] = in.nextInt();
            }
        }
        int secondAnswer = in.nextInt() - 1;
        int[][] secondCards = new int[4][4];
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                secondCards[i][j] = in.nextInt();
            }
        }

        int[] firstRow = firstCards[firstAnswer];
        int[] secondRow = secondCards[secondAnswer];

        int count = 0;
        int answer = -1;
        for (int first : firstRow) {
            boolean find = false;
            for (int second : secondRow) {
                if (first == second) {
                    find = true;
                    break;
                }
            }
            if (find) {
                ++count;
                answer = first;
            }
        }
        out.printf("Case #%d: ", testNumber);
        if (count == 0) {
            out.println("Volunteer cheated!");
        } else if (count > 1) {
            out.println("Bad magician!");
        } else {
            out.println(answer);
        }
    }
}

