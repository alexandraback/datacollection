import java.util.Scanner;


public class Main 
{
	public static void main(String args[])
	{
		int testcases;
		Scanner input = new Scanner(System.in);
		
		testcases = input.nextInt();
		
		for(int i=1;i<=testcases;i++)
		{
			int rows123=input.nextInt();
			for(int j=0;j<rows123;j++)
				input.nextLine();
			
			int kuldeep[]=new int [4];
			
			kuldeep[0]=input.nextInt();
			kuldeep[1]=input.nextInt();
			kuldeep[2]=input.nextInt();
			kuldeep[3]=input.nextInt();
			
			for(int j=rows123;j<=4;j++)
				input.nextLine();
			
			int row2=input.nextInt();
			for(int j=0;j<row2;j++)
				input.nextLine();
			
			int kkk1296[]=new int [4];
			
			kkk1296[0]=input.nextInt();
			kkk1296[1]=input.nextInt();
			kkk1296[2]=input.nextInt();
			kkk1296[3]=input.nextInt();
			
			for(int j=row2;j<=4;j++)
				input.nextLine();
			int counter1=0;
			int aanswer=-1;
			for(int j=0;j<4;j++)
			{
				for(int k=0;k<4;k++)
				{
					if(kkk1296[k]==kuldeep[j])
					{
						aanswer=kuldeep[j];
						counter1++;
					}
				}
			}
			if(counter1==1)
				System.out.println("Case #"+i+": "+aanswer);
			else if(counter1==0)
				System.out.println("Case #"+i+": "+"Volunteer cheated!");
			else
				System.out.println("Case #"+i+": "+"Bad magician!");
		}
	}
}
