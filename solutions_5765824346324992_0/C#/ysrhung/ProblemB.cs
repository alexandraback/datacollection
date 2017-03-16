using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1A
{


	class Round1A
	{
	
	static void log(string s)
	{
		using (StreamWriter writer = new StreamWriter("log.txt", true))
		{
			writer.WriteLine(s);
		}
	}
	
	
	public static int gcd(int a, int b)
	{  
		if (a > b)
		{
			int temp = b;
			b = a;
			a = temp;
		}
		int r = 0;
		while (true)
		{ 
			r = b % a;
			if (r == 0)
				break;
			b = a;
			a = r;
		}
		return a;
	}

	public static int computeLCM(int a, int b)
	{
		return a * b / gcd(a, b);
	}

	public static int solve(int N, List<int> nums)
	{
		List<int> left = new List<int>();
		for( int i = 0; i < nums.Count; ++i)
		{
			left.Add(0);
		}
		while (true)
		{
			for (int i = 0; i < nums.Count; ++i)
			{
				if (left[i] == 0)
				{
					if (N == 1)
						return i + 1;
					else
					{
						--N;
						left[i] = nums[i];
					}
				}
			}
			
			for (int i = 0; i < nums.Count; ++i)
			{
				left[i]--;
			}

		}
	}
	
	
	static string solveProblem(string line0, string line)
	{
		List<int> temp = new List<int>(line0.Split().Select(token => int.Parse(token)).ToArray());
		int N = temp[1];
		List<int> nums = new List<int>(line.Split().Select(token => int.Parse(token)).ToArray());
		int lcm = nums[0];
		for (int i = 1; i < nums.Count; ++i)
		{
			lcm = computeLCM(lcm, nums[i]);
		}
//		return lcm.ToString();
		int processRate = 0;
		for (int i = 0; i < nums.Count; ++i)
		{
			processRate += (lcm / nums[i]);
		}
		N = N % processRate;
		if (N == 0) N = processRate;
//		Console.WriteLine(lcm + " " +  processRate + " " + N);
		return solve(N, nums).ToString();


	}

        static void Main(string[] args)
        {
		using (StreamReader reader = new StreamReader("B-small-attempt0.in"))
		//using (StreamReader reader = new StreamReader("C-small-practice.in"))
		//using (StreamReader reader = new StreamReader("C-large-practice.in"))
		//using (StreamReader reader = new StreamReader("sample.in"))
		{
			using (StreamWriter writer = new StreamWriter("output.txt"))
			{
				string line = reader.ReadLine();
				int total = int.Parse(line);
				StringBuilder results = new StringBuilder();

				for (int i = 1; i <= total; ++i)
				{
					string tempResult = "Case #" + i.ToString() + ": " + solveProblem(reader.ReadLine(), reader.ReadLine());
	//				Console.WriteLine(tempResult);
					results.AppendLine(tempResult);
					
				}
				writer.WriteLine(results.ToString());

			}
		}
	}
    }
}
