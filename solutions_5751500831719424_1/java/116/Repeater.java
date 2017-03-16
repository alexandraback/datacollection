package r1b1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

public class Repeater
{
    public static void main(String[] args)
    throws Exception
    {
        File file = new File("src/r1b1/in.txt");
//        System.out.println(file.getAbsolutePath());
        FileReader fr = new FileReader(file);
        BufferedReader bufferedReader = new BufferedReader(fr);
        int count = Integer.parseInt(bufferedReader.readLine());
        for (int i = 0; i < count; ++i)
        {
            int strings = Integer.parseInt(bufferedReader.readLine());
            List<String> strs = new ArrayList<>(strings);
            for (int j = 0; j < strings; ++j)
            {
                strs.add(bufferedReader.readLine());
            }
            
            Case c = new Case(strs);
            System.out.println("Case #" + (i+1) + ": " +c.solve());
        }
    }
}
