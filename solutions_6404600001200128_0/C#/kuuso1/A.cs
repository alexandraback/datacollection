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
		
		int N=ri();
		int[] A=ria();
		int ans0=0;
		for(int i=1;i<N;i++){
			if(A[i-1]>A[i])ans0+=A[i-1]-A[i];
		}
		
		int ans1=0;
		int maxrate=0;
		for(int i=1;i<N;i++){
			int rate=0;
			if(A[i-1]>A[i]){
				rate=A[i-1]-A[i];
			}
			maxrate=Math.Max(maxrate,rate);
		}
//Console.WriteLine("mxrt={0}",maxrate);
		for(int i=0;i<N-1;i++){
			if(A[i]-maxrate<A[i+1]){
				ans1+=Math.Min(A[i],maxrate);
			}else{
				ans1+=maxrate;
			}
//Console.WriteLine(ans1);
		}
		
		
		
		
		Console.WriteLine("{0} {1}",ans0,ans1);
		
	}

	public Sol(int T){
		Console.Write("Case #{0}: ",T);
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