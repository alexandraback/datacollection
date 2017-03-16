using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using log4net;

namespace MagicTrick {
    class Program {
        static void Main(string[] args) {
            log4net.Config.XmlConfigurator.Configure();
            int testCount = Console.ReadLine().Split().Select(it => Int32.Parse(it)).First();
            for(int i = 1; i <= testCount; i++) {
                Test test = new Test();
                test.Load();
                Console.WriteLine("Case #{0}: {1}", i, test.Solve());
            }
        }
    }

    public class Test {
        private static readonly ILog log = LogManager.GetLogger(typeof(Test));

        int answer0;
        List<int> []lines0 =new List<int>[4];
        int answer1;
        List<int>[] lines1 = new List<int>[4];
        public void Load() {
            answer0 = Console.ReadLine().Split().Select(it => Int32.Parse(it)).First() - 1;
            for(int i = 0; i < 4; i++) {
                lines0[i] = Console.ReadLine().Split().Select(it => Int32.Parse(it)).ToList();
                log.Info(lines0.Length);
            }
            answer1 = Console.ReadLine().Split().Select(it => Int32.Parse(it)).First() - 1;
            for(int i = 0; i < 4; i++) {
                lines1[i] = Console.ReadLine().Split().Select(it => Int32.Parse(it)).ToList();
                log.Info(lines1.Length);
            }
        }
        public string Solve() {
            var result = lines1[answer1].Intersect(lines0[answer0]).ToList();
            if(!result.Any()) {
                return "Volunteer cheated!";
                //return "Volunteer cheated!";
            } else if(result.Count == 1) {
                return result[0].ToString();
            }
            return "Bad magician!";
            //return "Bad magician!";
        }
    }
}
