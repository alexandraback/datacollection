import java.util.Scanner;
import java.io.FileNotFoundException;
import java.io.File;
import java.util.ArrayList;
import java.util.Collections;

class B
{
   public static void main(String[] args) throws FileNotFoundException
   {
      File f = new File("input2.txt");
      Scanner s = new Scanner(f);

      int numTests = s.nextInt();

      for(int i = 0; i < numTests; i++)
      {
         int barbers = s.nextInt();
         int place = s.nextInt(); 
         int[] timeArr = new int[barbers];
         int[] barbArr = new int[barbers];

         for(int j = 0; j < barbers; j++)
         {
            timeArr[j] = s.nextInt();
            barbArr[j] = 0;
         }

         int res = findBarber(barbers, place, barbArr, timeArr);

         System.out.println("Case #" + (i+1) + ": " + res);
      }
   }

   static int findBarber(int barbers, int place, int[] barbArr, int[] timeArr)
   {
      int initial = -1;
      int initialBool = 0;
      int zeroBarbers = 0;
      while(true)
      {
         int prevPlace = place;
         zeroBarbers = 0;
         for(int j = 0; j < barbers; j++)
         {
            if(barbArr[j] == 0)
            {
               zeroBarbers++;
               place--;
               if(place == 0)
               {
                  return j + 1;
               }

               barbArr[j] = timeArr[j];
            }
         }
         if(zeroBarbers == barbers)
         {
            initialBool++;
         }

         if(initialBool == 1 && initial == -1)
         {
            initial = prevPlace;
         }

         if(initialBool == 2)
         {
            int rem = initial - prevPlace;
            place = prevPlace % rem;
            if(place == 0)
            {
               place = rem;
            }
            for(int j = 0; j < barbers; j++)
            {
               barbArr[j] = 0;
            }
            initialBool = -2;
            continue;   
         }

         for(int j = 0; j < barbers; j++)
         {
            barbArr[j] = barbArr[j] - 1;
         }
      }
   }
}