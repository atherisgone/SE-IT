package sib;
import java.util.*;


class Publication {
 protected String title;
 protected double price;
 protected int copies;
 

 public Publication(String title, double price, int copies) {
     this.title = title;
     this.price = price;
     this.copies = copies;
 }
 
 
 public Publication() {
     this.title = "";
     this.price = 0.0;
     this.copies = 0;
 }
 

 public void orderCopies(int qty) {
     this.copies += qty;
 }
 

 public double getTotalSale() {
     return this.price * this.copies;
 }
 

 public void displayInfo() {
     System.out.println("Title: " + title);
     System.out.println("Price: ₹" + price);
     System.out.println("Copies: " + copies);
 }
}


class Book extends Publication {
 private String author;
 

 public Book(String title, double price, int copies, String author) {
   
     this.title = title;
     this.price = price;
     this.copies = copies;
     this.author = author;
 }
 

 public void orderCopies(int qty) {
     this.copies += qty;
     System.out.println(qty + " copies of the book \"" + title + "\" have been ordered.");
 }
 

 public void displayBookInfo() {
     displayInfo();
     System.out.println("Author: " + author);
 }
}


class Magazine extends Publication {
 private String currentIssue;
 
 
 public Magazine(String title, double price, int copies) {
     
     this.title = title;
     this.price = price;
     this.copies = copies;
 }
 

 public void orderQty(int qty) {
     this.copies += qty;
     System.out.println(qty + " copies of the magazine \"" + title + "\" have been ordered.");
 }
 

 public void receiveIssue(String issue) {
     this.currentIssue = issue;
     System.out.println("Received new issue: " + currentIssue);
 }
 

 public void displayMagazineInfo() {
     displayInfo();
     System.out.println("Current Issue: " + currentIssue);
 }
}


public class Mag {
 public static void main(String[] args) {
     Scanner scanner = new Scanner(System.in);

     System.out.println("Enter Book Title:");
     String bookTitle = scanner.nextLine();
     
     System.out.println("Enter Book Price:");
     double bookPrice = scanner.nextDouble();
     
     System.out.println("Enter Number of Copies Ordered:");
     int bookCopiesOrdered = scanner.nextInt();
     
     System.out.println("Enter Number of Copies Already Ordered:");
     int bookCopiesAlreadyOrdered = scanner.nextInt();
     scanner.nextLine(); 
     
     System.out.println("Enter Book Author:");
     String bookAuthor = scanner.nextLine();
     

     int totalBookCopies = bookCopiesOrdered + bookCopiesAlreadyOrdered;
     

     Book book1 = new Book(bookTitle, bookPrice, totalBookCopies, bookAuthor);
     
     System.out.println("\nEnter Magazine Title:");
     String magTitle = scanner.nextLine();
     
     System.out.println("Enter Magazine Price:");
     double magPrice = scanner.nextDouble();
     
     System.out.println("Enter Number of Copies Ordered:");
     int magCopiesOrdered = scanner.nextInt();
     
     System.out.println("Enter Number of Copies Already Ordered:");
     int magCopiesAlreadyOrdered = scanner.nextInt();
     scanner.nextLine(); 
     

     int totalMagCopies = magCopiesOrdered + magCopiesAlreadyOrdered;
     

     Magazine mag1 = new Magazine(magTitle, magPrice, totalMagCopies);
     
     System.out.println("Enter Magazine Current Issue:");
     String magIssue = scanner.nextLine();
     mag1.receiveIssue(magIssue);
      
     book1.orderCopies(20);
     mag1.orderQty(30);
     
     System.out.println("\nBook Information:");
     book1.displayBookInfo();
     System.out.println("Total Sale for Book: ₹" + book1.getTotalSale());
     
     System.out.println("\nMagazine Information:");
     mag1.displayMagazineInfo();
     System.out.println("Total Sale for Magazine: ₹" + mag1.getTotalSale());
     
     double totalSale = book1.getTotalSale() + mag1.getTotalSale();
     System.out.println("\nTotal Sale of All Publications: ₹" + totalSale);
     
     scanner.close();
 }
}


