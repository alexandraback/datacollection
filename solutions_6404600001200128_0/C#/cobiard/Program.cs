using System;
using System.Collections.Generic;
using System.Text;

namespace A
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
        static void Main(string[] args)
        {
            //Zakladne premenne
            int T = int.Parse(Console.ReadLine());
            int[] y = new int[T];
            int[] z = new int[T];
            int N;

            //Hlavny cyklus - T testcases
            for (int i = 0; i < T; i++)
            {
                N = int.Parse(Console.ReadLine());
                int[] plates = new int[N];
                string riadok = Console.ReadLine();
                string[] vstup = new string[N];
                vstup = riadok.Split(' ');

                for (int j = 0; j < N; j++) plates[j] = int.Parse(vstup[j]);
                //Vstup

                //Y
                y[i] = 0;
                for (int j = 1; j < N; j++)
                    if (plates[j] < plates[j - 1])
                        y[i] += plates[j - 1] - plates[j];
                //endY

                //Z
                z[i] = 0;
                int max = 0;
                for (int j = 1; j < N; j++)
                    if (plates[j - 1] - plates[j] > max)
                        max = plates[j - 1] - plates[j];
                
                for (int j = 1; j < N; j++)
                        z[i] += Math.Min(plates[j - 1], max);

            }

            //Vystup
			for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #{0}: {1} {2}", i + 1, y[i], z[i]);
            }

            //Zakomentovat
            /*
            Console.ReadLine();
            Console.ReadLine();
            //*/
        }
    }
}
