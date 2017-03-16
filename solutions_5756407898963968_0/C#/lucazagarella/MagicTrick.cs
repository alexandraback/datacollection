using System.IO;
using System.Linq;

namespace GoogleCodeJam2014
{
    public class MagicTrick
    {
        //private const string filename = "A-sample";
        private const string filename = "A-small";
        //private const string filename = "A-large";

        public static void Run()
        {
            var lines = File.ReadAllLines(filename+".in");
            var file = new StreamWriter(filename + ".out");
            int r=0;
            var T = int.Parse(lines[r++]);

            for (int i = 0; i < T; i++)
            {
                var firstIndex = int.Parse(lines[r]);
                var firstRowString = lines[r + firstIndex];
                r += 5;
                var secondIndex = int.Parse(lines[r]);
                var secondRowString = lines[r + secondIndex];
                r += 5;

                var res = Result(firstRowString + " " + secondRowString);
                file.WriteLine("Case #" + (i + 1) + ": " + res);
            }

            file.Close();
        }

        public static string Result(string data)
        {
            var values = (data).Split(' ').GroupBy(x => x).Where(y => y.Count() > 1).Select(x => x.Key).ToArray();
            if (values.Length == 0) return "Volunteer cheated!";
            if (values.Length == 1) return values[0];

            return "Bad magician!";
        }

    }
}
