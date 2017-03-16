import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class Main {

    static class Pair {
        char a;
        int b;

        Pair(char a, int b) {
            this.a = a;
            this.b = b;
        }
    }

    static int solve(String []strings) {
        int n = strings.length;
        ArrayList<Pair> [] list = new ArrayList[n];
        for(int i=0;i<n;i++) {
            list[i] = new ArrayList<>();
            String s = strings[i];
            int j = 0;
            while (j < s.length()) {
                int k = j;
                while (k < s.length() && s.charAt(k)==s.charAt(j)) {
                    k++;
                }
                list[i].add(new Pair(s.charAt(j), k-j));
                j = k;
            }
        }
        int res = 0;
        for(int i = 1;i<n;i++) {
            if (list[i].size()!=list[0].size())return -1;
            for(int j=0;j<list[i].size();j++) {
                if (list[0].get(j).a!=list[i].get(j).a) {
                    return -1;
                }
            }
        }

        for(int i=0;i<list[0].size();i++) {
            int max = 0;
            for(int j=0;j<n;j++) {
                if (list[j].get(i).b > max) {
                    max = list[j].get(i).b;
                }
            }
            int cur = Integer.MAX_VALUE;
            for(int cnt=1;cnt<=max;cnt++) {
                int t = 0;
                for(int j=0;j<n;j++) {
                    t += Math.abs(list[j].get(i).b-cnt);
                }
                cur = Math.min(cur, t);
            }
            res += cur;
        }
        return res;


    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("input.txt"));
//        Scanner in = new Scanner(System.in);
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader(new File("input.txt")));
//        PrintWriter out = new PrintWriter(System.out);
        PrintWriter out = new PrintWriter(new File("output.txt"));

        int tc = in.nextInt();
        for(int t=1;t<=tc;t++) {
            int n = in.nextInt();
            String []ar =new String[n];
            for(int i=0;i<n;i++) {
                ar[i] = in.next();
            }
            out.print("Case #"+t+": ");
            int res = solve(ar);
            if (res==-1)out.println("Fegla won");
            else out.println(res);
        }

        in.close();
        out.close();
    }
}