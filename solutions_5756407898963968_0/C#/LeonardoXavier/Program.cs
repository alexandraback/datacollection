using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A_MagicTrick
{
    class Program
    {
        static void Main(string[] args)
        {

            var linhas = File.ReadAllLines("input.txt");
            var quantidade = Convert.ToInt32(linhas[0].Trim());
            var truques = new Truque[quantidade];
            var dados = new string[10];
            for (int x = 0; x < quantidade; x++)
            {
                for (var y = 0; y < 10; y++)
                {
                    dados[y] = linhas[x * 10 + 1 + y];
                }
                truques[x] = new Truque(x + 1, dados);
            }
            File.AppendAllLines("Output.txt", truques.Select(pX => pX.Resultado));
        }
    }
}
