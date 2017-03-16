using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _A__Magic_Trick
{
    class Program
    {
        static void Main(string[] args)
        {
            // Number of games
            int T = Int32.Parse(Console.ReadLine());
            // Set up output file
            TextWriter writer = new StreamWriter("out.txt", false);
            for (int t = 1; t <= T; t++)
            {
                // Row number
                int rowA = Int32.Parse(Console.ReadLine());
                // Read matrix
                Matrix matrixA = Matrix.Read(Console.In, 4, 4);
                int[] listA = matrixA[rowA - 1];
                // Row number
                int rowB = Int32.Parse(Console.ReadLine());
                // Read matrix
                Matrix matrixB = Matrix.Read(Console.In, 4, 4);
                int[] listB = matrixB[rowB - 1];
                // Match the lists
                int[] listC = listA.Intersect(listB).ToArray();
                writer.Write("Case #" + t + ": ");
                switch (listC.Length)
                {
                    case 1:
                        writer.WriteLine(listC[0]);
                        break;

                    case 0:
                        writer.WriteLine("Volunteer cheated!");
                        break;

                    default:
                        writer.WriteLine("Bad magician!");
                        break;
                }
            }
            // EOF
            writer.Close();
        }
    }

    class Matrix
    {
        private int[][] matrix;

        public Matrix(int rows, int cols)
        {
            matrix = new int[rows][];
            for (int row = 0; row < rows; row++) {
                matrix[row] = new int[cols];
            }
        }
        
        public int this[int x, int y]
        {
            get { return matrix[x][y]; }
            set { matrix[x][y] = value; }
        }

        public int[] this[int x]
        {
            get { return matrix[x]; }
        }
        
        public static Matrix Read(TextReader source, int rows, int cols)
        {
            Matrix m = new Matrix(rows, cols);
            for (int row = 0; row < rows; row++)
            {
                String[] line = source.ReadLine().Split(' ');
                for (int col = 0; col < cols; col++)
                {
                    m[row, col] = Int32.Parse(line[col]);
                }
            }
            return m;
        }
    }
}
