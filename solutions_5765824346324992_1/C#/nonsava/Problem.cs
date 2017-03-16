using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;


namespace nonsava.gcj
{
	class Problem
	{
		#region Main

		static string RESULTFILE = @"..\..\..\__out.txt";

		static void Main( string[] args )
		{
			if( 0 < args.Length ) {
				CASEFILE = args[0];
			} else if( 1 < args.Length ) {
				MAXTHREADS = int.Parse( args[1] );
			}

			DateTime startTime = DateTime.Now;

			int count;
			Problem[] testcases;

			using( TextReader reader = new StreamReader( CASEFILE ) ) {
				string line = reader.ReadLine();
				count = int.Parse( line );
				testcases = new Problem[count];

				for( int i = 0; i < count; i++ )
					testcases[i] = new Problem( reader );
			}

			Initialize();

			Thread[] threadPool = new Thread[MAXTHREADS];
			for( int t = 0; t < MAXTHREADS; t++ )
				threadPool[t] = null;

			for( int next = 0;; ) {
				if( count <= next ) {
					bool finished = true;
					for( int t = 0; t < MAXTHREADS; t++ )
						if( threadPool[t] != null && threadPool[t].IsAlive ) {
							finished = false;
							break;
						}
					if( finished )
						break;
				}

				for( int t = 0; t < MAXTHREADS; t++ ) {
					if( threadPool[t] != null && !threadPool[t].IsAlive )
						threadPool[t] = null;

					if( threadPool[t] == null && next < count ) {
						Console.WriteLine( "----------------------------------------------------- {0}/{1} ({2:F3}[sec])", next + 1, count, ( DateTime.Now - startTime ).TotalSeconds );
						testcases[next].WriteParams();

						threadPool[t] = new Thread( new ThreadStart( testcases[next++].Solv ) );
						threadPool[t].Start();
					}
				}

				Thread.Sleep( 100 );
			}

			Console.WriteLine( "\n#############################################################################\n" );
			using( TextWriter writer = new StreamWriter( RESULTFILE ) ) {
				for( int i = 0; i < count; i++ )
					testcases[i].WriteResult( writer, i + 1 );
			}

			TimeSpan span = DateTime.Now - startTime;
			Console.WriteLine( "\n#############################################################################\n" );
			Console.WriteLine( "{0:F3}[sec] = {1:F3}[min]", span.TotalSeconds, span.TotalMinutes );
			if( BEEP )
				Console.Beep( 1000, 5000 );
			Console.ReadKey();
		}


		string Result;

		private void WriteResult( TextWriter writer, int number )
		{
			writer.WriteLine( "Case #{0}: {1}", number, Result );
			Console.WriteLine( "Case #{0}: {1}", number, Result );
		}

		#endregion


		////////////////////////////////
		//static string CASEFILE = @"..\..\..\__in_sample.txt";

		//static string CASEFILE = @"..\..\..\B-small-attempt4.in";
		static string CASEFILE = @"..\..\..\B-large.in";

		static int MAXTHREADS = 8;
		static bool BEEP = false;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}



		////////////////////////////////
		int B;
		long N;
		int[] M;
		////////////////////////////////
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			B = int.Parse( strs[0] );
			N = long.Parse( strs[1] );
			M = new int[B];

			line = reader.ReadLine();
			strs = line.Split( new char[] { ' ' } );
			for( int i = 0; i < B; i++ ) {
				M[i] = int.Parse(strs[i]);
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1}", B, N );
			for( int i = 0; i < B; i++ )
				Console.Write( " {0}", M[i] );
			Console.WriteLine();
			////////////////////////////////
		}

		// 最大公約数を求める。
		static long GCD( long a, long b )
		{
			long small = Math.Min( a, b );
			long large = Math.Max( a, b );
			long r;
			long p = large;

			for( ;; ) {
				r = large - small;
				if( 0 == r )
					break;
				large = Math.Max( r, small );
				small = Math.Min( r, small );
				p = r;
			}

			return p;
		}

		// 最小公倍数を求める。
		static long LCM( long a, long b )
		{
			long gcd = GCD( a, b );

			return gcd * ( a / gcd ) * ( b / gcd );
		}


		private void Solv()
		{
			////////////////////////////////
			int[] m = new int[B];
			for (int i = 0; i < B; i++) {
				m[i] = 0;
			}

			long lcm = 1;
			for (int i = 0; i < B; i++) {
				lcm = LCM(lcm, M[i]);
			}
			Console.WriteLine("-------- lcm = {0}", lcm);
			long q = 0;
			for (int i = 0; i < B; i++) {
				q += lcm / M[i];
			}
			Console.WriteLine("--------   q = {0}", q);

			N = N % q;
			if (N == 0) {
				N = q;
			}
			Console.WriteLine("--------   N = {0}", N);

			int b = -10;
			for (long i = 0; i < N; i++) {
				b = -10;
				int min = int.MaxValue;
				for (int x = 0; x < B; x++) {
					if (m[x] == 0) {
						b = x;
						min = 0;
						break;
					} else if (m[x] < min) {
						b = x;
						min = m[x];
					}
				}
				if (min != 0) {
					for (int x = 0; x < B; x++) {
						m[x] -= min;
					}
				}
				m[b] = M[b];
			}
			++b;

			Result = b.ToString();
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
