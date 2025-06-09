#include <iostream>
#include <vector>
#include <limits>   
#include <string>    
#include "Funcionario.h"
#include "Desenvolvedor.h"
#include "Gerente.h"
#include "Estagiario.h"

int main() {
    std::vector<Funcionario*> funcionarios;
    const int CAPACIDADE_MINIMA_OBRIGATORIA = 6;
    const int CAPACIDADE_MAXIMA = 10;
    int contadorFuncionarios = 0;

    std::cout << "--- Sistema de Cadastro de Funcionarios ---" << std::endl;
    std::cout << "Por favor, cadastre ao menos " << CAPACIDADE_MINIMA_OBRIGATORIA << " funcionarios." << std::endl;

    while (contadorFuncionarios < CAPACIDADE_MINIMA_OBRIGATORIA || (contadorFuncionarios < CAPACIDADE_MAXIMA)) {
        std::cout << "\nCadastrar novo funcionario (total de " << contadorFuncionarios << "/" << CAPACIDADE_MAXIMA << " cadastrados):" << std::endl;
        std::cout << "Escolha o tipo de funcionario:" << std::endl;
        std::cout << "1 - Desenvolvedor" << std::endl;
        std::cout << "2 - Gerente" << std::endl;
        std::cout << "3 - Estagiario" << std::endl;
        std::cout << "0 - Concluir cadastro (se ja houver " << CAPACIDADE_MINIMA_OBRIGATORIA << " ou mais)" << std::endl;
        std::cout << "Opcao: ";

        int tipoFuncionario;
        std::cin >> tipoFuncionario;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (tipoFuncionario == 0) {
            if (contadorFuncionarios >= CAPACIDADE_MINIMA_OBRIGATORIA) {
                break;
            } else {
                std::cout << "Voce precisa cadastrar ao menos " << CAPACIDADE_MINIMA_OBRIGATORIA << " funcionarios antes de sair." << std::endl;
                continue;
            }
        } else if (tipoFuncionario < 1 || tipoFuncionario > 3) {
            std::cout << "Opcao invalida. Tente novamente." << std::endl;
            continue;
        }

        std::string nome;
        float salarioBase;
        int id;

        std::cout << "Digite o ID do funcionario: ";
        std::cin >> id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite o nome do funcionario: ";
        std::getline(std::cin, nome);
        std::cout << "Digite o salario base do funcionario: ";
        std::cin >> salarioBase;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Funcionario* novoFuncionario = nullptr;

        switch (tipoFuncionario) {
            case 1: {
                int quantidadeDeProjetos;
                std::cout << "Digite a quantidade de projetos do desenvolvedor: ";
                std::cin >> quantidadeDeProjetos;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                novoFuncionario = new Desenvolvedor(nome, salarioBase, id, quantidadeDeProjetos);
                break;
            }
            case 2: {
                float bonusMensal;
                std::cout << "Digite o bonus mensal do gerente: ";
                std::cin >> bonusMensal;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                novoFuncionario = new Gerente(nome, salarioBase, id, bonusMensal);
                break;
            }
            case 3: {
                int horasTrabalhadas;
                std::cout << "Digite as horas trabalhadas do estagiario: ";
                std::cin >> horasTrabalhadas;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                novoFuncionario = new Estagiario(nome, salarioBase, id, horasTrabalhadas);
                break;
            }
        }

        if (novoFuncionario != nullptr) {
            funcionarios.push_back(novoFuncionario);
            contadorFuncionarios++;
            std::cout << "Funcionario cadastrado com sucesso!" << std::endl;
        }

        if (contadorFuncionarios >= CAPACIDADE_MAXIMA) {
            std::cout << "\nCapacidade maxima de funcionarios atingida (" << CAPACIDADE_MAXIMA << "). Encerrando cadastro." << std::endl;
            break;
        }
    }

    std::cout << "\n--- Informacoes dos Funcionarios Cadastrados ---" << std::endl;
    if (funcionarios.empty()) {
        std::cout << "Nenhum funcionario cadastrado." << std::endl;
    } else {
        for (const Funcionario* f : funcionarios) {
            f->exibirInformacoes();
        }
    }

    for (Funcionario* f : funcionarios) {
        delete f;
    }
    funcionarios.clear();

    return 0;
}