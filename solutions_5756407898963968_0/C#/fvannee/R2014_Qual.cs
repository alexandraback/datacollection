using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrainAlgorithms.CodeJam
{
   internal class R2014_A : Problem
   {
      public override void ProcessOne()
      {
         int a1 = this.ReadInt();
         var num1 = this.ReadMultiArray(Int32.Parse, 4, 4, null);

         int a2 = this.ReadInt();
         var num2 = this.ReadMultiArray(Int32.Parse, 4, 4, null);

         int[] tbl = new int[17];
         for (int i = 0; i < 4; i++)
         {
            tbl[num1[a1-1, i]]++;
            tbl[num2[a2-1, i]]++;
         }

         var ans = new List<int>();
         for (int i = 1 ; i < 17; i++)
         {
            if (tbl[i] == 2)
               ans.Add(i);
         }
         if (ans.Count > 1)
            this.WriteLine("Bad magician!");
         else if (ans.Count == 1)
            this.WriteLine(ans[0].ToString());
         else
            this.WriteLine("Volunteer cheated!");
      }
   }

}
