package sib;
import java.util.*;


abstract class Shape {
    protected double dimension1;
    protected double dimension2;

    public void input() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the first dimension: ");
        dimension1 = scanner.nextDouble();
        System.out.print("Enter the second dimension: ");
        dimension2 = scanner.nextDouble();
    }
    
    public abstract double computeArea();
}

class Triangle extends Shape {
    public double computeArea() {
        return 0.5 * dimension1 * dimension2;
    }
}

class Rectangle extends Shape {
    public double computeArea() {
        return dimension1 * dimension2;
    }
}

public class Inheritance {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Shape shape = null; 
        int choice;
        
        do {
        System.out.println("Calculate area of: ");
        System.out.println("1. Triangle");
        System.out.println("2. Rectangle");
        System.out.println("3. Exit");
        System.out.print("Enter your choice: ");
        choice = scanner.nextInt();

  
        	switch (choice) {
            case 1:
                shape = new Triangle();
                shape.input();
            	System.out.println("The area of triangle is: " + shape.computeArea()+"\n====================");
                break;
            case 2:
                shape = new Rectangle();
                shape.input();
            	System.out.println("The area of rectangle is: " + shape.computeArea()+"\n====================");
                break;
            case 3:
            	break;
            default:
                System.out.println("Invalid choice! Try again\n=====================");
                break;
        	}
 
        }while(choice!=3);
    }
}