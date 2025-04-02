#include <iostream>
/*

    Input Iterator: Kann zum Lesen von Daten in einer einmaligen Durchlauf-Sequenz verwendet werden. Man kann mit ihnen durch Container wie Listen oder Dateien iterieren, dabei kann jeder Wert nur einmal gelesen werden.

    Output Iterator: Ermöglicht das Schreiben von Daten in einer einmaligen Durchlauf-Sequenz. Diese Iteratoren können zum Einfügen oder Modifizieren von Daten in Containern verwendet werden.

    Forward Iterator: Kombiniert die Eigenschaften von Input- und Output-Iteratoren. Mit Forward-Iteratoren kann man durch einen Container iterieren und Daten lesen sowie schreiben. Der Zugriff erfolgt sequenziell in eine Richtung.

    Bidirectional Iterator: Erweitert den Forward Iterator um die Möglichkeit, auch rückwärts durch den Container zu iterieren. Diese Iteratoren sind nützlich für Container, die eine bidirektionale Durchquerung unterstützen, wie beispielsweise die doppelt verkettete Liste (std::list).

    Random Access Iterator: Bietet den flexibelsten Zugriff, indem er Funktionen von Pointern nachahmt, einschließlich der Fähigkeit, direkt auf jedes Element zuzugreifen. Sie können nicht nur vorwärts und rückwärts iterieren, sondern auch Sprünge innerhalb des Containers machen. Dieser Typ ist typisch für Arrays und Vektoren (std::vector).
 */

class Integers{
private:
    int data[200];

    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = int*;
        using refernce = int&;

        Iterator(pointer ptr):m_ptr(ptr){}
        refernce operator*() const {return *m_ptr;}
        pointer operator->() {return m_ptr;}

        Iterator& operator++(){m_ptr++; return *this;}
        Iterator operator++(int){Iterator temp = *this; ++(*this); return temp;}
        pointer m_ptr;

        friend bool operator==(const Iterator&a, const Iterator &b){return a.m_ptr == b.m_ptr;}
        friend bool operator!=(const Iterator&a, const Iterator &b){return a.m_ptr != b.m_ptr;}
    };
public:
    Iterator begin() { return Iterator(&data[0]);}
    Iterator end() { return Iterator(&data[200]);}
};

int main() {

    Integers integers;

    for(auto &i: integers) {
        i = 100;
    }
    for(auto &i: integers) {
        std::cout << i << std::endl;
    }
    for(auto iter = integers.begin(); iter != integers.end(); ++iter ){
        std::cout << *iter << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
