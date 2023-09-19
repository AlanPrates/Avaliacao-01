#include <iostream>
#include <vector>
#include <string>
#include <locale.h>

using namespace std;

// Struct para representar um Passageiro
struct Passageiro {
    string CPF;
    string Nome;
    string DtNascimento;
    string NumAutorizacao;
};

// Struct para representar um Roteiro
struct Roteiro {
    int Codigo;
    string Data_Horaprevista;
    string Duracaoprevista;
    string Origem;
    string Destino;
};

// Fun��o para imprimir o menu de op��es de gest�o de passageiros
void menuPassageiros(vector<Passageiro>& passageiros) {
    int opcao;
    while (true) {
        
        cout << "--------------------------------" << endl;
        cout << "|----Gest�o de Passageiros-----|" << endl;
        cout << "--------------------------------" << endl;
        cout << "|     1. Incluir               |" << endl;
        cout << "|     2. Excluir               |" << endl;
        cout << "|     3. Alterar (por CPF)     |" << endl;
        cout << "|     4. Listar                |" << endl;
        cout << "|     5. Localizar (por CPF)   |" << endl;
        cout << "|     0. Sair                  |" << endl;
        cout << "   <<<  Escolha uma op��o  >>>> " <<endl;
        cin >> opcao;

        switch (opcao) {
            case 1: { // Incluir Passageiro
                Passageiro novoPassageiro;
                cout << "CPF: ";
                cin >> novoPassageiro.CPF;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, novoPassageiro.Nome);
                cout << "Data de Nascimento: ";
                getline(cin, novoPassageiro.DtNascimento);
                cout << "N�mero de Autoriza��o: ";
                getline(cin, novoPassageiro.NumAutorizacao);
                passageiros.push_back(novoPassageiro);
                cout << "Passageiro inclu�do com sucesso!" << endl;
                break;
            }
            case 2: { // Excluir Passageiro
                string cpfExcluir;
                cout << "Informe o CPF do passageiro a ser exclu�do: ";
                cin >> cpfExcluir;
                for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
                    if (it->CPF == cpfExcluir) {
                        passageiros.erase(it);
                        cout << "Passageiro exclu�do com sucesso!" << endl;
                        break;
                    }
                }
                break;
            }
            case 3: { // Alterar Passageiro por CPF
                string cpfAlterar;
                cout << "Informe o CPF do passageiro a ser alterado: ";
                cin >> cpfAlterar;
                for (auto& passageiro : passageiros) {
                    if (passageiro.CPF == cpfAlterar) {
                        cout << "Novo Nome : ";
                        cin.ignore();
                        getline(cin, passageiro.Nome);
                        cout << "Nova Data de Nascimento : ";
                        getline(cin, passageiro.DtNascimento);
                        cout << "Novo N�mero de Autoriza��o : ";
                        getline(cin, passageiro.NumAutorizacao);
                        cout << "Passageiro alterado com sucesso!" << endl;
                        break;
                    }
                }
                break;
            }
            case 4: { // Listar Passageiros
                cout << "\nLista de Passageiros:" << endl;
                for (const auto& passageiro : passageiros) {
                    cout << "CPF: " << passageiro.CPF << endl;
                    cout << "Nome: " << passageiro.Nome << endl;
                    cout << "Data de Nascimento: " << passageiro.DtNascimento << endl;
                    cout << "N�mero de Autoriza��o: " << passageiro.NumAutorizacao << endl << endl;
                }
                break;
            }
            case 5: { // Localizar Passageiro por CPF
                string cpfLocalizar;
                cout << "Informe o CPF do passageiro a ser localizado: ";
                cin >> cpfLocalizar;
                bool encontrado = false;
                for (const auto& passageiro : passageiros) {
                    if (passageiro.CPF == cpfLocalizar) {
                        cout << "\nInforma��es do Passageiro:" << endl;
                        cout << "CPF: " << passageiro.CPF << endl;
                        cout << "Nome: " << passageiro.Nome << endl;
                        cout << "Data de Nascimento: " << passageiro.DtNascimento << endl;
                        cout << "N�mero de Autoriza��o: " << passageiro.NumAutorizacao << endl;
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Passageiro n�o encontrado." << endl;
                }
                break;
            }
            case 0: // Sair
                return;
            default:
                cout << "Op��o inv�lida! Tente novamente." << endl;
        }
    }
}

// Função para imprimir o menu de opções de gestão de roteiros
void menuRoteiros(vector<Roteiro>& roteiros) {
    int opcao;
    while (true) {
        
        cout << "--------------------------------" << endl;
        cout << "|--------Gest�o de Roteiros----|" << endl;
        cout << "--------------------------------" << endl;
        cout << "|     1. Incluir               |" << endl;
        cout << "|     2. Excluir               |" << endl;
        cout << "|     3. Alterar (por C�digo)  |" << endl;
        cout << "|     4. Listar                |" << endl;
        cout << "|     5. Localizar (por C�digo)|" << endl;
        cout << "|     0. Sair                  |" << endl;
        cout << " <<<   Escolha uma op��o   >>>  ";
        cin >> opcao;

        switch (opcao) {
            case 1: { // Incluir Roteiro
                Roteiro novoRoteiro;
                cout << "C�digo: ";
                cin >> novoRoteiro.Codigo;
                cout << "Data e Hora Prevista: ";
                cin.ignore();
                getline(cin, novoRoteiro.Data_Horaprevista);
                cout << "Dura��o Prevista: ";
                getline(cin, novoRoteiro.Duracaoprevista);
                cout << "Origem: ";
                getline(cin, novoRoteiro.Origem);
                cout << "Destino: ";
                getline(cin, novoRoteiro.Destino);
                roteiros.push_back(novoRoteiro);
                cout << "Roteiro inclu�do com sucesso!" << endl;
                break;
            }
            case 2: { // Excluir Roteiro
                int codigoExcluir;
                cout << "Informe o C�digo do roteiro a ser exclu�do: ";
                cin >> codigoExcluir;
                for (auto it = roteiros.begin(); it != roteiros.end(); ++it) {
                    if (it->Codigo == codigoExcluir) {
                        roteiros.erase(it);
                        cout << "Roteiro exclu�do com sucesso!" << endl;
                        break;
                    }
                }
                break;
            }
            case 3: { // Alterar Roteiro por C�digo
                int codigoAlterar;
                cout << "Informe o C�digo do roteiro a ser alterado: ";
                cin >> codigoAlterar;
                for (auto& roteiro : roteiros) {
                    if (roteiro.Codigo == codigoAlterar) {
                        cout << "Nova Data e Hora Prevista (ou deixe em branco para manter a mesma): ";
                        cin.ignore();
                        getline(cin, roteiro.Data_Horaprevista);
                        cout << "Nova Dura��o Prevista (ou deixe em branco para manter a mesma): ";
                        getline(cin, roteiro.Duracaoprevista);
                        cout << "Nova Origem (ou deixe em branco para manter a mesma): ";
                        getline(cin, roteiro.Origem);
                        cout << "Novo Destino (ou deixe em branco para manter o mesmo): ";
                        getline(cin, roteiro.Destino);
                        cout << "Roteiro alterado com sucesso!" << endl;
                        break;
                    }
                }
                break;
            }
            case 4: { // Listar Roteiros
                cout << "\nLista de Roteiros:" << endl;
                for (const auto& roteiro : roteiros) {
                    cout << "C�digo: " << roteiro.Codigo << endl;
                    cout << "Data e Hora Prevista: " << roteiro.Data_Horaprevista << endl;
                    cout << "Dura��oo Prevista: " << roteiro.Duracaoprevista << endl;
                    cout << "Origem: " << roteiro.Origem << endl;
                    cout << "Destino: " << roteiro.Destino << endl << endl;
                }
                break;
            }
            case 5: { // Localizar Roteiro por C�digo
                int codigoLocalizar;
                cout << "Informe o C�digo do roteiro a ser localizado: ";
                cin >> codigoLocalizar;
                bool encontrado = false;
                for (const auto& roteiro : roteiros) {
                    if (roteiro.Codigo == codigoLocalizar) {
                        cout << "\nInforma��es do Roteiro:" << endl;
                        cout << "C�digo: " << roteiro.Codigo << endl;
                        cout << "Data e Hora Prevista: " << roteiro.Data_Horaprevista << endl;
                        cout << "Dura��o Prevista: " << roteiro.Duracaoprevista << endl;
                        cout << "Origem: " << roteiro.Origem << endl;
                        cout << "Destino: " << roteiro.Destino << endl;
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Roteiro n�o encontrado." << endl;
                }
                break;
            }
            case 0: // Sair
                return;
            default:
                cout << "Op��o inv�lida! Tente novamente." << endl;
        }
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    vector<Passageiro> passageiros;
    vector<Roteiro> roteiros;

    int menuPrincipal;
    while (true) {
        cout << "--------------------------------" << endl;
        cout << "|--------Menu Principal--------|" << endl;
        cout << "--------------------------------" << endl;
        cout << "    1. Gest�o de Passageiros" << endl;
        cout << "    2. Gest�o de Roteiros" << endl;
        cout << "    0. Sair" << endl;
        cout << "    Escolha uma op��o: ";
        cin >> menuPrincipal;

        switch (menuPrincipal) {
            case 1: // Gest�o de Passageiros
                menuPassageiros(passageiros);
                break;
            case 2: // Gest�o de Roteiros
                menuRoteiros(roteiros);
                break;
            case 0: // Sair do programa
                cout << "Programa Encerrado. Obrigado!" << endl;
                return 0;
            default:
                cout << "Op��oo inv�lida! Tente novamente." << endl;
        }
    }

    return 0;
}
