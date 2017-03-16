import java.io.*;
import java.util.Scanner;
class q2{
	static boolean a[][];
	static int r,c,n,max;
	public static void main(String[]args) throws UnsupportedEncodingException,FileNotFoundException{
		int t,i,j,res;
		FileInputStream fis = new FileInputStream("B-small-attempt0.in") ;
		PrintWriter writer = new PrintWriter("out2.txt", "UTF-8");
		Scanner sc = new Scanner(fis);
		t=sc.nextInt();
		for(i=1;i<=t;i++){
			r=sc.nextInt();
			c=sc.nextInt();
			n=sc.nextInt();
			max=r*c;
			a=new boolean[r][c];
				res=unhappiness(1,0,max);
				writer.println("Case #"+i+": "+res);
				/*for(int x=0;x<r;x++)
				for(int y=0;y<c;y++)
					System.out.print(a[x][y]+" ");
				System.out.println();*/
		}
		writer.close();
	}
	static int unhappiness(int pos,int occ,int rem){
		if(occ==n)
			return 0;
		if(rem<n-occ)
			return 4*max;
		
			int i=(pos-1)/c;
			int j=(pos-1)%c;
			int  u=0;
			if(j>0)
			if(a[i][j-1])
			u++;
			if(i>0)
			if(a[i-1][j])
			u++;
			a[i][j]=false;
			int p2=unhappiness(pos+1,occ,rem-1);
			a[i][j]=true;
			int p1=unhappiness(pos+1,occ+1,rem-1)+u;
			if(p1<p2)
				return p1;
			a[i][j]=false;
			return p2;
		
	}
	static int min(int a,int b){
	return a>b?b:a;
	}
}