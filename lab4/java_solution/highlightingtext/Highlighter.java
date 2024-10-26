// Highlighter.java
package highlightingtext;
import java.util.List;

public class Highlighter {
    private Document chdr;
    private Lexer lex;

    public Highlighter(Document chs) {
        this.chdr = chs;
        this.lex = new Lexer(chs);
    }

    public Highlighter(Document chs, Lexer l) {
        this.chdr = chs;
        this.lex = l;
    }

    public void addKeywords(List<String> kws) {
        for (String kw : kws) {
            lex.addKeyword(kw);
        }
    }

    public Document highlightCharStream() {
        Token currTkn = lex.scan();
        while (currTkn.getStype() != Token.ShortTtype.EOF) {
            switch (currTkn.getStype()) {
                case NUM:
                    chdr.setFormat(currTkn.getPosStartOfWord(), currTkn.getPosEndOfWord(),
                            Format.CharColor.GREEN);
                    break;
                case KEYWORD:
                    chdr.setFormat(currTkn.getPosStartOfWord(), currTkn.getPosEndOfWord(),
                            Format.CharColor.BLUE);
                    break;
                case ID:
                    chdr.setFormat(currTkn.getPosStartOfWord(), currTkn.getPosEndOfWord(),
                            Format.CharColor.RED);
                    break;
                default:
                    chdr.setFormat(currTkn.getPosStartOfWord(), currTkn.getPosEndOfWord(),
                            Format.CharColor.WHITE);
            }
            currTkn = lex.scan();
        }
        return chdr;
    }
}