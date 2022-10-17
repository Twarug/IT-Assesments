#include <iostream>

int main()
{
    int vCount = 5, eCount;
    std::cout << "Podaj liczbe wierzchoklkow: \n";
    std::cin >> vCount;
    
    std::cout << "Podaj liczbe krawedzi: \n";
    std::cin >> eCount;
    
    std::cout << "Podaj pary wierzcholkow: \n";
    bool* matrix = new bool[vCount * vCount]{}; 
    
    for(int i = 0; i < eCount; i++)
    {
        int a, b;
        std::cin >> a >> b;
    
        matrix[a + b * vCount] = true;
        
        // Aby traktować dane wejściowe jako graf niekierowany
        // matrix[b + a * vCount] = true;
    }
    
    std::cout << "\n   ";
    for(int i = 0; i < vCount; i++)
        std::cout << i << ' ';
    std::cout << "\n  -";
    for(int i = 0; i < vCount; i++)
        std::cout << "--";
    std::cout << '\n';
    
    for(int y = 0; y < vCount; y++)
    {
        std::cout << y << "| ";
        for(int x = 0; x < vCount; x++)
        {
            std::cout << matrix[x + y * vCount] << ' ';
        }
        std::cout << '\n';
    }

    delete[] matrix;
    
    return 0;
}