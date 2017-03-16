package ninja.nabil.codejam.round1;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;


public class Mushroom {

	private String folderName="C:/Data/workspaces/workspaces2015/cj/codejam/files" ; 
	
	private String fileName="A-large" ;
	
	private String inputFileName=fileName+".in" ; 
	
	private String outputFileName=fileName+".out" ; 
	
	private BufferedReader reader ;
	
	private BufferedWriter writer ;
	
	private Integer nCases ;
	
	private Integer caseNumber ;
	
	private Integer n ;
	
	private int[] q ;
	
	public static void main(String[] args) {
		try {
			Mushroom sc=new Mushroom() ;
			sc.openInputFile() ;
			sc.readFirstLine() ;
			sc.openOutputFile() ;
			sc.processCases() ;
			sc.closeInputFile() ;
			sc.closeOutputFile() ;
		} catch (Exception exp) {
			exp.printStackTrace() ;
		}
	}
	
	
	void openInputFile() throws Exception {
		reader=new BufferedReader(new FileReader(new File(folderName,inputFileName))) ;
	}
	
	void closeInputFile() throws Exception {
		reader.close() ;
	}
	
	void openOutputFile() throws Exception {
		writer=new BufferedWriter(new FileWriter(new File(folderName,outputFileName))) ;
	}
	
	void closeOutputFile() throws Exception {
		writer.flush() ;
		writer.close() ;
	}
	
	void readFirstLine()throws Exception  {
		nCases=new Integer(reader.readLine()) ;
		System.out.println("nCases="+nCases);
	}
	
	void processCases()throws Exception  {
		for (int i=1 ; i<=nCases ; i++) {
			caseNumber=i ;
			processCurrentCase() ;
		}
	}
	
	void processCurrentCase() throws Exception {
		n=new Integer(reader.readLine()) ;
		q=new int[n] ;
		StringTokenizer st=new StringTokenizer(reader.readLine()," ",false) ;
		for (int i=0 ; i<n ; i++) {
			q[i]=new Integer(st.nextToken()) ;
		}
		int method1=method1() ;
		int method2=method2() ;
		String output="Case #"+caseNumber+": "+method1+" "+method2 ;
		writer.write(output+"\n") ;
	}

	private int method1() {
		int ans=0 ;
		for (int i=1 ; i<n ; i++) {
			int diff=q[i-1]-q[i] ;
			if (diff>0) ans+=diff ;
		}
		return ans;
	}

	private int method2() {
		int ans=0 ;
		int max=0 ;
		for (int i=1 ; i<q.length ; i++) {
			int diff=q[i-1]-q[i] ;
			if (diff>max) max=diff ;
		}
		for (int i=0 ; i<(q.length-1) ; i++) {
			if (q[i]>max) {
				ans+=max ;
			} else {
				ans+=q[i] ;
			}
		}
		return ans;
	}

}
