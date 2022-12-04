#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "Dominios.h"

using namespace std;

class Tarefa {
    private:
            Texto nome;
            Codigo codigo;
            Data inicio;
            Data termino;
            Disciplina disciplina;
    public:
            void setNome(const Texto&);
            Texto getNome() const;

            void setCodigo(const Codigo&);
            Codigo getCodigo() const;

            void setInicio(const Data&);
            Data getInicio() const;

            void setTermino(const Data&);
            Data getTermino() const;

            void setDisciplina(const Disciplina&);
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

///Um projeto é um esforço temporário que tem como finalidade um resultado único e possui recursos delimitados; é identificado no sistema por um código, e possui um nome e uma descrição.
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

class Usuario {
    private:
            Nome nome;
            Matricula matricula;
            Senha senha;
    public:
            void setNome(const Nome&);
            Nome getNome() const;

            void setMatricula(const Matricula&);
            Matricula getMatricula() const;

            void setSenha(const Senha&);
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
