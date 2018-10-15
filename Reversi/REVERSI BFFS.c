//Grupo: Felipe Stéffano, Breno Medeiros, Flávio Saldanha, Samara Cíntia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int PosicaoI(char *i);

int PosicaoJ(char *j);

void save(char *p, int *pontuacao);

//void read();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char Linha ,tabuleiro[8][8], p1[15], p2[15], p[15], Pedra1 = '\0', Pedra2 = '\0', posicao[3];
    int i, j = 0, players, nivel=0, O, Vez, Possib, Pi = 0, Pj = 0, PossibCont2, PassaVez = 0, FimDeJogo=0, PontoX, PontoO, Nivel2=1, pontuacao, Mjogou;
    float qualidade[8][8], Q = 0;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if( (i==3 && j==3) || (i==4 && j==4))
            {
                tabuleiro[i][j] = 'O';
            }
            else if((i==3 && j==4) || (i==4 && j==3))
            {
                tabuleiro[i][j] = 'X';
            }
            else
            {
                tabuleiro[i][j] = '-';
            }
        }
    }

    /* INICIO: Da Introducao */
    printf("                      _________\n                    //         ||\n                    || REVERSI ||\n                    ||_________//\n\n  Bem vindo ao Jogo Reversi!\n\n");

    printf("  Quantos jogadores? 1 Jogador X 1 Computador  (1)\n                     2 Jogadores Individuais   (2)\n  Digite a quantidade de Jogadores: ");
    for(players=3; ((players<1) || (players>2)); )
    {
        scanf("%d",&players);
        if( (players<1) || (players>2) )
        {
            printf("  Quantidade invalida, tente novamente: ");
        }
    }
    /* FIM: Da Introducao */

    /* INICIO: Da escolha do Nome dos Jogadores */
    if(players==1)
    {
        printf("  Qual o nome do Jogador 1: ");
        scanf("%s", p1);
        fflush(stdin);
        printf("%s\n",p1);
        p2[0]='M'; p2[1]='a'; p2[2]='q'; p2[3]='u'; p2[4]='i'; p2[5]='n'; p2[6]='a';p2[7]=0;
        qualidade[0][0]=qualidade[7][0]=qualidade[0][7]=qualidade[7][7]=4;
        qualidade[1][1]=qualidade[6][1]=qualidade[1][6]=qualidade[6][6]=1;
        qualidade[2][2]=qualidade[5][2]=qualidade[2][5]=qualidade[5][5]=3;
        qualidade[3][3]=qualidade[4][3]=qualidade[3][4]=qualidade[4][4]=2;
        qualidade[1][0]=qualidade[0][1]=qualidade[6][0]=qualidade[7][1]=qualidade[0][6]=qualidade[1][7]=qualidade[6][7]=qualidade[7][6]=1.1;
        qualidade[2][1]=qualidade[1][2]=qualidade[5][1]=qualidade[6][2]=qualidade[1][5]=qualidade[2][6]=qualidade[6][5]=qualidade[5][6]=3.1;
        qualidade[2][0]=qualidade[0][2]=qualidade[5][0]=qualidade[7][2]=qualidade[0][5]=qualidade[2][7]=qualidade[7][5]=qualidade[5][7]=3.2;
        qualidade[3][2]=qualidade[2][3]=qualidade[4][2]=qualidade[5][3]=qualidade[2][4]=qualidade[3][5]=qualidade[5][4]=qualidade[4][5]=2.1;
        qualidade[3][1]=qualidade[1][3]=qualidade[4][1]=qualidade[6][3]=qualidade[1][4]=qualidade[3][6]=qualidade[6][4]=qualidade[4][6]=2.2;
        qualidade[3][0]=qualidade[0][3]=qualidade[4][0]=qualidade[7][3]=qualidade[0][4]=qualidade[3][7]=qualidade[7][4]=qualidade[4][7]=2.3;
    }
    else if(players==2)
    {
        printf("  Qual o nome do Jogador 1(Joga com X): ");
        scanf("%s", p1);
        fflush(stdin);
        printf("%s\n",p1);
        printf("  Qual o nome do Jogador 2(Joga com O): ");
        scanf("%s", p2);
        fflush(stdin);
        printf("%s\n",p2);
    }
    /* FIM: Da escolha do Nome dos Jogadores */

    /* INICIO: Da escolha do Nível */
    if(players==1)
    {
        printf(" Nivel de dificuldade:  Facil   (1)\n                        Medio   (2)\n                        Dificil (3)\n Escolha a sua dificuldade(1,2 ou 3): ");
        for( ; ((nivel<1) || (nivel>3)); )
        {
            scanf("%d",&nivel);
            if( (nivel<1) || (nivel>3) )
            {
                printf(" Nivel invalido, tente novamente: ");
            }
        }
        printf("\n");
    }
    /* FIM: Da escolha do Nível */




    Vez = 2;
    system("cls");
    do                                   // INICIO DA PARTIDA
    {
    /* INICIO: Da escolha da vez */
        if(Vez == 2)
        {
            Vez = 1;
            Pedra1 = 'X';
            Pedra2 = 'O';

        }
        else if(Vez == 1)
        {
            Vez = 2;
            Pedra1 = 'O';
            Pedra2 = 'X';
        }
    /* FIM: Da escolha da vez */

    /* INICIO: Contador de Possibilidades de Jogada */
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(tabuleiro[i][j] == Pedra1)
                {
                    for(Possib=0; Possib<8; Possib++)
                    {
                        switch(Possib)
                        {
                            case 0:
                            {
                                PossibCont2 = 0;
                                Pi = i;
                                Pj = j;
                                for(--Pi ; (Pi >=0); --Pi )
                                {
                                    if(tabuleiro[Pi][Pj] == Pedra2)
                                    {
                                        PossibCont2++;
                                    }
                                    else if(tabuleiro[Pi][Pj] == Pedra1)
                                    {
                                        break;
                                    }
                                    else if(PossibCont2>0)
                                    {
                                        tabuleiro[Pi][Pj] = '*';
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                                break;
                            case 1:
                            {
                                PossibCont2 = 0;
                                Pi = i;
                                Pj = j;
                                for( (--Pi, ++Pj) ; ( Pi>=0 && Pj<=7) ; (--Pi, ++Pj)) // Se sobrar tempo, transforar em Do While
                                {
                                    if(tabuleiro[Pi][Pj] == Pedra2)
                                    {
                                        PossibCont2++;
                                    }
                                    else if(tabuleiro[Pi][Pj] == Pedra1)
                                    {
                                        break;
                                    }
                                    else if(PossibCont2>0)
                                    {
                                        tabuleiro[Pi][Pj] = '*';
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                                break;
                            case 2:
                            {
                                PossibCont2 = 0;
                                Pi = i;
                                Pj = j;
                                for(++Pj ; Pj<=7; ++Pj)
                                {
                                    if(tabuleiro[Pi][Pj] == Pedra2)
                                    {
                                        PossibCont2++;
                                    }
                                    else if(tabuleiro[Pi][Pj] == Pedra1)
                                    {
                                        break;
                                    }
                                    else if(PossibCont2>0)
                                    {
                                        tabuleiro[Pi][Pj] = '*';
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                                break;
                            case 3:
                            {
                                PossibCont2 = 0;
                                Pi = i;
                                Pj = j;
                                for( (++Pi, ++Pj) ; ( Pi<=7 && Pj<=7) ; (++Pi, ++Pj))
                                {
                                    if(tabuleiro[Pi][Pj] == Pedra2)
                                    {
                                        PossibCont2++;
                                    }
                                    else if(tabuleiro[Pi][Pj] == Pedra1)
                                    {
                                        break;
                                    }
                                    else if(PossibCont2>0)
                                    {
                                        tabuleiro[Pi][Pj] = '*';
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                                break;
                            case 4:
                            {
                                PossibCont2 = 0;
                                Pi = i;
                                Pj = j;
                                for(++Pi; Pi<=7; ++Pi)
                                {
                                    if(tabuleiro[Pi][Pj] == Pedra2)
                                    {
                                        PossibCont2++;
                                    }
                                    else if(tabuleiro[Pi][Pj] == Pedra1)
                                    {
                                        break;
                                    }
                                    else if(PossibCont2>0)
                                    {
                                        tabuleiro[Pi][Pj] = '*';
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                                break;
                            case 5:
                            {
                                PossibCont2 = 0;
                                Pi = i;
                                Pj = j;
                                for( (++Pi, --Pj) ; ( Pi<=7 && Pj>=0) ; (++Pi, --Pj))
                                {
                                    if(tabuleiro[Pi][Pj] == Pedra2)
                                    {
                                        PossibCont2++;
                                    }
                                    else if(tabuleiro[Pi][Pj] == Pedra1)
                                    {
                                        break;
                                    }
                                    else if(PossibCont2>0)
                                    {
                                        tabuleiro[Pi][Pj] = '*';
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                                break;
                            case 6:
                            {
                                PossibCont2 = 0;
                                Pi = i;
                                Pj = j;
                                for(--Pj ;Pj>=0 ; --Pj)
                                {
                                    if(tabuleiro[Pi][Pj] == Pedra2)
                                    {
                                        PossibCont2++;
                                    }
                                    else if(tabuleiro[Pi][Pj] == Pedra1)
                                    {
                                        break;
                                    }
                                    else if(PossibCont2>0)
                                    {
                                        tabuleiro[Pi][Pj] = '*';
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                                break;
                            case 7:
                            {
                                PossibCont2 = 0;
                                Pi = i;
                                Pj = j;
                                for( (--Pi, --Pj) ; ( Pi>=0 && Pj>=0) ; (--Pi, --Pj))
                                {
                                    if(tabuleiro[Pi][Pj] == Pedra2)
                                    {
                                        PossibCont2++;
                                    }
                                    else if(tabuleiro[Pi][Pj] == Pedra1)
                                    {
                                        break;
                                    }
                                    else if(PossibCont2>0)
                                    {
                                        tabuleiro[Pi][Pj] = '*';
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    /* FIM: Contador de Possibilidades de Jogada */

    /* INICIO: Da Checagem do Fim do Jogo */
        Possib = 0;
        PontoX = 0;
        PontoO = 0;
        O      = 0;
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(tabuleiro[i][j] == '*')
                {
                    Possib++;
                }
                else if(tabuleiro[i][j] == 'X')
                {
                    PontoX++;
                }
                else if(tabuleiro[i][j] == 'O')
                {
                    PontoO++;
                }
                else if(tabuleiro[i][j]== '-')
                {
                    ++O;
                };
            }
        }
        if(Possib==0)
        {
            if(O>0)
            {
                if((PontoX==0) || (PontoO==0))
                {
                    FimDeJogo=1;
                    break;
                }
                else
                {
                    if((Vez==2) && (PassaVez==0))
                    {
                        printf("\nNao existe jogadas possiveis para %s.\nEntao a jogada sera passada para %s.\n", p2, p1);
                        PassaVez=1;
                        continue;
                    }
                    else if((Vez==1) && (PassaVez==0))
                    {
                        printf("\nNao existe jogadas possiveis para %s.\nEntao a jogada sera passada para %s.\n", p1, p2);
                        PassaVez=1;
                        continue;
                    }
                    else if(PassaVez==1)
                    {
                        FimDeJogo=2;
                        break;
                    }
                }
            }
            else
            {
                if(PontoX!=PontoO)
                {
                    FimDeJogo=3;
                    break;
                }
                else if(PontoX==PontoO)
                {
                    FimDeJogo=4;
                    break;
                }
            }
        }
        PassaVez=0;
    /* FIM: Da Checagem do Fim do Jogo */

    /* INICIO: Da declaracao da Vez */
        if(Vez == 1)
        {
            printf("Vez de %s:\n", p1);
        }
        else if(Vez == 2)
        {
            printf("Vez de %s:\n", p2);
        }
    /* FIM: Da declaracao da Vez */

    /* INICIO: Da exibição do Tabuleiro */
        Linha='A';
        printf(" ____________________________\n|              Coluna        |\n|          |1|2|3|4|5|6|7|8| |\n");
        for(i=0; i<8; i++)
        {
            printf("| Linha |%c|", Linha++);
            for(j=0; j<8; j++)
            {
                printf(" %c",tabuleiro[i][j]);
            }
            printf("  |\n");
        }
        printf("|____________________________|\n");
    /* FIM: Da exibição do Tabuleiro */

    /* INICIO: Recebimento de jogada VALIDA */
        do
        {
            if( (Vez==1) || ((Vez==2) && (players==2)) )
            {
                printf("\n  Vai jogar onde: ");
                scanf("%s",posicao);
                fflush(stdin);
                Pi = PosicaoI(&posicao[0]);
                Pj = PosicaoJ(&posicao[1]);
                if(tabuleiro[Pi][Pj] != '*')
                {
                    Pi = 8;
                    Pj = 8;
                }
                if((Pi == 8) || (Pj == 8))
                {
                    printf(" Jogada invalida, tente novamente.");
                }
                else
                {
                    tabuleiro[Pi][Pj] = Pedra1;
                }
            }
            else if((players==1) && (Vez==2))
            {
                if(nivel==1)
                {
                    Q=5;
                    for(i=0; i<8; i++)
                    {
                        for(j=0; j<8; j++)
                        {
                            if( (tabuleiro[i][j] == '*') && (Q > qualidade[i][j]) )
                            {
                                Q = qualidade[i][j];
                            }
                        }
                    }
                    Mjogou=0;
                    for(i=0; i<8; i++)
                    {
                        for(j=0; j<8; j++)
                        {
                            if( (tabuleiro[i][j] == '*') && (Q == qualidade[i][j]) && (Mjogou==0) )
                            {
                                Mjogou=1;
                                Pi = i;
                                Pj = j;
                                tabuleiro[Pi][Pj] = Pedra1;

                            }
                        }
                    }
                }
                else if(nivel==3)
                {
                    Q=0;
                    for(i=0; i<8; i++)
                    {
                        for(j=0; j<8; j++)
                        {
                            if( (tabuleiro[i][j] == '*') && (Q < qualidade[i][j]) )
                            {
                                Q = qualidade[i][j];
                            }
                        }
                    }
                    Mjogou=0;
                    for(i=0; i<8; i++)
                    {
                        for(j=0; j<8; j++)
                        {
                            if( (tabuleiro[i][j] == '*') && (Q == qualidade[i][j]) && (Mjogou==0) )
                            {
                                Mjogou=1;
                                Pi = i;
                                Pj = j;
                                tabuleiro[Pi][Pj] = Pedra1;
                            }
                        }
                    }
                }
                else if(nivel==2)
                {
                    if(Nivel2==1)
                    {
                        Nivel2=3;
                        Q=5;
                        for(i=0; i<8; i++)
                        {
                            for(j=0; j<8; j++)
                            {
                                if( (tabuleiro[i][j] == '*') && (Q > qualidade[i][j]) )
                                {
                                    Q = qualidade[i][j];
                                }
                            }
                        }
                        Mjogou=0;
                        for(i=0; i<8; i++)
                        {
                            for(j=0; j<8; j++)
                            {
                                if( (tabuleiro[i][j] == '*') && (Q == qualidade[i][j]) && (Mjogou==0) )
                                {
                                    Mjogou=1;
                                    Pi = i;
                                    Pj = j;
                                    tabuleiro[Pi][Pj] = Pedra1;
                                }
                            }
                        }
                    }
                    else if(Nivel2==3)
                    {
                        Nivel2=1;
                        Q=0;
                        for(i=0; i<8; i++)
                        {
                            for(j=0; j<8; j++)
                            {
                                if( (tabuleiro[i][j] == '*') && (Q < qualidade[i][j]) )
                                {
                                    Q = qualidade[i][j];
                                }
                            }
                        }
                        Mjogou=0;
                        for(i=0; i<8; i++)
                        {
                            for(j=0; j<8; j++)
                            {
                                if( (tabuleiro[i][j] == '*') && (Q == qualidade[i][j]) && (Mjogou==0) )
                                {
                                    Mjogou=1;
                                    Pi = i;
                                    Pj = j;
                                    tabuleiro[Pi][Pj] = Pedra1;
                                }
                            }
                        }
                    }
                }

            }
        } while ((Pi == 8) || (Pj == 8));
    /* FIM: Recebimento de jogada VALIDA */

    /* INICIO: Da jogada */
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(tabuleiro[i][j] == '*')
                {
                    tabuleiro[i][j] = '-';
                }
            }
        }
        i = Pi;
        j = Pj;
        for(Possib=0; Possib<8; Possib++)
        {
            switch(Possib)
            {
                case 0:
                {
                    PossibCont2 = 0;
                    Pi = i;
                    Pj = j;
                    for(--Pi ; (Pi >=0); --Pi )
                    {
                        if(tabuleiro[Pi][Pj] == Pedra2)
                        {
                            PossibCont2++;
                        }
                        else if((tabuleiro[Pi][Pj] == Pedra1) && (PossibCont2>0))
                        {
                            for(++Pi ; (Pi < i); ++Pi )
                            {
                                tabuleiro[Pi][Pj] = Pedra1;
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                    break;
                case 1:
                {
                    PossibCont2 = 0;
                    Pi = i;
                    Pj = j;
                    for( (--Pi, ++Pj) ; ( Pi>=0 && Pj<=7) ; (--Pi, ++Pj))
                    {
                        if(tabuleiro[Pi][Pj] == Pedra2)
                        {
                            PossibCont2++;
                        }
                        else if((tabuleiro[Pi][Pj] == Pedra1) && (PossibCont2>0))
                        {
                            for( (++Pi, --Pj) ; ((Pi < i) && (Pj > j)); (++Pi, --Pj))
                            {
                                tabuleiro[Pi][Pj] = Pedra1;
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                    break;
                case 2:
                {
                    PossibCont2 = 0;
                    Pi = i;
                    Pj = j;
                    for(++Pj ; Pj<=7; ++Pj)
                    {
                        if(tabuleiro[Pi][Pj] == Pedra2)
                        {
                            PossibCont2++;
                        }
                        else if((tabuleiro[Pi][Pj] == Pedra1) && (PossibCont2>0))
                        {
                            for( (--Pj) ; (Pj > j); (--Pj))
                            {
                                tabuleiro[Pi][Pj] = Pedra1;
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                    break;
                case 3:
                {
                    PossibCont2 = 0;
                    Pi = i;
                    Pj = j;
                    for( (++Pi, ++Pj) ; ( Pi<=7 && Pj<=7) ; (++Pi, ++Pj))
                    {
                        if(tabuleiro[Pi][Pj] == Pedra2)
                        {
                            PossibCont2++;
                        }
                        else if((tabuleiro[Pi][Pj] == Pedra1) && (PossibCont2>0))
                        {
                            for( (--Pi, --Pj) ; ((Pi > i) && (Pj > j)); (--Pi, --Pj))
                            {
                                tabuleiro[Pi][Pj] = Pedra1;
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                    break;
                case 4:
                {
                    PossibCont2 = 0;
                    Pi = i;
                    Pj = j;
                    for(++Pi; Pi<=7; ++Pi)
                    {
                        if(tabuleiro[Pi][Pj] == Pedra2)
                        {
                            PossibCont2++;
                        }
                        else if((tabuleiro[Pi][Pj] == Pedra1) && (PossibCont2>0))
                        {
                            for( (--Pi) ; (Pi > i); (--Pi))
                            {
                                tabuleiro[Pi][Pj] = Pedra1;
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                    break;
                case 5:
                {
                    PossibCont2 = 0;
                    Pi = i;
                    Pj = j;
                    for( (++Pi, --Pj) ; ( Pi<=7 && Pj>=0) ; (++Pi, --Pj))
                    {
                        if(tabuleiro[Pi][Pj] == Pedra2)
                        {
                            PossibCont2++;
                        }
                        else if((tabuleiro[Pi][Pj] == Pedra1) && (PossibCont2>0))
                        {
                            for( (--Pi, ++Pj) ; ((Pi > i) && (Pj < j)); (--Pi, ++Pj))
                            {
                                tabuleiro[Pi][Pj] = Pedra1;
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                    break;
                case 6:
                {
                    PossibCont2 = 0;
                    Pi = i;
                    Pj = j;
                    for(--Pj ;Pj>=0 ; --Pj)
                    {
                        if(tabuleiro[Pi][Pj] == Pedra2)
                        {
                            PossibCont2++;
                        }
                        else if((tabuleiro[Pi][Pj] == Pedra1) && (PossibCont2>0))
                        {
                            for( (++Pj) ; (Pj < j); (++Pj))
                            {
                                tabuleiro[Pi][Pj] = Pedra1;
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                    break;
                case 7:
                {
                    PossibCont2 = 0;
                    Pi = i;
                    Pj = j;
                    for( (--Pi, --Pj) ; ( Pi>=0 && Pj>=0) ; (--Pi, --Pj))
                    {
                        if(tabuleiro[Pi][Pj] == Pedra2)
                        {
                            PossibCont2++;
                        }
                        else if((tabuleiro[Pi][Pj] == Pedra1) && (PossibCont2>0))
                        {
                            for( (++Pi, ++Pj) ; ((Pi < i) && (Pj < j)); (++Pi, ++Pj))
                            {
                                tabuleiro[Pi][Pj] = Pedra1;
                            }
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                    break;
            }
        }system("cls");
    } while(FimDeJogo==0);
                                         // FIM DA PARTIDA

    /* INICIO: Do Fim do Jogo */
    if (FimDeJogo==1)
    {
        if (PontoX==0)
        {
            printf("\n%s nao tem mais pecas, \n%s venceu\n",p1,p2);
            printf("\n%s: %d pontos\n",p2,PontoO);
            strcpy(p,p2);
            pontuacao=PontoO;
        }
        else if (PontoO==0)
        {
            printf("\n%s nao tem mais pecas, \n%s venceu\n",p2,p1);
            printf("\n%s: %d pontos\n",p1,PontoX);
            strcpy(p,p1);
            pontuacao=PontoX;
        }
    }
    else if (FimDeJogo==2)
    {
        printf("\nNao existem mais jogadas possiveis\n");
        printf("%s: %d pontos\n%s: %d pontos\n",p1,PontoX,p2,PontoO);
        if (PontoX>PontoO)
        {
            printf("\n%s Venceu\n",p1);
            strcpy(p,p1);
            pontuacao=PontoX;
        }
        else if (PontoO>PontoX)
        {
            printf("\n%s Venceu\n",p2);
            strcpy(p,p2);
            pontuacao=PontoO;
        }
    }
    else if (FimDeJogo==3)
    {
        if (PontoX>PontoO)
        {
            printf("%s: %d pontos\n%s: %d pontos\n",p1,PontoX,p2,PontoO);
            printf("\n%s Venceu\n",p1);
            strcpy(p,p1);
            pontuacao=PontoX;
        }
        else if (PontoO>PontoX)
        {
            printf("%s: %d pontos\n%s: %d pontos\n",p1,PontoX,p2,PontoO);
            printf("\n%s Venceu\n",p2);
            strcpy(p,p2);
            pontuacao=PontoO;
        }
    }
    else if (FimDeJogo==4)
    {
        printf("\n%s: %d pontos\n%s: %d pontos\n",p1,PontoX,p2,PontoO);
        printf("\nEmpate de Jogo\n");
    }
    //save(p, pontuacao);
    //read();
}
    /* FIM: Do Fim do Jogo */

int PosicaoI(char *i)
{
    switch(*i)
    {
        case 'A':
        case 'a':
        {
            return 0;
        }
            break;
        case 'B':
        case 'b':
        {
            return 1;
        }
            break;
        case 'C':
        case 'c':
        {
            return 2;
        }
            break;
        case 'D':
        case 'd':
        {
            return 3;
        }
            break;
        case 'E':
        case 'e':
        {
            return 4;
        }
            break;
        case 'F':
        case 'f':
        {
            return 5;
        }
            break;
        case 'G':
        case 'g':
        {
            return 6;
        }
            break;
        case 'H':
        case 'h':
        {
            return 7;
        }
            break;
        default:
        {
            return 8;
        }
            break;
    }

}

int PosicaoJ(char *j)
{
    switch(*j)
    {
        case '1':
        {
            return 0;
        }
            break;
        case '2':
        {
            return 1;
        }
            break;
        case '3':
        {
            return 2;
        }
            break;
        case '4':
        {
            return 3;
        }
            break;
        case '5':
        {
            return 4;
        }
            break;
        case '6':
        {
            return 5;
        }
            break;
        case '7':
        {
            return 6;
        }
            break;
        case '8':
        {
            return 7;
        }
            break;
        default:
        {
            return 8;
        }
            break;
    }
}

/*void save(char *p, int *pontuacao)
{
    FILE *files;
    files=fopen("Ranking de Vitoriosos.txt", "a");
    if(files==NULL)
    {
        printf("Arquivo inválido!\n");
        exit(-1);
    }
    fprintf(files, "Nome: %s.\nPontuação: %d.\n\n", p, pontuacao);
    fclose(files);
}

void read()
{
    char auxiliar;
    FILE *files;
    files=fopen("Ranking de Vitoriosos.txt", "r");
    if(files==NULL)
    {
        printf("Arquivo inválido!\n");
        exit(-1);
    }
    while((auxiliar=fgetc(files))!=EOF)
    {
        putchar(auxiliar);
    }
    fclose(files);
}*/













