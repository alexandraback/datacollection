using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Scanner s = new Scanner(Console.ReadLine());
            int N = s.nextInt();
            for (int iTest = 0; iTest < N; ++iTest)
            {
                s = new Scanner(Console.ReadLine());
                int answer = s.nextInt() - 1;
                HashSet<int> answers = new HashSet<int>();
                for (int iLines = 0; iLines < 4; ++iLines)
                {
                    s = new Scanner(Console.ReadLine());
                    if (iLines == answer)
                    {
                        answers.Add(s.nextInt());
                        answers.Add(s.nextInt());
                        answers.Add(s.nextInt());
                        answers.Add(s.nextInt());
                    }
                }
                s = new Scanner(Console.ReadLine());
                answer = s.nextInt() - 1;
                for (int iLines = 0; iLines < 4; ++iLines)
                {
                    s = new Scanner(Console.ReadLine());
                    if (iLines == answer)
                    {
                        int goodAnswer = 0;
                        int nbAnswer = 0;
                        for (int iCard = 0; iCard < 4; ++iCard)
                        {
                            int card = s.nextInt();
                            if (answers.Contains(card))
                            {
                                nbAnswer++;
                                goodAnswer = card;
                            }
                        }
                        if (nbAnswer == 0)
                        {
                            Debug.WriteLine("Case #" + (iTest + 1) + ": Volunteer cheated!");
                        }
                        else if (nbAnswer == 1)
                        {
                            Debug.WriteLine("Case #" + (iTest + 1) + ": " + goodAnswer);
                        }
                        else
                        {
                            Debug.WriteLine("Case #" + (iTest + 1) + ": Bad magician!");
                        }
                    }
                }
            }
        }
    }
}
