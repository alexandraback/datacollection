import java.util.*;
import java.io.*;

public class Jammer
{
	public Jammer(){};
	
	/**Jams and does the problem*/
	public void jam(Scanner input, PrintWriter answerSheet)
	{
		//Extract the test cases
		int numCases = input.nextInt();
		input.nextLine();
		String data;
		
		
		for(int caseNumber = 1; caseNumber <= numCases; ++caseNumber)
		{
			int answerOne = input.nextInt() -1;
			int [][] boardOne = new int[4][4];
			for(int i = 0; i < 4; ++i)
			{
				for(int j = 0; j < 4; ++j)
				{
					boardOne[i][j] = input.nextInt();
				}
			}
			int answerTwo = input.nextInt() -1;
			int [][] boardTwo = new int[4][4];
			for(int i = 0; i < 4; ++i)
			{
				for(int j = 0; j < 4; ++j)
				{
					boardTwo[i][j] = input.nextInt();
				}
			}
			
			boolean go = true;
			
			int answer = -1;
			for(int i = 0; i < 4 && go; ++i)
			{
				int numOne = boardOne[answerOne][i];
				for(int j = 0; j < 4 && go; ++j)
				{
					int numTwo = boardTwo[answerTwo][j];
					
					if(numOne == numTwo)
					{
						if(answer != -1)
						{
							answerSheet.println("Case #" + caseNumber + ": " + "Bad magician!");
							go = false;
							continue;
						}
						
						answer = numOne;
					}
				}
			}
			
			if(go == false)
				continue;
			
			if(answer == -1)
			{
				answerSheet.println("Case #" + caseNumber + ": " + "Volunteer cheated!");
			}
			else
			{
				answerSheet.println("Case #" + caseNumber + ": " + answer);
			}
		}
	}
	
	/** Entry Point. Opens the input file passes it to the jammer.*/
	public static void main(String[] args)
	{
		//Open current directory
		File directory = new File(".");
		
		//Get the newest in file
		
		//Latest file so far
		int latestFileId = -1;
		File[] files = directory.listFiles();
		for(int i = 0; i < files.length; ++i)
		{
			if(files[i].isFile() &&//If we have a file 
			   files[i].getName().endsWith(".in") && // and its an in file
			   (latestFileId == -1 || files[i].lastModified() > files[latestFileId].lastModified()))//And its the newest file)
			{
				latestFileId = i;
			}
		}
		
		if(latestFileId == -1)
		{
			System.out.println("No File!");
			return;
		}
		
		//Get the latest file and pass it in as well as the answer sheet
		Jammer jammer = new Jammer();
		Scanner input;
		PrintWriter output;//Where to write the answer
		try
		{
			input = new Scanner(files[latestFileId]);
			output = new PrintWriter("out.txt", "UTF-8");
		}
		catch(Exception e)
		{
			System.out.println("BAIL! File not found!");
			return;
		}
		jammer.jam(input, output);
		input.close();
		output.close();
	}
};

