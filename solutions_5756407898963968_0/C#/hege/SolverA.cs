using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Xml;

namespace A
{
    class SolverA
    {
        public string SolveOne(TextReader input)
        {
            var nums1 = GetNums(input);
            var nums2 = GetNums(input);
            var res = nums1.Intersect(nums2).ToList();
            if (!res.Any())
                return "Volunteer cheated!";
            if (res.Count > 1)
                return "Bad magician!";
            return res.First().ToString(CultureInfo.InvariantCulture);
        }

        private static IEnumerable<int> GetNums(TextReader input)
        {
            string rowNumString = input.ReadLine();
            int rowNum = int.Parse(rowNumString);
            int[] res = null;
            for (int i = 1; i <= 4; ++i)
            {
                string row = input.ReadLine();
                if (i == rowNum)
                {
                    res = row.Split(' ').Select(int.Parse).ToArray();
                }
            }
            return res;
        }
    }
}
