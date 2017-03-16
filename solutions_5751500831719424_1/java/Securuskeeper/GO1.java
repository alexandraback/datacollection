import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author securuskeeper - Kevin Wong
 */
public class GO1 {
    
    
    // To store inputs    

    public static void main(String[] args) {
        String base="./";
        String input=base + "A-large.in";
        String output=base + "A-large.out";
        
        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);
            
            int n = sc.nextInt();
            sc.nextLine();
            for (int c=0; c<n; c++) {
                System.out.println("Test case " + (c+1) + "...");
                pw.print("Case #" + (c+1) + ": ");                
                test(sc, pw);
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(GO1.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }

    private static void test(Scanner sc, PrintWriter pw) {

        int n = sc.nextInt();
        
        char[][] c= new char[102][102];
        int[][] cn= new int[102][102];
        int[] p= new int[102];
        int fans=0;
        int d[]=new int[102];
        int minp=0;
        
        boolean skip=false;
        for(int i=0;i<n;i++)
        {
        	p[i]=-1;
        	String s=sc.next();
//        	System.out.println(s);
        	if(!skip)
        	{
        	for(int j=0;j<s.length();j++)
        	{
        		char x=s.charAt(j);
//        		System.out.print("<"+x+">");
        		if(j==0||s.charAt(j-1)!=s.charAt(j))
        		{
        			p[i]++;
        		}
        		c[i][p[i]]=x;
        		cn[i][p[i]]++;
        	}
        	if(i==0)minp=p[i];
        	else
        	{
        		if(p[i]!=minp)
        		{
        	        System.out.println("Fegla Won");
        	        pw.println("Fegla Won");
        	        skip=true;
        		}
        			
        	}
        	}
        }
        
        if(!skip)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<=p[i];j++)
                	System.out.print(c[i][j]);
            	System.out.println();
                for(int j=0;j<=p[i];j++)
                	System.out.print(cn[i][j]);
                System.out.println();
            }

            for(int j=0;j<=minp;j++)
            {
            	char b=c[0][j];
                for(int i=1;i<n;i++)
                {
                	if(c[i][j]!=b)
                	{
            	        System.out.println("Fegla Won");
            	        pw.println("Fegla Won");
            	        return;
                	}
                }
            }
            
            for(int j=0;j<=p[0];j++)
            {
            	int mind=Integer.MAX_VALUE;
            	int ans=0;
            	for(int si=0;si<n;si++)
    		    {
                	int rms=0;
                	for(int i=0;i<n;i++)
                		rms+=Math.abs(cn[i][j]-cn[si][j]);
                	if(rms<mind){
                		ans=si;
                		mind=rms;
                	}
                }
    		    fans+=mind;
    		}

            
           	System.out.println(fans);
            pw.println(fans);
            return;    	
        }
       
    }
}