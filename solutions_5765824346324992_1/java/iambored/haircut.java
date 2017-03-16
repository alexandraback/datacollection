import java.io.*;
import java.util.*;
public class haircut{
	public static void main(String[] args) throws IOException{
		BufferedReader f= new BufferedReader(new FileReader("haircut.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("haircut.out")));
		int nmnmnm = Integer.parseInt(f.readLine());
		for(int nmnm=0; nmnm<nmnmnm; nmnm++){
			StringTokenizer st = new StringTokenizer(f.readLine());
			int b = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(f.readLine());
			int[] barbers = new int[b];
			for(int i=0; i<b; i++){
				barbers[i] = Integer.parseInt(st.nextToken());
			}
			if(n<=b){
				out.println("Case #" + (nmnm+1) + ": " + n);
			}
			else{
				long t=1;
				long people = 0;
				long lower=0;
				long upper=0;
				while(people<=n){
					people=0;
					for(int i=0; i<b; i++){
						people+=t/barbers[i]+1;
					}
					lower=t;
					t*=2;
				}
				lower = lower/2;
				t=t/2;
				//System.out.println(t);
				upper = t;
				//System.out.println(t);
				t = lower +(upper-lower)/2;
				//System.out.println(t);
				while(lower!=upper){
					people=0;
					for(int i=0; i<b; i++){
						people+=t/barbers[i]+1;
					}
					/*if(t==12){
						System.out.println(people);
					}*/
					if(people>=n){
						if(upper==t){
							break;
						}
						upper =t;
					}
					else{
						if(lower==t){
							break;
						}
						lower = t;
					}
					t=lower + (upper-lower)/2;
					//System.out.println(lower + " " + upper);
				}
				//System.out.println(lower + " " + upper);
				int plow = 0;
				for(int i=0; i<b; i++){
					plow+=lower/barbers[i]+1;
				}
				int count = n-plow;
				//System.out.println(count);
				int zzzzzz=0;
				for(int i=0; i<b; i++){
					//System.out.println(upper);
					if((upper%(barbers[i]))==0){
						//System.out.println(t);
						zzzzzz++;
						if(count==zzzzzz){
							out.println("Case #" + (nmnm+1) + ": " + (i+1));
							break;
						}
					}
				}
				
			}
		}
		out.close();
	}
}