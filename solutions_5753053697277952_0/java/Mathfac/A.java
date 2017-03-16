import java.io.*;
import java.util.*;

public class A {

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        A solver = new A();
        solver.solve(1, in, out);
        out.close();
    }

    private static void removeDig(Map<Character, Integer> chMap, String dig_name, int times){
        for(Character c : dig_name.toCharArray()) {
            chMap.put(c, chMap.get(c) - times);
        }
    }

    private static void minimize(int[] arr, int st){
        for(int i = st; i < arr.length; i++) {
            if (arr[i] == -1) {
                arr[i] = 0;
            }
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int tn = in.nextInt();
//        String [] dig = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
//        Map<Character, Set<Integer>> setDig = new HashMap<>();
//        for (int i = 0; i < 10; i++) {
//            for (Character c : dig[i].toCharArray()) {
//                if (!setDig.containsKey(c)) {
//                    setDig.put(c,new HashSet<Integer>());
//                }
//                setDig.get(c).add(i);
//            }
//        }
//
//        for (Map.Entry<Character, Set<Integer>> c : setDig.entrySet()) {
//            System.out.print(c.getKey() + ": ");
//            for (Integer num : c.getValue()) {
//                System.out.print(num + ", ");
//            }
//            System.out.println();
//        }

        for (int ti = 0; ti < tn; ti++) {
            int n = in.nextInt();
            int[] a = new int[n];
            for(int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            System.out.print("Case #" + (ti + 1) + ": ");

            int maxIndex = 0;
            int maxIndex2 = 1;

                for (int i = 1; i < a.length; i++) {
                    int newnumber = a[i];
                    if ((newnumber > a[maxIndex])) {
                        maxIndex2 = maxIndex;
                        maxIndex = i;
                    } else
                        if ((newnumber > a[maxIndex2])) {
                            maxIndex2 = i;
                        }

                }

                if (maxIndex != maxIndex2) {
                    for (int i = a[maxIndex2]; i < a[maxIndex]; i++ ) {
                        System.out.print((char)('A' + maxIndex) + " ");
                    }
                    a[maxIndex] = a[maxIndex2];
                }

                for (int i = 0; i < a.length; i++) {
                    if (i != maxIndex && i != maxIndex2) {
                        for (int j = 0; j < a[i]; j++ ) {
                            System.out.print((char)('A' + i) + " ");
                        }
                        a[i] = 0;
                    }

                }

                for (int i = 0; i < a[maxIndex]; i++) {
                    System.out.print((char)('A' + maxIndex));
                    System.out.print((char)('A' + maxIndex2));
                    if (i < a[maxIndex] - 1)
                        System.out.print(" ");

                }





            System.out.println();
        }
    }

}


