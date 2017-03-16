import java.io.*;
import java.util.*;
import java.math.*;

class Solution {
    
    public static void main(String[] args) throws Exception {
        
        Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        

        for(int m=1;m<=t;m++)
        {
          
          	int n=in.nextInt();
           
            
            int a[]=new int[n];
            for(int i=0;i<n;i++)
            	a[i]=in.nextInt();
            
            System.out.printf("Case #%d: ",m);

            
            int max=0;

            for(int i=0;i<n;i++)
            {
            	if(a[max]<a[i])
            		max=i;
            }
            int max2=0;
            if(max==0)
            	max2=1;
            for(int i=0;i<n;i++)
            {
            	if(a[max2]<a[i] && i!=max)
            		max2=i;
            }

            if(a[max]!=a[max2])
            {
            	while(a[max]!=a[max2])
            	{
            		char d=(char)('A'+max);
            		if(a[max]-a[max2]==1)
            		{
            			System.out.print(d+" ");
            			a[max]--;
            		}
            		else
            		{
            			System.out.print(d+""+d+" ");
            			a[max]-=2;
            		}
            	}
            }

        	for(int i=0;i<n;i++)
        	{
        		char d=(char)('A'+i);
        		while(a[i]!=0 && i!=max && i!=max2)
        		{
        			if(a[i]==1)
        			{
        				System.out.print(d+" ");
        				a[i]--;
        			}
        			else
        			{
        				System.out.print(d+""+d+" ");
        				a[i]-=2;
        			}
        		}
        		
        	}

        	while(a[max]!=0)
        	{
        		char d=(char)('A'+max);
        		char e=(char)('A'+max2);

        		System.out.print(d+""+e+" ");
        		a[max]--;
        	}
            

            System.out.println();

        }
    }
}

    

