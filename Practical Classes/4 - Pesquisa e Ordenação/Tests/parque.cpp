#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include "ClienteNaoExistente.h"
#include <algorithm>
#include <vector>

using namespace std;



ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() = default;

vector<InfoCartao> ParqueEstacionamento::getClientes() const {
    return clientes;
}

unsigned int ParqueEstacionamento::getNumLugares() const {
    return lotacao;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
    return lotacao-vagas;
}

int ParqueEstacionamento::posicaoCliente(const string &nome) const {
    for(unsigned i = 0; i < clientes.size(); ++i)
        if(clientes.at(i).nome == nome)
            return i;
    return -1;
}

int ParqueEstacionamento::getFrequencia(const string &nome) const {
    int pos = posicaoCliente(nome);
    if(pos == -1)
        throw ClienteNaoExistente(nome);
    return clientes.at(pos).frequencia;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome) {
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
    info.frequencia = 0;
	clientes.push_back(info);
	numClientes++;
	return true;
}

bool ParqueEstacionamento::retiraCliente(const string & nome) {
	for (auto it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if (!it->presente) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}

bool ParqueEstacionamento::entrar(const string & nome) {
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente ) return false;
	clientes[pos].presente = true;
	clientes[pos].frequencia++;
	vagas--;
	return true;
}

bool ParqueEstacionamento::sair(const string & nome) {
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( !clientes[pos].presente ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}

void ParqueEstacionamento::ordenaClientesPorFrequencia() {
    insertionSort(clientes);
}

void ParqueEstacionamento::ordenaClientesPorNome() {
    for (unsigned int p = 1; p < clientes.size(); p++) {
        InfoCartao tmp = clientes[p];
        unsigned j;
        for (j = p; j > 0 && tmp.nome < clientes[j-1].nome; j--)
            clientes[j] = clientes[j-1];
        clientes[j] = tmp;
    }
}

vector<string> ParqueEstacionamento::clientesGamaUso(int n1, int n2) {
    vector<string> nomes;
    ordenaClientesPorFrequencia();
    for(const auto &x : clientes)
        if(x.frequencia >= n1 && x.frequencia <= n2)
            nomes.push_back(x.nome);
    return nomes;
}

ostream & operator<<(ostream & os, const ParqueEstacionamento & pe) {
    for(const auto &c : pe.clientes){
        os << "Nome: " << c.nome << endl;
        if(!c.presente)
            os << "Nao ";
        os << "Presente" << endl;
        os << "Frequencia: " << c.frequencia << endl;
    }
    return os;
}

InfoCartao ParqueEstacionamento::getClienteAtPos(vector<InfoCartao>::size_type p) const {
    InfoCartao info;
    if(p >= clientes.size())
        throw PosicaoNaoExistente(p);
    info = clientes.at(p);
    return info;
}
