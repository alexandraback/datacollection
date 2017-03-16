import java.util.ArrayList;
/**
 * Write a description of class Haircut here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Haircut
{
    static String filename = "B-small-attempt2.in";
    static String outfilename = "HaircutResults" + System.currentTimeMillis() + ".txt";

    public static void main(String [] args)
    {        
        System.out.print("a\f");
        Problem prob = HelperFunctions.getContentsOfFile(filename, 1, 2, 0);

        System.out.println();

        ArrayList<String> answers = new ArrayList<> (0);

        for(int a = 0; a < prob.cases.size(); a++)
        {
            System.out.println("Case: " + (a+1));

            ArrayList<Long> barbers = new ArrayList<> (0);
            ArrayList<Long> barbersTimesRemaining = new ArrayList<> (0);

            String [] splitCase = prob.cases.get(a).get(0).split(" ");

            Long place = Long.parseLong(splitCase[1]);
            Long result = new Long(0);

            splitCase = prob.cases.get(a).get(1).split(" ");

            for(int b = 0; b < splitCase.length; b++) 
            {
                barbers.add(Long.parseLong(splitCase[b]));
                barbersTimesRemaining.add(new Long(0));
            }
            
            Long lcm = LCM(barbers);
            Long cyclesPerLCM = new Long(0);
            for(int b = 0; b < splitCase.length; b++)
            {
                cyclesPerLCM += lcm/barbers.get(b);
            }
            
            double increase = Math.sqrt(place);
            Long cyclesPerLCMBig = new Long((long)increase*cyclesPerLCM);
            
            while(place > cyclesPerLCMBig) place -= cyclesPerLCMBig;

            while(place > cyclesPerLCM) place -= cyclesPerLCM;
            
            boolean repeat = true;
            while(repeat)
            {
                for(int b = 0; b < splitCase.length; b++)
                {
                    if(barbersTimesRemaining.get(b) == 0)
                    {
                        barbersTimesRemaining.set(b, barbers.get(b));
                        place--;
                        if(place == 0)
                        {
                            result = new Long(b+1);
                            repeat = false;
                            break;
                        }
                    }
                    barbersTimesRemaining.set(b, new Long(barbersTimesRemaining.get(b)-1));
                }
            }

            answers.add("" + result);
        }

        HelperFunctions.writeCasesToFile(outfilename, answers);
    }

    public static Integer GCD(Integer a, Integer b)
    {
        if (b==0) return a;
        return GCD(b,a%b);
    }

    public static Long LCM(ArrayList<Long> nums)
    {
        Long result = nums.get(0);
        for(int i = 1; i < nums.size(); i++) result = new Long(result*nums.get(i)/GCD(new Integer(result.toString()), new Integer(nums.get(i).toString())));
        return result;
    }
}
