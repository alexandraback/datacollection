using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Round_1_C
{
    class Program
    {
        static int max(List<int> tab)
        {
            int max = tab[0];
            for(int i = 1; i < tab.Count; i++)
            {
                if (tab[i] > max)
                    max = tab[i];
            }
            return max;
        }

        static int count_max(List<int> tab, int max)
        {
            int count = 0;
            for(int i = 0; i < tab.Count; i++)
            {
                if (tab[i] == max)
                    count++;
            }
            return count;
        }

        static int decrement(ref List<int> l, int max)
        {
            int i = 0;
            for(; i < l.Count; i++)
            {
                if (l[i] == max)
                {
                    l[i]--;
                    break;
                }
            }
            return i;
        }

        static bool is_empty(List<int> l)
        {
            int i = 0;
            while (i < l.Count && l[i] == 0)
                i++;
            return i == l.Count;
        }

        static void A()
        {
            StreamReader str = new StreamReader("A-large.in");
            //StreamReader str = new StreamReader("test.txt");
            StreamWriter stw = new StreamWriter("output-A.out");

            int T = Convert.ToInt32(str.ReadLine());
            for (int i = 0; i < T; i++)
            {
                int N = Convert.ToInt32(str.ReadLine());
                string[] tab = (str.ReadLine()).Split(' ');
                List<int> numbers = new List<int>();
                for (int a = 0; a < tab.Length; a++)
                    numbers.Add(Convert.ToInt32(tab[a]));
                stw.Write("Case #" + (i + 1) + ": ");
                while (! is_empty(numbers))
                {
                    int m = max(numbers), c = count_max(numbers, m);
                    if (c % 2 == 1)
                    {
                        int idx = decrement(ref numbers, m);
                        stw.Write((char)(idx + 65) + " ");
                    }
                    else
                    {
                        int idx = decrement(ref numbers, m);
                        stw.Write((char)(idx + 65));
                        idx = decrement(ref numbers, m);
                        stw.Write((char)(idx + 65) + " ");
                    }
                }
                stw.Write("\n");
            }
            str.Close();
            stw.Close();
        }

        static void B()
        {
            //StreamReader str = new StreamReader("B-large.in");
            StreamReader str = new StreamReader("test.txt");
            StreamWriter stw = new StreamWriter("output-B.out");

            int T = Convert.ToInt32(str.ReadLine());
            for (int i = 0; i < T; i++)
            {

            }

            str.Close();
            stw.Close();
        }

        static void C()
        {
            //StreamReader str = new StreamReader("C-large.in");
            StreamReader str = new StreamReader("test.txt");
            StreamWriter stw = new StreamWriter("output-C.out");

            int T = Convert.ToInt32(str.ReadLine());
            for (int i = 0; i < T; i++)
            {
                
            }

            str.Close();
            stw.Close();
        }
        static void Main(string[] args)
        {
            A();
        }
    }
}
