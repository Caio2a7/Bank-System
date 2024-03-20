#ifndef CONTA_HPP
#define CONTA_HPP
using namespace std;

typedef struct{

}Cliente;
class Conta{
private:
    int id;
    float saldo;
    Cliente proprietario;
public:
Conta(int _id, float _saldo, string _proprietario) : id(_id), saldo(_saldo), proprietario(_proprietario){}
};
class Corrente : public Conta{

};
class Poupanca : public Conta{

};
class Universitaria : public Conta{

};
class Carteira : public Conta{

};
#endif