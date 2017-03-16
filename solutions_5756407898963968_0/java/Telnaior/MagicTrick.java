package tel.cj.cj2014.qualification;

import java.io.IOException;
import java.util.Scanner;
import java.io.PrintStream;
import java.nio.file.Path;
import java.nio.file.Paths;

public class MagicTrick{
	/**This class is designed to solve Problem A: Magic Trick.
	 * @param Two arguments: Input filepath and (optionally) output filepath.
	 * @throws IOException
	 * @author Telnaior
	 */
	public static void main(String[] args) throws IOException
	/**Controller method to set up input and output, then pass to problem-specific method.
	 * 
	 */
	{
		Path inputPath = Paths.get(args[0]);
		Scanner sc = new Scanner(inputPath);
		PrintStream output = new PrintStream(args[1]);
		System.setOut(output);
		run(sc);
		output.close();
	}
	static void run(Scanner sc)
	{
		final int GRIDSIZE = 4; //Makes the class scalable (though only 4x4 is needed)
		//Start by grabbing the number of test cases
		final int CASES = sc.nextInt();
		//Then let's declare some variables for later
		int cardRow = 0;
		int[] cardGrid = new int[GRIDSIZE*GRIDSIZE];
		for(int caseNumber=1; caseNumber<=CASES; caseNumber++)
		{
			//Load the grid for the first answer
			cardRow = loadGrid(sc,GRIDSIZE,cardGrid);
			//Remember which cards were in the selected row
			int[] potentialCards = new int[GRIDSIZE];
			for(int i=0; i<GRIDSIZE; i++)
			{
				potentialCards[i] = cardGrid[(GRIDSIZE*cardRow)+i];
			}
			//Reload the grid for the second answer
			cardRow = loadGrid(sc,GRIDSIZE,cardGrid);
			//Compare the selected row with our cards from earlier
			int chosenCard = -1;
			for(int i=0; i<GRIDSIZE; i++)
			{
				for(int j:potentialCards)
				{
					//If any number matches, set chosenCard to the card's number
					if(cardGrid[(GRIDSIZE*cardRow)+i] == j)
					{
						//But only if we don't already have a card
						if(chosenCard != -1)
						{
							chosenCard = -2;
						}
						//If we do, set it to that and end this farce already
						else
						{
							chosenCard = j;
							break;
						}
					}
				}
				//If we've already found two matches, stop wasting time
				if(chosenCard == -2)
				{
					break;
				}
			}
			reportResult(caseNumber, chosenCard);
		}
	}
	static int loadGrid(Scanner sc, int GRIDSIZE, int[] cardGrid)
	{
		//Find out what row we need, subtract 1 here to make it easier later
		int cardRow = sc.nextInt();
		cardRow--;
		//Load up the grid of cards
		for(int i=0; i<cardGrid.length; i++)
		{
			cardGrid[i] = sc.nextInt();
		}
		return cardRow;
	}
	static void reportResult(int caseNumber, int chosenCard)
	{
		//Let's start by printing off the case number
		System.out.print("Case #"+caseNumber+": ");
		//Then check for chosenCard duds (-1 or -2)
		if(chosenCard == -1)
		{
			System.out.println("Volunteer cheated!");
			return;
		}
		if(chosenCard == -2)
		{
			System.out.println("Bad magician!");
			return;
		}
		//If we make it here we only have one card, so print it
		System.out.println(chosenCard);
	}
}
