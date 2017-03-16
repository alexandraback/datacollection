import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;

/**
 * @author Ivan Pryvalov (ivan.pryvalov@gmail.com)
 */
public class GCJ_2015_R1B_B implements Runnable {

	int R, C, N;
	
	private void solve() throws IOException {
		int T = scanner.nextInt(); //10^3
		for (int test = 0; test < T; test++) {
			if (inputFromFile){
				System.out.printf("Test %d out of %d ...\n", test+1, T);
			}
			
			R = scanner.nextInt();
			C = scanner.nextInt(); //RxC <= 16 small
			N = scanner.nextInt(); //N <= RxC
			
			if (inputFromFile){
				System.out.printf("R=%d, C=%d, N=%d\n", R,C,N);
			}
			
			int ans1 = solve1();
			int ans2 = sovle2();
			
			int res = Math.min(ans1, ans2);
			
			//output result
			String ans = String.format("Case #%d: %d",test+1, res);
			if (inputFromFile){
				System.out.printf("\tTest %d out of %d done\n", test+1, T);
				System.out.println(ans);
			}
			out.println(ans);
		}
	}
	
	private int sovle2() {
		if (R<C){
			int tmp = R; R=C; C=tmp;
		}
		
		int[][] A = new int[R][C];
		
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if (i>0)
					A[i][j]++;
				if (i<R-1)
					A[i][j]++;
				if (j>0)
					A[i][j]++;
				if (j<C-1)
					A[i][j]++;
			}
		}
		
		int steps = R*C-N;
		
		for(int it=0; it<steps; it++){
			int iB = -1;
			int jB = -1;
			int bestVal = 0; 
			for(int i=0; i<R; i++){
				for(int j=0; j<C; j++){
					if (A[i][j] > bestVal){
						bestVal = A[i][j];
						iB = i;
						jB = j;
					}
				}
			}
			if (bestVal==0){
				break;
			}
			A[iB][jB] = 0;
			if (iB>0)
				A[iB-1][jB]--;
			if (iB<R-1)
				A[iB+1][jB]--;
			if (jB>0)
				A[iB][jB-1]--;
			if (jB<C-1)
				A[iB][jB+1]--;
		}
		
		//sum
		int res = 0;
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if (A[i][j]==0)
					continue;
				if (i>0 && A[i-1][j]!=0)
					res++;
				if (j>0 && A[i][j-1]!=0)
					res++;
			}
		}
		return res;
	}

	private int solve1() {
		if (C<R){
			int tmp = R; R=C; C=tmp;
		}
		//now R<=C
		
		int[][] A = new int[R][C];
		
		int cntFree = 0;
		for(int i=0; i<R; i++){
			for(int j=i%2; j<C; j+=2){
				A[i][j]=1;
				cntFree++;
			}
		}
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if (A[i][j]==0){
					int cnt = 0;
					if (i>0) cnt++;
					if (i<R-1) cnt++;
					if (j>0) cnt++;
					if (j<C-1) cnt++;
					//CC[cnt]++;
					list.add(cnt);
				}
			}
		}
		Collections.sort(list);
		
		int res = 0;
		int Nleft = Math.max(N-cntFree, 0);
		for(int i=0; i<Nleft; i++){
			res += list.get(i);				
		}
		return res;
	}

	/////////////////////////////////////////////////
	final int BUF_SIZE = 1024 * 1024 * 8;//important to read long-string tokens properly
	final int INPUT_BUFFER_SIZE = 1024 * 1024 * 8 ;
	final int BUF_SIZE_INPUT = 1024;
	
	final int BUF_SIZE_OUT = 1024;
	
	boolean inputFromFile = true;
	String filenamePrefix = "B-small-attempt1";
//	String filenamePrefix = "B-small";
	String inSuffix = ".in";
	String outSuffix = ".out";
	
	//InputStream bis;
	//OutputStream bos;
	PrintStream out;
	ByteScanner scanner;
	ByteWriter writer;
	
//	@Override
	public void run() {
		try{
			InputStream bis = null;
			OutputStream bos = null;
			//PrintStream out = null;
			if (inputFromFile){
				File baseFile = new File(getClass().getResource("/").getFile());
				bis = new BufferedInputStream(
						new FileInputStream(new File(
								baseFile, filenamePrefix+inSuffix)),
								INPUT_BUFFER_SIZE);
				bos = new BufferedOutputStream(
						new FileOutputStream(
								new File(baseFile, filenamePrefix+outSuffix)));
				out = new PrintStream(bos);
			}else{
				bis = new BufferedInputStream(System.in, INPUT_BUFFER_SIZE);
				bos = new BufferedOutputStream(System.out);
				out = new PrintStream(bos);
			}
			scanner = new ByteScanner(bis, BUF_SIZE_INPUT, BUF_SIZE);
			writer = new ByteWriter(bos, BUF_SIZE_OUT);
			
			solve();
			out.flush();
		}catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	
	
	public interface Constants{
		final static byte ZERO = '0';//48 or 0x30
		final static byte NINE = '9';
		final static byte SPACEBAR = ' '; //32 or 0x20
		final static byte MINUS = '-'; //45 or 0x2d	
		
		final static char FLOAT_POINT = '.';
	}
	
	public static class EofException extends IOException{
	}
	
	public static class ByteWriter implements Constants {
		
		int bufSize = 1024;
		byte[] byteBuf = new byte[bufSize];
		OutputStream os;
		
		public ByteWriter(OutputStream os, int bufSize){
			this.os = os;
			this.bufSize = bufSize;
		}
		
		public void writeInt(int num) throws IOException{
	         int byteWriteOffset = byteBuf.length;
	         if (num==0){
	        	 byteBuf[--byteWriteOffset] = ZERO;
	         }else{
	        	 int numAbs = Math.abs(num);
	        	 while (numAbs>0){
	        		 byteBuf[--byteWriteOffset] = (byte)((numAbs % 10) + ZERO);
	        		 numAbs /= 10;
	        	 }
	        	 if (num<0)
	        		 byteBuf[--byteWriteOffset] = MINUS;
	         }
	         os.write(byteBuf, byteWriteOffset, byteBuf.length - byteWriteOffset);
		}
		
		/**
		 * Please ensure ar.length <= byteBuf.length!
		 * 
		 * @param ar
		 * @throws IOException
		 */
		public void writeByteAr(byte[] ar) throws IOException{
			for (int i = 0; i < ar.length; i++) {
				byteBuf[i] = ar[i];
			}
			os.write(byteBuf,0,ar.length);
		}
		
		public void writeSpaceBar() throws IOException{
			byteBuf[0] = SPACEBAR;
			os.write(byteBuf,0,1);
		}
		
	}
	
	public static class ByteScanner implements Constants{
		
		InputStream is;
		
		public ByteScanner(InputStream is, int bufSizeInput, int bufSize){
			this.is = is;
			this.bufSizeInput = bufSizeInput;
			this.bufSize = bufSize;
			
			byteBufInput = new byte[this.bufSizeInput];
			byteBuf = new byte[this.bufSize];
		}
		
		public ByteScanner(byte[] data){
			byteBufInput = data;
			bufSizeInput = data.length;
			bufSize = data.length;
			byteBuf = new byte[bufSize];
			byteRead = data.length;
			bytePos = 0;
		}
		
		private int bufSizeInput;
		private int bufSize;
		
		byte[] byteBufInput;
		byte by=-1;
		int byteRead=-1;
		int bytePos=-1;

		byte[] byteBuf;
		int totalBytes;
		
		boolean eofMet = false;
		
		private byte nextByte() throws IOException{
			
			if (bytePos<0 || bytePos>=byteRead){
				byteRead = is==null? -1: is.read(byteBufInput);
				bytePos=0;
				if (byteRead<0){
					byteBufInput[bytePos]=-1;//!!!
					if (eofMet)
						throw new EofException();
					eofMet = true;
				}
			}
			return byteBufInput[bytePos++];
		}
		
		/**
		 * Returns next meaningful character as a byte.<br>
		 * 
		 * @return
		 * @throws IOException
		 */
		public byte nextChar() throws IOException{
			while ((by=nextByte())<=0x20);
			return by;
		}
		
		/**
		 * Returns next meaningful character OR space as a byte.<br>
		 * 
		 * @return
		 * @throws IOException
		 */
		public byte nextCharOrSpacebar() throws IOException{
			while ((by=nextByte())<0x20);
			return by;
		}
		
	    /**
	     * Reads line.
	     * 
	     * @return
	     * @throws IOException
	     */
	    public String nextLine() throws IOException {
            readToken((byte)0x20);
            return new String(byteBuf,0,totalBytes);
	    }
	    
	    public byte[] nextLineAsArray() throws IOException {
            readToken((byte)0x20);
            byte[] out = new byte[totalBytes];
            System.arraycopy(byteBuf, 0, out, 0, totalBytes);
            return out;
	    }
	    
		
	    /**
	     * Reads token. Spacebar is separator char.
	     * 
	     * @return
	     * @throws IOException
	     */
	    public String nextToken() throws IOException {
            readToken((byte)0x21);
            return new String(byteBuf,0,totalBytes);
	    }
	    
	    /**
	     * Spacebar is included as separator char
	     * 
	     * @throws IOException
	     */
	    private void readToken() throws IOException {	    	
            readToken((byte)0x21);
	    }
	    
	    private void readToken(byte acceptFrom) throws IOException {
            totalBytes = 0;
            while ((by=nextByte())<acceptFrom);
            byteBuf[totalBytes++] = by;
            while ((by=nextByte())>=acceptFrom){
                byteBuf[totalBytes++] = by;
            }
	    }
		
        public int nextIntSafe(){
            try {
                return nextInt();
            } catch (IOException e) {
                throw new RuntimeException(e.getMessage(), e);
            }
        } 
        
	    public int nextInt() throws IOException{
			readToken();
			int num=0, i=0;
			boolean sign=false;
			if (byteBuf[i]==MINUS){
				sign = true;
				i++;
			}
			for (; i<totalBytes; i++){
				num*=10;
				num+=byteBuf[i]-ZERO;
			}
			return sign?-num:num;
		}
		
		public long nextLong() throws IOException{
			readToken();
			long num=0;
			int i=0;
			boolean sign=false;
			if (byteBuf[i]==MINUS){
				sign = true;
				i++;
			}
			for (; i<totalBytes; i++){
				num*=10;
				num+=byteBuf[i]-ZERO;
			}
			return sign?-num:num;
		}
		
		/*
		//TODO test Unix/Windows formats
		public void toNextLine() throws IOException{
			while ((ch=nextChar())!='\n');
		}
		*/
		
		public double nextDouble() throws IOException{
			readToken();
			char[] token = new char[totalBytes];
			for (int i = 0; i < totalBytes; i++) {
				token[i] = (char)byteBuf[i];
			}
			return Double.parseDouble(new String(token));
		}
		
		public int[] loadIntArray(int size) throws IOException{
			int[] a = new int[size];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextInt();
			}
			return a;
		}
		
		public long[] loadLongArray(int size) throws IOException{
			long[] a = new long[size];
			for (int i = 0; i < a.length; i++) {
				a[i] = nextLong();
			}
			return a;
		}
	    
	}
	
	public static abstract class Timing{
		private static int counter = 0;
		protected String name = "Timing"+(++counter);
		private boolean debug;
		
		public Timing(boolean debug) {
			super();
			this.debug = debug;
		}
		
		public abstract void run();
		public void start(){
			long time1 = System.currentTimeMillis();
			run();
			long time2 = System.currentTimeMillis();
			if (debug)
				System.out.println(name+" time = "+(time2-time1)/1000.0+" ms.");
		}
		
	}
	
	public static class Alg{
		public static interface BooleanChecker{
			public boolean check(long arg);
		}
		
		public static class BinarySearch{
					
			/**
			 * This check returns boolean value, result of function.
			 * It should be monotonic.
			 * 
			 * @return
			 */
			public BooleanChecker bc;
			
			
			/**
			 * Returns the following 2 elements: <pre> 0 0 [0] [1] 1 1 </pre> <br/>
			 * See a comment by "cerealguy" on 10.06.2013 (http://codeforces.ru/blog/entry/7919#comment-136245). <br/>
			 */
			public long[] search(long left, long right){
				while (right-left > 1){
					long mid = (left+right)/2;
					if (bc.check(mid)){
						right = mid;
					}else{
						left = mid;
					}
				}
				return new long[]{left,right};
			}
			
			/**
			 * Optional. Returns the following 2 elements: <pre> 1 1 [1] [0] 0 0</pre>. </br>
			 * 
			 * @see BinarySearch#search(long, long) 
			 */
			public long[] searchInverted(long left, long right){
				while (right-left > 1){
					long mid = (left+right)/2;
					if (!bc.check(mid)){
						right = mid;
					}else{
						left = mid;
					}
				}
				return new long[]{left,right};
			}
		}
	}
	
	public static class Modulo{
		long mod = (long)1e9+7;
		
		public Modulo(long mod) {
			super();
			this.mod = mod;
		}

		public long inv(long a) {
			long res =  pow(a, mod-2);
			return res;
		}

		public long pow(long a, long x) {
			if (x==0)
				return 1;
			long part = 1;
			if ((x&1)!=0)
				part = a;
			return (part * pow((a*a)%mod, x>>1)) % mod;
		}
		
		public long c(long n, long m){
			long res = 1;
			for(int i=1; i<=m; i++){
				res = (res * (n-m+i)) % mod;
				res = (res * inv(i)) % mod;
			}
			return res;
		}
		
	}
	
	
	/**
	 * Added 26.04.2013. 
	 * See KROK 2013, Round 1, Problem D.
	 */
	static class DisjointUnionSet implements Cloneable{
		
		int[] rank;
		int[] parent;
		
		protected DisjointUnionSet clone(){
			DisjointUnionSet cloned = new DisjointUnionSet(parent.length);
			for(int i=0; i<parent.length; i++){
				cloned.parent[i] = parent[i];
				cloned.rank[i] = rank[i];
			}
			return cloned;
		}

		public DisjointUnionSet(int n) {
			rank = new int[n];
			parent = new int[n];
			
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
		}
		
		@Override
		public String toString() {
			return "disj [parents=" + Arrays.toString(parent) + "]";
		}

		/**
		 * Problem specific or general?
		 * O(N * alpha)
		 * 
		 * @param set2
		 */
		public void union(DisjointUnionSet set2){
			for(int i=0; i<parent.length; i++){
				parent[find(i)] = parent[find(set2.find(i))];
			}
		}
		
		
		/**
		 * @param index1 range 0..n-1
		 * @param index2
		 */
		public void union(int index1, int index2){
			int p1 = find(index1);
			int p2 = find(index2);
			
			if (rank[p1] > rank[p2]){
				parent[p2] = p1;
			}else if (rank[p2] > rank[p1]){
				parent[p1] = p2;
			}else{
				parent[p2] = p1;
				rank[p1]++;
			}
		}

		/**
		 *  O(alpha(n)) 
		 * 
		 * @param index
		 * @return
		 */
		private int find(int index) {
			if (parent[index] != index)
				parent[index] =  find(parent[index]);
			return parent[index];
		}
		
		/**
		 * O(N alpha(N)) ==> see find()
		 * 
		 * @return
		 */
		public int getCountDisjointSets(){
			int[] used = new int[parent.length];
			for(int i=0; i<parent.length; i++){
				used[find(i)] = 1;
			}
			int res = 0;
			for(int i=0; i<parent.length; i++){
				res += used[i];
			}
			return res;
		}
	}

	private static Random rnd = new Random();
	public static class ArrayUtils{
		public static void shuffle(int[] a){
			for(int j=a.length-1; j>=1; j--){
				int i = rnd.nextInt(j+1);
				swap(a, i, j);
			}
		}
		
		public static void swap(int[] a, int i, int j){
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	
	public static void main(String[] args) {
		new GCJ_2015_R1B_B().run();
	}
	
}
