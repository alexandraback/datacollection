import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;


public class B {
	static int n,m,k;
	static boolean[][] v ,temp;
	static int calc(int mask){
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				temp[i][j]=false;
				int ind = i*m+j;
				if((mask&(1<<ind))!=0)
					v[i][j]=true;
				else
					v[i][j]=false;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(v[i][j]){
					temp[i][j]=true;
					if(i-1>=0 && v[i-1][j] &&!temp[i-1][j])
						cnt++;
					if(i+1<n && v[i+1][j] &&!temp[i+1][j])
						cnt++;
					if(j-1>=0 && v[i][j-1] && !temp[i][j-1])
						cnt++;
					if(j+1 <m && v[i][j+1] && !temp[i][j+1])
						cnt++;
				}
			}
		}
		return cnt;
	}
	
	static public void main(String[] args)throws Exception{
		BufferedReader br = new BufferedReader(new FileReader("input.in"));
		PrintWriter out = new PrintWriter("output.txt");
		int t = Integer.parseInt(br.readLine());
		for(int z=1;z<=t;z++){
			String[] in = br.readLine().split(" ");
			n = Integer.parseInt(in[0]);
			m = Integer.parseInt(in[1]);
			k =Integer.parseInt(in[2]);
			v = new boolean[n][m];
			temp = new boolean[n][m];
			int min=1000000;

			for(int i=0;i<(1<<(n*m));i++){
				int tmp=0;
				for(int j=0;j<(n*m);j++){
					if((i&(1<<j))!=0)
						tmp++;
				}
				if(tmp!=k)continue;
				int nw = calc(i);
				if(min>nw)
					min=nw;
			}
			
			
			out.println("Case #"+z+": "+min);
		}
		br.close();
		out.close();
	}
}
