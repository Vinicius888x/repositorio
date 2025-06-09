#include "Estagiario.h" 

// Implementação do construtor
Estagiario::Estagiario(std::string nome, float salarioBase, int id, int horasTrabalhadas)
    : Funcionario(nome, salarioBase, id), horasTrabalhadas(horasTrabalhadas) {}

// Implementação de calcularSalarioFinal()
float Estagiario::calcularSalarioFinal() const {
    return getSalarioBase() * (static_cast<float>(horasTrabalhadas) / 160.0f);
}

// Implementação de exibirInformacoes()
void Estagiario::exibirInformacoes() const {
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Tipo: Estagiario" << std::endl;
    std::cout << "Horas trabalhadas: " << horasTrabalhadas << std::endl;
    std::cout << "Salario base: " << std::fixed << std::setprecision(2) << getSalarioBase() << std::endl;
    std::cout << "Salario final: " << std::fixed << std::setprecision(2) << calcularSalarioFinal() << std::endl;
    std::cout << std::endl;
}