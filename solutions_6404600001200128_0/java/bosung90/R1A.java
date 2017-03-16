import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class R1A {

	private final static String CLASS_NAME = R1A.class.getSimpleName();
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		PrintWriter writer = new PrintWriter(CLASS_NAME + ".out", "UTF-8");
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t=0; t<T; t++)
		{
			int N = scan.nextInt();
			int[] M = new int[N];
			for(int n=0; n<N; n++)
			{
				M[n] = scan.nextInt();
			}
			
			String ans = "Case #"+(t+1)+": " + getAns(M);
			System.out.println(ans);
			writer.println(ans);
		}
		scan.close();
		writer.close();
	}
	
	private static String getAns(int[] M)
	{
		int Y = 0;
		int Z = 0;
		
		int prevY = M[0];
		for(int y = 1; y< M.length; y++)
		{
			if(prevY > M[y])
			{
				Y += prevY - M[y];
			}
			prevY = M[y];
		}
		
		int maxDiff = 0;
		int prevZ = M[0];
		for(int z = 1; z< M.length; z++)
		{
			if(prevZ - M[z] > maxDiff)
			{
				maxDiff = prevZ - M[z];
			}
			prevZ = M[z];
		}
		
		
		prevZ = M[0];
		for(int z = 1; z< M.length; z++)
		{
			if(prevZ >= maxDiff)
			{
				Z += maxDiff;
			}
			else
			{
				Z += prevZ;
			}
			prevZ = M[z];
		}
		
		
		return Y + " " + Z;
	}

}
