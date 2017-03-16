import java.io.*;

public class A {

    int N;
    int[] m;
    int[] diff;
    long total1;
    long total2;
    
    public A(In in) {
	N = in.readInt();
	m = new int[N];
	diff = new int[N-1];
	for(int i=0;i<N;i++) {
	    m[i] = in.readInt();
	}
	total1 = 0;
	int max = 0;
	for(int i=0;i<N-1;i++) {
	    diff[i] = m[i+1] - m[i];
	    if(-diff[i]>max) {
		max = -diff[i];
	    }
	    if(diff[i]<0) {
		total1 += -diff[i];
	    }
	}
	total2 = 0;
	for(int i=0;i<N-1;i++) {
	    if(m[i]>=max) {
		total2 += max;
	    }
	    else {
		total2 += m[i];
	    }
	}
	
    }

    public static void main(String[] args) throws IOException {
	In in = new In(args[0]);
	File file = new File(args[1]);
	PrintWriter pw = new PrintWriter(new FileOutputStream(file));
	int T = in.readInt();
	A solution;
	for(int t=1;t<=T;t++) {
	    solution = new A(in);
	    pw.println("Case #" + t + ": " + solution.total1 + " " + solution.total2);
	}
	pw.close();
    }
}
