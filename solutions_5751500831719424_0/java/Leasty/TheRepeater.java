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
        int min = Integer.MAX_VALUE;
        
        for(int i = 0; i < strings.length; ++i) {
            System.out.println("--------------");
            String goal = strings[i];
            int result = 0;
            boolean possible = true;
            for(int j = 0; j < strings.length && possible; ++j) {
                
                if(i != j) {
                    System.out.println("================" + i + " " + j);
                    String change = strings[j];
                    int goalIndex = 0;
                    int changeIndex = 0;
                    while(goalIndex != goal.length() && changeIndex != change.length() && possible) {
                        if(goal.charAt(goalIndex) == change.charAt(changeIndex)) {
                            int countGoal = 0;
                            int countChange = 0;
                            char character = goal.charAt(goalIndex);
                            for(; goalIndex < goal.length() && goal.charAt(goalIndex) == character; ++goalIndex) {
                                ++countGoal;
                            }
                            
                            for(; changeIndex < change.length() && change.charAt(changeIndex) == character; ++changeIndex) {
                                ++countChange;
                            }
                            
                            if(countGoal < countChange) {
                                result += countChange - countGoal;
                            } else {
                                result += countGoal - countChange;
                            }
                        } else {
                            System.out.println(goalIndex + " " + changeIndex);
                            return "Fegla Won";
                        }
                    }
                    
                    if(goalIndex != goal.length() || changeIndex != change.length()) {
                        return "Fegla Won";
                    }
                }
            }
            
            min = Math.min(min, result);
        }
        
        return "" + min;
    }
}
