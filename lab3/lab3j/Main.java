import highlightingtext.Document;
import highlightingtext.Highlighter; 
import java.util.Arrays;
import java.util.List;

public class Main
{
    public static void main(String[] args) {
        Document document = new Document("test.lua");
        Highlighter highlighter = new Highlighter(document);
        List<String> luaKeywords = Arrays.asList("function", "if", "then", 
                                    "return", "else", "end", "local", "for", "do");
        highlighter.addKeywords(luaKeywords);
        highlighter.highlightCharStream().outDocument(System.out);
    }
}