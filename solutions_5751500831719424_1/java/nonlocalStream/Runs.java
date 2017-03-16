public class Runs {
  char[] letter;
  int[] len;
  public Runs(char[] letter, int[] len, int index) {
    this.letter = new char[index];
    this.len = new int[index];
    for (int i = 0; i < index; i++) {
      this.letter[i] = letter[i];
      this.len[i] = len[i];
    }
  }
  public String toString(){
    String result = "";
    for (int i = 0; i < letter.length; i++) {
      result += letter[i]+":"+len[i]+"/";
    }
    return result;
  }
}
 
