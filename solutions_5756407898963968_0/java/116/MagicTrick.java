package problem1;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import net.lab0.tools.FileUtils;

public class MagicTrick
{
    public static void main(String[] args)
    throws IOException
    {
        String in = args[0];
        
        // System.out.println("Using " + new File(in).getAbsolutePath());
        List<String> text = FileUtils.readFileAsText(new File(in));
        int count = Integer.parseInt(text.get(0));
        List<Case> cases = new ArrayList<>();
        for (int i = 0; i < count; ++i)
        {
            List<String> lines = text.subList(1 + i * 10, 1 + (i + 1) * 10);
            Case c = new Case(lines);
            cases.add(c);
//            System.out.println(c);
            System.out.println("Case #" + (i + 1) + ": " + c.getResult());
        }
    }
}
