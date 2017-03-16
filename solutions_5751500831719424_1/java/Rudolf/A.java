import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * Created by arudenko on 03.05.14.
 */
public class A {
    public static void main(String[] args) throws FileNotFoundException {
        String fileName = "A-large";
        System.setIn(new FileInputStream(fileName + ".in"));
        System.setOut(new PrintStream(new FileOutputStream(fileName + ".out")));

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int ti = 0;ti < t;ti++) {
            int n = sc.nextInt();
            sc.nextLine();
            String strs[] = new String[n];
            for(int i = 0; i < n;i++) {
                strs[i] = sc.nextLine();
            }
            String result = solve(strs);
            System.out.println("Case #"+(ti+1)+": " + result);

        }

    }

    private static String solve(String[] strs) {
        String et = withoutDuplicates(strs[0]);
        for(int i = 1; i < strs.length; i++) {
            if(!et.equals(withoutDuplicates(strs[i])))
                return "Fegla Won";
        }
        int map[][] = new int[et.length()][strs.length];
        for(int i = 0; i < strs.length; i++) {
            int p = 0;
            map[p][i] = 1;
            for(int j = 1;j < strs[i].length();j++) {
                if(strs[i].charAt(j) != strs[i].charAt(j-1)) {
                    p++;
                    map[p][i] = 1;
                } else {
                    map[p][i]++;
                }
            }
        }
        long result = 0;
        for(int i = 0; i < map.length; i++) {
            result += countMoves(map[i]);
        }

        return result + "";
    }

    private static long countMoves(int[] arr) {
        Arrays.sort(arr);
        int bestRes = -1;
        for(int i = arr[0]; i <= arr[arr.length-1];i++){
            int res = 0;
            for(int j = 0; j < arr.length; j++) {
                res += Math.abs(arr[j] - i);
            }
            if(bestRes == -1 || res < bestRes)
                bestRes = res;
        }

        return bestRes;
    }

    private static String withoutDuplicates(String str) {
        String res = str.substring(0, 1);
        for(int i = 1;i < str.length(); i++) {
            if(res.charAt(res.length() - 1) != str.charAt(i))
                res = res + str.charAt(i);
        }
        return res;
    }
}
