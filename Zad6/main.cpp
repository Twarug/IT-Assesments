#include <iostream>
#include <array>
#include <span>
#include <chrono>

#if 0
    #define DEBUG_ARR(arr) \
        {\
            for(int i : arr)\
                std::cout << i << ' ';\
            std::cout << '\n';\
        }
#else
    #define DEBUG_ARR(arr)
#endif


void BubbleSort(std::span<int> collection);
void QuickSort(std::span<int> collection);
void HeapSort(std::span<int> collection);
void SelectionSort(std::span<int> collection);

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
    std::array counts = {
        1'000,
        10'000,
        30'000,
        60'000, 
        100'000
    };
    
    std::array<std::span<int>, counts.size()> arrays = {};

    while (true)
    {
        for(size_t i = 0; i < counts.size(); i++)
        {
            int count = counts[i];
            arrays[i] = std::span(new int[count], count);

            for(int j = 0; j < count; j++)
                arrays[i][j] = std::rand() % 1'000 + 1;
        }

        std::cout << "=============================\n";
        std::cout << "1) Bubble Sort\n";
        std::cout << "2) Quick Sort\n";
        std::cout << "3) Heap Sort\n";
        std::cout << "4) Selection Sort\n";
        std::cout << "=============================\n";
        std::cout << "Wybierz algorytm sortowania: ";

        char input;
        std::cin >> input;
        std::cout << "=======================\n";

        using SortFN = void(*)(std::span<int>);
        SortFN sort_fn;

        std::cout << '\n';
        
        switch (input)
        {
        case '1':
            std::cout << "Bubble Sort\n";
            sort_fn = BubbleSort;
            break;
            
        case '2':
            std::cout << "Quick Sort\n";
            sort_fn = QuickSort;
            break;
            
        case '3':
            std::cout << "Heap Sort\n";
            sort_fn = HeapSort;
            break;
            
        case '4':
            std::cout << "Selection Sort\n";
            sort_fn = SelectionSort;
            break;
            
            // exit
            default:
                return 0;
        }

        for(const auto s : arrays)
        {
            namespace ch = std::chrono;

            DEBUG_ARR(s)
        
            std::cout << "Sorting of " << s.size() << " elements sorted in: ";
            auto start = ch::high_resolution_clock::now();
            sort_fn(s);
            std::cout << ch::duration_cast<ch::duration<float, std::milli>>(ch::high_resolution_clock::now() - start) << '\n';
            
            DEBUG_ARR(s)
        }
        
        std::cout << std::flush;
        system("pause");
        system("cls");
        
        for (const auto s : arrays)
            delete[] s.data();
    }
}

void BubbleSort(std::span<int> collection)
{
    for(size_t i = 0; i < collection.size(); i++)
        for(size_t j = 1; j < collection.size() - i; j++)
            if(collection[j] < collection[j - 1])
                std::swap(collection[j], collection[j - 1]);
}

void QuickSort(std::span<int> collection)
{
    if(collection.size() <= 1)
        return;

    size_t pivotIndex;
    {
        int pivot = collection[0];
 
        int count = 0;
        for (size_t i = 1; i <= collection.size() - 1; i++) {
            if (collection[i] <= pivot)
                count++;
        }
 
        // Giving pivot element its correct position
        pivotIndex = count;
        std::swap(collection[pivotIndex], collection[0]);
 
        // Sorting left and right parts of the pivot element
        size_t i = 0, j = collection.size() - 1;
 
        while (i < pivotIndex && j > pivotIndex) {
 
            while (collection[i] <= pivot) {
                i++;
            }
 
            while (collection[j] > pivot) {
                j--;
            }
 
            if (i < pivotIndex && j > pivotIndex) {
                std::swap(collection[i++], collection[j--]);
            }
        }
    }

    if(pivotIndex > 0)
        QuickSort(collection.subspan(0, pivotIndex - 1));

    if(pivotIndex < collection.size())
        QuickSort(collection.subspan(pivotIndex + 1));
}

// Heapsort

void Heapify(std::span<int> collection, size_t i)
{
    // Initialize largest as root
    size_t largest = i;
 
    // left = 2*i + 1
    size_t l = 2 * i + 1;
 
    // right = 2*i + 2
    size_t r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < collection.size() && collection[l] > collection[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < collection.size() && collection[r] > collection[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        std::swap(collection[i], collection[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        Heapify(collection, largest);
    }
}

void HeapSort(std::span<int> collection)
{   
    for (size_t i = collection.size() / 2; i > 0; i--)
        Heapify(collection, i - 1);
 
    // One by one extract an element
    // from heap
    for (size_t i = collection.size() - 1; i > 0; i--) {
 
        // Move current root to end
        std::swap(collection[0], collection[i]);
 
        // call max heapify on the reduced heap
        Heapify(collection.subspan(0, i), 0);
    }
}

void SelectionSort(std::span<int> collection)
{ 
    // One by one move boundary of
    // unsorted subarray
    for (size_t i = 0; i < collection.size()-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        size_t min_idx = i;
        for (size_t j = i+1; j < collection.size(); j++)
            if (collection[j] < collection[min_idx])
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            std::swap(collection[min_idx], collection[i]);
    }
}