package codejam2014;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class QualA {	
	private String inFileName = "F:\\codejam\\A-small-attempt0.in";
	private String outFileNeme = "F:\\codejam\\output.txt";	
	public int testCaseCount=0;	
	public List<TestCase> cases;
	public class TestCase{		
		public String result;
		int f;
		int s;		
		int[] nos = new int[4];
		int[] nos2 = new int[4];
		public TestCase(){
			f = getInt();
			for (int i = 0; i < f; i++) nextLine();
			for (int i = 0; i < 4; i++) nos[i]=getInt();
			for (int i = 0; i < 5-f; i++) nextLine();
			s=getInt();
			for (int i = 0; i < s; i++) nextLine();
			for (int i = 0; i < 4; i++) nos2[i]=getInt();	
			for (int i = 0; i < 5-s; i++) nextLine();			
		}		
		public void solve(){
			int count = 0;
			int number = 0;
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(nos[i]==nos2[j]){
						number=nos[i];
						count++;break;
					}
				}
			}
			if(count==1){
				result = new Integer(number).toString();
			}else if(count>1){
				result = "Bad magician!";
			}else{
				result ="Volunteer cheated!";
			}
		}
	}	
	public void execute(){
		testCaseCount = getInt();
		cases = new ArrayList<TestCase>();
		for(int i =0; i<testCaseCount; i++){
			cases.add(getCase());
		};
		runSerial();
		for(int i =0; i<testCaseCount; i++){
			TestCase cs = cases.get(i);
			String op = "Case #" + (i+1) + ": " + cs.result;
			writeLine(op);
		}
	}	
	public void runSerial(){
		for(int i =0; i<testCaseCount; i++){
			TestCase cs = cases.get(i);
			cs.solve();
		}
	}
	public TestCase getCase(){
		return new TestCase();
	}	
	// generic code
	public void writeLine(String line){outSc.format(line+'\n');}
	public String nextLine(){return inSc.nextLine();}
	public String getWord(){return inSc.next();}	
	public Integer getInt(){return inSc.nextInt();}	
	public Double getDouble(){return inSc.nextDouble();}	
	public Long getLong(){return inSc.nextLong();}	
	public BigInteger getBigInt(){return  new BigInteger(getWord());}	
	public BigDecimal getBigDecimal(){return  new BigDecimal(getWord());}
	public void closeOutputFile(){outSc.flush();outSc.close();}	
	Scanner inSc;
	Formatter outSc;	
	public QualA() {
		try {inSc = new Scanner(new File(inFileName));} 
		catch (FileNotFoundException e1) {e1.printStackTrace();}	
		try {outSc = new Formatter(outFileNeme);} catch (FileNotFoundException e) {e.printStackTrace();}
	}	
	public void complete(){inSc.close();outSc.flush();outSc.close();}
	public static void main(String[] args) {
		QualA st = new QualA();
		st.execute();
		st.complete();
	}
}
