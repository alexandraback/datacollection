
import java.util.*;

public class A
{
   public static void main(String[] args)
   {
      new A(new Scanner(System.in));
   }

   int N;
   int[] vs;
   long solve1()
   {
      long res = 0;
      int onPlate = 0;
      for (int v : vs)
      {
         res += Math.max(0, onPlate-v);
         onPlate = v;
      }
      return res;
   }

   long solve3(int numEat)
   {
      long res = 0;
      int onPlate = vs[0];
      for (int i=1; i<N; i++)
      {
         int cnt = Math.min(numEat, onPlate);
         res += cnt;
         onPlate -= cnt;
         if (onPlate > vs[i])
            return Long.MAX_VALUE;
         onPlate = vs[i];
      }
      return res;
   }

   long solve2()
   {
      long res = Long.MAX_VALUE;
      for (int i=0; i<=20_000; i++)
         res = Math.min(res, solve3(i));
      return res;
   }

   public A(Scanner in)
   {
      int T = in.nextInt();


      for (int tc=1; tc<=T; tc++)
      {
         N = in.nextInt();
         vs = new int[N];
         for (int i=0; i<N; i++)
            vs[i] = in.nextInt();

         System.out.printf("Case #%d: %d %d%n", tc, solve1(), solve2());
      }
   }
}
