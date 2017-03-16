using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.R1C2016
{
    class Senate_Evacuation
    {
        public static void Run(System.Windows.Forms.TextBox inputTB, System.Windows.Forms.TextBox outputTB, System.Windows.Forms.TextBox debugTB)
        {

            int nbCases = int.Parse(inputTB.Lines.First());

            for (int i = 0; i < nbCases; i++)
            {
                var dico = new Dictionary<String, Int32>();
                int N = Int32.Parse(inputTB.Lines[i * 2 + 1]);
                var Nb = inputTB.Lines[i * 2 + 2].Split(' ');
                for (int n = 0; n < N; n++)
                {                    
                    char c = (char)('A' + n );                    
                    dico[c + ""] = Int32.Parse(Nb[n]);
                }
                outputTB.Text += ("Case #" + (i + 1) + ": "+Evacuate(dico).Trim()+"\r\n");
            
                continue;
            }
        }

        private static string Evacuate(Dictionary<string, int> dico)
        {
            var dc = dico.OrderByDescending(x => x.Value);
            if (dc.Where(x => x.Value != 0).Count() == 0)
            {
                return String.Empty;
            }
            else if (dc.Where(x => x.Value != 0).Count() == 2)
            {//Pas le choix 2
                var a = dc.First().Key;
                var b = dc.Skip(1).First().Key;
                dico[a]--;
                dico[b]--;
                return a + b + " " + Evacuate(dico);
            }
            else
            {//ok 1
                var a = dc.First().Key;
                dico[a]--;
                return a + " " + Evacuate(dico);
            }
        }
    }
}

