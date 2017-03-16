using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Qualification
{


	class Qualification
	{
	
	static void log(string s)
	{
		using (StreamWriter writer = new StreamWriter("log.txt", true))
		{
			writer.WriteLine(s);
		}
	}
	

	static int timeNeeded(List<int> p, List<int> config, int special)
	{
		int max = 0;
		for (int i = 0; i < p.Count; ++i)
		{
			int length = 0;
			if (config[i] > 0)
			{
				if (p[i] % (config[i] + 1) > 0)
				{
					length = p[i] / (config[i]+1) + 1;
				}
				else
				{
					length = p[i] / (config[i]+1);
				}
			}
			else 
			{
				length = p[i];
			}
			if (length > max)
				max = length;
		}
		return max + special;
	}
	
	static int computeBestIndex(List<int> p, List<int> config)
	{
		double max = -1.0;
		int index = -1;
		for (int i = 0; i < p.Count; ++i)
		{
			double length = (p[i] * 1.0) / config[i];
			if (length > max)
			{
				max = length;
				index = i;
			}
		}
		return index;
	}
	
	static int method1(List<int> nums)
	{
		int prev = nums[0];
		int total = 0;
		for (int i =1; i < nums.Count; ++i)
		{
			if (nums[i] < prev)
			{
				total += (prev - nums[i]);
			}
			prev = nums[i];
		}
		return total;
	}
	
	
	static int method2(List<int> nums)
	{
		int prev = nums[0];
		int maxRate = 0, diff = 0;
		int total = 0;
		for (int i =1; i < nums.Count; ++i)
		{
			diff = prev - nums[i];
			if (diff > maxRate)
			{
				maxRate = diff;
			}
			prev = nums[i];
		}
		prev = nums[0];
		for (int i =1; i < nums.Count; ++i)
		{
			if (prev > 0)
			{
				if (prev > maxRate)
				{
					total += maxRate;
				}
				else
				{
					total += prev;
				}
			}
			prev = nums[i];
		}

		return total;
	}
	
	static string solveProblem(string line0, string line)
	{
		List<int> nums = new List<int>(line.Split().Select(token => int.Parse(token)).ToArray());

		return method1(nums).ToString() + " " + method2(nums).ToString();
		


	}

        static void Main(string[] args)
        {
		using (StreamReader reader = new StreamReader("A-small-attempt0.in"))
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
