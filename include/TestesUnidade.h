#ifndef TESTESUNIDADE_H
#define TESTESUNIDADE_H
#include "Dominios.h"
#include "Entidades.h"
//por Miguel Carvalho 211068341
class TUDominio {
    protected:
        bool estado;
        Dominio * dominio;
        const string * VALOR_VALIDO;
        const string * VALOR_INVALIDO;
        virtual void setUp() = 0;
        void tearDown();
        virtual void testarCenarioValido();
        virtual void testarCenarioInvalido();

    public:
        bool run();
};

class TUDisciplina:public TUDominio{
    private:
        void setUp();
};

class TUTexto:public TUDominio{
    private:
        void setUp();
};

class TUCodigo:public TUDominio{
    private:
        void setUp();
};

class TUMatricula:public TUDominio{
    private:
        void setUp();
};

class TUSenha:public TUDominio{
    private:
        void setUp();
};

class TUData:public TUDominio{
    private:
        void setUp();
};

class TUNome:public TUDominio{
    private:
        void setUp();
};

//por Miguel Carvalho 211068341
class TUProjeto {
private:
    Projeto *projeto;
    bool estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    bool run();
};
//por: Anita Garcia Lagos OLiveira (211068243)
class TUTarefa {
    private:
        Tarefa *tarefa;
        bool estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
    public:
        bool run();
};
//por: Thiago Carrijo (211068350)
class TUUsuario {
    private:
       Usuario * usuario;
       const string * NOME_VALIDO;
       const string * MATRICULA_VALIDA;
       const string * SENHA_VALIDA;

       bool estado;
       void setUp();
       void testarCenarioSucesso();
       void tearDown();
    public:
        bool run();
};

#endif // TESTESUNIDADE_H
