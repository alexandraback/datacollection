import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

public class TheRepeater {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			List<Stack<Character>> stackList = new ArrayList<Stack<Character>>();
			// List<List<Character>> list = new ArrayList<List<Character>>();
			// List<Iterator<Character>> iterList = new ArrayList<Iterator<Character>>();
			int n = sc.nextInt();
			for (int j = 0; j < n; j++) {
				String word = sc.next();
				char[] charArray = word.toCharArray();
				// List<Character> charList = new LinkedList<Character>();
				Stack<Character> stack = new Stack<Character>();
				for (char c : charArray) {
					// charList.add(c);
					stack.push(c);
				}
				// iterList.add(charList.iterator());
				// list.add(charList);
				stackList.add(stack);
			}

			int ans = 0;

			outer: while (true) {
				Set<Character> set = new HashSet<Character>();
				List<Integer> repeatList = new ArrayList<Integer>();
				boolean everyStackEmpty = true;
				for (Stack<Character> stack : stackList) {
					if (!stack.empty()) {
						everyStackEmpty = false;
						break;
					}
				}
				if (everyStackEmpty) {
					// success
					break outer;
				}
				middle: for (Stack<Character> stack : stackList) {
					if (stack.isEmpty()) {
						//fail
						ans=-1;
						break outer;
					}
					int count = 0;
					while (true) {
						if (stack.isEmpty()) {
							// Done with last character type
							break;
						}
						Character ch = stack.pop();
						set.add(ch);
						if (set.size() > 1) {
							if (count == 0) {
								// fail
								ans = -1;
								break outer;
							}
							set.remove(ch);
							stack.push(ch);
							// done with non-last character type
							break;
						}
						count++;
					}
					repeatList.add(count);

				}
				Collections.sort(repeatList);
				int median = repeatList.get(repeatList.size() / 2);
				int score = 0;
				for (Integer count : repeatList) {
					score += Math.abs(median - count);
				}
				ans += score;

			}


			if (ans >= 0) {
				System.out.println("Case #" + (i + 1) + ": " + ans);
			} else {
				System.out.println("Case #" + (i + 1) + ": Fegla Won");
			}

		}

	}


}
