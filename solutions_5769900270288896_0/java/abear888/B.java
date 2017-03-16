import java.io.*;
import java.util.*;

public class B {
	public static int power(int base, int exponent){
		int output=1;
		for (int i=1; i<=exponent; i++){
			output*=base;
		}
		return output;
	}
	
	public static void main (String[]args)throws IOException{
		BufferedReader x=new BufferedReader(new FileReader("Bsmall.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Bsmall.out")));
		int t=Integer.parseInt(x.readLine());
		for (int cases=1; cases<=t; cases++){
			StringTokenizer st=new StringTokenizer(x.readLine());
			int r=Integer.parseInt(st.nextToken());
			int c=Integer.parseInt(st.nextToken());
			int n=Integer.parseInt(st.nextToken());
			int min=100000;
			for (int i=0; i<=power(2, r*c)-1; i++){
				ArrayList<Integer> temp=new ArrayList<Integer>();
				for (int j=0; j<r*c; j++){
					if ((i&(1L<<j))!=0){
						temp.add(j);
					}
				}
				if (temp.size()!=n)continue;
				int cur=0;
				for (int a:temp){
					for (int b:temp){
						if (a!=b &&((Math.abs(a%c-b%c)==1 && Math.abs(a/c-b/c)==0) || (Math.abs(a/c-b/c)==1 && Math.abs(a%c-b%c)==0))){
							cur++;
						}
					}
				}
				if (cur<min)min=cur;
			}
			out.println("Case #"+cases+": "+min/2);
		}
		out.close();
		System.exit(0);
	}
}