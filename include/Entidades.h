#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.h"

using namespace std;
///@brief Entidade que representa um trabalho realizado de uma certa disciplina dentro de um prazo determinado.
//por: Anita Garcia Lagos OLiveira (211068243)
class Tarefa {
    private:
            Texto nome;
            Codigo codigo;
            Data inicio;
            Data termino;
            Disciplina disciplina;
    public:
            ///@brief Armazena o nome da Tarefa caso o parâmetro passado seguir corretamente a formatação do domínio Texto.
            /// @param - Texto nome
            /// @throw - invalid_argument : se o valor passado não cumprir as regras de formatação
            void setNome(const Texto&);
            ///@brief Retorna o nome da Tarefa.
            /// @return - Texto nome
            Texto getNome() const;

            ///@brief Armazena o código da Tarefa caso o parâmetro passado seguir corretamente a formatação do domínio Código.
            /// @param - Codigo codigo
            /// @throw - invalid_argument : se o valor passado não cumprir as regras de formatação
            void setCodigo(const Codigo&);
            /// @brief Retorna o código da Tarefa.
            /// @return - Codigo codigo
            Codigo getCodigo() const;

            /// @brief Armazena a data de início da Tarefa caso o parâmetro passado seguir corretamente a formatação do domínio Data.
            /// @param - Data inicio
            /// @throw - invalid_argument : se o valor passado não cumprir as regras de formatação
            void setInicio(const Data&);
            /// @brief Retorna a data de início da Tarefa.
            /// @return - Data inicio
            Data getInicio() const;

            /// @brief Armazena a data de término da Tarefa caso o parâmetro passado seguir corretamente a formatação do domínio Data.
            /// @param - Data termino
            /// @throw - invalid_argument : se o valor passado não cumprir as regras de formatação
            void setTermino(const Data&);

            /// @brief Retorna a data de término da Tarefa.
            /// @return - Data termino
            Data getTermino() const;

            /// @brief Armazena a disciplina da Tarefa caso o parâmetro passado seguir corretamente a formatação do domínio Disciplina.
            /// @param - Disciplina discipllina
            /// @throw - invalid_argument : se o valor passado não cumprir as regras de formatação
            void setDisciplina(const Disciplina&);
            /// @brief Retorna a disciplina da Tarefa.
            /// @return - Disciplina disciplina
            Disciplina getDisciplina() const;
};

inline void Tarefa::setNome(const Texto &nome){
    this->nome = nome;
}

inline Texto Tarefa::getNome() const{
    return nome;
}

inline void Tarefa::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}

inline Codigo Tarefa::getCodigo() const{
    return codigo;
}

inline void Tarefa::setInicio(const Data &inicio){
    this->inicio = inicio;
}

inline Data Tarefa::getInicio() const{
    return inicio;
}

inline void Tarefa::setTermino(const Data &termino){
    this->termino = termino;
}

inline Data Tarefa::getTermino() const{
    return termino;
}

inline void Tarefa::setDisciplina(const Disciplina &disciplina){
    this->disciplina = disciplina;
}

inline Disciplina Tarefa::getDisciplina() const{
    return disciplina;
}

///@brief Um projeto é um esforço temporário que tem como finalidade um resultado único e possui recursos delimitados; é identificado no sistema por um código, e possui um nome e uma descrição.
class Projeto {
    private:
            Texto nome;
            Codigo codigo;
            Texto descricao;
    public:
            /// @brief Armazena o nome do Projeto caso o parâmetro passado seguir corretamente a formatação do domínio Texto.
            /// @param -Texto nome
            /// @throw -invalid_argument : se o valor passado não cumprir as regras de formatação
            void setNome(const Texto&);
            /// @brief Retorna o nome do Projeto.
            /// @return -Texto nome
            Texto getNome() const;
            /// @brief Armazena o código do Projeto caso o parâmetro passado seguir corretamente a formatação do domínio Código.
            /// @param -Codigo codigo
            /// @throw -invalid_argument : se o valor passado não cumprir as regras de formatação
            void setCodigo(const Codigo&);
            /// @brief Retorna o código do Projeto.
            /// @return -Codigo codigo
            Codigo getCodigo() const;
            /// @brief Armazena a descrição do Projeto caso o parâmetro passado seguir corretamente a formatação do domínio Texto.
            /// @param -Texto descricao
            /// @throw -invalid_argument : se o valor passado não cumprir as regras de formatação
            void setDescricao(const Texto&);
            /// @brief Retorna a descrição do Projeto.
            /// @return -Texto descricao
            Texto getDescricao() const;
};

inline void Projeto::setNome(const Texto &nome){
    this->nome = nome;
}

inline Texto Projeto::getNome() const{
    return nome;
}

inline void Projeto::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}

inline Codigo Projeto::getCodigo() const{
    return codigo;
}

inline void Projeto::setDescricao(const Texto &descricao){
    this->descricao = descricao;
}

inline Texto Projeto::getDescricao() const{
    return descricao;
}

///@brief Usuários são agentes externos ao sistema que usufruem da tecnologia para realizar determinado projeto.
///Cada usuário pode cadastrar uma conta informando nome, matrícula e senha.
class Usuario {
    private:
            Nome nome;
            Matricula matricula;
            Senha senha;
    public:
            /// @brief Armazena o nome do Usuário caso o parâmetro passado seguir corretamente a formatação do domínio Nome.
            /// @param - Nome nome
            /// @throw - invalid_argument : se o valor passado não cumprir as regras de formatação
            void setNome(const Nome&);
            /// @brief Retorna o nome do Usuário.
            /// @return - Nome nome
            Nome getNome() const;

            /// @brief Armazena a matrícula do Usuário caso o parâmetro passado seguir corretamente a formatação do domínio Matricula.
            /// @param - Matricula matricula
            /// @throw - invalid_argument : se o valor passado não cumprir as regras de formatação
            void setMatricula(const Matricula&);
            /// @brief Retorna a matrícula do Usuário.
            /// @return - Matricula matricula
            Matricula getMatricula() const;

            /// @brief Armazena a senha do Usuário caso o parâmetro passado seguir corretamente a formatação do domínio Senha.
            /// @param - Senha senha
            /// @throw - invalid_argument : se o valor passado não cumprir as regras de formatação
            void setSenha(const Senha&);
            /// @brief Retorna a senha do Usuário.
            /// @return - Senha senha
            Senha getSenha() const;
};

inline void Usuario::setNome(const Nome &nome){
    this->nome = nome;
}

inline Nome Usuario::getNome() const{
    return nome;
}

inline void Usuario::setMatricula(const Matricula &matricula){
    this->matricula = matricula;
}

inline Matricula Usuario::getMatricula() const{
    return matricula;
}

inline void Usuario::setSenha(const Senha &senha){
    this->senha = senha;
}

inline Senha Usuario::getSenha() const{
    return senha;
}

#endif // ENTIDADES_H_INCLUDED
