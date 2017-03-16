import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
public class B {

    public int B;
    public long N;;
    public int[] M;
    public long Tmin;
    public double factor;
    public int[] n;
    public int[] m;
    public long Ns;
    public PriorityQueue<Node> pq;
    public ArrayList<Node> nodes;
    public int ans;
    
    public B(In in) {
	B = in.readInt();
	N = in.readLong();
	M = new int[B];
	n = new int[B];
	m = new int[B];
	factor = 0;
	for(int i=0;i<B;i++) {
	    M[i] = in.readInt();
	    factor += 1/((double)M[i]);
	}
	Tmin = (long)((N-B)/factor);
	Ns = 0;
	for(int i=0;i<B;i++) {
	    n[i] = (int)((Tmin-1)/M[i])+1;
	    m[i] = (int)((long)n[i]*M[i]-Tmin);
	    Ns += n[i];
	}
	if(Ns>=N) {
	    System.out.println("Ns>=N");
	}
	nodes = new ArrayList<Node>();
	pq = new PriorityQueue<Node>();
	Node newNode;
	for(int i=0;i<B;i++){
	    newNode = new Node(i,m[i]);
	    nodes.add(newNode);
	    pq.add(newNode);
	}
	System.out.println("Tmin=" + Tmin);
	System.out.println("Ns=" + Ns);
    }

    public void operate() {
	Node current = null;
	for(long n=Ns+1;n<=N;n++) {
	    current = pq.poll();
	    current.min = current.min + M[current.index];
	    pq.add(current);
	    System.out.println(n + ": " + current.index);
	}
	ans = current.index;
    }
    

    class Node implements Comparable<Node> {
	int index;
	int min;
	public Node(int index,int min) {
	    this.index = index;
	    this.min = min;
	}
	public int compareTo(Node n) {
	    if(this.min>n.min) {
		return 1;
	    }
	    else if(this.min==n.min) {
		if(this.index<n.index) {
		    return -1;
		}
		if(this.index>n.index) {
		    return 1;
		}
		else {
		    return 0;
		}
	    }
	    else {
		return -1;
	    }
	}
    }

    public static void main(String[] args) throws IOException {
	In in = new In(args[0]);
	File file = new File(args[1]);
	PrintWriter pw = new PrintWriter(new FileOutputStream(file));
	int T = in.readInt();
	B solution;
	for(int t=1;t<=T;t++) {
	    solution = new B(in);
	    solution.operate();
	    pw.println("Case #" + t + ": " + (solution.ans+1));
	}
	pw.close();
    }
    
}
