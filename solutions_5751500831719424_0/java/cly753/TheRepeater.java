import java.io.*;
import java.util.*;


public class TheRepeater {
    public static Scanner sc;

    public static void main(String[] args) throws Exception {
//        sc = new Scanner(System.in);
        sc = new Scanner(new File("E:\\GitHub\\HHH\\CodeJam\\TheRepeater\\A-small-attempt1.in"));
        int c = sc.nextInt();
        String sol = "";

        for (int i = 1; i <= c; i++) {
        	sol += "Case #" + i + ": " + solve() + "\n";
//        	System.out.println("now is " + i);
        }
            

        System.out.print(sol);
        PrintWriter pw = new PrintWriter(new File("E:\\GitHub\\HHH\\CodeJam\\TheRepeater\\A-small-attempt1.out"));
        pw.print(sol);
        pw.close();
    }

    public static String solve() {
    	int noUseForSmallData = sc.nextInt();
    	
        String o = sc.next();
        String t = sc.next();
        
        if (!isValid(o, t)) {
        	return "Fegla Won";
        }

        int n = 1;
        char temp0 = o.charAt(0);
        for (int i = 0; i < o.length(); i++) {
            char temp = o.charAt(i);
            if (temp != temp0) {
                n++;
                temp0 = temp;
            }
        }
        
        int[] one = new int[n];
        int[] two = new int[n];

        temp0 = o.charAt(0);
        int j = 0;
        for (int i = 0; i < o.length(); i++) {
            char temp = o.charAt(i);
            if (temp == temp0) {
                one[j]++;
            } else {
                temp0 = temp;
                
                j++;
                one[j]++;
            }
        }

        temp0 = t.charAt(0);
        j = 0;
        for (int i = 0; i < t.length(); i++) {
            char temp = t.charAt(i);
            if (temp == temp0) {
                two[j]++;
            } else {
                temp0 = temp;
                j++;
                two[j]++;
            }
        }
        

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += absDiff(one[i], two[i]);
        }

        return "" + ans;
    }

    public static int absDiff(int a, int b) {
        int temp = a - b;
        if (temp > 0)
            return temp;
        return -1 * temp;
    }

    public static boolean isValid(String one, String two) {
        String oneTemp = toBasic(one);
        String twoTemp = toBasic(two);
        
//        System.out.println(oneTemp);
//        System.out.println(twoTemp);

        if (oneTemp.equals(twoTemp)) {
//        	System.out.println("equals");
        	return true;
        }
//        System.out.println("not equals");
        return false;
    }

    public static String toBasic(String one) {
        String temp = "";

        char tempChar = one.charAt(0);
        temp += Character.toString(one.charAt(0));
        for (int i = 0; i < one.length(); i ++) {
            if (one.charAt(i) != tempChar) {
                temp += Character.toString(one.charAt(i));
                tempChar = one.charAt(i);
            }
        }
//        System.out.println(temp);
        return temp;
    }
}