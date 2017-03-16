import java.io.File;
import java.util.Arrays;
import java.util.Scanner;


public class code {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(new File("B-small-attempt1.in"));// "Asample.in"));
    int input_size = s.nextInt();
    for (int n = 0; n < input_size; n++) {
      int test_size = s.nextInt();
      int place = s.nextInt();
      int[] a = new int[test_size];
      for (int x = 0; x < test_size; x++){
        a[x] = s.nextInt();
      }
      int result = solve(a, place);
      System.out.println("Case #" + (n + 1) + ": " + result);
    }
  }

  private static int solve(int[] a, int n){
    boolean allEqual = true;
    for(int i = 1; i < a.length; i++){
      if(a[i] != a[0]){
        allEqual = false;
        break;
      } 
    }

  if(allEqual){
    return (n - 1)% a.length + 1;
  }
    long l = lcm(a);
    int count = 0;
    for(int i = 0; i < a.length; i++){
      count += l/a[i];
    }
    n = (n-1) % count + 1;
    if(n < a.length){
      return n;
    }
    return solve1(a, n);
  }

  private static int solve1(int[] a, int n){
    int time = 0;
    int count = a.length;
    int[] timeLeft = new int[a.length];
    System.arraycopy(a, 0, timeLeft, 0, a.length);
    while(true){
      int[] index = new int[a.length + 1];
      int interval = min(timeLeft,index);
      minus(timeLeft, interval);
      if(count + index[0] >= n){
        return index[n - count] + 1;
      }
      count += index[0];
      for(int j = 0; j < index[0]; j++){
        timeLeft[index[1 + j]] = a[index[1 + j]];
      }
    }
  }

  private static int min(int[] a, int[] index){
    int result = a[0];
    int count = 1;
    for(int i = 1; i < a.length; i++){
      result = Math.min(result, a[i]);
    }
    for(int i = 0; i < a.length; i++){
      if(a[i] == result){
        index[count] = i;
        count++;
      }
    }
    index[0] = count - 1;
    return result;
  }

  private static void minus(int[] a, int m){
    for(int i = 0; i < a.length; i++){
      a[i] -= m;
    }
  }

  private static int gcd(int a, int b)
{
    while (b > 0)
    {
        int temp = b;
        b = a % b; // % is remainder
        a = temp;
    }
    return a;
}

private static int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

private static int lcm(int[] input)
{
    int result = input[0];
    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
    return result;
}

}
