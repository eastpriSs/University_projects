// Format.java
package highlightingtext;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;

public class Format {

    public static final String ANSI_RESET   = "\u001B[0m";
    public static final String ANSI_BLACK   = "\u001B[30m";
    public static final String ANSI_RED     = "\u001B[31m";
    public static final String ANSI_GREEN   = "\u001B[32m";
    public static final String ANSI_YELLOW  = "\u001B[33m";
    public static final String ANSI_BLUE    = "\u001B[34m";
    public static final String ANSI_PURPLE  = "\u001B[35m";
    public static final String ANSI_CYAN    = "\u001B[36m";
    public static final String ANSI_WHITE   = "\u001B[37m";

    public enum CharColor {
        WHITE, RED, GREEN, BLUE
    }

    private static final Map<CharColor, String> colorCodes = new HashMap<>();
    static {
        colorCodes.put(CharColor.WHITE, ANSI_WHITE);
        colorCodes.put(CharColor.RED, ANSI_RED);
        colorCodes.put(CharColor.GREEN, ANSI_GREEN);
        colorCodes.put(CharColor.BLUE, ANSI_BLUE);
    }

    public static class SetConsoleColor {
        private PrintStream os;

        public SetConsoleColor(PrintStream os) {
            this.os = os;
        }

        public void setColor(CharColor color) {
            os.print(colorCodes.getOrDefault(color, ANSI_RESET));
        }
    }
}