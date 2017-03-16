import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;



public class TaskB {
	
	int B,N,result;
	Barber[] barbers;
	
	class Barber implements Comparable{
		int n;
		long time;
		long period;
		public String toString(){
			return "["+n+","+time+","+period+"]";
		}
		public Barber(int n, long time){
			this.n=n;
			this.time=0;
			this.period=time;
		}
		@Override
		public int compareTo(Object arg0) {
			long r=this.time-((Barber)arg0).time;
			return r<0?-1:r>0?1:this.n-((Barber)arg0).n;
		}
	}
	
	public void parseCase(Scanner input) {
		B=input.nextInt();
		N=input.nextInt();
		barbers=new Barber[B];
		for (int i=0;i<B;i++)
		{
			barbers[i]=new Barber(i+1,input.nextInt());
			
		}
	}
	
	
	public void solveCase() {
		int mult=1;
		int sum=0;
		long min=barbers[0].period;
		int minpos=1;
		for(int i=0;i<B;i++){
			mult*=barbers[i].period;
			if(barbers[i].period<=min)
			{
				min=barbers[i].period;
				minpos=i;
			}
		}
		for(int i=0;i<B;i++)
			sum+=mult/barbers[i].period;
		result=minpos+1;
		N=N%sum;
		while(N>0){
			Barber barb=barbers[0];
			result=barb.n;
			barb.time+=barb.period;
			int pos=0;
			while(pos<B-1&&barb.compareTo(barbers[pos+1])>0){
				barbers[pos]=barbers[pos+1];
				pos++;
			}
			barbers[pos]=barb;
			N--;
		}
	}

	public String getSolution() {
		return ""+result;
	}
	

	public void runTask(String[] args) {
		if(args.length<1)
		{
			System.out.println("Not enough parameters");
			return;
		}
		try{
			Scanner in=new Scanner(new File(args[0]));
			in.useLocale(Locale.ENGLISH);
			PrintWriter out=new PrintWriter(new File(args[1]));
			runCases(in,out);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public void runCases(Scanner in, PrintWriter out){
		int numOfCases=in.nextInt();
		in.nextLine();
		for(int i=1;i<=numOfCases;i++){
			parseCase(in);
			solveCase();
			out.println("Case #"+i+": "+getSolution());
			out.flush();
			System.out.println("Case #"+i+": "+getSolution());
		}
		
	}

	public static void main(String[] args) {
		new TaskB().runTask(args);

	}

}
