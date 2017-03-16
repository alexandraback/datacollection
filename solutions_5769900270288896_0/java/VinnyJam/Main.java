package problemb;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        //Scanner in = new Scanner(new File("B-large.in"));
        Scanner in = new Scanner(new File("B-small-attempt1.in"));
        //Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter(new File("output.txt"));
        int test = in.nextInt();
        for (int t = 0; t < test; t++) {
            int r = in.nextInt();
            int c = in.nextInt();
            int n = in.nextInt();
            if (n <= (r * c + 1) / 2) {
                out.println("Case #" + (t + 1) + ": " + 0);
            } else {
                int bad = (r - 1) * c + (c - 1) * r;
                int m = r * c - n;
                if (r > c) {
                    int r1 = r;
                    r = c;
                    c = r1;
                }
                if (r == 1) {
                    out.println("Case #" + (t + 1) + ": " + (bad - 2 * m));
                } else {

                    if ((r * c % 2 == 0)) {
                        if (((r - 2) * (c - 2) + 1) / 2 >= m) {
                            bad -= 4 * m;
                            out.println("Case #" + (t + 1) + ": " + bad);

                        } else {
                            m -= (r - 2) * (c - 2) / 2;
                            bad -= 2 * (r - 2) * (c - 2);
                            if (m <= (r - 2) + (c - 2)) {
                                bad -= 3 * m;
                                out.println("Case #" + (t + 1) + ": " + bad);
                            } else {
                                bad -= (r - 2 + c - 2);
                                bad -= 2 * m;
                                out.println("Case #" + (t + 1) + ": " + bad);
                            }
                        }
                    } else {
                        int bad1 = (r - 1) * c + (c - 1) * r;
                        int bad2 = (r - 1) * c + (c - 1) * r;
                        int m0 = m;
                        if (((r - 2) * (c - 2) + 1) / 2 >= m) { //black
                            bad1 -= 4 * m;

                        } else {
                            m -= ((r - 2) * (c - 2) + 1) / 2;
                            bad1 -= 2 * ((r - 2) * (c - 2)) + 2;
                            if (m <= (r - 3 + c - 3)) {
                                bad1 -= 3 * m;

                            } else {
                                bad1 -= (r - 3 + c - 3);
                                bad1 -= 2 * m;

                            }
                        }

                        m = m0;
                        if (((r - 2) * (c - 2)) / 2 >= m) {
                            bad2 -= 4 * m;

                        } else {
                            m -= (r - 2) * (c - 2) / 2;
                            bad2 -= 2 * (r - 2) * (c - 2) - 2;
                            if (m <= (r - 1 + c - 1)) {
                                bad2 -= 3 * m;

                            } else {
                                bad2 -= r - 1 + c - 1;
                                bad2 -= 2 * m;
                            }
                        }
                        if (bad2 > bad1) {
                            bad2 = bad1;
                        }
                        out.println("Case #" + (t + 1) + ": " + bad2);
                    }
                }
            }
        }
        out.flush();
        out.close();

    }

}
