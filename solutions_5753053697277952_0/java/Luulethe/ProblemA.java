package com.google.round1c;

import java.io.*;
import java.util.*;

/**
 * Created by luult on 4/9/2016.
 */
public class ProblemA
{
    static String inputPath = "D:\\contest\\trainning\\round1c\\src\\main\\java\\com\\google\\round1c\\A-small-attempt1.in";
    static String outputPath = "D:\\contest\\trainning\\round1c\\src\\main\\java\\com\\google\\round1c\\a.out";
    static Scanner in;
    static BufferedWriter bw;
    static int numberTest;


    static Integer n, m;
    static String s = "";
    static String result = "";
    static int sum;
    static List<Party> partyList;

    public static void main(String[] args) throws IOException
    {
        bw = new BufferedWriter(new FileWriter(outputPath));
        in = new Scanner(new BufferedReader(new FileReader(inputPath)));

        numberTest = in.nextInt();
        for (int i = 0; i < numberTest; i++)
        {
            System.out.println("test :" + (i + 1));
            readInput();
            process();
            writeOutput(i);
        }

        bw.close();
    }

    private static void readInput()
    {
        n = in.nextInt();
        partyList = new ArrayList<Party>();
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            int numberSetator = in.nextInt();
            sum += numberSetator;
            Party party = new Party(numberSetator, (((char) ('A' + i))));
            partyList.add(party);
        }
    }


    private static void process()
    {
        result = "";
        while (sum > 0)
        {
            Collections.sort(partyList);
            result += partyList.get(0).name;
            partyList.get(0).senators--;
            sum--;

            if (checkToRemove(1, sum))
            {
                if (partyList.get(1).senators > 0)
                {
                    result += partyList.get(1).name;
                    partyList.get(1).senators--;
                    sum--;
                }
            }

            result += " ";
            for (Party party : partyList)
                if (party.senators > sum / 2)
                {
                    System.out.println("errrrrrrrrr");
                }
        }
    }

    private static boolean checkToRemove(int x, int sum)
    {
        int temp = partyList.get(x).senators;
        sum--;
        temp--;
        if (temp > sum / 2)
        {
            return false;
        }
        int index = 0;
        for (Party party : partyList)
        {
            if (index != x)
            {
                if (party.senators > sum / 2)
                {
                    return false;
                }
            }
            index++;
        }
        return true;
    }


    private static void writeOutput(int i) throws IOException
    {
        String result1 = "Case #" + (i + 1) + ": " + result + "\n";
        bw.write(result1);
    }
}
