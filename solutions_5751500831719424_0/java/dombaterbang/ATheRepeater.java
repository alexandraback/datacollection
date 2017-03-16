package com.ariantoanugerah.gcj2014.r1b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by ariantoanugerah on 04/05/14.
 */
public class ATheRepeater {

    private String fileName = "A-small-attempt0";

    private Scanner sc;
    private PrintWriter pw;

    public static void main(String[] args) {
        ATheRepeater q = new ATheRepeater();
        q.start();
    }

    private void start() {
        try {
            String dir = "src" + File.separator + ATheRepeater.class.getName().replaceAll("\\.", File.separator);
            dir = dir.substring(0, dir.lastIndexOf(File.separatorChar)+1);

            sc = new Scanner(new File(dir + fileName + ".in"));
            pw = new PrintWriter(new File(dir + fileName + ".out"));

            int totalCase = Integer.parseInt(sc.nextLine());

            for (int caseNo = 1; caseNo <= totalCase; caseNo++) {
                CaseSolver cs = new CaseSolver(caseNo, sc, pw);
                String result = cs.start();

                pw.println("Case #" + caseNo + ": " + result);
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } finally {
            if (sc!=null) {
                sc.close();
            }
            if (pw!=null) {
                pw.close();
            }
        }
    }

    class CaseSolver {
        Scanner sc;
        PrintWriter pw;
        int caseNo;

        int num;
        int len;

        public CaseSolver(int caseNo, Scanner sc, PrintWriter pw) {
            this.caseNo = caseNo;
            this.pw = pw;
            this.sc = sc;
        }

        public String start() {

            int totalStr = Integer.parseInt(sc.nextLine());

            String[] str = new String[totalStr];
            char[][] strChar = new char[totalStr][];
            int[] strPointer = new int[totalStr];


            for (int i = 0; i < totalStr; i++) {
                str[i] = sc.nextLine();
                strChar[i] = str[i].toCharArray();
            }

            int[][] charCount = new int[totalStr][100];

            boolean valid = true;
            boolean finished = false;
            int charSeq = 0;

            while (valid && !finished) {

                char currentChar = '.';
                if (strPointer[0] < strChar[0].length) {
                    currentChar = strChar[0][strPointer[0]];
                }


                for (int i = 0; i < totalStr; i++) {
                    char myChar = '.';
                    if (strPointer[i] < strChar[i].length) {
                        myChar = strChar[i][strPointer[i]];
                    }

                    if (myChar != currentChar) {
                        valid = false;
                        break;
                    } else {
                        charCount[i][charSeq]++;

                        while (strPointer[i] < strChar[i].length && strChar[i][strPointer[i]] == currentChar) {
                            charCount[i][charSeq]++;
                            strPointer[i]++;
                        }
                    }
                }

                if (currentChar == '.' && valid) {
                    finished = true;
                } else {
                    charSeq++;
                }
            }

            if (!valid) {
                return "Fegla Won";
            } else {
                int totAll = 0;
                for (int i = 0; i < charSeq; i++) {
//                    for (int j = 0; j < totalStr; j++) {
//                        System.out.print(" " + charCount[j][i]);
//
//                    }
//
//                    System.out.println();

                    int currentMinimum = 9999;
                    Map<Integer, Boolean> minMap = new HashMap<Integer, Boolean>();
                    for (int j = 0; j < totalStr; j++) {
                        if (minMap.get(charCount[j][i]) == null) {
                            int tot = 0;
                            //calc
                            for (int k = 0; k < totalStr; k++) {
                                tot += Math.abs(charCount[j][i] - charCount[k][i]);
                            }

                            if (tot < currentMinimum) {
                                currentMinimum = tot;
                            }

                            minMap.put(charCount[j][i], Boolean.TRUE);
                        } else {
                            continue;
                        }
                    }
                    totAll += currentMinimum;
//                    System.out.println(currentMinimum);
                }


                return String.valueOf(totAll);
            }

        }

    }
}

