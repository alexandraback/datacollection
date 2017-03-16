using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        public static void Main(string[] args)
        {
            solveEvac();
            
        }

        private static void solveEvac()
        {
            var res = File.ReadAllLines("A-large.in");
            var ans = new List<string>();
            for (int i = 1; i < res.Length; i+=2)
            {
                var steps = evacOne(res[i + 1]);
                ans.Add(nici(i / 2, steps));
            }
            File.WriteAllLines("AoutL.txt", ans);
        }

        private static string nici(int scase, List<string> steps)
        {
            var ret = "Case #"+(scase+1).ToString()+": ";
            foreach (var item in steps)
            {
                ret += item + " ";
            }
            return ret.Substring(0, ret.Length - 1);
        }

        private static List<string> evacOne(string v)
        {
            var tags = v.Split(' ').Select(x => int.Parse(x)).ToList();
            var steps = new List<string>();
            while(notDone(tags))
            {
                var step = selectOne(tags, true);
                step += selectOne(tags, false);
                steps.Add(step);
            }
            return steps;
        }

        private static string selectOne(List<int> tags, bool ignoreCheck)
        {
            var max = -1;
            var ind = -1;
            for (int i = 0; i < tags.Count; i++)
            {
                if (max < tags[i])
                {
                    max = tags[i];
                    ind = i;
                }
            }
            if (tags[ind] == 0)
                return "";
            if (!ignoreCheck)
            {
                if (notValid(tags, ind))
                    return "";
            }
            tags[ind]--;
            return MG[ind].ToString();
        }

        private static bool notValid(List<int> tags, int ind)
        {
            var tgs2 = new List<int>();
            for (int i = 0; i < tags.Count; i++)
            {
                tgs2.Add(tags[i]);
            }
            tgs2[ind]--;
            var sum = tgs2.Sum();

            foreach (var item in tgs2)
            {
                if ((double)item > ((double)sum / 2.0 + 0.25))
                    return true;
            }
            return false;
        }

        const string MG = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        private static bool notDone(IEnumerable<int> tags)
        {
            return !tags.All(x => x == 0);
        }
    }
}
