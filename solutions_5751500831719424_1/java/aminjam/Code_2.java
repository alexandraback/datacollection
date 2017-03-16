import java.io.*;
import java.util.*;

public class Code_2 {
    public static final String problem = "AS0";
    public static final String path = "C:\\Users\\amina\\Downloads\\";

    public static void main(String[] args) throws IOException {
        System.out.println("Problem:\t" + problem);
        Scanner sc;
        PrintWriter pw = new PrintWriter(new FileWriter("src\\output.txt"));
        switch (problem.substring(0, 2)) {
        case "AS": {
            String inf = path + "A-small-attempt" + problem.charAt(2) + ".in";
            sc = new Scanner(new FileReader(inf));
            main_A(sc, pw);
            break;
        }
        case "AL": {
            String inf = path + "A-large.in";
            sc = new Scanner(new FileReader(inf));
            main_A(sc, pw);
            break;
        }
        case "BS": {
            String inf = path + "B-small-attempt" + problem.charAt(2) + ".in";
            sc = new Scanner(new FileReader(inf));
            main_B(sc, pw);
            break;
        }
        case "BL": {
            String inf = path + "B-large.in";
            sc = new Scanner(new FileReader(inf));
            main_B(sc, pw);
            break;
        }
        case "CS": {
            String inf = path + "C-small-attempt" + problem.charAt(2) + ".in";
            sc = new Scanner(new FileReader(inf));
            main_C(sc, pw);
            break;
        }
        case "CL": {
            String inf = path + "C-large.in";
            sc = new Scanner(new FileReader(inf));
            main_C(sc, pw);
            break;
        }
        case "DS": {
            String inf = path + "D-small-attempt" + problem.charAt(2) + ".in";
            sc = new Scanner(new FileReader(inf));
            main_D(sc, pw);
            break;
        }
        default: {
            String inf = path + "D-large.in";
            sc = new Scanner(new FileReader(inf));
            main_D(sc, pw);
            break;
        }
        }
        sc.close();
        pw.close();
    }

    public static void main_A(Scanner sc, PrintWriter pw) throws IOException {
        int T=sc.nextInt();
       
        mainloop: for(int cn=1;cn<=T;cn++) {
            System.out.println("Case:\t" + cn);

            pw.println("Case #" + cn + ": sth");
        }
    }
    
    public static void main_B(Scanner sc, PrintWriter pw) throws IOException
    {
        int T=sc.nextInt();
        
        mainloop: for(int cn=1;cn<=T;cn++) {
            System.out.println("Case:\t" + cn);

            pw.println("Case #" + cn + ": sth");
        }
    }

    public static void main_C(Scanner sc, PrintWriter pw) throws IOException {
        int T=sc.nextInt();
       
        mainloop: for(int cn=1;cn<=T;cn++) {
            System.out.println("Case:\t" + cn);

            pw.println("Case #" + cn + ": sth");
        }
    }

    public static void main_D(Scanner sc, PrintWriter pw) throws IOException {
        int T=sc.nextInt();
       
        mainloop: for(int cn=1;cn<=T;cn++) {
            System.out.println("Case:\t" + cn);

            pw.println("Case #" + cn + ": sth");
        }
    }
}
