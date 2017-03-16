import java.util.Scanner;

class prog{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for(int i=1;i<=n;i++){
      int size = in.nextInt();
      in.nextLine();
      String[] words = new String[size];
      for(int j=0;j<size;j++){
	words[j] = in.nextLine();
      }
      System.out.println("Case #"+i+": "+q1(words));
    }
  }
  public static String q1(String[] w){
    int max = 0;
    int total = 0;
    while(w[0].length() > 0){
     int sum = 0;
     int avg = 0;
     char current = w[0].charAt(0);
     for(int i=0;i<w.length;i++){
       int j=0;
       for(; j<w[i].length() && current == w[i].charAt(j); j++){ }
       sum += j;
       if(j == 0){
	 return "Fegla Won";
       }
     }
     avg = (int)Math.round(sum/w.length);
     for(int i=0;i<w.length;i++){
       int j=0;
       for(; j<w[i].length() && current == w[i].charAt(j); j++){}
       total += (int)Math.abs(avg-j);
//       System.out.println("  "+w[i]+" "+avg+" "+(int)Math.abs(avg-j));
       w[i] = w[i].substring(j,w[i].length());
     }
    }

    for(int i=0; i<w.length; i++)
      if(w[i].length() > 0)
        return "Fegla Won";

    return ""+total;
  }
}
