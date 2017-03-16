/*
 * Created by SharpDevelop.
 * User: UX31
 * Date: 12.04.2014
 * Time: 12:11
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace problem
{
	class Program
	{
		public static void Main(string[] args)
		{
			var t = ReadInt();
			
			foreach (var index in Enumerable.Range(1, t)) {
				var r1 = ReadInt();
				var m1 = ReadMatrix(4);
				var r2 = ReadInt();
				var m2 = ReadMatrix(4);
				
				var set = m1[r1 - 1].Intersect(m2[r2 - 1]);
				
				string result;
				
				if (set.Count() == 1) {
					result = set.Single().ToString();
				} else {
					result = set.Any() ? "Bad magician!" : "Volunteer cheated!";
				}
				
				Console.WriteLine(string.Format(CultureInfo.InstalledUICulture, "Case #{0}: {1}", index, result));
			}
		}
		
		public static double Read(string number) {
			return double.Parse(number, CultureInfo.InvariantCulture);
		}
		
		public static int ReadInt() {
			return int.Parse(Console.ReadLine());
		}
		
		public static List<List<string>> ReadMatrix(int rows) {
			return Enumerable.Range(0, rows)
				.Select(index => Console.ReadLine().Split(' ').ToList())
				.ToList();
		}
		
		public static double Solve(double c, double f, double x) {
			double s = 0;
			double ff = 2;
			
			while (x/ff > x/(ff + f) + c/ff) {
				s += c/ff;
				ff += f;
			}
			
			s += x/ff;
			
			return s;
		}
	}
}