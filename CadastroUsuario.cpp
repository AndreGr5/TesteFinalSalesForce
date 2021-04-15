#include <bits/stdc++.h>

using namespace std;

typedef struct User{
    string nome;
    string sobrenome;
    string cpf;
    char sexo;
    int idade;

}user;

vector<user> Usuarios;

bool cpfDuplicado(string cpf){
    for(int i=0;i<Usuarios.size();i++){
        if(Usuarios[i].cpf==cpf){
            return true;
        }
    }
    return false;
}

bool valida(user Usuario){
    if(Usuario.sexo!='M' && Usuario.sexo!='F'){
        cout << "Erro: Sexo invalido! Use apenas M ou F";
        return(false);
    }
    if(Usuario.cpf.length()!=11){
        cout << "Erro: CPF deve conter 11 caracteres";
        return (false);
    }
    if(cpfDuplicado(Usuario.cpf)){
        cout << "Erro: CPF ja cadastrado";
        return (false);
    }
    return true;
}

bool cadastra(user Usuario){
    if(valida(Usuario)){
        Usuarios.push_back(Usuario);
        cout <<"\n\nUsuario cadastrado com sucesso!\n\n";
        return true;
    }
    else{
        cout << "\n\nTente novamente!\n\n";
        return false;
    }
}

int anoNasc(user Usuario, int aniver){
    if(aniver==1){
        return 2021-Usuario.idade;
    }
    else{
        return 2020-Usuario.idade;
    }

}

void printa(user Usuario,int aniver){
    cout <<"Nome: "<< Usuario.nome<<" "<<Usuario.sobrenome;
    cout <<"\nIdade: "<< Usuario.idade;
    cout << "\nAno de nascimento: " <<anoNasc(Usuario,aniver);
    cout <<"\nSexo: "<< Usuario.sexo;
    cout <<"\nCPF: "<<Usuario.cpf[0]<<Usuario.cpf[1]<<Usuario.cpf[2]<<".";
    cout <<Usuario.cpf[3]<<Usuario.cpf[4]<<Usuario.cpf[5]<<".";
    cout <<Usuario.cpf[6]<<Usuario.cpf[7]<<Usuario.cpf[8]<<"-";
    cout <<Usuario.cpf[9]<<Usuario.cpf[10];
}

void menu(user Usuario,int aniver){
    int option = 1;
    do{
    cout<< "Usuarios cadastrados: "<<Usuarios.size();
    cout<< "\nCadastro de novo usuario\n\n";
    cout<<"Digite o primeiro nome: ";
    cin >> Usuario.nome;
    cout<<"\nDigite o sobrenome: ";
    cin >> Usuario.sobrenome;
    cout<<"\nDigite os 11 digitos do cpf: ";
    cin >> Usuario.cpf;
    cout<<"\nDigite o sexo: (M para masculino ou F para feminino): ";
    cin >> Usuario.sexo;
    cout<<"\nDigite a idade: ";
    cin >> Usuario.idade;
    cout<<"\nJa fez aniversario esse ano? (1:sim 0: nao): ";
    cin >> aniver;

    if(cadastra(Usuario)){
        printa(Usuario,aniver);
    }

    cout << "\n\nCadastrar novamente? (1 para sim ou 0 para nao): ";
    cin >> option;
    system("cls");
    }while(option!=0);
}
int main(){
    user Usuario;
    int aniver;
    menu(Usuario,aniver);
    system("pause");
}
