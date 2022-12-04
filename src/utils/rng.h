#ifndef RNG_H
#define RNG_H

#include <random>
#include <unordered_map>
#include <utility>

#include <boost/functional/hash.hpp>

template <typename T>
inline double random_double(T min, T max) {
    static std::unordered_map<std::pair<T, T>,
            std::uniform_real_distribution<T>,
            boost::hash<std::pair<T, T>>> distributions;

    auto p = std::make_pair(min, max);
    auto it = distributions.find(p);
    if(it == distributions.end()) {
        auto dist = std::uniform_real_distribution<T>(min, max);
        distributions[p] = dist;
        it = distributions.find(p);
    }

    static std::mt19937 generator;
    return it->second(generator);
}

template <typename T>
inline double random_double()
{
    return random_double<T>(0, 0);
}

#endif // RNG_H
