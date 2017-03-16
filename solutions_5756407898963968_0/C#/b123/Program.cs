namespace Codejam
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;

    class Program
    {
        static int Main(string[] args)
        {
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

        public static void Solve()
        {
            int T = int.Parse(Console.ReadLine());

            for (int t = 1; t <= T; t++)
            {
                int row = int.Parse(Console.ReadLine());

                var possible1 = new List<int>();
                for (int r = 1; r <= 4; r++)
                {
                    if (r == row)
                    {
                        possible1 =
                            Console.ReadLine().Split(new char[] { ' ' })
                                .Select(s => int.Parse(s))
                                .ToList();
                    }
                    else
                    {
                        Console.ReadLine();
                    }
                }

                row = int.Parse(Console.ReadLine());

                var possible2 = new List<int>();
                for (int r = 1; r <= 4; r++)
                {
                    if (r == row)
                    {
                        possible2 =
                            Console.ReadLine().Split(new char[] { ' ' })
                                .Select(s => int.Parse(s))
                                .ToList();
                    }
                    else
                    {
                        Console.ReadLine();
                    }
                }

                var answer = possible1.Where(x => possible2.Any(y => y == x)).ToList();
                switch (answer.Count)
                {
                    case 0:
                        Console.WriteLine("Case #{0}: Volunteer cheated!", t);
                        break;
                    case 1:
                        Console.WriteLine("Case #{0}: {1}", t, answer[0]);
                        break;
                    default:
                        Console.WriteLine("Case #{0}: Bad magician!", t);
                        break;
                }
            }
        }
    }
}
