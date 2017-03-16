import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class GCJA {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		new solve().sol();

	}

}

class solve {
	void sol() throws Exception{
		ModScanner ms=new ModScanner();
		PrintWriter out=new PrintWriter("D://gcj//a.out");
		int t=ms.nextInt();
		
		for(int tc=1;tc<=t;tc++){
			int parties=ms.nextInt();
			String ans="";
			int arr[]=new int[parties];
			int count=0;
			for(int i=0;i<parties;i++){
				arr[i]=ms.nextInt();
				count+=arr[i];
			}
			int max=-1;
			int maxp=-1;
			int max1=-1;
			int max2=-1;
			while(count!=0){
				max=-1;
				maxp=-1;
				for(int i=0;i<parties;i++){
					if(arr[i]>max){
						max=arr[i];
						maxp=i;
					}
				}
				arr[maxp]--;
				count--;
				char res=(char) ('A'+maxp);
				ans=ans+" "+res;
				for(int i=0;i<parties;i++){
					if(arr[i]>count/2){
						arr[i]--;
						count--;
						ans=ans+(char)('A'+i);
					}
				}
			}
			
			out.println("Case #"+tc+": "+ans);
			System.out.println("Case #"+tc+": "+ans);
		}
		out.flush();
		out.close();
	}
}

class ModScanner {
	BufferedReader br;
	StringTokenizer st;
 
	public ModScanner() throws Exception {
		//br = new BufferedReader(new InputStreamReader(System.in));
		br = new BufferedReader(new FileReader("D://gcj//a.in"));
	}
 
	String nextToken() throws Exception {
		while (st == null || !st.hasMoreElements()) {
				st = new StringTokenizer(br.readLine());
			
		}
		return st.nextToken();
	}
 
	int nextInt() throws Exception, Exception {
		return Integer.parseInt(nextToken());
	}
 
	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}
 
	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}
}  