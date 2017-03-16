import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Comparator;
import java.util.HashSet;

public class Main {
	public static void main(String[] args) throws NumberFormatException,
	IOException {
		ContestScanner in = new ContestScanner("in.dat");
		ContestWriter out = new ContestWriter("out.dat");
		int t = in.nextInt();
		for(int test = 0; test < t; test++){
			int n = in.nextInt();
			int oldm = -1;
			int y = 0;
			int z = 0;
			int max = 0;
			int[] ma = new int[n];
			for(int i=0; i<n; i++){
				int m = in.nextInt();
				ma[i] = m;
//				z += Math.min(m, ((max+9)/10)*10);
				if(i > 0){
					if(oldm > m){
						y += oldm-m;
						if(oldm-m > max) max = oldm-m;
					}
					oldm = m;
				}else{
					oldm = m;
				}
			}
			int rate = max;
			for(int i=0; i<n-1; i++){
				z += Math.min(ma[i], rate);
			}
//			System.out.println(y);
			out.println("Case #"+(test+1)+": "+y+" "+z);
		}
		out.close();
	}
}

class Node{
	int id;
	HashSet<Node> edge = new HashSet<Node>();
	public Node(int id) {
		this.id = id;
	}
	public void createEdge(Node node) {
		edge.add(node);
	}
}

class MyComp implements Comparator<int[]> {
	final int idx;
	public MyComp(int idx){
		this.idx = idx;
	}
	public int compare(int[] a, int[] b) {
		return a[idx] - b[idx];
	}
}

class Reverse implements Comparator<Integer> {
	public int compare(Integer arg0, Integer arg1) {
		return arg1 - arg0;
	}
}


class ContestWriter {
	private PrintWriter out;

	public ContestWriter(String filename) throws IOException {
		out = new PrintWriter(new BufferedWriter(new FileWriter(filename)));
	}

	public ContestWriter() throws IOException {
		out = new PrintWriter(System.out);
	}

	public void println(String str) {
		out.println(str);
	}

	public void print(String str) {
		out.print(str);
	}

	public void close() {
		out.close();
	}
}

class ContestScanner {
	private BufferedReader reader;
	private String[] line;
	private int idx;

	public ContestScanner() throws FileNotFoundException {
		reader = new BufferedReader(new InputStreamReader(System.in));
	}

	public ContestScanner(String filename) throws FileNotFoundException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				filename)));
	}

	public String nextToken() throws IOException {
		if (line == null || line.length <= idx) {
			line = reader.readLine().trim().split(" ");
			idx = 0;
		}
		return line[idx++];
	}
	
	public String readLine() throws IOException{
		return reader.readLine();
	}

	public long nextLong() throws IOException, NumberFormatException {
		return Long.parseLong(nextToken());
	}

	public int nextInt() throws NumberFormatException, IOException {
		return (int) nextLong();
	}

	public double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}
}