import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.LinkedList;


public class B {
	static public void main(String[] args)throws Exception{
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("input.in"));
		PrintWriter out = new PrintWriter("output.txt");
		int t = Integer.parseInt(br.readLine());
		for(int z=1;z<=t;z++){
			String[] in = br.readLine().split(" ");
			int b = Integer.parseInt(in[0]);
			int n = Integer.parseInt(in[1]);
			in = br.readLine().split(" ");
			int sum = 0;
			int[] barbers = new int[b];
			int[] work = new int[b];
			LinkedList<Integer>[] mods = new LinkedList[b];
			double div = 0;
			int max=-1;
			for(int i=0;i<b;i++){
				barbers[i]=Integer.parseInt(in[i]);
				mods[i]=new LinkedList<Integer>();
				work[i]=barbers[i];
				if(barbers[i]>max)
					max=barbers[i];
			}
			for(int i=0;i<b;i++){
				div = Math.ceil((max*1.0)/(barbers[i]*1.0));
				sum+=div;
			}
			for(int i=0;i<b;i++)
				mods[i].add((i+1)%sum);

			int temp = b+1;
			while(temp<=sum){
				int min =1000000000;
				for(int i=0;i<b;i++){
					if(work[i]<min){
						min=work[i];
					}
				}
				for(int i=0;i<b;i++)
					work[i]-=min;
				for(int i=0;i<b;i++){
					if(work[i]==0){
						mods[i].add(temp%sum);
						work[i]=barbers[i];
						temp++;
						
					}
				}
			}
			int moo = n%sum,res=-1;
			for(int i=0;i<b;i++){
				for(int j=0;j<mods[i].size();j++){
					if(mods[i].get(j)==moo){
						res=i+1;
						break;
					}
				}
				if(res!=-1)break;
			}
			out.println("Case #"+z+": "+res);
		}
		br.close();
		out.close();
	}
}
