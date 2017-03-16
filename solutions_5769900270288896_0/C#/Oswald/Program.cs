using System;
using System.IO;
using System.Collections.Generic;
class MainClass
{
	public static bool[,] building;
	public static int valueOfSquare(int x, int y){
		int total = 0;
		if (x > 0 && building [x-1, y]) {
			total++;
		}
		if (x < building.GetLength(0)-1 && building [x+1, y]) {
			total++;
		}
		if (y > 0 && building [x, y-1]) {
			total++;
		}
		if (y < building.GetLength(1)-1 && building [x, y+1]) {
			total++;
		}
		return total;
	}
	public static void removeIt(){
		int smallest = -1;
		int smallestI=1;
		int smallestQ=1;
		for (int i = 0; i < building.GetLength (0); i++) {
			for (int q = 0; q < building.GetLength (1); q++) {
				if (!building [i, q]) {
					continue;
				}
			//	Console.WriteLine ("{0}, {1}", i, q);
				int total = valueOfSquare (i, q);
				if (total == 4) {
					building [i, q] = false;
					return;
				} else if (total > smallest) {
					smallest = total;
					smallestI = i;
					smallestQ = q;
				}/* else if (total >= smallest && (i + q)%2==1) {
					smallest = total;
					smallestI = i;
					smallestQ = q;
				}*/
			}
		}
		//Console.WriteLine ("{0}, {1}!!!", smallestI, smallestQ);
		building [smallestI, smallestQ] = false;
	}
	public static void Main (string[] args)
	{
		string[] lines = File.ReadAllLines ("test.txt");
		int total = Convert.ToInt32 (lines [0]);
		for (int i = 1; i <= total; i++) {
			string[] stuff=lines [i].Split (new char[]{ ' ' }, 3);
			int[] rcn = new int[3];
			for (int d = 0; d < 3; d++) {
				rcn [d] = Convert.ToInt32 (stuff [d]);
			}
			int r = rcn [0];
			int c = rcn [1];
			int n = rcn [2];
			int smallest = 9999999;
			for (int g = 0; g <= 1; g++) {
				for (int h = 0; h <= 1; h++) {
					building = new bool[r, c];
					if (g >= building.GetLength (0) || h >= building.GetLength (1)) {
						continue;
					}
					for (int ig = 0; ig < building.GetLength (0); ig++) {
						for (int q = 0; q < building.GetLength (1); q++) {
							building [ig, q] = true;
						}
					}
					if (r * c != n) {
						building [g, h] = false;
						//Console.WriteLine ("{0}, {1}", r * c, n);
						for (int q = r * c - 1; q > n; q--) {
							removeIt ();
						}
					}
					int totalThing=0;
					//Console.WriteLine ("{0}, {1} : {2}, {3}", r, c, building.GetLength (0), building.GetLength (1));
					for (int ig = 0; ig < building.GetLength (0); ig++) {
						for (int q = 0; q < building.GetLength (1)-1; q++) {
							if (building [ig, q] && building [ig, q + 1]) {
								totalThing++;
							}
						}
					}
					for (int ig = 0; ig < building.GetLength (0)-1; ig++) {
						for (int q = 0; q < building.GetLength (1); q++) {
							if (building [ig, q] && building [ig+1, q]) {
								totalThing++;
							}
						}
					}
					if (totalThing < smallest) {
						smallest = totalThing;
					}
				}
			}

			Console.WriteLine ("Case #{0}: {1}", i, smallest);
		}
	}
}