import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class SenateEvacuation
{
    public static void main(String[] args)
    {
        try
        {
            File file = new File("input.txt");
            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            StringBuffer output = new StringBuffer();
            
            int lines = Integer.parseInt(bufferedReader.readLine());
            for(int i = 1; i <= lines; i++)
            {
            	int total = 0, max = 0, maxParty = 0;
            	int[] parties = new int[Integer.parseInt(bufferedReader.readLine())];
            	String[] input = bufferedReader.readLine().split(" ");
                for(int j = 0; j < input.length; j++)
                {
					parties[j] = Integer.parseInt(input[j]);
					total += parties[j];
					if(parties[j] > max)
					{
						maxParty = j;
						max = parties[j];
					}
                }

                output.append("Case #" + i + ":");
                if(total % 2 == 1)
                {
                	output.append(" " + (char)('A' + maxParty));
                	total--;
                	parties[maxParty]--;
                	maxParty = getMaxPos(parties);
                	max = parties[maxParty];
                }
                while(total > 0)
                {
                	output.append(" " + (char)('A' + maxParty));
                	total--;
                	parties[maxParty]--;
                	maxParty = getMaxPos(parties);
                	max = parties[maxParty];
                	output.append((char)('A' + maxParty));
                	total--;
                	parties[maxParty]--;
                	maxParty = getMaxPos(parties);
                	max = parties[maxParty];
                }
                output.append("\r\n");
            }
            fileReader.close();
            
            file = new File("output.txt");
            FileWriter fileWriter = new FileWriter(file);
            fileWriter.write(output.toString());
            fileWriter.flush();
            fileWriter.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
    
    public static int getMaxPos(int[] array)
    {
    	int max = 0, maxPos = 0;
    	for(int i = 0; i < array.length; i++)
    	{
    		if(array[i] > max)
    		{
    			maxPos = i;
    			max = array[i];
    		}
    	}
    	return maxPos;
    }
}