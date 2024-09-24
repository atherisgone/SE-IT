import java.util.Scanner;

class ExceptionsTest {
    Scanner scr = new Scanner(System.in);
    int div;

    public void AllinOne() {
        int a[] = new int[5];

        System.out.println("Enter the elements of array: ");

        try {
            for (int i = 0; i < 5; i++) {
                try {
                    a[i] = Integer.parseInt(scr.next());
                } catch (NumberFormatException e) {
                    System.out.println("Invalid input! Please enter a valid integer.");
                }
            }
        } finally {
            try {
                int num1;

                System.out.println("Enter the number to divide: ");
                num1 = scr.nextInt();

                for (int i = 0; i < 5; i++) {
                    div = a[i] / num1;
                    System.out.println("Division of " + a[i] + "/" + num1 + " is: " + div);
                }
            } catch (ArithmeticException e) {
                System.out.println("Division by zero is not allowed.");
            }
        }
    }
}

public class ExceptionTest {
    public static void main(String args[]) {
        ExceptionsTest e = new ExceptionsTest();
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- Menu ---");
            System.out.println("1. Perform Division");
            System.out.println("2. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    e.AllinOne();
                    break;
                case 2:
                    System.out.println("Exiting the program.");
                    break;
                default:
                    System.out.println("Invalid choice! Please enter 1 or 2.");
            }
        } while (choice != 2);
    }
}
