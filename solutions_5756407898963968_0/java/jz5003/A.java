import java.util.*;
import java.io.*;
public class A {
	static int t, b,e, mat1[][] = new int[4][4], mat2[][] = new int[4][4];
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("A-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new File("A.out"));
		t = i(in.nextLine());
		for(int i = 0; i < t; i++)
		{
			b = i(in.nextLine());
			for(int j = 0; j < 4; j++)
			{
				StringTokenizer st = new StringTokenizer(in.nextLine());
				for(int k = 0; k < 4; k++)
				{
					mat1[j][k]=i(st.nextToken());
				}
			}
			e = i(in.nextLine());
			for(int j = 0; j < 4; j++)
			{
				StringTokenizer st = new StringTokenizer(in.nextLine());
				for(int k = 0; k < 4; k++)
				{
					mat2[j][k]=i(st.nextToken());
				}
			}
			int val = -1;
			boolean bad = false;
			outer:
			for(int j = 0; j < 4; j++)
			{
				int bb = mat1[b-1][j];
				for(int k = 0; k < 4; k++)
				{
					if(mat2[e-1][k]==bb)
					{
						if(val!=-1) 
							{
							bad = true;
							break outer;
							}
						val = bb;
					}
				}
			}
			String s = "";
			if(bad) s = "Bad magician!";
			else if(val==-1) s = "Volunteer cheated!";
			else
				s+=val;
			out.printf("Case #%d: %s\n",i+1,s);
			
		}
		out.close();
		System.exit(0);
		
	}
	static int i(String s)
	{
		return Integer.parseInt(s);
	}
}
