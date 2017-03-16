
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;


public class B
{
public static void main(String[] args) throws Exception
    {
        Scanner s=new Scanner(new FileInputStream(args[0]) );
        int t=s.nextInt();
        for (int i=1;i<=t;i++)
        {
             System.out.print("Case #"+i+": ");
             /*long l=s.nextLong();
             ArrayList<Integer> p=new ArrayList<Integer>();
             for (int k=0;k<l;k++)
                 p.add(s.nextInt() );
             System.err.println(p);
             */
             System.out.println(solve(s.nextInt(),s.nextInt(),s.nextInt() ) );
        }
    }
public static int solve(int r, int c, int num)
{
    int ret=0;
    int[][] grid=new int[r][c];
    int i22=0;
    for (int i=0;i<r;i++)
        for (int i2=0;i2<c;i2++)
        {
            if (i22<num)
            {
                grid[i][i2]=1;
                i22++;
            }
            else grid[i][i2]=0;
                
        }
    return solve2(grid,num,0);
    
/*boolean noway=false;
    int happiness=calc_happy(grid);
    while (happiness!=0 && !noway)
    {
        //System.err.println("aaa"+" "+happiness);
        int[] prop=null;
        int new_happi=happiness;
      for (int i=0;i<r  ;i++)
        for (int i2=0;i2<c ;i2++)
        if (grid[i][i2]==1 ) {
            for (int qi=i;qi<r;qi++)
        for (int qi2=i2;qi2<c;qi2++)
        if (grid[qi][qi2]==0 ) {
            grid[i][i2]=0;
            grid[qi][qi2]=1;
            int happi_now=calc_happy(grid);
             //System.err.println(happi_now+" az uj legjobb happi");
            if (happi_now<new_happi)
            {
                if (print) System.err.println(happi_now+" az uj legjobb happi");
                new_happi=happi_now;
                            prop=new int[]{i,i2,qi,qi2};
            }
                        grid[i][i2]=1;
            grid[qi][qi2]=0;

        }
            
        }
                  if (prop!=null)
            {
                //System.err.println(prop);
                grid[prop[0]][prop[1]]=0;
                grid[prop[2]][prop[3]]=1;
                happiness=new_happi;
            }
            else noway=true;

                  
    }
    return happiness;
  */  
}
static boolean print=false;
    private static int calc_happy(int[][] grid) {
        if (print) System.err.println("\n");
        int r=grid.length;
        int c=grid[0].length;
        int ret=0;
        for (int i=0;i<r;i++)
        {
            
        
            for (int i2=0;i2<c;i2++)
            {
        if (print)        System.err.print(grid[i][i2]);
                if (grid[i][i2]==1 )
                {
                    if (i+1<r) if (grid[i+1][i2]==1) ret++;
                
                if (i2+1<c) if (grid[i][i2+1]==1) ret++;
                }
            }
        if (print)    System.err.println("");
        }
        if (print) System.err.println("\n");
        return ret;
            }

    private static int solve2(int[][] grid, int num,int start) {
        int r=grid.length*grid[0].length;
        if (num!=0)
        {
            int legkisebbret=999;
            for (int i=start;i<r;i++)
            {
                int r2=i%grid[0].length;
                int r3=i/grid[0].length;
                grid[r3][r2]=1;
                legkisebbret=Math.min(legkisebbret, solve2(grid,num-1,i+1) );
                grid[r3][r2]=0;
            }
            return legkisebbret;
        }
        else
        {
          return calc_happy(grid);
        }
        
    }
            
        
    
}