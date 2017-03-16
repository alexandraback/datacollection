package ro.hasna.codejam;

import java.io.*;

/**
 * @author Octavian
 * @since 02.05.2015
 */
public class NoisyNeighbors {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("B-small-attempt3.in"));
//        BufferedReader reader = new BufferedReader(new FileReader("B.in"));
        BufferedWriter writer = new BufferedWriter(new PrintWriter("B.out"));
        int t = Integer.parseInt(reader.readLine());

        for (int i = 0; i < t; i++) {
            String[] v = reader.readLine().split(" ");
            int r = Integer.parseInt(v[0]);
            int c = Integer.parseInt(v[1]);
            int n = Integer.parseInt(v[2]);

            int rez = 0;
            n = n - (int) Math.ceil(r * c / 2.0);
            if (n > 0) {
                if (r == 1 || c == 1) {
                    if (r % 2 == 0 || c % 2 == 0) {
                        rez = 1 + (n - 1) * 2;
                    } else {
                        rez = n * 2;
                    }
                } else if (r == 2 || c == 2) {
                    if (n == 1) {
                        rez = 2;
                    } else {
                        rez = 4 + (n - 2) * 3;
                    }
                } else {
                    int k2 = 2;
                    int k3 = r + c - 4;
                    if (r % 2 == 1 && c % 2 == 1) {
                        if (n > 2) {
                            n++;
                            k2 = 4;
                            k3 = (r / 2 - 1) * 2 + (c / 2 - 1) * 2;
                        } else {
                            k2 = 0;
                            k3 = r / 2 * 2 + c / 2 * 2;
                        }
                    }

                    if (n <= k2) {
                        rez = n * 2;
                    } else if (n <= k2 + k3) {
                        rez = k2 * 2 + (n - k2) * 3;
                    } else {
                        rez = k2 * 2 + k3 * 3 + (n - k2 - k3) * 4;
                    }
                }
            }

            writer.append(String.format("Case #%d: %d\r\n", i + 1, rez));
            writer.flush();
        }

        writer.close();
        reader.close();
    }
}
