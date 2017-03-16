using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam1
{
    public class ChoiceRound
    {
        public ChoiceRound(TextReader stream)
        {
            Choice = byte.Parse(stream.ReadLine());
            var cards = new byte[4, 4];
            for (int j = 0; j < 4; j++)
            {
                var readRow = stream.ReadLine().Split(' ').Select(x => byte.Parse(x)).ToArray();
                System.Buffer.BlockCopy(readRow, 0, cards, j*4, 4);
            }

            Cards = cards;
        }

        public IEnumerable<byte> GetPossibilities()
        {
            return Cards.GetRow(Choice - 1);
        }

        public byte Choice { get; private set; }
        public byte[,] Cards { get; private set; }
    }
}
