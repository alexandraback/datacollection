import java.io.*;

public class A1_B {

	public static void main(String[] args) throws IOException {
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(in.readLine());
		for(int i=1;i<=tc;++i){
			String[] a=in.readLine().split(" ");
			String[] b=in.readLine().split(" ");
			int bno=Integer.parseInt(a[0]);
			int pos=Integer.parseInt(a[1]);
			int[] barbers=new int[bno];
			int lcm=1,temp,sum=0;
			for(int j=0;j<bno;++j){
				temp=Integer.parseInt(b[j]);
				barbers[j]=temp;
				lcm=lcm(lcm,temp);
			}
			for(int j:barbers){
				sum+=(lcm/j);
			}
			int[] ar=new int[bno];
			for(int j=0;j<bno;++j){
				ar[j]=barbers[j];
			}
			int res=0;
			pos%=sum;
			if(pos==0)
				pos=sum;
			if(pos<=bno)
				res=pos;
			else{
				for(int l=0;l<pos-bno-1;++l){
					int ase=min(ar);
					ar[ase]+=barbers[ase];
				}
				res=min(ar);
				++res;
			}
			System.out.println("Case #"+i+": "+res);
		}
		in.close();
	}

	public static int min(int[] ar){
		int re=0;
		int min=ar[0];
		re=0;
		for(int j=1;j<ar.length;++j){
			if(ar[j]<min){
				min=ar[j];
				re=j;
			}
		}
		return re;
	}
	
	public static int lcm(int x,int y){
		return y*x/gcd(x,y);
	}
	
	public static int gcd(int x,int y){
		if (y==0) return x;
		return gcd(y,x%y);
	}
}
