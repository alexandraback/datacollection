import java.io.BufferedReader;
import java.io.InputStreamReader;


public class B {

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int cas = 1; cas <=T; cas++) {
			String[] spl = in.readLine().split(" ");
			long B = Integer.parseInt(spl[0]);
			long N = Integer.parseInt(spl[1]);
			long[] barb = new long[(int)B];
			spl = in.readLine().split(" ");
			for (int i = 0; i < barb.length; i++) {
				barb[i] = Integer.parseInt(spl[i]);
			}
			long ans=-1;
			if(N<=B)
				ans= N;
			else
			{
				N-=B;
				long lo, hi, mi;
				lo=-1; hi=(long)(1e18);
				while(lo+1<hi)
				{
					mi=(lo+hi)/2;
					if(mi<0) lo=mi;
					else
					{
						long numServed = 0;
						for (int i = 0; i < B; i++) {
							numServed += mi/barb[i];
						}
						if(numServed >=N) hi=mi;
						else lo=mi;
					}
				}
				//System.out.println(hi);
				long attendedBef = 0;
				if(hi!=0)
				{
					for (int i = 0; i < B; i++) {
						attendedBef += (hi-1)/barb[i];
						//System.out.println(attendedBef);
					}
				}
				//System.out.println(hi+" "+attendedBef);
				int i=0;
				for (; i < B; i++) {
					if(hi%barb[i]==0)
					{
						attendedBef++;
						//System.out.println(attendedBef+" "+i);
						if(attendedBef==N)
							break;
					}
				}
				ans=i+1;
			}
			System.out.println("Case #"+cas+": "+(ans));
		}

	}

	

}
