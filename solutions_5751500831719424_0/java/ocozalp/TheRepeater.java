import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by ocozalp on 5/3/14.
 */
public class TheRepeater {
    public static void main(String [] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        for(int testCase = 1; testCase <= t; testCase++) {
            int n = sc.nextInt();
            sc.nextLine();

            String [] lines = new String[n];
            for(int i = 0; i<n; i++) lines[i] = sc.nextLine();

            int res = calculate(lines);

            if(res == -1) System.out.println("Case #" + testCase + ": Fegla Won");
            else System.out.println("Case #" + testCase + ": " + res);
        }
    }

    private static int calculate(String [] lines) {
        ArrayList<Token>[] counts = new ArrayList[lines.length];
        for(int i = 0; i<lines.length; i++) counts[i] = new ArrayList<Token>();

        for(int j = 0; j<lines.length; j++) {
            String line = lines[j];
            int count = 1;
            char currentChar = line.charAt(0);
            for(int i = 1; i<line.length(); i++) {
                if(line.charAt(i) == currentChar) count++;
                else {
                    counts[j].add(new Token(currentChar, count));
                    currentChar = line.charAt(i);
                    count = 1;
                }
            }
            counts[j].add(new Token(currentChar, count));
        }

        int len = counts[0].size();
        for(ArrayList<Token> list : counts) {
            if(list.size() != len) return -1;
        }

        for(int i = 0; i<len; i++) {
            char c = counts[0].get(i).c;

            for(ArrayList<Token> list : counts) {
                if(list.get(i).c != c) return -1;
            }
        }

        int result = 0;
        for(int i = 0; i<len; i++) {
            char c = counts[0].get(i).c;
            int [] arr = new int[counts.length];

            for(int j = 0; j<arr.length; j++) {
                arr[j] = counts[j].get(i).count;
            }

            Arrays.sort(arr);

            int subResult = 0;
            int median = arr[arr.length / 2];

            for(int num : arr) subResult += Math.abs(num - median);

            result += subResult;
        }

        return result;
    }

    private static class Token {
        public char c;
        public int count;

        public Token(char c, int count) {
            this.c = c;
            this.count = count;
        }
    }
}
