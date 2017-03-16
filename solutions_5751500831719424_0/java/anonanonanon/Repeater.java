public class Repeater {

   public static void main(String[] args) {
      int T = StdIn.readInt();
      
      for (int t = 0; t < T; t++) {
         int N = StdIn.readInt();
         String a = StdIn.readString();
         String b = StdIn.readString();
         
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
         System.out.print("Case #" + (t+1) +": ");
         if (!win) System.out.println("Fegla Won");
         else System.out.println(moves);
      }
   }

}
