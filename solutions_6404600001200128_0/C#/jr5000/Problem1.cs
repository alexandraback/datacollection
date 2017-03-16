using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam1a
{
    class Problem1
    {
        public static void Main()
        {
            new Problem1().Start();
        }

        void Start()
        {
            var fileName = "A-small-attempt1";
            using (var input = new System.IO.StreamReader("../../IO/" + fileName + ".in"))
            using (var output = new System.IO.StreamWriter("../../IO/" + fileName + ".out"))
            {
                var TC = int.Parse(input.ReadLine());
                for (var testCase = 1; testCase <= TC; testCase++)
                {
                    Console.WriteLine("Case #" + testCase);

                    int numMushrooms = int.Parse(input.ReadLine());
                    var mushrooms = input.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    int mushroomsEaten = 0;
                    int onPlate = mushrooms[0];
                    var min = Math.Max(0, mushrooms[0] - mushrooms[1]);
                    var num2 = 0;
                    for (int i = 1; i < numMushrooms; i++)
                    {
                        if (onPlate - mushrooms[i] > 0)
                            mushroomsEaten += onPlate - mushrooms[i];
                        if (onPlate - mushrooms[i] > 0)
                            min = Math.Max(min, onPlate - mushrooms[i]);
                        if (min == 0)
                            min = Math.Max(0, onPlate - mushrooms[i]);
                        onPlate = mushrooms[i];
                    }
                    for (int i = 1; i < numMushrooms; i++)
                    {
                        if (mushrooms[i] == 0 || mushrooms[i - 1] < min)
                            num2 += mushrooms[i - 1];
                        else
                            num2 += min;
                    }



                    output.WriteLine("Case #" + testCase + ": " + mushroomsEaten + " " + num2);
                }
            }
        }
    }
}
