#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "entities/transactions.hpp"
using namespace std;

TransactionData generateData(string transactionId, double amount, int accountId) {
    TransactionData transData;
    transData.transactionId = transactionId;
    transData.amount = amount;
    transData.accountId = accountId;
    return transData;
}

int main(int argc, char *argv[]) {
    auto start = chrono::high_resolution_clock::now();
    unique_ptr<int> conta1 = make_unique<int>(123);
    unique_ptr<int> conta2 = make_unique<int>(223);
    
    vector<unique_ptr<int>> contas;
    contas.push_back(move(conta1));
    contas.push_back(move(conta2));

    Withdraw saque(generateData("A231", 2000, *contas[0]));
    Deposit deposito(generateData("B231", 1000, *contas[1]));
    Transfer transferencia(generateData("C231", 3000, *contas[1]));

    TransactionsManager invoker;
    invoker.addTransaction(make_unique<Withdraw>(saque));
    invoker.addTransaction(make_unique<Deposit>(deposito));
    invoker.addTransaction(make_unique<Transfer>(transferencia));

    invoker.executeTransactions();

    auto end = chrono::high_resolution_clock::now();

    if (argc >= 2 && string(argv[1]) == "time") {
        chrono::duration<double> duration = end - start;
        cout << "Execution time: " << duration.count() << " seconds" << endl;
    }

    return 0;
}
