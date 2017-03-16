import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

import com.google.common.collect.HashMultimap;
import com.google.common.collect.SetMultimap;


public class A 
{
    private BufferedReader reader;
    private BufferedWriter writer;
    
    /**
     * @param args
     */
    public static void main(String[] args)
    {
        A a = new A(args[0]);
        a.executeTests();
    }
    

    public A(String filename)
    {
        // Open file
        File file = new File(filename);
        try
        {
            reader = new BufferedReader(new FileReader(file));
            writer = new BufferedWriter(new FileWriter(file+".out"));
        }
        catch (IOException e)
        {
            // Failed to open new buffered reader
            System.err.println("Failed to open FileReader");
            e.printStackTrace();
            System.exit(-1);
        }
    }
    
    private void executeTests()
    {
        // Read number of test cases
        int numberOfTests = 0; 
        
        try
        {
            // Read number of tests (first line)
            numberOfTests = Integer.parseInt(reader.readLine());
        }
        catch (NumberFormatException | IOException e)
        {
            // Failed to read a line
            System.err.println("Failed to read a line");
            e.printStackTrace();
            System.exit(-1);
        }

        for (int testCase = 1; testCase <= numberOfTests; testCase++)
        {
        	SetMultimap<Integer, Integer> first = HashMultimap.create();
        	SetMultimap<Integer, Integer> second = HashMultimap.create();
        	Integer firstGuess;
        	Integer secondGuess;
            
        	
            try
            {
            	firstGuess = Integer.parseInt(reader.readLine());
            	
            	// Grab and parse next test case                                
                for (int r = 1; r <= 4; r++)
                {
                    String[] input = reader.readLine().split(" ");
                    
                    for (String s : input)
                    {
                    	first.put(r, Integer.parseInt(s));
                    }
                }
                
                secondGuess = Integer.parseInt(reader.readLine());
                
                for (int r = 1; r <= 4; r++)
                {
                    String[] input = reader.readLine().split(" ");
                    
                    for (String s : input)
                    {
                    	second.put(r, Integer.parseInt(s));
                    }
                }
                

            	Set<Integer> firstFiltered = first.get(firstGuess);
            	Set<Integer> secondFiltered = second.get(secondGuess);
                Set<Integer> answers = new HashSet<>();
            	
            	
                for (Integer i : firstFiltered)
                {
                	if (secondFiltered.contains(i))
                	{
                		answers.add(i);
                	}
                }
            	
                String response;
                
                if (answers.isEmpty())
                {
                	response = "Volunteer cheated!";
                }
                else if (answers.size() > 1)
                {
                	response = "Bad magician!";
                }
                else
                {
                	response = answers.iterator().next().toString();
                }
                
                
                writer.write("Case #" + testCase + ": " + response + '\n');
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }
        
        try
        {
            reader.close();
            writer.flush();
            writer.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}

