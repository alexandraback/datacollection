using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{

    class Barber
    {
        private int serve_time;
        private int count_down;
        public bool isFree;
        public Barber(int serve_time)
        {
            this.count_down = serve_time;
            this.serve_time = serve_time;
            this.isFree = true;
        }
        private void finish()
        {
            this.count_down = this.serve_time;
            this.isFree = true;
        }
        public void serve()
        {
            this.isFree = false;
            this.tick();
        }
        public void tick()
        {
            if(this.count_down > 0)
            {
                this.count_down--;
            }
            else
            {
                this.finish();
            }
        }
    }

    class Customer
    {

        public Customer()
        {
            
        }
        
        public static int check_served(List<Barber> barbers)
        {
            
            for (int i = 0; i < barbers.Count; i++)
            {
                if(barbers[i].isFree)
                {
                   
                    return i;
                }
            }
            return -1;
        }
    }

    class Program
    {

        static int findLcd(int[] Mk)
        {
            int lcd = Mk.Max();
            while(true)
            {
                bool isOk = true;
                for (int i = 0; i < Mk.Length; i++ )
                {
                    if((lcd % Mk[i]) != 0)
                    {
                        isOk = false;
                        break;
                    }
                }
                if(isOk)
                {
                    return lcd;
                }
                else
                {
                    lcd++;
                }
            }
        }
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                string[] sparams = Console.ReadLine().Split(' ');
                int B = int.Parse(sparams[0]);
                int N = int.Parse(sparams[1]);
                sparams = Console.ReadLine().Split(' ');
                int[] Mk = new int[B];
                List<Barber> barbers = new List<Barber>();
                for (int i = 0; i < B; i++)
                {
                    Mk[i] =  int.Parse(sparams[i]);
                    Barber b = new Barber(Mk[i]);
                    barbers.Add(b);
                }

                int last_bb_id = 0;
                int lcd = findLcd(Mk);
                int numpers = 0;
                for(int i = 0; i < Mk.Length; i++)
                {
                    numpers += lcd / Mk[i];
                }
                N = N % numpers;
                if(N == 0)
                {
                    N = numpers;
                    
                }
                
                
                int count = 0;
                do
                {
                    int bb_id = Customer.check_served(barbers);
                    if (bb_id >= 0)
                    {
                        last_bb_id = bb_id;
                        barbers[bb_id].serve();
                        count++;
                    }
                    else
                    {
                        for (int i = 0; i < barbers.Count; i++)
                        {
                            barbers[i].tick();
                        }
                    }
                }
                while (count < N);
                Console.WriteLine("Case #{0}: {1}", t + 1, last_bb_id + 1);

                

                
            }
        }
    }
}
