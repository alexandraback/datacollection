package gcj;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class P2 {

	Scanner scio=new Scanner(System.in);
	int caseNum=0;
	
	long count(long k, int n, int[] a) {
		if (k<=0) return 0;
		long out=0;
		for(int i=0;i<n;++i) {
			out+=k/a[i];
			if (k%a[i]!=0) ++out;
		}
		return out;
	}
	
	void work() {
		int n=this.scio.nextInt();
		long myPos=this.scio.nextLong();
		long target=myPos;
		int[] a=new int[n];
		long max=0;
		for(int i=0;i<n;++i) {
			a[i]=this.scio.nextInt();
			max=Math.max(max, a[i]);
		}
		long q=0; long h=(myPos*max);
		while(q<=h) {
			long m=(h-q)/2+q;
			long c=count(m, n, a);
			//System.out.println(q+" "+h+" "+m+" count:"+c);
			if (c>=target && count(m-1,n,a)<target) {
				//System.out.println("break!");
				q=m; h=m; break;
			}
			if (c>=target) {
				h=m-1; continue;
			} else {
				q=m+1; continue;
			}
		}
		
		//q=q+1;
		//System.out.println("endas:"+q+" "+h+" count:"+count(q,n,a)+" vs "+count(q-1,n,a)+"target:"+target);
		
		long p=myPos-count(q-1,n,a);
/*		
		long maxPos=0;
		for(int i=0;i<n;++i) {
			maxPos=Math.max(maxPos, a[i]*((q)/a[i]));
		}
*/
//		System.out.println("pos"+p+" maxPos"+maxPos);
		
		int out=0;
		for(int i=0;i<n;++i) {
			if ((q-1)%a[i]==0) {
				--p;
				if (p==0) {
					out=i+1;
					break;
				}
			}
		}
		
		System.out.println("case #"+this.caseNum+": "+out);
	}
	
	void run() {
		
		try {
			File file=new File("B-small-attempt2.in");//
//			File file=new File("input.txt");

			this.scio=new Scanner(file); 
		} catch (FileNotFoundException e) {}
		
		int t=scio.nextInt();
		for(int i=0;i<t;++i) {
			this.caseNum=i+1;
			work();
		}
	}
	
	public static void main(String[] args) {
		new P2().run();
	}

}
