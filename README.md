## Objetivo
Sistema Bancário Desktop CLI para clientes do Banco Caixão Econômico poderem ter acesso a todos nossos serviços normalmente prestados em locais físicos

## Serviços
- Criação de Conta 
    - Corrente
    - Poupança
    - Conta Universitária(Corrente e Poupança)
- Depósito
- Saque
- Extrato bancário
- Criação de Carteire de Investimentos
    - Fundos de Investimento
    - Tesouro Direto
    - Ações
    - Criptomoedas
- Atendimento
- Previdência

## Sistema

### Interface
Os usuários irão interagir com o sistema apartir de uma CLI, com a navegação da interface ocorrendo pelas opções numeradas e o usuário inserido os dados via input. Ademais, o sistema sempre retorna mensagens de avisos como *Operação feita com sucesso* etc para situar o usuário.

### Regras de Negócio
As estruturas abstratas de dados, operações, regras e políticas são organizadas em aneis arquiteturais elevados, baseando todo o sistema ao redor dessas entidades, as quais não dependem de nenhum outro program de baixo nível, com o core do sistema sendo independente da interface, armazenamento de dados, bibliotecas, ou frameworks. 

### Banco de Dados
Os dados serão armazenados em arquivos binários .db e .bin, para acelerar a leitura pela memória ram, garantir uma maior segurança, pois apenas o programa correto conseguirá acessar os dados por saber as estruturas de dados.