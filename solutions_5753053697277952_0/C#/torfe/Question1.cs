using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Question1 : Problem
    {
        protected override string SolveCase()
        {
            var numberOfParties = this.ReadNextLineAsInt32();
            var partySizes = this.ReadNextLineAsInt32Array().ToList();
            var maxPartySize = partySizes.Max();
            var largestParty = partySizes.IndexOf(maxPartySize);
            var secondLargestParty = 0;
            var plan = string.Empty;

            if (partySizes.LastIndexOf(maxPartySize) != largestParty)
            {
                secondLargestParty = partySizes.LastIndexOf(maxPartySize);
            }
            else
            {
                var secondLargestPartySize = partySizes.Except(new int[] { maxPartySize }).Max();
                secondLargestParty = partySizes.IndexOf(secondLargestPartySize);

                var diff = maxPartySize - secondLargestPartySize;
                while (diff > 0)
                {
                    if (diff == 1)
                    {
                        plan += " " + this.PartyName(largestParty);
                    } 
                    else
                    {
                        plan += " " + this.PartyName(largestParty) + this.PartyName(largestParty);
                    }

                    diff -= 2;
                }
            }

            for (int i = 0; i < partySizes.Count; i++)
            {
                if (i == largestParty || i == secondLargestParty)
                {
                    continue;
                }

                var diff = partySizes[i];
                while (diff > 0)
                {
                    if (diff == 1)
                    {
                        plan += " " + this.PartyName(i);
                    }
                    else
                    {
                        plan += " " + this.PartyName(i) + this.PartyName(i);
                    }

                    diff -= 2;
                }
            }

            for (int i = 0; i < partySizes[secondLargestParty]; i++)
            {
                plan += " " + this.PartyName(largestParty) + this.PartyName(secondLargestParty);
            }

            return plan.Trim();
        }

        private char PartyName(int index)
        {
            return (char)(index + 65);
        } 
    }
}
