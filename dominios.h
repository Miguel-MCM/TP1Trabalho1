#ifndef DOMINIOS_H
#define DOMINIOS_H

#include <iostream>
#include <stdexcept>
#include <string.h>

using namespace std;

class Dominio
{
    protected:
        string valor;
        virtual void validar(string) = 0;
    public:
        static int countChar(string, string);
        static string formatarInt(int, int);
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
    public:
        static int incrFeb(string);
        string getDia(), getMes(), getAno();
        static string getDia(string), getMes(string), getAno(string);
        void setData(string), setData(string, string, string), setData(int, int, int);
        static int isLeapYear(int);
        static int isLeapYear(string);
        int isLeapYear();
        Data(string);
        Data(string, string, string);
        Data(int, int, int);
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
