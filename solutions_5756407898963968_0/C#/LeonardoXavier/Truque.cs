using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A_MagicTrick
{
    public class Truque
    {
        public Truque(Int32 pTeste, String[] pLinhas)
        {
            Montagem1 = new Montagem(pLinhas.Take(5).ToArray());
            Montagem2 = new Montagem(pLinhas.Skip(5).Take(5).ToArray());
            Resultado = String.Format("Case #{0}: {1}", pTeste, Processar());
        }

        private String Processar()
        {
            var resultado = Montagem1.Cartas[Montagem1.Linha - 1].Intersect(Montagem2.Cartas[Montagem2.Linha - 1]).ToArray();

            if (resultado.Length == 1)
                return resultado[0].ToString();
            if (resultado.Length == 0)
                return "Volunteer cheated!";
            return "Bad magician!";
        }

        public Montagem Montagem1 { get; set; }

        public Montagem Montagem2 { get; set; }

        public String Resultado { get; set; }
    }
}
