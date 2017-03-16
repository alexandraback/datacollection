import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by Aaron on 5/8/2016.
 */
public class Problem1C {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C:\\Users\\Aaron\\IdeaProjects\\CodeJam1C\\src\\inputAsmall.txt"));
        String numcases = in.nextLine();
        Problem1C problem1 = new Problem1C();
        //ArrayList<String> cases = new ArrayList<>();
        String[][] cases = new String[Integer.parseInt(numcases)][2];
        int counter = 0;
        while (in.hasNextLine()) {
            cases[counter][0] = in.nextLine();
            cases[counter][1] = in.nextLine();
            ++counter;
        }
        int casecounter = 1;
        PrintWriter out = new PrintWriter(new File("C:\\Users\\Aaron\\IdeaProjects\\CodeJam1C\\src\\output.txt"));
        for(String[] word : cases) {
            out.println("Case #"+casecounter+": "+problem1.getAnswer(word));
            ++casecounter;
        }
        out.flush();
        out.close();
    }
    public String getAnswer(String[] parties) {
        String abc = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
        String[] alphabet = abc.split("\\s+");
        String[] senators;
        senators = parties[1].split("\\s+");
        int[] senatorcount = new int[Integer.parseInt(parties[0])];
        int counter = 0;
        int total_senators = 0;
        for(String senator : senators) {
            senatorcount[counter] = Integer.parseInt(senator);
            total_senators += senatorcount[counter];
            ++counter;
        }
        int majority_index = 0;
        int rescued_senators = 0;
        String output = "";
        while (rescued_senators != total_senators) {
            for (int i = 0; i < senatorcount.length; i++) {
                if (senatorcount[i] > senatorcount[majority_index]) {
                    majority_index = i;
                }
            }
            senatorcount[majority_index] -= 1;
            output += alphabet[majority_index];
            majority_index = 0;
            ++rescued_senators;
            if(total_senators - rescued_senators != 2) {
                for(int i = 0; i < senatorcount.length; i++) {
                    if (senatorcount[i] > senatorcount[majority_index]) {
                        majority_index = i;
                    }
                }
                senatorcount[majority_index] -= 1;
                output += alphabet[majority_index]+" ";
                majority_index = 0;
                ++rescued_senators;
            }
            else {
                output += " ";
            }
        }
        return output;
    }
}
