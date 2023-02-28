import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < testCases; ++i) {
            String input_line = scanner.nextLine();
            String[] inputs = input_line.split(" ");
            String type = inputs[0];
            String atr = inputs[1];
            String name = inputs[2];
            double price = Double.parseDouble(inputs[3]);

            if (type.equals("electronic")) {
                Electronic electronic = new Electronic(name, atr, price);
                electronic.sell();
            } else {
                Clothing clothing = new Clothing(name, atr, price);
                clothing.sell();
            }
        }

        scanner.close();
    }
}

class Product {
    protected String name;
    protected double price;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public void sell() {
        System.out.println("The product " + name + " with price " + price + " is being sold.");
    }
}

class Electronic extends Product {
    private String brand;

    public Electronic(String name, String brand, double price) {
        super(name, price);
        this.brand = brand;
    }

    @Override
    public void sell() {
        System.out.println("The " + brand + " electronic product " + super.name + " with price " + super.price + " is being sold.");
    }
}

class Clothing extends Product {
    private String size;

    public Clothing(String name, String size, double price) {
        super(name, price);
        this.size = size;
    }

    @Override
    public void sell() {
        System.out.println("The " + size + " sized clothing " + super.name + " with price " + super.price + " is being sold.");
    }
}
