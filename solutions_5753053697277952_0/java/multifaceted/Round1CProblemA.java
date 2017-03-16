package Round1C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.HashMap;


/**
 * Created by mayank on 10/4/16.
 */
public class Round1CProblemA {

  private static Object[] ioResource()
      throws IOException {
    String problemFileName = "A-small";
    String inputFileName = problemFileName + ".txt";
    String outputFileName = problemFileName + "-out.txt";
    File homedir = new File(System.getProperty("user.home"));
    File CurrentIODir = new File(homedir, "IdeaProjects/CodeJam2016/ioFiles/round1C");
    File inputFile = new File(CurrentIODir, inputFileName);
    FileReader inputFileReader = new FileReader(inputFile);
    BufferedReader br = new BufferedReader(inputFileReader);

    File outputFile = new File(CurrentIODir, outputFileName);
    if (!outputFile.exists()) {
      outputFile.createNewFile();
    }
    FileWriter outputFileWriter = new FileWriter(outputFile.getAbsoluteFile());
    BufferedWriter bufferedWriter = new BufferedWriter(outputFileWriter);
    Object[] ioBuffers = new Object[2];
    ioBuffers[0] = br;
    ioBuffers[1] = bufferedWriter;
    return ioBuffers;
  }

  public static void main(String[] args)
      throws IOException {
    Object[] ioBuffers = ioResource();
    BufferedReader br = (BufferedReader) ioBuffers[0];
    BufferedWriter bufferedWriter = (BufferedWriter) ioBuffers[1];
    int t = Integer.parseInt(br.readLine());
    for (int i = 1; i <= t; i++) {
      String answer = solve(br);
      System.out.println("Case #" + i + ": " + answer);
      bufferedWriter.write("Case #" + i + ": " + answer);
      bufferedWriter.newLine();
    }
    bufferedWriter.flush();
    bufferedWriter.close();
  }

  public static String solve(BufferedReader br)
      throws IOException {
    int n = Integer.parseInt(br.readLine());
    String partitioning[] = br.readLine().trim().split(" ");
    if (n != partitioning.length) {
      return "fail";
    }
    int numPart[] = new int[n];
    int totalRemaining = 0;
    for (int i = 0; i < n; i++) {
      numPart[i] = Integer.parseInt(partitioning[i]);
      totalRemaining += numPart[i];
    }
    char ch = 'A';
    String answer = "";
    int[] largestParties = getLargestParties(numPart, n);

    while (largestParties[0] != -1) {
      if (largestParties[1] != -1) {
        //2 are largest party
        int r1 = largestParties[0];
        int r2 = largestParties[1];
        if (canRemove11(numPart, n, totalRemaining, r1, r2)) {
          numPart[r1] -= 1;
          numPart[r2] -= 1;
          totalRemaining -= 2;
          char ch1c = (char) (ch + r1);
          char ch2c = (char) (ch + r2);
          String ch1 = String.valueOf(ch1c);
          String ch2 = String.valueOf(ch2c);
          String removed = ch1 + ch2 + " ";
          answer += removed;
        } else {
          numPart[r1] -= 1;
          totalRemaining -= 1;
          char ch1c = (char) (ch + r1);
          String ch1 = String.valueOf(ch1c);
          String removed = ch1 + " ";
          answer += removed;
        }
      } else {
        //only 1 is largest party
        int r1 = largestParties[0];
        if (canRemove2(numPart, n, totalRemaining, r1)) {
          numPart[r1] -= 2;
          totalRemaining -= 2;
          char ch1c = (char) (ch + r1);
          String ch1 = String.valueOf(ch1c);
          String removed = ch1 + ch1 + " ";
          answer += removed;
        } else {
          numPart[r1] -= 1;
          totalRemaining -= 1;
          char ch1c = (char) (ch + r1);
          String ch1 = String.valueOf(ch1c);
          String removed = ch1 + " ";
          answer += removed;
        }
      }
      largestParties = getLargestParties(numPart, n);
    }
    answer = answer.trim();
    return answer;
  }

  public static int[] getLargestParties(int[] numPart, int n) {

    int largestParties[] = {-1, -1};
    int maxSize = 0;
    for (int i = 0; i < n; i++) {
      if (maxSize < numPart[i]) {
        maxSize = numPart[i];
        largestParties[0] = i;
        largestParties[1] = -1;
      }
      if (maxSize == numPart[i] && largestParties[1] == -1 && largestParties[0] != i) {
        largestParties[1] = i;
      }
    }
    return largestParties;
  }

  public static boolean canRemove2(int[] numPart, int n, double totalRemaining, int rIndex) {
    int[] newNumPart = numPart.clone();
    newNumPart[rIndex] -= 2;
    totalRemaining -= 2;
    for (int i = 0; i < n; i++) {
      if (newNumPart[i] > (totalRemaining / 2.0)) {
        return false;
      }
    }
    return true;
  }

  public static boolean canRemove11(int[] numPart, int n, double totalRemaining, int r1, int r2) {
    int[] newNumPart = numPart.clone();
    newNumPart[r1] -= 1;
    newNumPart[r2] -= 1;
    totalRemaining -= 2;
    for (int i = 0; i < n; i++) {
      if (newNumPart[i] > (totalRemaining / 2.0)) {
        return false;
      }
    }
    return true;
  }
}
