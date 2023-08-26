// test.cpp is a test file for the Enumerator class.

#include <cassert>
#include <iostream>
#include <chrono>

#include "enum.hpp"

void test_constructor() {
    printf("[test_constructor]\n");
    std::vector<uchar> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    assert(e.getMaxCombinations() == 39);
    printf("[test_constructor] passed\n\n");
}

void test_preset() {
    printf("[test_preset]\n");
    std::vector<uchar> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    std::vector<uchar> presetArray = {'a', 'a'};
    e.preset(presetArray); 
    assert(e.next() == "ab");
    printf("[test_preset] passed\n\n");
}

void test_invalidPreset() {
    printf("[test_invalidPreset]\n");
    std::vector<uchar> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    std::vector<uchar> presetArray = {'a', 'd'};
    assert(!e.preset(presetArray));
    printf("[test_invalidPreset] passed\n\n");
}

void test_largeCombinationLength() {
    printf("[test_largeCombinationLength]\n");
    std::vector<uchar> charArray = {'a', 'b', 'c', 'd', 'e'};
    Enumerator e(5, charArray);
    assert(e.getMaxCombinations() == 3905);
    printf("[test_largeCombinationLength] passed\n\n");
}

void test_tooLongPreset() {
    printf("[test_tooLongPreset]\n");
    std::vector<uchar> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    std::vector<uchar> presetArray = {'a', 'b', 'c', 'd'};
    assert(!e.preset(presetArray));
    printf("[test_tooLongPreset] passed\n\n");
}

int main() {

    test_constructor();
    test_preset();
    test_invalidPreset();
    test_largeCombinationLength();
    test_tooLongPreset();

    return 0;
}