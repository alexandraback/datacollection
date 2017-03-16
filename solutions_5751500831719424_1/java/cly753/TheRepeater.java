import java.io.*;
import java.util.*;


public class TheRepeater {
    public static Scanner sc;

    public static void main(String[] args) throws Exception {
//        sc = new Scanner(System.in);
        sc = new Scanner(new File("E:\\GitHub\\HHH\\CodeJam\\TheRepeater\\A-large.in"));
        int c = sc.nextInt();
        String sol = "";

        for (int i = 1; i <= c; i++) {
        	sol += "Case #" + i + ": " + solve() + "\n";
      	 // System.out.println("now is " + i);
        }

        System.out.print(sol);
        PrintWriter pw = new PrintWriter(new File("E:\\GitHub\\HHH\\CodeJam\\TheRepeater\\A-large.out"));
        pw.print(sol);
        pw.close();
    }

    public static String solve() {
    	int numString = sc.nextInt();

        String[] s = new String[numString];
        for (int i = 0; i < numString; i++) {
            s[i] = sc.next();
        }
        
        for (int i = 0; i < numString; i++) { // optimize here!!!
            for (int j = i + 1; j < numString; j++) {
                if (!isValid(s[i], s[j])) {
                    return "Fegla Won";
                }
            }
        }

        int n = 1;
        char temp0 = s[0].charAt(0);
        for (int i = 0; i < s[0].length(); i++) {
            char temp = s[0].charAt(i);
            if (temp != temp0) {
                n++;
                temp0 = temp;
            }
        }
//        System.out.println("n: " + n);

        int[][] numC = new int[numString][n];
        for (int i = 0; i < numString; i++) {
            fill(numC[i], s[i]);
        }
        
//        for (int j = 0; j < numString; j++) {
//        	for (int i = 0; i < n; i++) {
//            	System.out.print(numC[j][i]);
//            }
//            System.out.println();
//        }   

        int[] mid = new int[n];
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = 0; j < numString; j++) {
                temp += numC[j][i];
            }
            mid[i] = temp / numString;
        }        

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int minNow = 100000;
            for (int h = 0; h <= 100; h++) {
                int temp = 0;
                for (int j = 0; j < numString; j++) {
//                    System.out.println("h: " + h + ", " + absDiff(numC[j][i], h));
                    temp += absDiff(numC[j][i], h);
                }
                if (minNow > temp) {
                    minNow = temp;
                }
            }
            ans += minNow;
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
        
       // System.out.println(oneTemp);
       // System.out.println(twoTemp);

        if (oneTemp.equals(twoTemp)) {
       	// System.out.println("equals");
        	return true;
        }
       // System.out.println("not equals");
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
       // System.out.println(temp);
        return temp;
    }

    public static void fill(int[] toFill, String one) {
        char temp0 = one.charAt(0);
        int j = 0;
        for (int i = 0; i < one.length(); i++) {
            if (one.charAt(i) == temp0) {
                toFill[j]++;
            } else {
                temp0 = one.charAt(i);
                j++;
                toFill[j]++;
            }
        }
    }
}