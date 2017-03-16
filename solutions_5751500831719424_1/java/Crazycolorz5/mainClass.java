import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class mainClass {

	public static void main(String[] args) {
		File f = new File("A-large.in");
		File out = new File("theRepeater.out");
		FileInputStream fin;
		Scanner sin = null;
		try {
			fin = new FileInputStream(f);
			FileWriter fout = new FileWriter(out);
			try {
				sin = new Scanner(fin);
				int numOfCases = sin.nextInt();
				for(int casenum = 0; casenum<numOfCases; casenum++)
				{
					int N = sin.nextInt();
					StringBuilder[] strings = new StringBuilder[N];
					sin.nextLine();
					for(int i=0; i<N; i++)
					{
						strings[i] = new StringBuilder(sin.nextLine());
					}
					
					//First check if impossible
					//It will be impossible if one of the strings contains a letter that another does not
					//So reduce the number of consecutive letters in each string to one then check for equality.
					StringBuilder[] reducedStrings = new StringBuilder[N];
					for(int i=0; i<N; i++)
					{
						reducedStrings[i] = new StringBuilder(strings[i].toString());
					}
					for(int i=0; i<N; i++)
					{
						for(int x=1; x<reducedStrings[i].length(); x++)
						{
							if(reducedStrings[i].charAt(x)==reducedStrings[i].charAt(x-1))
							{
								reducedStrings[i].deleteCharAt(x);
								x--;
							}
						}
					}
					boolean impossible = false;
					for(int i=1; i<N; i++)
					{
						if(!reducedStrings[i].toString().equals(reducedStrings[i-1].toString()))
						{
							impossible = true;
							break;
						}
					}
					int finalDist = 0;
					if(!impossible)
					{
						//Turn each string into a list of integers.
						//the integer in the nth position is the number of repeats of that char
						//eg aaaabbcdee turns into [4,2,1,1,2]
						int numLetters = reducedStrings[0].length();
						int[][] numArray = new int[N][numLetters];
						for(int i=0; i<N; i++)
						{
							int curCount = 1, curCharNum = 0;
							char currentChar = strings[i].charAt(0);
							for(int x=1; x<strings[i].length(); x++)
							{
								if(strings[i].charAt(x)==currentChar)
								{
									curCount++;
								}
								else
								{
									numArray[i][curCharNum] = curCount;
									curCount = 1;
									currentChar = strings[i].charAt(x);
									curCharNum++;
								}
							}
							numArray[i][curCharNum] = curCount;
						}
						
						//Now this is a simple taxicab geometry problem.
						//Propose a point that seems reasonably in the center -- let's just say the first point.
						//get the number of points to the (same vertical line or right) and (same vertical line and left) of the point
						//If they are unequal, move in the direction with more.
						//If they are equal, move on to the next stage
						//Stage 2: Do the same thing with verical.(dimension 2 +-)
						//Repeat for each of the dimensions.
						
						
						//Nope, chuck testa. There's an easier way.
						//Find the *median* of each coordinate.
						//If there's an even number of numbers, it doesn't matter since all have the same "voting distance"
						int[] finalCoord = new int[numLetters];
						for(int i=0; i<finalCoord.length; i++)
						{
							//find the median of coords of the ith coord
							//do this by making a list of the coords, sorting it, and getting the n/2th element
							
							int[] ithCoord = new int[N]; //corresponds to elements of numArray
							for(int x=0; x<N; x++)
							{
								ithCoord[x] = numArray[x][i];
							}
							//Now sort.
							Arrays.sort(ithCoord);
							finalCoord[i] = ithCoord[ithCoord.length/2];
						}
						//Now the answer to the number of steps is simply the sum of the distanced of this point to all out points
						finalDist = 0;
						for(int i=0; i<N; i++)
						{
							for(int x=0; x<numLetters; x++)
							{
								finalDist+=Math.abs(finalCoord[x]-numArray[i][x]);
							}							
						}
						//And now we can output
					}
					
					
					try {
						fout.write("Case #" + (casenum+1) + ": ");
						if(impossible)
						{
							fout.write("Fegla Won\n");
						}
						else
						{
							fout.write(Integer.toString(finalDist));
							fout.write("\n");
						}
						fout.flush();
					} catch (IOException e1) {e1.printStackTrace();}
				}
			} finally {
				sin.close();
				fout.close();
			}
		}
		catch(IOException e)
		{}
	}
}