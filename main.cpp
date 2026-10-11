#include<iostream>
#include<string>
#include "bloomFilter.h"

int main(){

    std::size_t expectedItems = 10000;
    double target_FP_rate = 0.01;

    BloomFilter<std::string> filter (expectedItems , target_FP_rate);

    std::cout<<"Bloom Filter Created: \n";
    std::cout<<"Bit array size: "<<filter.bitCount()<<"bits\n" << filter.bitCount() / 8 / 1024 << " KB\n";
    std::cout<<"Hash Functions used: "<<filter.hashCount()<<"\n";

    filter.insert("Advait");
    filter.insert("Palve");
    filter.insert("Bunny");

    std::cout << std::boolalpha;
    std::cout << "Contains 'Advait': " << filter.contains("Advait") << "\n";
    std::cout << "Contains 'Palve': " << filter.contains("Palve") << "\n";
    std::cout << "Contains 'Tim': " << filter.contains("Tim") << "\n";

    std::cout << "Bit count: " << filter.bitCount() << '\n';
    std::cout << "Hash count: " << filter.hashCount() << '\n';

    return 0;

}