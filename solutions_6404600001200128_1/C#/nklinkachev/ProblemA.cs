using System;
using System.IO;
using System.Collections.Generic;

namespace GCJ20151A
{
	public class ProblemA
	{
		public string input_modifier = "large"; // small large

		public TextReader tr;
		public TextWriter tw;

		public ProblemA ()
		{
			tr = new StreamReader (string.Format ("A-{0}.in", input_modifier));
			tw = new StreamWriter (string.Format ("A-{0}.out", input_modifier));
		}

		public void Solve() {
			int T = int.Parse (tr.ReadLine ());

			for (int t=1; t<=T; t++) {
				string answer = SolveCase ();
				tw.WriteLine ("Case #{0}: {1}",t,answer);
				tw.Flush ();
			}
			tw.Close ();
		}

		public string SolveCase() {
			var n = int.Parse (tr.ReadLine ());
			var numStrs = tr.ReadLine ().Split (' ');
			List<int> nums = new List<int> ();
			foreach (var p in numStrs) {
				nums.Add (int.Parse (p));
			}

			int m1 = 0;
			int m2 = 0;
			int eatingRate = 0;

			for (int i=0; i<nums.Count-1; i++) {
				if (nums [i] > nums [i + 1]) {
					m1 += nums [i] - nums [i + 1];

					int currEatingRate = nums [i] - nums [i + 1];
					eatingRate = Math.Max (eatingRate, currEatingRate);
				}
			}
			for (int i=0; i<nums.Count-1; i++) {
				if (nums [i] < eatingRate) {
					m2 += nums [i];
				} else {
					m2 += eatingRate;
				}
			}
			return m1.ToString () + " " + m2.ToString ();
		}
	}
}

