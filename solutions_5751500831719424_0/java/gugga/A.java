package codejam2014;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class A {	
	private static final int ThreadCheckTime = 2000;
	private static final int TreadCount = 10;
	//private String inFileName = "H:\\Codejam\\src\\codejam2014\\inputA.in";
	private String inFileName = "H:\\Codejam\\src\\codejam2014\\A-small-attempt0.in";
	//private String inFileName = "H:\\Codejam\\src\\codejam2014\\A-large.in";
	private String outFileNeme = "H:\\Codejam\\src\\codejam2014\\output.txt";	
	public int testCaseCount=0;	
	public List<TestCase> cases;
	public class TestCase implements Runnable{		
		public String result;
		int N;
		String[] words;
		int[] loc;
		public TestCase(){
			N = getInt();
			words = new String[N];
			loc = new int[N];
			for (int i = 0; i < N; i++) {
				words[i]= getWord();
			}
		}		
		public void run(){
			Integer count = 0;
			while(true) {
				if(loc[0]>=words[0].length()){
					for (int j = 1; j < N; j++) {
						if(loc[j]!=words[j].length()){
							result = "Fegla Won";
							return;
						}
					}
					break;
				}
				int[] ct = new int[N];
				char c = words[0].charAt(loc[0]);
				for (int j = 0; j < N; j++) {
					ct[j] = getSeqLength(words[j], c, loc[j]);
					if(ct[j]==0){
						result = "Fegla Won";
						return;
					}
					loc[j]=loc[j]+ct[j];
				}
				int m = Integer.MAX_VALUE;
				for (int i = 0; i < ct.length; i++) {
					int curr = ct[i];
					int p = 0;
					for (int k = 0; k < ct.length; k++) {
						p+=Math.abs(curr-ct[k]);
					}
					m = Math.min(m, p);
				}
				count+=m;
			}
			result = count.toString();
		}
	}	
	int getSeqLength(String s, char c, int index){
		int ct = 0;
		for (int i = index; i < s.length(); i++) {
			if(s.charAt(i)==c){
				ct++;
			}else{
				break;
			}
		}
		return ct;
	}
	public void execute(){
		testCaseCount = getInt();
		cases = new ArrayList<TestCase>();
		for(int i =0; i<testCaseCount; i++){
			cases.add(getCase());
		}
		runParallel();
		for(int i =0; i<testCaseCount; i++){
			TestCase cs = cases.get(i);
			String op = "Case #" + (i+1) + ": " + cs.result;
			writeLine(op);
		}
	}	
	public void runSerial(){
		for(int i =0; i<testCaseCount; i++){
			TestCase cs = cases.get(i);
			cs.run();
		}
	}
	public void runParallel(){
		ExecutorService service = Executors.newFixedThreadPool(TreadCount);
		for(int i=0;i<testCaseCount;i++){service.execute(cases.get(i));}
		service.shutdown();
		while(true){if(service.isTerminated())break;
		try {Thread.sleep(ThreadCheckTime);} 
		catch (InterruptedException e) {e.printStackTrace();}
		}
	}
	public TestCase getCase(){
		return new TestCase();
	}	
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
	public A() {
		try {inSc = new Scanner(new File(inFileName));} 
		catch (FileNotFoundException e1) {e1.printStackTrace();}	
		try {outSc = new Formatter(outFileNeme);} catch (FileNotFoundException e) {e.printStackTrace();}
	}	
	public void complete(){inSc.close();outSc.flush();outSc.close();}
	public static void main(String[] args) {
		A st = new A();
		st.execute();
		st.complete();
	}
}
