# Enumerator Library

## Overview

The Enumerator library is designed for generating combinations based on a given array of characters. It offers two distinct implementations, each with its own advantages and performance characteristics.

## Implementations

## Original Enumerator

This approach simulates the workings of a mechanical counter, where each "slider" corresponds to a specific character.

                +-----+    +-----+
                |  A  |    |  A  |
                +-----+    +-----+
                |  A  |    |  B  |
                +-----+    +-----+
                |  A  |    |  C  |
                +-----+    +-----+
                |  A  |    |  D  |
                +-----+    +-----+

## Features:

- Generate combinations based on a provided array of characters.
- Set a starting point for combinations using the preset method.
- Determine the maximum possible combinations with the getMaxCombinations method.

## How to Use the Enumerator

1. Create an `Enumerator` object by providing the maximum combination length and the character array.
2. Use the `next()` method to retrieve the next combination.
3. Optionally, use the `preset()` and `setLimit()` methods to set an initial state and a limit, respectively.



## Enumerator v1

This is a more optimized version that's approximately 3 times faster than the original implementation but is 3 times slower than `loop_enum`.

## Features:

- Faster combination generation.
- Simplified internal structure for better performance.


## Comparison with Other Approaches

This library offers a distinct approach compared to traditional recursive and iterative methods of combination generation:

- **Time Complexity**: Our approach has a time complexity of O(1) for most combinations, compared to O(n) for recursive methods.
- **Space Complexity**: Both our approach and the iterative one utilize O(n) memory.
- **Operational Efficiency**: While our approach might involve additional operations due to slider management logic, this is offset by its time complexity advantage.

## Suitability

The Enumerator library is particularly efficient for short combinations on a single CPU. For longer combinations, parallelization is recommended. The `preset()` function was designed with this in mind, allowing for an even distribution of computational complexity across threads. Further optimization could involve running these threads on a GPU, though this would require future testing.

## Conclusion

Enumerator is a tool for combination generation, offering a unique and flexible approach to the task. It's especially suited for scenarios where high adaptability and control over the generation process are required.
