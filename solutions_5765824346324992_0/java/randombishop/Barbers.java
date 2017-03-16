package ninja.nabil.codejam.round1;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class Barbers {

	private String folderName="C:/Data/workspaces/workspaces2015/cj/codejam/files" ; 
	
	private String fileName="B-small-attempt3" ;
	
	private String inputFileName=fileName+".in" ; 
	
	private String outputFileName=fileName+".out" ; 
	
	private BufferedReader reader ;
	
	private BufferedWriter writer ;
	
	private Integer nCases ;
	
	private Integer caseNumber ;
	
	private Integer barbers ;
	
	private Integer place ;
	
	private int[] times ;
	
	public static void main(String[] args) {
		try {
			Barbers sc=new Barbers() ;
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
		StringTokenizer st=new StringTokenizer(reader.readLine()," ",false) ;
		barbers=new Integer(st.nextToken()) ;
		place=new Integer(st.nextToken()) ;
		st=new StringTokenizer(reader.readLine()," ",false) ;
		times=new int[barbers] ;
		for (int i=0 ; i<barbers ; i++) {
			times[i]=new Integer(st.nextToken()) ;
		}
		int result=result() ;
		String output="Case #"+caseNumber+": "+result ;
		writer.write(output+"\n") ;
	}

	
	private int result() {
		int modulo=modulo() ;
		int voidRounds=(place-1)/modulo ;
		int eliminateClients=voidRounds*modulo ;
		int remaining=place-eliminateClients ;
		int affectation=-1 ;
		Map<Integer,Integer> loads=new TreeMap<Integer,Integer>() ;		
		for (int i=0 ; i<remaining ; i++) {
			affectation=pickBarber(loads) ;
		}
		return affectation ;
	}


	private int modulo() {
		int mult=1 ;
		for (int i=0 ; i<barbers ; i++) {
			mult=mult*times[i] ;
		}
		int ans=0 ;
		for (int i=0 ; i<barbers ; i++) {
			ans+=(mult/times[i]) ;
		}
		return ans;
	}


	private int pickBarber(Map<Integer, Integer> loads) {
		int ans=1 ;
		int lowestLoad=Integer.MAX_VALUE ;
		for (int i=1 ; i<=barbers ; i++) {
			Integer currentLoad=loads.get(i) ;
			if (currentLoad==null) {
				currentLoad=0 ;
				loads.put(i,currentLoad) ;
			}
			if (currentLoad<lowestLoad) {
				lowestLoad=currentLoad ;
				ans=i ;
			}
		}
		Integer newLoad=loads.get(ans)+times[ans-1] ;
		loads.put(ans,newLoad) ;
		return ans ;
	}

}
