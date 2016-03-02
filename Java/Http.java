import java.io.*;
import java.net.*;

public class Http {

    public static void main(String[] args) {

        try {
            URL myUrl = new URL("http://www.isical.ac.in/~acmsc/TMW2014/TMW2014.html");
            URLConnection yc = myUrl.openConnection();
            yc.connect();

            BufferedReader in = new BufferedReader(new InputStreamReader(yc.getInputStream()));

            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                System.out.println(inputLine);
            }
            in.close();

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


    }

}

