import java.util.*;

public class A
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());
		String[] s;
		String reduced;
		int[][] counts;
                int strings, moves;
		int last, index;

		ArrayList<Integer> countSet = new ArrayList<Integer>();

		Hashtable<Integer, Integer> common = new Hashtable<Integer, Integer>();

		boolean fWins;

		int i, j;

		while(test <= cases)
		{
			moves = 0;
			fWins = false;

			strings = Integer.parseInt(sc.nextLine());
			s = new String[strings];

			s[0] = sc.nextLine();
			reduced = Reduce(s[0]);

			for(i = 1; i < strings; i++)
			{
				s[i] = sc.nextLine();
				if(!reduced.equals(Reduce(s[i])))
					fWins = true;
			}

			if(!fWins)
			{
				counts = new int[strings][reduced.length()];

				for(i = 0; i < strings; i++)
				{
					last = 0;
					index = 0;

					for(j = 1; j < s[i].length(); j++)
					{
						if(s[i].charAt(j) != s[i].charAt(j - 1))
						{
							counts[i][index] = j - last;
							last = j;
							index++;
						}
					}

					counts[i][index] = j - last;
				}

				for(i = 0; i < reduced.length(); i++)
				{
					common.clear();

					for(j = 0; j < strings; j++)
					{
						if(common.get(counts[j][i]) == null)
							common.put(counts[j][i], 1);
						else common.put(counts[j][i], common.get(counts[j][i]) + 1);
					}

					countSet.clear();
					countSet.addAll(common.keySet());

					Collections.sort(countSet);

					while(countSet.size() > 1)
					{
						if(common.get(countSet.get(0)) * (countSet.get(1) - countSet.get(0)) < common.get(countSet.get(countSet.size() - 1)) * (countSet.get(countSet.size() - 1) - countSet.get(countSet.size() - 2)))
						{
							moves += common.get(countSet.get(0)) * (countSet.get(1) - countSet.get(0));
							common.put(countSet.get(1), common.get(countSet.get(1)) + common.get(countSet.get(0)));
							countSet.remove(0);
						}
						else
						{
							moves += common.get(countSet.get(countSet.size() - 1)) * (countSet.get(countSet.size() - 1) - countSet.get(countSet.size() - 2));
							common.put(countSet.get(countSet.size() - 2), common.get(countSet.get(countSet.size() - 2)) + common.get(countSet.get(countSet.size() - 2)));
							countSet.remove(countSet.size() - 1);
						}
					}
				}
			}

			System.out.print("Case #" + test + ": ");

			if(fWins)
				System.out.println("Fegla Won");
			else System.out.println(moves);

			test++;
		}
	}

	public static String Reduce(String s)
	{
		char c = s.charAt(0);
		String r = "" + c;

		int i;

		for(i = 1; i < s.length(); i++)
		{
			if(s.charAt(i) != c)
			{
				c = s.charAt(i);
				r += c;
			}
		}

		return r;
	}
}