using System;
using System.Collections.Generic;
using System.IO;

namespace RoundA_B
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader stream = new StreamReader("C:/Users/Montana/Desktop/B-small-attempt1.in"))
            using (StreamWriter output = new StreamWriter("C:/Users/Montana/Desktop/B-small-attempt1.out"))
            {
                int cases = int.Parse(stream.ReadLine());

                for (int i = 0; i < cases; i++)
                {
                    string[] split1 = stream.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int b = int.Parse(split1[0]);
                    int n = int.Parse(split1[1]);

                    string[] split2 = stream.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    int[] m = new int[b];
                    for (int j = 0; j < m.Length; j++) m[j] = int.Parse(split2[j]);

                    List<Barber> barbers = new List<Barber>(m.Length);
                    for (int j = 0; j < m.Length; j++)
                    {
                        barbers.Add(new Barber(j + 1, m[j]));
                    }

                    int nBetweenStates = 0;

                    while (n > 0)
                    {
                        barbers.Sort();

                        int dt = barbers[0].minutesRemaining;

                        bool resetState = (nBetweenStates != 0);
                        for (int j = 0; j < barbers.Count; j++)
                        {
                            barbers[j].minutesRemaining -= dt;
                            if (barbers[j].minutesRemaining != 0 || !barbers[j].used) resetState = false;
                        }

                        if (resetState && n > nBetweenStates * 2)
                        {
                            n -= nBetweenStates * ((n / nBetweenStates) - 1);
                        }
                        else
                        {
                            nBetweenStates++;

                            barbers[0].minutesRemaining = barbers[0].minutesToTake;
                            barbers[0].used = true;
                            n--;
                        }
                    }

                    output.WriteLine("Case #{0}: {1}", i + 1, barbers[0].barberNumber);
                    Console.WriteLine("Case #{0}: {1}", i + 1, barbers[0].barberNumber);
                }
            }
        }
    }

    public class Barber : IComparable<Barber>
    {
        public int minutesRemaining = 0;
        public int minutesToTake = 0;
        public int barberNumber = 0;
        public bool used = false;

        public Barber(int barber, int minutes)
        {
            barberNumber = barber;
            minutesRemaining = 0;
            minutesToTake = minutes;
        }

        public int CompareTo(Barber other)
        {
            if (minutesRemaining == other.minutesRemaining) return barberNumber.CompareTo(other.barberNumber);
            else return minutesRemaining.CompareTo(other.minutesRemaining);
        }

        public override string ToString()
        {
            return string.Format("{0}:{1}", barberNumber, minutesRemaining);
        }
    }
}
