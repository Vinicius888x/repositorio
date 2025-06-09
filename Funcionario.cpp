#include "Funcionario.h" // Inclui o cabeçalho da própria classe

// Implementação do construtor
Funcionario::Funcionario(std::string nome, float salarioBase, int id)
    : nome(nome), salarioBase(salarioBase), id(id) {}

// Implementação dos getters
std::string Funcionario::getNome() const {
    return nome;
}

float Funcionario::getSalarioBase() const {
    return salarioBase;
}

int Funcionario::getId() const {
    return id;
}

// Implementação dos setters
void Funcionario::setNome(std::string novoNome) {
    nome = novoNome;
}

void Funcionario::setSalarioBase(float novoSalario) {
    salarioBase = novoSalario;
}

void Funcionario::setId(int novoId) {
    id = novoId;
}

// Implementação padrão de exibirInformacoes()
void Funcionario::exibirInformacoes() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Salario Base: " << std::fixed << std::setprecision(2) << salarioBase << std::endl;
}

// Implementação do destrutor virtual
Funcionario::~Funcionario() {

}