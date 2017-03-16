/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;
import java.util.*;
import java.lang.*;
/**
 *
 * @author Tom
 */
public class TheRepeater {
    private String[] strings;
    
    public static TheRepeater[] readFile(Scanner input) {
        TheRepeater[] puzzles = new TheRepeater[input.nextInt()];
        
        for(int i = 0; i < puzzles.length; ++i) {
            String[] strings = new String[input.nextInt()];
            input.nextLine();
            for(int j = 0; j < strings.length; ++j) {
                strings[j] = input.nextLine();
            }
            puzzles[i] = new TheRepeater(strings);
        }
        
        return puzzles;
    }
    
    private TheRepeater(String [] strings) {
        this.strings = strings;
    }
    
    public String solve() {
        int result = 0;
        boolean done = false;
        int[] indexes = new int[strings.length];
        while(!done) {
            if(indexes[0] == strings[0].length()) {
                done = true;
                for(int i = 0; i < strings.length; ++i) {
                    if(indexes[i] != strings[i].length()) {
                        return "Fegla Won";
                    }
                }
            } else {
                char character = strings[0].charAt(indexes[0]);
                int[] count = new int[strings.length];
                int max = 0;
                
                for(int i = 0; i < strings.length; ++i) {
                    if(indexes[i] == strings[i].length() || strings[i].charAt(indexes[i]) != character) {
                        return "Fegla Won";
                    }
                    
                    for(;indexes[i] < strings[i].length() && strings[i].charAt(indexes[i]) == character; ++indexes[i]) {
                        ++count[i];
                    }
                    
                    max = Math.max(max, count[i]);
                }
                int min = Integer.MAX_VALUE;
                
                for(int i = 1; i <= max; ++i) {
                    int score = 0;
                    for(int j = 0; j < count.length; ++j) {
                        if(i < count[j]) {
                            score += count[j] - i;
                        } else {
                            score += i - count[j];
                        }
                    }
                    min = Math.min(min, score);
                }
                
                result += min;
            }
        }

        return "" + result;
    }
}
