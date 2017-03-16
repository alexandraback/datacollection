using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A_MagicTrick
{
    public class Montagem
    {

        public Montagem(String[] pLinhas)
        {
            Linha = Convert.ToInt16(pLinhas[0]);

            Cartas = new[]
            {
                pLinhas[1].Split().Select(pX => Convert.ToInt32(pX)).ToArray(),
                pLinhas[2].Split().Select(pX => Convert.ToInt32(pX)).ToArray(),
                pLinhas[3].Split().Select(pX => Convert.ToInt32(pX)).ToArray(),
                pLinhas[4].Split().Select(pX => Convert.ToInt32(pX)).ToArray()
            };
        }


        public Int32 Linha { get; set; }

        public Int32[][] Cartas { get; set; }
    }
}
