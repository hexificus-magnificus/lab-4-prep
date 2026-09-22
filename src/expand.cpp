#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t
#include <iostream>
#include <bitset>

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
	if (input == 0)
		return 0;
	uint64_t out = 0;
	int size = 0;

	// find number of bits up to highest order 1 bit
	// O(n) since wc does n iterations
	while ((input >> ++size) >= 1) {}

	// add each bit of input to its proper place in output
	// O(n) since it does [size] iterations, and size is bounded by O(n)
	for (int i = 0; i < size; i++) {
		if (i*scale >= 64)
			break;
		uint64_t current = (input >> i) & 0b1;
		out |= current << (i * scale);
	}

	// since every section is O(n) or faster, the whole thing is O(n)
	return out;
}

int main() {
    // test here...
    uint64_t a = 0b1111111111;
    std::cout << std::bitset<64>(a) << "\n";
    std::cout << std::bitset<64>(expand(a, 2)) << "\n";
    std::cout << std::bitset<64>(expand(a, 3)) << "\n";
    std::cout << std::bitset<64>(expand(a, 4)) << "\n";
    std::cout << std::bitset<64>(expand(a, 5)) << "\n";
    std::cout << std::bitset<64>(expand(a, 6)) << "\n";
    std::cout << std::bitset<64>(expand(a, 7)) << "\n";
    return 0;
}
