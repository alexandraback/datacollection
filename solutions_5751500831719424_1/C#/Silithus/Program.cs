// Submitted by Silithus @ Macau
using System;
using System.Collections.Generic;
using System.IO;
using CCF_XOI;

namespace GoogleCodeJam2014
{
	class R1B_A
	{
		struct one_char
		{
			public char c;
			public int cnt;
		};

		public void Solve(XOI xoi)
		{
			int N, i, j, k, cnt, cur, len, ans;
			string s;
			List<one_char>[] oc;
			char pc;
			bool impos = false;

			N = xoi.ReadInt();
			oc = new List<one_char>[N];
			for (i = 0, len = -1; i < N; i++)
			{
				s = xoi.ReadLine();
				oc[i] = new List<one_char>();
				for (j = cnt = 1, pc = s[0]; j < s.Length; j++)
				{
					if (s[j] != pc)
					{
						oc[i].Add(new one_char { c = pc, cnt = cnt });
						pc = s[j]; cnt = 1;
					}
					else cnt++;
				}
				oc[i].Add(new one_char { c = pc, cnt = cnt });

				if (len == -1)
					len = oc[i].Count;
				else
					if (oc[i].Count != len)
						impos = true;
			}

			for (i = ans = 0; i < len && !impos; i++)
			{
				for (j = 0, cnt = Int32.MaxValue; j < N && !impos; j++)
				{
					for (k = cur = 0; k < N && !impos; k++)
					{
						if (j == k) continue;
						impos = (oc[j][i].c != oc[k][i].c);
						cur += Math.Abs(oc[j][i].cnt - oc[k][i].cnt);
					}
					cnt = Math.Min(cnt, cur);
				}
				ans += cnt;
			}

			if (impos)
				xoi.o.WriteLine("Fegla Won");
			else
				xoi.o.WriteLine(ans);
		}
	}

	class GCJ2014
	{
		static void Main(string[] args)
		{
			XOI xoi = new XOI();
			int t, T = xoi.ReadInt();

			for (t = 1; t <= T; t++)
			{
				xoi.o.Write("Case #{0}: ", t);
				(new R1B_A()).Solve(xoi);
			}
		}
	}
}

namespace CCF_XOI
{	// version 2014.02.07
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
			else return Double.Parse(s);
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
