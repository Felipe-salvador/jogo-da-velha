#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void limpaTela(){
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[3][3]){

    //Coloca o símbolo de '-' em cada posição do tabuleiro
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
           tabuleiro[i][j] = '-';
        }
    }
}

void exibeTabuleiro(char tabuleiro[3][3]){

    //Auxiliar
    int i, j;
    cout <<"\n";
    //Exibindo tabuleiro
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
           cout << tabuleiro[i][j] << " ";
        }
        cout << "\n";
    }
}

void jogo(){

    ///Variáveis Gerais
    char tabuleiro[3][3];
    int linha, coluna;
    int linhaJogada, colunaJogada;
    int estadoDeJogo = 1;
    int turnoDoJogador = 1;
    int rodada = 0;

    //Coloca os '-' no tabuleiro
    iniciaTabuleiro(tabuleiro);

    while(rodada <= 9 && estadoDeJogo == 1){

        limpaTela();

        //Exibe o tabuleiro na tela
        exibeTabuleiro(tabuleiro);

        cout << "\nRodada:" << rodada << "\n";

        //Lea posição desejada
        cout << "Jogador, digite uma linha: ";
        cin >> linhaJogada;
        cout << "Jogador, digite uma coluna: ";
        cin >> colunaJogada;

        //Verifica de quem é a vez para posicionar o marcador
        if(turnoDoJogador == 1){
            tabuleiro[linhaJogada][colunaJogada] = 'x';
            turnoDoJogador = 2;
        }else{
            tabuleiro[linhaJogada][colunaJogada] = 'o';
            turnoDoJogador = 1;
        }

        //Cofere se o jogo acabou
        //Cofere linha
        for(linha = 0; linha < 3; linha++){
            if(tabuleiro[linha][0] == 'x' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                estadoDeJogo = 0;
                cout << "O jogador X venceu!";
            }else if(tabuleiro[linha][0] == 'o' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                 estadoDeJogo = 0;
                 cout << "O jogador o venceu!";
            }
        }
        //Confere colunas
        for(coluna = 0; coluna < 3; coluna++){
            if(tabuleiro[0][coluna] == 'x' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                estadoDeJogo = 0;
                cout << "O jogador X venceu!";
            }else if(tabuleiro[0][coluna] == 'o' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                 estadoDeJogo = 0;
                 cout << "O jogador O venceu!";
            }
        }


        //Almenta uma rodada
        rodada++;

    }

    //Exibe o tabuleiro na tela
    exibeTabuleiro(tabuleiro);
    cout << "Fim de jogo!";

}

void menuInicial(){

    int opcao = 0;

    while(opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem vindo ao jogo!";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                cout << "Jogo iniciado!\n";
                jogo();
                break;
            case 2:
                cout << "Informacoes do jogo!";
                break;
            case 3:
                cout <<"Ate mais!";
                break;

        }

    }

}

int main(){

    menuInicial();

    return 0;
}

