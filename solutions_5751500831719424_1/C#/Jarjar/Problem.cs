using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJamQ21
{
    public class Problem
    {
            public Problem()
            {
                var pathname = "Sample.txt";
                using (FileStream fs = new FileStream(pathname, FileMode.Open))
                {
                    StreamReader sr = new StreamReader(fs);
                    using (FileStream fsout = new FileStream(pathname + ".out", FileMode.Create))
                    {
                        StreamWriter sw = new StreamWriter(fsout);
                        int caseScenario = Int32.Parse(sr.ReadLine()); // Nb de scenario
                        for (int sc = 1; sc <= caseScenario; sc++)
                        {
                            string result = string.Empty;
                            string inputLine = sr.ReadLine();
                            int lines = Int32.Parse(inputLine); // Nb of lines in the scenario
                            List<string> st = new List<string>();
                            List<string> stSimple = new List<string>();
                            string cas = sr.ReadLine();
                            st.Add(cas);
                            string r = simplify(cas);
                            int nbChar = r.Length;
                            List<int[]> listing = new List<int[]>();
                            int[] maxi = new int[nbChar];
                            int[] mini = new int[nbChar];
                            int[] decomp = new int[nbChar]; // will count the number of identical letters

                            int countInCas = 0;
                            for (int j = 0; j < nbChar; j++)
                            {
                                while (countInCas < cas.Length && r[j] == cas[countInCas])
                                {
                                    decomp[j]++;
                                    countInCas++;
                                }
                            }
                            listing.Add(decomp);
                            // initialization
                            for (int j = 0; j < nbChar; j++)
                            {
                                maxi[j] = decomp[j];
                                mini[j] = decomp[j];
                            }

                            for (int i = 1; i < lines; i++)
                            {
                                cas = sr.ReadLine();
                                st.Add(cas);
                                if (simplify(cas) != r)
                                {
                                    result = "Fegla Won";
                                }
                                if (string.IsNullOrEmpty(result))
                                {
                                    //int counting = target(st[0], st[1]); // Small case, N=2;
                                    //result = counting.ToString();
                                    //break;
                                    decomp = new int[nbChar]; // will count the number of identical letters
                                    countInCas = 0;
                                    for (int j = 0; j < nbChar; j++)
                                    {
                                        while (countInCas < cas.Length && r[j] == cas[countInCas])
                                        {
                                            decomp[j]++;
                                            countInCas++;
                                        }
                                    }
                                    listing.Add(decomp);
                                    for (int j = 0; j < nbChar; j++)
                                    {
                                        if (maxi[j] == 0 || maxi[j] < decomp[j])
                                            maxi[j] = decomp[j];
                                        if (mini[j] == 0 || mini[j] > decomp[j])
                                            mini[j] = decomp[j];
                                    }
                                }
                            }
                            //sw.WriteLine("Case #{0}: {1}", sc, result);
                            //continue;
                            if (string.IsNullOrEmpty(result))
                            {
                                int counting = countLower(listing, mini, maxi);
                                result = counting.ToString();
                            }

                            sw.WriteLine("Case #{0}: {1}", sc, result);
                        }
                        sw.Flush();
                    }

                }
            }

            int countLower(List<int[]> listing, int[] min, int[] max)
            {
                int count = 0;
                int length = min.Length;
                for (int i = 0; i < length; i++)
                {
                    int minimum = int.MaxValue;
                    int countingI = 0;
                    for (int j = min[i]; j <= max[i]; j++)
                    {
                        countingI = 0;
                        foreach (var c in listing)
                        {
                            countingI += Math.Abs(j - c[i]);
                        }
                        if (countingI < minimum)
                        {
                            minimum = countingI;
                        }
                    }
                    count += minimum;
                }
                return count;
            }

            // We can go from a to b
            int target(string a, string b)
            {
                int count = 0;
                int i = 0;
                while (a != b)
                {
                    if (i == a.Length)
                    {
                        if (b[i] == a[i - 1])
                        {
                            b = b.Remove(i, 1);
                            count++;
                            continue;
                        }
                    }
                    if (i == b.Length)
                    {
                        if (a[i] == b[i - 1])
                        {
                            a = a.Remove(i, 1);
                            count++;
                            continue;
                        }
                    }
                    if (a[i] == b[i])
                    {
                        i++;
                        continue;
                    }
                    if (a[i] == a[i - 1])
                    {
                        a = a.Remove(i, 1);
                        count++;
                        continue;
                    }
                    if (b[i] == b[i - 1])
                    {
                        b = b.Remove(i, 1);
                        count++;
                        continue;
                    }
                    

                }

                return count;
            }

            string simplify(string input)
            {
                string output = string.Empty;
                char last = ' ';
                for (int i = 0; i < input.Length; i++)
                {
                    if (last == input[i])
                        continue;
                    last = input[i];
                    output += input[i];
                }
                return output;
            }

        
    }
}
