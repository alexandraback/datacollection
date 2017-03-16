import java.io.File;
import java.util.Arrays;
import java.util.Scanner;


public class code {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(new File("A-large.in"));// "Asample.in"));
    int input_size = s.nextInt();
    for (int n = 0; n < input_size; n++) {
      int test_size = s.nextInt();
      int[] a = new int[test_size];
      for (int x = 0; x < test_size; x++){
        a[x] = s.nextInt();
      }
      int result = solve1(a);
      int result2 = solve2(a);
      System.out.println("Case #" + (n + 1) + ": " + result + " "+result2);
    }
  }
  private static int solve1(int[] a) {
    int result = 0;
    for(int i = 0; i < a.length - 1; i ++){
      if(a[i] > a[i + 1]){
        result += a[i] - a[i + 1];
      }
    }
    return result;
  }

  private static int solve2(int[] a){
    int result = 0;
    int speed = 0;
    for(int i = 0; i < a.length - 1; i++){
      speed = Math.max(speed, a[i] - a[i +1]);
    }
    for(int i = 0; i < a.length - 1; i++){
      result += Math.min(a[i], speed);
    }
    return result;
  }
}
