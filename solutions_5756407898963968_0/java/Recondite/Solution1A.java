package practice;

import genericSolver.ISolver;
import genericSolver.Reader;

import java.io.IOException;

public class Solution1A implements ISolver {

	public static void main(String[] args) {
		ISolver Solution = new Solution1A();
		Reader s;
		try {
			s = new Reader(Solution, "A-small-attempt1", "out");
			s.solveCases(false);
			s.finish();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * @param args
	 */
	@Override
	public String solve(Reader reader) {
		int f = reader.returnInt();
		int[] pos = new int[4];
		int[] end = new int[4];

		for (int i = 0; i < 4; i++)
			if ((f-1) == i)
				pos = reader.returnInts(4);
			else
				reader.returnInts(4);
		
		
		f = reader.returnInt();		
		for (int i = 0; i < 4; i++)
			if ((f-1) == i)
				end = reader.returnInts(4);
			else
				reader.returnInts(4);

		int count=0;
		int result=-1;
		
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){
				if(pos[i]==end[j]){
					result=pos[i];
					count++;
				}
			}
		
		if(count>1)
			return " Bad magician!";
		else if(count==1)
			return " "+result;
		else return " Volunteer cheated!";
		
	}

}
