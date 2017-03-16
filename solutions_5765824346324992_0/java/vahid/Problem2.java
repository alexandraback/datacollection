/*
 * (C) 2015 National Australia Bank
 * <p/>
 * [All rights reserved]. This product and related documentation are protected
 * by copyright restricting its use, copying, distribution, and decompilation.
 * No part of this product or related documentation may be reproduced in any
 * form by any means without prior written authorization of
 * National Australia Bank. Unless otherwise arranged, third parties may not
 * have access to this product or related documents.
 */
package round1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Scanner;

public class Problem2 {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("input.txt"));
        BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
        int n = input.nextInt();
        for (int counter = 1; counter <= n; counter++){
            System.out.println(counter);
            int b = input.nextInt();
            int k = input.nextInt();
            int[] times = new int[b];
            for (int j=0; j<b; j++)
                times[j] = input.nextInt();

            output.write("Case #" + counter + ": " + solve(k, times));
            output.newLine();
        }
        input.close();
        output.close();
    }

    private static long solve(long n, int[] times) {
 /*       BigDecimal cutsPerUnit = new BigDecimal(0);

        for (int i=0; i< times.length; i++)
            cutsPerUnit = cutsPerUnit.add(new BigDecimal(1).divide(new BigDecimal(times[i])));

        int toCutted = (n-times.length > 0) ? n-times.length : 0;

        return 0;*/


        ArrayList<Integer> list = new ArrayList<>(10000);

        int mult = times[0];
        for (int i=1; i<times.length; i++)
            mult *= times[i];

        for (int i= 0; i<mult; i++){
            for (int j=0; j<times.length; j++)
                if (i% times[j] == 0)
                    list.add(j+1);
        }

        n = (n-1) % list.size();
        return list.get((int)n);

    }
}
