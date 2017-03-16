/*
ID: epicdav1
LANG: JAVA
TASK: StandingOvation
*/

import java.io.*;
import java.util.*;

class MushroomMonster {

    public static Scanner scn;
    public static PrintWriter out;
    public static int maxd;

    public static void main(String[] args) throws IOException {
        scn = new Scanner(new File("MushroomMonster.in"));
        out = new PrintWriter(new BufferedWriter(new FileWriter("MushroomMonster.out")));

        int tests = scn.nextInt();
        scn.nextLine();

        for (int i = 0; i < tests; i++) {
            doStuff(i+1);
        }

        out.close();
        System.exit(0);
    }

    public static void doStuff(int casen){
        maxd = 0;
        int nmush = scn.nextInt();
        int[] plateamt = new int[nmush];
        for (int i = 0; i < nmush; i++) {
            plateamt[i] = scn.nextInt();
        }
        out.println("Case #" + casen + ": " + fmeth(plateamt)+" "+smeth(plateamt));
    }

    public static int fmeth(int[] mush){
        int count=0;
        for (int i = 0; i < mush.length-1; i++) {
            if (mush[i]>mush[i+1]){
                int diff = mush[i]-mush[i+1];
                count+=diff;
                if (diff>maxd){
                    maxd=diff;
                }
            }
        }
        return count;
    }

    public static int smeth(int[] mush){
        int count = 0;
        for (int i = 0; i < mush.length-1; i++) {
            if (mush[i]<maxd){
                count+=mush[i];
            }else {
                count+=maxd;
            }
        }
        return count;
    }

}