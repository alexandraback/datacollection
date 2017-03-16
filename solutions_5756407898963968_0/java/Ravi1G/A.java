package A;

/*
code may be used from https://github.com/Ravi1G

 */

import java.io.*;
import java.util.*;

public class A {

    public static void main(String[] args) {

      // Reader in = new Reader();
      // Writer out = new Writer();



         Reader in = new Reader("asmall.in");
        Writer out = new Writer("asmalloutput.out");

    /*    Reader in = new Reader("alarge.in");
        Writer out = new Writer("alargeoutput.out");
    */


        int T = in.nextInt();


        for (int i = 0; i < T; i++) {

            int a1,a2;
            int a[] = new int[4];
            ArrayList<Integer> l1,l2 ;
            l1 = new ArrayList<Integer>();
            l2 = new ArrayList<Integer>();
            a1 = in.nextInt();

            for (int j = 1; j < 5; j++) {

                for (int k = 0; k < 4; k++) {
                    a[k] = in.nextInt();

                }


                if(j==a1)
                {
                   for (int z : a)
                   {
                       System.out.println(z);
                       l1.add(z);
                   }
                }
            }
            a2 = in.nextInt();
            for (int j = 1; j < 5; j++) {

                for (int k = 0; k < 4; k++) {
                    a[k] = in.nextInt();
                }

                if(j==a2)
                {
                    for (int z : a)
                    {
                        System.out.println(z);
                        l2.add(z);
                    }
                }
            }
            System.out.println(l1.toString());

            String result;
            l1.retainAll(l2);
            System.out.println(l1.toString());
            if(l1.size()==0)
            {
                result ="Volunteer cheated!";

            }else if(l1.size()==1)
            {
                result = String.valueOf(l1.get(0));
            }
            else {
                result = "Bad magician!";
            }

            out.println("Case #" + (i + 1) + ": " + result );
           // System.out.println("Case #" + (i + 1) + ": " + i );
        }


        out.close();

    }//Main -end



}



// for Fast IO

class Reader {
    private BufferedReader input;
    private StringTokenizer line = new StringTokenizer("");

    public Reader() {
        input = new BufferedReader(new InputStreamReader(System.in));
    }

    public Reader(String s) {
        try {
            input = new BufferedReader(new FileReader(s));
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void fill() {
        try {
            if(!line.hasMoreTokens()) line = new StringTokenizer(input.readLine());
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public double nextDouble() {
        fill();
        return Double.parseDouble(line.nextToken());
    }

    public String nextWord() {
        fill();
        return line.nextToken();
    }

    public int nextInt() {
        fill();
        return Integer.parseInt(line.nextToken());
    }

    public long nextLong() {
        fill();
        return Long.parseLong(line.nextToken());
    }

    public double readDouble() {
        double d = 0;
        try {
            d = Double.parseDouble(input.readLine());
        } catch(IOException io) {io.printStackTrace(); System.exit(0);}
        return d;
    }

    public int readInt() {
        int i = 0;
        try {
            i = Integer.parseInt(input.readLine());
        } catch(IOException io) {io.printStackTrace(); System.exit(0);}
        return i;
    }

    public int[] readInts(int n) {
        int[] a = new int[n];
        for(int i=0; i<n; i++)
            a[i] = nextInt();
        return a;
    }

    public void fillInts(int[] a) {
        for(int i=0; i<a.length; i++)
            a[i] = nextInt();
    }

    public long readLong() {
        long l = 0;
        try {
            l = Long.parseLong(input.readLine());
        } catch(IOException io) {io.printStackTrace(); System.exit(0);}
        return l;
    }

    public String readLine() {
        String s = "";
        try {
            s = input.readLine();
        } catch(IOException io) {io.printStackTrace(); System.exit(0);}
        return s;
    }
}

class Writer {

    private BufferedWriter output;

    public Writer() {
        output = new BufferedWriter(new OutputStreamWriter(System.out));
    }

    public Writer(String s) {
        try {
            output = new BufferedWriter(new FileWriter(s));
        } catch(Exception ex) { ex.printStackTrace(); System.exit(0);}
    }

    public void println() {
        try {
            output.append("\n");
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void print(Object o) {
        try {
            output.append(o.toString());
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void println(Object o) {
        try {
            output.append(o.toString()+"\n");
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void printf(String format, Object... args) {
        try {
            output.append(String.format(format, args));
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void printfln(String format, Object... args) {
        try {
            output.append(String.format(format, args)+"\n");
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void flush() {
        try {
            output.flush();
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }

    public void close() {
        try {
            output.close();
        } catch(IOException io) { io.printStackTrace(); System.exit(0);}
    }
}