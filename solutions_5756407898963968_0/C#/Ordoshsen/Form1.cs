using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            using (StreamReader sr = new StreamReader(@"A-small-attempt2.in", true))
            {
                int T = Convert.ToInt32(sr.ReadLine());
                for (int i = 1; i < T+1; i++)
                {
                    string line;
                    int a1 = Convert.ToInt32(sr.ReadLine());
                    for(int j = 1;j<a1;j++)
                        line = sr.ReadLine();
                    
                    line = sr.ReadLine();
                    string[] numbers1 = line.Split(' ');
                    int[] nums1 = new int[4];
                    for (int j = 0; j < 4; j++)
                        nums1[j] = Convert.ToInt32(numbers1[j]);

                    for (int j = a1; j < 4; j++)
                        line = sr.ReadLine();

                    int a2 = Convert.ToInt32(sr.ReadLine());
                    for (int j = 1; j < a2; j++)
                        line = sr.ReadLine();

                    line = sr.ReadLine();
                    string[] numbers2 = line.Split(' ');
                    int[] nums2 = new int[4];
                    for (int j = 0; j < 4; j++)
                        nums2[j] = Convert.ToInt32(numbers2[j]);

                    for (int j = a2; j < 4; j++)
                        line = sr.ReadLine();

                    int solution = 0;
                    int magic=0;
                    for (int j=0;j<4;j++)
                        for (int k=0;k<4;k++)
                            if (nums1[j] == nums2[k])
                            {
                                solution++;
                                magic = nums1[j];
                            }
                    using (StreamWriter sw = new StreamWriter(@"A-small-attempt2.out", true))
                    {
                        if (solution == 0)
                            sw.WriteLine("Case #" + i + ": Volunteer cheated!");
                        if (solution == 1)
                            sw.WriteLine("Case #" + i + ": " + magic);
                        if (solution >1)
                            sw.WriteLine("Case #" + i + ": Bad magician!");
                        sw.Flush();
                    }
                }
            }
        }
    }
}
