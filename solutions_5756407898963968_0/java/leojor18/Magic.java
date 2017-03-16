package codejam;

import java.io.IOException;
import java.util.Scanner;

public class Magic extends JamBase {
	int numeroEncontrado;
	Scanner scanner;

	public int getNumerosIguales(int[] numerosFilaUno, int[] numerosFilaDos) {
		int numIguales = 0;
		if (numerosFilaUno.length != 4 || numerosFilaUno.length != 4) {
			return -1;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (numerosFilaUno[i] == numerosFilaDos[j]) {
					numIguales++;
					numeroEncontrado = numerosFilaUno[i];
				}
			}
		}
		return numIguales;
	}

	@Override
	public void execute() throws IOException {
		scanner = file.getScanner();
		int numeroCasos = scanner.nextInt();
		for (int n = 0; n < numeroCasos; n++) {
			int filaUnoEscogida = scanner.nextInt();
			int[][] cartasUno = obtenerCartas();
			int filaDosEscogida = scanner.nextInt();
			int[][] cartasDos = obtenerCartas();
			int numeroCartasIguales = getNumerosIguales(
					cartasUno[filaUnoEscogida-1], cartasDos[filaDosEscogida-1]);
			switch (numeroCartasIguales) {
			case 0:
				file.append(formatRespuesta(n + 1, "Volunteer cheated!"));
				break;
			case 1:
				file.append(formatRespuesta(n + 1, getNumeroEncontrado().toString()));
				break;
			case -1:
				System.out.println("error!!!");
				break;

			default:
				file.append(formatRespuesta(n + 1, "Bad magician!"));
				break;
			}
			file.newLine();
		}
		file.closeFiles();
		scanner.close();

	}

	private int[][] obtenerCartas() {
		int[][] cartas = new int[4][4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cartas[i][j] = scanner.nextInt();
			}
		}
		return cartas;
	}

	public Integer getNumeroEncontrado() {
		return numeroEncontrado;
	}
	
	public static void main(String[] args){
		JamBase jamBase = new Magic();
		try {
			jamBase.setNameFileIn("ejemploMagic");
			jamBase.setNameFileOut("salidaMagicEjemplo");
			jamBase.execute();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
