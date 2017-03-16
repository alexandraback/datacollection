package codejam2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

public class QualsA {

  private static final boolean DEBUG = false;
  private static final String BAD_MAGICIAN = "Bad magician!";
  private static final String VOLUNTEER_CHEATED = "Volunteer cheated!";
  private static final int BOARD_WIDTH = 4, BOARD_HEIGHT = 4;

  private int row1;
  private int[][] board1;
  private int row2;
  private int[][] board2;

  public void solveCases() throws IOException {
    String infilename = "Asin.in";
    String outfilename = "Asout.in";

    // create output file if it does not exist, otherwise overwrite everything
    // in it
    File file = new File("data/quals/" + outfilename);
    if (!file.exists()) {
      file.createNewFile();
    }

    // create reader and writer for the input and output files
    BufferedReader br = new BufferedReader(new FileReader("data/quals/"
        + infilename));
    BufferedWriter bw = new BufferedWriter(new FileWriter(
        file.getAbsoluteFile()));

    // get the number of test cases to use throughout solving process
    int numCases = Integer.parseInt(br.readLine());

    // create some temporary variables to use for storing input variabes and
    // output string
    String line;
    for (int i = 1; i <= numCases; i++) {
      row1 = Integer.parseInt(br.readLine());
      board1 = new int[BOARD_HEIGHT][BOARD_WIDTH];
      for (int j = 0; j < BOARD_HEIGHT; ++j) {
        line = br.readLine();
        String[] splitLine = line.split(" ");
        for (int k = 0; k < BOARD_WIDTH; ++k) {
          board1[j][k] = Integer.parseInt(splitLine[k]);
        }
      }
      
      row2 = Integer.parseInt(br.readLine());
      board2 = new int[BOARD_HEIGHT][BOARD_WIDTH];
      for (int j = 0; j < BOARD_HEIGHT; ++j) {
        line = br.readLine();
        String[] splitLine = line.split(" ");
        for (int k = 0; k < BOARD_WIDTH; ++k) {
          board2[j][k] = Integer.parseInt(splitLine[k]);
        }
      }

      line = "Case #" + i + ": " + solve() + "\n"; // solve here
      if(DEBUG){
        System.out.println(line);
      }
      bw.write(line);
    }
    br.close();
    bw.close();
  }

  private String solve() {
    if(DEBUG){
      System.out.println("Solving case");
    }
    int[] poss1 = board1[row1-1];
    int[] poss2 = board2[row2-1];
    
    if(DEBUG){
      String line = "row 1: ";
      for(int i=0; i<BOARD_WIDTH; ++i){
        line += poss1[i] + " ";
      }
      System.out.println(line);
      line = "row 2: ";
      for(int i=0; i<BOARD_WIDTH; ++i){
        line += poss2[i] + " ";
      }
      System.out.println(line);
    }
    
    List<Integer> possAll = new LinkedList<Integer>();
    for(int i=0; i<BOARD_WIDTH; ++i){
      int num = poss1[i];
      for(int j=0; j<BOARD_WIDTH; ++j){
        if(num==poss2[j]){
          possAll.add(num);
          break;
        }
      }
    }
    
    int size = possAll.size();
    if(size<1){
      return VOLUNTEER_CHEATED;
    }
    
    if(size>1){
      return BAD_MAGICIAN;
    }
    
    return Integer.toString(possAll.get(0));
  }

  public static void main(String[] args) {
    QualsA prob = new QualsA();
    try {
      prob.solveCases();
    } catch (IOException e) {
      System.out.println("Cannot read or write to files.");
      System.out.println(e.getMessage());
    }
  }
}
