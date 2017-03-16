package gcj;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class P1 {

	Scanner scio=new Scanner(System.in);
	int caseNum=0;
		
	void work() {
		int n=this.scio.nextInt();
		int[] a=new int[n];
		int m1=0; 
		int m2=0;
		int maxRate=0;
		for(int i=0;i<n;++i) {
			a[i]=this.scio.nextInt();
			if (i>0) {
				maxRate=Math.max(maxRate, a[i-1]-a[i]);
				m1+= Math.max(0, (a[i-1]-a[i]));
			}
		}
		for(int i=0;i<(n-1);++i) {
			m2+=Math.min(maxRate, a[i]);
		}
		
		System.out.println("case #"+this.caseNum+": " + m1 + " " + m2);
	}
	
	void run() {
		
		try {
			File file=new File("A-large.in");
			this.scio=new Scanner(file); 
		} catch (FileNotFoundException e) {}
		
		int t=scio.nextInt();
		for(int i=0;i<t;++i) {
			this.caseNum=i+1;
			work();
		}
	}
	
	public static void main(String[] args) {
		new P1().run();
	}

}
