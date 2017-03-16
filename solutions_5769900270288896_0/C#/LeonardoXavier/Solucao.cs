using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NoisyNeighbors.Modelo;


namespace NoisyNeighbors
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"B-small-attempt0 (3).in";
        public const string OutputFile = @"B-Small.out";

        private Int64 N, R, C;
        private Int64 flag;

        public override void LerDados()
        {
            var x = ProximoLongs();
            R = x[0];
            C = x[1];
            N = x[2];
        }

        public override void Resolver()
        {
            var quadrados = R*C;
            var lados = quadrados*4;
            var borda = (R + C)*2;
            var maxNegativo = (lados - borda)/2;

            Int64 metade = quadrados/2;
            metade += quadrados%2;
            if (metade >= N)
            {
                flag = 0;
                return;
            }
            if (N == quadrados)
            {
                flag = maxNegativo;
                return;
            }

            var sobra = N - metade;

            if (quadrados%2 == 0)
            {
                if (sobra == 1)
                {
                    flag += 2;
                    return;
                }
                if (sobra == 2)
                {
                    flag += 4;
                    return;
                }
                flag += 4;
                sobra -= 2;
            }

            var tres = R/2;
            tres += C/2;
            if (C%2 == 0 || R%2 == 0)
                tres--;
            if (sobra <= tres)
            {
                flag += sobra*3;
                return;
            }
            flag += 3*tres;
            sobra -= tres;
            tres = tres/2;
            if (sobra <= tres)
            {
                flag += sobra * 2;
                return;
            }
            flag += 2 * tres;
            sobra -= tres;

            flag += 4*sobra;

            if (flag > maxNegativo)
                flag = maxNegativo;
        }

       

        public override void EscreverResposta()
        {
            Out.WriteLine(flag);
        }
    }
}
