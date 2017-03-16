using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ARound1 {
    class Program {
        static void Main(string[] args) {
            var sr = new StreamReader(@"C:\gcj\2015\A-small-attempt0.in");
            var sw = new StreamWriter(@"C:\gcj\2015\A-small-attempt0.out");

            var numtestcases = Convert.ToInt64(sr.ReadLine());
            for(long i = 0; i < numtestcases; i++) {
                var intervals = Convert.ToInt32(sr.ReadLine());
                var plates = sr.ReadLine().Split(' ').Select(m => Convert.ToInt32(m)).ToList();

                int eaten1 = 0;
                int prev = plates[0];
                for(int j = 1; j < plates.Count; j++) {
                    var curr = plates[j];
                    if(curr < prev) {
                        eaten1 += prev - curr;
                    }
                    prev = curr;
                }

                
                prev = plates[0];
                var maxDiff = 0;
                for(int j = 1; j < plates.Count; j++) {
                    var curr = plates[j];
                    if(curr < prev) {
                        var diff = prev - curr;
                        if(diff > maxDiff) {
                            maxDiff = diff;
                        }
                    }
                    prev = curr;
                }

                
                int eaten2 = 0;
                if(maxDiff > 0){
                    prev = plates[0];
                    for(int j = 1; j < plates.Count; j++) {
                        var curr = plates[j];
                        eaten2 += Math.Min(prev, maxDiff);
                        prev = curr;
                    }
                }


                var outputString = String.Format("Case #{0}: {1} {2}", i+1, eaten1, eaten2);
                sw.WriteLine(outputString);
            }
            sr.Close();
            sw.Close();
        }
    }
}
