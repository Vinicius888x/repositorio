#include "Desenvolvedor.h" // Inclui o cabeçalho da própria classe

// Implementação do construtor
Desenvolvedor::Desenvolvedor(std::string nome, float salarioBase, int id, int quantidadeDeProjetos)
    : Funcionario(nome, salarioBase, id), quantidadeDeProjetos(quantidadeDeProjetos) {}

// Implementação de calcularSalarioFinal()
float Desenvolvedor::calcularSalarioFinal() const {
    return getSalarioBase() + (500.0f * quantidadeDeProjetos);
}

// Implementação de exibirInformacoes()
void Desenvolvedor::exibirInformacoes() const {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Tipo: Desenvolvedor" << std::endl;
    std::cout << "Projetos: " << quantidadeDeProjetos << std::endl;
    std::cout << "Salario base: " << std::fixed << std::setprecision(2) << getSalarioBase() << std::endl;
    std::cout << "Salario final: " << std::fixed << std::setprecision(2) << calcularSalarioFinal() << std::endl;
    std::cout << std::endl;
}