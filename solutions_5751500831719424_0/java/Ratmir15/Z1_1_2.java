package c2014_c.c2014_r2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class Z1_1_2 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z2.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-small-attempt1.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int n = scanner.nextInt();
            String[] l2 = readArray(scanner, n);
            //System.out.println(Arrays.toString(l2));
            //String x = minimize(l2[0]);
            List<Character> idealchars = new ArrayList<Character>();
            List<Integer> idealnumbers = new ArrayList<Integer>();
            idealchars.add(l2[0].charAt(0));
            idealnumbers.add(1);
            for (int j=1;j<l2[0].length();j++) {
                if (l2[0].charAt(j)==l2[0].charAt(j-1)) {
                    idealnumbers.set(idealnumbers.size()-1,idealnumbers.get(idealnumbers.size()-1)+1);
                } else {
                    idealchars.add(l2[0].charAt(j));
                    idealnumbers.add(1);
                }
            }
            //System.out.println(idealchars);
            //System.out.println(idealnumbers);
            boolean fl = true;
            int cnt=0;
            x:
            for (int i=1;i<n;i++) {
                List<Character> chars = new ArrayList<Character>();
                List<Integer> numbers = new ArrayList<Integer>();
                chars.add(l2[i].charAt(0));
                numbers.add(1);
                for (int j=1;j<l2[i].length();j++) {
                    if (l2[i].charAt(j)==l2[i].charAt(j-1)) {
                        numbers.set(numbers.size()-1,numbers.get(numbers.size()-1)+1);
                    } else {
                        chars.add(l2[i].charAt(j));
                        numbers.add(1);
                    }

                }
                if (chars.size()!=idealchars.size()) {
                    fl = false;
                    break;
                }
                System.out.println(numbers);
                System.out.println(idealnumbers);
                for (int j=0;j<chars.size();j++) {
                    if (chars.get(j)!=idealchars.get(j)) {
                        fl = false;
                        break x;
                    }
                    cnt += Math.abs(numbers.get(j)-idealnumbers.get(j));
                }
            }
            String s;
            if (!fl) {
                s = "Case #" + ti + ": Fegla Won";
            } else {
                s = "Case #" + ti + ": "+cnt;
                //Math.abs(l2[0].length()-l2[1].length());
            }
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

    private static String minimize(String s) {
        StringBuilder sb = new StringBuilder();
        sb.append(s.charAt(0));
        for (int i=1;i<s.length();i++) {
            if (s.charAt(i)!=s.charAt(i-1)) {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }

    private static int[][] read2DArray(Scanner scanner, int n, int m) {
        int [][]m1 = new int[n][m];
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                m1[i][j] = scanner.nextInt();
            }
        }
        return m1;
    }

    // 1 0 1 -> [1,0,1]
    private static int[] readIntArray(Scanner scanner, int n) {
        int [] a = new int[n];
        for (int i=0;i<n;i++) {
            a[i] = scanner.nextInt();
        }
        return a;
    }

    // 1 2/ 2 3 -> [[0 1 0],[1 0 1],[0 1 0]]
    private static void readGraphAsMatrix(Scanner scanner, int n, int[][] matrix) {
        for (int i=0;i<n-1;i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            matrix[x-1][y-1] = 1;
            matrix[y-1][x-1] = 1;
        }
    }

    // sdf ssf ggg -> [3]
    private static String[] readArray(Scanner scanner, int n) {
        String[] l2 = new String[n];
        for (int i=0;i<n;i++) {
            l2[i] = scanner.next();
        }
        return l2;
    }

    // 1 2 3 4 5 - > (1,2,3,4,5)
    private static HashSet<String> readSet(Scanner scanner, int n) {
        String[] l1 = new String[n];
        HashSet<String> set1 = new HashSet<String>();
        for (int i=0;i<n;i++) {
            l1[i] = scanner.next();
            set1.add(l1[i]);
        }
        return set1;
    }

}
