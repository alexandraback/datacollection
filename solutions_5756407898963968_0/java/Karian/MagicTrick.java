import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;


public class MagicTrick {

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
		int iRow = Integer.parseInt(buffer.readLine().trim());
		HashSet<Integer> set = new HashSet<Integer>();
		for (int i = 1; i <= 4; i++) {
			String sRow = buffer.readLine().trim();
			if (i == iRow )
			{
				String[] split = sRow.split(" ");
				for(int j = 0; j < 4; j++)
				{
					set.add(Integer.parseInt(split[j]));
				}
			}
		}
		iRow = Integer.parseInt(buffer.readLine().trim());
		int count = 0;
		int value = 0;

		for (int i = 1; i <= 4; i++) {
			String sRow = buffer.readLine().trim();
			if (i == iRow )
			{
				String[] split = sRow.split(" ");
				for(int j = 0; j < 4; j++)
				{
					if(set.contains(Integer.parseInt(split[j])))
					{
						count ++;
						value = Integer.parseInt(split[j]);
					}
				}
			}
		}

		if(count == 0)
		{
			return new String("Volunteer cheated!");
		}
		if(count == 1)
		{
			return new String(""+value);
		}
		return new String("Bad magician!");
	}
	
}
