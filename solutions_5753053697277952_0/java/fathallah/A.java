import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class A {
	static int n;
	static int arr[];
	
	static boolean check(){
		int sum=0;
		for(int i=0;i<n;i++)
			sum+=arr[i];
		for(int i=0;i<n;i++){
			if(arr[i]>sum/2 || arr[i]<0)
				return false;
		}
		return true;
	}
	static int sum(){
		int sum=0;
		for(int i=0;i<n;i++)
			sum+=arr[i];
		return sum;
	}
	static public void main(String[] args)throws Exception{
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter("output.txt");
		
		int t =Integer.parseInt(br.readLine());
		String[]in;
		for(int z=1;z<=t;z++){
			n = Integer.parseInt(br.readLine());
			arr = new int[n];
			in = br.readLine().split(" ");
			for(int i=0;i<n;i++)
				arr[i]=Integer.parseInt(in[i]);
			
			StringBuilder res = new StringBuilder();
			
			while(true){
				if(sum()==0)break;
				for(int i=1;i<(1<<n);i++){
					int cnt=0;
					for(int j=0;j<n;j++){
						if((i&(1<<j))!=0)
							cnt++;;
					}
					if(cnt>2)continue;
					for(int j=0;j<n;j++){
						if((i&(1<<j))!=0)
							arr[j]--;
					}
					if(check()){
						res.append(" ");
						for(int j=0;j<n;j++){
							if((i&(1<<j))!=0)
								res.append((char)(j+'A'));
						}
						continue;
					}
					for(int j=0;j<n;j++){
						if((i&(1<<j))!=0)
							arr[j]++;
					}
				}
			}
			out.println("Case #"+z+":"+res.toString());
		}
		br.close();
		out.close();
	}
}
