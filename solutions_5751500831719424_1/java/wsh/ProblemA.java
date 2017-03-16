
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class ProblemA {
     public static void main(String[] args) throws IOException {
    	Scanner in = new Scanner(new File("A-large.in"));
    	PrintStream out=new PrintStream("A-large.out"); 
    	 
     	//Scanner in = new Scanner(System.in);
     	//PrintStream out=new PrintStream(System.out);
     	 
    	 
        int t=in.nextInt();
        for (int z=1;z<=t;z++)
        {
        	int n=in.nextInt();
        	in.nextLine();
        	String[] s=new String[n];
        	
        	for (int i=0;i<n;i++)
        	{
        		s[i]=in.nextLine().trim();
        	}
        	
        	String[] siden=new String[n];
        	
        	for (int i=0;i<n;i++)
        	{
        		StringBuilder sb=new StringBuilder();
        		sb.append(s[i].charAt(0));
        		
        		for (int j=1;j<s[i].length();j++)
        		{
        			if (s[i].charAt(j)!=s[i].charAt(j-1))
        			{
        				sb.append(s[i].charAt(j));
        			}
        		}
        		siden[i]=sb.toString();
        		//out.println(siden[i]);
        	}
        	
        	boolean haveanswer=true;
        	for (int i=1;i<n;i++)
        	{
        		if (!siden[i].equals(siden[0]))
        		{
        			haveanswer=false;
        			break;
        		}
        	}
        	
        	if (!haveanswer)
        	{
        		out.println("Case #"+z+": Fegla Won");
        	}
        	//judge if fegla win
        	else
        	{
        		int length=siden[0].length();
        		int[][] count=new int[n][length];
        		for (int i=0;i<n;i++)
        		{
        			int step=0;
        			count[i][step]=1;
        			for (int j=1;j<s[i].length();j++)
            		{
            			if (s[i].charAt(j)!=s[i].charAt(j-1))
            			{
            				step++;
            				count[i][step]++;
            			}
            			else count[i][step]++;
            		}
        		}
        		/*
        		System.out.println(count[0][0]);
        		System.out.println(count[0][1]);
        		System.out.println(count[0][2]);
        		System.out.println(count[1][0]);
        		System.out.println(count[1][1]);
        		System.out.println(count[1][2]);
        		System.out.println(count[2][0]);
        		System.out.println(count[2][1]);
        		System.out.println(count[2][2]);
        		*/
        		
    			int answer=0;
        		for (int step=0;step<length;step++)
        		{
        			int lest=Integer.MAX_VALUE;
        			for (int i=0;i<n;i++)
        			{
        				int theone=0;
        				for (int j=0;j<n;j++)
        				{
        					theone+=Math.abs(count[i][step]-count[j][step]);
        				}
        				if (theone<lest)
        				{
        					lest=theone;
        				}
        			}
        			answer+=lest;
        		}
        		

        		out.println("Case #"+z+": "+answer);
        	}
        }   
	}
}
