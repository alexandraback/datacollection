import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class exo2 
{
	public static int INT(String s)
	{
		return Integer.parseInt(s);
	}
	
	public static int pgcd(int a, int b)
	{
		if (b==0) {return a;}
		if (a<b) {return pgcd(b,a);}
		return pgcd(b,a%b);
	}
	
	public static int ppcm(int a, int b)
	{
		return (a*b)/(pgcd(a,b));
	}
	
	public static int ppcm(int[] tab)
	{
		return ppcm(tab,tab.length);
	}
	
	public static int ppcm(int[] tab, int k)
	{
		if (tab.length==1 || k==1)
		{
			return tab[0];
		}
		if (tab.length==2 || k==2)
		{
			return ppcm(tab[0],tab[1]);
		}
		else
		{
			return ppcm(tab[k-1],ppcm(tab,k-1));
		}
	}
	
	public static int algo(int N, int B, int[] tab)
	{
		int pris=0;
		int[] action=new int[B];
		int gcd=ppcm(tab);
		int periode=0;
		System.out.println("new");
		System.out.println(gcd);
		for (int k=0;k<B;k++)
		{
			System.out.println("val:"+tab[k]);
			periode+=(gcd/tab[k]);
		}
		N=N%periode;
		if (N==0)
		{
			N=N+periode;
		}
		while(pris<N)
		{
			for (int k=0; k<B;k++)
			{
				if (action[k]==0)
				{
					action[k]++;
					action[k]=(action[k])%tab[k];
					pris++;
					if (pris==N)
					{
						return (k+1);
					}
				}
				else
				{
					action[k]++;
					action[k]=(action[k])%tab[k];
				}
			}
		}
		System.out.println("buuug"+N);
		return 0;
	}
	

	public static void main(String[] args) 
	{
		try{
			//File f = new File ("output_exo2_large");
			File f=new File("output_exo2_small");
			//File f=new File("output_exo2_test");
			
			FileWriter fw = new FileWriter (f);
			
			
			Scanner scan = new Scanner(System.in);
			try
			{
				//scan = new Scanner(new FileReader("B-large.in"));
				scan = new Scanner(new FileReader("B-small-attempt1.in"));
				//scan = new Scanner(new FileReader("B-test.in"));
			}
			catch(FileNotFoundException e)
			{
				e.printStackTrace();
				scan.close();
				return;
			}
			int T=scan.nextInt();
			int N,B;
			
			for (int test=1; test<=T; test++)
			{
				B=scan.nextInt();
				N=scan.nextInt();
				int[] tab=new int[B];
				for (int k=0; k<B; k++)
				{
					tab[k]=scan.nextInt();
				}
				int rep=algo(N, B, tab);
				fw.write("Case #"+test+": "+rep+"\n");
				
				
			}
			
			
			fw.close();
			System.out.println("FINI!! exo2");
			
			}catch(Exception e)
			{
				e.printStackTrace();
				System.out.println("erreur écriture solution");
			}

	}

}

