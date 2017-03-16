using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader("input.txt"))
            using (StreamWriter writer = new StreamWriter("output.txt"))
            {
                int cases = Convert.ToInt32(reader.ReadLine());
                int[] parties;
                int numberOfParties;
                string[] senators;
                int max = int.MinValue;
                StringBuilder evac;
                int count;

                for (int caseNumber = 1; caseNumber <= cases; caseNumber++)
                {
                    numberOfParties = Convert.ToInt32(reader.ReadLine());
                    parties = new int[numberOfParties];

                    senators = reader.ReadLine().Split(' ');
                    for (int i = 0; i < numberOfParties; i++)
                    {
                        parties[i] = Convert.ToInt32(senators[i]);
                        if (parties[i] > max)
                            max = parties[i];
                    }

                    evac = new StringBuilder();
                    count = 0;
                    while (max > 1)
                    {
                        for (int i = 0; i < numberOfParties; i++)
                        {
                            if (count == 2)
                            {
                                count = 0;
                                evac.Append(' ');
                            }
                            if (parties[i] == max)
                            {
                                evac.Append((char)(i + 'A'));
                                count++;
                                parties[i]--;
                            }                            
                        }

                        max--;
                    }
                    for (int i = 0; i < numberOfParties-2; i++)
                    {
                        if (count == 2)
                        {
                            count = 0;
                            evac.Append(' ');
                        }
                        if (parties[i] == max)
                        {
                            evac.Append((char)(i + 'A'));
                            count++;
                        }
                    }

                    evac.Append(' ');
                    evac.Append((char)(numberOfParties - 2 + 'A'));
                    evac.Append((char)(numberOfParties - 1 + 'A')); 

                    writer.WriteLine($"Case #{caseNumber}: {evac}");
                }
            }
        }

        


    }

}
