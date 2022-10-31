#include <iostream>
#include <chrono>

std::string SzyfrCezara(std::string in, int offset);
std::string DeszyfrCezara(std::string in, int offset);

std::string SzyfrXOR(std::string in, char mask);

int main()
{
    while (true)
    {
        std::cout << "=============================\n";
        std::cout << "1) Szyfrowanie   - \"Szyfr Cezara\"\n";
        std::cout << "2) Odszyfrowanie - \"Szyfr Cezara\"\n";
        std::cout << "3) Szyfrowanie   - \"XOR\"\n";
        std::cout << "4) Odszyfrowanie - \"XOR\"\n";
        std::cout << "=============================\n";
        std::cout << "Wybierz opcje: ";

        char input;
        std::cin >> input;
        std::cout << "=======================\n";

        switch (input)
        {
            case '1':
            case '2':
            case '3':
            case '4':
                break;
                        
            // exit
            default:
                return 0;
        }
        
        std::cout << "\nPodaj tekst do przetworzenia: ";
        
        std::string in;
        std::cin.ignore();
        std::getline(std::cin, in);


        std::cout << "\nEfekt:\n";
        switch (input)
        {
            case '1':
                std::cout << SzyfrCezara(in, 5);
                break;
                
            case '2':
                std::cout << DeszyfrCezara(in, 5);
                break;
                
            case '3':
            case '4':
                std::cout << SzyfrXOR(in, 126);
                break;
        }
        std::cout << "\n\n";
        
        std::cout << std::flush;
        system("pause");
    }
}

constexpr int letterCount = 'Z' - 'A' + 1;

std::string SzyfrCezara(std::string in, int offset)
{
    for(char& c : in)
    {
        int baseChar;
        if('A' <= c && c <= 'Z')
            baseChar = 'A';
        else if('a' <= c && c <= 'z')
            baseChar = 'a';
        else
            continue;

        c = static_cast<char>((c - baseChar + offset) % letterCount + baseChar);
    }
            
    return in;
}

std::string DeszyfrCezara(std::string in, int offset)
{    
    for(char& c : in)
    {
        int baseChar;
        if('A' <= c && c <= 'Z')
            baseChar = 'A';
        else if('a' <= c && c <= 'z')
            baseChar = 'a';
        else
            continue;

        c = static_cast<char>((c - baseChar - offset + letterCount) % letterCount + baseChar);
    }
    
    return in;
}

std::string SzyfrXOR(std::string in, char mask)
{
    for(char& c : in)
        c ^= mask;

    return in;
}