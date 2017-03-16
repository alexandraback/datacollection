import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class GoogleCodeJam2014Q1 {

	ArrayList<String> inputLines = new ArrayList<String>();
	ArrayList<String> outputLines = new ArrayList<String>();
	private static final String PATH ="/Users/koichisakumoto/Documents/GoogleCodeJam/";
	
	public static void main(String[] args) {
		GoogleCodeJam2014Q1 inst = new GoogleCodeJam2014Q1();
		inst.getLines(PATH + "Q1/A-small-attempt0.in.txt");
		inst.solveProblem();
		inst.putLines(PATH + "Q1/answer1.txt");
	}

	private void solveProblem(){
		int currentLine = 0;
		int totalNum = Integer.parseInt(inputLines.get(currentLine++));
		
		for (int problemNum = 1; problemNum <= totalNum; problemNum++ ) {
			
			// input problem 
			int selectedRowA = Integer.parseInt(inputLines.get(currentLine++)) - 1;
			int matrixA[][] = new int[4][4];
			String[] rowA1 = inputLines.get(currentLine++).split(" ");
			String[] rowA2 = inputLines.get(currentLine++).split(" ");
			String[] rowA3 = inputLines.get(currentLine++).split(" ");
			String[] rowA4 = inputLines.get(currentLine++).split(" ");
			for (int i = 0; i < 4; i++) matrixA[0][i] = Integer.parseInt(rowA1[i]);
			for (int i = 0; i < 4; i++) matrixA[1][i] = Integer.parseInt(rowA2[i]);
			for (int i = 0; i < 4; i++) matrixA[2][i] = Integer.parseInt(rowA3[i]);
			for (int i = 0; i < 4; i++) matrixA[3][i] = Integer.parseInt(rowA4[i]);
			int selectedRowB = Integer.parseInt(inputLines.get(currentLine++)) - 1;
			int matrixB[][] = new int[4][4];
			String[] rowB1 = inputLines.get(currentLine++).split(" ");
			String[] rowB2 = inputLines.get(currentLine++).split(" ");
			String[] rowB3 = inputLines.get(currentLine++).split(" ");
			String[] rowB4 = inputLines.get(currentLine++).split(" ");
			for (int i = 0; i < 4; i++) matrixB[0][i] = Integer.parseInt(rowB1[i]);
			for (int i = 0; i < 4; i++) matrixB[1][i] = Integer.parseInt(rowB2[i]);
			for (int i = 0; i < 4; i++) matrixB[2][i] = Integer.parseInt(rowB3[i]);
			for (int i = 0; i < 4; i++) matrixB[3][i] = Integer.parseInt(rowB4[i]);
			
			// solve problem
			// matrixA[selectedRowA] と matrixB[selectedRowB] の
			// 共通部分を計算する
			ArrayList<Integer> commonNum = new ArrayList<Integer>();
			for ( int i = 0; i < 4; i++ ){
				for ( int j = 0; j < 4; j++ ){
					if (matrixA[selectedRowA][i] == matrixB[selectedRowB][j]) {
						commonNum.add(Integer.valueOf(matrixA[selectedRowA][i]));
					}
				}
			}

			// 解答を作る
			if ( commonNum.size() == 1 ) {
				outputLines.add("Case #" + problemNum + ": " + commonNum.get(0));
			} else if ( commonNum.size() > 1 ) {
				outputLines.add("Case #" + problemNum + ": Bad magician!");
			} else {
				outputLines.add("Case #" + problemNum + ": Volunteer cheated!");
			}
		}
	}
	
	private void getLines(String fileName){
		try {
            FileReader in = new FileReader(fileName);
            BufferedReader br = new BufferedReader(in);
            String line;
            while ((line = br.readLine()) != null) {
            	inputLines.add(line);
            }
            br.close();
            in.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
	private void putLines(String fileName){
		try {
			FileWriter out = new FileWriter(fileName); // new file
			BufferedWriter bw = new BufferedWriter(out);
            for ( String line : outputLines ){
            	bw.write(line + "\r\n");
            }
            bw.close();
            out.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
}
