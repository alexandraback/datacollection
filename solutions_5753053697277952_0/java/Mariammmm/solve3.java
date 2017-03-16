import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public class solve3 {
	static  String input = "solve1.in";
	static  String output = "solve1.out";
	private static class party implements Comparable<party>{
		char name;
		int number;
		party(char name, int number){
			this.name = name;
			this.number = number;
		}
		
		public int compareTo(party p){
			if(p.number == this.number){
				return this.name - p.name;
			}
			
			return -this.number + p.number;
		}
		public String toString(){
			return ""+number;
		}
	}
	public static void main(String[] args) throws IOException{
//		BufferedReader in =new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		BufferedReader in =new BufferedReader(new FileReader(input));
		PrintWriter out = new PrintWriter(new FileWriter(output));
		
		int t = Integer.parseInt(in.readLine());
		
		for(int i=1; i<=t; i++){
			out.print("Case #"+i+": ");
			oneTest(in, out);
			out.println();
		}
		
		
		out.flush();
	}
	
	public static void oneTest(BufferedReader in, PrintWriter out) throws IOException{
		int n = Integer.parseInt(in.readLine());
		
		StringTokenizer tok = new StringTokenizer(in.readLine());
		TreeSet<party> set = new TreeSet<>();
		int sum = 0;
		for(int i=0; i<n; i++){
			char ch = 'A';
			ch+=i;
			int number = Integer.parseInt(tok.nextToken());
			sum+=number;
			set.add(new party(ch, number));
		}
		
		if(sum%2 != 0){
			party a = set.first();
			set.remove(a);			
			out.print(a.name);			
			a.number--;			
			if(a.number > 0){
				set.add(a);
			}
			out.print(" ");
		}
		while(set.size() > 0){
			party a = set.first();
			set.remove(a);			
			out.print(a.name);			
			a.number--;			
			if(a.number > 0){
				set.add(a);
			}
			if(set.isEmpty()) break;
			party b = set.first();			
			set.remove(b);
			out.print(b.name);
			b.number--;
			if(b.number>0){
				set.add(b);
			}
			out.print(" ");
		}
		
		
		
	}
	
	static int findMax(int []arr){
		int max = -1;
		int res = -1;
		for(int i=0; i<arr.length; i++){
			if(arr[i]==0) continue;
			if(arr[i] > max){
				max = arr[i];
				res = i;
			}
		}
		
		return res;
	}
}
