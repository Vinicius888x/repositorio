#ifndef GERENTE_H
#define GERENTE_H

#include "Funcionario.h" // Inclui a classe base

class Gerente : public Funcionario {
private:
    float bonusMensal;

public:
    // Construtor
    Gerente(std::string nome, float salarioBase, int id, float bonusMensal);

    // Implementação dos métodos virtuais
    float calcularSalarioFinal() const override;
    void exibirInformacoes() const override;
};

#endif 