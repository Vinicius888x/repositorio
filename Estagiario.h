#ifndef ESTAGIARIO_H
#define ESTAGIARIO_H

#include "Funcionario.h" // Inclui a classe base

class Estagiario : public Funcionario {
private:
    int horasTrabalhadas;

public:
    // Construtor
    Estagiario(std::string nome, float salarioBase, int id, int horasTrabalhadas);

    float calcularSalarioFinal() const override;
    void exibirInformacoes() const override;
};

#endif 