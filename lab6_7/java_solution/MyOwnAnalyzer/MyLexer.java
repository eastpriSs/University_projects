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
        String lex = new String();
        if (token.getStype() == Token.ShortTtype.KEYWORD) {
            for(int i = token.getPosStartOfWord(); i < token.getPosEndOfWord(); ++i){
                lex += chstr.get(i);
            }
        }
        token.setType(table.get(lex));
        return token;
    }

    public Token myScan() {
        Token token = new Token();
        return token;
    }
}
