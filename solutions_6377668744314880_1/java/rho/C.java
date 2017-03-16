import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;


class tree implements Comparable<tree>
{
	long x, y;
	static tree center = new tree(0,0);
	public tree(int X, int Y)
	{
		x=X; y=Y;
	}
	
	long cross(tree T1, tree T2)
	{
		return (T1.x-x)*(T2.y-y)-(T1.y-y)*(T2.x-x);
	}
	
	public int compareTo(tree o) {
		double angle1=Math.atan2(y-center.y, x-center.x);
		double angle2=Math.atan2(o.y-center.y, o.x-center.x);
		if(Math.abs(angle1-angle2)<.0001 && center.cross(this, o)==0)
			return 0;
		else if(angle1<angle2)
			return -1;
		else
			return 1;
	}
	
	@Override
	public String toString() {
		return x+","+y+"|"+Math.atan2(y-center.y, x-center.x);
	}
}

public class C {
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("C-large.in"));
		File file = new File("example.txt");
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        
		 
		int T = sc.nextInt();
		for(int testC = 1; testC<=T; ++testC)
		{
			int N = sc.nextInt();
			ArrayList<tree> arrL = new ArrayList<tree>(), cpy=new ArrayList<tree>();
			for(int i=0; i<N; ++i)
			{
				arrL.add(new tree(sc.nextInt(), sc.nextInt()));
			}
			//System.out.println(arrL);	
			
			output.write(String.format("Case #%d:\n", testC));	
			if(N>3)
			{
				for(int i=0; i<N; ++i)
				{
					tree.center=arrL.get(i);
					cpy.clear();
					for(int j=0; j<N; j++)
						if(i!=j)
							cpy.add(arrL.get(j));
					Collections.sort(cpy);
					//System.out.println("("+i+"|"+tree.center.toString()+")"+cpy);
					int begin=0, end=1, rem=N;
					while(begin<N-1)
					{
						if(end==begin)
						{
							end=(end+1)%(N-1);
						}
						//System.out.println(begin+","+end);
						while(end!=begin && tree.center.cross(cpy.get(begin), cpy.get(end))>=0)
						{
							end=(end+1)%(N-1);
							//System.out.println(begin+","+end);
						}
						if(end==begin)
						{
							rem=0;
							break;
						}
						if(rem>(N-1-(end-begin+N-1)%(N-1)))
							rem=(N-1-(end-begin+N-1)%(N-1));
						begin++;
					}
					output.write(rem+"\n");
				}
			}
			else if(N==3)
				output.write("0\n0\n0\n");
			else if(N==2)
				output.write("0\n0\n");
			else if(N==1)
				output.write("0\n");
			System.out.println(testC);
			
		}
		
		output.close();
	}
	
}
