package sib;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

class Employee{
    private String name;
    private String id;
    private String address;
    private String mailID;
    private String mobileNo;

    public Employee(String name, String id, String address, String mailID,String mobileNo){
        this.name=name;
        this.id=id;
        this.address=address;
        this.mailID=mailID;
        this.mobileNo=mobileNo;
    }

    public void display(){
        System.out.println("Employee Name: "+name+"\n"+"Employee ID: "+id);
        System.out.println("Mail ID: "+mailID+"\nContact No: "+mobileNo);        
    }

    public double calculate_GS(double BP){
        double DA=BP*97/100;
        double HRA=BP*10/100;
        double GrossSalary=BP+DA+HRA;
        double PF=BP*12/100;
        double SCF=BP*0.1/100;
        double NetSalary=GrossSalary-PF-SCF;
        return GrossSalary;
    }

    public double calculate_NS(double BP, double GS){
        double PF=BP*12/100;
        double SCF=BP*0.1/100;
        double NetSalary=GS-PF-SCF;
        return NetSalary;
    }

    public void paySlip(double GS,double NS){
    }
}

class Programmer extends Employee{
    private double BP;
    private String des;

    public Programmer(String name, String id, String address, String mailID, String mobileNo, double bPay, String des){
        super(name,id,address,mailID,mobileNo);
        BP=bPay;
        this.des=des;
    }

    public void paySlip(double GS, double NS){
        System.out.println("--------------Pay Slip--------------");
        this.display();
        System.out.println("Designation: "+this.des);
        System.out.println("Basic Pay: "+this.BP);
        System.out.println("Gross Salary: "+GS+"\t"+"Net Salary: "+NS);
        System.out.println("---------------------------------------");
    }
}

class Team_Lead extends Employee{
    private double BP;
    private String des;
    public Team_Lead(String name, String id, String address, String mailID, String mobileNo, double bPay, String des){
        super(name,id,address,mailID,mobileNo);
        BP=bPay;
        this.des=des;
    }

    public void paySlip(double GS, double NS){
        System.out.println("--------------Pay Slip---------------");
        this.display();
        System.out.println("Designation: "+des);
        System.out.println("Basic Pay: "+BP);
        System.out.println("Gross Salary: "+GS+"\t"+"Net Salary: "+NS);
        System.out.println("---------------------------------------");
    }
}

class Assistant_Project_Manager extends Employee{
    private double BP;
    private String des;
    public Assistant_Project_Manager(String name, String id, String address, String mailID, String mobileNo, double bPay, String des){
        super(name,id,address,mailID,mobileNo);
        BP=bPay;
        this.des=des;
    }

    public void paySlip(double GS, double NS){
        System.out.println("--------------Pay Slip---------------");
        this.display();
        System.out.println("Designation: "+des);
        System.out.println("Basic Pay: "+BP);
        System.out.println("Gross Salary: "+GS+"\t"+"Net Salary: "+NS);
        System.out.println("---------------------------------------");
    }
}

class Project_Manager extends Employee{
    private double BP;
    private String des;
    public Project_Manager(String name, String id, String address, String mailID, String mobileNo, double bPay, String des){
        super(name,id,address,mailID,mobileNo);
        BP=bPay;
        this.des=des;
    }

    public void paySlip(double GS, double NS){
        System.out.println("--------------Pay Slip---------------");
        this.display();
        System.out.println("Designation: "+des);
        System.out.println("Basic Pay: "+BP);
        System.out.println("Gross Salary: "+GS+"\t"+"Net Salary: "+NS);
        System.out.println("---------------------------------------");
    }
}

public class Emp{
    Employee e;
    double GrossSalary, NetSalary;
    ArrayList<Employee> obj=new ArrayList<>();
    Scanner get=new Scanner(System.in);

    public void addEmployee(){
        double bPay;
        System.out.println("Enter the Employee Name: ");
        String name=get.next();
        System.out.println("Enter the Employee ID: ");
        String id=get.next();
        System.out.println("Enter the Address: ");
        String address=get.next();    
        System.out.println("Enter the Mail ID: ");
        String mailID=get.next();  
        System.out.println("Enter the Mobile No: ");
        String mobileNo=get.next();  
        System.out.println("Enter the Designation: ");
        System.out.println("1.Programmer \n2.Team Lead \n3.Assistant Project Manager \n4.Project Manager");
        int c=get.nextInt();
        System.out.println("Enter the basic pay: ");
        bPay=get.nextDouble();

        if(c==1){
            e= new Programmer(name, id, address, mailID, mobileNo, bPay, "Programmer");
            obj.add(e);
            GrossSalary=e.calculate_GS(bPay);
            NetSalary=e.calculate_NS(bPay, GrossSalary);
        }
        else if(c==2){
            e= new Team_Lead(name, id, address, mailID, mobileNo, bPay, "Team_Lead");
            obj.add(e);
            GrossSalary=e.calculate_GS(bPay);
            NetSalary=e.calculate_NS(bPay, GrossSalary);
        }
        else if(c==3){
            e= new Assistant_Project_Manager(name, id, address, mailID, mobileNo, bPay, "Assistant_Project_Manager");
            obj.add(e);
            GrossSalary=e.calculate_GS(bPay);
            NetSalary=e.calculate_NS(bPay, GrossSalary);
        }
        else if(c==4){
            e= new Project_Manager(name, id, address, mailID, mobileNo, bPay, "Project_Manager");
            GrossSalary=e.calculate_GS(bPay);
            NetSalary=e.calculate_NS(bPay, GrossSalary);
            obj.add(e);
        }
    }

    public void displayEmployee(){
        for(Employee e:obj){
            e.paySlip(GrossSalary, NetSalary);
        }
    }

    public static void main(String args[]) throws IOException{
        Emp x=new Emp();
        String check;
        Scanner scr=new Scanner(System.in);
        int ch=0;
        do{
            System.out.println("Enter your choice: ");
            System.out.println("\n1.Add Employee \n2.Display Pay Slip");
            ch=scr.nextInt();
            switch(ch){
                case 1:
                    x.addEmployee();
                    System.out.println("Do you want to continue?(Press 'y')");
                    check=x.get.next();
                    break;
                case 2:
                    x.displayEmployee();
                    System.out.println("Do you want to continue?(Press 'y')");
                    check=x.get.next();
                    break;
                
                default:
                    System.out.println("Enter choice: ");
                    return;
            }
        }while(check.equalsIgnoreCase("y"));
    }
}