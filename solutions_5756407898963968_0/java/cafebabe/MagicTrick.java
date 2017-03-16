import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MagicTrick {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("output_a.out"));
		int numOfTests = in.nextInt();
		for (int test = 1; test <= numOfTests; test++) {
			int firstRow = in.nextInt();
			int currentRow = 1;
			in.nextLine();
			while (currentRow < firstRow) {
				in.nextLine();
				currentRow++;
			}
			List<Integer> firstNums = new ArrayList<Integer>();
			firstNums.add(in.nextInt());
			firstNums.add(in.nextInt());
			firstNums.add(in.nextInt());
			firstNums.add(in.nextInt());
			while (currentRow <= 4) {
				in.nextLine();
				currentRow++;
			}
			currentRow = 1;
			int secondRow = in.nextInt();
			in.nextLine();
			while (currentRow < secondRow) {
				in.nextLine();
				currentRow++;
			}
			List<Integer> secondNums = new ArrayList<Integer>();
			secondNums.add(in.nextInt());
			secondNums.add(in.nextInt());
			secondNums.add(in.nextInt());
			secondNums.add(in.nextInt());
			while (currentRow <= 4) {
				in.nextLine();
				currentRow++;
			}
			final List<Integer> intersection = intersect(firstNums, secondNums);
			if (intersection.isEmpty()) {
				out.println(String.format("Case #%d: Volunteer cheated!", test));
			} else if (intersection.size() > 1) {
				out.println(String.format("Case #%d: Bad magician!", test));
			} else {
				out.println(String.format("Case #%d: %d", test, intersection.get(0)));
			}
		}
		out.close();
		in.close();
	}
	
	private static List<Integer> intersect(List<Integer> first, List<Integer> second) {
		final List<Integer> result = new ArrayList<Integer>();
		for (final Integer elem: first) {
			if (second.contains(elem)){
				result.add(elem);
			}
		}
		return result;
	}
 
}
