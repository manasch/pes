import java.util.*;
import java.lang.Math;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < testCases; ++i) {
            String input_line = scanner.nextLine();
            String[] input = input_line.split(" ");
            String shape = input[0];
            int radius = Integer.parseInt(input[1]);
            int height = Integer.parseInt(input[2]);

            Circle c = null;

            if (shape.equals("CYLINDER")) {
                Cylinder cylinder = new Cylinder(radius, height);
                System.out.println((int) Math.ceil(cylinder.area()) + " " + (int) Math.ceil(cylinder.volume()));

            } else if (shape.equals("CONE")) {
                Cone cone = new Cone(radius, height);
                System.out.println((int) Math.ceil(cone.area()) + " " + (int) Math.ceil(cone.volume()));
            }
        }

        scanner.close();
    }
}

class Circle {
    int radius;

    Circle(int r) {
        this.radius = r;
    }

    int area() {
        return (int) Math.ceil((3.14f * this.radius * this.radius));
    }
}

class Cylinder extends Circle {
    int height;
    Cylinder(int r, int h) {
        super(r);
        this.height = h;
    }

    @Override
    int area() {
        return (int) Math.ceil((2 * 3.14 * this.radius * (this.radius + this.height)));
    }

    int volume() {
        return (int) Math.ceil((3.14 * this.radius * this.radius * this.height));
    }
}

class Cone extends Circle {
    int height;
    double l;
    Cone(int r, int h) {
        super(r);
        this.height = h;
        l = Math.sqrt(this.radius * this.radius + this.height * this.height);
    }

    @Override
    int area() {
        return (int) Math.ceil(3.14 * this.radius * (this.radius + l));
    }

    int volume() {
        return (int) Math.ceil((3.14 * this.radius * this.radius * height) / 3);
    }
}
