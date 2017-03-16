import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class a {

  private static Scanner input;


  public static void main(String[] args) {
    input = new Scanner(System.in);
    int t = input.nextInt();
    for (int i = 0; i < t; i++) {
      int n = input.nextInt();
      String nowTemplete = "";
      boolean hasAnw = true;
      List<String> inputStr = new ArrayList<String>();
      for (int j = 0; j < n; j++) {
        String tmp = input.next();
        String cut = cutStr(tmp);
        if (nowTemplete.length() == 0) {
          nowTemplete = cut;
        } else {
          if (!nowTemplete.equals(cut)) {
            hasAnw = false;
            break;
          }
        }
        inputStr.add(tmp);
      }
      if (hasAnw) {
        int min = 0;
        for (int k = 0; k < nowTemplete.length(); k++) {
          char p = nowTemplete.charAt(k);
          List<Integer> lengtharr = new ArrayList<Integer>();
          for (int q = 0; q < inputStr.size(); q++) {
            String tmpStr = inputStr.get(q);
            Integer ll = 0;
            for (int w = 0; w < tmpStr.length(); w++) {
              if (tmpStr.charAt(w) == p) {
                ll++;
              } else {
                break;
              }
            }
            tmpStr = tmpStr.substring(ll);
            inputStr.set(q, tmpStr);
            lengtharr.add(ll);
          }
          int mindiff = getMinDiff(lengtharr);
          min += mindiff;
        }
        System.out.println("Case #" + (i + 1) + ": " + min);
      } else {
        System.out.println("Case #" + (i + 1) + ": Fegla Won");
      }
    }
  }


  private static int getMinDiff(List<Integer> lengtharr) {
    int min = -1;
    for (int i = 0; i < lengtharr.size(); i++) {
      int base = lengtharr.get(i);
      int tmpmin = 0;
      for (Integer t : lengtharr) {
        tmpmin += Math.abs(t - base);
      }
      if (min == -1 || min > tmpmin) {
        min = tmpmin;
      }
    }
    return min;
  }


  public static String cutStr(String in) {
    String cut = "";
    cut += in.charAt(0);
    for (int i = 1; i < in.length(); i++) {
      if (in.charAt(i) != in.charAt(i - 1)) {
        cut += in.charAt(i);
      }
    }
    return cut;
  }


}
