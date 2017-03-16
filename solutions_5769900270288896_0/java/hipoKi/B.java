package b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class B {
    public void solve() throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("B-small-attempt0.in")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        
        for(int ii = 0; ii < T; ii++)
        {
            out.print("Case #" + (ii+1) + ": ");
            int R = in.nextInt();
            int C = in.nextInt();
            int N = in.nextInt();
            int filled = R * C;
            boolean occupied[][] = new boolean[R][C];
            for(int r = 0; r < R; r++)
                for(int c = 0; c < C; c++)
                {
                    occupied[r][c] = true;
                }
            
            for(int i = 4; -1 < i; i--)
            {
                if(filled == N)
                    break;
                for(int r = 0; r < R; r++)
                {
                    if(filled == N)
                        break;
                    for(int c = 0; c < C; c++)
                    {
                        if(this.valor(occupied, r, c, R, C) == i)
                        {
                            occupied[r][c] = false;
                            filled--;
                            if(filled == N)
                                break;
                        }
                    }
                }
            }
            out.println(this.countUnhappines(occupied, R, C));
        }
        
        out.close();
        in.close();
    }

    public void solve2() throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("B-small-attempt1.in")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("b1.out")));
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        
        for(int ii = 0; ii < T; ii++)
        {
            out.print("Case #" + (ii+1) + ": ");
            int R = in.nextInt();
            int C = in.nextInt();
            int N = in.nextInt();
            int res = Integer.MAX_VALUE;
            LinkedList<Integer> comb = null;
            while((comb = this.nextCombination(R*C-1, N, comb)) != null)
            {
                boolean occupied[][] = new boolean[R][C];
                
                for(int i = 0; i < comb.size(); i++)
                {
                    int cell = comb.get(i);
                    occupied[cell/C][cell%C] = true;
                }
                
                res = Math.min(res, this.countUnhappines(occupied, R, C));
            }
            out.println(res);
        }
        
        out.close();
        in.close();
    }

    public static void main(String... args) throws IOException {
        B b = new B();
        b.solve2();
    }

    private int valor(boolean[][] occupied, int r, int c, int R, int C) {
        int result = 0;
        if(0 < r && occupied[r-1][c])
            result++;
        if(0 < c && occupied[r][c-1])
            result++;
        if(r < (R-1) && occupied[r+1][c])
            result++;
        if(c < (C-1) && occupied[r][c+1])
            result++;
        return result;
    }

    private int countUnhappines(boolean[][] occupied, int R, int C) {
        int res = 0;  
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++)
                if(occupied[r][c])
                    res += this.valor(occupied, r, c, R, C);
        return res / 2;
    }
    
    LinkedList<Integer> firstCombination(int max, int cant)
    {
        LinkedList<Integer> res = new LinkedList<Integer>();
        for(int i = 0; i < cant; i++)
            res.add(i);
        return res;
    }
    
    LinkedList<Integer> nextCombination(int max, int cant, LinkedList<Integer> l)
    {
        if(l == null)
            return this.firstCombination(max, cant);
        int pos = l.size() - 1;
        while(pos>-1)
        {
            if(l.get(pos) == max-(l.size()-1-pos))
            {
                pos--;
            } else {
                int val = l.get(pos);
                for(int i = pos; i < l.size(); i++)
                {
                    val++;
                    l.set(i, val);
                }
                break;
            }
        }
        if(pos == -1)
            return null;
        else
            return l;
    }
    
    public void testComb()
    {        
        PrintWriter out = new PrintWriter(System.out);
        LinkedList<Integer> comb = null;
        while((comb = this.nextCombination(2, 0, comb)) != null)
        {
            for(int i = 0; i < comb.size(); i++)
                out.print(" " + comb.get(i));
            out.println();
        }
    }
}
