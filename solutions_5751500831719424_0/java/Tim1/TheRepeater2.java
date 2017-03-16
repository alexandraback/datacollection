
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.ArrayList;
import java.util.List;

/**
 * @author  tasyrkin
 * @since   2014/04/12
 */
public class TheRepeater2 {

    private static class Cont {
        char ch;
        int cnt;
    }

    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Integer t = Integer.parseInt(br.readLine());
        int init = t;
        while (t-- > 0) {

            int n = Integer.parseInt(br.readLine());
            List[] arr = new List[n];

            for (int i = 0; i < n; i++) {
                arr[i] = new ArrayList();

                String s = br.readLine();
                char[] ch = s.toCharArray();
                for (int j = 0; j < ch.length; j++) {
                    if (j == 0) {
                        Cont c = new Cont();
                        c.ch = ch[j];
                        c.cnt = 1;
                        arr[i].add(c);
                    } else {
                        Cont c = (Cont) arr[i].get(arr[i].size() - 1);
                        if (c.ch != ch[j]) {
                            Cont c1 = new Cont();
                            c1.ch = ch[j];
                            c1.cnt = 1;
                            arr[i].add(c1);
                        } else {
                            c.cnt++;
                        }
                    }
                }
            }

            boolean fw = false;
            for (int i = 1; i < n; i++) {
                if (arr[i].size() != arr[i - 1].size()) {
                    fw = true;
                    break;
                }

                for (int j = 0; j < arr[0].size(); j++) {
                    if (((Cont) arr[i].get(j)).ch != ((Cont) arr[i - 1].get(j)).ch) {
                        fw = true;
                        break;
                    }
                }
            }

            if (fw) {
                System.out.println("Case #" + (init - t) + ": Fegla Won");
            } else {
                int sum = 0;
                for (int i = 0; i < arr[0].size(); i++) {
                    int min = Integer.MAX_VALUE;
                    for (int j = 1; j <= 100; j++) {
                        int curr = 0;
                        for (int k = 0; k < n; k++) {
                            curr += Math.abs(j - ((Cont) arr[k].get(i)).cnt);
                        }

                        if (curr < min) {
                            min = curr;
                        }
                    }

                    sum += min;
                }

                System.out.println("Case #" + (init - t) + ": " + sum);
            }
        }

    }

}
