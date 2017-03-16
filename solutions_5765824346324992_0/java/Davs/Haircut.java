/*
ID: epicdav1
LANG: JAVA
TASK: StandingOvation
*/

import java.io.*;
import java.util.*;

class Haircut {

    public static Scanner scn;
    public static PrintWriter out;

    public static void main(String[] args) throws IOException {
        scn = new Scanner(new File("Haircut.in"));
        out = new PrintWriter(new BufferedWriter(new FileWriter("Haircut.out")));

        int tests = scn.nextInt();
        scn.nextLine();

        for (int i = 0; i < tests; i++) {
            doStuff(i+1);
        }

        out.close();
        System.exit(0);
    }

    public static void doStuff(int casen){
        int nbarbs = scn.nextInt();
        int mpos = scn.nextInt()-1;
        int max =0;
        if (mpos<nbarbs){
            out.println("Case #" + casen + ": " + (mpos+1));
            return;
        }
        int[] barbs = new int[nbarbs];
        long lcm = 1;

        for (int i = 0; i < nbarbs; i++) {
            int cur = scn.nextInt();
            barbs[i]=cur;
            lcm = lcm(lcm, cur);
            if (cur>max){
                max=cur;
            }
        }

//        System.out.println(lcm);

        int countmult = 0;
        for (int i = 0; i < nbarbs; i++) {
            countmult += lcm/barbs[i];
        }

        mpos %=countmult;

        if (mpos<nbarbs){
            out.println("Case #" + casen + ": " + (mpos+1));
            return;
        }else{mpos-=nbarbs;}


//        int mins = 1;
//        boolean[] taken = new boolean[nbarbs];
//        int[] shortests = new int[nbarbs];
//        for (int i = 0; i < nbarbs; i++) {
//            shortests[i]=i;
//        }
//        int[] barbsshort = Arrays.copyOf(barbs, nbarbs);
//        for (int i = 0; i < nbarbs-1; i++) {
//            for (int j = i+1; j < nbarbs; j++) {
//                if (barbsshort[i]>barbsshort[j]){
//                    barbsshort[i]^=barbsshort[j];
//                    barbsshort[j]^=barbsshort[i];
//                    barbsshort[i]^=barbsshort[j];
//                    shortests[i]^=shortests[j];
//                    shortests[j]^=shortests[i];
//                    shortests[i]^=shortests[j];
//                }
//            }
//        }

//        for (int i = 0; i < nbarbs; i++) {
//            System.out.println(shortests[i]+" "+barbsshort[i]);
//        }
//        System.out.println();
//
//        int mins = barbsshort[0];
//        int mins = 1;
        int ppos = 0;
        outer:
        while (mpos>0){
            for (int i = 1; i < max; i++) {
                for (int j = 0; j < nbarbs; j++) {
                    if (barbs[j]%i==0){
                        mpos--;
                    }
                    if (mpos<0){
                        ppos=j;
                        break outer;
                    }
                }
            }
        }
        int barb = ppos;

        out.println("Case #" + casen + ": " + (barb+1));
    }

    public static long gcd(long x, long y){
        while (y>0){
            long holdy = y;
            y = x%y;
            x=holdy;
        }
        return x;
    }

    public static long lcm(long x, long y){
        return x * (y/gcd(x,y));
    }

}