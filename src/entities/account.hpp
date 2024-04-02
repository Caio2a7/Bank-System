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
    virtual void setData(AccountData newData) = 0;
};
class CurrentAccount : public Account{
private:
    AccountData currentData;
public:
    void setData(AccountData newData){
        currentData = newData;
        ofstream arquivo("../data/conta.txt");
        if(!arquivo.is_open()){
            cerr << "Erro ao abrir o arquivo." << endl;
        }
        arquivo << "TESTE" << endl;
        arquivo.close();

        ifstream arquivo1("../data/conta.txt");
        string linha;
        while(getline(arquivo1, linha)){
            cout << "Linha " << linha << endl;
        }
        arquivo.close();
    }
    AccountData getData() override {
        return currentData;
    };
};
class SavingAccount : public Account{
private:
    AccountData SavingData;
public:
    void setData(AccountData newData){
        SavingData = newData;
    }
    AccountData getData() override {
        return SavingData;
    };
};
class InvestmentAccount : public Account{
private:
    AccountData InvestmentData;
public:
    void setData(AccountData newData) override{
        InvestmentData = newData;
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
