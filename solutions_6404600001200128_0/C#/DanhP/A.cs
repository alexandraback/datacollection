using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2015
{
    class Program
    {
        static String path = "A-small-attempt1.in";
        static String destDath = "A-output.txt";
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
                int nums1 = int.Parse(lines[(i - 1) * 2 + 1]);
                List<int> nums2 = GetListNumbers(lines[(i - 1) * 2 + 2]);
                int count1 = 0;
                int curr = nums2[0];
                for (int j = 1; j < nums2.Count; j++ ) {
                    if (nums2[j] < curr)
                    {
                        count1 += (curr - nums2[j]);
                    }
                    curr = nums2[j];
                }
                int max = 0;
                int curr2 = 0;
                foreach (int num in nums2)
                {
                    if (num < curr2)
                    {
                        int val = curr2 - num;
                        if (val > max) max = val;
                    }
                    curr2 = num;
                }
                int count2 = 0;
                for (int k = 0; k < nums2.Count - 1; k++ )
                {
                    if (nums2[k] <= max)
                    {
                        count2 += nums2[k];
                    }
                    else
                    {
                        count2 += max;
                    }
                }
                String outLine = "Case #" + i + ": " + count1 + " " + count2;
                outLines.Add(outLine);
            }
            writeFile(outLines, destDath);
        }


        ////////////////////////////////////////////////////////////////
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

        public static List<int> GetListNumbers(String line)
        {
            List<int> numbers = new List<int>();
            String[] parts = line.Split(separator);
            foreach (String p in parts)
            {
                if (p.Trim() != "")
                {
                    numbers.Add(Int32.Parse(p.Trim()));
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
    }
}
