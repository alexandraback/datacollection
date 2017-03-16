import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.List;
import java.util.stream.Stream;
import java.util.Collection;
import java.util.Scanner;
import java.util.Optional;
import java.util.stream.Collectors;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author wannabe
 */
public class Main {

	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("task.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("task.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task {

		final static String alphabet = "abcdefghijklmnopqrstuvwxyz";

		public void solve(int testNumber, Scanner in, PrintWriter out) {
			int t = in.nextInt();
			for (int i = 1; i <= t; i++) {
				int n = in.nextInt();
				List<Integer> senators = new ArrayList<>();
				for (int j = 0; j < n; j++) {
					senators.add(in.nextInt());
				}
				out.println("Case #" + i + ": " + solve(senators));
			}
		}

		private String solve(List<Integer> senators) {
			int n = senators.size();
			List<String> order = new ArrayList<>();
			while (true) {
				if (senators.stream().mapToInt(Integer::intValue).sum() == 0) {
					break;
				}
				for (int i = 0; i < senators.size(); i++) {
					final int sum = senators.stream().mapToInt(Integer::intValue).sum();
					if (senators.get(i) == 0) {
						continue;
					}
					senators.set(i, senators.get(i) - 1);
					Optional<Integer> superior = IntStream.range(0, senators.size()).boxed().filter(index -> 2 * senators.get(index) > (sum - 1)).findFirst();
					if (!superior.isPresent()) {
						order.add(alphabet.substring(i, i + 1).toUpperCase());
					} else {
						senators.set(superior.get(), senators.get(superior.get()) - 1);
						Optional<Integer> anotherSuperior = IntStream.range(0, senators.size()).boxed().filter(index -> 2 * senators.get(index) > (sum - 2)).findFirst();
						if (!anotherSuperior.isPresent()) {
							order.add(alphabet.substring(i, i + 1).toUpperCase() + alphabet.substring(superior.get(), superior.get() + 1).toUpperCase());
						} else {
							senators.set(i, senators.get(i) + 1);
							senators.set(i, senators.get(superior.get()) + 1);
						}
					}
				}
			}
			return order.stream().collect(Collectors.joining(" "));
		}

	}
}

