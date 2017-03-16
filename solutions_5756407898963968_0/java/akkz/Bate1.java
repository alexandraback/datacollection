package QualificationRound.MagicTrick;

import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Bate1
{
	private static Scanner in = new Scanner(System.in);
	private static PrintStream out = System.out;
	
	public static void main(String[] args)
	{
		int current = in.nextInt()+1;
		for(int i=1; i<current; i++)
		{
			check(i);
		}
	}
	
	private static void check(int i)
	{
		int[] nums = new int[Short.MAX_VALUE];
		Arrays.fill(nums, 0);
		
		int row1 = in.nextInt();
		
		for(int j=0; j<4; j++)
		{
			for(int k=0; k<4; k++)
			{
				if(j+1==row1)
					nums[in.nextInt()]++;
				else
					in.nextInt();
			}
		}
		
		int row2 = in.nextInt();
		
		for(int j=0; j<4; j++)
		{
			for(int k=0; k<4; k++)
			{
				if(j+1==row2)
					nums[in.nextInt()]++;
				else
					in.nextInt();
			}
		}
		
		boolean flag = false;
		int num = 0;
		for(int j=0; j<Short.MAX_VALUE; j++)
		{
			if(nums[j] == 2)
			{
				if(!flag)
				{
					flag = true;
					num = j;
				}
				else
				{
					out.println("Case #" + i + ": Bad magician!");
					return;
				}
			}
		}
		
		if(flag)
		{
			out.println("Case #" + i + ": " + num);
		}
		else
		{
			out.println("Case #" + i + ": Volunteer cheated!");
		}
	}
}
