using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SenateEvaculation
{
    class Program
    {
        private static long sCurCase = 1;

        static void Main(string[] args)
        {
            string inputFilepath = args[0];
            string outputFilepath = inputFilepath.Replace(".in", ".out");

            if (File.Exists(outputFilepath))
            {
                try
                {
                    File.Delete(outputFilepath);
                }
                catch (Exception ex)
                {
                    throw new Exception("Couldn't clear output file! is it held by another program?", ex);
                }
            }

            using (StreamReader reader = new StreamReader(File.OpenRead(inputFilepath)))
            {
                long numCases = long.Parse(reader.ReadLine().Trim());
                using (StreamWriter writer = new StreamWriter(File.OpenWrite(outputFilepath)))
                {
                    for (long i = 0; i < numCases; i++)
                    {
                        handleCase(reader, writer);
                    }
                }
            }
        }

        private static void WriteCaseResult(StreamWriter writer, string res)
        {
            writer.WriteLine("Case #{0}: {1}", sCurCase++, res);
        }


        private static void handleCase(StreamReader reader, StreamWriter writer)
        {
            string input1 = reader.ReadLine().Trim();
            string input2 = reader.ReadLine().Trim();
            int partiesNum = int.Parse(input1);
            string[] partiesCountStrs = input2.Split(' ');

            Dictionary<int, int> partyIndexToSeantorsLeft = new Dictionary<int, int>(partiesNum);
            int totalSenators = 0;
            for (int i = 0; i < partiesNum; i++)
            {
                int senatorCount = int.Parse(partiesCountStrs[i]);

                partyIndexToSeantorsLeft.Add(i, senatorCount);

                totalSenators += senatorCount;
            }

            StringBuilder sb = new StringBuilder(1000);


            int senatorsLeft = totalSenators;
            while (senatorsLeft > 0)
            {
                var maxValue = partyIndexToSeantorsLeft.Max(k => k.Value);
                var kvp = partyIndexToSeantorsLeft.Where(entry => entry.Value == maxValue).First();
                partyIndexToSeantorsLeft[kvp.Key]--;
                sb.Append(getChar(kvp.Key));
                senatorsLeft--;
                if (senatorsLeft == 0)
                {
                    break;
                }

                for (int partyIndex = 0; partyIndex < partiesNum; partyIndex++)
                {
                    var partyValue = partyIndexToSeantorsLeft[partyIndex];
                    if(partyValue == 0)
                    {
                        continue;
                    }

                    partyIndexToSeantorsLeft[partyIndex]--;
                    if (isMajorityExist(partyIndexToSeantorsLeft, senatorsLeft - 1))
                    {
                        partyIndexToSeantorsLeft[partyIndex]++;
                    }
                    else
                    {
                        sb.Append(getChar(partyIndex));

                        senatorsLeft--;

                        break;
                    }
                }


                sb.Append(" ");
            }

            string caseResult = sb.ToString();


            WriteCaseResult(writer, caseResult);
        }

        private static bool isMajority(int amounth, int total)
        {
            return (amounth  > total / 2.0);
        }

        private static bool isMajorityExist(Dictionary<int, int> partyIndexToSeantorsLeft, int total)
        {
            foreach (var kvp in partyIndexToSeantorsLeft)
            {
                if (isMajority(kvp.Value, total))
                {
                    return true;
                }
            }
            return false;
        }

        private static char getChar(int partyIndex)
        {
            return (char)('A' + partyIndex);
        }
    }
}
