using System;
using System.IO;
using System.Collections.Generic;


class Party
{
    public char letter;
    public int count;

    public Party(char letter, int count)
    {
        this.letter = letter;
        this.count = count;
    }
}

class A
{
    static string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public void Solve()
    {
        StreamReader reader = new StreamReader("A_in.txt");
        StreamWriter writer = new StreamWriter("A_out.txt");

        int T = Int32.Parse(reader.ReadLine());

        for (int t = 0; t < T; t++)
        {
            List<Party> parties = new List<Party>();

            int N = Int32.Parse(reader.ReadLine());
            string[] line = reader.ReadLine().Split();
            int senators = 0;

            for (int i = 0; i < N; i++)
            {
                int partyCount = Int32.Parse(line[i]);

                Party party = new Party(alphabet[i], partyCount);
                parties.Add(party);
                senators += partyCount;
            }

            List<string> actions = new List<string>();
            while (senators > 0)
            {
                parties.Sort((x, y) => y.count.CompareTo(x.count));

                // Are there two parties left only with equal senators? If so, pick one from each
                if (parties.Count == 2)
                {
                    Party p1 = parties[0];
                    Party p2 = parties[1];
                    if (p1.count == p2.count)
                    {
                        //Console.Error.WriteLine("one from each");
                        actions.Add(p1.letter.ToString() + p2.letter.ToString());
                        senators -= 2;
                        p1.count -= 1;
                        p2.count -= 1;
                    }
                    else if (p1.count == p2.count + 1)
                    {
                        //Console.Error.WriteLine("one from the bigger");
                        actions.Add(p1.letter.ToString());
                        senators -= 1;
                        p1.count -= 1;
                    }
                    else
                    {
                        //Console.Error.WriteLine("two from the bigger");
                        actions.Add(p1.letter.ToString() + p1.letter.ToString());
                        senators -= 2;
                        p1.count -= 2;
                    }
                }
                else
                {

                    // Otherwise just sort the parties and take one from the largest
                    Party largest = parties[0];
                    largest.count -= 1;
                    senators -= 1;
                    actions.Add(largest.letter.ToString());
                    if (largest.count == 0) parties.Remove(largest);
                }
            }

            string answer = "";
            foreach (string s in actions) answer += s + " ";

            writer.WriteLine("Case #{0}: {1}", (t + 1), answer);
            Console.WriteLine("Case #{0}: {1}", (t + 1), answer);
        }

        reader.Close();
        writer.Close();
    }


}
