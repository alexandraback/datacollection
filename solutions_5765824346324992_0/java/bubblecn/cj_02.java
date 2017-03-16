import java.util.*;
public class cj_02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int t=0;

		while(t<n){
			t++;
			long result=0;
			int n1=sc.nextInt();
			long n2=sc.nextLong();
			int[] a=new int[n1];
			for(int i=0;i<n1;i++)
				a[i]=sc.nextInt();
			long nLcm=nlcm(a,a.length);
			int rNum=n1;
			HashMap<Integer,Integer> hs=new HashMap();
			for(int i=1;i<=n1;i++)
				hs.put(i, i);
			for(int i=1;i<nLcm;i++){
				for(int j=0;j<n1;j++)
					if(i%a[j]==0){
						rNum++;
						hs.put(rNum, j);
					}
			}
			int Number=(int) (n2%rNum);
			if (Number==0)
				Number=rNum;
			System.out.println("Case #"+t+": "+hs.get(Number));
		}
	}
	public static long gcd(long a,long b){
		if(a<b){
			long temp=a;
			a=b;
			b=temp;
		}
		if(b==0)
			return a;
		else return gcd(b,a%b);
	}
	public static long lcm(long a,long b){
		return a*b/gcd(a,b);
	}
	public static long nlcm(int[] a,int n){
		if(n==0)
			return a[0];
		return lcm(a[n-1],nlcm(a,n-1));
	}
	

}
