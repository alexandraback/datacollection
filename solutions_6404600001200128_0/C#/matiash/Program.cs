using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MushroomMonster
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("A-small-attempt0.in");
			OutputFile output = new OutputFile("output.txt");

			int[] values = input.ReadIntArray();
			int TEST_COUNT = values[0];

			for (int i = 0; i < TEST_COUNT; i++)
			{
				TestCase testCase = new TestCase(input);
				output.WriteCase(i + 1, testCase.GetSolution());
			}

			output.Close();
		}
	}

	class TestCase
	{
		private readonly int[] m_Measurements;

		public TestCase(InputFile input)
		{
			input.ReadLine();
			m_Measurements = input.ReadIntArray();
		}

		public string GetSolution()
		{
			int total1 = 0;
			int minimumEatingPerPeriod = 0;
			for (int i = 1; i < m_Measurements.Length; i++)
			{
				int diff = -(m_Measurements[i] - m_Measurements[i - 1]);
				if (diff > 0)
					total1 += diff;

				if (diff > minimumEatingPerPeriod)
					minimumEatingPerPeriod = diff;
			}

			int total2 = 0;
			for (int i = 1; i < m_Measurements.Length; i++)
			{
				int diff = -(m_Measurements[i] - m_Measurements[i - 1]);
				int eating = Math.Min(Math.Max(diff, minimumEatingPerPeriod), m_Measurements[i-1]);
				total2 += eating;
			}

			return total1.ToString() + " " + total2.ToString();
		}
	}
}
