import java.util.*;

public class repeater
{
	static Scanner scan;
	static int T, N, index, moves; 
	static String out, reduced;	
	static String[] words;
	static int[][] f;
	static boolean lost;
	
	static void init()
	{
		N= scan.nextInt();
		words= new String[N];
		reduced="";
		out="";
		index=0;
		moves=0;
		lost=false;
		f= new int[100][100];
		for(int i=0; i<N; i++)
			words[i]=scan.next();
			
	}
	public static void main(String[] args)
	{
		scan= new Scanner(System.in);
		T= scan.nextInt();
		
		for(int t=1; t<=T; t++)
		{	
			init();
			
			for(int i=0; i<N && !lost; i++)
			{
				String t1=words[i].charAt(0)+"";
				index=0;
				f[i][0]=1;
				for(int j=1 ;j<words[i].length(); j++)
				{
					if(words[i].charAt(j)!=words[i].charAt(j-1))
					{
						t1+=words[i].charAt(j);
						index++;
						f[i][index]++;
					}
					else
						f[i][index]++;
				}
				
				if(i==0)
					reduced=t1;
					
				else
				{
					if(!t1.equals(reduced))
					{
						out="Fegla Won";
						lost=true;
					}
				}
			}
	//		System.out.println(reduced);
			
/*			for(int i=0; i<N; i++)
			{
				for(int j=0; j<reduced.length(); j++)
					System.out.print(f[i][j]+" ");
				System.out.println();
			}
	*/		
			if(!lost)
			{
				for(int i=0; i<reduced.length(); i++)
				{
					int min=100*100;
					
					for(int k=1; k<=100; k++)
					{
						int temp=0;
						for(int j=0; j<N; j++)
						{
							temp+= Math.abs(k-f[j][i]);
						}
						min= Math.min(temp,min);
					}
					
					moves+=min;
					
				}
				out=moves+"";
			}
			System.out.println("Case #"+t+": "+out);
		}
	}
}