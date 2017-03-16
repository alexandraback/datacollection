import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {

    //
    // boilerplate
    //
    static String path = "/Users/liwen/Downloads/";
    static String fname = "A-small-attempt0";

    static BufferedWriter bw;
    static BufferedReader br;

    public static void init() throws IOException {
        br = new BufferedReader(new FileReader(path + fname + ".in"));
        bw = new BufferedWriter(new FileWriter(path + fname + ".txt"));

      //  br = new BufferedReader(new InputStreamReader(System.in));
       // bw = new BufferedWriter(new OutputStreamWriter(System.out));

    }


    ///////////////////////////////////
    // code starts from here
    //

    public static String getDistinct(String str) {
        String res = "";

        char prev = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (i == 0) {
                res += str.charAt(i);
                prev = str.charAt(i);
            } else {
                if (str.charAt(i) == prev) {
                    continue;
                } else {
                    res += str.charAt(i);
                    prev = str.charAt(i);
                }
            }
        }

        return res;
    }

    public static int[] getCnts(String str, int len) {
        char prev = 0;
        int bufCnt =  0;
        int [] cnts = new int[len];
        int pos = 0;

        for (int i = 0; i < str.length(); ++i) {
            if (i == 0) {
                prev = str.charAt(i);
                bufCnt = 1;
            } else {
                if (str.charAt(i) == prev) {
                    bufCnt += 1;
                } else {
                    cnts[pos++] = bufCnt;
                    prev = str.charAt(i);
                    bufCnt = 1;
                }
            }
        }

        if (bufCnt > 0) {
            cnts[pos++] = bufCnt;
        }

        return cnts;
    }

    public static int checkAll(String [] arr, int n) throws IOException{
        String std = "";
        for (int i = 0; i < arr.length; ++i) {
            String dict = getDistinct(arr[i]);
            if (i == 0)
                std = dict;
            else {
                if (!dict.equals(std)) {
                    return -1;
                }
            }
        }

        int A[][] = new int[n][std.length()];

        for (int i = 0; i < arr.length; ++i) {
            A[i] = getCnts(arr[i], std.length());
        }

        int tot = 0;
        for (int i = 0; i < std.length(); i++) {
            int curMin = 0;
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    cnt += Math.abs(A[j][i] - A[k][i]);
                }
                if (j == 0 || cnt < curMin) {
                    curMin = cnt;
                }
            }
            tot += curMin;
        }

        return tot;
    }


    //
    // code ends here
    //////////////////////////////////

    public static void main(String[] args) throws IOException {
        //
        // boilerplate
        //

        init();

        int N = Integer.parseInt(br.readLine());

        ///////////////////////////////////
        // code starts here
        //
        int n;


        //
        // code ends here
        //////////////////////////////////


        for (int l = 1; l <= N; ++l) {
            bw.write("Case #" + l + ":");
            /////////////////////////////////////
            /// code starts here
            ///
            n = Integer.parseInt(br.readLine());
            String [] arr = new String[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = br.readLine();
            }

            int res = checkAll(arr, n);

            if (res < 0)
                bw.write(" Fegla Won\n");
            else
                bw.write(" " + res+ "\n");
            ///
            /// code ends here
            ////////////////////////////////////

        }

        bw.close();
    }
}
