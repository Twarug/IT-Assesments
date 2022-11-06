#include <iostream>
#include <fstream>
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
        
        std::cout << "\nPodaj plik do przetworzenia: ";
        
        std::string path;
        std::cin.ignore();
        std::getline(std::cin, path);
        
        std::fstream file(path);
        std::string text((std::istreambuf_iterator(file)), std::istreambuf_iterator<char>());

        switch (input)
        {
            case '1':
            {
                int offset;
                std::cout << "Podaj przesuniecie: ";
                std::cin >> offset;
                    
                text = SzyfrCezara(text, offset);
                break;
            }
            case '2':
            {
                int offset;
                std::cout << "Podaj przesuniecie: ";
                std::cin >> offset;

                text = DeszyfrCezara(text, offset);
                break;
            }
            case '3':
            case '4':
            {
                char mask;
                std::cout << "Podaj maske: ";
                std::cin >> mask;
                
                text = SzyfrXOR(text, mask);
                break;
            }
        }

        file.seekg(0);
        file << text;
        file.close();
        
        std::cout << "Operacja zakonczona\n";

        std::cout << "Efekt: " << text << '\n';
        
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