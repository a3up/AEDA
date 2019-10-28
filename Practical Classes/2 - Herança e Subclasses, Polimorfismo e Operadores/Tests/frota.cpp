#include "frota.h"
#include <string>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1) {
    veiculos.push_back(v1);
}
int Frota::numVeiculos() const {
    return veiculos.size();
}
int Frota::menorAno() const {
    if(veiculos.empty())
        return 0;
    int res = veiculos.at(0) -> getAno();
    for(auto v: veiculos){
        if(v -> getAno() < res)
            res = v -> getAno();
    }
    return res;
}
float Frota::totalImposto() const {
    float res = 0;
    for(auto veiculo : veiculos){
        res += veiculo -> calcImposto();
    }
    return res;
}
vector<Veiculo*> Frota::operator () (int anoM) const {
    vector<Veiculo*> res;
    for(auto v: veiculos)
        if(v->getAno() == anoM)
            res.push_back(v);
    return res;
}
ostream & operator<<(ostream &o, const Frota &f) {
    for(auto veiculo : f.veiculos){
        veiculo -> info();
    }
    return o;
}