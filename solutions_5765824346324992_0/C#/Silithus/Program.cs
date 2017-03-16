// Submitted by Silithus @ Macau
using System;
using System.IO;
using System.Collections.Generic;
using CCF_XOI;

namespace GoogleCodeJam2015
{
	class Round1A_B
	{
		public int GCD(int a, int b)
		{
			int t = a % b;
			while (t != 0)
			{
				a = b;
				b = t;
				t = a % b;
			}
			return b;
		}

		public void Solve(XOI xoi)
		{
			int N, B, i, t, ans;
			long lcm;
			int[] M;
			List<int> wait = new List<int>();

			B = xoi.ReadInt();
			N = xoi.ReadInt();
			M = new int[B];

			for (i = t = 0, lcm = 0; i < B; i++)
			{
				M[i] = xoi.ReadInt();
				t = (i > 0 ? GCD(t, M[i]) : M[i]);
				lcm = (i > 0 ? lcm * (long)M[i] / t : M[i]);
			}

			for (long ii = 0; ii < lcm; ii++)
			{
				for (i = 0; i < B; i++)
				{
					if ((ii % M[i]) == 0)
						wait.Add(i + 1);
				}
			}

			ans = wait[(N - 1) % wait.Count];

			xoi.o.WriteLine(ans);
		}
	}

	class GCJ2015
	{
		static void Main(string[] args)
		{
			XOI xoi = new XOI();
			int t, T = xoi.ReadInt();

			for (t = 1; t <= T; t++)
			{
				xoi.o.Write("Case #{0}: ", t);
				(new Round1A_B()).Solve(xoi);
			}
		}
	}
}

namespace CCF_XOI
{	// version 2014.06.20
	class XOI
	{
		protected StreamReader sr;
		public StreamWriter o;
		protected Queue<string> buf = new Queue<string>();
		public bool EOF = false;

		public XOI()
		{
			this.sr = new StreamReader(Console.OpenStandardInput());
			this.o = new StreamWriter(Console.OpenStandardOutput());
			this.o.AutoFlush = true;
		}

		public XOI(string in_path, string out_path)
		{
			this.sr = new StreamReader(in_path);
			this.o = new StreamWriter(out_path);
			this.o.AutoFlush = true;
		}

		public int ReadInt()
		{
			string s = this.GetNext();
			if (s == null) return -1;
			else return Int32.Parse(s);
		}

		public long ReadLong()
		{
			string s = this.GetNext();
			if (s == null) return -1;
			else return Int64.Parse(s);
		}

		public double ReadDouble()
		{
			string s = this.GetNext();
			if (s == null) return -1;
			else return Double.Parse(s, System.Globalization.CultureInfo.InvariantCulture);
		}

		public string ReadString()
		{
			string s = this.GetNext();
			return (s == null ? null : s);
		}

		public string ReadLine()
		{	// I will ignore current buffer and read a new line
			string s = "";
			while (s == "" && !this.EOF)
			{
				s = sr.ReadLine();
				this.EOF = (s == null);
			}
			return (this.EOF ? null : s);
		}

		protected string GetNext()
		{
			if (buf.Count == 0)
			{
				while (buf.Count == 0 && !this.EOF)
				{
					string s = sr.ReadLine();
					if (s == null)
						this.EOF = true;
					else
						foreach (string ss in s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries))
							buf.Enqueue(ss);
				}
			}

			return (this.EOF ? null : buf.Dequeue());
		}
	}
}
