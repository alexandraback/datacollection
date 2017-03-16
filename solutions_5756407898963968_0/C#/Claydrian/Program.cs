using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    class Program
    {
        static void Main(string[] args)
        {
            // Your submission system killed my google chrome.
            // IE 8 was fine!
            string path = "A-small-attempt2.in";
            System.IO.StreamReader reader = new System.IO.StreamReader(path);
            System.IO.StreamWriter output = new System.IO.StreamWriter("output.txt");
            int testCases = int.Parse(reader.ReadLine());
            for (int i = 0; i < testCases; i++)
            {
                var row1 = getRow(reader, int.Parse(reader.ReadLine()));
                var row2 = getRow(reader, int.Parse(reader.ReadLine()));
                var intersection = row1.Intersect(row2);
                var count = intersection.Count();
                output.Write( "Case #" );
                output.Write( i + 1 );
                output.Write(": ");
                if ( count == 1)
                {
                    output.WriteLine(intersection.First());
                }
                else if (count > 1)
                {
                    output.WriteLine("Bad magician!");
                }
                else
                {
                    output.WriteLine("Volunteer cheated!");
                }
            }
            output.Close();
            reader.Close();
        }

        static IEnumerable<int> getRow(System.IO.StreamReader reader, int selectedRow )
        {
            IEnumerable<int> result = null;
            for (int i = 1; i <= 4; i++)
            {
                var result2 = readRow(reader.ReadLine());
                if (i == selectedRow)
                {
                    result = result2;
                }
            }
            return result;
        }

        static IEnumerable<int> readRow(string row)
        {
            return row.Split(' ').Select(s => int.Parse(s));
        }
    }
}
