// ATIVIDADE 1
#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct passageiro
{
    int cpf;
    string nome;
    string dtNascimento;
    int numAutorizacao;
};

struct roteiro
{
    int codigo;
    int data_horaPrevista;
    int duracao_prevista;
    string origem;
    string destino;
};

struct passageiro passageiro[5];

void gestaoDePassageiro()
{
    int cpfIns;
    int opcao;
    while (true)
    {
        int contador = 0;
        cout << "Selecione uma das Opções" << endl;

        cout << "1 incluir" << endl;
        cout << "2 Excluir" << endl;
        cout << "3 Alterar(Apenas Por CPF)" << endl;
        cout << "4 Listar" << endl;
        cout << "5 Localizar Por CPF" << endl;
        cout << "0 Sair" << endl;

        cin >> opcao;
        switch (opcao)
        {
        case 1:

            cout << "Digite o CPF: " << endl;
            cin >> passageiro[contador].cpf;
            cout << "Nome: " << endl;
            cin >> passageiro[contador].nome;
            cout << "Data de Nascimento: " << endl;
            cin >> passageiro[contador].dtNascimento;
            cout << "Digite o número de autorização: " << endl;
            cin >> passageiro[contador].numAutorizacao;

            break;

            case 2:

             cout << "Digite o CPF: " << endl;
            
             cin >> cpfIns;

for (int i = 0; i < 5; i++)
{
    if (cpfIns == passageiro[i].cpf)
    {
        passageiro[i].cpf = 0;
        passageiro[i].nome = "0";
        passageiro[i].dtNascimento = "0";
        passageiro[i].numAutorizacao = 0;
    }
    
}





            break;

        case 0:

            break;
        }

        if (opcao == 0)
        {

            break;
        }
    }
}

void gestaoDeRoteiro()
{
}

int main()
{

    gestaoDePassageiro();

    cout << "MAIN: " << endl;

    gestaoDePassageiro();

    return (0);
}