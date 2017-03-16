import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;



public class TaskC {

	class Tree{
		long x,y;
		Tree(long x, long y){
			this.x=x;
			this.y=y;
		}
	}
	
	Tree[] trees;
	int[][] left;
	int[][] right;
	int N;
	
	public void parseCase(Scanner input) {
		N=input.nextInt();
		trees=new Tree[N];
		left=new int[N][N];
		right=new int[N][N];
		for(int i=0;i<N;i++)
			trees[i]=new Tree(input.nextLong(), input.nextLong());
	}
	
	
	public void solveCase() {
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			{
				Tree a=trees[i];
				Tree b=trees[j];
				for(int k=0;k<N;k++)
				{
					Tree c=trees[k];
					long D=(c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x);
					if(D<0) left[i][j]++;
					if(D>0) right[i][j]++;
				}
			}
				
	}

	public String getSolution() {
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<N;i++){
			int minleft=100000;
			int minright=100000;
			for(int j=0;j<N;j++)
			{
				if(i!=j){
					if(left[i][j]<minleft)minleft=left[i][j];
					if(right[i][j]<minright)minright=right[i][j];
				}
			}
			sb.append("\n"+Math.min(minleft,minright));
		}
		return N==1?"\n0":sb.toString();
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
		new TaskC().runTask(args);

	}

}
