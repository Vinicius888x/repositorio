#include "ContaBancaria.h"

ContaBancaria::ContaBancaria(int numero, Cliente titular, double saldo)
    : numero(numero), titular(titular), saldo(saldo) {}

void ContaBancaria::depositar(double valor) {
    if (valor > 0) {
        saldo += valor;
    } else {
        cout << "Valor de depósito inválido." << endl;
    }
}

void ContaBancaria::sacar(double valor) {
    if (valor > saldo) {
        cout << "Saldo insuficiente para saque na conta " << numero << endl;
    } else if (valor <= 0) {
        cout << "Valor de saque inválido." << endl;
    } else {
        saldo -= valor;
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino) {
    if (valor <= 0) {
        cout << "Valor de transferência inválido." << endl;
    } else if (valor > saldo) {
        cout << "Saldo insuficiente para transferir da conta " << numero << endl;
    } else {
        saldo -= valor;
        destino.depositar(valor);
        cout << "Transferido: R$ " << valor << " da conta " << numero
             << " para a conta " << destino.numero << endl;
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    if (valor <= 0) {
        cout << "Valor de transferência inválido." << endl;
    } else if (valor > saldo) {
        cout << "Saldo insuficiente para transferir da conta " << numero << endl;
    } else {
        double metade = valor / 2.0;
        saldo -= valor;
        destino1.depositar(metade);
        destino2.depositar(metade);
        cout << "Transferido: R$ " << metade << " para cada conta ("
             << destino1.numero << " e " << destino2.numero
             << ") da conta " << numero << endl;
    }
}

void ContaBancaria::exibirSaldo() const {
    cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
}

void ContaBancaria::exibirInformacoes() const {
    cout << "Titular: " << titular.getNome()
         << ", CPF: " << titular.getCpf() << endl;
    cout << "Número da Conta: " << numero
         << ", Saldo: R$ " << saldo << endl;
}
