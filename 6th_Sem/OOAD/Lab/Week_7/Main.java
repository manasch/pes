import java.util.*;
import java.io.*;

class Config implements Serializable {
    private HashMap<String, String> configCfg;

    Config() {
        configCfg = new HashMap<String, String>();
        configCfg.put("Path", null);
        configCfg.put("Version", null);
        configCfg.put("SystemVersion", null);
    }

    public HashMap<String, String> getHashMap() {
        return this.configCfg;
    }

    // public void setHashMap(HashMap<String, String> config) {
    //     this.configCfg = config;
    // }
}

class ConfigSerDes {
    private static final String FILENAME = "config.cfg";

    public static Config loadConfig() {
        Config config = null;

        try {
            FileInputStream fin = new FileInputStream(FILENAME);
            ObjectInputStream oin = new ObjectInputStream(fin);

            config = (Config) oin.readObject();
            oin.close();
            fin.close();
        } catch (Exception e) {
            System.out.println("\nconfig.cfg doesn't exist, creating a new config file.");
            config = new Config();
            saveConfig(config);
        }

        return config;
    }

    public static void saveConfig(Config config) {
        try {
            FileOutputStream fout = new FileOutputStream(FILENAME);
            ObjectOutputStream oout = new ObjectOutputStream(fout);

            oout.writeObject(config);
            oout.close();
            fout.close();
            System.out.println("\nSaved to file.");
        } catch (Exception e) {
            System.out.println("\nAn error occured" + e);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Config config = ConfigSerDes.loadConfig();
        HashMap<String, String> mmap = config.getHashMap();
        String input = "";

        System.out.println("\nInitial config:");
        System.out.println(mmap);

        while (true) {
            System.out.print("\nq: Quit\nn: New\nv: View\nChoice: ");
            input = sc.nextLine();
            if (input.equals("q")) {
                break;
            }
            else if (input.equals("v")) {
                System.out.println("\nConfig File:");
                System.out.println(config.getHashMap());
            }
            else if (input.equals("n")) {
                System.out.print("\nEnter Key: ");
                String key = sc.nextLine();
                System.out.print("Enter Value: ");
                String value = sc.nextLine();
                mmap.put(key, value);
                ConfigSerDes.saveConfig(config);
            }
            else {
                System.out.println("\nInvalid Input!");
                continue;
            }
        }
    }
}

