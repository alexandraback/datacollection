package farm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.ObjectInputStream.GetField;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.List;
import java.util.StringTokenizer;

public class Solver {
	static class Model {
		List<String> strings = new ArrayList<String>();
	}

	static class Symbol {
		char symbol;
		int rep = 0;
	}

	static Model[] readInputs(String path) throws IOException {
		InputStream ips = new FileInputStream(path);
		InputStreamReader ipsr = new InputStreamReader(ips);
		BufferedReader br = new BufferedReader(ipsr);
		String ligne;

		ligne = br.readLine();
		int casesCount = Integer.parseInt(ligne);
		Model[] arrayModels = new Model[casesCount];

		for (int c = 0; c < casesCount; c++) {
			arrayModels[c] = new Model();
			ligne = br.readLine();
			StringTokenizer tokenizer = new StringTokenizer(ligne);
			int nbStrings = Integer.parseInt(tokenizer.nextToken());
			for (int i = 0; i < nbStrings; i++) {
				arrayModels[c].strings.add(br.readLine());
			}
		}

		br.close();
		return arrayModels;
	}

	static int resolve(Model model) {
		List<String> strings = model.strings;
		// Symbolisation
		List<List<Symbol>> listSymbols = new ArrayList<List<Symbol>>();
		for (String str : strings) {
			listSymbols.add(toSymbols(str));
		}
		int cost = 0;
		int nbSymbol = listSymbols.get(0).size();

		for (int s = 0; s < nbSymbol; s++) {
			int symCostMin = Integer.MAX_VALUE;
			for (int i = 0; i < listSymbols.size(); i++) {
				List<Symbol> from = listSymbols.get(i);
				int symbCost = 0;
				for (int j = 0; j < listSymbols.size(); j++) {
					if (i == j) {
						continue;
					}
					List<Symbol> to = listSymbols.get(j);
					if (from.size() != to.size())
						return -1;
					if (from.get(s).symbol != to.get(s).symbol)
						return -1;
					symbCost += Math.abs(from.get(s).rep - to.get(s).rep);
				}
				if (symCostMin > symbCost) {
					symCostMin = symbCost;
				}
			}
			cost += symCostMin;

		}
		return cost;
	}

	static int cost(List<Symbol> from, List<Symbol> to) {
		if (from.size() != to.size())
			return -1;
		int cost = 0;
		for (int i = 0; i < from.size(); i++) {
			if (from.get(i).symbol != to.get(i).symbol)
				return -1;
			cost += Math.abs(from.get(i).rep - to.get(i).rep);
		}
		return cost;
	}

	static List<Symbol> toSymbols(String str) {
		List<Symbol> list = new ArrayList<Solver.Symbol>();
		Symbol symbol = null;
		for (int i = 0; i < str.length(); i++) {
			if (symbol != null) {
				if (str.charAt(i) == symbol.symbol) {
					symbol.rep++;
				} else {
					symbol = new Symbol();
					symbol.symbol = str.charAt(i);
					symbol.rep++;
					list.add(symbol);
				}
			} else {
				symbol = new Symbol();
				symbol.symbol = str.charAt(i);
				symbol.rep++;
				list.add(symbol);
			}
		}
		return list;
	}

	static void writeOutput(int[] awnsers, String path) throws IOException {
		OutputStream ops = new FileOutputStream(path);
		OutputStreamWriter opsr = new OutputStreamWriter(ops);
		BufferedWriter bw = new BufferedWriter(opsr);

		for (int c = 0; c < awnsers.length; c++) {
			if (awnsers[c] == -1) {
				bw.write("Case #" + (c + 1) + ": Fegla Won\n");
			} else {
				bw.write("Case #" + (c + 1) + ": " + awnsers[c] + "\n");
			}

		}
		bw.close();
	}

	public static void main(String[] args) throws IOException {
		String inputPath = "inputs/A-small-attempt0.in";
		String outputPath = "outputs/A-small-attempt0.ou";
		Model[] models = readInputs(inputPath);
		int[] awnsers = new int[models.length];
		for (int i = 0; i < models.length; i++) {
			awnsers[i] = resolve(models[i]);
		}
		writeOutput(awnsers, outputPath);

	}
}
