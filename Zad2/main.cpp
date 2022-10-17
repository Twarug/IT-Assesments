#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <numeric>


void Robot();
void Ciag();
void MoreLess();
void Totolotek();
void Cisnienie();
int LiczbyPitagorejskie(int a, int b, int c);

int main()
{
    while (true)
    {
        std::cout << "\n=======================\n";
        std::cout << "1) Zad1 - Robocik\n";
        std::cout << "2) Zad2 - Ciag\n";
        std::cout << "3) Zad3 - \"ZA DUZO/ZA MALO\"\n";
        std::cout << "4) Zad4 - \"Totolotek\"\n";
        std::cout << "5) Zad5 - Cisnienie\n";
        std::cout << "6) Zad6 - LiczbyPitagorejskie(int a, int b, int c);\n";
        std::cout << "x) Wyjscie\n";
        std::cout << "=======================\n";
        std::cout << "Wybierz opcje: ";

        char input;
        std::cin >> input;
        std::cout << "=======================\n";
        
        switch (input)
        {
            case '1':
                Robot();
                break;
            
            case '2':
                Ciag();
                break;
            
            case '3':
                MoreLess();
                break;
            
            case '4':
                Totolotek();
                break;
            
            case '5':
                Cisnienie();
                break;

            case '6':
            {
                int a, b, c;
                std::cout << "Podaj 3 liczby: ";
                std::cin >> a >> b >> c;
                std::cout << "Wynikiem tej funkcji jest " << LiczbyPitagorejskie(a, b, c) << '\n';
                break;
            }
            
            // exit
            default:
                return 0;
        }
        
        system("pause");
    }
}

void Robot()
{
    int x = 0, y = 0;
    int count;

    std::cout << "Podaj liczbe krokow: ";
    std::cin >> count;

    for(int i = 0; i < count; i++)
    {
        int step;
        std::cin >> step;

        switch (i % 4)
        {
            case 0:
                y += step;
                break;

            case 1:
                x += step;
                break;

            case 2:
                y -= step;
                break;
                
            case 3:
                x -= step;
                break;
            
            default:
                std::cerr << "Wystapil blad\n";
                return;
        }
    }

    std::cout << "Robot znajduje sie na pozycji (" << x << ", " << y << ")\n";
}

void Ciag()
{
    int tab[100];
    int a1, r;
    std::cout << "Podaj pierwszy element ciagu arytmetycznego oraz jego roznice: ";
    std::cin >> a1 >> r;
    
    for(int n = 0; n < 100; n++)
    {
        tab[n] = a1 + r * n;
        std::cout << tab[n] << ' ';
    }
}

void MoreLess()
{
    std::srand(static_cast<unsigned int>(time(nullptr)));
    int num = std::rand() % 100 + 1;
    int moves = 0;

    std::cout << "Zgadnij liczbe z przedzialu <1, 100>: ";

    while(true)
    {
        int answer;
        std::cin >> answer;
        if(answer == num)
            break;

        if (num > answer)
            std::cout << "Szukana liczba jest wiekrza. ";
        else
            std::cout << "Szukana liczba jest mniejsza. ";

        std::cout << "Sprobuj jeszcze raz: ";
        moves++;
    }

    std::cout << "Gratulacje!!! Szukana liczba to " << num << '\n';
    std::cout << "Zostala znaleziona w " << moves << " ruchach.\n";
}

void Totolotek()
{
    using namespace std::chrono_literals;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (true)
    {
        int nums[6];
        std::cout << "Nowe liczby: ";

        for(int i = 0; i < 6; i++)
        {
            int num = std::rand() % 49 + 1;

            bool skip = false;
            for(int j = 0; j < i; j++)
                if(nums[j] == num)
                {
                    i--;
                    skip = true;
                    break;
                }

            if(skip)
                continue;

            nums[i] = num;
            
            std::cout << num << ' ';
        }
        std::cout << '\n';
        std::this_thread::sleep_for(1s);
    }
}

void Cisnienie()
{
    
}


int LiczbyPitagorejskie(int a, int b, int c)
{
    if(a > c)
        std::swap(a, c);

    if(a > b)
        std::swap(a, b);

    if(b > c)
        std::swap(b, c);
    
    return a * a + b * b == c * c;
}