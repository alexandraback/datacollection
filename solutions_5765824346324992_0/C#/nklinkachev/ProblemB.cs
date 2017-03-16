using System;
using System.IO;
using System.Collections.Generic;
// check priority queue file for license
using JMBucknall.Containers;

namespace GCJ20151A
{
	public class ProblemB
	{
		struct BarberNode : IComparable
		{
			public long FreeAt;
			public int Num;

			public BarberNode(long f, int num) {
				FreeAt=f;
				Num=num;
			}

			public int CompareTo(object o) {
				var b = (BarberNode)o;
				if (FreeAt < b.FreeAt)
					return 1;
				if (FreeAt > b.FreeAt)
					return -1;
				if (Num < b.Num)
					return 1;
				if (Num > b.Num)
					return -1;
				return 0;
			}
		}

		public string input_modifier = "small"; // small large

		public TextReader tr;
		public TextWriter tw;

		public ProblemB ()
		{
			tr = new StreamReader (string.Format ("B-{0}.in", input_modifier));
			tw = new StreamWriter (string.Format ("B-{0}.out", input_modifier));
		}

		public long GCD(long a, long b) {
			if (b == 0)
				return a;
			if (b > a) {
				long k = a;
				a = b;
				b = k;
			}
			return GCD (b, a % b);
		}

		public long LCM(long a, long b) {
			return a * b / GCD (a, b);
		}

		public void Solve() {
			int T = int.Parse (tr.ReadLine ());
			Console.WriteLine (T);

			for (int t=1; t<=T; t++) {
				Console.WriteLine("Starting " + t.ToString());
				string answer = SolveCase ();
				tw.WriteLine ("Case #{0}: {1}",t,answer);
				tw.Flush ();
				Console.WriteLine ("Finished " + t.ToString ());
			}
			tw.Close ();
		}

		public string SolveCase() {
			var input = tr.ReadLine ().Split (' ');
			int b = int.Parse (input [0]);
			long n = long.Parse (input [1]);

			var numStrs = tr.ReadLine ().Split (' ');
			List<int> m = new List<int> ();


			PriorityQueue q = new PriorityQueue ();

			foreach (var p in numStrs) {
				m.Add (int.Parse (p));
			}

			long l = m [0];
			for (int i=1; i<m.Count; i++) {
				l = LCM (l, m [i]);
			}

			long ppl = 0;
			for (int i=0; i<m.Count; i++) {
				ppl += l / m [i];
			}

			n %= ppl;
			if (n == 0)
				n = ppl;
			for (int i=0; i<m.Count; i++) {
				q.Enqueue (new BarberNode (0, i), new BarberNode (0, i));

			}

			long ind = 1;
			while (true) {
				BarberNode bn = (BarberNode)q.Dequeue();
				//Console.WriteLine ((bn.Num+1) + " ---> " + ind);
				if (ind == n)
					return (bn.Num+1).ToString();
				bn.FreeAt += m [bn.Num];

				q.Enqueue (bn, bn);
				ind++;
			}
		}
	}
}

