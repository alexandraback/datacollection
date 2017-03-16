using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Repeater
{
    class Program
    {
        static void Main(string[] args)
        {
            string entree = "A-large.in";
            string sortie = "out.txt";

            StringBuilder sb = new StringBuilder();
            string[] parametres = File.ReadAllLines(entree);


            int nbTest = int.Parse(parametres[0]);

            int numLigne = 1;
            for (int i = 1; i <=nbTest; i++)
            {
                int nbLignes = int.Parse(parametres[numLigne]);
                numLigne ++;

                List<string> chaines = new List<string>();
                for (int j = 0; j < nbLignes; j++)
                {
                    chaines.Add(parametres[numLigne + j]);
                }

                string resultat = Calculer(chaines.ToArray());
                sb.AppendLine("Case #" + i + ": " + resultat);

                numLigne += nbLignes;
            }

            File.WriteAllText(sortie, sb.ToString());
        }

        private static string Calculer(string[] p)
        {
            if (IsPossible(p) == false)
                return "Fegla Won";

            List<int[]> frequences = new List<int[]>();
            for (int i = 0; i < p.Length; i++)
            {
                int[] f = CalculerFrequence(p[i]);
                frequences.Add(f);
            }

            int nbLettres = frequences[0].Count();

            int res = 0;
            for (int i = 0; i < nbLettres; i++)
            {
                res += CalculerDistance(frequences, i);
            }


            return res.ToString();
        }

        private static int CalculerDistance(List<int[]> frequences, int i)
        {
            List<int> freq = frequences.Select(x => x[i]).ToList();
            int min = freq.Min();
            int max = freq.Max();

            int nbModifsMin = int.MaxValue;

            for (int j = min; j <= max; j++)
            {
                int dist = CalculerDistance(freq, j);
                if (dist < nbModifsMin)
                    nbModifsMin = dist;
            }

            return nbModifsMin;
        }

        private static int CalculerDistance(List<int> freq, int j)
        {
            return freq.Select(x => Math.Abs(x - j)).Sum();
        }

        private static int[] CalculerFrequence(string p)
        {
            List<int> frequences = new List<int>();
            int f = 1;
            char c = p[0];
            for (int i = 1; i < p.Length; i++)
            {
                if (p[i] != c)
                {
                    frequences.Add(f);
                    f = 1;
                    c = p[i];
                }
                else f++;
            }
            frequences.Add(f);
            return frequences.ToArray();
        }

        private static bool IsPossible(string[] p)
        {
            string pattern = CalculerPattern(p[0]);
            for (int i = 1; i < p.Count(); i++)
            {
                if (CalculerPattern(p[i]) != pattern)
                    return false;
            }
            return true;
        }

        private static string CalculerPattern(string p)
        {
            char c = p[0];
            string res = c.ToString();
            for (int i = 1; i < p.Length; i++)
            {
                if (p[i] != c)
                    res += p[i];
                c = p[i];
            }
            return res;
        }


        
    }
}
