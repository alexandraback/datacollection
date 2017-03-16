using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;

namespace Rozwel.CodeJam._2014_QR
{
    public class A_MagicTrick : ProblemBase
    {
        public override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        public class TestCase : TestCaseBase
        {
            byte Pos1;
            byte Pos2;
            string[][] Arrangement1;
            string[][] Arrangement2;

            public TestCase(TextReader inputStream)
            {
                Arrangement1 = new string[5][];
                Arrangement2 = new string[5][];
                string line;

                line = inputStream.ReadLine();
                Pos1 = byte.Parse(line);

                line = inputStream.ReadLine();
                Arrangement1[1] = line.Split(' ');
                line = inputStream.ReadLine();
                Arrangement1[2] = line.Split(' ');
                line = inputStream.ReadLine();
                Arrangement1[3] = line.Split(' ');
                line = inputStream.ReadLine();
                Arrangement1[4] = line.Split(' ');

                line = inputStream.ReadLine();
                Pos2 = byte.Parse(line);

                line = inputStream.ReadLine();
                Arrangement2[1] = line.Split(' ');
                line = inputStream.ReadLine();
                Arrangement2[2] = line.Split(' ');
                line = inputStream.ReadLine();
                Arrangement2[3] = line.Split(' ');
                line = inputStream.ReadLine();
                Arrangement2[4] = line.Split(' ');
            }
            public override void Solve(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();
                List<string> matchedValues = new List<string>();
                foreach (string value1 in Arrangement1[Pos1])
                {
                    token.ThrowIfCancellationRequested();
                    foreach (string value2 in Arrangement2[Pos2])
                    {
                        token.ThrowIfCancellationRequested();
                        if (value1 == value2)
                        {
                            matchedValues.Add(value1);
                            break;
                        }
                    }
                }
                if (matchedValues.Count == 0)
                {
                    Result = "Volunteer cheated!";
                }
                if (matchedValues.Count == 1)
                {
                    Result = matchedValues[0];
                }
                if (matchedValues.Count > 1)
                {
                    Result = "Bad magician!";
                }
            }
        }
    }
}
