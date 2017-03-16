package codejam2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public abstract class Question {
  
  private static final String DATA_PATH = "data/";
  protected final String inputName;
  
  public Question(String inputName){
    this.inputName = inputName;
  }
  
  protected abstract String getRoundName();
  protected abstract void setupCase(BufferedReader br) throws IOException;
  protected abstract String getCaseSolution();
  
  protected String getCaseLine(int caseNum){
    return "Case #" + caseNum + ": ";
  }
  
  private String getInputFilename(){
    return getRoundName() + "/" + getClass().getSimpleName() + "/" + inputName + ".in";
  }
  
  private String getOutputFilename(){
    return getRoundName() + "/" + getClass().getSimpleName() + "/" + inputName + ".out";
  }
  
  public void solveCases() throws IOException {
    String infilename = DATA_PATH + getInputFilename();
    String outfilename = DATA_PATH + getOutputFilename();
    
    File outputFile = new File(outfilename);
    if (!outputFile.exists()) {
      outputFile.createNewFile();
    }

    BufferedReader br = new BufferedReader(new FileReader(infilename));
    BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile.getAbsoluteFile()));

    int numCases = Integer.parseInt(br.readLine());

    for (int i = 1; i <= numCases; i++) {
      setupCase(br);

      long startTime = 0;
      if(Main.DEBUG){
        startTime = System.currentTimeMillis();
        System.out.println("Solving case " + i);
      }
      
      String solution = getCaseSolution();
      
      if(Main.DEBUG){
        System.out.println(getCaseLine(i) + solution);
        long currTime = System.currentTimeMillis();
        long timeTaken = currTime - startTime;
        System.out.println("Solution took: " + timeTaken + "ms");
        System.out.println();
      }
      
      bw.write(getCaseLine(i));
      bw.write(solution);
      bw.write("\n");
    }
    br.close();
    bw.close();
  }
}
