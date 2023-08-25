#include <cassert>
#include "enumerator.hpp"

void test_constructor() {
    printf("test_constructor\n");
    std::vector<unsigned char> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    assert(e.getMaxCombinations() == 39);
    printf("test_constructor passed\n");
}

void test_preset() {
    printf("test_preset\n");
    std::vector<unsigned char> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    std::vector<unsigned char> presetArray = {'a', 'a'};
    e.preset(presetArray);
    auto next = e.next();
    assert(next == "ab");
    printf("test_preset passed\n");
}

void test_setLimit() {
    printf("test_setLimit\n");
    std::vector<unsigned char> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    std::vector<unsigned char> limitArray = {'a', 'b', 'c'};
    e.setLimit(limitArray);
    while (e.next() != "abb") {}
    assert(e.next() == "abc");
    assert(e.next() == "");
    printf("test_setLimit passed\n");
}

void test_invalidPreset() {
    printf("test_invalidPreset\n");
    std::vector<unsigned char> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    std::vector<unsigned char> presetArray = {'a', 'd'};
    assert(!e.preset(presetArray));
    printf("test_invalidPreset passed\n");
}

void test_invalidLimit() {
    printf("test_invalidLimit\n");
    std::vector<unsigned char> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    std::vector<unsigned char> limitArray = {'a', 'd'};
    assert(!e.setLimit(limitArray));
    printf("test_invalidLimit passed\n");
}

void test_largeCombinationLength() {
    printf("test_largeCombinationLength\n");
    std::vector<unsigned char> charArray = {'a', 'b', 'c', 'd', 'e'};
    Enumerator e(5, charArray);
    assert(e.getMaxCombinations() == 3905);
    printf("test_largeCombinationLength passed\n");
}

void test_tooLongPreset() {
    printf("test_tooLongPreset\n");
    std::vector<unsigned char> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    std::vector<unsigned char> presetArray = {'a', 'b', 'c', 'd'};
    assert(!e.preset(presetArray));
    printf("test_tooLongPreset passed\n");
}

void test_tooLongLimit() {
    printf("test_tooLongLimit\n");
    std::vector<unsigned char> charArray = {'a', 'b', 'c'};
    Enumerator e(3, charArray);
    std::vector<unsigned char> limitArray = {'a', 'b', 'c', 'd'};
    assert(!e.setLimit(limitArray));
    printf("test_tooLongLimit passed\n");
}

int main() {
    test_constructor();
    test_preset();
    test_setLimit();
    test_invalidPreset();
    test_invalidLimit();
    test_largeCombinationLength();
    test_tooLongPreset();
    test_tooLongLimit();
    return 0;
}