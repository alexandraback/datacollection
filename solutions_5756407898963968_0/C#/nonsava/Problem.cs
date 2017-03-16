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

		static string CASEFILE = @"..\..\..\A-small-attempt1.in";
//		static string CASEFILE = @"..\..\..\A-large.in";

//		static string CASEFILE = @"..\..\..\B-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\B-large.in";

//		static string CASEFILE = @"..\..\..\C-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\C-large.in";

//		static string CASEFILE = @"..\..\..\D-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\D-large.in";

		//static string CASEFILE = @"..\..\..\X-small-practice.in";
		//static string CASEFILE = @"..\..\..\X-large-practice.in";

		static int MAXTHREADS = 1;
		static bool BEEP = false;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}



		////////////////////////////////
		long A1;
		long[,] C1 = new long[4,4];
		long A2;
		long[,] C2 = new long[4,4];
		////////////////////////////////
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			A1 = long.Parse( line );
			for(int r=0; r < 4; r++) {
				line = reader.ReadLine();
				string[] strs = line.Split( new char[] { ' ' } );
				for( int i = 0; i < 4; i++ ) {
					C1[r,i] = long.Parse( strs[i] );
				}
			}

			line = reader.ReadLine();
			A2 = long.Parse( line );
			for(int r=0; r < 4; r++) {
				line = reader.ReadLine();
				string[] strs = line.Split( new char[] { ' ' } );
				for( int i = 0; i < 4; i++ ) {
					C2[r,i] = long.Parse( strs[i] );
				}
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0}", A1 );
			for(int r=0; r < 4; r++) {
				for( int i = 0; i < 4; i++ )
					Console.Write( " {0}", C1[r,i] );
				Console.WriteLine();
			}
			Console.WriteLine( "{0}", A2 );
			for(int r=0; r < 4; r++) {
				for( int i = 0; i < 4; i++ )
					Console.Write( " {0}", C2[r,i] );
				Console.WriteLine();
			}
			////////////////////////////////
		}


		private void Solv()
		{
			////////////////////////////////
			int c = 0;
			long x = -1;
			List<long> r = new List<long>();
			for (int i = 0; i < 4; i++) {
				r.Add(C1[A1-1,i]);
			}

			for (int i = 0; i < 4; i++) {
				if (r.Contains(C2[A2-1,i])) {
					c++;
					x = C2[A2-1,i];
				}
			}

			if (c == 1) {
				Result = x.ToString();
			} else if (c == 0) {
				Result = "Volunteer cheated!";
			} else {
				Result = "Bad magician!";
			}
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
