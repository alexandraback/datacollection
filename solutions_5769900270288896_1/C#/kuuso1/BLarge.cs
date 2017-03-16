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
		
		var d=rla();
		R=d[0];C=d[1];N=d[2];
		if(R%2==0&&C%2==0){
			long C0=R*C/2;
			long C1=2;
			long C2=(R/2-1)*2+(C/2-1)*2;
			
			if(N<=C0){Console.WriteLine(0);return;}
			N-=C0;
			long sum=0;
			if(N<=C1){Console.WriteLine(2*N);return;}
			N-=C1;sum+=2*C1;
			if(N<=C2){sum+=3*N;Console.WriteLine(sum);return;}
			N-=C2;sum+=3*C2;
			sum+=4*N;
			Console.WriteLine(sum);return;
		}
		if(R%2==1&&C%2==0){
			long C0=R*C/2;
			long C1=2;
			long C2=(R/2+R/2-1)+(C/2-1)*2;

			if(N<=C0){Console.WriteLine(0);return;}
			N-=C0;
			long sum=0;
			if(N<=C1){Console.WriteLine(2*N);return;}
			N-=C1;sum+=2*C1;
			if(N<=C2){sum+=3*N;Console.WriteLine(sum);return;}
			N-=C2;sum+=3*C2;
			sum+=4*N;
			Console.WriteLine(sum);return;
		}
		if(R%2==0&&C%2==1){
			long C0=R*C/2;
			long C1=2;
			long C2=(R/2-1)*2+(C/2-1+C/2);

			if(N<=C0){Console.WriteLine(0);return;}
			N-=C0;
			long sum=0;
			if(N<=C1){Console.WriteLine(2*N);return;}
			N-=C1;sum+=2*C1;
			if(N<=C2){sum+=3*N;Console.WriteLine(sum);return;}
			N-=C2;sum+=3*C2;
			sum+=4*N;
			Console.WriteLine(sum);return;

		}
		
		if(R%2==1&&C%2==1){
			long sum=Math.Min(cal1(N),cal2(N));
			Console.WriteLine(sum);
		}
		
		
		
		
		
	}
	
	
	long cal1(long NN){
		long C0=(R*C)/2+1;
		long C1=0;
		long C2=(R/2)*2+(C/2)*2;
		
		if(NN<=C0){return 0;}
		NN-=C0;
		long sum=0;
		if(NN<=C1){return 2*NN;}
		NN-=C1;sum+=2*C1;
		if(NN<=C2){sum+=3*NN;return sum;}
		NN-=C2;sum+=3*C2;
		sum+=4*NN;
		return sum;
	}
	
	
	long cal2(long NN){
		long C0=(R*C)/2;
		long C1=4;
		long C2=(R-R/2-2)*2+(C-C/2-2)*2;
		
		if(NN<=C0){return 0;}
		NN-=C0;
		long sum=0;
		if(NN<=C1){return 2*NN;}
		NN-=C1;sum+=2*C1;
		if(NN<=C2){sum+=3*NN;return sum;}
		NN-=C2;sum+=3*C2;
		sum+=4*NN;
		return sum;
	}

	
	
	
	
	
	long N,R,C;
	

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