/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author astorres
 */
public class B {

    public static final String rutaDatos = "C:\\Users\\astorres\\Desktop\\CodeJam\\";
    
    public static int G[][];
    public static int INF = 1000000, R, C;
    
    public static int desc() {
        int r = 0;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++) {
                if(i+1<R&&G[i][j]==1&&G[i+1][j]==1) r++;
                if(j+1<C&&G[i][j]==1&&G[i][j+1]==1) r++;
            }
        return r;
    }
    
    public static int min(int r, int c, int n){
        int m=INF;
        if(n==0) return desc();
        if(r>=R) return INF;
        if(c>=C) return min(r+1,0, n);
        G[r][c] = 1;
        m = min(r,c+1,n-1);
        G[r][c] = 0;
        m = Math.min(m,min(r,c+1,n));
        return m;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        String problem = "B";
        //String input=problem+"-sample.in";
        String input=problem+"-small-attempt0.in";
        //String input=problem+"-large.in";
        Scanner in = new Scanner(new File(rutaDatos+input));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(rutaDatos+"out\\"+input+".out.txt")));

        int T = in.nextInt();
        for(int i=0;i<T;i++) {
            
            /*********************************/
            
            R = in.nextInt();
            C = in.nextInt();
            G = new int[R][C];
            for(int j=0;j<R;j++)
                for(int k=0;k<C;k++)
                    G[j][k] = 0;
            int N = in.nextInt();
            
            int res = min(0,0,N);
            
            /*********************************/
            
            System.out.println("Case #"+(i+1)+": "+res);
            out.println("Case #"+(i+1)+": "+res);
        }
        out.close();
    }
    
}
