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

/// @brief Conjunto de 11 dígitos numéricos que representam uma informação.
/// @details O último dígito do código é o dígito verificador, calculado através do algoritmo de módulo 11 a seguir:<ul>
///     <li> Cada dígito do número, começando da direita para a esquerda é multiplicado, na ordem, por 2, depois 3, depois 4 e assim sucessivamente, até o primeiro dígito do número. </li>
///     <li> O somatório dessas multiplicações é multiplicado por 10 e depois dividido por 11. </li>
///     <li> O resto desta divisão (módulo 11) é o dígito verificador. </li>
/// </ul>
/// Observação: <ul>
///     <li> Sempre que o resto da divisão for maior ou igual a 10, o dígito verificador será 0 </li>
/// </ul>
//por: Anita Garcia Lagos OLiveira (211068243)
class Codigo:public Dominio {
    private:
        void validar(string);
};

/// @brief Conjunto de caracteres que possibilita registrar um usuário no sistema.
/// @details Formato: "LLLLDDDD" (8 caracteres) <ul>
///     <li> "L" é letra maiúscula (A-Z); </li>
///     <li> "D" é dígito numérico (0-9).
/// </ul>
//por: Anita Garcia Lagos OLiveira (211068243)
class Matricula: public Dominio {
    private:
        void validar(string);
};

/// @brief Sequência de  caracteres alfanuméricos que permite o acesso a dados ou sistemas informáticos protegidos.
/// @details Formato: "XXXXXX" (6 caracteres) <ul>
///     <li> "X" é letra maiúscula (A-Z) ou dígito (0-9); </li>
///     <li> Não pode haver caractere duplicado; </li>
///     <li> Existem pelo menos duas letras maiúsculas e dois dígitos. </li>
/// </ul>
//por: Anita Garcia Lagos OLiveira (211068243)
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
//por: Thiago Carrijo (211068350)
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
//por: Thiago Carrijo (211068350)
class Nome:public Dominio {
    private:
        void validar(string);
};

#endif // DOMINIOS_H
