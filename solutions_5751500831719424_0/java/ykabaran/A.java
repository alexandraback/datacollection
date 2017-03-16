package codejam2014.round1B;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;

import codejam2014.Main;

public class A extends Round1B {
  
  public A(String inputName) {
    super(inputName);
  }
  
  private int N;
  private String[] words;
  
  @Override
  protected void setupCase(BufferedReader br) throws IOException { 
    N = Integer.parseInt(br.readLine());
    words = new String[N];
    for(int i=0; i<N; ++i){
      words[i] = br.readLine();
    }
  }
  
  private static final String LOST = "Fegla Won";
  
  private static int countChanges(String s){
    int length = s.length();
    int numChanges = 1;
    char lastChar = s.charAt(0);
    for(int i=1; i<length; ++i){
      if(s.charAt(i) != lastChar){
        ++numChanges;
        lastChar = s.charAt(i);
      }
    }
    
    return numChanges;
  }
  
  private static class CharCount {
    public char c;
    public int count;
    
    public CharCount(char c){
      this.c = c;
      count = 1;
    }
    
    public void addTo(){
      ++count;
    }
  }
  
  private static LinkedList<CharCount> getCharCount(String s){
    LinkedList<CharCount> result = new LinkedList<CharCount>();
    int length = s.length();
    CharCount lastChar = new CharCount(s.charAt(0));
    result.add(lastChar);
    for(int i=1; i<length; ++i){
      char currChar = s.charAt(i);
      if(currChar != lastChar.c){
        CharCount newChar = new CharCount(currChar);
        lastChar = newChar;
        result.add(newChar);
      } else {
        lastChar.addTo();
      }
    }
    
    return result;
  }
  
  @Override
  protected String getCaseSolution() {
    if(N>2){
      return "Not Yet";
    }
    
    ArrayList<LinkedList<CharCount>> charCounts 
     = new ArrayList<LinkedList<CharCount>>(N);
    
    LinkedList<CharCount> firstCharCount = getCharCount(words[0]);
    charCounts.add(firstCharCount);
    int charCountSize = firstCharCount.size();
    for(int i=1; i<N; ++i){
      LinkedList<CharCount> currCharCount = getCharCount(words[i]);
      int currCharCountSize = currCharCount.size();
      if(currCharCountSize != charCountSize){
        return LOST;
      } else {
        for(int j=0; j<charCountSize; ++j){
          if(firstCharCount.get(j).c != currCharCount.get(j).c){
            return LOST;
          }
        }
      }
      charCounts.add(currCharCount);
    }
    
    int[] minCounts = new int[charCountSize];
    int[] maxCounts = new int[charCountSize];
    int index = 0;
    for(CharCount c : firstCharCount){
      minCounts[index] = c.count;
      maxCounts[index] = c.count;
      ++index;
    }
    for(int j=1; j<N; ++j){
      LinkedList<CharCount> currCharCount = charCounts.get(j);
      index = 0;
      for(CharCount c : currCharCount){
        int currCount = c.count;
        if(currCount<minCounts[index]){
          minCounts[index] = currCount;
        } else if(currCount>maxCounts[index]){
          maxCounts[index] = currCount;
        }
        ++index;
      }
    }
    
    int numMoves = 0;
    for(int i=0; i<charCountSize; ++i){
      numMoves += maxCounts[i]-minCounts[i];
    }
    
    return Integer.toString(numMoves);
  }
}
