import java.util.*;

public class A
{
	static StringBuilder out = new StringBuilder();
	
	public static void main(String [] args)
	{
		Scanner sc = new Scanner(System.in);
		int numTests = sc.nextInt();
		for(int test = 1; test <= numTests; test++)
		{
			out.append(String.format("Case #%d: ", test));
			
			int n = sc.nextInt();
			
			String[] strings = new String[n];
			for(int i = 0; i < n; i++)
				strings[i] = sc.next();
			
			if(!possible(strings)){
				out.append("Fegla Won" + "\n");
				continue;
			}
			ArrayList<ArrayList<Integer>> grid = convertStringsToIntArrays(strings);
			/*
			System.out.println("Test " + test);
			for(int i = 0; i < grid.size(); i++)
			{
				for(int j = 0; j < grid.get(i).size(); j++)
				{
					System.out.print(grid.get(i).get(j) + " ");
				}
				System.out.println();
			}
			*/
			int minCost = findMinCost(grid);
			out.append(minCost + "\n");
		}
		System.out.print(out.toString());
	}
	static int findMinCost( ArrayList<ArrayList<Integer>> grid )
	{		
		int totalMinCost = 0;
		for(int i = 0; i < grid.get(0).size(); i++)
		{
			int minCostForAnyQuant = Integer.MAX_VALUE;
			for(int k = 1; k <= 100; k++)
			{
				int costForThisQuant = 0;
				for(int j = 0; j < grid.size(); j++)
				{
					costForThisQuant += Math.abs(grid.get(j).get(i) - k);
				}
				minCostForAnyQuant = Math.min(minCostForAnyQuant,costForThisQuant);
			}
			totalMinCost += minCostForAnyQuant;
		}
		return totalMinCost;
	}
	static boolean possible(String[] strings)
	{
		int numStrings = strings.length;
		int[] ind = new int[strings.length]; //numStrings
		int numAtEnd = 0;
		for(int i = 0; ; i++)
		{
			
			if(numAtEnd == numStrings)
				return true;
			if(numAtEnd > 0)
				return false;
			
			char c = strings[0].charAt(ind[0]);
			for(int j = 1; j < numStrings; j++)
			if(strings[j].charAt(ind[j]) != c)
				return false;
			
			for(int j = 0; j < numStrings; j++)
			{
				while(ind[j] < strings[j].length() && strings[j].charAt(ind[j]) == c)
					ind[j]++;
				if(ind[j] == strings[j].length())
					numAtEnd++;
			}
		}
	}
	static ArrayList<ArrayList<Integer>> convertStringsToIntArrays(String[] strings)
	{
		int n = strings.length;
		ArrayList<ArrayList<Integer>> grid = new ArrayList<ArrayList<Integer>>();
		for(String s : strings)
		{
			ArrayList<Integer> row = new ArrayList<Integer>();
			char c = s.charAt(0);
			int count = 1;

			for(int i = 1; i < s.length(); i++)
			{
				if(c == s.charAt(i))
					++count;
				else
				{
					row.add(count);
					c = s.charAt(i);
					count = 1;
				}
			}
			row.add(count);
			grid.add(row);
		}
		return grid;
	}
	
}


/*
			
			
			int[][] graph = new int[n][n];
			
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					graph[i][j] = aToBCost(strings[i].toCharArray(), strings[j].toCharArray());
				}
			}
			
			int minCost = Integer.MAX_VALUE;
			int minI = -1;
			CHECK:
			for(int i = 0; i < n; i++)
			{
				int totalCost = 0;
				for(int j = 0; j < n; j++)
				{
					if(graph[i][j] == -1)
						continue CHECK;
					totalCost += graph[i][j];
				}
				if(totalCost < minCost)
				{
					minCost = totalCost;
					minI = i;
				}
			}
			
			System.out.println(test + ": " + minI);
			
			if(minI != -1)
			for(int j = 0; j < graph[minI].length; j++)
				System.out.println(j + ":: " + graph[minI][j]);
			
			if(minCost == Integer.MAX_VALUE)
				out.append("Fegla Won" + "\n");
			else
				out.append(minCost + "\n");
		}
		System.out.print(out.toString());
	}
	static boolean possible(char[] a, char[] b)
	{

	}
	static int aToBCost(char[] a, char[] b)
	{
		if(!possible(a, b))
			return -1;
		
		int bInd = 0;
		int aInd = 0;
		int cost = 0;
		while(true)
		{
			int aStart = aInd;
			int bStart = bInd;
			
			if(aInd == a.length)
				break;
			char c = b[bInd];
			while(aInd < a.length && a[aInd] == c)
				aInd++;
			while(bInd < b.length && b[bInd] == c)
				bInd++;
			
			cost += Math.abs((aInd - aStart) - (bInd - bStart));
		}
		return cost;
	}
}
*/