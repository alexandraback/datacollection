using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;


namespace Haircut
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"B-small-attempt4.in";
        public const string OutputFile = @"B-Small55666.out";


        private Int64 B, N;
        private Int64[] _tempos;
        private Int64 R = 1;
        private Int64[] _uso;

        public override void LerDados()
        {
            var valores = ProximoInteiros();
            B = valores[0];
            N = valores[1];
            _tempos = ProximoLongs();
            _uso = new long[B];
        }

        public override void Resolver()
        {
           if (B == 1)
                return;
            var mdc = new HashSet<Int64>();
            for (int x = 0; x < _tempos.Length; x++)
            {
                mdc.Add(_tempos[x]);
            }
            Int64 comum = 1;
            foreach (var i in mdc)
            {
                comum*= i;
            }
            Int64 soma = 0;
            for (int x = 0; x < _tempos.Length; x++)
            {
                soma += comum/_tempos[x];
            }
            N = N % soma;
            if (N == 0)
            {
                var x = _tempos.Min();
                for (int y = _tempos.Length; y > 0; y--)
                    if (_tempos[y - 1] == x)
                    {
                        R = y;
                        return;
                    }
            }
            if (N <= B)
            {
                R = N;
                return;
            }

            while (N != 0)
            {
                var idx = -1;
                var min = _uso.Min();
                for (int x = 0; x < _uso.Length; x++)
                {
                    _uso[x] -= min;
                    if (idx == -1 && _uso[x] == 0)
                    {
                        idx = x + 1;
                        _uso[x] += _tempos[x];
                        N--;
                    }
                }
                R = idx;
            }


        }

        public static int MDC(int a, int b)
        {
            int resto;
            while (b != 0)
            {
                resto = a % b;
                a = b;
                b = resto;
            }
            return a;
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(R);
        }
    }
}
