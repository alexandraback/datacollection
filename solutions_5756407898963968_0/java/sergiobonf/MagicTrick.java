package magicTrick;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class MagicTrick {

    public static void main(String[] args) throws IOException {
	String mainDir = "/Users/sergio/Downloads";
	Path path = FileSystems.getDefault().getPath(mainDir, "A-small-attempt0.in");
	Path outputFile = FileSystems.getDefault().getPath(mainDir,
		"output.txt");

	List<String> inputLines = Files.readAllLines(path,
		StandardCharsets.UTF_8);

	List<String> outputLines = new ArrayList<String>();

	long start = System.currentTimeMillis();

	int numCases = Integer.parseInt(inputLines.get(0));
	int rowForCase = 10;
	for (int i = 0; i < numCases; i++) {

	    int firstLine = (i) * rowForCase + 1;

	    int firstRow = Integer.parseInt(inputLines.get(firstLine));

	    int[][] firstArrangement = GetMatrix(
		    inputLines.subList(firstLine + 1, firstLine + 5), 4);

	    //printMatrix(firstArrangement);
	    //System.out.println("------");
	    int secondRow = Integer.parseInt(inputLines.get(firstLine + 5));
	    int[][] secondArrangement = GetMatrix(
		    inputLines.subList(firstLine + 6, firstLine + 10), 4);

	    //printMatrix(secondArrangement);

	    //System.out.println(firstRow);
	    //System.out.println(secondRow);

	    HashSet<Integer> cards = new HashSet<Integer>();
	    for (int j = 0; j < firstArrangement.length; j++) {
		cards.add(firstArrangement[firstRow - 1][j]);
	    }

	    List<Integer> intersection = new ArrayList<Integer>();
	    for (int j = 0; j < secondArrangement.length; j++) {
		int card = secondArrangement[secondRow - 1][j];
		if (!cards.add(card))
		    intersection.add(card);
	    }

	    //System.out.println("intesection: " + intersection.size());
	    String result;
	    if (intersection.size() == 1) {
		result = intersection.get(0).toString();
	    } else if (intersection.size() > 1) {
		result = "Bad magician!";
	    } else {
		result = "Volunteer cheated!";
	    }

	    String caseResult = "Case #" + (i + 1) + ": " + result;
	    outputLines.add(caseResult);
	    System.out.println(caseResult);

	}
	System.out.println("Completed: " + (System.currentTimeMillis() - start)
		/ 1000d + " s");

	StandardOpenOption option;
	if (!Files.exists(outputFile)) {
	    option = StandardOpenOption.CREATE_NEW;
	} else {
	    option = StandardOpenOption.TRUNCATE_EXISTING;
	}
	Files.write(outputFile, outputLines, option);

    }

    private static int[][] GetMatrix(List<String> inputLines, int n) {
	int[][] matrix = new int[n][n];

	for (int i = 0; i < n; i++) {
	    String[] cells = inputLines.get(i).split(" ");
	    for (int j = 0; j < cells.length; j++) {
		matrix[i][j] = Integer.parseInt(cells[j]);
	    }
	}

	return matrix;
    }

    private static void printMatrix(int[][] matrix) {
	for (int i = 0; i < matrix.length; i++) {
	    for (int j = 0; j < matrix.length; j++) {

		System.out.print(matrix[i][j]+" ");
	    }
	    System.out.println();
	}
	System.out.println();
    }

}
