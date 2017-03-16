using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.IO;

namespace _1B {
    class Program {
        static BigInteger gcd(BigInteger a, BigInteger b) {
            if (b == 0)
                return a;

            return gcd(b, a % b);
        }

        static void Main(string[] args) {
            int[] ans = new int[101];
            int T;
            using (StreamReader sr = new StreamReader("date.in")) {
                T = Convert.ToInt32(sr.ReadLine());
                for (int k = 1; k <= T; k++) {
                    int B;
                    BigInteger N;
                    string[] aux = sr.ReadLine().Split(' ');
                    B = Convert.ToInt32(aux[0]);
                    N = BigInteger.Parse(aux[1]);
                    long[] barbier = Array.ConvertAll(sr.ReadLine().Split(' '), s => Convert.ToInt64(s));
                    long[] curent = new long[barbier.Length];

                    BigInteger LCM = 1;
                    for (int i = 0; i < B; i++) {
                        LCM = LCM * barbier[i] / gcd(LCM, barbier[i]);
                        curent[i] = barbier[i];
                    }

                    BigInteger total = 0;
                    for (int i = 0; i < B; i++)
                        total += LCM / barbier[i];

                    N = (N - 1) % total + 1;
                    if (N <= B) {
                        ans[k] = (int)N;
                    } else {
                        N -= B;
                        while (true) {
                            long minim = curent.Min();
                            bool gasit = false;
                            for (int i = 0; i < B; i++)
                                if (curent[i] == minim) {
                                    curent[i] = barbier[i];
                                    N--;
                                    if (N == 0) {
                                        gasit = true;
                                        ans[k] = i + 1;
                                        break;
                                    }
                                } else
                                    curent[i] -= minim;
                            if (gasit)
                                break;
                        }
                    }
                }
            }

            using (StreamWriter sw = new StreamWriter("out.txt"))
                for (int k = 1; k <= T; k++)
                    sw.WriteLine("Case #{0}: {1}\n", k, ans[k]);

        }
    }
}
