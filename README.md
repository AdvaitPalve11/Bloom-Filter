# Bloom Filter in C++

A memory-efficient probabilistic data structure implemented in C++17 using templates and double hashing.

### Prerequisites
- C++17 compiler (GCC or Clang)
- CMake 3.20+

### Build & Run
```bash
cmake -S . -B build
cmake --build build
```

### Features
- Insert and membership queries
- Configurable false-positive rate
- Custom bit and hash counts

### Usage
```cpp
BloomFilter<std::string> filter(10000, 0.01);
filter.insert("xyz");
filter.contains("xyz"); // true
```

Bloom Filters can produce false positives but should not produce false negatives.
