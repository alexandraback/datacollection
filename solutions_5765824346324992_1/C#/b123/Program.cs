namespace Codejam
{
    using System;
    using System.Collections.Generic;
    using System.Globalization;
    using System.IO;
    using System.Linq;
    using System.Text;

    class Program
    {
        private static NumberFormatInfo ni;

        static int Main(string[] args)
        {
            ni = (NumberFormatInfo)CultureInfo.CurrentCulture.NumberFormat.Clone();
            ni.NumberGroupSeparator = String.Empty;

            StreamWriter writer = null;
            if (args.Length < 2) { return 1; }

            try
            {
                // Attempt to open output file.
                writer = new StreamWriter(args[1]);
                // Redirect standard output from the console to the output file.
                Console.SetOut(writer);
                // Redirect standard input from the console to the input file.
                Console.SetIn(new StreamReader(args[0]));
            }
            catch (IOException e)
            {
                TextWriter errorWriter = Console.Error;
                errorWriter.WriteLine(e.Message);
                return 1;
            }

            Solve();

            writer.Close();
            // Recover the standard output stream so that a  
            // completion message can be displayed.
            StreamWriter standardOutput = new StreamWriter(Console.OpenStandardOutput());
            standardOutput.AutoFlush = true;
            Console.SetOut(standardOutput);
            Console.WriteLine("Complete");
            return 0;
        }

        public static List<T> ReadLine<T>()
        {
            return Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                        .Select(s => (T)Convert.ChangeType(s, typeof(T))).ToList();
        }

        public static void Solve()
        {
            int T = int.Parse(Console.ReadLine());

            for (int t = 1; t <= T; t++)
            {
                var line1 = ReadLine<long>();
                long B = line1[0];
                long N = line1[1];

                var Ms = ReadLine<long>();

                // Binary search the number of minutes
                long min = -1;
                long max = (N / B) * Ms.Max();

                while (max - min > 1)
                {
                    long middle = min + (max - min) / 2;
                    long haircuts = 0;
                    for (int b = 0; b < B; b++)
                    {
                        haircuts += 1 + middle / Ms[b];
                    }
                    
                    if (haircuts < N)
                    {
                        min = middle;
                    }
                    else if (haircuts > N)
                    {
                        max = middle;
                    }
                    else // haircuts = N
                    {
                        max = middle;
                    }
                }

                // At min, we have < N haircuts. At max, we have >= N haircuts
                long haircutsTotal = 0;
                for (int b = 0; b < B; b++)
                {
                    haircutsTotal += 1 + min / Ms[b];
                }

                int bAnswer = 0;
                for (int b = 0; b < B; b++)
                {
                    if (max % Ms[b] == 0)
                    {
                        haircutsTotal++;
                        if (haircutsTotal == N)
                        {
                            bAnswer = b;
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1}", t, bAnswer + 1);
            }
        }
    }
}
