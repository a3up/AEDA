#include "veiculo.h"
#include <iostream>
#include <utility>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a):
    marca(move(mc)), mes(m), ano(a) {}
int Veiculo::getAno() const {
    return ano;
}
string Veiculo::getMarca() const {
    return marca;
}
int Veiculo::info() const {
    cout << "Marca      : " << marca << endl;
    cout << "Data       : " << mes << "/" << ano << endl;
    return 3;
}
bool Veiculo::operator<(const Veiculo &v) const {
    if (ano != v.ano)
       return (ano < v.ano);
    return (mes < v.mes);
}

Motorizado::Motorizado(string mc, int m, int a,string c,int cil):
    Veiculo(move(mc), m, a), combustivel(move(c)), cilindrada(cil) {}
string Motorizado::getCombustivel() const {
    return combustivel;
}
int Motorizado::info() const {
    int antInfo = Veiculo::info();
    cout << "Combustivel: " << combustivel << endl;
    cout << "Cilindrada : " << cilindrada << endl;
    return antInfo + 2;
}
float Motorizado::calcImposto() const {
    if((combustivel == "gasolina" && cilindrada <= 1000) || (combustivel != "gasolina" && cilindrada <= 1500))
        return ano > 1995 ? 14.56 : 8.10;
    if((combustivel == "gasolina" && cilindrada <= 1300) || (combustivel != "gasolina" && cilindrada <= 2000))
        return ano > 1995 ? 29.06 : 14.56;
    if((combustivel == "gasolina" && cilindrada <= 1750) || (combustivel != "gasolina" && cilindrada <= 3000))
        return ano > 1995 ? 45.15 : 22.65;
    if((combustivel == "gasolina" && cilindrada <= 2600) || (combustivel != "gasolina"))
        return ano > 1995 ? 113.98 : 54.89;
    if(combustivel == "gasolina" && cilindrada <= 3500)
        return ano > 1995 ? 181.17 : 87.13;
    return ano > 1995 ? 320.89 : 148.37;
}

Automovel::Automovel(string mc, int m, int a,string c, int cil):
    Motorizado(move(mc), m, a, move(c), cil) {}
int Automovel::info() const {
    int antInfo = Motorizado::info();
    return antInfo;
}

Camiao::Camiao(string mc, int m, int a,string c, int cil,int cm):
    Motorizado(move(mc), m, a, move(c), cil), carga_maxima(cm) {}
int Camiao::info() const {
    int antInfo = Motorizado::info();
    cout << "Carga      : " << carga_maxima << endl;
    return antInfo + 1;
}

Bicicleta::Bicicleta(string mc, int m, int a,string t):
    Veiculo(move(mc), m, a), tipo(move(t)) {}
int Bicicleta::info() const {
    int antInfo = Veiculo::info();
    cout << "Tipo       : " << tipo << endl;
    return antInfo + 1;
}
float Bicicleta::calcImposto() const {
    return 0;
}