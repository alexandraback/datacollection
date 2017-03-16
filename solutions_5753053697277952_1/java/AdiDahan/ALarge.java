package senate_evacuation;

import com.google.common.collect.Lists;

import java.util.List;
import java.util.Scanner;

/**
 * Created by Adi on 08/05/2016.
 * Guava Library is available online by Google :) - https://github.com/google/guava
 */
public class ALarge {

    public static final char A = 'A';

    private List<String> lstOutput = Lists.newArrayList();

    public ALarge()
    {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        for(int i=0; i < T; i++)
        {
            int N = in.nextInt();

            List<Integer> lstParties = Lists.newArrayList();
            String sOrder = "";

            for(int j=0; j < N ; j++)
            {
                lstParties.add(in.nextInt());
            }

            while(true)
            {
                int maxParty = getMaxParty(lstParties);
                if(maxParty == 0)
                {
                    break;
                }

                List<Integer> lstMatches = Lists.newArrayList();
                for(int j=0; j < N ; j++)
                {
                    if(lstParties.get(j) == maxParty)
                    {
                        lstMatches.add(j);
                    }
                }
                Integer index = lstMatches.get(0);
                Integer value = lstParties.remove((int) index);
                lstParties.add(index, value - 1);
                sOrder += " " + (char)(A+index);

                if(lstMatches.size() %2 == 0)
                {
                    index = lstMatches.get(1);
                    value = lstParties.remove((int) index);
                    lstParties.add(index, value - 1);
                    sOrder += (char)(A+index);
                }


            }

            lstOutput.add("Case #" + (i+1) + ":" + sOrder);
        }

        in.close();
    }

    private int getMaxParty(List<Integer> lstParties)
    {
        int max = 0;

        for(int i=0; i < lstParties.size() ; i++)
        {
            Integer currentMembers = lstParties.get(i);
            if(currentMembers > max)
            {
                max = currentMembers;
            }
        }

        return max;
    }

    public void printOutput()
    {
        for(String string : lstOutput)
        {
            System.out.println(string);
        }
    }

    public static void main(String[] args)
    {
        ALarge main = new ALarge();
        main.printOutput();
    }
}
