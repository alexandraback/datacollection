using System;
using System.IO;
using System.Collections.Generic;


namespace B
{
	class Problem
	{
		int r,c,n;

		int [] getvec(string s)
		{
			int[] v;
			string[] x = s.Split (' ');

			v = new int[x.Length];

			for (int i = 0; i < v.Length; i++)
				v [i] = int.Parse (x [i]);

			return v;
		}

		public Problem(TextReader r)
		{
			int[] v = getvec (r.ReadLine ());
			this.r = v [0];
			c = v [1];
			n = v [2];
		}



		int [,] w;

		int getcost(int x, int y)
		{
			int z = 0;
			if (x > 0 && w [x - 1, y] == 1)
				z++;
			if (y > 0 && w [x, y - 1] == 1)
				z++;

			return z;
		}

		int best = 1000000;

		void go(int x, int y, int cost, int n)
		{
			int nextx, nexty;

		
		//	Console.WriteLine ("{0},{1} {2}", x, y, n);

			if (x == 0 && y == r) {
				if (n == 0 && cost < best)
					best = cost;

				return;
			}

			if (x == c - 1) {
				nextx = 0;
				nexty = y + 1;
			} else {
				nextx = x + 1;
				nexty = y;
			}

			go (nextx, nexty, cost, n);
			w [x, y] = 1;
			int cc = getcost (x, y);
			if (n > 0) go (nextx, nexty, cost + cc, n - 1);
			w [x, y] = 0;
		}


		public string Solve()
		{
			w = new int[c, r];

			go (0, 0, 0, n);
			

			return ""+best;
		}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			TextReader r = new StreamReader (args [0]);
			TextWriter w = new StreamWriter (args [0] + ".out");


			int t = int.Parse(r.ReadLine ());

			for (int i = 1; i <= t; i++) {
				Problem p = new Problem (r);

				string sol = p.Solve ();

				Console.WriteLine ("Case #{0}: {1}", i, sol);
			}

		}
	}
}
