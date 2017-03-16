using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Haircut
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("B-small-attempt1.in");
			OutputFile output = new OutputFile("output.txt");

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
		private readonly int[] m_BarberTimes;
		private readonly int m_PlaceInLine;

		public TestCase(InputFile input)
		{
			int[] parameters = input.ReadIntArray();
			m_PlaceInLine = parameters[1];
			m_BarberTimes = input.ReadIntArray();
		}

		public int GetSolution()
		{
			// See how much we can calculate fast.
			long cycleLength = lcm(m_BarberTimes);
			long customersPerCycle = 0;
			for (int i = 0; i < m_BarberTimes.Length; i++)
			{
				Debug.Assert(cycleLength % m_BarberTimes[i] == 0);
				customersPerCycle += cycleLength / m_BarberTimes[i];
			}

			return Calculate((m_PlaceInLine - 1) % customersPerCycle);
		}

		public static long lcm(int[] numbers)
		{
			if (numbers.Length == 1)
				return numbers[0];

			long result = lcm(numbers[0], numbers[1]);
			for (int i = 2; i < numbers.Length; i++)
				result = lcm(result, numbers[i]);

			return result;
		}

		public static long lcm(long a, long b)
		{
			long num1, num2;
			if (a > b)
			{
				num1 = a;
				num2 = b;
			}
			else
			{
				num1 = b;
				num2 = a;
			}

			for (long i = 1; i <= num2; i++)
			{
				if ((num1 * i) % num2 == 0)
				{
					return i * num1;
				}
			}
			return num2;
		}

		public int Calculate(long peopleInFront)
		{
			if (peopleInFront == 0)
				return 1;

			int[] timeRemaining = new int[m_BarberTimes.Length];

			while (true)
			{
				// Fill unused barbers.
				for (int i = 0; i < timeRemaining.Length; i++)
				{
					if (timeRemaining[i] == 0)
					{
						timeRemaining[i] = m_BarberTimes[i];
						peopleInFront--;
					}

					if (peopleInFront == -1)
						return i + 1; // The barber that took us!
				}

				// Make time run.
				int untilNext = timeRemaining.Min();
				for (int i = 0; i < timeRemaining.Length; i++)
					timeRemaining[i] -= untilNext;
			}

			throw new Exception("This should never happen");
		}
	}
}
