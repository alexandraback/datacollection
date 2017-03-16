using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2015
{
    class Program
    {
        static String path = "B-small-attempt1.in";
        static String destDath = "B-output-small.txt";
        static void Main(string[] args)
        {
            String[] lines = readFile(path);
            List<String> realLines = new List<String>();
            foreach (String l in lines)
            {
                if (l.Trim() != "") realLines.Add(l.Trim());                
            }
            
            doIt(realLines);
            Console.WriteLine("Press any key to exit");
            Console.ReadKey();
        }
        ///////////////////////////////////////////////////////////////////////

        public static void doIt(List<String> lines)
        {
            List<String> outLines = new List<String>();
            int nTestCases = Int32.Parse(lines[0]);
            for (int i = 1; i <= nTestCases; i++)
            {
                List<ulong> nums1 = GetListNumbers(lines[(i - 1) * 2 + 1]);
                ulong B = nums1[0];
                ulong N = nums1[1];
                long[] nums2 = GetListLongNumbers(lines[(i - 1) * 2 + 2]).ToArray();
                ulong scm = GetSmallestCommonMultiple(nums2.ToArray());
                ulong count = 0;
                foreach (long time in nums2)
                {
                    count += (scm / (ulong)time); 
                }
                ulong Num = N % count;
                if (Num == 0)
                {
                    Num = count;
                }
                long[] minutes = new long[B];
                int res = 0;
                for (ulong j = 0; j < Num; j++)
                {
                    long min = minutes.Min();
                    int index = FindIn(minutes, min);
                    res = index + 1;
                    minutes[index] += nums2[index];
                }
                Console.WriteLine("Case #" + i );
                String outLine = "Case #" + i + ": " + res;
                outLines.Add(outLine);
            }
            writeFile(outLines, destDath);
        }

        static int FindIn(Int64[] list, Int64 value)
        {
            int count = 0;
            foreach (Int64 i in list)
            {
                if (value == i)
                    break;
                count++;
            }
            return count;
        }
        
        //////////////////////////////////////////////////////////////////////
        // Split
        static char[] separator = { ' ' };
        public static List<String> GetListStrings(String line)
        {
            List<String> strs = new List<String>();
            String[] parts = line.Split(separator);
            foreach (String p in parts)
            {
                if (p.Trim() != "")
                {
                    strs.Add(p);
                }
            }
            return strs;
        }

        public static List<ulong> GetListNumbers(String line)
        {
            List<ulong> numbers = new List<ulong>();
            String[] parts = line.Split(separator);
            foreach (String p in parts)
            {
                if (p.Trim() != "")
                {
                    numbers.Add(ulong.Parse(p.Trim()));
                }
            }
            return numbers;
        }
        public static List<long> GetListLongNumbers(String line)
        {
            List<long> numbers = new List<long>();
            String[] parts = line.Split(separator);
            foreach (String p in parts)
            {
                if (p.Trim() != "")
                {
                    numbers.Add(long.Parse(p.Trim()));
                }
            }
            return numbers;
        }
        //////////////////////////
        //IO ACCESS
        public static String[] readFile(String path)
        {
            return System.IO.File.ReadAllLines(path);
        }

        public static void writeFile(List<String> lines, String path)
        {
            using (System.IO.StreamWriter file = new System.IO.StreamWriter(path))
            {
                foreach (string line in lines)
                {
                    if (line.Trim() != "")
                    {
                        file.WriteLine(line);
                    }
                }
            }
        }
        /// <summary>
        /// Calculates the lowest common multiple of the given numbers.
        /// </summary>
        /// <param name="numbers">Numbers to be processed</param>
        /// <returns>The lowest common multiple of the numbers.</returns>
        static ulong GetSmallestCommonMultiple(params long[] numbers)
        {
            if (numbers.Contains(0))
                return 0;

            ulong[][] lists = (from x in numbers
                               where x != 1 // 1 has no effects
                               select GetPrimeFactors((ulong)(x < 0 ? x * -1 : x))).ToArray(); //Determine all prime factors
            Dictionary<ulong, uint> list = new Dictionary<ulong, uint>();

            foreach (ulong[] l in lists)//Iterate over all prime factor lists
            {
                uint n = 1;
                ulong cur = 0;
                if (l.Length == 0)
                    continue;// number is a 1
                foreach (ulong i in l)//Iterate over all prime factors
                {
                    if (cur == i)
                        ++n;
                    else
                    {
                        if (cur != 0)
                        {
                            if (list.ContainsKey(cur))//Does the list already contain this number?
                            {
                                if (list[cur] <= n)//Number is already in list and previous count smaller than actual count
                                    list[cur] = n;//New allocation of count
                            }
                            else
                            {
                                list.Add(cur, n);//Add new number to list.
                            }
                        }
                        n = 1;
                        cur = i;
                    }
                }
                if (list.ContainsKey(cur))//Does list already contain this number?
                {
                    if (list[cur] <= n)//Number is already in list and previous count smaller than actual count
                        list[cur] = n;//New allocation of count
                }
                else
                {
                    list.Add(cur, n);//Add new number to list
                }
            }
            ulong result = 1;
            foreach (KeyValuePair<ulong, uint> l in list)//Iterate over all values
                result *= Pow(l.Key, l.Value);//Exponentiate and multiply numbers
            return result;//Return value
        }

        /// <summary>
        /// Exponentiates a value with the exponent.
        /// </summary>
        /// <param name="b">base</param>
        /// <param name="e">exponent</param>
        /// <returns>The power of the base <c>b</c> and the exponent <c>e</c>.</returns>
        static ulong Pow(ulong b, uint e)
        {
            ulong result = 1;
            for (uint i = 0; i < e; ++i)
                result *= b;
            return result;
        }

        /// <summary>
        /// Returns the prime factors of a number.
        /// </summary>
        /// <param name="x">The number to be factorized.</param>
        /// <returns>The prime factors of the number</returns>
        /// <exception cref="System.ArgumentOutOfRangeException">Is thrown when x is smaller or equal 1.</exception>
        static ulong[] GetPrimeFactors(ulong x)
        {
            if (x <= 1)
                throw new ArgumentOutOfRangeException("x", "x >= 2");
            List<ulong> list = new List<ulong>();

            //? remove/list 2
            while ((double)x / (double)2 == (ulong)((double)x / (double)2))//remove 2
            {
                list.Add(2);
                x /= 2;
            }

            //? Check odd numbers for prime numbers and eventually remove/list
            for (ulong i = 3; i <= x && x != 1; )
            {
                if ((double)x / (double)i == (ulong)((double)x / (double)i)) // is number divisible by i?
                {
                    list.Add(i); // Add to list
                    x /= i; // Remove factor from number
                }
                else
                {
                    i += 2; // Next odd number
                }
            }
            return list.ToArray(); // Return as array
        }
    }
}
