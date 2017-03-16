import java.io.*;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.StringTokenizer;

//remember to change task name; change public class name!
public class prA {

	static void solve() throws Exception{
		int t=nextInt();
		for(int k=1;k<t+1;k++)
		{
			int r1=nextInt();
			for(int j=1;j<r1;j++)nextLine();
			HashSet<Integer>hs=new HashSet<Integer>();
			for(int j=0;j<4;j++)hs.add(nextInt());
			//System.err.println(hs.toString());
			for(int j=0;j<4-r1;j++)nextLine();
			int r2=nextInt();
			for(int j=1;j<r2;j++)nextLine();
			int union=0;
			int same=0;
			for(int j=0;j<4;j++){
				int a=nextInt();
				if(hs.contains(a)){
					union++;
					same=a;
				}

			}
			for(int j=0;j<4-r2;j++)nextLine();
			switch(union){
				case 0:out.println("Case #"+k+": Volunteer cheated!");break;
				case 1:out.println("Case #"+k+": "+same);break;
				default:out.println("Case #"+k+": Bad magician!");break;

			}
		}
	}
	public static void main(String[] args) throws Exception {
		String filename="A-small-attempt0";// change name here!
		in = new BufferedReader(new FileReader(filename+".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(filename+".out")));

		//	setTime();
		solve();
		in.close();
		//printTime();
		//	printMemory();
		out.close();
		System.exit(0);
	}
	static double time;
	static void setTime(){
		time=System.currentTimeMillis();
	}
	static void printTime(){
		System.err.println("Time consumed (sec): "+(System.currentTimeMillis()-time)/1024);
	}
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok = new StringTokenizer("");
	//	static long systemTime;
	static void printMemory() {
		System.err.println("Memory consumed: "
				+ (Runtime.getRuntime().totalMemory() - Runtime.getRuntime()
				.freeMemory()) / 1000 + " kb");
	}
	static void println(Object o){
		out.println(o);
		//	System.err.println(o);
	}
	static void print(Object o){
		out.print(o);
		//	System.err.print(o);
	}

	static String nextLine() throws Exception{
		return in.readLine();
	}
	static String next() {//if !hasNext returns null
		while (!tok.hasMoreTokens()) {
			String w = null;
			try {
				w = in.readLine();
			} catch (Exception e) {
				e.printStackTrace();
			}
			if (w == null)
				return null;
			tok = new StringTokenizer(w);
		}
		return tok.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static long nextLong() {
		return Long.parseLong(next());
	}

	static double nextDouble() {
		return Double.parseDouble(next());
	}

	static BigInteger nextBigInteger() {
		return new BigInteger(next());
	}
}