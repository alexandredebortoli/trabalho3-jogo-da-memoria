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
//#include <Windows.h>
using namespace std;

#define TAM 4

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //SetConsoleOutputCP(CP_UTF8);

    int matPrincipal [TAM][TAM] = {1, 4, 5, 2, 7, 2, 8, 7, 3, 6, 1, 4, 6, 5, 3, 8};
    int matGabarito [TAM][TAM];
    int matJogo [TAM][TAM];

    int selectMenu, jogadas, paresEncontrados; // Controle dos laços de repetições
    int peca1L, peca2L, peca1C, peca2C;
    bool vazio = false;

    do
    {
        system("cls");
        cout << "---------- Menu ----------\n" << "Digite o número da opção desejada\n"; //Menu
        cout << "1-Jogar / 2-Sobre / 3-Fim\n";
        cin >> selectMenu;

        if(selectMenu == 1) /*************************** JOGAR ***************************/
        {
            system("cls");
            srand(time(NULL));

            //Operações selecionadas aleatoriamente para a matriz principal gerar a matriz gabarito
            switch(rand() % TAM + 1) //Condição é número aleatório de 1-4
            {
                case 1: //Sem Modificação
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[i][j];
                        }
                    }
                    break;
                case 2: //Transposta
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[j][i];
                        }
                    }
                    break;
                case 3: //Invertida por Linha
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[(TAM - 1) - i][j];
                        }
                    }
                    break;
                case 4: //Invertida por Coluna
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

            //Zerando Matriz Jogo
            for (int i = 0; i < TAM; i++)
                {
                    for(int j = 0; j < TAM; j++)
                    {
                        matJogo [i][j] = 0;
                    }
                }

            jogadas = 24;
            paresEncontrados = 0;

            //INTERAÇÃO DO JOGO
            do
            {
                cout << "Pares Encontrados: " << paresEncontrados << " / 8\t" << "Jogadas: " << jogadas << " / 24\n" << endl;
                for (int i = 0; i < TAM; i++)
                {
                    for(int j = 0; j < TAM; j++)
                    {
                        cout << matJogo[i][j] << "\t";
                    }
                    cout << endl;
                }

                //VALOR PARA PEÇA 1
                do
                {
                    cout << "\nInforme a posição (linha e coluna) da primeira peça a ser virada: " << endl;
                    cin >> peca1L >> peca1C;
                    peca1L -= 1;
                    peca1C -= 1;

                    if(matJogo[peca1L][peca1C] == 0)
                    {
                        matJogo[peca1L][peca1C] = matGabarito[peca1L][peca1C];
                        vazio = true;
                    }
                    else
                    {
                        cout << "\nPosição informada inválida. Tente novamente...\n" << endl;
                        vazio = false;
                    }
                } while (vazio != true);

                system("cls");

                cout << "Pares Encontrados: " << paresEncontrados << " / 8\t" << "Jogadas: " << jogadas << " / 24\n" << endl;
                for (int i = 0; i < TAM; i++)
                {
                    for(int j = 0; j < TAM; j++)
                    {
                        cout << matJogo[i][j] << "\t";
                    }
                    cout << endl;
                }

                //VALOR PARA PEÇA 2
                do
                {
                    cout << "\nInforme a posição (linha e coluna) da segunda peça a ser virada: " << endl;
                    cin >> peca2L >> peca2C;
                    peca2L -= 1;
                    peca2C -= 1;

                    if(matJogo[peca2L][peca2C] == 0)
                    {
                        matJogo[peca2L][peca2C] = matGabarito[peca2L][peca2C];
                        vazio = true;
                    }
                    else
                    {
                        cout << "\nPosição informada inválida. Tente novamente...\n" << endl;
                        vazio = false;
                    }
                } while (vazio != true);
                
                system("cls");

                cout << "Pares Encontrados: " << paresEncontrados << " / 8\t" << "Jogadas: " << jogadas << " / 24\n" << endl;
                for (int i = 0; i < TAM; i++)
                {
                    for(int j = 0; j < TAM; j++)
                    {
                        cout << matJogo[i][j] << "\t";
                    }
                    cout << endl;
                }

                if (matJogo[peca1L][peca1C] == matJogo[peca2L][peca2C])
                {
                    cout << "\nJOGADA OK\n" << endl;
                    jogadas--;
                    paresEncontrados++;
                }
                else 
                {
                    cout << "\nJOGADA NOK\n" << endl;
                    matJogo[peca1L][peca1C] = 0;
                    matJogo[peca2L][peca2C] = 0;
                    jogadas--;
                }

                system("pause");
                system("cls");
            } while (paresEncontrados < 8 && jogadas > 0);

            if (paresEncontrados == 8)
                cout << "VITÓRIA!\n" << endl;
            else
                cout << "DERROTA!\n" << endl;

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