import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by benoi_000 on 4/16/2015.
 */
public class A {

    public static void main(String args[]) throws FileNotFoundException {
        final String defaultFile = A.class.getName()+".in";
        final PrintStream out;
        final InputStream in;
        if (args.length==0) {
            in = new FileInputStream("test/"+defaultFile);
            out =System.out;

        } else {
            in = new FileInputStream("resources/"+args[0]);
            out = new PrintStream(new FileOutputStream("result/"+args[0]));
        }
        Scanner scanner = new Scanner(in);
        int nbTest = scanner.nextInt();
        for (int i=0;i<nbTest;i++) {
            scanner.nextLine();
            int nb =scanner.nextInt();
            scanner.nextLine();
            List<Integer> data = new ArrayList<Integer>(nb);
            for(int j=0;j<nb;j++)
                data.add(scanner.nextInt());

            Object res = comput(data);
            out.println("Case #"+(i+1)+": "+res);
        }

    }

    public static String comput(List<Integer> data) {
        int first =0;
        int rate =0;
        int second =0;
        for (int i=1;i<data.size();i++) {
            int d =data.get(i-1)-data.get(i);
            if (d>0) {
                first+=d;
                rate = Math.max(rate,d);
            }
        }
        for (int i=0;i<data.size()-1;i++) {
            second += Math.min(rate,data.get(i));
        }
        return  first+" "+second;
    }
}
