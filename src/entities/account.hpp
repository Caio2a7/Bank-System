#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
//int id
//AccountType tipo
//string proprietario_nome
//string proprietario_cpf
//vector<string> proprietario_end
//string data_criacao
typedef struct{
    int id;
    double amount;
    string creationData;
    string ownerName;
    string ownerCpf;
    vector<string> ownerEnd;
} AccountData;
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
//Factory para controlar quais contas serão instanciadas
class AccountFactory{
public:
    enum AccountType{
        CURRENT_ACCOUNT,
        SAVING_ACCOUNT
    };
    static unique_ptr<Account> createAccount(AccountType type){
        switch(type){
            case CURRENT_ACCOUNT:
                return make_unique<CurrentAccount>();
            case SAVING_ACCOUNT:
                return make_unique<SavingAccount>();
        };
        return nullptr;
    }
};


#endif