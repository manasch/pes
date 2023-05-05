import java.util.*;

abstract class TestQuestion {
    protected String question;
    abstract public void readQuestion();

    public String toString() {
        return "> " + question + "\n";
    }
}

class ShortAnswer extends TestQuestion {
    private int numLines = 1;
    
    @Override
    public void readQuestion() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nShort Answer Question: ");
        question = scanner.nextLine();
    }

    public String toString() {
        return super.toString() + "Number of Lines: " + numLines;
    }
}

class LongAnswer extends TestQuestion {
    private int numLines;

    @Override
    public void readQuestion() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nLong Answer Question: ");
        question = scanner.nextLine();
        System.out.print("Enter the number of lines: ");
        numLines = scanner.nextInt();
    }

    public String toString() {
        return super.toString() + "Number of lines: " + numLines;
    }
}

class MCQ extends TestQuestion {
    private int numChoices;
    private String[] choices;

    @Override
    public void readQuestion() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nMCQ Question: ");
        question = scanner.nextLine();
        System.out.print("Enter the number of choices: ");
        numChoices = scanner.nextInt();

        scanner.nextLine();
        choices = new String[numChoices];
        for (int i = 0; i < numChoices; ++i) {
            System.out.print("Enter Choice " + (i + 1) + ": ");
            choices[i] = scanner.nextLine();
        }
    }

    public String toString() {
        String MCQString = "";
        for (int i = 0; i < numChoices; ++i) {
            MCQString += "Option " + (i + 1) + ": " + choices[i] + "\n";
        }

        return super.toString() + "\n" + "Number of Choices: " + numChoices + "\n" + MCQString;
    }
}

class TQManager {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the total number of questions: ");
        int numQ = scanner.nextInt();
        scanner.nextLine();

        TestQuestion[] TestQuestions = new TestQuestion[numQ];

        int choice;
        for (int i = 0; i < numQ; ++i) {
            System.out.println("\nChoose the type of question");
            System.out.println("1. ShortAnswer\n2. LongAnswer\n3. MCQ");
            System.out.print("Choice: ");

            choice = scanner.nextInt();

            if (choice == 1) {
                TestQuestions[i] = new ShortAnswer();
            }
            else if (choice == 2) {
                TestQuestions[i] = new LongAnswer();
            }
            else if (choice == 3) {
                TestQuestions[i] = new MCQ();
            }
            else {
                System.out.println("Invalid Input");
                --i;
                continue;
            }

            TestQuestions[i].readQuestion();
        }


        for (int i = 0; i < numQ; ++i) {
            System.out.println("\nQuestion: " + (i + 1));
            System.out.println(TestQuestions[i].toString());
        }
    }
}
