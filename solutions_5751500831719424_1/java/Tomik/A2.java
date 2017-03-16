package round1b;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Created by tomas on 03.05.14.
 */
public class A2 {

    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int N = sc.nextInt();
            sc.nextLine();
            String[] str = new String[N];
            for (int j = 0; j < N; j++) {
                str[j] = sc.nextLine();
            }

            ArrayList<ArrayList<Character>> chars = new ArrayList<ArrayList<Character>>();
            ArrayList<ArrayList<Integer>> counts = new ArrayList<ArrayList<Integer>>();


            for (int j = 0; j < N; j++) {
                char prev = 0;
                int count = 0;
                ArrayList<Character> actChars = new ArrayList<Character>();
                ArrayList<Integer> actCounts = new ArrayList<Integer>();
                for (int k = 0; k < str[j].length(); k++) {
                    char act = str[j].charAt(k);
                    if (prev != act) {
                        if (prev != 0) {
                            actChars.add(prev);
                            actCounts.add(count);
                        }
                        count = 0;
                    }
                    count += 1;
                    prev = act;
                }
                actChars.add(prev);
                actCounts.add(count);
                counts.add(actCounts);
                chars.add(actChars);
            }

            boolean fw = false;

            int size = -1;
            for (ArrayList<Character> al : chars) {
                if (size == -1) {
                    size = al.size();
                } else {
                    if (size != al.size()) {
                        fw = true;
                        break;
                    }
                }
            }

            if (!fw) {
                o:
                for (int j = 0; j < size; j++) {
                    char c = 0;
                    for (ArrayList<Character> al : chars) {
                        if (c == 0) {
                            c = al.get(j);
                        } else {
                            if (c != al.get(j)) {
                                fw = true;
                                break o;
                            }
                        }
                    }
                }
            }

            int oper = 0;
            if (!fw) {
                for (int j = 0; j < size; j++) {
                    ArrayList<Integer> ac = new ArrayList<Integer>();
                    Integer min = Integer.MAX_VALUE;
                    Integer max = Integer.MIN_VALUE;
                    for (ArrayList<Integer> al : counts) {
                        Integer val = al.get(j);
                        ac.add(val);
                        min = Math.min(min, val);
                        max = Math.max(max, val);
                    }

                    Integer currOper = Integer.MAX_VALUE;
                    for (Integer mid = min; mid <= max; mid++) {
                        Integer sum = 0;
                        for (Integer cv : ac) {
                            sum += Math.abs(cv - mid);
                        }
                        currOper = Math.min(currOper, sum);
                    }

                    oper += currOper;
                }
            }


            if (fw) {
                System.out.println("Case #" + i + ": Fegla Won");
            } else {
                System.out.println("Case #" + i + ": " + oper);
            }
        }
    }

}
