import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Locale;
import java.util.Scanner;

public class B {
    Scanner input;
    PrintWriter output;

    public B(Scanner input, PrintWriter output){
        this.input = input;
        this.output = output;
    }

    public void solveProblem(int testCase){
//        System.out.println("Test case: " + testCase);
        int rows = input.nextInt();
        int columns = input.nextInt();
        int tenants = input.nextInt();
        int rooms = rows * columns;
        int filledWithoutAngryness = rooms / 2 + rooms % 2; // tenant in every other room, no walls touch
        int maxUnhappiness = Integer.MAX_VALUE;
        boolean oddRowsAndColumns =((rows * columns) % 2) == 1;
        if(filledWithoutAngryness >= tenants){
//            System.out.println("no unhappiness");
            output.println("Case #" + testCase + ": 0");
            return;
        }
        if(filledWithoutAngryness < tenants){
//            System.out.println("normal filling");
            int unhappyTenants = tenants - filledWithoutAngryness;
//            System.out.println("rooms to fill: " + unhappyTenants);
            int unhappiness = 0;

            // fill corners first (unhappiness + 2 per tenant)
            int corners = oddRowsAndColumns ? 0 : 2; // we fill all corners if rows and columns are odd.
            int cornerTenants = Math.min(unhappyTenants, corners);
//            System.out.println("tenants in corners: " + cornerTenants);
            unhappiness += cornerTenants;
            unhappyTenants -= cornerTenants;

            // fill sides (unhappiness + 3 per tenant)
            int sideFields = oddRowsAndColumns ? rows - 2 : (rows / 2) + ((rows - 1) / 2); // 2 * rows / 2, exclude corners (already filled)
            sideFields += oddRowsAndColumns ? columns - 2 : (columns / 2) + ((columns - 1) / 2); // 2 * rows / 2, exclude corners (already filled)
            int sideTenants = Math.min(unhappyTenants, sideFields);
//            System.out.println("tenants on sides: " + sideTenants);
            unhappiness += 3 * sideTenants;
            unhappyTenants -= sideTenants;

            // fill the rest (unhappiness + 4 per tenant)
            int rest = ((rooms - 2) * (rooms - 2)) / 2;
            int restTenants =  Math.min(unhappyTenants, rest);
//            System.out.println("rest: " + restTenants);
            unhappiness += 4 * restTenants;
            maxUnhappiness = Math.min(unhappiness, maxUnhappiness);
        }

        if(filledWithoutAngryness < tenants && oddRowsAndColumns){ // both rows and columns uneven. We can trade 1 happy tenant for 4 corners instead of 2.
//            System.out.println("odd rows and columns");
            filledWithoutAngryness = rooms / 2;
            int unhappyTenants = tenants - filledWithoutAngryness;
//            System.out.println("rooms to fill: " + unhappyTenants);
            int unhappiness = 0;

            // fill corners first (unhappiness + 2 per tenant)
            int corners = oddRowsAndColumns ? 4 : 2; // all corners are empty if both rows are odd.
            int cornerTenants = Math.min(unhappyTenants, corners);
//            System.out.println("tenants in corners: " + cornerTenants);
            unhappiness += 2 * cornerTenants;
            unhappyTenants -= cornerTenants;

            // fill sides (unhappiness + 3 per tenant)
            int sideFields = rows - 2; // 2 * rows / 2, exclude corners (already filled)
            sideFields += columns - 2; // 2 * rows / 2, exclude corners (already filled)
            int sideTenants = Math.min(unhappyTenants, sideFields);
//            System.out.println("tenants on sides: " + sideTenants);
            unhappiness += 3 * sideTenants;
            unhappyTenants -= sideTenants;

            // fill the rest (unhappiness + 4 per tenant)
            int rest = ((rooms - 2) * (rooms - 2)) / 2 + 1;
            int restTenants =  Math.min(unhappyTenants, rest);
//            System.out.println("rest: " + restTenants);
            unhappiness += 4 * restTenants;
            maxUnhappiness = Math.min(unhappiness, maxUnhappiness);
        }
        output.println("Case #" + testCase + ": " + maxUnhappiness);
    }

    public static void main(String[] args){
        final long startTime = System.currentTimeMillis();
        File file = new File("B.in");
        Scanner input = null;
        try {
            input = new Scanner(file).useLocale(Locale.US);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        PrintWriter output = null;
        try {
            output = new PrintWriter("B.out", "UTF-8");
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        int problems = input.nextInt();
        for(int i = 1; i <= problems; i++){
            new B(input, output).solveProblem(i);
        }
        output.close();
        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time: " + (endTime - startTime) + " ms");
    }
}
