package dmitry.shohov;

import java.io.*;
import java.util.*;

public class Main {
    private static List<List<String>> input = new ArrayList<>();
    private static PrintWriter writer;

    public Main() {

    }

    public void run() {
        assert input.size() > 0;
        int numberOfCases = Integer.parseInt(input.get(0).get(0));
        for (int i = 0; i < numberOfCases; i++) {
            runCase(i + 1, input.subList(1 + i * 10, 1 + 10 + i * 10));
        }
    }

    public void runCase(int caseNumber, List<List<String>> caseData) {
        int firstArrangementRow = Integer.parseInt(caseData.get(0).get(0));
        List<List<Integer>> firstArrangement = new ArrayList<>(4);
        for (int i = 0; i < 4; i++) {
            List<String> row = caseData.get(i + 1);
            List<Integer> cardsRow = new ArrayList<>(4);
            for (String card : row) {
                cardsRow.add(Integer.parseInt(card));
            }
            firstArrangement.add(cardsRow);
        }
        int secondArrangementRow = Integer.parseInt(caseData.get(5).get(0));
        List<List<Integer>> secondArrangement = new ArrayList<>(4);
        for (int i = 0; i < 4; i++) {
            List<String> row = caseData.get(i + 6);
            List<Integer> cardsRow = new ArrayList<>(4);
            for (String card : row) {
                cardsRow.add(Integer.parseInt(card));
            }
            secondArrangement.add(cardsRow);
        }

        List<Integer> oneRow = firstArrangement.get(firstArrangementRow - 1);
        List<Integer> twoRow = secondArrangement.get(secondArrangementRow - 1);
        oneRow.retainAll(twoRow);
        if (oneRow.size() > 1) {
            writer.println("Case #" + caseNumber + ": Bad magician!");
        } else if (oneRow.isEmpty()) {
            writer.println("Case #" + caseNumber + ": Volunteer cheated!");
        } else {
            writer.println("Case #" + caseNumber + ": " + oneRow.get(0));
        }
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        TimeZone.setDefault(TimeZone.getTimeZone("GMT"));

        if (args.length < 2) {
            System.err.println("Requires two arguments - input and output files");
            return;
        }
        File inputFile = new File(args[0]);
        if (!inputFile.exists()) {
            System.err.println("Input file (first argument) does not exist");
            return;
        }

        BufferedReader inputReader = new BufferedReader(new FileReader(inputFile));
        String line;
        while ((line = inputReader.readLine()) != null) {
            List<String> lineInput = new ArrayList<>();
            StringTokenizer tokenizer = new StringTokenizer(line, " ");
            while (tokenizer.hasMoreTokens()) {
                lineInput.add(tokenizer.nextToken());
            }
            input.add(lineInput);
        }
        inputReader.close();

        writer = new PrintWriter(new BufferedWriter(new FileWriter(args[1])));

        Main main = new Main();
        main.run();

        writer.flush();
        writer.close();

        inputReader = new BufferedReader(new FileReader(args[1]));
        while ((line = inputReader.readLine()) != null) {
            System.out.println(line);
        }
        inputReader.close();
    }
}
