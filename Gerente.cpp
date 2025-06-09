#include "Gerente.h" // Inclui o cabeçalho da própria classe

// Implementação do construtor
Gerente::Gerente(std::string nome, float salarioBase, int id, float bonusMensal)
    : Funcionario(nome, salarioBase, id), bonusMensal(bonusMensal) {}

// Implementação de calcularSalarioFinal()
float Gerente::calcularSalarioFinal() const {
    return getSalarioBase() + bonusMensal;
}

// Implementação de exibirInformacoes()
void Gerente::exibirInformacoes() const {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Tipo: Gerente" << std::endl;
    std::cout << "Bonus: " << std::fixed << std::setprecision(2) << bonusMensal << std::endl;
    std::cout << "Salario base: " << std::fixed << std::setprecision(2) << getSalarioBase() << std::endl;
    std::cout << "Salario final: " << std::fixed << std::setprecision(2) << calcularSalarioFinal() << std::endl;
    std::cout << std::endl;
}