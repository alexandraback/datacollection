using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;
using System.Numerics;

namespace Rozwel.CodeJam._2015_R1A
{
    public class B_HairCut : ProblemBase
    {
        public override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        public class TestCase : TestCaseBase
        {
            uint N;
            uint B;
            uint[] M;

            public TestCase(TextReader inputStream)
            {
                string Line = inputStream.ReadLine();
                var CaseParts = Line.Split(' ');
                B = uint.Parse(CaseParts[0]);
                N = uint.Parse(CaseParts[1]);
                Line = inputStream.ReadLine();
                CaseParts = Line.Split(' ');
                M = new uint[B];
                for (int i = 0; i < B; i++)
                {
                    M[i] = uint.Parse(CaseParts[i]);
                }
            }

            public override void Solve(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();
                UInt64 Timer = 0;
                var FindingGCD = BigInteger.GreatestCommonDivisor(M[0], M[1]);
                var FindingLCM = (M[0] / FindingGCD) * M[1];
                for (int i = 2; i < B; i++)
                {
                    FindingGCD = BigInteger.GreatestCommonDivisor(FindingGCD, M[i]);
                    FindingLCM = (FindingLCM / FindingGCD) * M[i];
                }
                var GCD = (uint)FindingGCD;
                var LCM = (uint)FindingLCM;
                uint BulkProcess = 0;
                for (int i = 0; i < B; i++)
                {
                    BulkProcess += LCM / M[i];
                }
                while (N>BulkProcess)
                {
                    N -= BulkProcess;
                    Timer += LCM;
                }
                while (N > 0)
                {
                    for (int i = 0; i < B; i++)
                    {
                        if (Timer % M[i] == 0)
                        {
                            N--;
                            if (N == 0)
                            {
                                i++;
                                Result = i.ToString();
                                return;
                            }
                        }
                    }
                    Timer += GCD;
                }

            }
        }
    }
}
