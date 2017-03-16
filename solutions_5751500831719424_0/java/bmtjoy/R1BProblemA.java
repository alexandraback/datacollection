/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam2014;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 *
 * @author Ben
 */
public class R1BProblemA 
{
    int nCols;
    
    public int solve(ArrayList<ArrayList<Integer>> cols)
    {
        assert(nCols == cols.size());
        
        int total = 0;
        
        for(int colId = 0; colId < cols.size(); colId++)
        {
            ArrayList<Integer> col = cols.get(colId);
            Collections.sort(col);
            int min = col.get(0), max = col.get(col.size()-1);
            int colTot = Integer.MAX_VALUE;
            
            for(int len = min; len <= max; len++){
                
                int tot = 0;
                //make everything length 'len'
                for(int i = 0; i < col.size(); i++){
                    tot += Math.abs(col.get(i) - len);
                }
                
                colTot = Math.min(colTot, tot);
            }
            
            total += colTot;
        }
        
        return total;
    }
    
    public boolean check(int [] cnt, int N){
        nCols = -1;
        int ref = cnt[0];
        for(int i = 1; i < N; i++)
            if(cnt[i] != ref)
                return false;
        nCols = ref;
        return true;
    }
    
    public void go() throws Exception
    {
        try(Scanner sc = new Scanner(new FileReader("A-small-attempt1.in"));
            PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt1.out")))
        {
            int T = sc.nextInt();
            for(int t = 1; t <= T; t++)
            {
                System.out.println("Case: " + t);
                int N = sc.nextInt();
                String [] S  = new String [N];
                for(int i = 0; i < N; i++)
                    S[i] = sc.next();
                
                int [] arr;
                
                int [] cnt = new int [N];
                for(int i = 0; i < N; i++)cnt[i] = 1;
                
                for(int i = 0; i < N; i++){
                    char last = S[i].charAt(0), curr;
                    for(int j = 1; j < S[i].length(); j++){
                        curr = S[i].charAt(j);
                        if(curr != last)
                            cnt[i]++;
                        last = curr;
                    }
                }
                
                if(!check(cnt, N))
                    pw.printf("Case #%d: Fegla Won\n", t);
                else{
                    
                    boolean fail = false;
                    char [] checkStrings = new char[nCols];
                    
                    ArrayList<ArrayList<Integer>> cols = new ArrayList<>();
                    for(int i = 0; i < nCols; i++)
                        cols.add(new ArrayList<Integer>());
                    
                    for(int i = 0; i < N; i++){
                        
                        int count = 1;
                        int  idx  = 0;
                        char prev = S[i].charAt(0), curr;
                        for(int j = 1; j < S[i].length(); j++){
                            curr = S[i].charAt(j);
                            if(curr == prev){
                                count++;
                            }
                            else{
                                
                                if(i == 0){
                                    checkStrings[idx] = prev;
                                }else{
                                    if(prev!=checkStrings[idx])fail = true;
                                }
                                
                                cols.get(idx).add(count);
                                count=1;
                                idx++;
                            }
                            prev = curr;
                        }
                        
                        if(i == 0)
                            checkStrings[idx] = prev;
                        else if(prev != checkStrings[idx])fail = true;
                        
                        cols.get(idx).add(count);
                        ///assert(idx == nCols);
                    }
                    
                    if(fail)
                        pw.printf("Case #%d: Fegla Won\n", t);
                    else
                        pw.printf("Case #%d: %d\n", t, solve(cols));
                }
            }
        }
    }
}
