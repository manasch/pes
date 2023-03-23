// Multithreading in java, download multiple files, each file on a separate thread.

import java.util.regex.*;
import java.io.*;
import java.net.*;

class Downloader {
    public static void main(String[] args) {
        final String urlFile = "urls.txt";
        try (BufferedReader reader = new BufferedReader(new FileReader(urlFile))) {
            
            String line;
            while ((line = reader.readLine()) != null) {
                Thread thread = new FileDownloaderThread(line);
                thread.start();
            }

            reader.close();
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private static class FileDownloaderThread extends Thread {
        private String fileURL;
        public FileDownloaderThread(String url) {
            this.fileURL = url;
        }

        public void run() {
            try {
                URL urlObject = new URL(this.fileURL);
                String fileName = extractFileName(urlObject);
                System.out.println("Downloading: " + fileName + " Thread: " + Thread.currentThread().getId());
                try (
                        BufferedInputStream bin = new BufferedInputStream(urlObject.openStream());
                        FileOutputStream fos = new FileOutputStream(fileName)
                    ) {
                    byte[] buffer = new byte[2048];
                    int bytesRead;
                    while ((bytesRead = bin.read(buffer, 0, 2048)) != -1) {
                        fos.write(buffer, 0, bytesRead);
                    }
                    fos.close();
                }
                System.out.println("Finished Downloading: " + fileName + " Thread: " + Thread.currentThread().getId());
            } catch (Exception e) {
                System.out.println("Error downloading from " + this.fileURL + " " + e.getMessage());
            }
        }
    }

    private static String extractFileName(URL url) {
        String path = url.getPath();
        String regex = ".*/(.*)";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(path);
        if (matcher.matches()) {
            return matcher.group(1);
        }
        return "unknown";
    }
}
