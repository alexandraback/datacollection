package codjam2014qual;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ProbA {
public static void main(String[] args)
{
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	for(int curcase =1;curcase <=n;curcase++ )
	{
		int rowone = sc.nextInt();
		sc.nextLine();
		for(int i=1;i<rowone;i++)
			sc.nextLine();
		Set<String> currow =  new HashSet<String>(Arrays.asList(sc.nextLine().split(" ")));
		for(int i=rowone+1;i<=4;i++)
			sc.nextLine();
		int rowtwo = sc.nextInt();
		sc.nextLine();
		for(int i=1;i<rowtwo;i++)
			sc.nextLine();
		Set<String> currow2 =  new HashSet<String>(Arrays.asList(sc.nextLine().split(" ")));
		for(int i=rowtwo+1;i<=4;i++)
			sc.nextLine();		
		currow.retainAll(currow2);
		if (currow.size()==0)
		System.out.println("Case #"+curcase+": Volunteer cheated!");
		if (currow.size()>1)
		System.out.println("Case #"+curcase+": Bad magician!");		
		if(currow.size()==1)
		System.out.println("Case #"+curcase+": "+currow.iterator().next());	
	}
}
}
