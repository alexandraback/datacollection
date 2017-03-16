using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Mail;
using System.IO;

namespace Code
{
    class Code
    {

        static void Main(string[] args)
        {
            using (System.IO.StreamWriter file = new System.IO.StreamWriter("C:\\out.txt"))
            {
                FileStream filestream = new FileStream("c:\\in.txt", FileMode.Open);
                StreamReader streamreader = new StreamReader(filestream);

                string firstLine = streamreader.ReadLine();

                int caseID = 0;
                while (!streamreader.EndOfStream)
                {
                    caseID++;
                    string[] lines = new String[10];
                    lines[0] = streamreader.ReadLine();
                    lines[1] = streamreader.ReadLine();
                    lines[2] = streamreader.ReadLine();
                    lines[3] = streamreader.ReadLine();
                    lines[4] = streamreader.ReadLine();
                    lines[5] = streamreader.ReadLine();
                    lines[6] = streamreader.ReadLine();
                    lines[7] = streamreader.ReadLine();
                    lines[8] = streamreader.ReadLine();
                    lines[9] = streamreader.ReadLine();
                    int answer1 = -1; 
                    int answer2 = -1;
                    int.TryParse(lines[0], out answer1);
                    int.TryParse(lines[5], out answer2);
                    string[] data1;
                    string[] data2;
                    data1 = lines[answer1].Split(' ');
                    data2 = lines[answer2+5].Split(' ');
                    int[] block1 = {0,0,0,0};
                    for(int a = 0; a<=3; a++)
                    {
                        int.TryParse(data1[a], out block1[a]);
                    }
                    int[] block2 = { 0, 0, 0, 0 };
                    for (int a = 0; a <= 3; a++)
                    {
                        int.TryParse(data2[a], out block2[a]);
                    }
                    int end = 0;
                    int number = 0;

                    foreach (int x in block1)
                    {
                        foreach (int y in block2)
                        {
                            if (x == y)
                            {
                                end = x;
                                number++;
                            }
                        }
                    }

                    if (number == 1)
                    {
                        file.WriteLine("Case #{0}: {1}", caseID, end);
                    }
                    else if (number == 0)
                    {
                        file.WriteLine("Case #{0}: Volunteer cheated!", caseID);
                    }
                    else
                    {
                        file.WriteLine("Case #{0}: Bad magician!", caseID);
                    }


                }
            }
        }
    }
}
