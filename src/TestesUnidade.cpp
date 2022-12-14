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
    VALOR_INVALIDO = new const string("12345678908");
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
    dominio = new Data;
    estado = true;
}

void TUNome::setUp() {
    VALOR_VALIDO = new const string("Neymar Jr");
    VALOR_INVALIDO = new const string("cRISTIANO rONALDO");
    dominio = new Nome;
    estado = true;
}

void TUProjeto::setUp() {
    projeto = new Projeto;
    estado = true;
}

void TUProjeto::tearDown() {
    delete projeto;
}

bool TUProjeto::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

void TUProjeto::testarCenarioSucesso() {
    const string NOME_VALIDO = "Projeto Alpha 001";
    const string CODIGO_VALIDO = "12345678900";
    const string DESCRICAO_VALIDA = "Um projeto muito bacaninha!";

    try {
        // teste do nome
        Texto nome;
        nome.setValor(NOME_VALIDO);
        projeto->setNome(nome);
        if (projeto->getNome().getValor() != NOME_VALIDO)
            estado = false;

        // teste codigo
        Codigo codigo;
        codigo.setValor(CODIGO_VALIDO);
        projeto->setCodigo(codigo);
        if (projeto->getCodigo().getValor() != CODIGO_VALIDO)
            estado = false;

        // teste descri????o
        Texto descricao;
        descricao.setValor(DESCRICAO_VALIDA);
        projeto->setDescricao(descricao);
        if (projeto->getDescricao().getValor() != DESCRICAO_VALIDA)
         estado = false;
    }
    catch (...) {
        estado = false;
    }
}

void TUTarefa::setUp() {
    tarefa = new Tarefa;
    estado = true;
}

void TUTarefa::tearDown(){
    delete tarefa;
}

bool TUTarefa::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

void TUTarefa::testarCenarioSucesso(){
    const string VALOR_VALIDO_NOME = "Trabalho de TP1";
    const string VALOR_VALIDO_CODIGO = "12345678900";
    const string VALOR_VALIDO_INICIO = "01-01-00";
    const string VALOR_VALIDO_TERMINO = "01-01-01";
    const string VALOR_VALIDO_DISCIPLINA = "Arquitetura";

    Texto nome;
    nome.setValor(VALOR_VALIDO_NOME);
    tarefa->setNome(nome);
    if(tarefa->getNome().getValor() != VALOR_VALIDO_NOME)
        estado = false;

    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    tarefa->setCodigo(codigo);
    if(tarefa->getCodigo().getValor() != VALOR_VALIDO_CODIGO)
        estado = false;

    Data inicio;
    inicio.setValor(VALOR_VALIDO_INICIO);
    tarefa->setInicio(inicio);
    if(tarefa->getInicio().getValor() != VALOR_VALIDO_INICIO)
        estado = false;

    Data termino;
    termino.setValor(VALOR_VALIDO_TERMINO);
    tarefa->setTermino(termino);
    if(tarefa->getTermino().getValor() != VALOR_VALIDO_TERMINO)
        estado = false;

    Disciplina disciplina;
    disciplina.setValor(VALOR_VALIDO_DISCIPLINA);
    tarefa->setDisciplina(disciplina);
    if(tarefa->getDisciplina().getValor() != VALOR_VALIDO_DISCIPLINA)
        estado = false;
}

void TUUsuario::setUp() {
    usuario = new Usuario();
    NOME_VALIDO = new const string(" Thiago Carrijo Rab ");
    MATRICULA_VALIDA = new const string("ABCD1234");
    SENHA_VALIDA = new const string("A1B2C3");

    estado = true;
}

void TUUsuario::testarCenarioSucesso() {
    try {
        Nome nome_teste;
        nome_teste.setValor(*NOME_VALIDO);
        usuario->setNome(nome_teste);
        if (usuario->getNome().getValor() != *NOME_VALIDO) {
            estado = false;
        }

        Senha senha_teste;
        senha_teste.setValor(*SENHA_VALIDA);
        usuario->setSenha(senha_teste);
        if (usuario->getSenha().getValor() != *SENHA_VALIDA)
            estado = false;

        Matricula matricula_teste;
        matricula_teste.setValor(*MATRICULA_VALIDA);
        usuario->setMatricula(matricula_teste);
        if (usuario->getMatricula().getValor() != *MATRICULA_VALIDA)
            estado = false;
    }
    catch (...) {
        estado = false;
    }
}

void TUUsuario::tearDown() {
    delete usuario;
    delete NOME_VALIDO;
    delete SENHA_VALIDA;
    delete MATRICULA_VALIDA;
}

bool TUUsuario::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

