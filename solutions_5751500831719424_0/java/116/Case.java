package r1b1;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Case
{
    private List<String> strings = new ArrayList<>();
    
    public Case(List<String> strings)
    {
        this.strings.addAll(strings);
    }
    
    @Override
    public String toString()
    {
        StringBuffer buffer = new StringBuffer();
        for (String s : strings)
        {
            buffer.append(s).append('\n');
        }
        return buffer.toString();
    }
    
    public String solve()
    {
        if (!check())
        {
            return "Fegla Won";
        }
        else
        {
            return findCount();
        }
    }
    
    private String findCount()
    {
        List<Character> chars = new ArrayList<>();
        char previous = '\0';
        for (char c : strings.iterator().next().toCharArray())
        {
            if (c != previous)
            {
                chars.add(c);
                previous = c;
            }
        }
        
        List<List<Integer>> counts = new ArrayList<>();
        for (String s : strings)
        {
            int i = 0;
            List<Integer> countsSubList = new ArrayList<>();
            for (char c : chars)
            {
                int count = 0;
                while (i < s.length() && s.charAt(i) == c)
                {
                    count++;
                    i++;
                }
                countsSubList.add(count);
            }
            counts.add(countsSubList);
        }
        
        int sum = 0;
        int index = 0;
        for (char c : chars)
        {
            sum += Math.abs(counts.get(0).get(index) - counts.get(1).get(index));
            index++;
        }
        
        return "" + sum;
    }
    
    private boolean check()
    {
        List<String> tmp = new ArrayList<>();
        for (String s : strings)
        {
            tmp.add(s.replaceAll("(.)\\1+", "$1"));
        }
        
        String first = tmp.iterator().next();
        for (String s : tmp)
        {
            if (!first.equals(s))
            {
                return false;
            }
        }
        
        return true;
    }
}
