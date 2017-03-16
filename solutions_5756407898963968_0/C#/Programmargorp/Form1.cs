using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Magic_Trick
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string input = richTextBox1.Text;
            string [] read = input.Split('\n');
            int length = Convert.ToInt32(read[0]);
            int counter = 0;
            for (int x = 1; x <= read.Length-5; x+=10)
            {
                counter++;
                int rownum = Convert.ToInt32(read[x]);
                string[] read1 = read[x + rownum].Split(' ');
                Array.Sort(read1);
                int rownum1 = Convert.ToInt32(read[x+5]);
                string[] read2 = read[x+5 + rownum1].Split(' ');
                Array.Sort(read2);
                bool [] equal = new bool[4]{false,false,false,false};
                for (int y = 0; y < 4; y++)
                {
                    for (int z = 0; z < 4; z++)
                    {
                        if (read1[y] == read2[z])
                        {
                            equal[y] = true;
                        }
                    }
                }
                int numtrue = 0;
                for (int y = 0; y < 4; y++)
                {
                    if (equal[y] == true)
                    {
                        numtrue++;
                    }
                }
                if(numtrue==1){
                    for (int y = 0; y < 4; y++){
                        if(equal[y]==true){
                            richTextBox2.Text = richTextBox2.Text + "Case #" + counter + ": " + read1[y]+"\n";
                        }
                    }
                }
                else if (numtrue == 0)
                {
                    richTextBox2.Text = richTextBox2.Text + "Case #" + counter + ": Volunteer cheated!\n";
                }
                else
                {
                    richTextBox2.Text = richTextBox2.Text + "Case #" + counter + ": Bad magician!\n";
                }
            }
        }
    }
}
