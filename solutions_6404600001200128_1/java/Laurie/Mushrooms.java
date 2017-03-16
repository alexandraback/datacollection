import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Mushrooms {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner (new File("b.in"));
		//Scanner in = new Scanner (System.in);
		int cases = in.nextInt();
		for (int caseNo = 1; caseNo <= cases; caseNo++)
		{
			int size = in.nextInt();
			int []pieces = new int[size];
			for (int i = 0; i < size; i++)
			{
				pieces[i] = in.nextInt();
			}
			int res1 = findFirst(pieces);
			int res2 = findSecond(pieces);
			
			System.out.println("Case #" + caseNo + ": " + res1 + " " + res2);
			
		}
	}

	private static int findFirst(int[] p) {
		int count = 0;
		int base = p[0];
		for (int i = 1; i < p.length; i++)
		{
			int curr = p[i];
			if (curr < base)
				count += (base - curr);
			base = curr;
		}
		return count;

	}

	
	private static int findSecond(int[] p) {
		int max= 0;
		int base = p[0];
		for (int i = 1; i < p.length; i++)
		{
			int curr = p[i];
			if (curr < base)
			{
				int diff = (base - curr);
				if (diff > max)
					max = diff;
			}
			base = curr;
		}
		int rate = max/10;
		int count = 0;
		base = p[0];
		int eaten = max;
		for (int i = 0; i < p.length-1; i++)
		{
			int curr = p[i];
			if (curr < eaten)
				count += curr;
			else
				count += max;
			//System.out.println("Eaten =  " + count);
			base = curr;
		}
		
		
		return count;

	}

}
