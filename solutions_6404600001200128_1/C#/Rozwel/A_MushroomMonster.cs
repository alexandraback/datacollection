using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Rozwel.CodeJam.Framework;
using System.IO;

namespace Rozwel.CodeJam._2015_R1A
{
    public class A_MushroomMonster : ProblemBase
    {
        public override TestCaseBase CreateTestCase(TextReader inputStream)
        {
            return new TestCase(inputStream);
        }
        public class TestCase : TestCaseBase
        {
            int Intervals;
            int[] Quantity;
            string R1;
            string R2;

            public TestCase(TextReader inputStream)
            {
                string Line = inputStream.ReadLine();
                Intervals = int.Parse(Line);
                Line = inputStream.ReadLine();
                var CaseParts = Line.Split(' ');
                Quantity = new int[Intervals];
                for (int i = 0; i < Intervals; i++)
                {
                    Quantity[i] = int.Parse(CaseParts[i]);
                }
            }

            public override void Solve(System.Threading.CancellationToken token)
            {
                token.ThrowIfCancellationRequested();

                /*Pass 1:
                 * Loop through quantities.  
                 * check change from previous quantity. 
                 * If less, add to eaten count
                 */

                int Eaten = 0;
                for (int i = 1; i < Intervals; i++)
                {
                    if (Quantity[i - 1] > Quantity[i])
                    {
                        Eaten += (Quantity[i - 1] - Quantity[i]);
                    }
                }
                R1 = Eaten.ToString();

                int MaxChange = 0;
                int Change = 0;
                for (int i = 1; i < Intervals; i++)
                {
                    Change = Quantity[i-1] - Quantity[i];
                    if (Change > MaxChange)
                        MaxChange = Change;
                }

                Eaten = 0;
                for (int i = 0; i < Intervals - 1; i++)
                {
                    if (MaxChange > Quantity[i])
                        Eaten += Quantity[i];
                    else
                        Eaten += MaxChange;
                }
                R2 = Eaten.ToString();

                Result = R1 + " " + R2;
            }
        }
    }
}
