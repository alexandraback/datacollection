using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace BRound1 {
    class Program {
        static void Main(string[] args) {
            var sr = new StreamReader(@"C:\gcj\2015\B-small-attempt0.in");
            var sw = new StreamWriter(@"C:\gcj\2015\B-small-attempt0.out");

            var numtestcases = Convert.ToInt64(sr.ReadLine());
            for(long i = 0; i < numtestcases; i++) {
                var line1 = sr.ReadLine().Split(' ');
                var B = Convert.ToInt32(line1[0]);
                var N = Convert.ToInt32(line1[1]);

                var M = sr.ReadLine().Split(' ').Select(m => Convert.ToInt32(m)).ToList();

                int result = 1;
                if(B > 1){
                    var queue = new Queue<int>();
                    for(int j = 0; j < B; j++) {
                        queue.Enqueue(j + 1);
                    }

                    var low = lcm(M[0],M[1]);
                    for(int j = 2; j < B; j++){
                        low = lcm(low,M[j]);
                    }
                    
                    var list = new List<int>();
                    int time = 0;
                    var timeThing = new SortedSet<Tuple<int,int>>(new CmpTpl());
                    do{
                        if(queue.Count > 0){
                            var top = queue.Dequeue();
                            timeThing.Add(Tuple.Create(top,time + M[top-1]));
                            list.Add(top);
                        }else{
                            var min = timeThing.First();
                            var nextTime = min.Item2;
                            do{
                                queue.Enqueue(min.Item1);
                                timeThing.Remove(min);
                                min = timeThing.Min();
                            }while(timeThing.Count > 0 && min.Item2 == nextTime);
                            time = nextTime;
                        }

                    }while(time < low);

                   result = list[(N-1) % list.Count];

                }
                
                var outputString = String.Format("Case #{0}: {1}", i + 1, result);
                sw.WriteLine(outputString);
            }
            sw.Close();
        }
        public static int gcd(int a, int b){
            while(b > 0){
                var t = b;
                b = a % b;
                a = t;
            }
            return a;
        }

        public static int lcm(int a, int b){
            var g = gcd(a,b);
            return a*b/g;
        }
         

    }

    public class CmpTpl : IComparer<Tuple<int,int>> {
        public int Compare(Tuple<int,int> a, Tuple<int,int> b){
            if(a.Item2 < b.Item2){
                return -1;
            }else if(b.Item2 < a.Item2){
                return 1;
            } else if(a.Item1 == b.Item1 && a.Item2 == b.Item2) {
                return 0;
            } else if(a.Item2 == b.Item2 && a.Item1 < b.Item1) {
                return -1;
            }
            return 1;
        }
    }
}
