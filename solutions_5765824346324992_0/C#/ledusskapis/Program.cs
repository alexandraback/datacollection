using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Q1A_Haircut
{
    class Program
    {
        static void Main(string[] args)
        {
            var inFilename = args[0];
            var inFile = new StreamReader(inFilename);
            var outFile = new StreamWriter("output.txt");
            string line = inFile.ReadLine();
            var numTestCases = Int32.Parse(line);
            int testCase = 0;
            while ((line = inFile.ReadLine()) != null)
            {
                var str1 = line.Split(' ');
                var numBarbers = Int32.Parse(str1[0]);
                var myPlace = Int32.Parse(str1[1]);
                var str2 = inFile.ReadLine().Split(' ');
                var minutesPerBarber = new Dictionary<int, int>();
                for (var i=0;i<numBarbers;++i)
                {
                    minutesPerBarber[i] = Int32.Parse(str2[i]);
                }

                var barber = GetMyBarber(numBarbers, myPlace, minutesPerBarber);
                outFile.WriteLine("Case #{0}: {1}", testCase + 1, barber+1);
                ++testCase;
            }
            outFile.Close();
            inFile.Close();
        }

        public static int GetMyBarber(int numBarbers, int myPlace, Dictionary<int,int> minutesPerBarber)
        {
            var curMin = minutesPerBarber[0];
            var sameMins = true;
            for (var i=1;i<numBarbers;++i)
            {
                if (minutesPerBarber[i] != curMin)
                {
                    sameMins = false;
                    break;
                }
            }

            if (sameMins)
            {
                var place = myPlace - 1; //0..N-1
                var barb = place % numBarbers;
                return barb;
            }

            //Get common
            var com = 1;
            foreach (var bar in minutesPerBarber.Values)
            {
                com *= bar;
            }
            var numThrough = 0;
            for(var i=0;i<numBarbers;++i)
            {
                numThrough += (int)(com / minutesPerBarber[i]);
            }
            int div = (int)Math.Floor((double)myPlace / numThrough);
            if (div > 1)
            {
                myPlace = myPlace - numThrough * (div - 1);
            }
            //Get rid of rest
            //int div = (int) Math.Floor( (double) myPlace / com);
            //if (div > 1)
            //{
            //    myPlace = myPlace - com * div;
            //}

            var currentCustomer = 1;
            var barbers = new List<Barber>();
            for (var i=0;i<numBarbers;++i)
            {
                if (currentCustomer == myPlace)
                {
                    return i;
                }
                barbers.Add(new Barber { Id = i, MinsBusy = minutesPerBarber[i] });
                currentCustomer++;
            }
            while (true)
            {
                barbers.Sort((x,y) => x.MinsBusy.CompareTo(y.MinsBusy));
                var mins = barbers.First().MinsBusy;
                for(var i=0;i<numBarbers;++i)
                {
                    barbers[i].MinsBusy -= mins;
                }
                //Get the first free barber
                var freeBarbers = barbers.Where(b => b.MinsBusy == 0);
                foreach (var barb in freeBarbers.OrderBy(b => b.Id))
                {
                    if (currentCustomer == myPlace)
                    {
                        return barb.Id;
                    }
                    barb.MinsBusy = minutesPerBarber[barb.Id];
                    currentCustomer++;
                }
            }
        }

        public class Barber
        {
            public int Id { get; set; }
            public int MinsBusy { get; set; }
        }
    }
}
