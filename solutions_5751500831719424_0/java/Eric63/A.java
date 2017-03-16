import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class A {
	//private static final String INPUT_NAME = "sample";
	private static final String INPUT_NAME = "A-small-attempt0";
	//private static final String INPUT_NAME = "A-large";

	Scanner scanner;
	private BufferedWriter outputFile;

	public static void main(String[] args) throws IOException {
		new A().start();
	}

	private void start() {
		openFiles();

		int caseNbTotal = scanner.nextInt();
		for (int caseNb = 0 ; caseNb < caseNbTotal ; caseNb++){
			solveOneTestCase(caseNb);
		}

		// The end
		closeFiles();
	}

	private void solveOneTestCase(int caseNb) {
		// read case data
		int nbWord  = scanner.nextInt();
		char [][] words = new char[nbWord] [];
		for (int i = 0 ; i < nbWord ; i ++ ) {
			String nextLine = scanner.next();
			char[] charArray = nextLine.toCharArray();
			words[i] = charArray;
		}
		int nbMove = 0;
		try {

			boolean done = false ;
			int[] nextCharIndex = new int[nbWord] ;
			while (!done){
				int[] nbSameLetter = new int[nbWord];
				if (nextCharIndex[0] == words[0].length) {
					for (int i = 1 ; i < nbWord ; i ++ ) {
						if (nextCharIndex[i] != words[i].length) {
							throw new Exception();
						}
					}
					done = true;
				} else {
					char currentLetter = words[0][nextCharIndex[0]]; 
					for (int i = 0 ; i < nbWord ; i ++ ) {
						nbSameLetter[i] = getnbSameLetter(words[i],nextCharIndex[i],currentLetter);

					}
					int[] copyOf = Arrays.copyOf(nbSameLetter, nbSameLetter.length);
					Arrays.sort(nbSameLetter);
					int x = nbSameLetter[(nbSameLetter.length - 1) / 2 ] ;

					for (int i = 0 ; i < nbWord ; i ++ ) {
						nextCharIndex[i] += copyOf[i];

						nbMove += Math.abs(x - copyOf[i]);
					}
				}
			}


			writeCase(caseNb, String.valueOf( nbMove));
		} catch (Exception e) {
			writeCase(caseNb, "Fegla Won");
		}

	}


	private int getnbSameLetter(char[] word, int nextCharIndex, char currentLetter) throws Exception {
		if (word[nextCharIndex] != currentLetter) {
			throw new Exception();
		}
		int nb = 0;
		for (int i = nextCharIndex ; i < word.length ; i++) {
			if (word[i] == currentLetter){
				nb++;
			} else {
				break;
			}
		}
		return nb;
	}

	private void closeFiles() {
		try {scanner.close();
		outputFile.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	private void openFiles() {
		try {
			scanner = new Scanner(A.class.getResourceAsStream(INPUT_NAME + ".in"));
			outputFile = new BufferedWriter(new FileWriter(INPUT_NAME + "-result.txt"));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	private  void writeCase(int caseNb, String result) {
		StringBuilder sb = new StringBuilder("Case #");
		sb.append(caseNb+1);
		sb.append(": ");
		sb.append(result);
		String line = sb.toString();
		System.out.println(line);
		try {
			outputFile.write(line);
			outputFile.write("\n");
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

}
