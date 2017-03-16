using System;
using System.Collections.Generic;
using System.Text;

namespace B
{
    public class Reader
    {
        public static int ReadInt()
        {
            int x;
            int vstup = 0;
            bool minus = false;
            x = Console.Read();
            while (!(x >= '0' && x <= '9'))
            {
                if (x == '-') minus = true;
                else minus = false;
                x = Console.Read();
            }
            while (x >= '0' && x <= '9')
            {
                vstup = vstup * 10 + (x - '0');
                x = Console.Read();
            }
            if (minus) vstup = -vstup;
            return vstup;
        }
    }

    class Program
    {
        static int lcm(int a, int b)
        {
            long x = a * b;
            while (a != b)
            {
                if (a % b == 0) return (int)(x/b);
                else if (b % a == 0) return (int)(x/a);
                else if (a > b) a = a % b;
                else b = b % a;
            }
            return (int)(x/a);
        }

        static int lcm(int[] p)
        {
            int a = p[0];
            for (int i = 1; i < p.Length; i++)
            {
                a = lcm(a, p[i]);
            }
            return a;
        }

        static void Main(string[] args)
        {
            //Zakladne premenne
            int T = int.Parse(Console.ReadLine());
            int[] vystup = new int[T];



            //Hlavny cyklus - T testcases
            for (int i = 0; i < T; i++)
            {
                vystup[i] = 0;
                string riadok = Console.ReadLine();
                string[] prvy = new string[2];
                prvy = riadok.Split(' ');
                int B = int.Parse(prvy[0]);
                int N = int.Parse(prvy[1]);
                string[] druhy = new string[B];
                int[] cut = new int[B];
                riadok = Console.ReadLine();
                druhy = riadok.Split(' ');
                for (int j = 0; j < B; j++) cut[j] = int.Parse(druhy[j]);
                //endinput

                int w = 0;
                int g = lcm(cut);
                for (int j = 0; j < B; j++) w += g / cut[j];
                if (N > w)
                {
                    N = N % w;
                    if (N == 0) N += w;
                }
                
                //endmodulo

                int[] wait = new int[B];
                int min;
                int pom;
                if (N <= B) 
                {
                    vystup[i] = N - 1;
                    continue;
                }
                for (int j = 0; j < B; j++) wait[j] = cut[j];
                N -= B;
                while (N > 0)
                {
                    min = 0; 
                    for (int j = 0; j < B; j++)
                    {
                        if (wait[j] < wait[min]) min = j;
                    }
                    pom = wait[min];
                    for (int j = 0; j < B; j++)
                    {
                        wait[j] -= pom;
                    }
                    /*
                    Console.WriteLine("#{0}, {1}", N, min);
                    for (int j = 0; j < B; j++)
                    {
                        Console.WriteLine("{0}: {1}", j, wait[j]);
                    }
                     */
                    N--;
                    wait[min] += cut[min];
                    if (N == 0) vystup[i] = min;
                }
            }



            //Vystup
            for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, vystup[i] + 1);
            }

            //Zakomentovat
            /*
            Console.ReadLine();
            Console.ReadLine();
            //*/
        }
    }
}
