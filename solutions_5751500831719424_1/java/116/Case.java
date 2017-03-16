package r1b1;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import com.google.common.collect.Lists;

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
        
        int sum = 0;
        
        List<Integer> lastIndex = new ArrayList<>();
        for (int i = 0; i < strings.size(); ++i)
        {
            lastIndex.add(0);
        }
        
        for (int i = 0; i < chars.size(); ++i)
        {
            char currentChar = chars.get(i);
            List<Integer> counts = new ArrayList<>();
            for (int j = 0; j < strings.size(); ++j)
            {
                int index = lastIndex.get(j);
                int count = 0;
                String currentString = strings.get(j);
                while (index < currentString.length() && currentString.charAt(index) == currentChar)
                {
                    count++;
                    index++;
                }
                counts.add(count);
                lastIndex.set(j, index);
            }
            
            int minTotal = Integer.MAX_VALUE;
            for (int j = Collections.min(counts); j <= Collections.max(counts); ++j)
            {
                int total = 0;
                for (int k : counts)
                {
                    total += Math.abs(k - j);
                }
                
                if (total < minTotal)
                {
                    minTotal = total;
                }
            }
            
            sum += minTotal;
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
