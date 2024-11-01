package TemplatedDocument;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

public class Document<T> {
    private static final int DEFAULT_BUFFER_SIZE = 2048;
    private ArrayList<Format.CharColor> formatChars = new ArrayList<>(DEFAULT_BUFFER_SIZE);
    private List<T> chstr = new ArrayList<>(DEFAULT_BUFFER_SIZE);

    private Document() {
    }

    public Document(String path) throws IllegalArgumentException {
        try (BufferedReader reader = new BufferedReader(new FileReader(path))) {
            int ch;
            while ((ch = reader.read()) != -1) {
                chstr.add((T) Character.toString((char) ch));
                formatChars.add(Format.CharColor.WHITE);
            }
        } catch (IOException e) {
            throw new IllegalArgumentException("file " + path + " did not open.", e);
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (T c : chstr) {
            sb.append(c.toString());
        }
        return sb.toString();
    }

    public Document<T> append(T element) {
        this.chstr.add(element);
        this.formatChars.add(Format.CharColor.WHITE);
        return this;
    }

    public Document<T> append(T element, Format.CharColor cl) {
        this.chstr.add(element);
        this.formatChars.add(cl);
        return this;
    }

    public void outDocument(PrintStream os) {
        Format.SetConsoleColor setConsoleColor = new Format.SetConsoleColor(os);
        for (int i = 0; i < chstr.size(); i++) {
            setConsoleColor.setColor(formatChars.get(i));
            os.print(chstr.get(i).toString()); // Assuming T has a toString method
            setConsoleColor.setColor(Format.CharColor.WHITE);
        }
    }

    public void setFormat(int begin, int end, Format.CharColor cl) {
        for (int i = begin; i < end; i++) {
            formatChars.set(i, cl);
        }
    }

    public List<T> getChstr() {
        return chstr;
    }

    public Document<T> shallowCopy() {
        Document<T> newDocument = new Document<T>();
        newDocument.chstr.addAll(chstr);
        newDocument.formatChars.addAll(formatChars);
        return newDocument;
    }

    public Document<T> deepCopy() {
        Document<T> newDocument = new Document<T>();
        for (T c : chstr) {
            newDocument.chstr.add(c);
        }
        for (Format.CharColor color : formatChars) {
            newDocument.formatChars.add(color);
        }
        return newDocument;
    }
}