import java.util.*;
import java.io.*;
public class B2 {
public static void main(String args[]) throws Exception
{
	Scanner in = new Scanner(new File("B.in"));
	int numcases = in.nextInt();
	int count=1;
	while(numcases-->0)
	{
		int b = in.nextInt();
		long n = in.nextLong();
		
		long pcount = 0;
		
		long[] ctime = new long[b];
		boolean[] busy = new boolean[b];
		for(int i=0;i<ctime.length;i++)
		{
			ctime[i] = in.nextLong();
			busy[i] = false;
		}
		
		long lcm = lcm(ctime);
		long lcmcount = 0;
		for(int i=0;i<ctime.length;i++)
		{
			lcmcount+=lcm/ctime[i];
		}
		
		long lcmmult = (n-ctime.length)/lcmcount;
		
		long time = lcmmult*lcm;
		lcmcount*=lcmmult;
		lcmcount+=ctime.length;
		pcount = lcmcount;

		if(pcount==n)
		{	pcount-=ctime.length; time-=1;
			for(int i=0;i<ctime.length;i++)
			{
			 busy[i] = true;	
			}
		}
		if(lcmmult==0)
		{	pcount=0; time=0;}
		
			
		
		//////////////////////////////////
		
		out:	while(pcount<=n)
		{
		 	for(int i=0;i<ctime.length;i++)
		 	{
		 	//	System.out.println("time: "+time);
		 	//	System.out.println("pcount: "+pcount+" n: "+n);
		 		
		 	  if(busy[i])
		 	  {
		 		if(time%ctime[i]==0)
		 			busy[i] = false;
		 	  }
		 	  if(!busy[i])
		 	  {
		 		  pcount++;
		 		  busy[i] = true;
		 		  if(pcount==n)
		 		  {  System.out.println("Case #"+count+": "+(i+1)); }
		 	  }
		 	  
		 	}
		 	
		 	time++;
		}
		
		/////////////////////////////////////
		
		count++;
		
	}
	
}

private static long gcd(long a, long b)
{
    while (b > 0)
    {
        long temp = b;
        b = a % b; // % is remainder
        a = temp;
    }
    return a;
}

private static long lcm(long a, long b)
{
    return a * (b / gcd(a, b));
}

private static long lcm(long[] input)
{
    long result = input[0];
    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
    return result;
}


}