import java.io.*;
import java.util.*;

public class Test3 {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    
    public static void main (String[] args) throws IOException {

        //generateInput(100);
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "3.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "3.out"));

        int tc = sc.nextInt();
        
        for (int tci=1;tci<=tc;tci++) {
            int ans1 = sc.nextInt()-1;
            int[][] arr1 = new int[4][4];
            for (int i=0;i<4;i++) {
                for (int j=0;j<4;j++) {
                    arr1[i][j] = sc.nextInt();
                }
            }
            
            int ans2 = sc.nextInt()-1;
            int[][] arr2 = new int[4][4];
            for (int i=0;i<4;i++) {
                for (int j=0;j<4;j++) {
                    arr2[i][j] = sc.nextInt();
                }
            }
            
            int cnt = 0;
            int card = 0;
            for (int i=0;i<4;i++) {
                for (int j=0;j<4;j++) {
                    if (arr1[ans1][i]==arr2[ans2][j]) {
                        card = arr1[ans1][i];
                        cnt++;
                    }
                }
            }
            String ans;
            if (cnt==1) {
                ans = ""+card;
            }
            else if (cnt==0) {
                ans = "Volunteer cheated!";
            }
            else {
                ans = "Bad magician!";
            }
            pw.println("Case #" + tci + ": " + ans);
        }
        pw.close();
        sc.close();
    }

    public static void generateInput(int tc) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "3.in"));
        int maxL = 1000000;
        pw.print(tc);
        Random rd = new Random();
        for (int tci = 1; tci <= tc; tci++) {
            pw.println();
            int l = rd.nextInt(maxL);
            int n = rd.nextInt(l);
            String s = "";
            for (int i = 0; i < l; i++) {
                s += (char) rd.nextInt('a' + 26);
            }
            pw.println(s + " " + n);
        }
        pw.close();
    }
}
