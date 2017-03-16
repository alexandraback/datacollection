using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader Input = new StreamReader("Data/Input.txt");
            StreamWriter Output = new StreamWriter("Data/Output.txt");
            int T = int.Parse(Input.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                Console.WriteLine("Case #" + i);
                Output.Write("Case #" + i + ": ");
                Solution(Input, Output);
                Output.WriteLine();
            }
            Input.Close();
            Output.Close();
            //Console.Read();
        }
        static void Solution(StreamReader Input, StreamWriter Output)
        {
            int N = int.Parse(Input.ReadLine());
            List<int> Pi = Input.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
            double sum = Pi.Sum();
            while (sum > 0)
            {
                string E = "";
                int max = 0;
                int index = 0;
                for (int i = 0; i < N; i++)
                {
                    if (Pi[i] >= max)
                    {
                        max = Pi[i];
                        index = i;
                    }
                }
                E += (char)('A' + index);
                Pi[index]--;
                sum--;
                for (int i = 0; i < N; i++)
                {
                    if (Pi[i] >= max)
                    {
                        max = Pi[i];
                        index = i;
                    }
                }
                if (max > (sum / 2))
                {
                    E += (char) ('A' + index);
                    Pi[index]--;
                    sum--;
                }
                Output.Write(E + " ");
            }
        }
    }
}
