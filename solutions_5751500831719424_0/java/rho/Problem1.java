import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;


public class Problem1 {
public static void main(String[] args) throws IOException {
	Scanner sc = new Scanner(new File("p1.in"));
	BufferedWriter out = new BufferedWriter(new FileWriter(new File("p1.out")));
	
	int T = sc.nextInt();
	for(int t=0; t<T; ++t)
	{
		int N = sc.nextInt();
		String[] strs  = new String[N];
		for(int n=0; n<N; ++n)
			strs[n]=sc.next();
		boolean done = false;
		boolean won = true;
		int TD=0;
	o:	while(!done)
		{
		//System.out.println(Arrays.toString(strs));
		//System.out.println(TD);
			if(strs[0].length()==0)
			{
				for(int n=1; n<N; ++n)
				{
					if(strs[n].length()!=0)
					{
						won=false;
						done=true;
						break o;
					}
				}
				won=true;
				done=true;
				break o;
			}
			int[] nums = new int[N];
			char C = strs[0].charAt(0);
			for(int n=0; n<N; n++)
			{
				if(strs[n].length()==0)
				{
					won=false;
					done=true;
					break o;
				}
				nums[n]=0;
				while(nums[n]<strs[n].length() && strs[n].charAt(nums[n])==C) ++nums[n];
				strs[n]=strs[n].substring(nums[n]);
			}
			Arrays.sort(nums);
			if(nums[0]==0)
			{
				won=false;
				done=true;
				break;
			}
			int D=0;
			int M=nums[N/2];
			for(int n=0; n<N; ++n)
				D+=Math.abs(nums[n]-M);
			TD+=D;
		}
		System.out.print("Case #"+(t+1)+": ");
		if(won)
		{
			System.out.println(TD);
		}
		else
		{
			System.out.println("Fegla Won");
		}
	}
}
}
