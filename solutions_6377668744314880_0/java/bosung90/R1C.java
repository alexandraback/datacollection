import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class R1C {

	private final static String CLASS_NAME = R1C.class.getSimpleName();
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		PrintWriter writer = new PrintWriter(CLASS_NAME + ".out", "UTF-8");
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t=0; t<T; t++)
		{
			int N = scan.nextInt();
			long[] X = new long[N];
			long[] Y = new long[N];
			for(int n=0; n<N; n++)
			{
				X[n] = scan.nextLong();
				Y[n] = scan.nextLong();
			}
			String ans = "Case #"+(t+1)+":";
			System.out.println(ans);
			writer.println(ans);
			getAns(X, Y, writer);
		}
		scan.close();
		writer.close();
	}
	
	private static void getAns(long[] X, long[] Y, PrintWriter writer)
	{
		for(int i=0; i<X.length; i++)
		{
			//for each other dot, make a line. 
			//Calculate number of dots that lie outside of the line (on each side)
			//pick the lowest number of dots you could find
			
			
			long lowestNum = Long.MAX_VALUE;
			
			long Ax = X[i];
			long Ay = Y[i];
			
			for(int x=0; x<X.length; x++)
			{
				long Bx = X[x];
				long By = Y[x];
				
				if(i == x)
					continue;
				
				long localMin = getMinNumSide(Ax, Ay, Bx, By, X, Y);
				if(lowestNum > localMin)
					lowestNum = localMin;
			}
			
			if(lowestNum == Long.MAX_VALUE)
				lowestNum = 0;
			
			System.out.println(lowestNum);
			writer.println(lowestNum);
		}
	}
	
	private static long getMinNumSide(long Ax, long Ay, long Bx, long By, long[] X, long[] Y)
	{
		long positiveSide = 0;
		long negativeSide = 0;
		for(int x=0; x<X.length; x++)
		{
			long sign = getWhichSideOfLine(Ax, Ay, Bx, By, X[x], Y[x]);
			if(sign > 0)
				positiveSide ++;
			else if(sign <0)
				negativeSide ++;
		}
		return (positiveSide > negativeSide)? negativeSide : positiveSide;
	}
	
	private static long getWhichSideOfLine(long Ax, long Ay, long Bx, long By, long Mx, long My)
	{
		//0 if p3 is on the line
		//-1 if it is on the one side
		//1 if it is on the other side
		
		long sign = (Bx-Ax)*(My-Ay) - (By-Ay)*(Mx-Ax);
		
		if(sign == 0)
			return 0;
		if(sign > 0)
			return 1;
		else
			return -1;
		
	}

}
