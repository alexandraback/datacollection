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

		static string CASEFILE = @"..\..\..\B-small-attempt0.in";
//		static string CASEFILE = @"..\..\..\B-large.in";

		static int MAXTHREADS = 1;
		static bool BEEP = false;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}



		////////////////////////////////
		int R;
		int C;
		int N;
		////////////////////////////////
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			R = int.Parse( strs[0] );
			C = int.Parse( strs[1] );
			N = int.Parse( strs[2] );
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0} {1} {2}", R, C, N );
			////////////////////////////////
		}

		int check(int[,] f, int x, int y) {
			int h = 0;
			if (x > 0 && f[x-1,y] == 1) {
				h++;
			}
			if (x < C-1 && f[x+1,y] == 1) {
				h++;
			}
			if (y > 0 && f[x,y-1] == 1) {
				h++;
			}
			if (y < R-1 && f[x,y+1] == 1) {
				h++;
			}
			return h;	
		}

		//int count() {
		//    int h = 0;
		//    int[,] f = new int[C,R];
		//    for (int y = 0; y < R; y++) {
		//        for (int x = 0; x < C; x++) {
		//            f[x,y] = (x+y+1)%2;
		//            N -= f[x,y];
		//        }
		//    }
		//    if (N <= 0) return h;

		//    if (f[C-1,R-1] == 0) {
		//        f[C-1,R-1] = 1;
		//        h += check(f, C-1, R-1);
		//        if (--N == 0) return h;
		//    }
		//    if (f[C-1,0] == 0) {
		//        f[C-1,0] = 1;
		//        h += check(f, C-1, 0);
		//        if (--N == 0) return h;
		//    }
		//    if (f[0,R-1] == 0) {
		//        f[0,R-1] = 1;
		//        h += check(f, 0, R-1);
		//        if (--N == 0) return h;
		//    }

		//    for (int y = 0; y < R; y++) {
		//        for (int x = 0; x < C; x++) {
		//            if(f[x,y] ==0) {
		//                f[x,y] = 1;
		//                h += check(f, x, y);
		//                if (--N == 0) return h;
		//            }
		//        }
		//    }
			
		//    return h;
		//}



		int checkall(int[,] f) {
			int h = 0;
			for (int y = 0; y < R; y++) {
				for (int x = 0; x < C; x++) {
					if (f[x,y]==1)
						h += check(f, x, y);
				}
			}
			return h/2;
		}

		int minh = int.MaxValue;

		void count(int[,] f, int ii, int n) {
			if (n == N) {
				int h = checkall(f);
				if (h < minh) {
					minh = h;
				}
				return;
			}
	
			for (int i = ii; i < R*C; i++) {
				int x = i%C;
				int y = i/C;
				f[x,y] = 1;
				count(f, i+1, n+1);
				if (minh == 0) return;
				f[x,y] = 0;
			}
		}

		private void Solv()
		{
			////////////////////////////////
			int[,] f = new int[C,R];
			for (int y = 0; y < R; y++) {
				for (int x = 0; x < C; x++) {
					f[x,y] = 0;
				}
			}
			count(f, 0, 0);
			Result = minh.ToString();
			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
