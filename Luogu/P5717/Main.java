import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] a = new int[3];
        for (int i = 0; i < 3; ++i) a[i] = in.nextInt();
        Arrays.sort(a);
        if (a[0] + a[1] <= a[2]) {
            System.out.println("Not triangle");
            return;
        }
        if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) System.out.println("Right triangle");
        if (a[0] * a[0] + a[1] * a[1] > a[2] * a[2]) System.out.println("Acute triangle");
        if (a[0] * a[0] + a[1] * a[1] < a[2] * a[2]) System.out.println("Obtuse triangle");
        if (a[0] == a[1] || a[1] == a[2]) System.out.println("Isosceles triangle");
        if (a[0] == a[2]) System.out.println("Equilateral triangle");
    }
}