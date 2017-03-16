package org.shelajev.round1c;

import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by shelajev on 09/04/16.
 */
public class A {

  private final String inputFile = "A-large.in";
  private final String outputFile = "A-large.out";

  public static void main(String[] args) throws IOException {
    A a = new A();
    a.run();
  }

  private void run() throws IOException {
    Scanner sc = inputFile.isEmpty() ? new Scanner(System.in) : new Scanner(Paths.get(inputFile));
    PrintWriter w = outputFile.isEmpty() ? new PrintWriter(System.out) : new PrintWriter(Paths.get(outputFile).toFile());

    String msg = "Case #%d:";
    int T = sc.nextInt();
    for (int i = 1; i <= T; i++) {
      w.print(String.format(msg, i));
      int n = sc.nextInt();
      int[] p = new int[n];
      for (int ij = 0; ij < n; ij++) {
        p[ij] = sc.nextInt();
      }
      solve(p, w);
      w.println();
    }
    w.flush();
  }

  private void solve(int[] p, PrintWriter w) {
    PriorityQueue<Party> q = new PriorityQueue<>();
    Map<Character, Integer> map = new HashMap<>();
    for (int i = 0; i < p.length; i++) {
      if (p[i] > 0) {
        q.add(new Party(getChar(i), p[i]));
        map.put(getChar(i), p[i]);
      }
    }

    while (!q.isEmpty()) {
      w.print(" ");
      Party party = q.poll();
      Party next = q.peek();
      if (next != null && party.amount == next.amount && !(map.size() == 3 && map.values().stream().allMatch(x -> x == 1))) {
        q.poll(); // remove the next
        w.print(party.name + "" + next.name);
        if (party.amount > 1) {
          q.add(new Party(party.name, party.amount - 1));
          map.put(party.name, party.amount - 1);
        }
        else {
          map.remove(party.name);
        }
        if (next.amount > 1) {
          q.add(new Party(next.name, next.amount - 1));
          map.put(next.name, next.amount - 1);
        }
        else {
          map.remove(next.name);
        }
      }
      else {
        w.print(party.name);
        int z = party.amount - 1;
        if (z > 0) {
          q.add(new Party(party.name, z));
          map.put(party.name, z);
        }
        else {
          map.remove(party.name);
        }
      }
    }
    return;
  }

  char getChar(int a) {
    return (char) ('A' + a);
  }

  class Party implements Comparable<Party> {
    char name;
    int amount;

    Party(char n, int a) {
      this.name = n;
      this.amount = a;
    }

    @Override public int compareTo(Party o) {
      return -Double.compare(amount, o.amount);
    }
  }
}
