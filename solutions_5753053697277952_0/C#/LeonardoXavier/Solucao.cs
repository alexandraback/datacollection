using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace A_SenateEvacuation
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"A-small-attempt0 (3).in";
        public const string OutputFile = @"A_small.out";

        private int _qtd;
        private int _total;
        private List<Party> _parties = new List<Party>();
        List<string> _saida = new List<string>();

        public override void LerDados()
        {
            _qtd = ProximoInteiro();
            var qtd = ProximoInteiros();
            _total = qtd.Sum();
            for (int x = 0; x < qtd.Length; x++)
            {
                _parties.Add(new Party
                {
                    P = (char)('A' + x),
                    Qtd = qtd[x]
                });
            }
        }

        public override void Resolver()
        {
            while (_parties.Count != 0)
            {
                string saida = Proximo(false);
                saida += Proximo(true);
                _saida.Add(saida);
            }
        }

        private string Proximo(bool bpValidar)
        {
            _parties.Sort((p1, p2) => p2.Qtd.CompareTo(p1.Qtd));
            if (_parties.Count > 1 && bpValidar)
            {
                if (_parties[1].Qtd * 2 > _total - 1)
                    return string.Empty;
            }
            _parties[0].Qtd --;
            var resp = new string(_parties[0].P, 1);
            if(_parties[0].Qtd == 0)
                _parties.RemoveAt(0);
            _total--;
            return resp;
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(string.Join(" ", _saida));
        }
    }
}
