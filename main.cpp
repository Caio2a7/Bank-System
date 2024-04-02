#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "entities/transactions.hpp"
#include "entities/account.hpp"
using namespace std;

TransactionData setData(string transactionId, double amount, int accountId) {
    TransactionData transData;
    transData.transactionId = transactionId;
    transData.amount = amount;
    transData.accountId = accountId;
    return transData;
}

vector<unique_ptr<Account>> generateAccounts(){
    unique_ptr<Account> currentAccount = AccountFactory::createAccount(AccountFactory::CURRENT_ACCOUNT);
    AccountData newData = {id: 1, 1000, "12", "Caio", "1313123", {"Rua", "Estado"}};
    AccountData newData1 = {id: 2, 3000, "13", "Daniel", "8589678", {"Uar", "Doesta"}};
    currentAccount->setData(newData);
    unique_ptr<Account> savingAccount = AccountFactory::createAccount(AccountFactory::SAVING_ACCOUNT);
    savingAccount->setData(newData1);
    vector<unique_ptr<Account>> accounts;
    accounts.push_back(move(currentAccount));
    accounts.push_back(move(savingAccount));
    return accounts;
}

int main(int argc, char *argv[]) {
    auto start = chrono::high_resolution_clock::now();
    
    /*Escopo para contas*/
    vector<unique_ptr<Account>> contas = generateAccounts();
    /*Escopo para formatar os dados transladados(funções de taxa, análise...)*/
    
    Withdraw saque(setData("A231", 2000, contas[0]->getData().id));
    Deposit deposito(setData("B231", 1000, contas[1]->getData().id));
    Transfer transferencia(setData("C231", 3000, contas[1]->getData().id));
    
    /*Escopo para orquestração das operações(redes, registro...)*/
    TransactionsManager invoker;
    invoker.addTransaction(make_unique<Withdraw>(saque));
    invoker.addTransaction(make_unique<Deposit>(deposito));
    invoker.addTransaction(make_unique<Transfer>(transferencia));

    invoker.executeTransactions();
    
    /*Option de cronometrar tempo de execução*/
    auto end = chrono::high_resolution_clock::now();
    if (argc >= 2 && string(argv[1]) == "time") {
        chrono::duration<double> duration = end - start;
        cout << "Execution time: " << duration.count() << " seconds" << endl;
    }

    return 0;
}
