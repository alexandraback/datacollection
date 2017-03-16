import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Repeater {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("repeater.in"));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int Z = new Integer(st.nextToken());
		
		for(int z = 1; z <= Z; z++)
		{
			System.out.print("Case #" + z + ": ");
			
			st = new StringTokenizer(br.readLine());
			int numStrings = Integer.parseInt(st.nextToken());
			String[] strArr = new String[numStrings];
			for(int i = 0; i < strArr.length; i++)
				strArr[i] = br.readLine() + '_';
			
			// extract first string's chars
			ArrayList<Character> theCharsList = new ArrayList<Character>();
			char[] chars = strArr[0].toCharArray();
			for(int i = 0; i < chars.length - 1; i++)
			{
				if(chars[i] != chars[i+1])
				{
					theCharsList.add(chars[i]);
				}
			}

			Character[] theChars = theCharsList.toArray(new Character[0]);
			int[][] count = new int[numStrings][theChars.length];
			int firstRunCounter = 0;
			int charCounter = 0;
			for(int i = 0; i < chars.length - 1; i++)
			{
				firstRunCounter++;
				if(chars[i] != chars[i+1])
				{
					count[0][charCounter] = firstRunCounter;
					firstRunCounter = 0;
					charCounter++;
				}
			}
			
			// compare chars with other strings
			boolean solvable = true;
			charCounter = 0;
			int runCounter = 0;
			
			outer:
			for(int i = 1; i < numStrings; i++)
			{
				charCounter = 0;
				char[] tempChars = strArr[i].toCharArray();
				runCounter = 0;
				
				for(int j = 0; j < tempChars.length - 1; j++)
				{
					runCounter++;
					if(tempChars[j] != tempChars[j+1])
					{
						if(charCounter < theChars.length && tempChars[j] == theChars[charCounter])
						{
							count[i][charCounter] = runCounter;
							charCounter++;
							runCounter = 0;
						}
						else
						{
							solvable = false;
							break outer;
						}
					}
				}
				if(!(charCounter == theChars.length))
				{
					solvable = false;
					break outer;
				}
			}
			if(!solvable)
			{
				System.out.println("Fegla Won");
				continue;
			}
			
			// for each char, figure out what to change
			
			int ans = 0;
			for(int col = 0; col < count[0].length; col++)
			{
				int charMin = Integer.MAX_VALUE;
				for(int chosen = 0; chosen < count.length; chosen++)
				{
					int tempCost = 0;
					for(int row = 0; row < count.length; row++)
					{
						if(row == chosen)
							continue;
						tempCost += Math.abs((count[row][col] - count[chosen][col])); 
					}
					if(tempCost < charMin)
						charMin = tempCost;
				}
				ans += charMin;
			}
			
			System.out.println(ans);
		}
	}

}
