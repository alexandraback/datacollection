import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class one {
	
	static final String name = "A-small-attempt0";
	
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File(name + ".in"));
		PrintWriter out = new PrintWriter(new File(name + ".out"));
		
		int tc = in.nextInt();
		for(int i = 1; i <= tc; i++){
			out.println("Case #" + i + ": " + solve(in));
		}
		
		in.close();
		out.close();
	}

	private static String solve(Scanner in) {
		int n = in.nextInt();
		party[] parties = new party[n];
		int tot = 0;
		for(int i = 0; i < n; i++){
			parties[i] = new party(in.nextInt(), (char)(i + 'A') + "");
			tot += parties[i].n;
		}
		
		String s = "";
		while(tot > 0){
			Arrays.sort(parties);
			s += parties[0].s;
			parties[0].n--;
			tot--;
			for(int i = 0; i < parties.length; i++){
				if(parties[i].n > tot / 2){
					s += parties[i].s;
					parties[i].n--;
					tot--;
				}
			}
			if(tot != 0) 
				s += " ";
		}
		return s;
	}
}

class party implements Comparable<party>{
	int n;
	String s;
	
	public party(int n, String s){
		this.n = n;
		this.s = s;
	}
	
	public int compareTo(party p){
		return p.n - n;
	}
	
	public String toString(){
		return n + " " + s;
	}
}