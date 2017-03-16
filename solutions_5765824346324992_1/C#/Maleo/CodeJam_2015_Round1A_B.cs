using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Linq;

namespace GoogleCodeJamV2
{
	public class CodeJam_2015_Round1A_B : ITestCase
	{
		public string GetTitle()
		{
			return "B. Haircut";
		}

		public Func<string, int> LinesPerTestCase()
		{
			return x => 2;
		}

		public string Run(List<string> lines)
		{
			int barbers = int.Parse (lines [0].Split (' ') [0]);
			int positionInLine = int.Parse(lines [0].Split (' ') [1]);

			List<int> times = lines[1].Split (' ').Select (x => int.Parse (x.ToString())).ToList ();

			if (positionInLine <= barbers) {
				return positionInLine.ToString ();
			} else {

				bool same = true;

				for (int i=1; i<barbers; i++) {
					if (times [i] != times [0]) {
						same = false;
						break;
					}
				}

				if (same) 
				{
					int mod = positionInLine % barbers;

					return mod > 0 ? mod.ToString() : barbers.ToString();
				} 
				else 
				{
					double mult = 1000;

					//for (int i=0; i<barbers; i++) {
					//	mult = mult * times [i];
					//}

					int peopleInMult = 0;

					for (int i=0; i<barbers; i++) {
						peopleInMult = peopleInMult + int.Parse(Math.Floor (mult / times [i]).ToString()); 
					}

					positionInLine = positionInLine % peopleInMult;

					List<int> current = Enumerable.Repeat (0, barbers).ToList ();

					int currentClient = 1;
					int minTimes = times.Min ();

					while (currentClient < positionInLine) {
						if (current.Contains (0)) {
							int ind = current.IndexOf (0);
							current [ind] += times [ind];

							currentClient++;
						} else {
							current = current.Select (x => x - 1).ToList ();
						}
					}

					int min = current.Min ();

					return (current.IndexOf (min) + 1).ToString ();
				}
			}
		}
	}
}

