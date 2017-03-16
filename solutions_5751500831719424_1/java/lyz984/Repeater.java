package round1b;

import java.util.*;
import java.util.Map.Entry;

public class Repeater {
	
	private static int test(Scanner scanner) {
		int N = scanner.nextInt();
		scanner.nextLine();
		String[] strings = new String[N];
		for (int i = 0; i < strings.length; i++) {
			strings[i] = scanner.nextLine();
			// System.err.println("\"" + strings[i] + "\"");
		}
		
		String[] shortStrings = new String[N];

		List<List<Entry<Character, Integer>>> entries = new ArrayList<List<Entry<Character, Integer>>>(N);
		for (int i = 0; i < strings.length; i++) {
			String string = strings[i];
			StringBuilder sb = new StringBuilder();
			List<Entry<Character, Integer>> list = new LinkedList<Entry<Character, Integer>>();
			char ch = string.charAt(0);
			int count = 1;
			for (int j = 1; j < string.length(); j++) {
				if (string.charAt(j) == ch) {
					count++;
				} else {
					sb.append(ch);
					list.add(new AbstractMap.SimpleEntry<Character, Integer>(ch, count));
					ch = string.charAt(j);
					count = 1;
				}
			}
			sb.append(ch);
			list.add(new AbstractMap.SimpleEntry<Character, Integer>(ch, count));
			shortStrings[i] = sb.toString();
			// System.err.println("\"" + shortStrings[i] + "\"");
			entries.add(list);
		}

		String shortString = shortStrings[0];
		for (int i = 1; i < shortStrings.length; i++) {
			if (!shortString.equals(shortStrings[i])) {
				// System.err.println("-1");
				return -1;
			}
		}
		
		int allActions = 0;
		for (int i = 0; i < shortString.length(); i++) {
			int[] values = new int[entries.size()];
			int j = 0;
			for (List<Entry<Character, Integer>> list : entries) {
				values[j] = list.get(i).getValue();
				j++;
			}
			Arrays.sort(values);
			int min = Integer.MAX_VALUE;
			for (int k = values[0]; k <= values[values.length-1]; k++) {
				int actions = 0;
				for (j = 0; j < values.length; j++) {
					actions += Math.abs(k - values[j]);
				}
				// System.err.println("actions: " + actions);
				if (actions < min) {
					min = actions;
				}
			}
			// System.err.println("min: " + min);
			allActions += min;
		}
		
		return allActions;
	}

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in))
		{
			int cntTests = scanner.nextInt();
			for (int i = 0; i < cntTests; i++) {
				int result = test(scanner);
				System.out.println("Case #" + (i+1) + ": " + (result < 0 ? "Fegla Won" : Integer.toString(result)));
			}
		}
	}

}
