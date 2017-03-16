
public class B1 {

  public static int barber(long[] input, int N) {
    
    long second = findMinSecond(input, N);
    int numberOfPeopleStrtingHaircut = numberOfPeopleStrtingHaircut(input, second);
    int minN = findMinN(N - numberOfPeopleStrtingHaircut, N, second, input);
    
    int result = findFirstFreeBarkerForSecond(input, second, N - minN);
    
    return result;
  }
  
  private static int findMinN(int minN, int maxN, long second, long[] input) {
    
    int low = minN;
    int high = maxN;

    while (low <= high) {
      int mid = (low + high) >>> 1;
      
      long curSec = findMinSecond(input, mid);

      if (curSec < second) {
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }

    return low;
  }
  
  private static int numberOfPeopleStrtingHaircut(long[] input, long second) {
    
    int result = 0;
    
    for (int i = 0; i < input.length; i++) {
      if ((second - 1) % input[i] == 0) {
        result++;
      }
    }
    
    return result;
  }
  
  private static int findFirstFreeBarkerForSecond(long[] input, long second, int Nth) {
    int result = 0;
    
    for (int i = 0; i < input.length; i++) {
      if ((second - 1) % input[i] == 0) {
        if (Nth == 0) {
          result = i;
          break;
        } else {
          Nth--;
        }
      }
    }
    
    return result + 1;
  }
  
  private static long findMinSecond(long[] input, long N) {
    
    long low = 0;
    long high = 100000000000002L;

    while (low <= high) {
      long mid = (low + high) >>> 1;
      
      boolean canChop = canChopNForTime(input, mid, N);

      if (!canChop) {
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }

    return low;
  }
  
  private static boolean canChopNForTime(long[] input, long time, long N) {
    
    long total = 0;
    
    for (int i = 0; i < input.length; i++) {
      total += time / input[i];
      if (time % input[i] != 0) {
        total++;
      }
    }
    
    return total >= N;
  }
  
}
