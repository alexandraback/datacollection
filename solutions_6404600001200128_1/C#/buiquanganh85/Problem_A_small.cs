using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{



    class Program
    {


        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                int nplates = int.Parse(Console.ReadLine());
                string[] snumbers = Console.ReadLine().Split(' ');
                int[] numbers = new int[nplates];
                for(int i = 0; i < nplates; i++)
                {
                    numbers[i] = int.Parse(snumbers[i]);
                }

                int x = 0;
                int min_speed = 0;
                for(int i = 0; i < nplates - 1; i++)
                {
                    if(numbers[i] > numbers[i+1])
                    {
                        x += numbers[i] - numbers[i + 1];
                        if(min_speed < (numbers[i] - numbers[i + 1]))
                        {
                            min_speed = numbers[i] - numbers[i + 1];
                        }
                    }
                }

                int y = 0;
                for (int i = 0; i < nplates - 1;i++ )
                {
                    if (numbers[i] <= min_speed)
                    {
                        y += numbers[i];
                    }
                    else
                    {
                        y += min_speed;
                    }
                }

                Console.WriteLine("Case #{0}: {1} {2}",t+1,x,y);
            }
        }
    }
}
