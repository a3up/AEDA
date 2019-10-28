//
// Created by up201800168 on 18/10/2019.
//

#ifndef AEDA1920_FP04_CLIENTENAOEXISTENTE_H
#define AEDA1920_FP04_CLIENTENAOEXISTENTE_H


class ClienteNaoExistente : exception {
    string nome;
public:
    ClienteNaoExistente(string n) : nome(n) {}
    string getNome() {
        return nome;
    }
};
class PosicaoNaoExistente : exception {
    vector<InfoCartao>::size_type pos;
public:
    PosicaoNaoExistente(vector<InfoCartao>::size_type p) : pos(p) {}
    vector<InfoCartao>::size_type getValor() {
        return pos;
    }
};


#endif //AEDA1920_FP04_CLIENTENAOEXISTENTE_H
