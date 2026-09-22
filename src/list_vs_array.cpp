#include <cstddef>  // size_t
#include <vector>
#include <list>
#include <random>
#include <cstdint>
#include <iostream>

#include "timer.h"

constexpr size_t SIZE = 16000000;

int main() {
    // test here...
    std::mt19937_64 rng(0);
    std::vector<uint64_t> v;
    std::vector<uint64_t> vr(SIZE);
    std::list<uint64_t> l;
    Timer t;

    for (size_t i = 0; i < SIZE; i++) {
    	v.push_back(rng());
    }
    std::cout << "Unreserved vector creation took " << t.click<Timer::Micros>() << " microseconds\n";

    rng.seed(0);
    for (size_t i = 0; i < SIZE; i++) {
    	vr.push_back(rng());
    }
    std::cout << "Reserved vector creation took " << t.click<Timer::Micros>() << " microseconds\n";

    rng.seed(0);
    for(size_t i = 0; i < SIZE; i++) {
    	l.push_back(rng());
    }
    std::cout << "List creation took " << t.click<Timer::Micros>() << " microseconds\n";

    uint64_t vSum = 0;
    for (uint64_t i : v) {
    	vSum += i;
    }
    std::cout << "Vector summing took " << t.click<Timer::Micros>() << " microseconds\n";

    uint64_t lSum = 0;
    for (uint64_t i : l) {
    	lSum += i;
    }
    std::cout << "List summing took " << t.click<Timer::Micros>() << " microseconds\n";

    return 0;
}
