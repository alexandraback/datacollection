using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014 {
	class Program {
		static void Main(string[] args) {
			if (args.Count() != 2) {
				Console.Error.WriteLine("Usage: .exe input_file_name output_file_name");
				return;
			}
			using (StreamWriter sw = new StreamWriter(args[1])) {
				using (StreamReader sr = new StreamReader(args[0])) {
					int tn = int.Parse(sr.ReadLine());
					for (int i = 1; i <= tn; ++i) {
						int rx = int.Parse(sr.ReadLine());
						HashSet<int> xset = null;
						for (int j = 1; j <= 4; ++j) {
							string line = sr.ReadLine();
							if (j == rx)
								xset = new HashSet<int>(line.Trim().Split(' ').Select(x => int.Parse(x)));
						}
						int ry = int.Parse(sr.ReadLine());
						HashSet<int> yset = null;
						for (int j = 1; j <= 4; ++j) {
							string line = sr.ReadLine();
							if (j == ry)
								yset = new HashSet<int>(line.Trim().Split(' ').Select(x => int.Parse(x)));
						}
						var res = xset.Where(x => yset.Contains(x));
						sw.Write("Case #" + i.ToString() + ": ");
						if (res.Count() == 1)
							sw.WriteLine(res.First().ToString());
						else if (res.Count() == 0)
							sw.WriteLine("Volunteer cheated!");
						else
							sw.WriteLine("Bad magician!");
					}
					sr.Close();
				}
				sw.Close();
			}
		}
	}
}
