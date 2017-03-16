import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileNameExtensionFilter;



public class Q1B {

	int cn;
	Child[] ch;

	public static void main(String[] args) throws ExecutionException, Throwable{
		JFileChooser jfc = new JFileChooser("./iofile");
		jfc.setFileFilter(new FileNameExtensionFilter(null, "in"));
		while(jfc.showOpenDialog(null) != JFileChooser.APPROVE_OPTION);
		File fi = jfc.getSelectedFile();
		String fo = fi.getPath();
		fo = fo.substring(0, fo.length() - 2) + "out";
		PrintStream ps = new PrintStream(fo);
		
		Q1B q = new Q1B();
		q.ReadInput(fi);
		
		boolean large = fi.getName().contains("large");
		q.PrintOutput(ps, large);
		ps.close();
	}
	
	void ReadInput(File fi) throws IOException{
		Scanner in = new Scanner(fi);
		Scanner line = new Scanner(in.nextLine());
		cn = line.nextInt();
		line.close();
		ch = new Child[cn];
		for(int c = 0; c < cn; c++){
			ch[c] = new Child(in);
		}
		in.close();
	}
	
	
	void PrintOutput(PrintStream ps, boolean large) throws IOException, Throwable, ExecutionException{
		if(large){
			ExecutorService exec = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
			Future[] fc = new Future[cn];
			for(int c = 0; c < cn; c++){
				fc[c] = exec.submit(ch[c]);
			}
			exec.shutdown();
			for(int c = 0; c < cn; c++){
				while(!fc[c].isDone())
					Thread.sleep(10000);
				ps.format("Case #%d: %s\n", c + 1, ch[c].result);
			}
		}
		else{
			for(int c = 0; c < cn; c++){
				ch[c].run();
				ps.format("Case #%d: %s\n", c + 1, ch[c].result);
			}
		}
	}
	
	static class Child implements Runnable{
		String result = "ERROR";
		int barber;
		long pos;
		int[] period;
		
		Child(Scanner in){
			barber = in.nextInt();
			pos = in.nextLong();
			period = new int[barber];
			for(int i = 0; i < barber; ++i)
				period[i] = in.nextInt();
		}
		
		int Calc(long time){
			long sum = 0;
			ArrayList<Integer> exact = new ArrayList<>();
			for(int i = 0; i < barber; ++i){
				if(time % period[i] == 0)
					exact.add(i+1);
				sum += (time - 1) / period[i] + 1;
			}
			if(sum >= pos)
				return -1;
			if(sum + exact.size() < pos)
				return 0;
			return exact.get((int) (pos - sum - 1));
		}
		
		@Override
		public void run() {
			int m = 0;
			for(int i: period)
				if(m < i)
					m = i;
			long b = 0, e = pos * m;
			while(b < e){
				long x = (b + e) / 2;
				int r = Calc(x);
				if(r > 0){
					result = Integer.toString(r);
					return;
				}else if(r == 0){
					b = x + 1;
				}else{
					e = x - 1;
				}
			}
			int r = Calc(b);
			if(r > 0)
				result = Integer.toString(r);
		}
		
	}
}