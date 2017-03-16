/*
 * Created by SharpDevelop.
 * User: santi
 * Date: 2014.04.12.
 * Time: 7:07
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.IO;

namespace MagicTrick
{
	class Program
	{
		public static void Main(string[] args)
		{
			int darabszam = 0;
			string line;

			// Read the file and display it line by line.
			System.IO.StreamReader file = new System.IO.StreamReader(args[0]);
			//System.IO.StreamReader file = new System.IO.StreamReader("input.txt");
			System.IO.StreamWriter outfile = new System.IO.StreamWriter("result.out");

			line = file.ReadLine();
			darabszam = Int32.Parse(line);
			
			for (int counter = 0; counter < darabszam; counter++)
			{
				outfile.Write("Case #{0}: ", counter+1);
				ReadProblem(file, outfile);
			}
			
			file.Close();
			outfile.Close();
			/*Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);*/
		}
		
		public static void ReadProblem(StreamReader file, StreamWriter outfile)
		{
			int LineNum;
			int[] FirstOrder = new int[4];
			int[] SecondOrder = new int[4];
			LineNum = Int32.Parse(file.ReadLine());
			for (int i = 0; i<4; i++)
			{
				if (i == LineNum-1)
				{
					string[] cards = file.ReadLine().Split(' ');
					for (int j = 0; j<cards.Length; j++)
						FirstOrder[j] = Int32.Parse(cards[j]);
				}
				else
					file.ReadLine();
			}

			LineNum = Int32.Parse(file.ReadLine());
			for (int i = 0; i<4; i++)
			{
				if (i == LineNum-1)
				{
					string[] cards = file.ReadLine().Split(' ');
					for (int j = 0; j<cards.Length; j++)
						SecondOrder[j] = Int32.Parse(cards[j]);
				}
				else
					file.ReadLine();
			}
			
			int count = 0;
			int res = 0;
			for (int i = 0; i<4 ; i++)
			{
				for (int j =0; j<4; j++)
				{
					if ( FirstOrder[i] == SecondOrder[j])
					{
						res = FirstOrder[i];
						count++;
					}
				}
			}
			
			if (count == 0)
				outfile.WriteLine("Volunteer cheated!");
			if (count == 1)
				outfile.WriteLine("{0}", res);
			if (count > 1)
				outfile.WriteLine("Bad magician!");
			
		}
		
	}
}
