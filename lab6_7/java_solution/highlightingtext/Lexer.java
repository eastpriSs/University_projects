// Lexer.java
package highlightingtext;
import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;


public class Lexer {
    private static final int DEFAULT_KEYWORD_COUNT = 25;
    private ArrayList<String> keywords = new ArrayList<>();
    private int begin;
    private int it;
    private int forwardIt;

    protected List<Character> chstr;
    

    private class Counter
    {
        int getAmountOfKeywords()
        {
            return Lexer.table.size();
        }
    }

    protected static final Map<String, Token.Ttype> table = new HashMap<>();
    static {
        table.put("local", Token.Ttype.LLOCAL);
    }

    public static boolean isKeyword(String lex) {
        return table.containsKey(lex);
    }

    public int getAmountOfKeywords()
    {
        return new Counter().getAmountOfKeywords();
    }

    public Lexer(Document cs) {
        this.chstr = cs.getChstr();
        this.begin = 0;
        this.it = begin;
        this.forwardIt = it + 1;
        keywords.ensureCapacity(DEFAULT_KEYWORD_COUNT);
    }

    public void addKeyword(String kw) {
        keywords.add(kw);
    }
    public void addKeyword(String kw, Token.Ttype t) {
        keywords.add(kw);
        table.put(kw, t);
    }

    public Token scan() {
        Token scanningToken = new Token();
        if (it >= chstr.size()) {
            return scanningToken;
        }
        char currentChar = chstr.get(it);
        if (Character.isDigit(currentChar)) {
            while (forwardIt < chstr.size() && Character.isDigit(chstr.get(forwardIt))) {
                forwardIt++;
            }
            scanningToken.setStype(Token.ShortTtype.NUM);
        } else if (Character.isLetter(currentChar)) {
            while (forwardIt < chstr.size() && (Character.isLetter(chstr.get(forwardIt)) || Character.isDigit(chstr.get(forwardIt)))) {
                forwardIt++;
            }
            String lexem = chstr.subList(it, forwardIt).stream().map(String::valueOf).reduce("", String::concat);
            if (keywords.contains(lexem)) {
                scanningToken.setStype(Token.ShortTtype.KEYWORD);
            } else {
                scanningToken.setStype(Token.ShortTtype.ID);
            }
        } else {
            scanningToken.setStype(Token.ShortTtype.UNKNOWN);
        }
        scanningToken.setPosStartOfWord(it - begin);
        scanningToken.setPosEndOfWord(forwardIt - begin);

        it = forwardIt;
        forwardIt = it + 1;
        return scanningToken;
    }
}