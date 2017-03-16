import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class ProbMagicTrick
{
	public static void main(final String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new FileReader(new File(
				"data11.txt")));
		PrintWriter writer = new PrintWriter(new FileWriter(new File(
				"out11.txt")));
		int noCases = Integer.parseInt(reader.readLine());
		for (int testCase = 1; testCase <= noCases; testCase++) {
			int answer1 = Integer.parseInt(reader.readLine());
			ArrayList<Integer> row1 = new ArrayList<Integer>();
			for (int r = 1; r <= 4; r++) {
				String[] row = reader.readLine().split(" ");
				if (r == answer1) {
					row1.add(Integer.parseInt(row[0]));
					row1.add(Integer.parseInt(row[1]));
					row1.add(Integer.parseInt(row[2]));
					row1.add(Integer.parseInt(row[3]));
				}
			}
			int answer2 = Integer.parseInt(reader.readLine());
			ArrayList<Integer> row2 = new ArrayList<Integer>();
			for (int r = 1; r <= 4; r++) {
				String[] row = reader.readLine().split(" ");
				if (r == answer2) {
					row2.add(Integer.parseInt(row[0]));
					row2.add(Integer.parseInt(row[1]));
					row2.add(Integer.parseInt(row[2]));
					row2.add(Integer.parseInt(row[3]));
				}
			}
			row2.retainAll(row1);
			if(row2.size() == 0)
				writer.printf("Case #%d: Volunteer cheated!%n", testCase);
			else if(row2.size() == 1)
				writer.printf("Case #%d: %d%n", testCase,row2.get(0));
			else
				writer.printf("Case #%d: Bad magician!%n", testCase);
		}
		writer.close();
		reader.close();
	}
}
