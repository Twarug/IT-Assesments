#include <iostream>
#include <numeric>

int main()
{
    std::cout << "================\n\n";

    // 1.
    {
        std::cout << "Podaj Rok: ";
        int year;
        std::cin >> year;

        std::cout << "Rok " << year << " " << (year % 400 == 0 || year % 100 != 0 && year % 4 == 0 ? "jest" : "nie jest") << " przestepny.\n";
    }
    
    std::cout << "\n================\n\n";

    // 2.
    {
        
        std::cout << "Podaj granice przedzialu: ";
        int in1, in2;
        std::cin >> in1 >> in2;

        int min = std::min(in1, in2);
        int max = std::max(in1, in2);
        int sum = 0;
        
        std::cout << "Liczby calkowite w przedziale <" << min << ", " << max << ">:\n";
        
        for(int i = min; i <= max; i++)
        {
            std::cout << i << " ";
            if(i % 2 == 0)
                sum += i;
        }
        std::cout << "\n\n";

        std::cout << "Suma liczb parzystych tego przedziału wynosi: " << sum;
        std::cout << '\n';
    }
    
    std::cout << "\n================\n\n";

    // 3.
    {
        int min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::min();
        std::cout << "Podaj 5 liczb: ";
        for (int i = 0; i < 5; i++)
        {
            int num;
            std::cin >> num;
            min = std::min(min, num);
            max = std::max(max, num);
        }

        std::cout << "Najmniejsza liczba to: " << min << '\n';
        std::cout << "Najwiekrza liczba to: " << max << '\n';
        std::cout << "Roznica miedzy nimi wynosi: " << (max - min) << '\n';
    }
    
    std::cout << "\n================\n\n";

    // 4.
    {
        std::cout << "Podaj ilosc liczb: ";
        int count;
        std::cin >> count;
        std::cout << "Podaj " << count << " liczb: ";

        int sum = 0;
        for(int i = 0; i < count; i++)
        {
            int num;
            std::cin >> num;
            sum += num;
        }
        
        int avg = sum / count;

        std::cout << "Srednia wynosi: " << avg << '\n';
        
        for(int i = 0; i < avg; i++)
            std::cout << "0 ";
        std::cout << '\n';
    }
    
    return 0;
}
