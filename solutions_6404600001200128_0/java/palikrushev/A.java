
public class A {
  
  public static String mushrooms(int[] values) {
    
    
    long result1 = 0;
    long result2 = 0;
    int difference, maxDifference = 0;
    
    for (int i = 1; i < values.length; i++) {
      difference = values[i-1] - values[i];
      maxDifference = Math.max(maxDifference, difference);
      if (difference > 0) {
        result1 += difference;
      }
    }
    
    
    for (int i = 0; i < values.length - 1; i++) {
      result2 += Math.min(values[i], maxDifference);
    }
    
    return String.valueOf(result1) + " " + String.valueOf(result2);
  }

}