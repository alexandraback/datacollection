package gcj2016.c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.TreeMap;

public class ProblemA {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File(args[0])));
		int lineNum = Integer.parseInt(reader.readLine());
		ProblemA problemA = new ProblemA();
		for (int i = 0; i < lineNum; ++i) {
			int teamNum = Integer.parseInt(reader.readLine());
			String tokens[] = reader.readLine().split(" ");
			Map<String, Integer> members = new TreeMap<>();
			for (int j = 0; j < teamNum; ++j) {
				String key = String.valueOf((char) (j + 65));
				Integer value = new Integer(tokens[j]);
				members.put(key, value);
			}
			List<Map.Entry<String, Integer>> list = new ArrayList<>(members.entrySet());

			List<String> result = problemA.solve(list, new ArrayList<String>());
			System.out.print("Case #" + (i + 1) + ": ");
			for (String elem : result) {
				System.out.print(elem + " ");
			}
			System.out.println("");
		}
	}

	private List<String> solve(List<Map.Entry<String, Integer>> list, List<String> previousResult) {
		Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
			@Override
			public int compare(Entry<String, Integer> arg0, Entry<String, Integer> arg1) {
				return arg1.getValue().compareTo(arg0.getValue());
			}
		});

		Map.Entry<String, Integer> first = list.get(0);
		if (first.getValue() <= 0) {
			return previousResult;
		}

		Map.Entry<String, Integer> second = list.get(1);

		Map.Entry<String, Integer> third = list.size() >= 3 ? list.get(2) : null;

		if (first.getValue() > second.getValue()) {
			previousResult.add(first.getKey());
			list.get(0).setValue(first.getValue() - 1);
			return solve(list, previousResult);
		} else {
			if (third == null || third.getValue() == 0) {
				previousResult.add(first.getKey() + second.getKey());
				list.get(0).setValue(first.getValue() - 1);
				list.get(1).setValue(second.getValue() - 1);
				return solve(list, previousResult);
			}else{
				previousResult.add(first.getKey());
				list.get(0).setValue(first.getValue() - 1);
				return solve(list, previousResult);				
			}
		}
	}

}
