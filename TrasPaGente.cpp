#include <iostream>
#include <vector>
using namespace std;

// Definindo a estrutura Passageiro
struct Passageiro {
    string CPF;
    string Nome;
    string DtNascimento;
    string NumAutorizacao;
};

// Definindo a estrutura Roteiro
struct Roteiro {
    int Codigo;
    string Data_HoraPrevista;
    string Origem;
    string Destino;
};

// Funções de Gestão de Passageiros

void IncluirPassageiro(vector<Passageiro>& passageiros) {
    Passageiro novo;
    cout << "CPF: ";
    cin >> novo.CPF;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, novo.Nome);
    cout << "Data de Nascimento: ";
    cin >> novo.DtNascimento;
    cout << "Numero de Autorizacao: ";
    cin >> novo.NumAutorizacao;
    passageiros.push_back(novo);
}

void ExcluirPassageiro(vector<Passageiro>& passageiros) {
    string cpf;
    cout << "Digite o CPF do passageiro a ser excluido: ";
    cin >> cpf;
    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (it->CPF == cpf) {
            passageiros.erase(it);
            cout << "Passageiro excluido com sucesso!" << endl;
            return;
        }
    }
    cout << "Passageiro nao encontrado." << endl;
}

void AlterarPassageiro(vector<Passageiro>& passageiros) {
    string cpf;
    cout << "Digite o CPF do passageiro a ser alterado: ";
    cin >> cpf;
    for (auto& passageiro : passageiros) {
        if (passageiro.CPF == cpf) {
            cout << "Novo Nome (ou pressione Enter para manter o mesmo): ";
            cin.ignore();
            getline(cin, passageiro.Nome);
            cout << "Nova Data de Nascimento (ou pressione Enter para manter a mesma): ";
            getline(cin, passageiro.DtNascimento);
            cout << "Novo Numero de Autorizacao (ou pressione Enter para manter o mesmo): ";
            getline(cin, passageiro.NumAutorizacao);
            cout << "Passageiro alterado com sucesso!" << endl;
            return;
        }
    }
    cout << "Passageiro nao encontrado." << endl;
}

void ListarPassageiros(const vector<Passageiro>& passageiros) {
    for (const auto& passageiro : passageiros) {
        cout << "CPF: " << passageiro.CPF << ", Nome: " << passageiro.Nome << ", Data de Nascimento: " << passageiro.DtNascimento
             << ", Numero de Autorizacao: " << passageiro.NumAutorizacao << endl;
    }
}

void LocalizarPassageiro(const vector<Passageiro>& passageiros) {
    string cpf;
    cout << "Digite o CPF do passageiro a ser localizado: ";
    cin >> cpf;
    for (const auto& passageiro : passageiros) {
        if (passageiro.CPF == cpf) {
            cout << "CPF: " << passageiro.CPF << ", Nome: " << passageiro.Nome << ", Data de Nascimento: " << passageiro.DtNascimento
                 << ", Numero de Autorizacao: " << passageiro.NumAutorizacao << endl;
            return;
        }
    }
    cout << "Passageiro nao encontrado." << endl;
}

// Funções de Gestão de Roteiros

void IncluirRoteiro(vector<Roteiro>& roteiros) {
    Roteiro novo;
    cout << "Codigo: ";
    cin >> novo.Codigo;
    cout << "Data e Hora Prevista (DD/MM/YYYY HH:MM): ";
    cin.ignore();
    getline(cin, novo.Data_HoraPrevista);
    cout << "Origem: ";
    getline(cin, novo.Origem);
    cout << "Destino: ";
    getline(cin, novo.Destino);
    roteiros.push_back(novo);
}

void ExcluirRoteiro(vector<Roteiro>& roteiros) {
    int codigo;
    cout << "Digite o Codigo do roteiro a ser excluido: ";
    cin >> codigo;
    for (auto it = roteiros.begin(); it != roteiros.end(); ++it) {
        if (it->Codigo == codigo) {
            roteiros.erase(it);
            cout << "Roteiro excluido com sucesso!" << endl;
            return;
        }
    }
    cout << "Roteiro nao encontrado." << endl;
}

void AlterarRoteiro(vector<Roteiro>& roteiros) {
    int codigo;
    cout << "Digite o Codigo do roteiro a ser alterado: ";
    cin >> codigo;
    for (auto& roteiro : roteiros) {
        if (roteiro.Codigo == codigo) {
            cout << "Nova Data e Hora Prevista (ou pressione Enter para manter a mesma): ";
            cin.ignore();
            getline(cin, roteiro.Data_HoraPrevista);
            cout << "Nova Origem (ou pressione Enter para manter a mesma): ";
            getline(cin, roteiro.Origem);
            cout << "Novo Destino (ou pressione Enter para manter o mesmo): ";
            getline(cin, roteiro.Destino);
            cout << "Roteiro alterado com sucesso!" << endl;
            return;
        }
    }
    cout << "Roteiro nao encontrado." << endl;
}

void ListarRoteiros(const vector<Roteiro>& roteiros) {
    for (const auto& roteiro : roteiros) {
        cout << "Codigo: " << roteiro.Codigo << ", Data e Hora Prevista: " << roteiro.Data_HoraPrevista << ", Origem: " << roteiro.Origem
             << ", Destino: " << roteiro.Destino << endl;
    }
}

void LocalizarRoteiro(const vector<Roteiro>& roteiros) {
    int codigo;
    cout << "Digite o Codigo do roteiro a ser localizado: ";
    cin >> codigo;
    for (const auto& roteiro : roteiros) {
        if (roteiro.Codigo == codigo) {
            cout << "Codigo: " << roteiro.Codigo << ", Data e Hora Prevista: " << roteiro.Data_HoraPrevista << ", Origem: " << roteiro.Origem
                 << ", Destino: " << roteiro.Destino << endl;
            return;
        }
    }
    cout << "Roteiro nao encontrado." << endl;
}

int main() {
    vector<Passageiro> passageiros;
    vector<Roteiro> roteiros;
    int opcao;

    do {
        cout << "\nMenu de Opcoes:" << endl;
        cout << "1. Gestao de Passageiros" << endl;
        cout << "2. Gestao de Roteiros" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                int opcaoPassageiros;
                do {
                    cout << "\nMenu de Opcoes para Passageiros:" << endl;
                    cout << "1. Incluir" << endl;
                    cout << "2. Excluir" << endl;
                    cout << "3. Alterar" << endl;
                    cout << "4. Listar" << endl;
                    cout << "5. Localizar" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> opcaoPassageiros;

                    switch (opcaoPassageiros) {
                        case 1:
                            IncluirPassageiro(passageiros);
                            break;
                        case 2:
                            ExcluirPassageiro(passageiros);
                            break;
                        case 3:
                            AlterarPassageiro(passageiros);
                            break;
                        case 4:
                            ListarPassageiros(passageiros);
                            break;
                        case 5:
                            LocalizarPassageiro(passageiros);
                            break;
                        case 0:
                            cout << "Voltando ao menu principal..." << endl;
                            break;
                        default:
                            cout << "Opcao invalida. Tente novamente." << endl;
                            break;
                    }

                } while (opcaoPassageiros != 0);
                break;

            case 2:
                int opcaoRoteiros;
                do {
                    cout << "\nMenu de Opcoes para Roteiros:" << endl;
                    cout << "1. Incluir" << endl;
                    cout << "2. Excluir" << endl;
                    cout << "3. Alterar" << endl;
                    cout << "4. Listar" << endl;
                    cout << "5. Localizar" << endl;
                    cout << "0. Voltar" << endl;
                    cout << "Escolha uma opcao: ";
                    cin >> opcaoRoteiros;

                    switch (opcaoRoteiros) {
                        case 1:
                            IncluirRoteiro(roteiros);
                            break;
                        case 2:
                            ExcluirRoteiro(roteiros);
                            break;
                        case 3:
                            AlterarRoteiro(roteiros);
                            break;
                        case 4:
                            ListarRoteiros(roteiros);
                            break;
                        case 5:
                            LocalizarRoteiro(roteiros);
                            break;
                        case 0:
                            cout << "Voltando ao menu principal..." << endl;
                            break;
                        default:
                            cout << "Opcao invalida. Tente novamente." << endl;
                            break;
                    }

                } while (opcaoRoteiros != 0);
                break;

            case 0:
                cout << "Saindo..." << endl;
                break;

            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}