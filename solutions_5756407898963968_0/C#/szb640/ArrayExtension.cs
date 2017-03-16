using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam1
{
    public static class ArrayExtension
    {
        public static IEnumerable<T> GetRow<T>(this T[,] arr, int index)
        {
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                yield return arr[index, i];
            }
        }
    }
}
