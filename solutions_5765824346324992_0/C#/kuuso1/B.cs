using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class TEST{
	static void Main(){
		int T=int.Parse(Console.ReadLine());
		for(int i=1;i<=T;i++){
			Sol mySol =new Sol(i);
			mySol.Solve();
		}
	}
}

class Sol{
	public void Solve(){
		
		var dd=ria();
		int B=dd[0];
		int N=dd[1];
		long[] A=rla();
		
		long lcm=A[0];
		for(int i=1;i<B;i++){
			lcm=lcm*A[i]/gcd(lcm,A[i]);
		}
//Console.WriteLine(lcm);		
		long tot=0;
		for(int i=0;i<B;i++)tot+=lcm/A[i];
		
		int[] Q=new int[B];
		int[] ord=new int[(int)tot];
		for(int i=0;i<tot;i++)ord[i]=-1;
		for(int i=0;i<tot;i++){
			int min=Q.Min();
			if(min>0){
				for(int j=0;j<B;j++)Q[j]-=min;
			}
			for(int j=0;j<B;j++){
				if(Q[j]==0){
					ord[i]=j;
					Q[j]+=(int)A[j];
					break;
				}
			}
		}
//Console.WriteLine(String.Join(" ",ord));
		Console.WriteLine(ord[(N-1)%tot]+1);


	}

	public Sol(int T){
		Console.Write("Case #{0}: ",T);
	}

	long gcd(long a,long b){
		return a==0?b:gcd(b%a,a);
	}


	static String rs(){return Console.ReadLine();}
	static int ri(){return int.Parse(Console.ReadLine());}
	static long rl(){return long.Parse(Console.ReadLine());}
	static double rd(){return double.Parse(Console.ReadLine());}
	static String[] rsa(){return Console.ReadLine().Split(' ');}
	static int[] ria(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>int.Parse(e));}
	static long[] rla(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>long.Parse(e));}
	static double[] rda(){return Array.ConvertAll(Console.ReadLine().Split(' '),e=>double.Parse(e));}

}

struct Pair{
	public char C;
	public int N;
	public Pair(char c,int n){
		this.N=n;
		this.C=c;
	}
}