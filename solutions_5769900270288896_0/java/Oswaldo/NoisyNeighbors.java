import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class NoisyNeighbors {
	public static void main(String[] args) throws IOException {
		String[] input;
		if (args.length > 0) { input = args; }
		else {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String x = null;
			int size = Integer.parseInt(in.readLine());
			input = new String[size];
			for (int i=0; i<size; i++) {
				input[i] = in.readLine();
			}
		}
		solve(input);
	}
	
	public static void solve(String[] input) {
		int counter = 1;
		String[] temp;
		int r, c, n;
		boolean[][] grid;
		for (String s: input) {
			temp = s.split(" ");
			r = Integer.parseInt(temp[0]);
			c = Integer.parseInt(temp[1]);
			n = Integer.parseInt(temp[2]);
			grid = new boolean[r][c];
			System.out.println("Case #" + counter + ": " + countMinimum(grid, n));
			counter++;
		}
	}
	
	public static int countMinimum(boolean[][] grid, int n) {
		if (quickCheck(grid, n)) { return 0; }
		grid = new boolean[grid.length][grid[0].length];
		int empty = grid.length * grid[0].length - n;
		if (empty > n) { return recurse(grid, n); }
		else {
			reverseGrid(grid);
			return reverseRecurse(grid, empty);
		}
	}
	
	public static boolean quickCheck(boolean[][] grid, int n) {
		int best, bX, bY, temp;
		for (int i=0; i<n; i++) {
			best = Integer.MAX_VALUE;
			bX = -1;
			bY = -1;
			for (int x=0; x<grid.length; x++) {
				for (int y=0; y<grid[x].length; y++) {
					if (grid[x][y]) { continue; }
					temp = countNoise(grid, x, y);
					if (temp < best) {
						best = temp;
						bX = x;
						bY = y;
					}
				}
			}
			grid[bX][bY] = true;
		}
		return countTotalNoise(grid) == 0;
	}
	
	public static int recurse(boolean[][] g, int n) {
		if (n == 0) { return countTotalNoise(g); }
		int temp;
		int best = Integer.MAX_VALUE;
		for (int x=0; x<g.length; x++) {
			for (int y=0; y<g[x].length; y++) {
				if (!g[x][y]) {
					g[x][y] = true;
					temp = recurse(g, n-1);
					g[x][y] = false;
					if (temp < best) { best = temp; }
				}
			}
		}
		return best;
	}
	
	public static int reverseRecurse(boolean[][] g, int n) {
		if (n == 0) { return countTotalNoise(g); }
		int temp;
		int best = Integer.MAX_VALUE;
		for (int x=0; x<g.length; x++) {
			for (int y=0; y<g[x].length; y++) {
				if (g[x][y]) {
					g[x][y] = false;
					temp = reverseRecurse(g, n-1);
					g[x][y] = true;
					if (temp < best) { best = temp; }
				}
			}
		}
		return best;
	}
	
	public static void print(boolean[][] g) {
		for (int x=0; x<g.length; x++) {
			for (int y=0; y<g[x].length; y++) {
				if (g[x][y]) { System.out.print("T"); }
				else { System.out.print("F"); }
			}
			System.out.println();
		}
		System.out.println("-----");
	}
	
	public static void reverseGrid(boolean[][] g) {
		for (int x=0; x<g.length; x++) {
			for (int y=0; y<g[x].length; y++) {
				g[x][y] = !g[x][y];
			}
		}
	}
	
	public static int countTotalNoise(boolean[][] g) {
		int total = 0;
		for (int x=0; x<g.length; x++) {
			for (int y=0; y<g[x].length; y++) {
				try { if (g[x][y] && g[x][y+1]) { total++; } } catch (Exception e) { }
				try { if (g[x][y] && g[x+1][y]) { total++; } } catch (Exception e) { }
			}
		}
		return total;
	}
	
	public static int countNoise(boolean[][] grid, int x, int y) {
		int counter = 0;
		try { if (grid[x-1][y]) { counter++; } } catch (Exception e) { }
		try { if (grid[x+1][y]) { counter++; } } catch (Exception e) { }
		try { if (grid[x][y-1]) { counter++; } } catch (Exception e) { }
		try { if (grid[x][y+1]) { counter++; } } catch (Exception e) { }
		return counter;
	}
}