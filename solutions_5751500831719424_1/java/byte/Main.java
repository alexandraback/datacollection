import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: gouravr
 * Date: 5/3/14
 * Time: 2:26 AM
 */
public class Main {
    public static class Node {

        public Node(char c, int ct) {
            this.c = c;
            this.ct = ct;
        }

        public char c;
        public int ct;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T, N;
        String str;
        T = Integer.parseInt(br.readLine().trim());
        int index = 0;
        while (T-- > 0) {
            index++;
            System.out.print(String.format("Case #%d: ", index));
            N = Integer.parseInt(br.readLine().trim());
            List<List<Node>> list = new ArrayList<List<Node>>();

            for (int i = 0; i < N; ++i) {
                str = br.readLine().trim();
                Character prev = null;
                Node pn = null;
                List<Node> n = new ArrayList<Node>();
                for (int j = 0; j < str.length(); ++j) {
                    if (prev == null || str.charAt(j) != prev) {
                        if (pn != null) {
                            n.add(pn);
                        }
                        pn = new Node(str.charAt(j), 1);
                        prev = str.charAt(j);
                    } else {
                        pn.ct = pn.ct + 1;
                    }
                }

                n.add(pn);
                list.add(n);
            }

            boolean can = true;
            int ps = list.get(0).size();
            for (int i = 1; i < N; ++i) {
                if (list.get(i).size() != ps) {
                    can = false;
                    break;
                }

                for (int j = 0; j < ps; ++j) {
                    if (list.get(0).get(j).c != list.get(i).get(j).c) {
                        can = false;
                        break;
                    }
                }

                if (!can) {
                    break;
                }
            }

            if (!can) {
                System.out.print("Fegla Won\n");
                continue;
            } else {
                int totalRes = 0;
                for (int i = 0; i < ps; ++i) {
                    int min = 100;
                    int max = 0;
                    for (int j = 0; j < N; ++j) {
                        min = Math.min(min, list.get(j).get(i).ct);
                        max = Math.max(max, list.get(j).get(i).ct);
                    }

                    int res = 10000000;

                    for (int k = min; k <= max; ++k) {
                        int tmp = 0;
                        for (int j = 0; j < N; ++j) {
                            tmp += Math.abs(k - list.get(j).get(i).ct);
                        }
                        res = Math.min(res, tmp);
                    }
                    //System.out.println(list.get(0).get(i).c + " " + ps);
                    totalRes += res;
                }
                System.out.print(totalRes);
                System.out.print("\n");
            }
        }
    }
}

