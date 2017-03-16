import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Round1B14A {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
//		PrintStream out = System.out;
		int nCases = Integer.parseInt(in.readLine());
		outer: for(int z = 0; z < nCases; z++)
		{
			int nStrings = Integer.parseInt(in.readLine());
			String[] strings = new String[nStrings];
			for(int i = 0; i < nStrings; i++) strings[i] = in.readLine();
			
			char[] chars = new char[strings[0].length()];
			chars[0] = strings[0].charAt(0);
			int charIndex = 1;
			for(int i = 1; i < strings[0].length(); i++)
			{
				if(strings[0].charAt(i) != strings[0].charAt(i - 1))
				{
					chars[charIndex++] = strings[0].charAt(i);
				}
			}
			//charIndex now has length
			int nChars = charIndex;
			chars = Arrays.copyOf(chars, nChars);
			
			out.print("Case #" + (z + 1) + ": ");
			int[][] charCounts = new int[charIndex][nStrings]; //[char][string] for convenience
			for(int s = 0; s < nStrings; s++)
			{
				String string = strings[s];
				if(string.charAt(0) != chars[0])
				{
					out.println("Fegla Won");
					continue outer;
				}
				charIndex = 0;
				for(int i = 0; i < string.length(); i++)
				{
					char c = string.charAt(i);
					if(c != chars[charIndex]) charIndex++;
					if(charIndex == nChars || c != chars[charIndex])
					{
						out.println("Fegla Won");
						continue outer;
					}
					charCounts[charIndex][s]++;
				}
				if(charIndex < nChars - 1) //didn't use last characters
				{
					out.println("Fegla Won");
					continue outer;
				}
			}
			
			int moves = 0;
			for(int[] c : charCounts)
			{
				int median = median(c);
				for(int s : c)
				{
					moves += Math.abs(median - s);
				}
			}
			out.println(moves);
		}
		in.close();
		out.close();
	}
	
	static int median(int[] l)
	{
		int len = l.length;
		int[] list = new int[len];
		System.arraycopy(l, 0, list, 0, len);
		Arrays.sort(list);
		return list[len / 2];
	}
}
