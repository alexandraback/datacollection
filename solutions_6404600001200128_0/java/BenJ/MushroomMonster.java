package src;
import java.io.BufferedReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;


public class MushroomMonster
{
	public static void main(String [] args) throws IOException
	{
		List<String> text = readTextFile("Round1A/A-small-attempt0.in");
		
		int numCases = Integer.parseInt(text.remove(0));
		
		for(int i =  1; i <= numCases; i++)
		{
			int numIntervals = Integer.parseInt(text.remove(0));
			String[] intervals = text.remove(0).split(" ");
			
			
			
			// Print solution
			System.out.println("Case #" + i + ": " + MM(numIntervals, intervals));
		}
	}
	
	public static String MM(int numIntervals, String[] intervals)
	{
		int methodOne = 0;
		int methodTwo = 0;
		int maxDifference = 0;
		
		for(int i = 0; i < numIntervals - 1; i++)
		{
			int difference = Integer.parseInt(intervals[i]) - Integer.parseInt(intervals[i+1]);
			
			if(difference > 0)
				methodOne += difference;
			
			if(difference > maxDifference)
				maxDifference = difference;
		}
		for(int i = 0; i < numIntervals - 1; i++)
		{
			int current = Integer.parseInt(intervals[i]);
			methodTwo += current >= maxDifference ? maxDifference : current;
		}
		
		return methodOne + " " + methodTwo;
	}

	final static Charset ENCODING = StandardCharsets.UTF_8;
	
	static List<String> readTextFile(String filename) throws IOException
	{
		List<String> list = new ArrayList<>();
		
		Path path = Paths.get(filename);
		try (BufferedReader reader = Files.newBufferedReader(path, ENCODING)) {
			String line;
			while((line = reader.readLine()) != null) {
				list.add(line);
			}
		}
		return list;
	}
}
