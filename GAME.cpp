#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char jog1[20], jog2[20];
char mat[4][4]={{'.','1','2','3'},{'1','.','.','.'},{'2','.','.','.'},{'3','.','.','.'}};
int incl,incc,lin,col,vez,queJog=0;
char cont='s';

void matriz();
void comV();
int verLin();
int verCol();
int verIgu(int lin, int col);

int main()
{
    int linMat, colMat,igu;
    setlocale(LC_ALL, "Portuguese");
    while (cont=='s'||cont=='S')
    {
        printf("\n Digite o nome do jogador 1: ");
        fgets(jog1,20,stdin);
        system("cls");
        printf("\n Digite o nome do jogador 2: ");
        fgets(jog2,20,stdin);
        for ( vez = 0; vez < 9; vez++)
        {
            queJog=queJog%2;
            if (queJog==0)
            {
                system("cls");
                matriz();
                printf(" E a vez do(a):%s",jog1);
                printf(" Voce e o -- X --");
                linMat=verLin();
                colMat=verCol();
                igu=verIgu(lin,col);

                while (igu==0)
                {
                    printf("\n O local ja esta ocupado digite novamente\n");
                    linMat=verLin();
                    colMat=verCol();
                    igu=verIgu(lin,col);          
                }
                mat[linMat][colMat]='X';
                comV();
                queJog=queJog+1;
            }
            else
            {
                system("cls");
                matriz();
                printf(" E a vez do(a):%s",jog2);
                printf(" Voce e o -- O --");
                linMat=verLin();
                colMat=verCol();
                igu=verIgu(lin,col);

                while (igu==0)
                {
                    system("cls");
                    matriz();
                    printf("\n O local ja esta ocupado digite novamente\n");
                    linMat=verLin();
                    colMat=verCol();
                    igu=verIgu(lin,col);          
                }
                mat[linMat][colMat]='O';
                comV();
                queJog=queJog+1;
            }
            }
            printf("\n");
            printf(" Fim de jogo\n");
            printf(" S - para continuar\n N - para para sair\n");
            scanf("%c%*c", &cont);
            for ( incl = 1; incl < 4; incl++)
            {
                for ( incc = 1; incc < 4; incc++)
                {
                    mat[incl][incc]='.';
                }
            }
            system("cls");
    }
    return 0;
}
void matriz()
{
    printf("\n");
    printf("\n");       
    printf(" %c   %c   %c   %C\n", mat[0][0], mat[0][1], mat[0][2], mat[0][3]);
    printf("\n");
    printf(" %c   %c | %c | %C\n", mat[1][0], mat[1][1], mat[1][2], mat[1][3]);
    printf("    -----------\n");
    printf(" %c   %c | %c | %C\n", mat[2][0], mat[2][1], mat[2][2], mat[2][3]);
    printf("    -----------\n");
    printf(" %c   %c | %c | %C\n", mat[3][0], mat[3][1], mat[3][2], mat[3][3]);
    printf("\n");
}
int verLin()
{
    printf("\n Digite o numero da linha: ");
    scanf("%i%*c",&lin);
    if (lin>3)
    {
        while (lin>3)
        {
            system("cls");
            matriz();
            printf("\n Valor invalida digite o numero da linha: ");
            scanf("%i%*c", &lin);
        }
    }
    return lin;
}
int verCol()
{
    printf("\n Digite o numero da coluna: ");
    scanf("%i%*c",&col);
    if (col>3)
    {
        while (col>3)
        {
            system("cls");
            matriz();
            printf("\n Valor invalida digite o numero da linha: ");
            scanf("%i%*c", &col);
        }
    }
    return col;
}
int verIgu(int lin, int col)
{
    int li, co;
    li=lin;
    co=col;
    if (mat[li][co]=='X'||mat[li][co]=='O')
    {
        li=0;
        co=0;
    }
    return li+co;
}
void comV()
{
    if (((mat[1][1]=='O')&&(mat[1][2]=='O')&&(mat[1][3]=='O'))||
        ((mat[2][1]=='O')&&(mat[2][2]=='O')&&(mat[2][3]=='O'))||
        ((mat[3][1]=='O')&&(mat[3][2]=='O')&&(mat[3][3]=='O'))||
        ((mat[1][1]=='O')&&(mat[2][1]=='O')&&(mat[3][1]=='O'))||
        ((mat[1][2]=='O')&&(mat[2][2]=='O')&&(mat[3][2]=='O'))||
        ((mat[1][3]=='O')&&(mat[2][3]=='O')&&(mat[3][3]=='O'))||
        ((mat[1][1]=='O')&&(mat[2][2]=='O')&&(mat[3][3]=='O'))||
        ((mat[1][3]=='O')&&(mat[2][2]=='O')&&(mat[3][1]=='O'))||
        ((mat[1][1]=='X')&&(mat[1][2]=='X')&&(mat[1][3]=='X'))||
        ((mat[2][1]=='X')&&(mat[2][2]=='X')&&(mat[2][3]=='X'))||
        ((mat[3][1]=='X')&&(mat[3][2]=='X')&&(mat[3][3]=='X'))||
        ((mat[1][1]=='X')&&(mat[2][1]=='X')&&(mat[3][1]=='X'))||
        ((mat[1][2]=='X')&&(mat[2][2]=='X')&&(mat[3][2]=='X'))||
        ((mat[1][3]=='X')&&(mat[2][3]=='X')&&(mat[3][3]=='X'))||
        ((mat[1][1]=='X')&&(mat[2][2]=='X')&&(mat[3][3]=='X'))||
        ((mat[1][3]=='X')&&(mat[2][2]=='X')&&(mat[3][1]=='X'))
        )
    {
        system("cls");
        matriz();
        queJog=queJog%2;
        if (queJog==0)
        {
            printf("\n Parabens %s voce venceu!\n", jog1);
            printf("\n");
            printf("########################\n");
            printf("  ####################  \n");
            printf("  ####################  \n");
            printf("  ####################  \n");
            printf("    ################    \n");
            printf("      ############      \n");
            printf("        ########        \n");
            printf("          ####          \n");
            printf("          ####          \n");
            printf("          ####          \n");
            printf("      ############      \n");
            printf("     ##############     \n");
        }
        else
        {
            printf("\n Parabens %s voce venceu!\n", jog2);
            printf("\n");
            printf("########################\n");
            printf("  ####################  \n");
            printf("  ####################  \n");
            printf("  ####################  \n");
            printf("    ################    \n");
            printf("      ############      \n");
            printf("        ########        \n");
            printf("          ####          \n");
            printf("          ####          \n");
            printf("          ####          \n");
            printf("      ############      \n");
            printf("     ##############     \n");
        }  
        vez=10;
    }   
}
