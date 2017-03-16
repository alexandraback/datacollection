import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;



public class Question1 
{

	public static void main(String[] args)
	{
		StringMatch("C:\\CodeJam\\Round1\\A-small-attempt0.in");
	}

	public static void StringMatch(String filePath)
	{
		try 
		{
			BufferedReader bufferedReader = new BufferedReader(new FileReader(filePath));
			String line;
			boolean firstline = true;


			File file = new File("C:\\CodeJam\\Round1\\PracInput.txt");

			// if file doesnt exists, then create it
			if (!file.exists()) 
			{
				file.createNewFile();
			}

			//FileWriter fw = new FileWriter(file.getAbsoluteFile());
			//BufferedWriter bw = new BufferedWriter(fw);


			int testCases  = 0;

			testCases = Integer.parseInt(bufferedReader.readLine());
			int caseNo = 1;

			while (caseNo<=testCases) 
			{
				int lines = Integer.parseInt(bufferedReader.readLine());
				String[] arr = new String[lines];
				int[] arr1 = new int[lines];

				int maxlength = Integer.MIN_VALUE;
				boolean possible = true;

				for(int i=0; i<lines; i++)
				{
					arr[i] = bufferedReader.readLine();
					if(arr[i].length()>maxlength)
						maxlength = arr[i].length();
				}

				boolean tocontinue = true;
				int totalops = 0;
				int index = 0;

				//Checking the start index

				while(tocontinue)
				{

					for(int i=0; i<lines-1; i++)
					{
						if(arr[i].charAt(index)!=arr[i+1].charAt(index))
						{
							possible = false;
							break;
						}
					}

					if(possible==false)
					{
						tocontinue = false;
					}

					else
					{


						for(int i=0; i<lines; i++)
						{
							for(int j=0; j<arr[i].length()-1; j++)
							{
								if(arr[i].charAt(j)==arr[i].charAt(j+1))
									arr1[i]++;
								else
									break;
							}
						}

						int minops = Integer.MAX_VALUE;
						for(int i=0; i<arr1.length; i++)
						{
							int operations = 0;
							for(int j=0; j<arr1.length; j++)
							{
								if(j==i)
									continue;
								operations += Math.abs(arr1[j]-arr1[i]);
							}

							if(operations<minops)
								minops = operations;
						}
						
						totalops += minops;

						int count = 0;
						for(int i=0; i<lines; i++)
						{
							arr[i] = arr[i].substring(arr1[i]+1);
							arr1[i] = 0;

							if(arr[i].equals(""))
								count++;
						}

						if(count>0 && count<lines)
						{
							possible = false;
							tocontinue = false;
						}
						
						if(count==lines)
						{
							tocontinue = false;
							possible = true;
						}
					}
				}

				
				if(!possible)
					System.out.println("Case #"+caseNo+": "+"Fegla Won");
				else
					System.out.println("Case #"+caseNo+": "+totalops);
						
					caseNo++;
			}

		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		} 
	}




}
