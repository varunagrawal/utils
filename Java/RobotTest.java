import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class RobotTest {

    public static void type(Robot robo, int key) {
        robo.keyPress(key);
        robo.keyRelease(key);
        robo.delay(1000);
    }

    public static void main(String[] args) throws Exception {

        Robot robo = new Robot();

        robo.mouseMove(200, 200);

        robo.delay(5000);

        RobotTest.type(robo, KeyEvent.VK_V);
        RobotTest.type(robo, KeyEvent.VK_A);
        RobotTest.type(robo, KeyEvent.VK_R);
        RobotTest.type(robo, KeyEvent.VK_U);
        RobotTest.type(robo, KeyEvent.VK_N);
        RobotTest.type(robo, KeyEvent.VK_SPACE);
        RobotTest.type(robo, KeyEvent.VK_R);
        RobotTest.type(robo, KeyEvent.VK_O);
        RobotTest.type(robo, KeyEvent.VK_X);

    }
}
