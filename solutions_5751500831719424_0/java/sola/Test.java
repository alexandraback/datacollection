package test2;
import java.io.*;
import java.util.*;

public class Test {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    
    public static void main (String[] args) throws IOException {

        //generateInput(100);
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "test.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "test.out"));

        
        int tc = sc.nextInt();
        
        for (int tci=1;tci<=tc;tci++) {
            int N = sc.nextInt();
            int[][] strings = new int[N][100];
            char[] base = new char[100];
            int[] buffer = new int[100];
            //int[] solution = new int[100];
            //Arrays.fill(solution,0);
            String s = sc.next();
            int c = -1;
            for (int j=0;j<s.length();j++) {
                if (j==0||s.charAt(j)!=base[c]) {
                   c++;
                   base[c] = s.charAt(j);
                }
                strings[0][c]++;
            }
            int l = c+1;
            boolean impos = false;
            for (int i=1;i<N && !impos;i++) {
                s = sc.next();
                c = 0;
                for (int j=0;j<s.length();j++) {
                    if (s.charAt(j)==base[c]) {
                       strings[i][c]++;
                    }
                    else {
                        if (j==0) {
                            impos = true;
                            break;
                        }
                        c++;
                        if (c>=l||s.charAt(j)!=base[c]) {
                            impos = true;
                            break;
                        }
                        else {
                            strings[i][c]++;
                        }
                    }
                }
                if (c+1<l) {
                    impos = true;
                    break;
                }
            }
            if (impos) {
                pw.println("Case #" + tci + ": Fegla Won");
            }
            else {
                int ans = 0; 
                for (int i=0;i<l;i++) {
                    Arrays.fill(buffer,1000);
                    for (int j=0;j<N;j++) {
                        buffer[j] = strings[j][i];
                    }
                    Arrays.sort(buffer);
                    int mid = buffer[N/2];
                    for (int j=0;j<N;j++) {
                        ans += Math.abs(mid-buffer[j]);
                    }
                }
                
                pw.println("Case #" + tci + ": " + ans);
            }
        }
        pw.close();
        sc.close();
    }

    
    public static void generateInput(int tc) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "test.in"));
        pw.print(tc);
        Random rd = new Random();
        for (int tci = 1; tci <= tc; tci++) {
            pw.println();
            int N = rd.nextInt(1001);
            pw.println(N);
            for (int i=0;i<N;i++) {
                pw.print(rd.nextFloat()+" ");
            }
            pw.println();
            for (int i=0;i<N;i++) {
                pw.print(rd.nextFloat()+" ");
            }
            pw.println();
        }
        pw.close();
    }
}
