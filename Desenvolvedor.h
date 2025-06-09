#ifndef DESENVOLVEDOR_H
#define DESENVOLVEDOR_H

#include "Funcionario.h" // Inclui a classe base

class Desenvolvedor : public Funcionario {
private:
    int quantidadeDeProjetos;

public:
    // Construtor
    Desenvolvedor(std::string nome, float salarioBase, int id, int quantidadeDeProjetos);

    // Implementação dos métodos virtuais
    float calcularSalarioFinal() const override;
    void exibirInformacoes() const override;
};

#endif 