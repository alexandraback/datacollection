package com.rocketfuel.kamran;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/**
 * Hello world!
 *
 */
public class App
{
    BufferedReader br;
    BufferedWriter bw;

    public static final int MAX_SIZE = 1000001;
    public static int[] ANS = new int[MAX_SIZE+3];

    public App(BufferedReader br, BufferedWriter bw) {
        this.br = br;
        this.bw = bw;
    }

    public static int popcount(int num) {
        int ans = 0;
        while (num > 0) {
            num = num&(num-1);
            ++ans;
        }
        return ans;
    }

    public static boolean inside(int r, int c) {
        return r>=0 && c>=0;
    }

    public void run() throws IOException {

        int T = Integer.parseInt(br.readLine());

        for (int ts=1; ts<=T; ++ts) {
            String line = br.readLine();
            String[] args = line.split(" ");
            int R = Integer.parseInt(args[0]);
            int C = Integer.parseInt(args[1]);
            int N = Integer.parseInt(args[2]);

            int size = R*C;
            int[][] oc = new int[R][C];
            int ans = R*C*4;
            for (int mask=0; mask<(1<<size); ++mask) {
                if (popcount(mask) == N) {
                    int curans = 0;
                    for (int i=0; i<R; ++i) {
                        for (int j=0; j<C; ++j) {
                            oc[i][j] = 0;
                        }
                    }
                    for (int i=0; i<size; ++i) {
                        if ((mask&(1<<i)) > 0) {
                            int r = i / C;
                            int c = i % C;
                            oc[r][c] = 1;
                            if (inside(r-1,c) && oc[r-1][c]==1)
                                curans++;
                            if (inside(r,c-1) && oc[r][c-1]==1)
                                curans++;
                        }
                    }
                    ans = Math.min(ans, curans);
                }
            }
            String ansStr = "Case #" + ts + ": " + ans + "\n";
            bw.write(ansStr);
            bw.flush();
        }
        br.close();
        bw.close();
    }

    public static void main( String[] args )
    {
        BufferedReader br = null;
        BufferedWriter bw = null;
        if (System.getProperty("input.stdin").equals("true")) {
            br = new BufferedReader(new InputStreamReader(System.in));
            bw = new BufferedWriter(new PrintWriter(System.out));
        } else {
            ClassLoader classLoader = App.class.getClassLoader();
            try {
                br = new BufferedReader(new FileReader(
                        new File(classLoader.getResource("1.txt").getFile())));
                bw = new BufferedWriter(new FileWriter(
                        new File("src/main/resources/2.txt")
                ));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {

            }
        }
        try {
            new App(br, bw).run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
