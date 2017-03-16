import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

class A {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File(A.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(A.class.getSimpleName() + ".out"));
		
		int q[][] = new int[100][100];
		char c[] = new char[100];		
		int p;
		
		int tt = in.nextInt();
		for(int t=1; t<=tt; ++t) {            
            			
			int n = in.nextInt();
			int a = 0;
			
			String foo = in.nextLine();
			String s[] = new String[n];
			
			for(int i=0; i<n; ++i) {
				s[i] = in.nextLine();
			}
			
			int l = s[0].length();
			q[0][0] = 1;
			c[0] = s[0].charAt(0);
			p = 0;
			for(int j=1; j<l; ++j) {
				char w = s[0].charAt(j);
				if(w==c[p]) {
					++q[0][p];
				} else {
					++p;
					q[0][p] = 1;
					c[p] = w;
				}
			}
			
			boolean flag = true;
			
			for(int i=1; i<n; ++i) {
				char cc = s[i].charAt(0);
				if(cc != c[0]) {
					flag = false;
					break;
				}
				int qq = 1;
				int e=0;
				l = s[i].length();
				for(int j=1; j<l; ++j) {
					char w = s[i].charAt(j);
					if(w==cc) {
						++qq;
					} else {
						q[i][e] = qq;
						++e;
						if(e>p || c[e]!=w) {
							flag = false;
							break;
						}						
						qq = 1;
						cc = w;
					}
				}
				if(!flag) {
					break;
				}
				q[i][e] = qq;									
				if(e != p) {
					flag = false;
					break;
				}								
			}
			
			for(int j=0; j<=p; ++j) {
				int mi = q[0][j];
				int ma = mi;
				for(int i=1; i<n; ++i) {
					if(ma<q[i][j]) {
						ma = q[i][j];
					}
					if(mi>q[i][j]) {
						mi = q[i][j];
					}
				}
				int vv = -1;
				for(int k=mi; k<=ma; ++k) {
					int v=0;
					for(int i=0; i<n; ++i) {
						if(q[i][j]>k) {
							v += q[i][j]-k;
						} else {
							v += -q[i][j]+k;
						}						
					}
					if (vv==-1 || vv>v) {
						vv = v;
					}
				}	
				a += vv;				
			}
			
			/*
			out.println("Case #"+t+": "+n);
			for(int i=0; i<n; ++i) {
				out.println(s[i]);	
			}
			out.println(flag);	
			for(int j=0; j<=p; ++j)
				out.print(c[j]+" ");	
			out.println("");
			if(flag) {
				for(int i=0; i<n; ++i) {
					for(int j=0; j<=p; ++j) {
						out.print(q[i][j]+" ");
					}
					out.println("");
				}
			}
			*/
			if(flag) {
				out.println("Case #"+t+": "+a);
			} else {
				out.println("Case #"+t+": Fegla Won");
			}			
        }
		
		out.close();
	}
}