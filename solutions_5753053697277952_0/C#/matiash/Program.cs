using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SenateEvacuation
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("A-small-attempt0.in");
			OutputFile output = new OutputFile("output-small.txt");

			int[] values = input.ReadIntArray();
			int TEST_COUNT = values[0];

			for (int i = 0; i < TEST_COUNT; i++)
			{
				TestCase testCase = new TestCase(input);
				output.WriteCase(i + 1, testCase.GetSolution().ToString());
			}

			output.Close();
		}
	}

	class TestCase
	{
		private readonly int[] m_Counts;

		public TestCase(InputFile input)
		{
			input.ReadIntArray();
			m_Counts = input.ReadIntArray();
		}

		internal object GetSolution()
		{
			List<String> plan = new List<string>();

			// First make even
			if ((m_Counts.Sum() % 2) == 1)
			{
				int maxPos = m_Counts.ToList().IndexOf(m_Counts.Max());

				plan.Add(((char)(maxPos + 'A')).ToString());
				m_Counts[maxPos] = m_Counts[maxPos] - 1;
			}

			while (m_Counts.Sum() != 0)
			{
				int maxPos = m_Counts.ToList().IndexOf(m_Counts.Max());
				m_Counts[maxPos] = m_Counts[maxPos] - 1;
				String first = ((char)(maxPos + 'A')).ToString();

				maxPos = m_Counts.ToList().IndexOf(m_Counts.Max());
				m_Counts[maxPos] = m_Counts[maxPos] - 1;
				String second = ((char)(maxPos + 'A')).ToString();

				plan.Add(first + second);
			}

			return String.Join(" ", plan);
		}
	}
}
