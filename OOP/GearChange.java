import java.util.Scanner;

interface Vehicle {
    void Gear_change(int speed);
    int Speed_Up(int increase);
    int Apply_Brakes(int decrease);
}

class Bicycle implements Vehicle {
    private int speed = 0;
    private int gear = 0;

    public void Gear_change(int speed1) {
        if (speed1 == 0) {
            System.out.println("Bicycle is on neutral gear");
        } else if (speed1 > 0 && speed1 <= 10) {
            gear = 1;
            System.out.println("Gear Changed to " + gear);
        } else if (speed1 > 10 && speed1 <= 20) {
            gear = 2;
            System.out.println("Gear Changed to " + gear);
        } else if (speed1 > 20 && speed1 <= 30) {
            gear = 3;
            System.out.println("Gear Changed to " + gear);
        } else if (speed1 > 30) {
            gear = 4;
            System.out.println("Gear Changed to " + gear);
        }
    }

    public int Speed_Up(int increase) {
        if ((speed + increase) <= 80) {
            speed += increase;
            System.out.println("Bicycle speed increased to: " + speed + " km/h");
            return speed;
        } else {
            System.out.println("Speed limit can't exceeded than 80 km/h");
            return speed;
        }
    }

    public int Apply_Brakes(int decrease) {
        if ((speed - decrease) <= 0) {
            speed = 0;
            System.out.println("Bicycle is neutral. Can't decrease more speed");
            return 0;
        } else {
            speed -= decrease;
            System.out.println("Bicycle speed decreased to: " + speed + " km/h");
            return speed;
        }
    }
}

class Bike implements Vehicle {
    private int speed = 0;
    private int gear = 0;

    public void Gear_change(int speed1) {
        if (speed1 == 0) {
            System.out.println("Bike is on neutral gear");
        } else if (speed1 > 0 && speed1 <= 10) {
            gear = 1;
            System.out.println("Gear Changed to " + gear);
        } else if (speed1 > 10 && speed1 <= 30) {
            gear = 2;
            System.out.println("Gear Changed to " + gear);
        } else if (speed1 > 30 && speed1 <= 40) {
            gear = 3;
            System.out.println("Gear Changed to " + gear);
        } else if (speed1 > 40) {
            gear = 4;
            System.out.println("Gear Changed to " + gear);
        }
    }

    public int Speed_Up(int increase) {
        if ((speed + increase) <= 120) {
            speed += increase;
            System.out.println("Bike speed increased to: " + speed + " km/h");
            return speed;
        } else {
            System.out.println("Speed limit can't exceeded than 120 km/h");
            return speed;
        }
    }

    public int Apply_Brakes(int decrease) {
        if ((speed - decrease) <= 0) {
            speed = 0;
            System.out.println("Bike is neutral. Can't decrease more speed");
            return 0;
        } else {
            speed -= decrease;
            System.out.println("Bike speed decreased to: " + speed + " km/h");
            return speed;
        }
    }
}

class Car implements Vehicle {
    private int speed = 0;
    private int gear = 0;

    public void Gear_change(int speed1) {
        if (speed1 == 0) {
            System.out.println("Car is on neutral gear");
        } else if (speed1 > 0 && speed1 <= 20) {
            gear = 1;
            System.out.println("Gear Changed to " + gear);
        } else if (speed1 > 20 && speed1 <= 30) {
            gear = 2;
            System.out.println("Gear Changed to " + gear);
        } else if (speed1 > 30 && speed1 <= 50) {
            gear = 3;
            System.out.println("Gear Changed to " + gear);
        } else if (speed1 > 50 && speed1 <= 60) {
            gear = 4;
            System.out.println("Gear Changed to " + gear);
        } else if (speed1 > 60) {
            gear = 5;
            System.out.println("Gear Changed to " + gear + " It is the top gear");
        }
    }

    public int Speed_Up(int increase) {
        if ((speed + increase) <= 180) {
            speed += increase;
            System.out.println("Car speed increased to: " + speed + " km/h");
            return speed;
        } else {
            System.out.println("Speed limit can't exceeded than 180 km/h");
            return speed;
        }
    }

    public int Apply_Brakes(int decrease) {
        if ((speed - decrease) <= 0) {
            speed = 0;
            System.out.println("Car is neutral. Can't decrease more speed");
            return 0;
        } else {
            speed -= decrease;
            System.out.println("Car speed decreased to: " + speed + " km/h");
            return speed;
        }
    }
}

public class GearChange {
        public void execute(Vehicle v) {
            int s, ch;
            String c;

            Scanner scr = new Scanner(System.in);
            do {
                System.out.println("\n1. Increase Speed 2. Apply Brakes 3. Exit \nEnter your choice: ");
                ch = scr.nextInt();

                if (ch == 1) {
                    do {
                        s = v.Speed_Up(20);
                        v.Gear_change(s);
                        System.out.println("Do you want to speed up more? 'Y' or 'N' ");
                        c = scr.next();
                    } while (c.equalsIgnoreCase("y"));
                } else if (ch == 2) {
                    do {
                        s = v.Apply_Brakes(20);
                        v.Gear_change(s);
                        System.out.println("Do you want to decrease more speed? 'Y' or 'N' ");
                        c = scr.next();
                    } while (c.equalsIgnoreCase("y"));
                } else if (ch == 3) {
                    return;
                }
            } while (ch!=3);
        }

    public static void main(String[] args) {
        int ch;

        GearChange op = new GearChange();
        Vehicle myBicycle = new Bicycle();
        Vehicle myBike = new Bike();
        Vehicle myCar = new Car();
        String choice = "Y";
        
        Scanner scr = new Scanner(System.in);

        do {
            System.out.println("\n1. Bicycle 2. Bike 3. Car 4. Exit \nChoose a Vehicle: ");
            ch = scr.nextInt();

            switch (ch) {
                case 1:
                    op.execute(myBicycle);
                    System.out.println("Do you want to continue? 'Y' or 'N' ");
                    choice = scr.next();
                    break;
                case 2:
                    op.execute(myBike);
                    System.out.println("Do you want to continue? 'Y' or 'N' ");
                    choice = scr.next();
                    break;
                case 3:
                    op.execute(myCar);
                    System.out.println("Do you want to continue? 'Y' or 'N' ");
                    choice = scr.next();
                    break;
                case 4:
                    System.out.println("Do you want to continue for other Vehicle? 'Y' or 'N' ");
                    choice = scr.next();
                    break;
                default:
                    System.out.println("Enter Correct Choice");
            }
        } while(choice.equalsIgnoreCase("y"));
    }
}