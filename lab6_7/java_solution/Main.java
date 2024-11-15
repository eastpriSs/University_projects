import highlightingtext.*;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main
{
    public static void main(String[] args) {
        List<Document> docs = new ArrayList<>(10);
        docs.add(new Document("testLua.lua"));
        docs.add(new Document("testLua1.lua"));
        docs.add(new Document("testPython.py"));
        docs.add(new Document("testPython1.py"));
        docs.add(new Document("abc"));
        docs.add(new Document("bca"));
        docs.add(new Document("eac"));

        Document foundDoc = docs.stream()
                .filter(a -> a.getFilename().equals("abc"))
                .findFirst()
                .orElse(null);
        if (foundDoc != null) {
            System.out.println("found");
        }

        Comparator<Document> comp = Comparator.comparing(Document::getFilename);
        Collections.sort(docs, comp);

        Document hidden = new Document("testLua1.lua");
        boolean res2 = Collections.binarySearch(docs, hidden, comp) >= 0;

        if (res2) {
            System.out.println("found");
        }
    }
}



