import highlightingtext.Document;
import highlightingtext.Highlighter;
import java.util.Arrays;
import java.util.List;


public class Main
{
    public static void main(String[] args) {
        Document[] sources = new Document[2];
        sources[0] = new Document("testPython.py");
        sources[1] = new Document("testLua.lua");
        Highlighter[] highlighters = new Highlighter[2];
        highlighters[0] = new Highlighter(sources[0]);
        highlighters[1] = new Highlighter(sources[1]);
                
        List<String> pyKeywords = Arrays.asList("def", "if", "return", "else");
        highlighters[0].addKeywords(pyKeywords);

        List<String> luaKeywords = Arrays.asList("function", "if", "then", 
                                    "return", "else", "end", "local", "for", "do");
        highlighters[1].addKeywords(luaKeywords);
        

        highlighters[0].highlightCharStream().outDocument(System.out);
        System.out.println("\n\nLua code:");
        highlighters[1].highlightCharStream().outDocument(System.out);
    }
}



