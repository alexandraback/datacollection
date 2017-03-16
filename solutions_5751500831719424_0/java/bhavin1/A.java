import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.Scanner;

public class A {

	Scanner in;
	// BufferedReader in;
	BufferedWriter out;

	public A() throws IOException {
		in = new Scanner(new File("prob.in"));
		// in = new BufferedReader(new FileReader("prob.in"));

		out = new BufferedWriter(new FileWriter("prob.out"));
	}

	public void solve() throws Exception {

		int numCases = in.nextInt();

		for (int i = 1; i <= numCases; i++) {
			runCase(i);
		}
		out.close();
		in.close();
	}

	private void runCase(int caseNum) throws Exception {

		int N = in.nextInt();

		String[] s = new String[N];
		//Iterator[] iter = new Iterator[N];
		for (int i = 0; i < N; i++) {
			s[i]=in.next();
			//iter[i]=new As[i].toCharArray()
		}
		int[] index=new int[N];
		int[] count= new int[N];
		ArrayList<Character> string = new ArrayList<Character>();
		ArrayList<Integer> counts = new ArrayList<Integer>();
		//Collections.fill(counts, new Integer(0));
		char c='0';
		int moves=0;
		boolean end=false;
		while(true) {
			String str="";
			
			for(int i=0; i<N; i++) {
				
				str = s[i];
				if(str.equals("")) break;
				if(c=='0') {
					c = str.charAt(0);
				}
				else if(c!=str.charAt(0)) {
					output(out, caseNum, "Fegla Won");
					return ;
				}
				//string.add(str.charAt(0));
				count[i]=1;
				boolean eos=true;
				int j;
				for(j=1; j<s[i].length(); j++) {
					if(str.charAt(j)==c) {
						count[i]++;
					} else {
						eos=false;
						break;
					}
				}
				s[i]=str.substring(j);
				if(eos) s[i]="";
				if(eos) end=true;
			}
			moves+=calculateMoves(count);
			c='0';
			if(end) break;

		}
		
		for(int i=0; i<N; i++) {
			if(!s[i].equals("")) {
				output(out, caseNum, "Fegla Won");
				return;
			}
		}
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//
//			}
//		}

		output(out, caseNum, moves);

	}


	private int calculateMoves(int[] count) {
		int base=0;
		int result=Integer.MAX_VALUE;
		
		for(int i=0; i<count.length; i++) {
			base=count[i];
			int currcnt=0;
			
			for(int j=0; j<count.length; j++) {
				currcnt+=Math.abs(count[j]-base);
			}
			
			if(currcnt<result) result=currcnt;
		}
		return result;
	}

	public static void main(String[] args) throws Exception {
		A s = new A();
		s.solve();

	}

	public void output(BufferedWriter out, int caseNum, int string)
			throws IOException {
		out.write("Case #" + caseNum + ": " + string + "\n");
	}

	public void output(BufferedWriter out, int caseNum, double string)
			throws IOException {
		out.write("Case #" + caseNum + ": " + string + "\n");
	}

	public void output(BufferedWriter out, int caseNum, String string)
			throws IOException {
		out.write("Case #" + caseNum + ": " + string + "\n");
	}

}
