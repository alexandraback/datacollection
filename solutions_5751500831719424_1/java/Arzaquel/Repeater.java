package round1b;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import org.apache.commons.lang3.ArrayUtils;

public class Repeater {

	public static void solve(Scanner in)
	{
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int n = in.nextInt();
			ArrayList<ArrayList<Integer>> nchars = new ArrayList<ArrayList<Integer>>();
			ArrayDeque<Character> chars = null;
			boolean feglaWon = false;
			
			for (int j = 0; j < n; j++) {
				String s = in.next();
				if(feglaWon)
					continue;
				char c[] = s.toCharArray();
				ArrayList<Integer> count = new ArrayList<>();
				nchars.add(count);
				ArrayDeque<Character> queue = new ArrayDeque<Character>();
				for (int k = 0; k < c.length; k++) {
					if(queue.isEmpty() || queue.getLast() != c[k])
					queue.add(c[k]);
				}
				if(chars == null)
				{
					chars = queue;
				}
				else
				{
					if(!ArrayUtils.isEquals(chars.toArray(), queue.toArray()))
					{
						feglaWon = true;
						
					}
				}
				char prev = c[0];
				int reps = 1;
				for (int k = 1; k < c.length; k++) {
					if(c[k] == prev)
						reps++;
					else
					{
						count.add(reps);
						reps = 1;
						prev = c[k];
					}
				}
				count.add(reps);
			}
			if(feglaWon)
				System.out.format("Case #%d: Fegla Won\n", i+1);
			else
			{
				int totalsum = 0;
				for (int j = 0; j < chars.size(); j++) {
					int charcount[] = new int[n];
					for (int k = 0; k < n; k++) {
						charcount[k] = nchars.get(k).get(j);
					}
					Arrays.sort(charcount);
					int median = charcount[charcount.length/2];
					int sum = 0;
					for (int k = 0; k < charcount.length; k++) {
						sum += Math.abs(median - charcount[k]);
					}
					totalsum += sum;
				}
				System.out.format("Case #%d: %d\n", i+1, totalsum);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		solve(in);
	}

}
