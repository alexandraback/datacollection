import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;



public class TaskA {

	boolean felgaWon;
	char[] letters;
	int[][] matrix;
	int N;
	int result;
	int size;
	
	public void parseCase(Scanner input) {
		letters=new char[100];
		felgaWon=false;
		N=input.nextInt();
		input.nextLine();
		String s=input.nextLine();
		int lastIndex=0;
		letters[0]=s.charAt(0);
		for(char c:s.toCharArray())
			if(letters[lastIndex]!=c)
				letters[++lastIndex]=c;
		size=lastIndex+1;
		matrix=new int[size][N];
		splitString(0,s);
		for(int i=1;i<N;i++)
		{
			s=input.nextLine();
			splitString(i,s);
			if(felgaWon) return;
		}
		
	}
	
	
	private int findMin(int i) {
		int min=10000;
		Set<Integer> ls=new HashSet<>();
		for(int j:matrix[i])
			ls.add(j);
		for(int j:ls)
		{
			int sum=0;
			for(int x=0;x<N;x++)
				sum+=(Math.abs(matrix[i][x]-j));
			if(sum<min)
				min=sum;
		}
		return min;
	}


	private void splitString(int n, String s) {
		int lastIndex=0;
		for(char c:s.toCharArray())
			if(letters[lastIndex]==c)
				matrix[lastIndex][n]+=1;
			else if(matrix[lastIndex][n]>0&&letters[lastIndex+1]==c){
				lastIndex++;
				matrix[lastIndex][n]++;
			}
			else {
				felgaWon=true;
				return;
			}
		if(lastIndex<size-1)
			felgaWon=true;
	}


	public void solveCase() {
		result=0;
		for(int i=0;i<size;i++)
		{
			int pmin=findMin(i);
			result+=pmin;
		}
	}

	public String getSolution() {
		return felgaWon?"Fegla Won":Integer.toString(result);
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
