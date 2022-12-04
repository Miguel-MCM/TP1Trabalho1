#include <iostream>
#include <math.h>
#include "Dominios.h"
#include "TestesUnidade.h"

using namespace std;

int main()
{
    TUDisciplina t_u_disciplina;
    cout << "Teste Unidade Disciplina: ";
    if (t_u_disciplina.run())
        cout << "SUCESSO." << endl;
    else
        cout << "FRACASSO" << endl;

    TUTexto t_u_texto;
    cout << "Teste Unidade Texto: ";
    if (t_u_texto.run())
        cout << "SUCESSO." << endl;
    else
        cout << "FRACASSO" << endl;

    TUCodigo t_u_codigo;
    cout << "Teste Unidade Codigo: ";
    if (t_u_codigo.run())
        cout << "SUCESSO." << endl;
    else
        cout << "FRACASSO" << endl;

    TUMatricula t_u_matricula;
    cout << "Teste Unidade Matricula: ";
    if (t_u_matricula.run())
        cout << "SUCESSO." << endl;
    else
        cout << "FRACASSO" << endl;

    TUSenha t_u_senha;
    cout << "Teste Unidade Senha: ";
    if (t_u_senha.run())
        cout << "SUCESSO." << endl;
    else
        cout << "FRACASSO" << endl;

    TUData t_u_data;
    cout << "Teste Unidade Data: ";
    if (t_u_data.run())
        cout << "SUCESSO." << endl;
    else
        cout << "FRACASSO" << endl;

    TUNome t_u_nome;
    cout << "Teste Unidade Nome: ";
    if (t_u_nome.run())
        cout << "SUCESSO." << endl;
    else
        cout << "FRACASSO" << endl;

    cout << endl;

    TUProjeto t_u_projeto;
    cout << "Teste Unidade Projeto: ";
    if (t_u_projeto.run())
        cout << "SUCESSO" << endl;
    else
        cout << "FRACASSO" << endl;

    return 0;
}
