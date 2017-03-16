package com.google.codejam.b14;

import com.google.codejam.Problem;

public class ProblemA extends Problem {

    public ProblemA() {
        //super("test/Test.in");
        super("A-large.in");
        //super("A-small-attempt1.in");
    }

    public static void main(String[] args) {
        new ProblemA().solve();
    }

    @Override
    protected String run() {
        int result = 0;
        int n = input.getInt();
        String[] lines = new String[n];
        for (int i = 0; i < n; i++){
            lines[i] = input.nextLine();
        }
        int[] index = new int[n];
        int[] fa = new int[n];
        while (true){
            char ch = 0;
            for (int i = 0 ; i < n; i++){
                int f = 0;
                while (index[i] < lines[i].length()){
                    if (ch == 0){
                        ch = lines[i].charAt(index[i]);
                    }
                    boolean isMatch = lines[i].charAt(index[i]) == ch;
                    if (isMatch){
                        index[i]++;
                        f++;
                    } else {
                        break;
                    }
                }
                fa[i] = f;
            }

            int zeros = 0;
            for (int f : fa) {
                if (f == 0){
                    zeros ++;
                }
            }

            if (zeros == n){
                break;
            } else if (zeros > 0) {
                return "Fegla Won";
            }


            result += min(fa);
        }




        return result + "";
    }

    private int min(int[] fa) {
        int m = Integer.MAX_VALUE;
        for (int f0 : fa){
            int c = 0;
            for (int f : fa){
                c += Math.abs(f - f0);
            }
            m = Math.min(m, c);
        }
        return m;
    }
}
