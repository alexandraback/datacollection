package google.jam2016.r1c;
//-------------------------------------------------------------------------------------------------------
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.UnsupportedEncodingException;
import java.io.Writer;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class A implements Runnable {
	private final static long START_TIME=System.currentTimeMillis();

	private final static boolean USE_FILES=false;
	private final static File FILE_DIR=new File("D:/");
	private final static File IN_FILE=new File(FILE_DIR,"in.txt");
	private final static File OUT_FILE=new File(FILE_DIR,"out.txt");


	private final static boolean LOG_ENABLED=true;
	private final static boolean ONLINE_JUDGE = (System.getProperty("ONLINE_JUDGE") != null);
	private final static String SYSTEM_ENCODING="utf-8";
	private final static int DEFAULT_BUFFER_SIZE=256*256;


	private static class Logger{
		private final PrintWriter logWriter=Util.newPrintWriter(System.err,true);
		private final DecimalFormat df=new DecimalFormat("0.000");
		private void message(String type, String message, Object ... params){
			if(ONLINE_JUDGE || !LOG_ENABLED){
				return;
			}
			logWriter.printf("["+type+"] "+df.format((System.currentTimeMillis()-START_TIME)/1000.0)+": "+message+"\r\n", params);
		}
		public void debug(String message, Object ... params){
			message("DEBUG", message, params);
		}
	}

	public final static class Util{
		public final static String LINE_SEPARATOR=System.getProperty("line.separator"); 
		public static PrintWriter newPrintWriter(OutputStream out, boolean autoFlush){
			try {
				return new PrintWriter(new OutputStreamWriter(new BufferedOutputStream(out), SYSTEM_ENCODING),autoFlush);
			} catch (UnsupportedEncodingException e) {
				throw new IllegalStateException(e);
			}
		}

		public static PrintWriter newPrintWriter(Writer writer, boolean autoFlush){
			return new PrintWriter(writer,autoFlush);
		}


		private static void flushStringBuilder(Writer writer, StringBuilder sb) throws IOException {
			if(sb.length()>DEFAULT_BUFFER_SIZE){
				writer.append(sb);
				sb.setLength(0);
			}
		}

		public static void printArray(Writer writer, Object ... elements) throws IOException{
			StringBuilder sb = new StringBuilder();
			boolean first=true;
			for(Object o:elements){
				if(first){
					first=false;
				}else{
					sb.append(" ");
				}
				sb.append(o);
				flushStringBuilder(writer, sb);
			}
			sb.append(LINE_SEPARATOR);
			writer.append(sb);
		}
		public static void printArray(Writer writer, int ... elements) throws IOException{
			StringBuilder sb = new StringBuilder();
			boolean first=true;
			for(Object o:elements){
				if(first){
					first=false;
				}else{
					sb.append(" ");
				}
				sb.append(o);
				flushStringBuilder(writer, sb);
			}
			sb.append(LINE_SEPARATOR);
			writer.append(sb);
		}

		public static long getElement(long[] array,int index, long outOfBoundsValue){
			if(index<0 || index>=array.length){
				return outOfBoundsValue;
			}
			return array[index];
		}
		public static char getElement(char[] array,int index, char outOfBoundsValue){
			if(index<0 || index>=array.length){
				return outOfBoundsValue;
			}
			return array[index];
		}

		public static int getElement(int[] array,int index, int outOfBoundsValue){
			if(index<0 || index>=array.length){
				return outOfBoundsValue;
			}
			return array[index];
		}

		public static double getElement(double[] array,int index, double outOfBoundsValue){
			if(index<0 || index>=array.length){
				return outOfBoundsValue;
			}
			return array[index];
		}

		public static <T> T firstNotNull(T value1, T value2){
			if(value1!=null){
				return value1;
			}
			if(value2!=null){
				return value2;
			}
			throw new NullPointerException("All values are nulls");
		}

		public static long max(long... values){
			long result=values[0];
			for(int i=1,n=values.length;i<n;i++){
				long currentValue = values[i];
				if(result<currentValue){
					result=currentValue;
				}
			}
			return result;
		}
		public static double max(double... values){
			double result=values[0];
			for(int i=1,n=values.length;i<n;i++){
				double currentValue = values[i];
				if(result<currentValue){
					result=currentValue;
				}
			}
			return result;
		}
		public static long min(long... values){
			long result=values[0];
			for(int i=1,n=values.length;i<n;i++){
				long currentValue = values[i];
				if(result>currentValue){
					result=currentValue;
				}
			}
			return result;
		}
		public static double min(double... values){
			double result=values[0];
			for(int i=1,n=values.length;i<n;i++){
				double currentValue = values[i];
				if(result>currentValue){
					result=currentValue;
				}
			}
			return result;
		}




	}

	public final static class FastScanner{
		private BufferedReader reader;
		private StringTokenizer currentTokenizer;
		public FastScanner(Reader reader) {
			if(reader instanceof BufferedReader){
				this.reader=(BufferedReader) reader;
			}else{
				this.reader=new BufferedReader(reader);
			}
		}

		public String next(){
			if(currentTokenizer==null || !currentTokenizer.hasMoreTokens()){
				try {
					String line=reader.readLine();
					log.debug("Input line has been read:'%s'", line);
					currentTokenizer=new  StringTokenizer(line);
				} catch (IOException e) {
					throw new IllegalStateException(e);
				}
			}

			return currentTokenizer.nextToken();
		}
		public int nextInt(){
			return Integer.parseInt(next());
		}
		public int[] nextInts(int n){
			int[] result=new int[n];
			for(int i=0;i<n;i++){
				result[i]=nextInt();
			}
			return result;
		}

		public long nextLong(){
			return Long.parseLong(next());
		}

		public long[] nextLongs(int n){
			long[] result=new long[n];
			for(int i=0;i<n;i++){
				result[i]=nextLong();
			}
			return result;
		}


		public double nextDouble(){
			return Double.parseDouble(next());
		}

		public double[] nextDoubles(int n){
			double[] result=new double[n];
			for(int i=0;i<n;i++){
				result[i]=nextDouble();
			}
			return result;
		}


	}
	public final static class MultidimensionalArrayHelper{
		private final int[] dimensions;
		private final int size;
		public MultidimensionalArrayHelper(int ...dimensions) {
			this.dimensions=dimensions;
			int s=1;
			for(int dimension:dimensions){
				s*=dimension;
			}
			this.size=s;
		}
		public int index(int ... indexes){
			int n=indexes.length;
			int index=0;
			for(int i=n-1;i>0;i--){
				index=(index+indexes[i])*dimensions[i-1];
			}
			index+=indexes[0];
			return index;
		}

		public int size() {
			return size;
		}
	}


	private final static Logger log=new Logger();
	private final BufferedReader reader;
	private final FastScanner in;
	private final PrintWriter out;


	public A(Reader reader, Writer writer){
		this.reader=new BufferedReader(reader,DEFAULT_BUFFER_SIZE);
		this.out=new PrintWriter(new BufferedWriter(writer, DEFAULT_BUFFER_SIZE),false);
		in=new FastScanner(this.reader);
	}

	public static void main(String[] args) throws IOException {
		if(USE_FILES){
			OUT_FILE.delete();
		}

		try(InputStream input=USE_FILES?new FileInputStream(IN_FILE):System.in;
				OutputStream outputStream=USE_FILES?new FileOutputStream(OUT_FILE):System.out;){
			new A(
					new InputStreamReader(input, SYSTEM_ENCODING),
					new OutputStreamWriter(outputStream, SYSTEM_ENCODING)).run();
		}
	}

	@Override
	public void run(){
		log.debug("Started");
		try{
			solve();
			out.flush();
		}finally{
			log.debug("Stopped");
		}
	}

	private void solve(){
		int n = in.nextInt();
		for(int i=0;i<n;i++){
			out.print("Case #"+(i+1)+": ");
			solveInternal();
			out.println();
		}
	}

	private void solveInternal() {
		int n=in.nextInt();
		int[] senators=new int[n];
		senators[0]=in.nextInt();
		senators[1]=in.nextInt();
		int maxI;
		int nextMaxI;

		if(senators[0]>=senators[1]){
			maxI=0;
			nextMaxI=1;
		}else{
			maxI=1;
			nextMaxI=0;
		}
		for(int i=2;i<n;i++){
			senators[i]=in.nextInt();
			if(senators[i]>=senators[maxI]){
				nextMaxI=maxI;
				maxI=i;
			}
		}
		for(int i=0;i<(senators[maxI]-senators[nextMaxI]);i++){
			printAsLetter(maxI);
			out.print(' ');
		}
		for(int i=0;i<n;i++){
			if(i==maxI || i == nextMaxI){
				continue;
			}
			for(int j=0;j<senators[i];j++){
				printAsLetter(i);
				out.print(' ');
			}
		}
		
		for(int i=0;i<senators[nextMaxI];i++){
			printAsLetter(maxI);
			printAsLetter(nextMaxI);
			if(i!=senators[nextMaxI]-1){
				out.print(' ');
			}
		}

		
	}
	void printAsLetter(int i){
		out.print((char)('A'+i));
	}

}
//-------------------------------