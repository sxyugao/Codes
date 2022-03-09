import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), k = cin.nextInt();
        int sum = (1 + n) * n / 2, cntA = n / k;
        double sumA = (k + k * cntA) * cntA / 2;
        Double resA = sumA / cntA, resB = (sum - sumA) / (n - cntA);
        DecimalFormat df = new DecimalFormat("0.0");
        System.out.println(df.format(resA) + " " + df.format(resB));
        cin.close();
    }
}