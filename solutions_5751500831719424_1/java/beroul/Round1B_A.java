import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Locale;
import java.util.Scanner;


public class Round1B_A {


	String round="Round_1B";
	String exercice="A";

	// global var
	int N;
	String[] S;
	
	
	void log(Object s) {
		//System.out.println(s);
	}
	
	void info(String s) {
		System.out.println(s);
	}
	
	void error(String s) {
		System.out.println(s);
	}

		

	class Composite{
		String s;
		ArrayList<Integer> l;
		
		
		public Composite(String s, ArrayList<Integer> l) {
			this.s = s;
			this.l = l;
		}
		
				
	}
	
	Composite strip(String s){
		log("Stripping "+s+" "+s.length());
		int N=s.length();
		char c=s.charAt(0);
		String res="";
		int count=0;
		ArrayList<Integer> l=new ArrayList<Integer>();
		for (int i=0;i<N;i++){
			char d=s.charAt(i);
			if (d==c) {
				count++;
			} else {
				res=res+c;
				l.add(count);
				count=1;
				c=d;
			}
		}
		res=res+c;
		l.add(count);
		log(s+" "+res);
		log(l);
		return new Composite(res,l);
	}
	
	int findMinimum(Composite[] C,int pos){
		log("Finding minimum for pos:"+pos);
		int min=-1;
		int max=-1;
		
		for (int i=0;i<N;i++){
			if (min==-1)
				min=C[i].l.get(pos);
			else
				min=Math.min(min,C[i].l.get(pos));
			
			if (max==-1)
				max=C[i].l.get(pos);
			else
			max=Math.max(max,C[i].l.get(pos));
		}
		int res=-1;
		for (int d=min;d<=max;d++){
			int resd=0;
			for (int i=0;i<N;i++) {
				resd+=Math.abs(C[i].l.get(pos)-d);
			}
		//	log("resd:"+resd);
			if (res==-1)
				res=resd;
			else
			if (resd<res) {
				log("ok for resd:"+resd+" for post:"+pos);
				res=resd;
			}
		}
		log("returning:"+res);
		return res;
	}
	
	String solve(){
		Composite[] C=new Composite[N];
		for (int i=0;i<N;i++) {
			C[i]=strip(S[i]);
		}
		String s0=C[0].s;
		log("Stripped:"+C[0].s);
		for (int i=1;i<N;i++){
			String s=C[i].s;
				if (!s0.equals(s))
					return "Fegla Won";
		}
	
		int count=0;
		int M=C[0].l.size();
		for (int i=0;i<M;i++){
			int a=findMinimum(C,i);
			count+=a;
		}
		return ""+count;
	
	}
	

	void process() throws Exception {

	//	File inputFile=new File(round+"/test_"+exercice+".in");
	//	PrintWriter outputFile= new PrintWriter(round+"/test_"+exercice+".out","UTF-8");
	

	//		File inputFile=new File(round+"/"+exercice+"-small-attempt1.in");
	//		PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-small-attempt1.out","UTF-8");

		
		File inputFile=new File(round+"/"+exercice+"-large.in");
		PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large.out","UTF-8");


		Scanner scanner=new Scanner(inputFile);
		scanner.useLocale(Locale.US);
		int T = scanner.nextInt();
		System.out.println("Doing "+T+" cases");

		

		for (int t=1;t<=T;t++) {
	
			// do Something
			N=scanner.nextInt();
			S=new String[N];
		
			
			for (int i=0;i<N;i++){
				S[i]=scanner.next();
		}
			
			
			String ss=""+solve();
		
			System.out.println("Case #"+t+": "+ss);
			outputFile.println("Case #"+t+": "+ss);
			
		}
		scanner.close();
		outputFile.close();

	}



	public static void main(String[] args) throws Exception {
		Round1B_A J=new Round1B_A();
		J.process();
	}


}

