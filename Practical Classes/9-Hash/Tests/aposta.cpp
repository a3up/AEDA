#include "aposta.h"

using namespace std;

bool Aposta::contem(unsigned num) const {
    return this->numeros.find(num) != this->numeros.end();
}

void Aposta::geraAposta(const vector<unsigned> &valores, unsigned n) {
    for (unsigned i = 0; this->numeros.size() < n; i++)
        this->numeros.insert(valores[i]);
}

unsigned Aposta::calculaCertos(const tabHInt &sorteio) const {
    unsigned rightOnes = 0;
    for (auto &num : sorteio)
        rightOnes += this->contem(num);
    return rightOnes;
}
