import java.util.Scanner;

public class A {
 public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int T = Integer.parseInt(s.nextLine());
    for (int t = 1; t <= T; t++) {
      int N = Integer.parseInt(s.nextLine());
      Runs[] strings = new Runs[N]; 
      for (int i = 0; i < N; i++) {
        String str = s.nextLine();
        char prev = 0;
        int index = -1;
        char[] letter = new char[str.length()];
        int [] len = new int[str.length()];
        for (int j = 0; j < str.length(); j++) {
          char c = str.charAt(j);
          if (c != prev) {
            index += 1;
            letter[index] = c;
            len[index] = 1;
            prev = c;
          } else {
            len[index] += 1;
          }
        }
        index++;
        strings[i] = new Runs(letter, len, index);
        //System.out.println(strings[i]);
     }
     boolean possible = true;
     int runs_len = strings[0].letter.length;  
     for (int i = 1; (i < N) && possible; i++) {
       if (strings[i].letter.length != runs_len) {
         possible = false;
     }}
     
     int ans = 0;
     for (int i = 0; (i < runs_len) && possible; i++){
       char this_letter = strings[0].letter[i];
       double average = strings[0].len[i];
       for (int j = 1; (j < N) && possible; j++) {
         if (strings[j].letter[i] != this_letter) {
           possible = false;
         } else {
           average += strings[j].len[i];
         }
       }
       
       average /= N;
       double distance = 0;
       for (int j = 0; (j < N) && possible; j++) {
         distance += Math.abs(strings[j].len[i] - average);
       }
       ans += (int) distance; 
     }
     System.out.print("Case #"+t+": ");
     if (possible) {
       System.out.println(ans);
     } else {
       System.out.println("Fegla Won");
     }
    }
  }
}

 
