#include "parque.h"

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot), numMaximoClientes(nMaxCli){
    vagas = lot;
    clientes = {};
}
unsigned int ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}
unsigned int ParqueEstacionamento::getNumMaximoClientes() const{
    return numMaximoClientes;
}
bool ParqueEstacionamento::adicionaCliente(const string & nome){
    if(getNumClientesAtuais() >= numMaximoClientes || posicaoCliente(nome) != -1){
        return false;
    }
    InfoCartao a;
    a.nome = nome;
    a.presente = false;
    clientes.push_back(a);
    return true;
}
int ParqueEstacionamento::posicaoCliente(const string & nome) const{
    for(int i = 0; i < clientes.size(); ++i){
        if(clientes.at(i).nome == nome){
            return i;
        }
    }
    return -1;
}
bool ParqueEstacionamento::entrar(const string & nome){
    int index = posicaoCliente(nome);
    if(index == -1 || vagas <= 0 || clientes.at(index).presente){
        return false;
    }
    clientes.at(index).presente = true;
    vagas--;
    return true;
}
bool ParqueEstacionamento::retiraCliente(const string & nome){
    int index = posicaoCliente(nome);
    if(index == -1 || clientes.at(index).presente){
        return false;
    }
    clientes.erase(clientes.begin()+index);
    return true;
}
bool ParqueEstacionamento::sair(const string & nome){
    int index = posicaoCliente(nome);
    if(index == -1 || !clientes.at(index).presente){
        return false;
    }
    clientes.at(index).presente = false;
    vagas++;
    return true;
}
unsigned int ParqueEstacionamento::getNumLugaresOcupados() const{
    return lotacao - vagas;
}
unsigned int ParqueEstacionamento::getNumClientesAtuais() const{
    return clientes.size();
}
bool ParqueEstacionamento::salvarClientes() const{
    ofstream file("clientes.txt");
    for(const auto & cliente : clientes){
        file << cliente.nome << endl;
    }
}