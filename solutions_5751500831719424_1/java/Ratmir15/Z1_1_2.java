package c2014_c.c2014_r2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Z1_1_2 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z2.txt";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-small-attempt1.in";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int n = scanner.nextInt();
            String[] l2 = readArray(scanner, n);
            boolean fl = true;
            int cnt = 0;
            List<List<Character>> all_chars = new ArrayList<List<Character>>(n);
            List<List<Integer>> all_numbers = new ArrayList<List<Integer>>(n);
            int size = 0;
            x:
            for (int i = 0; i < n; i++) {
                List<Character> chars = new ArrayList<Character>();
                List<Integer> numbers = new ArrayList<Integer>();
                all_chars.add(chars);
                all_numbers.add(numbers);
                chars.add(l2[i].charAt(0));
                numbers.add(1);
                for (int j = 1; j < l2[i].length(); j++) {
                    if (l2[i].charAt(j) == l2[i].charAt(j - 1)) {
                        numbers.set(numbers.size() - 1, numbers.get(numbers.size() - 1) + 1);
                    } else {
                        chars.add(l2[i].charAt(j));
                        numbers.add(1);
                    }
                }
                if (i == 0) {
                    size = chars.size();
                }
                if (size != chars.size()) {
                    fl = false;
                    break;
                }
            }
            if (fl) {
                y:
                for (int j = 0; j < all_chars.get(0).size(); j++) {
                    int max = 0;
                    int min = Integer.MAX_VALUE;
                    for (int k = 0; k < n; k++) {
                        List<Character> characters = all_chars.get(k);
                        if (characters.get(j) != all_chars.get(0).get(j)) {
                            fl = false;
                            break y;
                        }
                        int xx = all_numbers.get(k).get(j);
                        if (xx < min) {
                            min = xx;
                        }
                        if (xx > max) {
                            max = xx;
                        }
                    }
                    int min_cost = Integer.MAX_VALUE;
                    for (int idx = min; idx <= max; idx++) {
                        int cost = 0;
                        for (int k = 0; k < n; k++) {
                            cost += Math.abs(idx - all_numbers.get(k).get(j));
                        }
                        if (cost < min_cost) {
                            min_cost = cost;
                        }
                    }
                    cnt += min_cost;
                }
            }
            String s;
            if (!fl) {
                s = "Case #" + ti + ": Fegla Won";
            } else {
                s = "Case #" + ti + ": " + cnt;
                //Math.abs(l2[0].length()-l2[1].length());
            }
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }

        out.close();
    }

    // 1 0 1 -> [1,0,1]
    private static int[] readIntArray(Scanner scanner, int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        return a;
    }

    // 1 2/ 2 3 -> [[0 1 0],[1 0 1],[0 1 0]]

    private static void readGraphAsMatrix(Scanner scanner, int n, int[][] matrix) {
        for (int i = 0; i < n - 1; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            matrix[x - 1][y - 1] = 1;
            matrix[y - 1][x - 1] = 1;
        }
    }

    // sdf ssf ggg -> [3]
    private static String[] readArray(Scanner scanner, int n) {
        String[] l2 = new String[n];
        for (int i = 0; i < n; i++) {
            l2[i] = scanner.next();
        }
        return l2;
    }

    // 1 2 3 4 5 - > (1,2,3,4,5)
    private static HashSet<String> readSet(Scanner scanner, int n) {
        String[] l1 = new String[n];
        HashSet<String> set1 = new HashSet<String>();
        for (int i = 0; i < n; i++) {
            l1[i] = scanner.next();
            set1.add(l1[i]);
        }
        return set1;
    }

}
