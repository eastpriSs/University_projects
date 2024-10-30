import highlightingtext.Document;
import highlightingtext.Highlighter;
import java.util.Arrays;
import java.util.List;

public class Main
{
    public static void main(String[] args) {
        Document[][] sources = new Document[2][2];
        try {
            sources[0][0] = new Document("testPython.py");
            sources[0][1] = new Document("testLua.lua");
            sources[1][0] = new Document("testPython1.py");
            sources[1][1] = new Document("testLua1.lua");
        } 
        catch(IllegalArgumentException e) {
            System.out.println(e.toString());
            return;
        }
        Highlighter[][] highlighters = new Highlighter[2][2];
        highlighters[0][0] = new Highlighter(sources[0][0]);
        highlighters[0][1] = new Highlighter(sources[0][1]);
        highlighters[1][0] = new Highlighter(sources[1][0]);
        highlighters[1][1] = new Highlighter(sources[1][1]);
                
        List<String> pyKeywords = Arrays.asList("def", "if", "return", "else");

        List<String> luaKeywords = Arrays.asList("function", "if", "then", 
                                    "return", "else", "end", "local", "for", "do");
        
        highlighters[0][0].addKeywords(pyKeywords);
        highlighters[0][1].addKeywords(luaKeywords);
        highlighters[1][0].addKeywords(pyKeywords);
        highlighters[1][1].addKeywords(luaKeywords);
        
        System.out.println("\n\ntestPython.py code:");
        highlighters[0][0].highlightCharStream().outDocument(System.out);

        System.out.println("\n\ntestLua.lua code:");
        highlighters[0][1].highlightCharStream().outDocument(System.out);
        
        System.out.println("\n\ntestPython1.py code:");
        highlighters[1][0].highlightCharStream().outDocument(System.out);

        System.out.println("\n\ntestLua1.lua code:");
        highlighters[1][1].highlightCharStream().outDocument(System.out);
    }
}



