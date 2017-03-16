import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.List;

public class InputData {
	private final List<String> lines = new ArrayList<String>();
	
	/**
	 * Obtains a list of input lines from the given InputStream to populate this structure.
	 * Input format: first line with a single number, which is the number of lines in the data.
	 * NOTE: no extensive safety checking.
	 * @param in InputStream to read from.
	 */
	public InputData(InputStream in, int linesPerCase) throws NoSuchElementException {
		Scanner scanner = new Scanner(in);
		int cases;
		try {
			cases = Integer.parseInt(scanner.nextLine());
		} catch (NumberFormatException e) {
			scanner.close();
			throw new NoSuchElementException("First line is not an integer.");
		}
		for (int i = 0; i < cases * linesPerCase; i++) {
			lines.add(scanner.nextLine());
		}
		scanner.close();
	}
	
	public InputData(InputStream in) {
		this(in, 1);
	}
	
	public InputData(int linesPerCase) {
		this(System.in, linesPerCase);
	}
	
	public InputData() {
		this(System.in, 1);
	}
	
	public List<String> getLines() {
		return Collections.unmodifiableList(lines);
	}
	
	public int size() {
		return lines.size();
	}

}
