using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1C
{
    class A
    {
        class Party
        {
            public int Size { get; set; }
            public char Name { get; set; }
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());

            for (int t = 1; t <= T; t++)
            {
                int P = int.Parse(Console.ReadLine());
                Party[] parties = Console.ReadLine().Split(' ').Select(pz => new Party { Size = int.Parse(pz) }).ToArray();
                for (int i = 0; i < P; i++)
                {
                    parties[i].Name = (char)('A' + i);
                }

                parties = parties.OrderByDescending(p => p.Size).ToArray();
                Console.Write("Case #{0}: ", t);
                int diff = parties[0].Size - parties[1].Size;
                while (diff-- > 0)
                {
                    Console.Write("{0} ", parties[0].Name);
                }

                for (int i = 2; i < P; i++)
                {
                    while (parties[i].Size-- > 0)
                    {
                        Console.Write("{0} ", parties[i].Name);
                    }
                }
                while (parties[1].Size-- > 0)
                {
                    Console.Write("{0}{1} ", parties[0].Name, parties[1].Name);
                }

                Console.WriteLine();
            }

        }
    }
}
