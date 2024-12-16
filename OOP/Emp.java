import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

class Employee {
    private String name;
    private String id;
    private String address;
    private String mailID;
    private String mobileNo;
    private double grossSalary; // Store gross salary here
    private double netSalary;   // Store net salary here

    public Employee(String name, String id, String address, String mailID, String mobileNo) {
        this.name = name;
        this.id = id;
        this.address = address;
        this.mailID = mailID;
        this.mobileNo = mobileNo;
    }

    public void setSalaries(double BP) {
        double DA = BP * 97 / 100;
        double HRA = BP * 10 / 100;
        this.grossSalary = BP + DA + HRA;

        double PF = BP * 12 / 100;
        double SCF = BP * 0.1 / 100;
        this.netSalary = this.grossSalary - PF - SCF;
    }

    public void displayPaySlip(String designation, double basicPay) {
        System.out.println("--------------Pay Slip---------------");
        System.out.println("Employee Name: " + name);
        System.out.println("Employee ID: " + id);
        System.out.println("Mail ID: " + mailID);
        System.out.println("Contact No: " + mobileNo);
        System.out.println("Designation: " + designation);
        System.out.println("Basic Pay: " + basicPay);
        System.out.println("Gross Salary: " + grossSalary + "\tNet Salary: " + netSalary);
        System.out.println("---------------------------------------");
    }
}

class Programmer extends Employee {
    private double BP;

    public Programmer(String name, String id, String address, String mailID, String mobileNo, double BP) {
        super(name, id, address, mailID, mobileNo);
        this.BP = BP;
        this.setSalaries(BP);
    }

    public void paySlip() {
        super.displayPaySlip("Programmer", BP);
    }
}

class Team_Lead extends Employee {
    private double BP;

    public Team_Lead(String name, String id, String address, String mailID, String mobileNo, double BP) {
        super(name, id, address, mailID, mobileNo);
        this.BP = BP;
        this.setSalaries(BP);
    }

    public void paySlip() {
        super.displayPaySlip("Team_Lead", BP);
    }
}

class Assistant_Project_Manager extends Employee {
    private double BP;

    public Assistant_Project_Manager(String name, String id, String address, String mailID, String mobileNo, double BP) {
        super(name, id, address, mailID, mobileNo);
        this.BP = BP;
        this.setSalaries(BP);
    }

    public void paySlip() {
        super.displayPaySlip("Assistant Project Manager", BP);
    }
}

class Project_Manager extends Employee {
    private double BP;

    public Project_Manager(String name, String id, String address, String mailID, String mobileNo, double BP) {
        super(name, id, address, mailID, mobileNo);
        this.BP = BP;
        this.setSalaries(BP);
    }

    public void paySlip() {
        super.displayPaySlip("Project Manager", BP);
    }
}

public class Emp {
    ArrayList<Employee> obj = new ArrayList<>();
    Scanner get = new Scanner(System.in);

    public void addEmployee() {
        System.out.println("Enter the Employee Name: ");
        String name = get.next();
        System.out.println("Enter the Employee ID: ");
        String id = get.next();
        System.out.println("Enter the Address: ");
        String address = get.next();
        System.out.println("Enter the Mail ID: ");
        String mailID = get.next();
        System.out.println("Enter the Mobile No: ");
        String mobileNo = get.next();
        System.out.println("Enter the Designation: ");
        System.out.println("1. Programmer \n2. Team Lead \n3. Assistant Project Manager \n4. Project Manager");
        int c = get.nextInt();
        System.out.println("Enter the basic pay: ");
        double bPay = get.nextDouble();

        switch (c) {
            case 1:
                obj.add(new Programmer(name, id, address, mailID, mobileNo, bPay));
                break;
            case 2:
                obj.add(new Team_Lead(name, id, address, mailID, mobileNo, bPay));
                break;
            case 3:
                obj.add(new Assistant_Project_Manager(name, id, address, mailID, mobileNo, bPay));
                break;
            case 4:
                obj.add(new Project_Manager(name, id, address, mailID, mobileNo, bPay));
                break;
            default:
                System.out.println("Invalid choice!");
        }
    }

    public void displayEmployee() {
        for (Employee e : obj) {
            if (e instanceof Programmer) {
                ((Programmer) e).paySlip();
            } else if (e instanceof Team_Lead) {
                ((Team_Lead) e).paySlip();
            } else if (e instanceof Assistant_Project_Manager) {
                ((Assistant_Project_Manager) e).paySlip();
            } else if (e instanceof Project_Manager) {
                ((Project_Manager) e).paySlip();
            }
        }
    }

    public static void main(String args[]) throws IOException {
        Emp x = new Emp();
        String check = "y";
        Scanner scr = new Scanner(System.in);
        int ch;

        do {
            System.out.println("Enter your choice: ");
            System.out.println("\n1. Add Employee \n2. Display Pay Slip");
            ch = scr.nextInt();
            switch (ch) {
                case 1:
                    x.addEmployee();
                    break;
                case 2:
                    x.displayEmployee();
                    break;
                default:
                    System.out.println("Invalid choice!");
                    break;
            }
            System.out.println("Do you want to continue? (Press 'y')");
            check = scr.next();
        } while (check.equalsIgnoreCase("y"));
    }
}
