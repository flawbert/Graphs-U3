#include "../include/Grafo.hpp"
using namespace std;

Grafo::Grafo(int n) : numCidades(n) {//Construtor
    matrizDistancias.resize(n, vector<double>(n, 0.0));
    idsOriginais.resize(n);
    for(int i=0; i<n; i++) idsOriginais[i] = i+1;
}

Grafo::Grafo(const vector<vector<double>>& matrizCompleta, const vector<string>& nomesCompletos, const vector<int>& idsDesejados) { //Construtor de subgrafo
    numCidades = idsDesejados.size();
    matrizDistancias.resize(numCidades, vector<double>(numCidades));
    nomesCidades.resize(numCidades);
    idsOriginais = idsDesejados;

    for (int i = 0; i < numCidades; i++) {
        int indiceGlobalI = idsDesejados[i] - 1; //indice na matriz completa, 0-based
        if (indiceGlobalI>= 0 && indiceGlobalI < (int)nomesCompletos.size()) { //copia nome da cidade
            nomesCidades[i] = nomesCompletos[indiceGlobalI];
        } else {
            nomesCidades[i] = "Desc " + to_string(idsDesejados[i]);
        }
        for (int j = 0; j < numCidades; j++) {
            int indiceGlobalJ = idsDesejados[j] - 1;
            if (indiceGlobalI < (int)matrizCompleta.size() && indiceGlobalJ < (int)matrizCompleta.size()) { //faz a cópia dos valores da matriz completa para a submatriz
                matrizDistancias[i][j] = matrizCompleta[indiceGlobalI][indiceGlobalJ];
            } else {
                matrizDistancias[i][j] = numeric_limits<double>::infinity();
            }
        }
    }
}
double Grafo::d(int i, int j) const {
    return matrizDistancias[i][j];
}

int Grafo::getNumCidades() const{
    return numCidades;
}

string Grafo::getNome(int i) const {
    if (i >= 0 && i < (int)nomesCidades.size()) return nomesCidades[i];
    return "";
}

int Grafo::getIdOriginal(int i) const {
    if (i >= 0 && i < (int)idsOriginais.size()) return idsOriginais[i];
    return 0;
}