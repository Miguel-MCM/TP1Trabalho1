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
        cout << "\tSUCESSO." << endl;
    else
        cout << "\tFRACASSO" << endl;

    TUTexto t_u_texto;
    cout << "Teste Unidade Texto:\t ";
    if (t_u_texto.run())
        cout << "\tSUCESSO." << endl;
    else
        cout << "\tFRACASSO" << endl;

    TUCodigo t_u_codigo;
    cout << "Teste Unidade Codigo:\t";
    if (t_u_codigo.run())
        cout << "\tSUCESSO." << endl;
    else
        cout << "\tFRACASSO" << endl;

    TUMatricula t_u_matricula;
    cout << "Teste Unidade Matricula: ";
    if (t_u_matricula.run())
        cout << "\tSUCESSO." << endl;
    else
        cout << "\tFRACASSO" << endl;

    TUSenha t_u_senha;
    cout << "Teste Unidade Senha:\t";
    if (t_u_senha.run())
        cout << "\tSUCESSO." << endl;
    else
        cout << "\tFRACASSO" << endl;

    TUData t_u_data;
    cout << "Teste Unidade Data:\t";
    if (t_u_data.run())
        cout << "\tSUCESSO." << endl;
    else
        cout << "\tFRACASSO" << endl;

    TUNome t_u_nome;
    cout << "Teste Unidade Nome:\t";
    if (t_u_nome.run())
        cout << "\tSUCESSO." << endl;
    else
        cout << "\tFRACASSO" << endl;

    cout << endl;

    TUProjeto t_u_projeto;
    cout << "Teste Unidade Projeto: \t";
    if (t_u_projeto.run())
        cout << "\tSUCESSO." << endl;
    else
        cout << "\tFRACASSO." << endl;

     TUTarefa t_u_tarefa;
    cout << "Teste Unidade Tarefa: \t";
    if (t_u_tarefa.run())
        cout << "\tSUCESSO." << endl;
    else
        cout << "\tFRACASSO." << endl;

    TUUsuario t_u_usuario;
    cout << "Teste Unidade Usuario: \t\t";
    if (t_u_usuario.run())
        cout << "SUCESSO." << endl;
    else
        cout << "FRACASSO." << endl;

    return 0;
}
