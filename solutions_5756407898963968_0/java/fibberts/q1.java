import java.util.Scanner;

class q1{
  public static void main(String[] args){
    int[] row1 = new int[4], row2 = new int[4];
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for(int i=1;i<=n;i++){
      int ans1 = in.nextInt();
      in.nextLine();
      loadarray(row1, in, ans1);
      int ans2 = in.nextInt();
      in.nextLine();
      loadarray(row2, in, ans2);
      System.out.print("Case #"+i+": ");
      System.out.println(eval(row1, row2));
    }
  }
  public static String eval(int[] row1, int[] row2){
    int[] possible = new int[17];
    for(int i=0;i<possible.length;i++)
      possible[i] = 0;
    for(int i=0;i<row1.length;i++)
      possible[row1[i]]++;
    for(int i=0;i<row2.length;i++)
      possible[row2[i]]++;
    int indexOfATwo = -1;
    for(int i=0; i<possible.length;i++){
      if(possible[i] == 2){
        if(indexOfATwo < 0)
          indexOfATwo = i;
        else if(indexOfATwo >= 0)
          return "Bad magician!";
      }
    }
    if(indexOfATwo < 0)
      return "Volunteer cheated!";
    return ""+indexOfATwo;
  }
  public static void loadarray(int[] row, Scanner in, int which){
    int i=1;
    while(i++ < which)
      in.nextLine();
    for(int j=0;j<row.length;j++)
      row[j] = in.nextInt();
    in.nextLine();
    while(i++ <= 4)
      in.nextLine();
  }
}
