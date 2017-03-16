package Qualif14;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class A {
	// get Pb Letter for input/output file names.
	public static String pbLetter;
	static {
		pbLetter=new Object() { }.getClass().getEnclosingClass().getName();
		int idx = pbLetter.lastIndexOf('.');
		if(idx != -1) pbLetter = pbLetter.substring(idx+1);
		pbLetter = pbLetter.toUpperCase();
	}
	public static int[] winning = {0xF,0xF0,0xF00,0xF000,0x1111,0x2222,0x4444,0x8888,0x1248,0x8421};
	
	public static void main(String[] args) throws Throwable {
		//Scanner sc = new Scanner(new File("./"+pbLetter+"-small.in"));
		//System.out.println(System.getProperty("user.dir"));
		Scanner sc = new Scanner(new File("./"+pbLetter+"-small-attempt1.in"));
		
		//Scanner sc = new Scanner(new File("./"+pbLetter+"-large.in"));
		
		TeePrintStream out= new TeePrintStream(System.out, "./output-"+pbLetter+".txt");
		
		int testCount = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= testCount; i++) {
			out.format("Case #%d: ",i );
			solve(sc, out);
		}
		out.close();
	}

	static void solve(Scanner sc, PrintStream out) {
		int[] before = new int[4];
		int[] after = new int[4];
		int count = 0;
		int theOne = -1;
		int row = sc.nextInt();
		int i;
		for(i=0; i< row; ++i) sc.nextLine();
		for(int j=0;j<4;++j) before[j] = sc.nextInt();
		for(; i<= 4; ++i) sc.nextLine();
		
		row = sc.nextInt();
		for(i=0; i< row; ++i) sc.nextLine();
		for(int j=0;j<4;++j) {
			int cur = sc.nextInt();
			for(int k=0;k<4;++k) if( cur == before[k])  {count++; theOne = cur;}
		}
		for(; i<= 4; ++i) sc.nextLine();
	
	
		out.println( count==1 ? theOne: (count==0 ? "Volunteer cheated!" : "Bad magician!" ));
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