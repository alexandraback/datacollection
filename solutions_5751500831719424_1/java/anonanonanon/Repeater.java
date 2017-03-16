public class Repeater {


   public static int solve(String a, String b) {
      int j = 0;
      boolean win = true;
      int moves = 0;
      String shorter;
      String longer;
         
      if (a.length() < b.length()) {
         shorter = a;
         longer = b;
      }
      else {
         shorter = b;
         longer = a;
      }
         
      for (int i = 0; i < shorter.length() && j < longer.length();) {
         if (shorter.charAt(i) != longer.charAt(j)) {
            win = false;
            break;
         }
            
         // count each sequence
         int shortSeq = 0;
         char target = shorter.charAt(i);
         while (i < shorter.length() && target == shorter.charAt(i)) {
            i++;
            shortSeq++;
         }
         int longSeq = 0;
         char longTarget = longer.charAt(j);
         while (j < longer.length() && longTarget == longer.charAt(j)) {
            j++;
            longSeq++;
         }
         moves += Math.abs(longSeq - shortSeq);
      }
      if (a.charAt(a.length() - 1) != b.charAt(b.length() - 1)) win = false;
      if (win != true) return -1;
      return moves;

   }
   public static void main(String[] args) {
      int T = StdIn.readInt();
      
      for (int t = 0; t < T; t++) {
         int N = StdIn.readInt();
         
         int totalMoves = 0;
         boolean win = true;
         String a = StdIn.readString();
         for (int i = 0; i < N - 1; i++) {
            String b = StdIn.readString();

            int moves = solve(a, b);
            if (moves == -1) {
               win = false;
            }
            totalMoves += moves;
         }
         System.out.print("Case #" + (t+1) +": ");
         if (!win) System.out.println("Fegla Won");
         else System.out.println(totalMoves);
      }
   }

}
