#include "TestesUnidade.h"

#include <stdexcept>
bool TUDominio::run(){
    setUp();
    testarCenarioValido();
    testarCenarioInvalido();
    tearDown();
    return estado;
}

void TUDominio::tearDown(){
    delete dominio;
    delete VALOR_VALIDO;
    delete VALOR_INVALIDO;
}

void TUDominio::testarCenarioValido() {
    try {
        dominio->setValor(*VALOR_VALIDO);
        if (dominio->getValor() != *VALOR_VALIDO)
            estado = false;
    }
    catch(...) {
        estado = false;
    }
}

void TUDominio::testarCenarioInvalido(){
    try {
        dominio->setValor(*VALOR_INVALIDO);
        estado = false;
    }
    catch (invalid_argument &except) {
        if(dominio->getValor() == *VALOR_INVALIDO)
            estado = false;
    }
}

void TUDisciplina::setUp() {
    VALOR_VALIDO = new const string("Arquitetura");
    VALOR_INVALIDO = new const string("Tecnicas de Programcao 1");
    dominio = new Disciplina;
    estado = true;
}

void TUTexto::setUp() {
    VALOR_VALIDO = new const string("Lorem ipsum dolor sit amet.");
    VALOR_INVALIDO = new const string("abc");
    dominio = new Texto;
    estado = true;
}

void TUCodigo::setUp() {
    VALOR_VALIDO = new const string("12345678900");
    VALOR_INVALIDO = new const string("1234567898");
    dominio = new Codigo;
    estado = true;
}

void TUMatricula::setUp() {
    VALOR_VALIDO = new const string("ABCD1234");
    VALOR_INVALIDO = new const string("1234ABCD");
    dominio = new Matricula;
    estado = true;
}

void TUSenha::setUp() {
    VALOR_VALIDO = new const string("A1B2C3");
    VALOR_INVALIDO = new const string("123456");
    dominio = new Senha;
    estado = true;
}

void TUData::setUp() {
    VALOR_VALIDO = new const string("01-01-00");
    VALOR_INVALIDO = new const string("30-02-99");
    dominio = new Data("31-12-99");
    estado = true;
}
/*
void TUNome::setUp() {
    VALOR_VALIDO = new const string("Neymar Jr");
    VALOR_INVALIDO = new const string("cRISTIANO rONALDO");
    dominio = new Nome;
    estado = true;
}
*/
