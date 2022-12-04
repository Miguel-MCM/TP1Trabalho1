#ifndef TESTESUNIDADE_H
#define TESTESUNIDADE_H
#include "Dominios.h"


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
        //void setUp();
};

#endif // TESTESUNIDADE_H
