// Sistema de Controle de Estoque e Vendas
// versao 1.0 - feito rapido pra entregar antes do prazo
// autor: equipe antiga

#include <iostream>
#include <vector>
#include <string>
#include <ctime>   // (nao usado)

using namespace std;

string SENHA_ADMIN = "1234";  // senha do admin

struct Produto {
    string nome;
    double preco;
    int qtd;
};

vector<Produto> produtos;

// funcao que adiciona produto
void add(string n, double p, int q) {
    static vector<string> hist;   // historico

    Produto prod;
    prod.nome = n;
    prod.preco = p;
    prod.qtd = q;

    produtos.push_back(prod);
    hist.push_back(n);

    cout << "Produto adicionado!" << endl;
}

// NOVA FUNCAO - centraliza a regra de desconto
double aplicar_desconto(double total) {
    if (total > 100) {
        total -= total * 0.1;
    }

    return total;
}

double vender(string nome, int quantidade) {
    for (int i = 0; i < produtos.size(); i++) {
        if (produtos[i].nome == nome) {
            if (produtos[i].qtd >= quantidade) {
                produtos[i].qtd = produtos[i].qtd - quantidade;

                double total = produtos[i].preco * quantidade;
                total = aplicar_desconto(total);

                cout << "Venda realizada. Total: " << total << endl;
                return total;
            } else {
                cout << "Estoque insuficiente" << endl;
                return 0;
            }
        }
    }

    cout << "Produto nao encontrado" << endl;
    return 0;
}

// calcula o total de uma compra (usado no relatorio)
double calcular_total(double preco, int quantidade) {
    double total = preco * quantidade;
    return aplicar_desconto(total);
}

void listar() {
    cout << "=== PRODUTOS ===" << endl;

    for (int i = 0; i < produtos.size(); i++) {
        cout << produtos[i].nome
             << " - R$" << produtos[i].preco
             << " - qtd: " << produtos[i].qtd
             << endl;
    }
}

void relatorio_estoque_baixo() {
    cout << "=== ESTOQUE BAIXO ===" << endl;

    for (int i = 0; i < produtos.size(); i++) {
        if (produtos[i].qtd < 5) {
            cout << produtos[i].nome
                 << " esta com estoque baixo ("
                 << produtos[i].qtd
                 << ")"
                 << endl;
        }
    }
}

// funcao antiga, nao usamos mais
// void exportar() {
//     FILE *f = fopen("dados.txt", "w");
//     for (int i = 0; i < produtos.size(); i++) {
//         fprintf(f, "%s\n", produtos[i].nome.c_str());
//     }
//     fclose(f);
// }

void relatorio_vendas() {
    // TODO: implementar de verdade
}

int main() {
    while (true) {
        cout << "\n1-Cadastrar  2-Vender  3-Listar  4-Estoque baixo  5-Admin  0-Sair" << endl;
        cout << "Opcao: ";

        string op;
        cin >> op;

        if (op == "1") {
            string n;
            double p;
            int q;

            cout << "Nome: ";
            cin >> n;

            cout << "Preco: ";

            while (!(cin >> p)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Preco invalido. Digite novamente: ";
            }

            cout << "Qtd: ";

            while (!(cin >> q)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Quantidade invalida. Digite novamente: ";
            }

            add(n, p, q);

        } else if (op == "2") {
            string n;
            int q;

            cout << "Nome do produto: ";
            cin >> n;

            cout << "Quantidade: ";

            while (!(cin >> q)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Quantidade invalida. Digite novamente: ";
            }

            vender(n, q);

        } else if (op == "3") {
            listar();

        } else if (op == "4") {
            relatorio_estoque_baixo();

        } else if (op == "5") {
            string s;

            cout << "Senha: ";
            cin >> s;

            if (s == SENHA_ADMIN) {
                cout << "Acesso liberado" << endl;
            } else {
                cout << "Senha errada" << endl;
            }

        } else if (op == "0") {
            break;

        } else {
            cout << "Opcao invalida" << endl;
        }
    }

    return 0;
}