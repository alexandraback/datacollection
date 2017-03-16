package round1A_15;


import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.lang.reflect.Method;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

import javax.swing.DebugGraphics;

public class A {
	
	
	
	//public static String theFile="-small.in";
	public static String theFile="-small-attempt0.in";
	//public static String theFile="-large.in";
	
	//input reader
	static class InputData {
		//declare vars
		int N;
		int[] m;
		
		//parse input
		InputData(Scanner in) throws IOException {
			N = in.nextInt();
	    	m = new int[N];
	    	for(int i=0;i<N;++i) m[i] = in.nextInt();
		}

		String solve() {
			int m1=0;
			int max=0;
			int m2=0;
			int last = m[0];
			for(int i=1;i<N;++i) {
				if(m[i]<last) {
					int dec = last-m[i];
					m1+= dec;
					if(dec>max) max=dec;
				}
				last=m[i];
			}
			for(int i=0;i<N-1;++i) { m2+= Math.min(m[i], max);}
			return m1+" "+m2;
		}
	}
	static class Solver implements Callable<String> {

		InputData data;
		
		Solver(InputData data) {
			this.data = data;
		}

		@Override
		public String call() throws Exception {
			return data.solve();
		}
		
	}
	
	public void run() {
		try {
			//System.out.println(System.getProperty("user.dir"));
			//File f= new File(pbLetter+theFile);
			//System.out.println(f.getAbsolutePath()+","+f.exists());
			
			Scanner sc = new Scanner( new BufferedReader(new FileReader(pbLetter+theFile)));
			out = new TeePrintStream(System.out,Folder+"/"+pbLetter + "-output.txt");
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);
			
			int tests = sc.nextInt();
			@SuppressWarnings("unchecked")
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(sc)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				//System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.print(ts[test].get());
				out.println();
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Method m;
		try {
			m = currentClass.getMethod("run");
			m.invoke(currentClass.newInstance(),(Object[])null);
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	static String pbLetter;
	static PrintStream out;
	static String Folder;
	
	static Class<?> currentClass;
	static {
		currentClass = new Object() { }.getClass().getEnclosingClass();
		pbLetter=currentClass.getName();
		Folder = currentClass.getPackage().getName();
		int idx = pbLetter.lastIndexOf('.');
		if(idx != -1) pbLetter = pbLetter.substring(idx+1);
		pbLetter = pbLetter.toUpperCase();
	}
	static class TeePrintStream extends PrintStream {
		protected PrintStream parent;

		public TeePrintStream(PrintStream orig, OutputStream os, boolean flush)
				throws IOException {
			super(os, flush);
			parent = orig;
		}
		public TeePrintStream(PrintStream orig, String fn)
				throws IOException {
			this(orig, new FileOutputStream(fn), true);
		}

		public boolean checkError() {
			return parent.checkError() || super.checkError();
		}
		public void write(int x) {
			parent.write(x);
			super.write(x); 
		}

		/** override write(). This is the actual "tee" operation. */
		public void write(byte[] x, int o, int l) {
			parent.write(x, o, l); 
			super.write(x, o, l);
		}

		/** Close both streams. */
		public void close() {
			parent.close();
			super.close();
		}
		/** Flush both streams. */
		public void flush() {
			parent.flush();
			super.flush();
		}
	}
}