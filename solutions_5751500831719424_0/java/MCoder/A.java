package codejam.mc.y2014.r1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;
import java.util.Properties;
import java.util.Scanner;

public class A
{
  static void solve() throws Exception
  {
    int T = sc.nextInt();
    for (int i = 1; i <= T; i++)
    {
      //

      int N = sc.nextInt();
      List<Character> cl = new ArrayList<Character>();
      List<List<Character>> woc = new ArrayList<>();
      for (int j = 0; j < N; j++)
      {
        ArrayList<Character> wol = new ArrayList<Character>();
        woc.add(wol);
        String wo = sc.next();
        for (char c : wo.toCharArray())
          wol.add(c);
      }
      List<List<Character>> wdc = new ArrayList<>();
      List<List<Integer>> wdi = new ArrayList<>();
      for (int j = 0; j < N; j++)
      {
        ArrayList<Character> w = new ArrayList<Character>();
        wdc.add(w);
        ArrayList<Integer> wi = new ArrayList<Integer>();
        wdi.add(wi);

        Character c = null;
        Iterator<Character> it = woc.get(j).iterator();
        int pos = 0;
        while (it.hasNext())
        {
          if (c == null)
          {
            c = it.next();
            w.add(c);
            pos = 0;
            wi.add(1);
          }
          Character n = it.next();
          if (c == n)
          {
            wi.set(pos, wi.get(pos) + 1);
            continue;
          }
          else
          {
            w.add(n);
            c = n;
            pos++;
            wi.add(1);
          }
        }
      }
      List<Character> check = wdc.get(0);
      boolean notpos = false;
      for (int j = 1; j < N; j++)
      {
        if (!check.equals(wdc.get(j)))
        {
          notpos = true;
          break;
        }
      }
      int fullcount = 0;
      if (!notpos)
      {
        int size = wdi.get(0).size();
        int pos = 0;
        while (pos < size)
        {
          int min = Integer.MAX_VALUE;
          int max = 0;
          for (List<Integer> wi : wdi)
          {
            Integer pi = wi.get(pos);
            min = Math.min(pi, min);
            max = Math.max(pi, max);
          }
          int cmin = Integer.MAX_VALUE;
          for (int val = min; val <= max; val++)
          {
            int count = 0;
            for (List<Integer> wi : wdi)
            {
              Integer pi = wi.get(pos);
              count = count + Math.abs(val - pi);
            }
            cmin = Math.min(cmin, count);
          }
          fullcount += cmin;
          pos++;
        }
      }

      if (notpos)
        out("Case #" + i + ": Fegla Won");
      else
        out("Case #" + i + ": " + fullcount);

      //
    }
  }

  // =====================
  // no changes
  // =====================

  public static void main(String[] args) throws Exception
  {
    long start = System.currentTimeMillis();
    Properties prop = new Properties();
    ClassLoader cl = A.class.getClassLoader();
    prop.load(cl.getResourceAsStream("build.properties"));
    String task = prop.getProperty("input");
    sc = new Scanner(new File(prop.getProperty("download.dir") + task + ".in"));
    sc.useLocale(Locale.US);
    pw = new PrintWriter(prop.getProperty("upload.dir") + task + ".out");
    solve();
    sc.close();
    pw.flush();
    pw.close();
    float dur = ((float) (System.currentTimeMillis() - start)) / 1000f;
    System.out.println("Finished in : " + dur + " sek.");
  }

  static void out(Object result) throws Exception
  {
    System.out.println(result.toString());
    pw.println(result.toString());
  }

  static PrintWriter pw;
  static Scanner sc;
}