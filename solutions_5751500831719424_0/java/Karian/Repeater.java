import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class Repeater {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// open file and create a buffered reader
		FileReader input = new FileReader(args[0]);
		BufferedReader buffer = new BufferedReader(input);
		
		//read the number of testcases
		int max = Integer.parseInt(buffer.readLine().trim());
		
		// read a line and call the solving procedure for a single test case.  We expect back the result as a string
		for (int i = 1; i <= max; i++) {
			System.out.println("Case #"+i+": " + solve(buffer));
		}
	}

	private static String solve(BufferedReader buffer) throws IOException {
		int nbStrings = Integer.parseInt(buffer.readLine().trim());
		String[] string = new String[nbStrings];
		for (int i = 0; i < nbStrings; i++) {
			string[i] = buffer.readLine().trim();
		}
		char current = string[0].charAt(0);
		String target = String.valueOf(current);
		for(int j = 1; j < string[0].length(); j++)
		{
			if(current != string[0].charAt(j))
			{
				current = string[0].charAt(j);
				target = target.concat(String.valueOf(current));
			}
		}
		int length = target.length();
		int[][] values = new int[nbStrings][length];
		
		for (int i = 0; i < nbStrings; i++) 
		{
			int position = 0;
			for(int j = 0; j < length; j++)
			{
				if(position >= string[i].length() || string[i].charAt(position) != target.charAt(j))
				{
					return new String("Fegla Won");
				}
				while(position < string[i].length() && string[i].charAt(position) == target.charAt(j))
				{
					position++;
					values[i][j]++;
				}
			}
			if(position < string[i].length())
			{
				return new String("Fegla Won");
			}
		}
		
		// specific code for easy, nbStrings = 2
		int total = 0;
		for(int i = 0; i < length; i++)
		{
			total += Math.abs(values[0][i]-values[1][i]);
		}
				
		return String.valueOf(total);
	}
	

}
