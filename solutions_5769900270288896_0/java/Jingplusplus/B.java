import java.io.*;

public class B {

    public int R;
    public int C;
    public int N;
    public int answer;
    public int M;
    public int m;
    
    public B(In in, PrintWriter pw) {
	R = in.readInt();
	C = in.readInt();
	N = in.readInt();	
	if(R<C) {
	    m = R;
	    M = C;
	}
	else {
	    m = C;
	    M = R;
	}
	if(m==1) {
	    if(N<=(M+1)/2) {
		answer = 0;
	    }
	    else if(M%2==0){
		answer = (N-M/2)*2-1;
	    }
	    else {
		answer = (N-(M+1)/2)*2;
	    }
	}
	if(m==2) {
	    if(N<=M) {
		answer = 0;
	    }
	    else if (N-M<=2){
		answer = 2*(N-M);
	    }
	    else {
		answer = 3*(N-M) - 2;
	    }
	}
	if(m==3) {
	    if(N<=(3*M+1)/2) {
		answer = 0;
	    }
	    else if(M==3) {
		if(N==6) answer = 3;
		else if(N==7) answer = 6;
		else if(N==8) answer = 8;
		else if(N==9) answer = 12;
	    }
	    else if(M==4) {
		if(N<=8) answer = 2*(N-6);
		else if(N<=11) answer = 3*(N-6)-2;
		else answer = 17;
	    }
	    else if(M==5) {
		if(N<=14) answer = 3*(N-8);
		else answer = 22;
	    }
	}
	if(m==4) {
	    if(N<=8) {
		answer = 0;
	    }
	    else if(N<=10) answer = (N-8)*2;
	    else if(N<=14) answer = (N-8)*3-2;
	    else answer = 6*3 + (N-14)*4 - 2;
	}
	pw.println(answer);
	
    }
    public static void main(String[] args) throws IOException {
	In in = new In(args[0]);
	File file = new File(args[1]);
	PrintWriter pw = new PrintWriter(new FileOutputStream(file));
	B solution;
	int T = in.readInt();
	for(int t=1;t<=T;t++) {
	    pw.print("Case #" + t + ": ");
	    solution = new B(in,pw);
	}
	pw.close();
    }
}
