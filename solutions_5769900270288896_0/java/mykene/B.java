package roundTwo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by rubenverboon on 11/04/15.
 */
public class B {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner sc = new Scanner(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/B.in"));
    PrintWriter pw = new PrintWriter(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/B.out"));
    B b = new B();
    int c = sc.nextInt();
    for (int i = 0; i < c; i++) {
      pw.println("Case #" + (i + 1) + ": " + b.solve(sc));
    }
    pw.close();
    sc.close();
  }


  private int solve(Scanner sc) {
    int r = sc.nextInt();
    int c = sc.nextInt();
    int n = sc.nextInt();

    if(n==0) return 0;

    ArrayList<Integer> list = new ArrayList<>();
    for (int i = 0; i < r * c; i++)
      list.add(i);


    Set<Set<Integer>> g = getCombinationsFor(list, n);


    int t =0;

    return g.stream().map((a) -> {


      boolean[][] map = new boolean[r][c];

      a.forEach((b) -> {
        map[b % r][b / r] = true;
      });

      int sum = 0;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c - 1; j++) {
          if (map[i][j] && map[i][j + 1]) sum++;
        }
      }

      for (int j = 0; j < c; j++) {
        for (int i = 0; i < r - 1; i++) {
          if (map[i][j] && map[i + 1][j]) sum++;
        }
      }
      return sum;
    }).reduce(Math::min).get();


  }


  public static Set<Set<Integer>> getCombinationsFor(List<Integer> group, int subsetSize) {
    Set<Set<Integer>> resultingCombinations = new HashSet<Set<Integer>> ();
    int totalSize=group.size();
    if (subsetSize == 0) {
      emptySet(resultingCombinations);
    } else if (subsetSize <= totalSize) {
      List<Integer> remainingElements = new ArrayList<Integer> (group);
      Integer X = popLast(remainingElements);

      Set<Set<Integer>> combinationsExclusiveX = getCombinationsFor(remainingElements, subsetSize);
      Set<Set<Integer>> combinationsInclusiveX = getCombinationsFor(remainingElements, subsetSize-1);
      for (Set<Integer> combination : combinationsInclusiveX) {
        combination.add(X);
      }
      resultingCombinations.addAll(combinationsExclusiveX);
      resultingCombinations.addAll(combinationsInclusiveX);
    }
    return resultingCombinations;
  }

  private static void emptySet(Set<Set<Integer>> resultingCombinations) {
    resultingCombinations.add(new HashSet<Integer>());
  }

  private static Integer popLast(List<Integer> elementsExclusiveX) {
    return elementsExclusiveX.remove(elementsExclusiveX.size()-1);
  }
}
