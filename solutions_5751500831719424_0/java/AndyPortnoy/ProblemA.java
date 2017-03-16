import java.lang.String;
import java.util.*;
import java.io.*;

public class ProblemA {
    final static String PROBLEM_NAME = "ProblemA";
    final static String WORK_DIR = "/home/adp4/GCJ/" + PROBLEM_NAME + "/";


    static void preprocess()
    {

    }

    int stepThrough(List<List<Pair>>input)
    {
        int moves = 0;
        int length = input.get(0).size();
        for (List<Pair> item : input)
        {
            if (item.size() != length)
            {
                return -1;
            }
        }

        for (int k = 0; k<length; k++)
        {
           Pair a = input.get(0).get(k);
           Pair b = input.get(1).get(k);
           if (a.aChar!=b.aChar)
           {
               return -1;
           }
           else
           {
               moves += Math.abs(a.count-b.count);
           }
        }

        return moves;
    }




    void solve(Scanner sc, PrintWriter pw) {
        List<List<Pair>> input = new ArrayList<List<Pair>>();
        int N = sc.nextInt();
        String garbage = sc.nextLine();
        for (int k = 0; k < N; k++)
        {
            String temp = sc.nextLine();
            List<Pair>parsed = new ArrayList<Pair>();
            char lastChar = '0';
            int count = 0;
            for (int i = 0; i < temp.length(); i++)
            {
                char cur = temp.charAt(i);
                if (cur == lastChar)
                {
                    count++;
                }
                else
                {
                    if (count != 0)
                    {
                        parsed.add(new Pair(count, lastChar));
                    }
                    lastChar = cur;
                    count = 1;
                }
            }
            parsed.add(new Pair(count, lastChar));
            input.add(parsed);
        }
        int moves = stepThrough(input);
        if (moves == -1)
        {
            pw.print("Fegla Won");
        }
        else
        {
            pw.print(moves);
        }
        pw.println();
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        String infile;
        String outfile;

        if(args.length<2)
        {
            System.out.println("Defaulting to input.txt and output.txt");
            infile = "input.txt";
            outfile = "output.txt";
        }
        else
        {
            System.out.println("Input = "+args[0]);
            System.out.println("Output = "+args[1]);
            infile = args[0];
            outfile = args[1];
        }

        Scanner sc = new Scanner(new FileReader(WORK_DIR + infile));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + outfile));
        int caseCnt = sc.nextInt();
        sc.nextLine();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            new ProblemA().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }




    public class Pair
    {
        public int count;
        public char aChar;
        public Pair(int c, char a)
        {
            count = c;
            aChar = a;
        }

    }
}