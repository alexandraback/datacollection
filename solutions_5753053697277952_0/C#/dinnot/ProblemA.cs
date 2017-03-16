using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam._2016r1c
{
    class ProblemA : IProblemSolver
    {
        public bool UsedBruteForce
        {
            get
            {
                return false;
            }
        }

        public string BruteForce(int caseNo)
        {
            throw new NotImplementedException();
        }

        int n;
        Party[] parties;

        public void ProcessInput()
        {
            n = GCJ.io.nextLineAsInt();
            int[] senators = GCJ.io.nextLineSeparatedAsInt();
            parties = new Party[n];
            for(int i = 0; i < n; i++)
            {
                parties[i] = new Party();
                parties[i].Senators = senators[i];
                parties[i].Letter = (char)('A' + i);
            }
        }

        public void Seed()
        {

        }

        public string Solve(int caseNo)
        {
            List<string> result = new List<string>();
            int sum = parties.Select(t => t.Senators).Sum();
            Array.Sort(parties);
            while(sum > 0)
            {
                string goingOut = "";
                //can take 2?
                var max = (sum - 2) / 2;
                var diff = 0;
                var idx = parties.Length-1;
                while(idx >= 0 && parties[idx].Senators > max)
                {
                    diff += parties[idx--].Senators - max;
                }
                if(diff <= 2)
                {
                    parties[parties.Length - 1].Senators--;
                    goingOut += parties[parties.Length - 1].Letter;
                    Array.Sort(parties);
                    parties[parties.Length - 1].Senators--;
                    goingOut += parties[parties.Length - 1].Letter;
                    sum -= 2;
                }
                //take one
                else
                {
                    parties[parties.Length - 1].Senators--;
                    goingOut += parties[parties.Length - 1].Letter;
                    sum -= 1;
                }
                result.Add(goingOut);
                Array.Sort(parties);
            }
            var plan = string.Join(" ", result);
            GCJ.io.Write(string.Format("Case #{0}: {1}", caseNo, plan));
            return plan;
        }

        public class Party : IComparable<Party>
        {
            public int Senators { get; set; }
            public char Letter { get; set; }

            public int CompareTo(Party other)
            {
                return this.Senators.CompareTo(other.Senators);
            }
        }
    }
}
