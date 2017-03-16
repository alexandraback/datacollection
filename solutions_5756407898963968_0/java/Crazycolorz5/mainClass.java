import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;


public class mainClass {

	public static void main(String[] args) {
		File f = new File("A-small-attempt1.in");
		File out = new File("magicTrick.out");
		FileInputStream fin;
		Scanner sin = null;
		try {
			fin = new FileInputStream(f);
			FileWriter fout = new FileWriter(out);
			try {
				sin = new Scanner(fin);
				int numOfCases = sin.nextInt();
				for(int casenum = 0; casenum<numOfCases; casenum++)
				{
					int rowOne = sin.nextInt();
					int[] theRowOne = new int[4];
					for(int i=0; i<4; i++)
					{
						if(i==rowOne-1)
						{
							theRowOne = getRow(sin);
						}
						else
							ignoreRow(sin);
					}
					int rowTwo = sin.nextInt();
					int[] theRowTwo = new int[4];
					for(int i=0; i<4; i++)
					{
						if(i==rowTwo-1)
						{
							theRowTwo = getRow(sin);
						}
						else
							ignoreRow(sin);
					}
					
					ArrayList<Integer> inBothRows = getIntersect(theRowOne, theRowTwo);					
					
					try {
						fout.write("Case #" + (casenum+1) + ": ");// + String.valueOf(count) + "\n");
						if(inBothRows.size()==1)
							fout.write(inBothRows.get(0).toString());
						else if(inBothRows.size()==0)
							fout.write("Volunteer cheated!");
						else
							fout.write("Bad magician!");
						fout.write("\n");
						fout.flush();
					} catch (IOException e1) {e1.printStackTrace();}
				}
			} finally {
				sin.close();
				fout.close();
			}
		}
		catch(IOException e)
		{}
	}

	public static void ignoreRow(Scanner s)
	{
		s.nextInt();
		s.nextInt();
		s.nextInt();
		s.nextInt();
	}
	public static int[] getRow(Scanner s)
	{
		int[] theRow = new int[4];
		theRow[0] = s.nextInt();
		theRow[1] = s.nextInt();
		theRow[2] = s.nextInt();
		theRow[3] = s.nextInt();
		return theRow;
		
	}
	public static ArrayList<Integer> getIntersect(int[] r1, int[] r2)
	{
		Arrays.sort(r1);
		Arrays.sort(r2);
		int i1=0, i2=0;
		ArrayList<Integer> theIntersect = new ArrayList<Integer>();
		while(i1<r1.length&&i2<r2.length)
		{
			if(r1[i1]==r2[i2])
			{
				theIntersect.add(r1[i1]);
				i1++;
			}
			else
			{
				if(r1[i1]<r2[i2])
				{
					i1++;
				}
				else
				{
					i2++;
				}
			}
		}
		return theIntersect;
	}
}
