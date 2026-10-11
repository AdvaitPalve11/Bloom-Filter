#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstddef>
#include <utility>

template <typename T>
class BloomFilter {
private:
    std::vector<bool> bitSet;
    std::size_t numBits;
    std::size_t numHashes;

    std::pair<std::size_t, std::size_t>

    getHashPair(const T& item) const {

        std::hash<T> primaryHash;
        std::size_t h1 = primaryHash(item);

        std::size_t h2 = std::hash<std::size_t>{}(h1 ^ 0x9e3779b97f4a7c15ULL);

        return {h1, h2};
    }

public:
    // Constructor 1: bit and hash counts
    BloomFilter(std::size_t numbits, std::size_t numhashes)
        : bitSet(numbits == 0 ? 1 : numbits, false),
          numBits(numbits == 0 ? 1 : numbits),
          numHashes(numhashes == 0 ? 1 : numhashes) {}

    // Constructor 2: Expected items and target false-positive rate
    BloomFilter(std::size_t expected,
                double target_false_positive_rate) {
        if (expected == 0) 
            expected = 1;
        

        if (target_false_positive_rate <= 0.0 || target_false_positive_rate >= 1.0)
             target_false_positive_rate = 0.01;
        

        numBits = static_cast<std::size_t>(-static_cast<double>(expected) *std::log(target_false_positive_rate) /  (std::log(2.0) * std::log(2.0))  );

        numHashes = static_cast<std::size_t>( (static_cast<double>(numBits) /static_cast<double>(expected)) * std::log(2.0)  );

        if (numBits == 0) 
            numBits = 1;
        

        if (numHashes == 0) 
            numHashes = 1;
        
        bitSet.assign(numBits, false);
    }

    void insert(const T& item) {

        auto [h1, h2] = getHashPair(item);

        for (std::size_t i = 0; i < numHashes; ++i) {
            std::size_t bit_index = (h1 + i * h2) % numBits;

            bitSet[bit_index] = true;
        }

    }

    // Check if an item exist
    [[nodiscard]] bool contains(const T& item) const {
        auto [h1, h2] = getHashPair(item);

        for (std::size_t i = 0; i < numHashes; ++i) {
            std::size_t bit_index = (h1 + i * h2) % numBits;

            if (!bitSet[bit_index])
                return false;
            
        }

        return true;
    }

    // Reset all bits
    void clear() {
        bitSet.assign(numBits, false);
    }

    [[nodiscard]] std::size_t bitCount() const {
        return numBits;
    }

    [[nodiscard]] std::size_t hashCount() const {
        return numHashes;
    }
};
