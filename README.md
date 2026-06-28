# Sistema de Controle de Estoque e Vendas

Projeto desenvolvido para a disciplina **DIM0501 – Boas Práticas de Programação**, da Universidade Federal do Rio Grande do Norte (UFRN), com o objetivo de identificar, classificar, priorizar e quitar dívidas técnicas presentes em um sistema legado.

## Objetivo

O projeto consiste na análise de um sistema simples de controle de estoque e vendas desenvolvido sob pressão, contendo diversas dívidas técnicas. O trabalho tem como foco aplicar conceitos de gerenciamento de dívida técnica, realizando um diagnóstico do código existente, priorizando os problemas encontrados e implementando a correção dos itens considerados mais importantes.

## Funcionalidades do Sistema

O sistema permite:

* Cadastro de produtos;
* Registro de vendas;
* Atualização automática do estoque;
* Listagem dos produtos cadastrados;
* Relatório de produtos com estoque baixo;
* Acesso administrativo por senha.

## Tecnologias Utilizadas

* Linguagem: C++
* Compilador recomendado: g++
* Padrão utilizado: C++17

## Estrutura do Projeto

```text
.
├── Estoque.cpp
├── README.md
└── Relatorio_Tecnico.pdf
```

## Como Compilar

Utilizando o compilador **g++**:

```bash
g++ -std=c++17 Estoque.cpp -o estoque
```

## Como Executar

No Linux ou macOS:

```bash
./estoque
```

No Windows:

```bash
estoque.exe
```

## Dívidas Técnicas Identificadas

Durante a análise do código foram identificadas diversas dívidas técnicas relacionadas a:

* Robustez;
* Código duplicado;
* Configuração hardcoded;
* Arquitetura;
* Código morto;
* Ausência de testes;
* Documentação;
* Uso de números mágicos.

Esses itens foram classificados quanto ao esforço de correção (principal), impacto e custo de convivência (juros), permitindo estabelecer uma ordem de prioridade para sua quitação.

## Dívidas Técnicas Quitadas

Neste trabalho foram quitadas duas dívidas técnicas consideradas prioritárias.

### D2 – Validação das Entradas

Foi adicionada validação para os campos de preço e quantidade, impedindo que entradas inválidas interrompam a execução do programa.

**Benefícios:**

* Maior robustez;
* Melhor experiência do usuário;
* Redução de falhas durante a execução.

### D3 – Unificação da Regra de Desconto

Foi criada uma função responsável pelo cálculo do desconto, eliminando a duplicação da regra existente nas funções `vender()` e `calcular_total()`.

**Benefícios:**

* Eliminação de código duplicado;
* Padronização da regra de negócio;
* Facilidade de manutenção;
* Redução do risco de inconsistências futuras.

## Resultados Obtidos

Após as refatorações realizadas:

* O sistema continua apresentando o mesmo comportamento funcional.
* As entradas do usuário passaram a ser validadas corretamente.
* A regra de desconto passou a possuir uma única implementação.
* O código tornou-se mais consistente e mais fácil de manter.

## Autores

* Randson Thiago Sales da Silva Lima

## Disciplina

DIM0501 – Boas Práticas de Programação

Universidade Federal do Rio Grande do Norte (UFRN)

Semestre 2026.1
