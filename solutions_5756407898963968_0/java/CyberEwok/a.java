package qualification14;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class a 
{
	public static void main(String args[]) throws IOException
	{
		String path="C:\\CodeJam14\\";
		String fileInput="input.txt";
		String fileOutput="output.txt";
		Scanner sc=new Scanner(new FileReader(path+fileInput));
		BufferedWriter bw=new BufferedWriter(new FileWriter(path+fileOutput));
		int numCases=sc.nextInt();
		for(int i=0;i<numCases;i++)
		{
			int[][] sets=new int[2][4];
			for(int block=0;block<2;block++)
			{
				int desRow=sc.nextInt()-1;
				for(int row=0;row<4;row++)
				{
					for(int col=0;col<4;col++)
					{
						if(row==desRow)
							sets[block][col]=sc.nextInt();
						else
							sc.nextInt();
					}
				}
			}
			List<Integer> ret=intersect(sets[0],sets[1]);
			bw.write("Case #"+(i+1)+": ");
			if(ret.isEmpty())
			{
				bw.write("Volunteer cheated!\n");
			}
			else if(ret.size()>1)
			{
				bw.write("Bad magician!\n");
			}
			else
			{
				bw.write(ret.get(0)+"\n");
			}
		}
		bw.close();
	}
	
	public static List<Integer> intersect(int[] set1, int[] set2)
	{
		List ret=new ArrayList<Integer>();
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(set1[i]==set2[j])
					ret.add(set1[i]);
		return ret;
	}

}
