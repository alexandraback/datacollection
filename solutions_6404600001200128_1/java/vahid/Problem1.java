package round1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Problem1 {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("input.txt"));
        BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
        int n = input.nextInt();
        for (int counter = 1; counter <= n; counter++){
            int x = input.nextInt();
            int[] data = new int[x];
            for (int j=0; j<x; j++)
                data[j] = input.nextInt();
            output.write("Case #" + counter + ": " + solve1(data) + " " + solve2(data));
            output.newLine();
        }
        input.close();
        output.close();
    }

    private static int solve2(int[] data) {
        int result =0;

        int maxDif = findMaxDif(data);

        for (int i=0; i<data.length-1; i++)
            result += (data[i]<maxDif) ? data[i] : maxDif;

        return result;
    }

    private static int findMaxDif(int[] data) {
        int result = 0;
        for (int i=1; i< data.length; i++)
                result = (data[i-1] - data[i] > result) ? data[i-1] - data[i] : result;
        return result;
    }

    private static int solve1(int[] data) {
        int result =0;
        for (int i=1; i< data.length; i++)
            if (data[i]< data[i-1])
                result += data[i-1] - data[i];
        return result;
    }


}
