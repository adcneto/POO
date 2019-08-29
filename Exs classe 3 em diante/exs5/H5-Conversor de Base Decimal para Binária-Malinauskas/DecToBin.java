import java.util.Scanner;

public class DecToBin {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		while(scanner.hasNext()) {
			long numero = scanner.nextLong();
			String binario = Long.toBinaryString(numero);
			System.out.println(binario);
		}
		
		scanner.close();
	}
}
