
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author bachu
 */
public class senate {
    
    public static void main(String args[]) throws FileNotFoundException{
        Scanner scan = new Scanner(new File("senate.in"));
        PrintWriter writer = new PrintWriter(new File("senate.out"));
        int cases = scan.nextInt();
        for (int i = 0; i < cases; i++) {
            int n = scan.nextInt();
            int nums[] = new int[n];
            int tot=0;
            for (int j = 0; j < n; j++) {
                int asd = scan.nextInt();
                tot+=asd;
                nums[j] = asd;
            }
            writer.write(String.format("Case #%d: %s%n", i+1, result(nums, tot)));
        }
        writer.close();
    }
    
    static String atos(int nums[]) {
        String result = "";
        for (int i = 0; i < nums.length; i++) {
            result += "" + nums[i] + " ";
        }
        return result;
    }
    
    static String result(int nums[], int total) {
        if (!valid(nums, total)) {
            return "invalid";
        }
        if (total == 0) {
            return "";
        }
        
        int max1 = nums[0];
        int max2 = max1;
        int max1i = 0;
        int max2i = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= max1) {
                max2 = max1;
                max2i = max1i;
                max1i = i;
                max1 = nums[i];
            }
            else if (nums[i] >= max2) {
                max2 = nums[i];
                max2i = i;
            }
        }
        int numsOriginal[] = new int[nums.length];
        int numsOriginal2[] = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            numsOriginal[i] = nums[i];
            numsOriginal2[i] = nums[i];
        }
        nums[max1i] -= 2;
        String pos = itoc(max1i) + "" + itoc(max1i) + " " + result(nums, total - 2);
        if (!pos.endsWith("invalid")) {
            return pos;
        }
        nums = numsOriginal;
        nums[max1i]--;
        nums[max2i]--;
        pos = itoc(max1i) + "" + itoc(max2i) + " " + result(nums, total - 2);
        if (!pos.endsWith("invalid")) {
            return pos;
        }
        nums = numsOriginal2;
        nums[max1i]--;
        pos = itoc(max1i) + " " + result(nums, total - 1);
        return pos;
    }
    
    static char itoc(int i) {
        return (char) ('A'  + (char)i);
    }
    
    static boolean valid(int nums[], int total) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > total / 2 || nums[i] < 0) {
                return false;
            }
        }
        return true;
    }

}
