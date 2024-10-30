// Token.java
package highlightingtext;
public class Token {
    public enum ShortTtype {
        UNKNOWN, KEYWORD, NUM, ID, OPERATOR, EOF
    }

    public enum Ttype {
        UNKNOWN, EOF, LVAR, PLUS, MINUS, COMMA, DIV, MOD, LFLOAT_NUM, LNUM, LNAME,
        LLOCAL, LFUNCTION
    }

    private Ttype type = Ttype.EOF;
    private ShortTtype stype = ShortTtype.EOF;
    private int posStartOfWord;
    private int posEndOfWord;

    public Token() {
    }

    public Token(Ttype t) {
        this.type = t;
    }

    public Token(ShortTtype t) {
        this.stype = t;
    }

    public Token(ShortTtype st, Ttype t) {
        this.stype = st;
        this.type = t;
    }

    public Ttype getType() {
        return type;
    }

    public void setType(Ttype type) {
        this.type = type;
    }

    public ShortTtype getStype() {
        return stype;
    }

    public void setStype(ShortTtype stype) {
        this.stype = stype;
    }

    public int getPosStartOfWord() {
        return posStartOfWord;
    }

    public void setPosStartOfWord(int posStartOfWord) {
        this.posStartOfWord = posStartOfWord;
    }

    public int getPosEndOfWord() {
        return posEndOfWord;
    }

    public void setPosEndOfWord(int posEndOfWord) {
        this.posEndOfWord = posEndOfWord;
    }
}