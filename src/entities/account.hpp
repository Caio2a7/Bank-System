#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
using namespace std;

typedef struct{
    int id;
    double amount;
    string creationData;
    string ownerName;
    string ownerCpf;
    vector<string> ownerEnd;
} AccountData;
//Implementação do Factory Method
class Account{
public:
    virtual ~Account(){};
    virtual AccountData getData() = 0;
    virtual int setData(AccountData newData) = 0;
};
class CurrentAccount : public Account{
private:
    AccountData currentData;
public:
    int setData(AccountData newData){
        currentData = newData;
        ofstream arquivo("../data/conta.db", ios::out | ios::binary);
        if(!arquivo.is_open()){
            cerr << "Erro ao abrir o arquivo." << endl;
            return 0;
        }
        
        arquivo << "ID: " << newData.id << "\n"  
        << "Proprietário: " << newData.ownerName << "\n"
        << "CPF: " << newData.ownerCpf << "\n"
        << "Endereço: \n" 
            << " (País): " << newData.ownerEnd[0]
            << "\n (Estado): " << newData.ownerEnd[1]
            << "\n (Cidade): " << newData.ownerEnd[2]
            << "\n (Rua e Número): " << newData.ownerEnd[3]
        << "\nSaldo: " << newData.amount << "\n"
        << endl;
        arquivo.close();

        ifstream arquivo1("../data/conta.db");
        string linha;
        while(getline(arquivo1, linha)){
            cout << "" << linha << endl;
        }
        arquivo.close();
        return 1;
    }
    AccountData getData() override {
        return currentData;
    };
};
class SavingAccount : public Account{
private:
    AccountData SavingData;
public:
    int setData(AccountData newData){
        SavingData = newData;
        return 1;
    }
    AccountData getData() override {
        return SavingData;
    };
};
class InvestmentAccount : public Account{
private:
    AccountData InvestmentData;
public:
    int setData(AccountData newData) override{
        InvestmentData = newData;
        return 1;
    };
    AccountData getData() override{
        return InvestmentData;
    }
};
//Factory para controlar quais contas serão instanciadas
class AccountFactory{
public:
    enum AccountType{
        CURRENT_ACCOUNT,
        SAVING_ACCOUNT,
        INVESTIMENT_ACCOUNT
    };
    static unique_ptr<Account> createAccount(AccountType type){
        switch(type){
            case CURRENT_ACCOUNT:
                return make_unique<CurrentAccount>();
            case SAVING_ACCOUNT:
                return make_unique<SavingAccount>();
            case INVESTIMENT_ACCOUNT:
                return make_unique<InvestmentAccount>();
        };
        return nullptr;
    }
};


#endif
