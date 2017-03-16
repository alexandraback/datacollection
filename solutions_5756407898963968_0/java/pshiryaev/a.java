/*
 Problem A. Magic Trick
 */
package jam.y2014.q;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class a {

    static Scanner in;
    static PrintStream out;
    static final String filepath = System.getProperty("user.dir") + "//src//jam//y2014//q//A-small-attempt1.in";

    public static void main(String[] args) throws FileNotFoundException {
        System.out.println(filepath);
        in = new Scanner(new File(filepath));
        out = new PrintStream(new File(filepath + ".out"));

        int T = Integer.parseInt(in.nextLine()); // The first line of the input gives the number of test cases, T. T test cases follow. 
        for (int t = 1; t <= T; t++) {
            String s1 = getRow();
            String s2 = " " + getRow() + " ";

            int found = 0;
            String card = "";
            int i = 0;
            for (String s : s1.split(" ")) {
                if (s2.contains(" " + s + " ")) {
                    found++;
                    card = s;
                }
            }

            out.print("Case #" + t + ": ");
            if (found == 0) {
                out.println("Volunteer cheated!");
            } else if (found == 1) {
                out.println(card);
            } else {
                out.println("Bad magician!");
            }

        }

        in.close();
        out.close();

    }

    public static String getRow() {
        // Each test case starts with a line containing an integer: the answer to the first question. 
        int pos = Integer.parseInt(in.nextLine());

          // The next 4 lines represent the first arrangement of the cards: each contains 4 integers, 
        // separated by a single space. 
        String result = "";
        for (int i = 1; i <= 4; i++) {
            String s = in.nextLine();
            if (i == pos) {
                result = s;
            }
        }

        return result;
    }

}
