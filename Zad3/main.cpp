#include <iostream>

bool negacja(bool x) { return !x; } 
bool koniunkcja(bool p, bool q) { return p && q; } 
bool alternatywa(bool p, bool q) { return p || q; } 
bool implikacja(bool p, bool q) { return !p || q; }
bool rownowaznosz(bool p, bool q) { return p == q; } 

int main()
{
    {
        int in;
        bool p, q;
        std::cout << "Podaj warosc p: ";
        std::cin >> in;
        p = in;
        std::cout << "Podaj warosc q: ";
        std::cin >> in;
        q = in;

        std::cout << "~p: " << negacja(p) << '\n';
        std::cout << "~q: " << negacja(q) << '\n';

        std::cout << "p ^ q: " << koniunkcja(p, q) << '\n';
        std::cout << "p v q: " << alternatywa(p, q)  << '\n';
    
        std::cout << "p => q: " << implikacja(p, q) << '\n';
        std::cout << "q => p: " << implikacja(q, p) << '\n';

        std::cout << "p <=> q: " << rownowaznosz(p, q) << '\n';
    }

    std::cout << "\n======================\n\n";
    
    {
        int in;
        bool p, q, r;
        std::cout << "Podaj wartosc p: ";
        std::cin >> in;
        p = in;
        
        std::cout << "Podaj wartosc q: ";
        std::cin >> in;
        q = in;
        
        std::cout << "Podaj wartosc r: ";
        std::cin >> in;
        r = in;

        std::cout << "p ^ q: " << koniunkcja(p, q) << '\n';
        std::cout << "p v q: " << alternatywa(p, q) << '\n';

        std::cout << "~p ^ (p v q): " << koniunkcja(negacja(p), alternatywa(p, q)) << '\n';

        std::cout << "(p ^ r) => q: " << implikacja(koniunkcja(p, r), q) << '\n'; 
        std::cout << "~(p <=> (q v r)): " << negacja(rownowaznosz(p, alternatywa(q, r))) << '\n'; 
        std::cout << "[(p => r) v ~q] <=> [p => (r ^ ~q)]: " << rownowaznosz(alternatywa(implikacja(p, r), negacja(q)), implikacja(p, koniunkcja(r, negacja(q)))) << '\n'; 
        std::cout << "[(~r v q) v ~(q ^ r)] => [~(q => p)]: " << implikacja(alternatywa(alternatywa(negacja(r), q), negacja(koniunkcja(q, r))), negacja(implikacja(q, p))) << '\n'; 
    }
    
    return 0;
}