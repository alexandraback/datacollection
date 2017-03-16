using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace JamSenate
{
    class Program
    {
        const string INPUT_PATH = "D:\\CodeJam\\input.in";
        const string OUTPUT_PATH = "D:\\CodeJam\\output.txt";

        static void Main(string[] args)
        {
            FileStream inputStream = new FileStream(INPUT_PATH, FileMode.Open);
            StreamReader reader = new StreamReader(inputStream);
            FileStream outputStream = new FileStream(OUTPUT_PATH, FileMode.Create);
            StreamWriter writer = new StreamWriter(outputStream);
            int cases = int.Parse(reader.ReadLine());
            for (int i = 0; i < cases; i++)
            {
                int[] senators = new int[int.Parse(reader.ReadLine())];
                string[] textSenators = reader.ReadLine().Split(' ');
                for (int j = 0; j < senators.Length; j++)
                {
                    senators[j] = int.Parse(textSenators[j]);
                }
                writer.WriteLine("Case #" + (i + 1).ToString() + ": " + GetInstructionText(CreateEvacuationPlan(senators)));
            }
            reader.Close();
            writer.Close();
            inputStream.Close();
            outputStream.Close();
        }

        static List<Instuction> CreateEvacuationPlan(int[] numbersOfSenators)
        {
            List<Instuction> instructions = new List<Instuction>();
            int biggestPartySize = numbersOfSenators[0];
            int biggestParty = 0;
            for (int i = 1; i < numbersOfSenators.Length; i++)
            {
                if (numbersOfSenators[i] > biggestPartySize)
                {
                    biggestPartySize = numbersOfSenators[i];
                    biggestParty = i;
                }
            }
            int secondParty = biggestParty == 0 ? 1 : 0;
            int secondPartySize = numbersOfSenators[secondParty];
            for (int i = 0; i < numbersOfSenators.Length; i++)
            {
                if (secondPartySize < numbersOfSenators[i] && biggestParty != i)
                {
                    secondParty = i;
                    secondPartySize = numbersOfSenators[i];
                }
            }
            while (secondPartySize != biggestPartySize)
            {
                instructions.Add(new Instuction(biggestParty));
                biggestPartySize--;
                numbersOfSenators[biggestParty]--;
            }
            for (int i = 0; i < numbersOfSenators.Length; i++)
            {
                if (i != biggestParty && i != secondParty)
                {
                    while (numbersOfSenators[i] != 0)
                    {
                        instructions.Add(new Instuction(i));
                        numbersOfSenators[i]--;
                    }
                }
            }
            for (int i = 0; i < biggestPartySize; i++)
            {
                instructions.Add(new Instuction(biggestParty, secondParty));
            }
            return instructions;
        }

        static string GetInstructionText(List<Instuction> instrucions)
        {
            StringBuilder builder = new StringBuilder();
            builder.Append(instrucions[0].ToString());
            for (int i = 1; i < instrucions.Count; i++)
            {
                builder.Append(' ');
                builder.Append(instrucions[i].ToString());
            }
            return builder.ToString();
        }
    }

    struct Instuction
    {
        int Senator1;
        int Senator2;

        public Instuction(int senator1)
        {
            this.Senator1 = senator1;
            this.Senator2 = -1;
        }

        public Instuction(int senator1, int senator2)
        {
            this.Senator1 = senator1;
            this.Senator2 = senator2;
        }

        public override string ToString()
        {
            return this.Senator2 == -1 ? GetPartyChar(this.Senator1).ToString() : GetPartyChar(this.Senator1).ToString() + GetPartyChar(this.Senator2).ToString();
        }

        static char GetPartyChar(int partyNumber)
        {
            return (char)(partyNumber + 'A');
        }
    }
}
