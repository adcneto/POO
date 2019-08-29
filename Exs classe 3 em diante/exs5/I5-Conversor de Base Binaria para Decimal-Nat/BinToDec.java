import java.util.Scanner;

public class BinToDec {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		while(scanner.hasNext()) {
			String binario = scanner.nextLine();
			long numero = Long.parseLong(binario, 2);
			System.out.println(numero);
		}
		
		scanner.close();
	}
}
