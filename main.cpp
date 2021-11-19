/*
    Autores: Alexandre Debortoli de Souza, Paula Gama, Victor Nascimento, Nicolas Fajardo
    Data: Novembro - 2021
    UNIVALI - Algoritmos e Programação - Professor: Rafael Ballotin Martins
    Trabalho 3 - Jogo da Memória

    Objetivo: Programar em C++ um jogo da memória onde pares de números terão que ser descobertos.
    Ganha o jogo se o jogador tiver descoberto todos os pares dentro do número de jogadas estipuladas.
*/
#include <iostream>
#include <time.h>
#include <locale.h>
using namespace std;

#define TAM 4

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int matPrincipal [TAM][TAM] = {1, 4, 5, 2, 7, 2, 8, 7, 3, 6, 1, 4, 6, 5, 3, 8};
    int matGabarito [TAM][TAM];
    int matJogo [TAM][TAM] = {0};

    int selectMenu; // Controle dos laços de repetições

    do
    {
        system("cls");
        cout << "---------- Menu ----------\n" << "Digite o número da opção desejada\n"; //Menu
        cout << "1-Jogar / 2-Sobre / 3-Fim\n";
        cin >> selectMenu;

        if(selectMenu == 1) /*************************** JOGAR ***************************/
        {
            srand(time(NULL));

            cout << "Matriz Principal: "<< endl;

            for(int i = 0; i < TAM; i++)
            {
                for(int j = 0; j < TAM; j++)
                {
                    cout << matPrincipal[i][j] << "\t";
                }
                cout << endl;
            }

            //Operações selecionadas aleatoriamente para a matriz principal gerar a matriz gabarito
            switch(rand() % TAM + 1) //Condição é número aleatório de 1-4
            {
                case 1: //Sem Modificação
                    cout << "Sem Modificacao: " << endl;
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[i][j];
                        }
                    }
                    break;
                case 2: //Transposta
                    cout << "Transposta: " << endl;
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[j][i];
                        }
                    }
                    break;
                case 3: //Invertida por Linha
                    cout << "Invertida por Linha: " << endl;
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[(TAM - 1) - i][j];
                        }
                    }
                    break;
                case 4: //Invertida por Coluna
                    cout << "Invertida por Coluna: " << endl;
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[i][(TAM - 1) - j];
                        }
                    }
                    break;
                default: //Debug do rand()
                    cout << "Gerou um número aleatório fora do parâmetro!" << endl;
                    system("Pause");
                    break;
            }

            for(int i = 0; i < TAM; i++)
            {
                for(int j = 0; j < TAM; j++)
                {
                    cout << matGabarito[i][j] << "\t";
                }
                cout << endl;
            }
            system("pause");
        }
        else if(selectMenu == 2) /*************************** SOBRE ***************************/
        {
            system("cls");
            cout << "--- Equipe de Desenvolvimento ---\n"; // Autores
            cout << "Alexandre Debortoli de Souza\n";
            cout << "Paula Gama\n";
            cout << "Victor Nascimento\n";
            cout << "Nicolas Fajardo\n";

            cout << "\n--- Data ---\n"; // Data
            cout << "Novembro/2021\n";

            cout << "\n--- Professor e Disciplina ---\n"; // Professor e Disciplina
            cout << "Rafael Ballotin Martins";
            cout << " - Algoritmos e Programação\n";

            system("pause");
        }

    } while (selectMenu != 3); /*************************** FIM ***************************/
    
    return 0;
}