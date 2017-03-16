import java.util.*;
import java.io.*;

public class CodeJam1BA
{
   public static void main(String[] args)
   {
      Scanner s = new Scanner(System.in);
      
      int T = s.nextInt();
      
      for(int t = 1; t<=T; t++)
      {
         int N = s.nextInt();
         ArrayList<String> strings = new ArrayList<String>(N);
         ArrayList<ArrayList<String>> letters = new ArrayList<ArrayList<String>>(N);
         ArrayList<ArrayList<Integer>> counts = new ArrayList<ArrayList<Integer>>(N);
         for(int n =0; n<N; n++)
         {
            strings.add(s.next());
            letters.add(new ArrayList<String>());
            counts.add(new ArrayList<Integer>());
         }
         for(int i =0; i<N; i++)
         {
            String str = strings.get(i);
            int ind = 0;
            while(ind<str.length())
            {
               String letter = str.substring(ind, ind+1);
               int count = 1;
               while(ind+1<str.length() && str.charAt(ind) == str.charAt(ind+1))
               {
                  count++;
                  ind++;
               }
               ind++;
               letters.get(i).add(letter);
               counts.get(i).add(count);
            }
         }
         
         boolean possible = true;
         ArrayList<String> lettersNeeded = letters.get(0);
         int sizeOfLetters = lettersNeeded.size();
         for(int i = 1; i<N; i++)
         {
            if(letters.get(i).size() == sizeOfLetters)
            {
               for(int j = 0; j<sizeOfLetters; j++)
               {
                  if(!letters.get(i).get(j).equals(lettersNeeded.get(j)))
                  {
                     possible = false;
                     break;
                  }
               }
            }
            else
            {
               possible = false;
            }
            if(!possible)
            {
               break;
            }
         }
         String finalString = "ERROR";
         if(possible)
         {
            int totalMoves = 0;
            for(int i = 0; i<sizeOfLetters; i++)
            {
               int minLetterMoves = 100000;
               for(int j = 0; j<N; j++)
               {
                  int ifCorrectMoves = 0;
                  for(int k=0; k<N; k++)
                  {
                     if(k!=j)
                     {
                        ifCorrectMoves += Math.abs(counts.get(k).get(i)-counts.get(j).get(i));
                     }
                  }
                  if(ifCorrectMoves<minLetterMoves)
                     minLetterMoves = ifCorrectMoves;
               }
               totalMoves+=minLetterMoves;
            }
            finalString = "" + totalMoves;
            
         }
         else
         {
            finalString = "Fegla Won";
         }
         
         
         
         
         System.out.printf("Case #%d: " + finalString + "\n", t);
      }
   }
}