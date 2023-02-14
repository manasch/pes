import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc_obj = new Scanner(System.in);
        int num = sc_obj.nextInt();
        String line = "";

        sc_obj.nextLine();
        while(sc_obj.hasNextLine()) {
            line = sc_obj.nextLine();
            String[] inputs = line.split(" ");
            if (inputs.length == 1 && inputs[0].equals("None")) {
                new Bird();
            }
            else if (inputs.length == 1) {
                new Bird(inputs[0]);
            }
            else if (inputs.length == 2) {
                new Bird(inputs[0], Integer.parseInt(inputs[1]));
            }
            else if (inputs.length == 3) {
                new Bird(inputs[0], Integer.parseInt(inputs[1]), Integer.parseInt(inputs[2]));
            }
            else continue;
        }
    }
}

class Bird {
    public Bird() {
        System.out.println("A bird is flying.");
    }
    public Bird(String name) {
        System.out.println(name + " is flying.");
    }
    public Bird(String name, int height) {
        System.out.println(name + " is flying at height " + height + " metres.");
    }
    public Bird(String name, int height, int speed) {
        System.out.println(name + " is flying at height " + height + " metres and at speed " + speed + " metres per second.");
    }
}
