#ifndef DOMINIOS_H
#define DOMINIOS_H

#include <iostream>
#include <stdexcept>
#include <string.h>

using namespace std;

class Dominio
{
    protected:
        static int count_char(string, string);
        string valor;
        virtual void validar(string) = 0;

    public:
        string getValor();
        void setValor(string);
};

inline string Dominio::getValor() {
    return valor;
}


class Data:public Dominio {
    private:
        static const int SIZE = 8;
        void validar(string);
        static int incrFeb(string);
    public:
        string getDia(), getMes(), getAno();
        static string getDia(string), getMes(string), getAno(string);
        void setData(string);
        static int isLeapYear(int);
        static int isLeapYear(string);
        int isLeapYear();
        Data(string);
        Data(string, string, string);
};

inline string Data::getDia() {
    return getDia(this->valor);
}

inline string Data::getDia(string data) {
    return data.substr(0, 2);
}

inline string Data::getMes() {
    return getMes(this->valor);
}

inline string Data::getMes(string data) {
    return data.substr(3, 2);
}

inline string Data::getAno() {
    return getAno(this->valor);
}

inline string Data::getAno(string data) {
    return "20" + data.substr(6, 2);
}

#endif // DOMINIOS_H
