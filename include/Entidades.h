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

class Projeto {
    private:
            Texto nome;
            Codigo codigo;
            Texto descricao;
    public:
            void setNome(const Texto&);
            Texto getNome() const;

            void setCodigo(const Codigo&);
            Codigo getCodigo() const;

            void setDescricao(const Texto&);
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
