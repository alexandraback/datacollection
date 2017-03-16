import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;



public class TaskA {

	int N;
	int[] pieces;
	int first;
	int second;
	
	public void parseCase(Scanner input) {
		N=input.nextInt();
		pieces=new int[N];
		for(int i=0;i<N;i++)
			pieces[i]=input.nextInt();
	}
	
	
	public void solveCase() {
		first=0;
		int min=0;
		for(int i=0;i<N-1;i++)
			if(pieces[i]>pieces[i+1]){
				first+=pieces[i]-pieces[i+1];
				min=Math.max(min, pieces[i]-pieces[i+1]);
			}
		second=0;
		for(int i=0;i<N-1;i++)
			if(pieces[i]>=min)
				second+=min;
			else
				second+=pieces[i];
	}

	public String getSolution() {
		return first+" "+second;
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
		new TaskA().runTask(args);

	}

}
