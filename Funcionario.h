#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string> // Necessário para std::string
#include <iostream> 
#include <iomanip>  

class Funcionario {
private:
    int id;

protected:
    std::string nome;
    float salarioBase;

public:
    // Construtor
    Funcionario(std::string nome, float salarioBase, int id);

    // Getters (geralmente const)
    std::string getNome() const;
    float getSalarioBase() const;
    int getId() const;

    // Setters
    void setNome(std::string novoNome);
    void setSalarioBase(float novoSalario);
    void setId(int novoId);

    // Métodos virtuais puros e virtuais
    virtual float calcularSalarioFinal() const = 0;
    virtual void exibirInformacoes() const; 

    // Destrutor virtual (muito importante!)
    virtual ~Funcionario();
};

#endif