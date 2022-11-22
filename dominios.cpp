#include "dominios.h"

using namespace std;

int Dominio::countChar(string param, string target) {
    if (target.length() != 1)
        throw invalid_argument("Argumento invalido");
    int res;
    for (int i = 0; i < param.length(); i++)
        if (param[i] == target[0])
            res++;
    return res;
}

void Data::validar(string data) {
    int MESES[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // validar a formatacao
    if (data.length() != SIZE) {
        throw invalid_argument("Argumento invalido: tamanho inadequado " + data);
    }
    string const BARRA = "/";
    for (int i = 0; i < SIZE; i++) {
        if (i == 2 || i == 5) {
            if (data[i] != BARRA[0]) {
                throw invalid_argument("Argumento invalido: fora da formatacao " + data);
            }
        }
        else if (!isdigit(data[i])) {
            throw invalid_argument("Argumento invalido: digito invalido " + data);
        }
    }

    if (0 < stoi(getMes(data)) < 13) {
        if (stoi(getDia(data)) <= MESES[stoi(getMes(data)) - 1] + incrFeb(data))
            return;
    }
    throw invalid_argument("Argumento invalido: data invalida " + data);
}

void Data::setData(string data) {
    validar(data);
    this->valor = data;
}

void Data::setData(string dia, string mes, string ano) {
    string data = dia + "/" + mes + "/" + ano;
    this->setData(data);
}

void Data::setData(int dia, int mes, int ano) {
    string data = formatarInt(dia, 2) + "/" + formatarInt(mes, 2) + "/" + formatarInt(ano, 2);
    this->setData(data);
}

Data::Data(string data) {
    this->setData(data);
}

Data::Data(string dia, string mes, string ano) {
    this->setData(dia, mes, ano);
}

Data::Data(int dia, int mes, int ano) {
    this->setData(dia, mes, ano);
}

string Dominio::formatarInt(int n, int digitos) {
    string str_n = to_string(n);
    int tamanho = str_n.length();

    for (int i = 0; i < digitos - tamanho; i++) {
        str_n = "0" + str_n;
    }

    return str_n;
}

int Data::incrFeb(string data) {
    if (stoi(getMes(data)) != 2)
        return 0;
    return isLeapYear(data);
}

int Data::isLeapYear() {
    return isLeapYear(this->valor);
}

int Data::isLeapYear(int ano) {
    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
        return 1;
    return 0;
}

int Data::isLeapYear(string data) {
    return isLeapYear(stoi(getAno(data)));
}
