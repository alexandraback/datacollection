package R1B_2015;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class B {
	static int m;
public static void main(String args[]) throws NumberFormatException,IOException {
		
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("B-large.out");
		int t=in.readInt();
		int r,c,n,area,n1;		
		int min;
		boolean board[][];
		for(int i=1;i<=t;i++){
			r=in.readInt();
			c=in.readInt();
			n=in.readInt();
			area=r*c;
			if(n<=area/2+area%2){
				print(out,0,i);
				continue;
			}
			if(n==r*c){
				print(out,2*n-r-c,i);
				continue;
			}
			board=new boolean[r][c];
			n1=n;
			for(int j=0;j<c;j+=2){
				board[0][j]=true;
				n1--;
			}			
			min=solving(r,c,n1,board);
			board=new boolean[r][c];
			n1=n;
			for(int j=1;j<c;j+=2){
				board[0][j]=true;
				n1--;
			}	
			min=Math.min(solving(r,c,n1,board),min);
			print(out,min,i);
			
		}
		out.flush();
		out.close();

	}
private static int solving(int r,int c,int n,boolean board[][]){
	for(int j=1;j<r;j++){
		for(int k=0;k<c;k++){
			if(!board[j-1][k]&&(k==0||!board[j][k-1])){
				board[j][k]=true;
				n--;
			}
		}
	}	
	int count[]=new int[5];
	int walls=0;
	for(int j=0;j<r;j++){
		for(int k=0;k<c;k++){
			if(!board[j][k]){
				walls=0;
				if(j-1>=0&&board[j-1][k])
					walls++;
				if(k-1>=0&&board[j][k-1])
					walls++;
				if(k+1<c&&board[j][k+1])
					walls++;
				if(j+1<r&&board[j+1][k])
					walls++;
				count[walls]++;
			}
		}
	}
	int min=0;
	for(int j=0;j<count.length;j++){
		if(n>0&&count[j]>0){
			if(n<=count[j]){
				min+=n*j;
				break;
			}
			else{
				min+=count[j]*j;
				n-=count[j];
			}
		}
	}
	return min;
}

	private static void print(PrintWriter out,Object t,int cases){
		out.println("Case #"+cases+": "+t);
	}

	private static class Stdin {
		BufferedReader br;

		StringTokenizer st = new StringTokenizer("");

		private Stdin() throws FileNotFoundException {
			br = new BufferedReader(new FileReader("B-large.in"));

		}

		private String readNext() throws IOException {

			while (!st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		private int readInt() throws IOException, NumberFormatException {

			return Integer.parseInt(readNext());

		}

		private long readLong() throws IOException, NumberFormatException {

			return Long.parseLong(readNext());

		}
		private double readDouble() throws IOException, NumberFormatException {

			return Double.parseDouble(readNext());

		}
	}
}
