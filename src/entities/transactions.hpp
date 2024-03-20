#ifndef TRANSACAO_HPP
#define TRANSACAO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory> 
using namespace std;

struct TransactionData {
    string transactionId;
    double amount;
    int accountId;
};

// Commander Interface
class Transaction {
public:
    virtual ~Transaction() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Concrete commander
class Withdraw : public Transaction {
private:
    TransactionData withdrawData;
public:
    Withdraw(TransactionData _withdrawData) : withdrawData(_withdrawData) {}

    void execute() override {
         cout<< " Executado Saque(Transação: " << withdrawData.transactionId << ", Quantidade: " 
        << withdrawData.amount << ", Conta: " << withdrawData.accountId << ")" << endl;
    }

    void undo() override {
        cout << "Saque cancelado" << endl;
    }
};

// Concrete commander
class Deposit : public Transaction {
private:
    TransactionData depositData;
public:
    Deposit(TransactionData _depositData) : depositData(_depositData) {}

    void execute() override {
        cout<< " Executado Saque(Transação: " << depositData.transactionId << ", Quantidade: " 
        << depositData.amount << ", Conta: " << depositData.accountId << ")" << endl;
    }

    void undo() override {
        cout << "Depósito Cancelado" << endl;
    }
};

// Concrete Commander
class Transfer : public Transaction {
private:
    TransactionData transferData;
public:
    Transfer(TransactionData _transferData) : transferData(_transferData) {}

    void execute() override {
        cout << "Executado Saque (Transação: " << transferData.transactionId 
         << ", Quantidade: " << transferData.amount 
         << ", Conta: " << transferData.accountId << ")" << endl;
    }

    void undo() override {
        cout << "Transferência Cancelada" << endl;
    }
};

// Invoker
class TransactionsManager {
private:
    vector<unique_ptr<Transaction>> transactions; 
public:
    TransactionsManager() {}

    void addTransaction(unique_ptr<Transaction> transaction) {
        transactions.push_back(move(transaction)); 
    }

    void executeTransactions() {
        for (auto& transaction : transactions) {
            transaction->execute();
        }
    }
};

#endif
