import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.List;

public class Repeater {

	public static void main(String[] args) throws Exception {
		Repeater object = new Repeater();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase()
				+ ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		for (int tc = 1; tc <= testCases; tc++) {
			st.nextToken();
			int n = (int) st.nval;

			List<String> strings = new ArrayList<>();

			for (int i = 0; i < n; i++) {
				st.nextToken();
				strings.add(st.sval);
			}

			int output = object.solve(strings);

			if (output == -1)
				wr.write("Case #" + tc + ": " + "Fegla Won" + "\r\n");
			else
				wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		wr.close();
	}

	private int solve(List<String> strings) {

		List<ArrayList<String>> parts = new ArrayList<ArrayList<String>>();

		for (String s : strings) {
			parts.add(split(s));
		}

		for (int i = 0; i < strings.size(); i++)
			for (int j = i + 1; j < strings.size(); j++) {

				List<String> parts1 = parts.get(i);
				List<String> parts2 = parts.get(j);

				if (parts1.size() != parts2.size())
					return -1;

				for (int z = 0; z < parts1.size(); z++)
					if (parts1.get(z).charAt(0) != parts2.get(z).charAt(0))
						return -1;
			}

		List<String> parts0 = parts.get(0);

		int result = 0;

		for (int z = 0; z < parts0.size(); z++) {

			int best = 1000000000;

			for (int rep = 1; rep < 102; rep++) {

				int counter = 0;

				for (int i = 0; i < strings.size(); i++) {
					int cur = parts.get(i).get(z).length();

					counter += Math.abs(cur - rep);
				}

				best = Math.min(best, counter);
			}

			result += best;
		}

		return result;

	}

	private ArrayList<String> split(String s) {
		ArrayList<String> result = new ArrayList<>();

		for (int pos = 0; pos < s.length(); pos++) {

			StringBuilder next = new StringBuilder();
			next.append(s.charAt(pos) + "");

			for (int k = pos + 1; k < s.length()
					&& s.charAt(k) == s.charAt(pos); k++) {
				pos = k;
				next.append(s.charAt(pos) + "");
			}

			result.add(next.toString());
		}

		return result;
	}

}
