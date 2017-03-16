import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;



import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  


public class A {
	
	Scanner scan;
	public A(Scanner s) {
		this.scan = s;
	}
	class s{
		String c;
		ArrayList<Integer> a=new ArrayList<>();
		s(String x){
			a.add(1);
			c=x.charAt(0)+"";
			for(int i=1;i<x.length();i++){
				if(x.charAt(i)!=x.charAt(i-1)){
					c+=x.charAt(i);
					a.add(1);
				} else {
					a.set(a.size()-1, a.get(a.size()-1)+1);
				}
			}
		}
	}
	
	public String solve() {
		int n = intLine();
		int res = 0;
		s[] A = new s[n];
		for(int i=0;i<n;i++){
			String s = scan.nextLine();
			A[i]=new s(s);
			if(A[i].c.equals(A[0].c)==false)return "Fegla Won";
		}
		int m = A[0].c.length();
		for(int i=0;i<m;i++) {
			int rr =Integer.MAX_VALUE;
			for(int k=1;k<=100;k++){
				int r = 0;
				for(int j=0;j<n;j++){
					r += abs(k - A[j].a.get(i));
				}
				rr = min(rr, r);
			}
			res+=rr;
		}
		
		return ""+res;
	}
    
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = A.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt0.in";
		String largeName = cn+"-large.in";
		String name = smallName;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		PrintStream out = new PrintStream(new File(outName));
		//PrintStream out = System.out;
		Scanner scan = new Scanner(in);
		
		int N = parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			String res = new A(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
			System.err.println(c + " done");
		}
		
		System.err.println("All done");
		
	}

}


