#include "jogador.h"

void Jogador::adicionaAposta(const Aposta &ap) {
    this->apostas.insert(ap);
}

unsigned Jogador::apostasNoNumero(unsigned num) const {
    unsigned ret = 0;
    for(auto &aposta : this->apostas)
        ret += aposta.contem(num);
    return ret;
}

tabHAposta Jogador::apostasPremiadas(const tabHInt &sorteio) const {
    tabHAposta money;
    for(auto &aposta : this->apostas)
        if(aposta.calculaCertos(sorteio) >= 3)
            money.insert(aposta);
    return money;
}
