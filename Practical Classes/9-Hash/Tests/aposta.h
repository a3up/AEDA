#pragma once

#include <unordered_set>
#include <vector>

using namespace std;

typedef unordered_set<unsigned> tabHInt;

class Aposta {
    tabHInt numeros;
public:
    Aposta() = default;;

    void geraAposta(const vector<unsigned> &valores, unsigned n = 6);

    bool contem(unsigned num) const;

    unsigned calculaCertos(const tabHInt &sorteio) const;

    tabHInt getNumeros() const { return numeros; }
};
