#include "Dominios.h"

#include <stdexcept>
#include <ctype.h>

using namespace std;

void Dominio::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

void Disciplina::validar(string valor) {

    const int NUM_DISCIP_VALIDAS = 6;
    const string DISCIPLINAS_VALIDAS[NUM_DISCIP_VALIDAS] = {"Arquitetura", "Desenvolvimento", "Gerenciamento", "Implantacao", "Requisitos", "Teste"};

    for (int i = 0; i < NUM_DISCIP_VALIDAS; i++) {
        if (valor == DISCIPLINAS_VALIDAS[i])
          return ;
    }
        throw invalid_argument("Disciplina Invalida");
}


bool Texto::charEmSequencia(char carac, string str) {
    for (int i=1; i<str.size();i++) {
        if (str[i]==carac && str[i-1]==carac)
            return true;
    }
    return false;
}

bool Texto::pontuacoesEmSequencia(const string pontuacoes, string valor) {
    for (int i=1; i<valor.size();i++) {
        if ((pontuacoes.find(valor[i]) != string::npos) && (pontuacoes.find(valor[i-1]) != string::npos))
            return true;
    }
    return false;
}

void Texto::validar(string valor) {
    const string PONTUACOES_VALIDAS = ".,;?!:-";
    // mais de 10 caracteres
    if (valor.size() < 10) throw invalid_argument("Texto com menos de 10 caracteres.");
    if (valor.size() > 40) throw invalid_argument("Texto com mais de 40 caracteres.");
    // cada caractere é letra(A-Z ou a-z), digito(0-9) ou pontuaçao ( . , ; ? ! : - )
    for (string::iterator it=valor.begin(); it!=valor.end(); ++it) {
        if(!(isalpha(*it) || isdigit(*it) || isspace(*it) || (PONTUACOES_VALIDAS.find(*it) != string::npos)))
            throw invalid_argument("Texto com caractere invalido.");
    }
    //não há espaços em branco em sequencia
    if (charEmSequencia(' ', valor)) throw invalid_argument("Texto com espaços em sequencia.");
    //Não há sinal de pontuação (. , ; : ? ! -) em sequência.
    if (pontuacoesEmSequencia(PONTUACOES_VALIDAS, valor)) throw invalid_argument("Texto com pontuacoes em sequencia.");
}

void Codigo::validar(string valor) {
    const int TAMANHO = 11;
    const int VERIFICADOR = 10;
    int pesos_arr[10] = {3,2,9,8,7,6,5,4,3,2};
    int result_ponderado = 0;
    int digito_verificador;

    if(valor.size() != TAMANHO)
       throw invalid_argument("1.Argumento invalido.");

    char* char_arr;
    char_arr = &valor[0];

    for (int i=0; i < TAMANHO ; i++) {
        if (isdigit(char_arr[i])==0) {
            throw invalid_argument("2.Argumento invalido.");
        }

        if (i != VERIFICADOR) {
            result_ponderado += (char_arr[i] - '0')*pesos_arr[i];
        }
        else {
            digito_verificador = (result_ponderado*10)%11;
            if (digito_verificador > 9) {
                digito_verificador = 0;
            }
            if (digito_verificador!=(char_arr[i] - '0')){
                throw invalid_argument("3.Argumento invalido.");
            }
        }
    }
 }

 void Matricula::validar(string valor) {
     const int MAX_CHAR = 4;
     const int TAMANHO = 8;

     if(valor.size() != TAMANHO)
        throw invalid_argument("Argumento invalido.");

     char* char_arr;
     char_arr = &valor[0];

     for (int i=0; i < TAMANHO ; i++) {
        if (i < MAX_CHAR) {
            if (isalpha(char_arr[i])==0 || isupper(char_arr[i])==0){
                throw invalid_argument("Argumento invalido.");
            }
        }
        else {
            if (isdigit(char_arr[i])==0) {
                throw invalid_argument("Argumento invalido.");
            }
        }
    }

     }

void Senha::validar(string valor) {
    const int TAMANHO = 6;
    const int MINIMO = 2;
    int letras = 0;
    int digitos = 0;

    if(valor.size() != TAMANHO) {
        throw invalid_argument("Argumento invalido.");
    }

    char* char_arr;
    char_arr = &valor[0];

    for (int i=0; i < TAMANHO ; i++) {
        if (isdigit(char_arr[i])==0 && isupper(char_arr[i])==0) {
            throw invalid_argument("Argumento invalido.");
        }
        if (isdigit(char_arr[i])) {
            digitos ++;
        }
        if (isupper(char_arr[i])) {
            letras ++;
        }

        for (int j=i+1; j < TAMANHO; j++) {
            if (char_arr[i] == char_arr[j]) {
                throw invalid_argument("Argumento invalido.");
            }
        }
    }

    if (letras < MINIMO || digitos < MINIMO){
        throw invalid_argument("Argumento invalido.");
    }
}

string Data::formatarInt(int n, int digitos) {
    string str_n = to_string(n);
    int tamanho = str_n.length();

    for (int i = 0; i < digitos - tamanho; i++) {
        str_n = "0" + str_n;
    }

    return str_n;
}

int Data::countChar(string param, string target) {
    if (target.length() != 1)
        throw invalid_argument("Argumento invalido");
    int res;
    for (int i = 0; i < param.length(); i++)
        if (param[i] == target[0])
            res++;
    return res;
}

int Data::calcAno(int ano) {
    return 100 * (SECULO - 1) + ano;
}

void Data::validar(string data) {
    int MESES[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // validar a formatacao
    if (data.length() != SIZE) {
        throw invalid_argument("Argumento invalido: tamanho inadequado " + data);
    }
    for (int i = 0; i < SIZE; i++) {
        if (i == 2 || i == 5) {
            if (data[i] != BARRA) {
                throw invalid_argument("Argumento invalido: fora da formatacao " + data);
            }
        }
        else if (!isdigit(data[i])) {
            throw invalid_argument("Argumento invalido: digito invalido " + data);
        }
    }

    // validacao do dia, mes e ano
    int mes = stoi(getMes(data));
    int dia = stoi(getDia(data));
    if (1 <= mes && mes <= 12) {
        if (dia != 0 && dia <= MESES[mes - 1] + incrFeb(data))
            return;
    }
    throw invalid_argument("Argumento invalido: data invalida " + data);
}

int Data::incrFeb(string data) {
    if (stoi(getMes(data)) != 2)
        return 0;
    return isLeapYear(data);
}

bool Data::isLeapYear() {
    return isLeapYear(this->valor);
}

bool Data::isLeapYear(int ano) {
    return ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0);
}

bool Data::isLeapYear(string data) {
    return isLeapYear(calcAno(stoi(getAno(data))));
}

void Nome::validar(string nome) {
    if (nome.length() > 20)
        throw invalid_argument("Tamanho de nome invalido");

    int espacos = 0;
    int p = 0;
    for (string::iterator it=nome.begin(); it != nome.end(); it++) {
        if (isspace(*it)) {
            if (it != nome.begin() && it != nome.end() - 1) {
                espacos++;
            }
            if (it != nome.end() - 1 && isspace(*(it + 1))) {
                throw invalid_argument("Sequencia de espacos invalido");
            }
        }
        else if (isalpha(*it)) {
            if (it == nome.begin() || isspace(*(it - 1))) {
                if (islower(*it)) {
                    throw invalid_argument("Prenome ou sobrenome comecando com letra minuscula");
                }
            }
            else if (isupper(*it)){
                throw invalid_argument("Prenome ou sobrenome com letra maiuscula no meio");
            }

        }
        else {
            throw invalid_argument("Caracter invalido (posicao: " + to_string(p) + ")");
        }
        p++;
    }

    if (espacos > 2) {
        throw invalid_argument("Mais de 2 sobrenomes");
    }
}
