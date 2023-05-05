import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int capacity = scanner.nextInt();
        scanner.nextLine();
        String input_string = scanner.nextLine();
        String[] input_split = input_string.split(" ");

        MyQueue q = new MyQueue(capacity);

        for (String x: input_split) {
            if (x.equals("pop")) {
                q.dequeue();
            } else {
                int val = Integer.parseInt(x);
                q.enqueue(val);
            }
        }
    }
}

class MyQueue {
    private int capacity;
    private Stack<Integer> s1 = new Stack<Integer>();
    private Stack<Integer> s2 = new Stack<Integer>();

    MyQueue(int c) {
        capacity = c;
    }
    
    public void enqueue(int x) {
        if (s1.size() < capacity) {
            s1.push(x);
        } else {
            System.out.println("Queue is full");
        }
    }

    public void dequeue() {
        if (s1.size() == 0) {
            System.out.println("Queue is empty");
        } else {
            while (!s1.empty()) {
                s2.push(s1.pop());
            }

            System.out.println(s2.pop());

            while (!s2.empty()) {
                s1.push(s2.pop());
            }
        }
    }
}
