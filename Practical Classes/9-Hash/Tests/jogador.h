#pragma once

#include "aposta.h"
#include <string>
#include <utility>

using namespace std;

struct apostaHash {
    int operator()(const Aposta &ap) const {
        int ret = 0;
        for (const auto &num : ap.getNumeros())
            ret += num;
        return ret;
    }

    bool operator()(const Aposta &ap1, const Aposta &ap2) const {
        return true;
    }
};


typedef unordered_set<Aposta, apostaHash, apostaHash> tabHAposta;

class Jogador {
    tabHAposta apostas;
    string nome;
public:
    explicit Jogador(string nm = "anonimo") { nome = move(nm); }

    void adicionaAposta(const Aposta &ap);

    unsigned apostasNoNumero(unsigned num) const;

    tabHAposta apostasPremiadas(const tabHInt &sorteio) const;

    unsigned getNumApostas() const { return apostas.size(); }
};
