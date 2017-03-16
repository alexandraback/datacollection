import java.util.*;


public class MagicTrick {

	public void solve()
	{
		Scanner sc = new Scanner(System.in);
		int numTest = sc.nextInt();
		for(int i=0;i<numTest;i++)
		{
			ArrayList<Integer> ans = new ArrayList<Integer>();
			HashSet<Integer> set = new HashSet<Integer>();
			int rowInFirst = sc.nextInt();
		//	sc.nextLine();
			for(int c=0;c<rowInFirst-1;c++)
			{
				sc.nextInt();
				sc.nextInt();
				sc.nextInt();
				sc.nextInt();
			}
			for(int j=0;j<4;j++)
			{
				set.add(sc.nextInt());
			}
			for(int c=0;c<4-rowInFirst;c++)
			{
				sc.nextInt();
				sc.nextInt();
				sc.nextInt();
				sc.nextInt();
			}
			
			int rowInSecond = sc.nextInt();
	//		sc.nextLine();
			for(int c=0;c<rowInSecond-1;c++)
			{
				sc.nextInt();
				sc.nextInt();
				sc.nextInt();
				sc.nextInt();
			}
			for(int j=0;j<4;j++)
			{
				int temp = sc.nextInt();
				if(set.contains(temp))
				{
					ans.add(temp);
				}
			}
			for(int c=0;c<4-rowInSecond;c++)
			{
				sc.nextInt();
				sc.nextInt();
				sc.nextInt();
				sc.nextInt();
			}
			System.out.printf("Case #%d: ", i+1);
			if(ans.size()==0)
			{
				System.out.printf("Volunteer cheated!\n");
			}
			else if(ans.size()==1)
			{
				System.out.printf("%d\n",ans.get(0));
			}
			else
			{
				System.out.printf("Bad magician!\n");
			}
		}
		sc.close();
	}
}
