#include<SortedAlghs.h> 
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <execution>
#include <algorithm>
using namespace Sorted;
using namespace std;


class RandomArrayGenerator {
public:
    static inline std::mt19937 generator;
    static const std::vector<int> generate(const size_t size, const int min_value,const int max_value, const unsigned int seed) {
        generator.seed(seed);
        std::uniform_int_distribution<int> distribution(min_value, max_value);

        std::vector<int> arr(size);
       /* for (size_t i = 0; i < size; i++) {
            arr[i] = distribution(generator);
        }*/
        std::generate_n(std::execution::par_unseq, arr.begin(), arr.size(), [&]() {return distribution(generator); });

        return arr;
    }
};
template <typename T>
T sorted_gen(size_t size) {
    T arr(size);
    for (size_t i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

template <typename T>
T reversed_gen(size_t size) {
    T arr(size);
    for (size_t i = size; i > 0; i--) {
        arr[size - i] = i;
    }
    return arr;
}

void calculateAverages(size_t num_arrays, int min_value, int max_value, unsigned int seed, int size, Stats(*callback)(std::vector<int>&)) {
    Stats st_random_arr;
    Stats st_sorted_arr;
    Stats st_reversed_arr;
    std::vector<int> sortedArr = sorted_gen<std::vector<int>>(size);
    std::vector<int> reversedArr = reversed_gen<std::vector<int>>(size);
    st_sorted_arr = (*callback)(sortedArr);
    st_reversed_arr = (*callback)(reversedArr);
    for (size_t i = 0; i < num_arrays; i++) {
        std::vector<int> arr = RandomArrayGenerator::generate(size, min_value, max_value, seed);

        st_random_arr += (*callback)(arr);
    };

    std::string filename = "data.txt";
    std::ofstream out(filename, std::ios_base::app);
    if (out.is_open())
    {
        out << st_random_arr.copy_count / num_arrays << std::endl;
        out << st_random_arr.comparison_count / num_arrays << std::endl;
        out << st_sorted_arr.copy_count << std::endl;
        out << st_sorted_arr.comparison_count << std::endl;
        out << st_reversed_arr.copy_count << std::endl;
        out << st_reversed_arr.comparison_count << std::endl;
    }
    out.close();
};


int main()
{
    const unsigned int seed = 1250;
    const size_t num_arrays = 100;
    const int min_value = 0;
    const int max_value = 1000;
    int array_size[] {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000};
    for (int i = 0; i < size(array_size); i++) {
        cout << "ARRAY SIZE:" << array_size[i] << endl;
        calculateAverages(num_arrays, min_value, max_value, seed, array_size[i], bubbleSort);
        cout << "______" << endl;
        calculateAverages(num_arrays, min_value, max_value, seed, array_size[i], cocktailSort);
        cout << "______" << endl;
        calculateAverages(num_arrays, min_value, max_value, seed, array_size[i], combSort);
        cout << "______" << endl;
    }        
}