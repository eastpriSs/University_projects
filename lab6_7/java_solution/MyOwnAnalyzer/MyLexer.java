package MyOwnAnalyzer;
import highlightingtext.Lexer;
import highlightingtext.Document;
import highlightingtext.Token;


public class MyLexer extends Lexer {

    private int it = 0;
    private int forwardIt = it + 1;
    

    public MyLexer(Document cs) {
        super(cs);
        addKeyword("var", Token.Ttype.LVAR);
    }

    @Override
    public Token scan() {
        Token token = super.scan();
        return token;
    }

    public Token myLexerScan() {
        Token token = new Token();
        String expectedKeyword = "var";
        int lengthOfKeyword = 3;
        if (chstr.get(it) == expectedKeyword.charAt(it)) {
            while (chstr.get(forwardIt) == expectedKeyword.charAt(forwardIt)) {
                ++forwardIt;
            }
            if (lengthOfKeyword == (forwardIt - it))
                token.setType(table.get(expectedKeyword));
        }
        
        token.setPosStartOfWord(it);
        token.setPosEndOfWord(forwardIt);
        return token;
    }
}
