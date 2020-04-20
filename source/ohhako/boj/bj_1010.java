import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.math.BigInteger;

public class Main {
	public static void makeBridge(int n, int m) {
		BigInteger parent = BigInteger.ONE;
		BigInteger child = BigInteger.ONE;
		
		for (int i = 1; i <= n ; i++) {
			parent = parent.multiply(BigInteger.valueOf(m-i+1));
			child = child.multiply(BigInteger.valueOf(i));
		}
		System.out.println(parent.divide(child));
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			String[] cmd = br.readLine().split(" ");
			makeBridge(Integer.parseInt(cmd[0]), Integer.parseInt(cmd[1]));
		}
	}
}