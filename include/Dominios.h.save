#ifndef DOMINIOS_H
#define DOMINIOS_H

#include <string>

using namespace std;
/// Classe abstrata, cujo principal atributo é uma string.
/// Essa classe serve como base para todas as outras classes de domínios do sistema.
class Dominio
{
    protected:
        /// Atributo principal da classe. <br/>
        /// É uma string que sempre está seguindo a formatação definida pela classe.
        string valor;
        /// Função que recebe uma string e avalia se ela cumpre as regras de formatação da classe, se elas não forem cumpridas lança uma exceção invalid_argument.
        /// @param -string valor: string que será avaliada.
        /// @throw -invalid_argumet: se a string passada não seguir a formatação apropriada para a classe
        virtual void validar(string valor) = 0;
        static int countChar(string, string);
        static string formatarInt(int, int);

    public:
        /// Retorna a string, com formatação válida, armazenada em valor
        /// @return -string valor
        string getValor() const;
        /// Armazena o valor da string passada no atributo valor se a string seguir corretamente as regras de formatação da classe.
        /// @param -string valor: string que se quer armazenar no atributo, esse valor deve seguir as regras de formatação da classe
        /// @throw -invalid_argument : se o valor passado não cumprir as regras de formatção
        void setValor( string valor );
};

inline string Dominio::getValor() const {
    return valor;
}

/// Representa os conhecimentos específicos que se ensinam em cada cadeira de uma escola. <br/>
/// O valor armazenado serve a seguinte regra:<ul>
/// <li>O valor deve ser uma das seguintes:<ul><li> Arquitetura</li><li> Desenvolvimento</li><li> Gerenciamento</li><li> Implantacao</li><li> Requisitos</li><li> Teste </li></ul></li> </ul>
class Disciplina:public Dominio {
    private:
        void validar(string valor);

};

/// Conjunto de Palavras.
/// O valor armazenado serve a seguinte regra:<ul>
///     <li> Deve ter no mínimo 10 caracteres e no máximo 40 </li>
///     <li> Cada caractere deve ser letra (de A-Z ou a-z), dígito (0-9) ou sinal de pontuação (. , ; ? ! : - ). </li>
///     <li> Não podem haver espaços em branco em sequência. </li>
///     <li> Não há sinal de pontuação (. , ; : ? ! -) em sequência.
/// </ul>
/// A acentução é desconsiderada.
class Texto:public Dominio {
    private:
        bool pontuacoesEmSequencia(const string pontuacoes, string valor);
        void validar(string valor);
        bool charEmSequencia(char carac, string str);

};

class Codigo:public Dominio {
    private:
        void validar(string);
};


class Matricula: public Dominio {
    private:
        void validar(string);
};


class Senha: public Dominio {
    private:
        void validar(string);
};

class Data:public Dominio {
    private:
        static const int SIZE = 8;
        static const int SECULO = 21;
        string const BARRA = "-";

        void validar(string);
        static int incrFeb(string);
        static int calcAno(int);

    public:
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
