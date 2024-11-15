// Document.java
package highlightingtext;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public class Document {
    private static final int DEFAULT_BUFFER_SIZE = 2048;
    private ArrayList<Format.CharColor> formatChars = new ArrayList<>(DEFAULT_BUFFER_SIZE);
    private List<Character> chstr = new ArrayList<>(DEFAULT_BUFFER_SIZE);
    private String fileName;

    private Document()
    {}

    public Document(String path) throws IllegalArgumentException {
        try (BufferedReader reader = new BufferedReader(new FileReader(path))) {
            fileName = path;
            int ch;
            while ((ch = reader.read()) != -1) {
                chstr.add((char) ch);
                formatChars.add(Format.CharColor.WHITE);
            }
        } catch (IOException e) {
            throw new IllegalArgumentException("file " + path + " did not open.", e);
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < chstr.size(); ++i)
        {
            sb.append(Format.colorCodes.get(formatChars.get(i)));
            sb.append(chstr.get(i));
        }
        return sb.toString();
    }

    public Document append(String str)
    {
        for (Character c : str.toCharArray()) {
            this.chstr.add(c);   
            this.formatChars.add(Format.CharColor.WHITE);
        }
        return this;
    }

    public Document append(String str, Format.CharColor cl)
    {
        for (Character c : str.toCharArray()) {
            this.chstr.add(c);   
            this.formatChars.add(cl);
        }
        return this;
    }

    public String getFilename() {
        return fileName;
    }

    public void outDocument(PrintStream os) {
        Format.SetConsoleColor setConsoleColor = new Format.SetConsoleColor(os);
        for (int i = 0; i < chstr.size(); i++) {
            setConsoleColor.setColor(formatChars.get(i));
            os.print(chstr.get(i));
            setConsoleColor.setColor(Format.CharColor.WHITE);
        }
    }

    public void setFormat(int begin, int end, Format.CharColor cl) {
        for (int i = begin; i < end; i++) {
            formatChars.set(i,cl);
        }
    }
    
    public List<Character> getChstr() {
        return chstr;
    }

    public Document shallowCopy() {
        Document newDocument = new Document();
        newDocument.chstr.addAll(chstr);
        newDocument.formatChars.addAll(formatChars);
        return newDocument;
    }

    public Document deepCopy() {
        Document newDocument = new Document();
        for (Character c : chstr) {
            newDocument.chstr.add(c);
        }
        for (Format.CharColor color : formatChars) {
            newDocument.formatChars.add(color);
        }
        return newDocument;
    }
}