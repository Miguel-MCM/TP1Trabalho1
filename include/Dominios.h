#ifndef DOMINIOS_H
#define DOMINIOS_H

#include <string>

using namespace std;
/// @brief Classe abstrata, cujo principal atributo é uma string.
/// @details Essa classe serve como base para todas as outras classes de domínios do sistema.
// por: Miguel Carvalho 211068341
class Dominio
{
    protected:
        /// @brief Atributo principal da classe. <br/>
        /// É uma string que sempre está seguindo a formatação definida pela classe.
        string valor;
        virtual void validar(string valor) = 0;


    public:
        /// @brief Retorna a string, com formatação válida, armazenada em valor
        /// @return string valor
        /// @memberof Disciplina
        string getValor() const;
        /// @brief Armazena o valor da string passada no atributo valor se a string seguir corretamente as regras de formatação da classe.
        /// @param -string valor: string que se quer armazenar no atributo, esse valor deve seguir as regras de formatação da classe
        /// @throw -invalid_argument : se o valor passado não cumprir as regras de formatação
        void setValor( string valor );
};

inline string Dominio::getValor() const {
    return valor;
}

/// @brief Representa os conhecimentos específicos que se ensinam em cada cadeira de uma escola. <br/>
/// @details O valor armazenado serve a seguinte regra:<ul>
/// <li>O valor deve ser uma das seguintes:<ul><li> Arquitetura</li><li> Desenvolvimento</li><li> Gerenciamento</li><li> Implantacao</li><li> Requisitos</li><li> Teste </li></ul></li> </ul>
// por Miguel Carvalho 211068341
class Disciplina:public Dominio {
    private:
        void validar(string valor);

};

/// @brief Representa um conjunto de palavras.
/// @details O valor armazenado segue as seguintes regras:<ul>
///     <li> Deve ter no mínimo 10 caracteres e no máximo 40 </li>
///     <li> Cada caractere deve ser letra (de A-Z ou a-z), dígito (0-9) ou sinal de pontuação (. , ; ? ! : - ). </li>
///     <li> Não podem haver espaços em branco em sequência. </li>
///     <li> Não há sinal de pontuação (. , ; : ? ! -) em sequência.</li>
/// </ul>
/// A acentução é desconsiderada.
// por Miguel Carvalho 211068341
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

/// @brief Forma de representação do dia atual, a partir do ano 2000
/// @details Regras de formatação:
/// <ul>
/// <li>DD-MM-AA, em que D, M e A representam os digitos de Dia, Mês e Ano</li>
/// <li>Dias: 1 a 31</li>
/// <li>Meses: 1 a 12</li>
/// <li>Anos: 0 a 99</li>
/// <li>Há verificação de ano bissexto</li>
/// </ul>
class Data:public Dominio {
    private:
        static const int SIZE = 8;
        static const int SECULO = 21;
        static const char BARRA = '-';

        void validar(string);
        static int incrFeb(string);
        static int calcAno(int);
        static int countChar(string, string);
        static string formatarInt(int, int);

    public:
        /// @brief Retorna apenas a parte do dia da data armazenada
        string getDia();
        /// @brief Retorna apenas a parte do mês da data armazenada
        string getMes();
        /// @brief Retorna apenas a parte do ano da data armazenada
        string getAno();
        /// @brief Retorna apenas a parte do dia da string passada
        static string getDia(string);
        /// @brief Retorna apenas a parte do mês da string passada
        static string getMes(string);
        /// @brief Retorna apenas a parte do ano da string passada
        static string getAno(string);

        /// @brief Retorna se o ano passado é um ano bissexto
        static bool isLeapYear(int);
        /// @brief Retorna se o ano passado é um ano bissexto
        static bool isLeapYear(string);
        /// @brief Retorna se o ano da data armazenado é um ano bissexto
        bool isLeapYear();

        /// @brief Construtor padrão que apenas armazenará a string recebida no atributo valor, após validação.
        /// @param string data
        Data(string);

        /// @brief Construtor alternativo que receberá dia, mês e ano separadamente e os junta para armazená-los no atributo valor, após validação.
        /// @param string Dia
        /// @param string Mes
        /// @param string Ano
        Data(string, string, string);

        /// @brief Construtor alternativo, que receberá dia, mês e ano separadamente e, depois de convertê-los para string, os junta para armazená-los no atributo valor, após validação.
        /// @param int Dia
        /// @param int Mes
        /// @param int Ano
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

/// @brief Conjunto de caracteres que são uma forma alternativa de identificação do usuário.
/// @details <ul>
/// <li>Nome é composto por prenome e até dois sobrenomes.</li>
/// <li>Texto (prenome mais sobrenomes e espaços em branco) é composto por total de até 20 caracteres.</li>
/// <li>Cada caractere é letra (A-Z a-z) ou espaço em branco.</li>
/// <li>Primeira letra de prenome ou de sobrenome é maiúscula (A-Z) e as outras são minúsculas (a-z).</li>
/// <li>Não há espaços em branco em sequência.</li>
/// <li>Acentuação pode ser desconsiderada.</li>
/// </ul>

class Nome:public Dominio {
    private:
        void validar(string);

    public:
        /// Construtor padrão, recebe uma string e, após validar, a armazena no atributo valor.
        /// @param string nome

        Nome(string);
};

#endif // DOMINIOS_H
