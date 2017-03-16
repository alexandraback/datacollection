using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace GoogleCodeJamV2
{
	public class CodeJam_2015_Round1A_A : ITestCase
	{
		public string GetTitle()
		{
			return "A. Mushroom Monster";
		}

		public Func<string, int> LinesPerTestCase()
		{
			return x => 2;
		}

		public string Run(List<string> lines)
		{
			int n = int.Parse (lines [0]);
			List<int> list = lines[1].Split (' ').Select (x => int.Parse (x.ToString())).ToList ();

			int firstMethod = 0;
			int secondMethod = 0;

			int max = 0;

			for (int i=0; i < n - 1; i++) {
				if (list [i] > list [i + 1]) {
					firstMethod += list [i] - list [i + 1];

					if (max < list [i] - list [i + 1]) {
						max = list [i] - list [i + 1];
					}
				}
			}

			if (max > 0) {
				for (int i=0; i < n - 1; i++) {
					if (list [i] >= max) {
						secondMethod += max;
					} else {
						secondMethod += list [i];
					}
				}
			}

			return string.Format ("{0} {1}", firstMethod, secondMethod);
		}
	}
}

