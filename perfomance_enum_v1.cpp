// test_perfomance.cpp is a test file for the Enumerator class.

#include <cassert>
#include <iostream>
#include <chrono>

#include "enum_v1.hpp"
#include "loop_enum/loop_enum.hpp"

const int maxLenTest = 6;

const std::vector<uchar> testCharArray = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//const std::vector<uchar> testCharArray = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m','n','o'};
//const std::vector<uchar> testCharArray = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//const std::vector<uchar> testCharArray = {'0', '1', '2', '3', '4' };

double test_time() 
{
    printf("[test_enumerator_v1_time]\n");

    Enumerator enumerator(maxLenTest, testCharArray);
    double maxCombinations = enumerator.getMaxCombinations();
    std::cout << "Max combinations: " << maxCombinations << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    
    double combinations = 0;
    std::string combination;
    while(enumerator.next(combination)) {
        combinations++;
    }
    std::cout << "Combinations: " << combinations << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    double enumeratorTime = elapsed.count();

    std::cout << "Enumerator time: " << elapsed.count() << " seconds" << std::endl;
    std::cout << "Average time per combination: " << elapsed.count() / combinations << " seconds" << std::endl;

    printf("[test_enumerator_v1_time] passed\n\n");
    return enumeratorTime;
}

double test_dummy_time() 
{
    printf("[test_loop_time]\n");

    auto start = std::chrono::high_resolution_clock::now();

    double combinations = 0;
    if (maxLenTest == 5)
    {
        combinations = loop_enum_5x(testCharArray);
    }
    else if (maxLenTest == 6)
    {
        combinations = loop_enum_6x(testCharArray);
    }
    else
    {
        std::cout << "Invalid maxLenTest" << std::endl;
        return 0;
    }
    std::cout << "Combinations: " << combinations << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    double dummyTime = elapsed.count();

    std::cout << "Loop time: " << elapsed.count() << " seconds" << std::endl;
    std::cout << "Average time per combination: " << elapsed.count() / combinations << " seconds" << std::endl;

    printf("[test_loop_time] passed\n\n");
    return dummyTime;
}

int main() {
    double enumeratorTime = test_time();
    double dummyTime = test_dummy_time();

    std::cout << "Speedup: " << dummyTime / enumeratorTime << "x" << std::endl;

    return 0;
}
