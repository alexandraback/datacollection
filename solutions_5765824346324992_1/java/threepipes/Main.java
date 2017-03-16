import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
	public static void main(String[] args) throws NumberFormatException,
	IOException {
		ContestScanner in = new ContestScanner("in.dat");
		ContestWriter out = new ContestWriter("out.dat");
		int t = in.nextInt();
		for(int test = 0; test < t; test++){
			int b = in.nextInt();
			int n = in.nextInt();
			long[][] m = new long[b][2];
			long mmax = 0;
			for(int i=0; i<b; i++){
				m[i][0] = in.nextInt();
				m[i][1] = i+1;
				if(m[i][0] > mmax) mmax = m[i][0];
			}
			long right = (long)n*mmax;
			long left = 0;
			long mid = (left + right)/2;
//			int cutnum = 0;
			while(true){
				long can = 0;
				for(int i=0; i<b; i++){
					can += (mid+m[i][0]-1)/m[i][0];
				}
				if(can > n-1){
					right = mid;
				}else{
					if(can == n-1){
//						cutnum = n-1;
						break;
					}else if(left + 1 == right){
						can = 0;
						for(int i=0; i<b; i++){
							can += (right+m[i][0]-1)/m[i][0];
						}
						if(can < n) mid = right;
						else mid = left;
						break;
					}else{
						left = mid;
					}
				}
				mid = (left+right)/2;
			}
			int done = 0;
			for(int i=0; i<b; i++){
				done += (mid+m[i][0]-1)/m[i][0];
				m[i][0] = ((mid+m[i][0]-1)/m[i][0])*m[i][0];
			}
			int rest = n-done-1;
			Arrays.sort(m, new MyComp(0));
			
//			System.out.println(test);
			out.println("Case #"+(test+1)+": "+m[rest][1]);
		}
		out.close();
	}
}

class Barber implements Comparable<Barber>{
	int id;
	int min;
	int fin;
	public Barber(int id, int min){
		this.id = id;
		this.min = min;
		fin = 0;
	}
	
	@Override
	public int compareTo(Barber o) {
		int res = o.min-min;
		if(res == 0){
			res = o.id - id;
		}
		return res;
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

class MyComp implements Comparator<long[]> {
	final int idx;
	public MyComp(int idx){
		this.idx = idx;
	}
	public int compare(long[] a, long[] b) {
		if(a[idx]-b[idx] < 0){
			return -1;
		}else if(a[idx]-b[idx] > 0){
			return 1;
		}
		return 0;
	}
}

//class MyComp implements Comparator<int[]> {
//	final int idx;
//	public MyComp(int idx){
//		this.idx = idx;
//	}
//	public int compare(int[] a, int[] b) {
//		return a[idx] - b[idx];
//	}
//}

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