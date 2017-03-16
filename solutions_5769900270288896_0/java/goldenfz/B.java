package R1B_2015;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class B {
		static int min;
public static void main(String args[]) throws NumberFormatException,IOException {
		
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("B-small-attempt0.out");
		int t=in.readInt();
		int r,c,n;
		int a[];
		for(int i=1;i<=t;i++){
			r=in.readInt();
			c=in.readInt();
			n=in.readInt();
			a=new int[r*c];
			for(int j=0;j<n;j++)
				a[j]=1;
			min=solve(a,r,c);
			permutation(a,0,r,c);
			print(out,min,i);
		}
		out.flush();
		out.close();

	}
private static void permutation(int []a,int k,int r,int c){
	if(k==a.length-1){
		min=Math.min(solve(a,r,c),min);
		return;
	}else{
		for(int i=k;i<a.length;i++){
			if(isSwap(a,k,i)){ 
			swap(a,k,i); 
			permutation(a,k+1,r,c); 
			swap(a,k,i); 	
			}
		}
		
	}
	
}
private static int solve(int[]a,int r,int c){
	boolean board[][]=new boolean[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			board[i][j]=a[c*i+j]==1;
		}
	}
	int count=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i+1<r&&board[i][j]&&board[i+1][j])
				count++;
			if(j+1<c&&board[i][j]&&board[i][j+1])
				count++;
		}
	}
	return count;
	
}
private static void swap(int []a,int k,int j){
	int tem=a[k];
	a[k]=a[j];
	a[j]=tem;
}
private static boolean isSwap(int[]a,int k,int j){
	for(int i=k;i<j;i++)
		if(a[i]==a[j])
		return false;
	return true;
}
	private static void print(PrintWriter out,Object t,int cases){
		out.println("Case #"+cases+": "+t);
	}

	private static class Stdin {
		BufferedReader br;

		StringTokenizer st = new StringTokenizer("");

		private Stdin() throws FileNotFoundException {
			br = new BufferedReader(new FileReader("B-small-attempt0.in"));

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
