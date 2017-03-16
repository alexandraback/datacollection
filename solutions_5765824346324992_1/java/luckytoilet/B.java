
import java.util.*;
import java.math.*;

public class B{
  static long freebarb[] = new long[1005];

  static BigInteger lcm(BigInteger a, BigInteger b){
    return a.multiply(b).divide(a.gcd(b));
  }

  public static void main(String... args){
    Scanner in = new Scanner(System.in);
    int TC = in.nextInt();
    for(int tc=0; tc<TC; tc++){
      int B = in.nextInt();
      long N = in.nextLong();
      ArrayList<Integer> barbers = new ArrayList<Integer>();
      for(int i=0; i<B; i++){
        barbers.add(in.nextInt());
      }
      for(int i=0; i<B; i++){
        freebarb[i] = 0;
      }

      // find lcm
      BigInteger cyclelen = new BigInteger("1");
      for(int i=0; i<B; i++){
        cyclelen = lcm(cyclelen, new BigInteger(Integer.toString(barbers.get(i))));
      }

      long percycle = 0;
      for(int i=0; i<B; i++){
        percycle += cyclelen.divide(new BigInteger(Integer.toString(barbers.get(i)))).longValue();
      }

      N = N % percycle;
      if(N == 0){
        N = percycle;
      }

      int ans = 0;
      long time = 0;
      int served = 0;

      while(true){
        // look for first free barber
        int barbnum = -1;
        for(int i=0;i<B;i++){
          if(freebarb[i] <= time){
            barbnum = i;
            break;
          }
        }

        if(served == N-1){
          ans = barbnum+1;
          break;
        }
        freebarb[barbnum] = time + barbers.get(barbnum);
        long wake = 150000000000000L;
        for(int i=0;i<B;i++){
          if(wake > freebarb[i])
            wake = freebarb[i];
        }
        time = wake;
        served++;
      }

      System.out.println("Case #" + (tc+1) + ": " + ans);
    }
  }
}



