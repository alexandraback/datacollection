package prob1;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by lvitor on 30/04/16.
 */
public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("src/prob1/in2.in"));
        PrintWriter out = new PrintWriter("src/prob1/out2.txt");
        Main m = new Main();
        int T = in.nextInt();
        in.nextLine();
        for(int i = 1; i <= T; i++){
            int nParties = in.nextInt();
            int total = 0;
            int[] parties = new int[nParties];
            for(int j=0; j<nParties; j++){parties[j] = in.nextInt();total += parties[j];};
            String sol = m.solve(total, parties);
            System.out.println("Case #" + i + ": " + sol);
            out.write("Case #" + i + ": " + sol);
            out.write("\n");
        }
//        while(in.hasNext()){
////            System.out.println(in.next());
//            out.write(in.nextLine()); // in.next() retrieves next token
//        }
        out.close();
    }

    public void printParties(int[] p){
        for(int i=0; i<p.length; i++)
        System.out.print(p[i] + " ");
        System.out.println();
    }

    public String solve(int tot, int[] p){
        if(tot == 0)return "";
//        printParties(p);
        String out = "";
        if(tot % 2 == 1){
            int m = findMax(p);
            p[m]--;
            tot--;
            out += Character.toChars('A'+m)[0] + " ";
        }
        while(tot > 0){
            int m = findMax(p);
            p[m]--;
            tot--;
            out += Character.toChars('A'+m)[0];
            m = findMax(p);
            p[m]--;
            tot--;
            out += Character.toChars('A'+m)[0] + " ";
        }
        return out;
    }

    public int findMax(int[] p){
        int max = 0;
        for(int i=0; i<p.length; i++){
            if(p[i] > p[max])max = i;
        }
        return max;
    }


}
