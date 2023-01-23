#ifndef VECTORHASHER_H_
#define VECTORHASHER_H_

#include <fstream>
#include <string>
#include <vector>
 #include <vector>


struct VectorHasher {
    size_t operator()(const vector<double> &V) const {
        size_t hash = V.size();
        for(auto &i : V) {
            hash ^= (int)i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
#endif

