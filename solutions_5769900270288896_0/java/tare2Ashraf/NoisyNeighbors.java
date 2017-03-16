import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class NoisyNeighbors {
	
	static int r,c;
	
	public static int find(boolean[][] grid, int n, int i, int j){
				
		if(n==0)
			return 0;
		
		if(j==c){
			i++;
			j=0;
		
		}
		
		if(i==r){
			return Integer.MAX_VALUE/2;
		}
		
		int way1=Integer.MAX_VALUE/2;
		int way2=Integer.MAX_VALUE/2;
		
		way1=find(grid, n, i, j+1);
		
		int numAround=0;
		
		if(i-1>=0 && grid[i-1][j]){
			numAround++;
		}
		if(j-1>=0 && grid[i][j-1]){
			numAround++;
		}
		

		grid[i][j]=true;
		way2=numAround+find(grid, n-1, i, j+1);
		grid[i][j]=false;
		
		return Math.min(way1, way2);
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br =new BufferedReader(new FileReader("in.txt"));
		BufferedWriter bw=new BufferedWriter(new FileWriter("out.txt"));
		
		int t=Integer.parseInt(br.readLine());

		for(int tt=0;tt<t;tt++){
			String[] s=br.readLine().split(" ");
			
			r=Integer.parseInt(s[0]);
			c=Integer.parseInt(s[1]);
			int n=Integer.parseInt(s[2]);
			
			bw.append("Case #"+(tt+1)+": "+find(new boolean[r][c], n, 0, 0)+"\n");
			
		}
		bw.close();
	}
}

