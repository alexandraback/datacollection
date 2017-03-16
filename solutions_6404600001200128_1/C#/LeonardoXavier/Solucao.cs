using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace MushroomMonster
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"A-large (1).in";
        public const string OutputFile = @"A-large.out";

        private Int32[] _numeros;
        private Int32 A = 0, B = 0;
        private Int32 _rate = 0;

        public override void LerDados()
        {
            ProximaLinha();
            _numeros = ProximoInteiros();
        }

        public override void Resolver()
        {
            PrimeiroMetodo();
            SegundoMetodo();
        }

        private void SegundoMetodo()
        {
            if (_rate == 0)
                return;
            for (int x = 0; x < _numeros.Length - 1; x++)
            {
                B += _rate > _numeros[x] ? _numeros[x] : _rate;
            }
        }

        private void PrimeiroMetodo()
        {
            var diff = 0;
            for (int x = 0; x < _numeros.Length - 1; x++)
            {
                diff = _numeros[x] - _numeros[x + 1];
                if (diff > 0)
                {
                    A += diff;
                    if (diff > _rate)
                        _rate = diff;
                }
            }
        }

        public override void EscreverResposta()
        {
            Out.WriteLine("{0} {1}", A, B);
        }
    }
}
