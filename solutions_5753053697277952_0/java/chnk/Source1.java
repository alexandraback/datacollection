import java.io.*;
import java.util.*;
class Source1 
{
	public static void main(String[] args) throws IOException 
	{
		String s,word,buffer;
		String[][] board;

		FileReader input = new FileReader("A-small.in");
		Scanner in = new Scanner(input);
		File file = new File("A-small.out");
		BufferedWriter out = new BufferedWriter(new FileWriter(file));

		s = in.nextLine();
		int count= Integer.parseInt(s);

		int i=1;
		 while (in.hasNext())
		{

			 out.write("Case #"+(i++)+": ");

			
				if(in.hasNext())s = in. nextLine();

				int N = Integer.parseInt(s);

				if(in.hasNext())s = in. nextLine();

				String[] sp = s.split(" ");
				int [] list = new int[N]; 
				for (int x=0;x<N;x++ )
				{
					list[x]= Integer.parseInt(sp[x]);

				}


				out.write(vote(N,list));
				out.newLine();

		}


		 out.close();
	}
	public static String vote(int N , int[] list)
	{
		String result="";
		int sum=99;
		while (sum>0)
		{
			sum=0;
			int max=0;
			int inmax=0;
			for (int i=0;i<N;i++ )
			{
				sum+=list[i];
				if(i==0)
				{
					max= list[i];
					inmax=i;
				}
				else
				{
					if(max<list[i])
					{
						max=list[i];
						inmax=i;
					}
				}
			}

			//remove max
			if(list[inmax]>0)
			{
				sum--;
				list[inmax]--;
				result+=""+ (char)(inmax+65);
			}

			int count=1;
			for (int i=0;i<N;i++ )
			{
				if(count>0&&list[i]>sum/2)
				{
					count--;
					sum--;
					list[i]--;
					result+=""+ (char)(i+65);
				}
			}




			result+=" ";

		}

		return result;
	}

}
