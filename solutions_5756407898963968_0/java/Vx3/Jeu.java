
public class Jeu {
	private Integer row1;
	private Integer row2;
	
	private Integer[][] grid1;
	private Integer[][] grid2;
	
	public Jeu(String string, String string2, String string3, String string4,
			String string5, String string6, String string7, String string8,
			String string9, String string10) {
		row1 = Integer.valueOf(string);
		row2 = Integer.valueOf(string2);
		
		grid1 = new Integer[4][4];
		grid2 = new Integer[4][4];
		
		String[] grid11 = string3.split(" ");
		String[] grid12 = string4.split(" ");
		String[] grid13 = string5.split(" ");
		String[] grid14 = string6.split(" ");
		
		String[] grid21 = string7.split(" ");
		String[] grid22 = string8.split(" ");
		String[] grid23 = string9.split(" ");
		String[] grid24 = string10.split(" ");
		
		for (int i = 0; i < 4 ; i++) {
			grid1[0][i] = Integer.valueOf(grid11[i]);
			grid1[1][i] = Integer.valueOf(grid12[i]);
			grid1[2][i] = Integer.valueOf(grid13[i]);
			grid1[3][i] = Integer.valueOf(grid14[i]);
			
			grid2[0][i] = Integer.valueOf(grid21[i]);
			grid2[1][i] = Integer.valueOf(grid22[i]);
			grid2[2][i] = Integer.valueOf(grid23[i]);
			grid2[3][i] = Integer.valueOf(grid24[i]);
		}
	}

	public String compute() {
		if (row1 < 1 && row1 > 4) {
			return "Volunteer cheated!";
		}
		if (row2 < 1 && row2 > 4) {
			return "Volunteer cheated!";
		}
		
		
		Integer[] firstRow = grid1[row1 - 1];
		Integer[] secondRow = grid2[row2 - 1];
		
		int nb = 0;
		Integer last = -1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (firstRow[i] == secondRow[j]) {
					nb++;
					last = firstRow[i];
				}
			}
		}
		
		if (nb == 0) {
			return "Volunteer cheated!";
		}
		
		else if (nb == 1) {
			return last.toString();
		}
		
		else {
			return "Bad magician!";
		}
	}
}
