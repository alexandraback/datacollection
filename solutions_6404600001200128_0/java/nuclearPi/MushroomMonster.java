import java.util.ArrayList;
import java.lang.System;
/**
 * Write a description of class MushroomMonster here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class MushroomMonster
{
    static String filename = "A-small-attempt1.in";
    static String outfilename = "MushroomMonsterResults" + System.currentTimeMillis() + ".txt";

    public static void main(String [] args)
    {
        System.out.print("a\f");
        Problem prob = HelperFunctions.getContentsOfFile(filename, 1, 2, 0);

        System.out.println();

        ArrayList<String> answers = new ArrayList<> (0);

        for(int a = 0; a < prob.cases.size(); a++)
        {
            ArrayList<Long> mushrooms = new ArrayList<> (0);
            
            String [] splitCase = prob.cases.get(a).get(1).split(" ");
            
            for(int b = 0; b < splitCase.length; b++) mushrooms.add(Long.parseLong(splitCase[b]));
            
            long result1 = 0, result2 = 0, numShrooms;
            
            numShrooms = mushrooms.size();
            
            for(int b = 0; b < numShrooms - 1; b++)
            {
                if(mushrooms.get(b) > mushrooms.get(b+1)) result1 += mushrooms.get(b) - mushrooms.get(b+1);
            }
            
            double rateOfConsumption = 0;
            for(int b = 0; b < numShrooms - 1; b++)
            {
                if(mushrooms.get(b) - mushrooms.get(b+1) > rateOfConsumption) rateOfConsumption = mushrooms.get(b) - mushrooms.get(b+1);
            }

            for(int b = 0; b < numShrooms - 1; b++)
            {
                if(mushrooms.get(b) > rateOfConsumption) result2 += rateOfConsumption;
                else result2 += mushrooms.get(b);
            }
            
            
            answers.add("" + result1 + " " + result2);
        }
        
        HelperFunctions.writeCasesToFile(outfilename, answers);
    }
}
