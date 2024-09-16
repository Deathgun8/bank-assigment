#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0;
    int c1 = 12800, c2 = 6400, c5 = 3200, c20 = 1600, c50 = 800, c150 = 400, c300 = 200, c350 = 100, cedulas = 0;
    int countC1, countC2, countC5, countC20, countC50, countC150, countC300, countC350, quant;
    int quantidadeSacar, somaTotal1 = 0, somaTotal2 = 0, i;
    int menu = 0, comando = 0, valido = 1;
    int saldo = 0, sacado = 0;
    int digito1 = 0, digito2 = 0;
    char cpf[12] = "";
    char extenso[1000];

    while (menu != 6) // 6 vai sair do programa
    {

        if (menu == 0) // menu principal
        {
            printf("\n Bem vindo ao menu principal, pressione:\n 1 - Sacar \n 2 - Menu Gerente \n 3 - Finalizar \n");
            scanf("%d", &comando);

            switch (comando)
            {
            case 1:
                // 455 131 108 14

                while (valido != 0)
                {
                    do
                    {
                        printf("\nQual o seu CPF?\n");
                        scanf("%s", cpf);
                    } while (strlen(cpf) != 11);

                    somaTotal1 = 0;
                    somaTotal2 = 0;

                    // Calcular o primeiro dígito verificador
                    for (i = 0; i < 9; i++)
                    {
                        somaTotal1 += (cpf[i] - '0') * (10 - i);
                    }
                    digito1 = somaTotal1 % 11;
                    if (digito1 < 2)
                    {
                        digito1 = 0;
                    }
                    else
                    {
                        digito1 = 11 - digito1;
                    }

                    // Calcular o segundo dígito verificador
                    for (i = 0; i < 10; i++)
                    {
                        somaTotal2 += (cpf[i] - '0') * (11 - i);
                    }
                    digito2 = somaTotal2 % 11;
                    if (digito2 < 2)
                    {
                        digito2 = 0;
                    }
                    else
                    {
                        digito2 = 11 - digito2;
                    }

                    // Verificar os dígitos verificadores
                    if ((cpf[9] - '0') == digito1 && (cpf[10] - '0') == digito2)
                    {
                        printf("CPF valido\n");
                        valido = 0;
                    }
                    else
                    {
                        printf("CPF invalido\n");
                    }
                }
                // inicialização de variaveis
                quantidadeSacar = 0;
                countC1 = 0, countC2 = 0, countC5 = 0, countC20 = 0, countC50 = 0, countC150 = 0, countC300 = 0, countC350 = 0;

                        printf("\n Quanto deseja sacar? \n");
                scanf("%d", &quantidadeSacar);

                // verifica o valor que o usuário deseja sacar
                while (quantidadeSacar < 0)
                {
                    printf("Numero invalido \n");
                    scanf("%d", &quantidadeSacar);
                }

                // adiciona o valor que foi sacado na variavel sacado para ser utilizado depois
                sacado += quantidadeSacar;

                // faz a conversão para extenso
                n1 = quantidadeSacar % 10;
                n2 = (quantidadeSacar / 10) % 10;
                n3 = (quantidadeSacar / 100) % 10;
                n4 = (quantidadeSacar / 1000) % 10;
                n5 = (quantidadeSacar / 10000) % 10;
                n6 = (quantidadeSacar / 100000) % 10;
                n7 = (quantidadeSacar / 1000000) % 10;

                // o programa tem limite de 9 milhoes , ou 9999999
                // n7
                if (n7 == 9)
                {
                    strcat(extenso, "nove milhoes ");
                }
                if (n7 == 8)
                {
                    strcat(extenso, "oito milhoes ");
                }
                if (n7 == 7)
                {
                    strcat(extenso, "sete milhoes ");
                }
                if (n7 == 6)
                {
                    strcat(extenso, "seis milhoes ");
                }
                if (n7 == 5)
                {
                    strcat(extenso, "cinco milhoes ");
                }
                if (n7 == 4)
                {
                    strcat(extenso, "quatro milhoes ");
                }
                if (n7 == 3)
                {
                    strcat(extenso, "tres milhoes ");
                }
                if (n7 == 2)
                {
                    strcat(extenso, "dois milhoes ");
                }
                if (n7 == 1)
                {
                    strcat(extenso, "um milhao ");
                }

                // coloca o e
                if (n7 != 0)
                {
                    if (n6 != 0 && n5 == 0 && n4 == 0 && n3 == 0 && n2 == 0 && n1 == 0)
                    {
                        strcat(extenso, " e ");
                    }
                    else
                    {
                        strcat(extenso, ", ");
                    }
                }

                // n6
                if (n6 == 9)
                {
                    strcat(extenso, "novecentos ");
                }
                if (n6 == 8)
                {
                    strcat(extenso, "oitocentos ");
                }
                if (n6 == 7)
                {
                    strcat(extenso, "setecentos ");
                }
                if (n6 == 6)
                {
                    strcat(extenso, "seicentos ");
                }
                if (n6 == 5)
                {
                    strcat(extenso, "quinhentos ");
                }
                if (n6 == 4)
                {
                    strcat(extenso, "quatrocentos ");
                }
                if (n6 == 3)
                {
                    strcat(extenso, "trezentos ");
                }
                if (n6 == 2)
                {
                    strcat(extenso, "duzentos ");
                }
                if (n6 == 1)
                {
                    if (n5 != 0 && n4 != 0)
                    {
                        strcat(extenso, "cento ");
                    }
                    else
                    {
                        strcat(extenso, "cem ");
                    }
                }
                // coloca o mil

                if (n6 != 0 && n5 == 0 && n4 == 0)
                {
                    strcat(extenso, " mil ");
                }

                // coloca o e
                if (n6 != 0 && n5 != 0)
                {
                    strcat(extenso, " e ");
                }

                // n5
                if (n5 == 9)
                {
                    strcat(extenso, "noventa ");
                }
                if (n5 == 8)
                {
                    strcat(extenso, "oitenta ");
                }
                if (n5 == 7)
                {
                    strcat(extenso, "setenta ");
                }
                if (n5 == 6)
                {
                    strcat(extenso, "sessenta ");
                }
                if (n5 == 5)
                {
                    strcat(extenso, "cinquenta ");
                }
                if (n5 == 4)
                {
                    strcat(extenso, "quarenta ");
                }
                if (n5 == 3)
                {
                    strcat(extenso, "trinta ");
                }
                if (n5 == 2)
                {
                    strcat(extenso, "vinte ");
                }
                if (n5 == 1)
                {
                    if (n4 == 0)
                    {
                        strcat(extenso, "dez ");
                    }
                    if (n4 == 9)
                    {
                        strcat(extenso, "dezenove ");
                        n4 = 0;
                    }
                    if (n4 == 8)
                    {
                        strcat(extenso, "dezoito ");
                        n4 = 0;
                    }
                    if (n4 == 7)
                    {
                        strcat(extenso, "desessete ");
                        n4 = 0;
                    }
                    if (n4 == 6)
                    {
                        strcat(extenso, "desesseis ");
                        n4 = 0;
                    }
                    if (n4 == 5)
                    {
                        strcat(extenso, "quinze ");
                        n4 = 0;
                    }
                    if (n4 == 4)
                    {
                        strcat(extenso, "quatorze ");
                        n4 = 0;
                    }
                    if (n4 == 3)
                    {
                        strcat(extenso, "treze ");
                        n4 = 0;
                    }
                    if (n4 == 2)
                    {
                        strcat(extenso, "doze ");
                        n4 = 0;
                    }
                    if (n4 == 1)
                    {
                        strcat(extenso, "onze ");
                        n4 = 0;
                    }
                }

                // coloca o mil
                if (n5 != 0 && n4 == 0)
                {
                    strcat(extenso, " mil ");
                }

                // coloca o e
                if (n5 != 0 && (n4 != 0))
                {
                    strcat(extenso, " e ");
                }

                // n4
                if (n4 == 9)
                {
                    strcat(extenso, "nove mil ");
                }
                if (n4 == 8)
                {
                    strcat(extenso, "oito mil ");
                }
                if (n4 == 7)
                {
                    strcat(extenso, "sete mil ");
                }
                if (n4 == 6)
                {
                    strcat(extenso, "seis mil ");
                }
                if (n4 == 5)
                {
                    strcat(extenso, "cinco mil ");
                }
                if (n4 == 4)
                {
                    strcat(extenso, "quatro mil ");
                }
                if (n4 == 3)
                {
                    strcat(extenso, "tres mil ");
                }
                if (n4 == 2)
                {
                    strcat(extenso, "dois mil ");
                }

                if (n4 == 1)
                {
                    if (n5 != 0)
                    {
                        strcat(extenso, " um mil ");
                    }
                    else
                    {
                        strcat(extenso, " mil ");
                    }
                }

                // coloca o e
                if (n7 != 0 || n6 != 0 || n5 != 0 || n4 != 0)
                {
                    if (n3 != 0 && (n2 == 0 && n1 == 0))
                    {
                        strcat(extenso, " e ");
                    }
                    else
                    {
                        strcat(extenso, ", "); //
                    }
                }

                // n3
                if (n3 == 9)
                {
                    strcat(extenso, "novecentos ");
                }
                if (n3 == 8)
                {
                    strcat(extenso, "oitocentos ");
                }
                if (n3 == 7)
                {
                    strcat(extenso, "setecentos ");
                }
                if (n3 == 6)
                {
                    strcat(extenso, "seicentos ");
                }
                if (n3 == 5)
                {
                    strcat(extenso, "quinhentos ");
                }
                if (n3 == 4)
                {
                    strcat(extenso, "quatrocentos ");
                }
                if (n3 == 3)
                {
                    strcat(extenso, "trezentos ");
                }
                if (n3 == 2)
                {
                    strcat(extenso, "duzentos ");
                }
                if (n3 == 1)
                {
                    if (n2 != 0 || n1 != 0)
                    {
                        strcat(extenso, "cento");
                    }
                    else
                    {
                        strcat(extenso, "cem");
                    }
                }

                // coloca o e
                if (n7 != 0 || n6 != 0 || n5 != 0 || n4 != 0)
                {
                    if (n3 != 0 && (n2 != 0 || n1 != 0))
                    {
                        strcat(extenso, " e ");
                    }
                }

                // n2
                if (n2 == 9)
                {
                    strcat(extenso, "noventa  ");
                }
                if (n2 == 8)
                {
                    strcat(extenso, "oitenta  ");
                }
                if (n2 == 7)
                {
                    strcat(extenso, "setenta  ");
                }
                if (n2 == 6)
                {
                    strcat(extenso, "sessenta  ");
                }
                if (n2 == 5)
                {
                    strcat(extenso, "cinquenta  ");
                }
                if (n2 == 4)
                {
                    strcat(extenso, "quarenta  ");
                }
                if (n2 == 3)
                {
                    strcat(extenso, "trinta  ");
                }
                if (n2 == 2)
                {
                    strcat(extenso, "vinte  ");
                }
                if (n2 == 1)
                {
                    if (n1 == 0)
                    {
                        strcat(extenso, "dez");
                    }
                    if (n1 == 9)
                    {
                        strcat(extenso, "dezenove ");
                        n1 = 0;
                    }
                    if (n1 == 8)
                    {
                        strcat(extenso, "dezoito ");
                        n1 = 0;
                    }
                    if (n1 == 7)
                    {
                        strcat(extenso, "desessete ");
                        n1 = 0;
                    }
                    if (n1 == 6)
                    {
                        strcat(extenso, "desesseis ");
                        n1 = 0;
                    }
                    if (n1 == 5)
                    {
                        strcat(extenso, "quinze ");
                        n1 = 0;
                    }
                    if (n1 == 4)
                    {
                        strcat(extenso, "quatorze ");
                        n1 = 0;
                    }
                    if (n1 == 3)
                    {
                        strcat(extenso, "treze");
                        n1 = 0;
                    }
                    if (n1 == 2)
                    {
                        strcat(extenso, "doze ");
                        n1 = 0;
                    }
                    if (n1 == 1)
                    {
                        strcat(extenso, "onze ");
                        n1 = 0;
                    }
                }
                // coloca o e
                if (n2 != 0 && n1 != 0)
                {
                    strcat(extenso, "e ");
                }

                // n1
                if (n1 == 9)
                {
                    strcat(extenso, "nove ");
                }
                if (n1 == 8)
                {
                    strcat(extenso, "oito ");
                }
                if (n1 == 7)
                {
                    strcat(extenso, "sete ");
                }
                if (n1 == 6)
                {
                    strcat(extenso, "seis ");
                }
                if (n1 == 5)
                {
                    strcat(extenso, "cinco ");
                }
                if (n1 == 4)
                {
                    strcat(extenso, "quatro ");
                }
                if (n1 == 3)
                {
                    strcat(extenso, "tres ");
                }
                if (n1 == 2)
                {
                    strcat(extenso, "dois ");
                }
                if (n1 == 1)
                {
                    strcat(extenso, "um ");
                }

                // mostra ao usuario  quantidade por extenso
                printf("O valor do saque de %d em extenso e %s \n", quantidadeSacar, extenso);
                strcpy(extenso, "");

                // Calcula a quantidade máxima de notas 350 que o usuário vai receber
                while (quantidadeSacar >= 350 && c350 > 0)
                {
                    quantidadeSacar -= 350;
                    countC350++;
                    c350--;
                }

                // Calcula as notas de 350
                while (quantidadeSacar >= 300 && c300 > 0)
                {
                    quantidadeSacar -= 300;
                    countC300++;
                    c300--;
                }

                // Calcula as notas de 350
                while (quantidadeSacar >= 150 && c150 > 0)
                {
                    quantidadeSacar -= 150;
                    countC150++;
                    c150--;
                }

                // Calcula as notas de 350
                while (quantidadeSacar >= 50 && c50 > 0)
                {
                    quantidadeSacar -= 50;
                    countC50++;
                    c50--;
                }

                // Calcula as notas de 350
                while (quantidadeSacar >= 20 && c20 > 0)
                {
                    quantidadeSacar -= 20;
                    countC20++;
                    c20--;
                }

                // Calcula as notas de 350
                while (quantidadeSacar >= 5 && c5 > 0)
                {
                    quantidadeSacar -= 5;
                    countC5++;
                    c5--;
                }

                // Calcula as notas de 350
                while (quantidadeSacar >= 2 && c2 > 0)
                {
                    quantidadeSacar -= 2;
                    countC2++;
                    c2--;
                }

                while (quantidadeSacar >= 1 && c1 > 0)
                {
                    quantidadeSacar -= 1;
                    countC1++;
                    c1--;
                }

                // mostra ao usuario a quantidade de cada nota que ele vai receber
                if (quantidadeSacar > 0)
                {
                    printf("Nao ha cedulas suficiente no caixa para completar o pagamento ");
                }
                else
                {
                    printf("Notas de 350 reais: %d \n", countC350);
                    printf("Notas de 300 reais: %d \n", countC300);
                    printf("Notas de 150 reais: %d \n", countC150);
                    printf("Notas de 50 reais: %d \n", countC50);
                    printf("Notas de 20 reais: %d \n", countC20);
                    printf("Notas de 5 reais: %d \n", countC5);
                    printf("Notas de 2 reais: %d \n", countC2);
                    printf("Notas de 1 real: %d \n", countC1);
                }

                break;

            case 2:
                menu = 1;
                printf("%d", menu);
                break;

            case 3:
                // finalizar
                printf("\n Programa finalizado");
                menu = 6;
                break;

            default:
                printf("\nEntrada invalida.");
                menu = 0;
                break;
            }
        }

        if (menu == 1) // menu gerente
        {
            n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0;

            printf("\n Bem vindo ao menu do gerente, pressione:\n 1 - Valor total sacado \n 2 - Valor do saldo existente \n 3 - Quantidade de cedulas existentes \n 4 - Abastecer o caixa eletronico \n 5 - Voltar ao menu principal\n");
            scanf("%d", &comando);

            switch (comando)
            {
            case 1:
                if (sacado == 0)
                {
                    printf("Ainda nao foi sacado nenhum valor");
                }
                else
                {
                    n1 = sacado % 10;
                    n2 = (sacado / 10) % 10;
                    n3 = (sacado / 100) % 10;
                    n4 = (sacado / 1000) % 10;
                    n5 = (sacado / 10000) % 10;
                    n6 = (sacado / 100000) % 10;
                    n7 = (sacado / 1000000) % 10;

                    // o programa tem limite de 9 milhoes , ou 9999999
                    // n7
                    if (n7 == 9)
                    {
                        strcat(extenso, "nove milhoes ");
                    }
                    if (n7 == 8)
                    {
                        strcat(extenso, "oito milhoes ");
                    }
                    if (n7 == 7)
                    {
                        strcat(extenso, "sete milhoes ");
                    }
                    if (n7 == 6)
                    {
                        strcat(extenso, "seis milhoes ");
                    }
                    if (n7 == 5)
                    {
                        strcat(extenso, "cinco milhoes ");
                    }
                    if (n7 == 4)
                    {
                        strcat(extenso, "quatro milhoes ");
                    }
                    if (n7 == 3)
                    {
                        strcat(extenso, "tres milhoes ");
                    }
                    if (n7 == 2)
                    {
                        strcat(extenso, "dois milhoes ");
                    }
                    if (n7 == 1)
                    {
                        strcat(extenso, "um milhao ");
                    }

                    // coloca o e
                    if (n7 != 0)
                    {
                        if (n6 != 0 && n5 == 0 && n4 == 0 && n3 == 0 && n2 == 0 && n1 == 0)
                        {
                            strcat(extenso, " e ");
                        }
                        else
                        {
                            strcat(extenso, ", ");
                        }
                    }

                    // n6
                    if (n6 == 9)
                    {
                        strcat(extenso, "novecentos ");
                    }
                    if (n6 == 8)
                    {
                        strcat(extenso, "oitocentos ");
                    }
                    if (n6 == 7)
                    {
                        strcat(extenso, "setecentos ");
                    }
                    if (n6 == 6)
                    {
                        strcat(extenso, "seicentos ");
                    }
                    if (n6 == 5)
                    {
                        strcat(extenso, "quinhentos ");
                    }
                    if (n6 == 4)
                    {
                        strcat(extenso, "quatrocentos ");
                    }
                    if (n6 == 3)
                    {
                        strcat(extenso, "trezentos ");
                    }
                    if (n6 == 2)
                    {
                        strcat(extenso, "duzentos ");
                    }
                    if (n6 == 1)
                    {
                        if (n5 != 0 && n4 != 0)
                        {
                            strcat(extenso, "cento ");
                        }
                        else
                        {
                            strcat(extenso, "cem ");
                        }
                    }
                    // coloca o mil

                    if (n6 != 0 && n5 == 0 && n4 == 0)
                    {
                        strcat(extenso, " mil");
                    }

                    // coloca o e
                    if (n6 != 0 && n5 != 0)
                    {
                        strcat(extenso, " e ");
                    }

                    // n5
                    if (n5 == 9)
                    {
                        strcat(extenso, "noventa ");
                    }
                    if (n5 == 8)
                    {
                        strcat(extenso, "oitenta ");
                    }
                    if (n5 == 7)
                    {
                        strcat(extenso, "setenta ");
                    }
                    if (n5 == 6)
                    {
                        strcat(extenso, "sessenta ");
                    }
                    if (n5 == 5)
                    {
                        strcat(extenso, "cinquenta ");
                    }
                    if (n5 == 4)
                    {
                        strcat(extenso, "quarenta ");
                    }
                    if (n5 == 3)
                    {
                        strcat(extenso, "trinta ");
                    }
                    if (n5 == 2)
                    {
                        strcat(extenso, "vinte ");
                    }
                    if (n5 == 1)
                    {
                        if (n4 == 0)
                        {
                            strcat(extenso, "dez");
                        }
                        if (n4 == 9)
                        {
                            strcat(extenso, "dezenove ");
                            n4 = 0;
                        }
                        if (n4 == 8)
                        {
                            strcat(extenso, "dezoito ");
                            n4 = 0;
                        }
                        if (n4 == 7)
                        {
                            strcat(extenso, "desessete ");
                            n4 = 0;
                        }
                        if (n4 == 6)
                        {
                            strcat(extenso, "desesseis ");
                            n4 = 0;
                        }
                        if (n4 == 5)
                        {
                            strcat(extenso, "quinze ");
                            n4 = 0;
                        }
                        if (n4 == 4)
                        {
                            strcat(extenso, "quatorze ");
                            n4 = 0;
                        }
                        if (n4 == 3)
                        {
                            strcat(extenso, "treze");
                            n4 = 0;
                        }
                        if (n4 == 2)
                        {
                            strcat(extenso, "doze ");
                            n4 = 0;
                        }
                        if (n4 == 1)
                        {
                            strcat(extenso, "onze ");
                            n4 = 0;
                        }
                    }

                    // coloca o mil
                    if (n5 != 0 && n4 == 0)
                    {
                        strcat(extenso, " mil ");
                    }

                    // coloca o e
                    if (n5 != 0 && (n4 != 0))
                    {
                        strcat(extenso, " e ");
                    }

                    // n4
                    if (n4 == 9)
                    {
                        strcat(extenso, "nove mil ");
                    }
                    if (n4 == 8)
                    {
                        strcat(extenso, "oito mil ");
                    }
                    if (n4 == 7)
                    {
                        strcat(extenso, "sete mil ");
                    }
                    if (n4 == 6)
                    {
                        strcat(extenso, "seis mil ");
                    }
                    if (n4 == 5)
                    {
                        strcat(extenso, "cinco mil ");
                    }
                    if (n4 == 4)
                    {
                        strcat(extenso, "quatro mil ");
                    }
                    if (n4 == 3)
                    {
                        strcat(extenso, "tres mil ");
                    }
                    if (n4 == 2)
                    {
                        strcat(extenso, "dois mil ");
                    }

                    if (n4 == 1)
                    {
                        if (n5 != 0)
                        {
                            strcat(extenso, " um mil ");
                        }
                        else
                        {
                            strcat(extenso, " mil ");
                        }
                    }

                    // coloca o e
                    if (n7 != 0 || n6 != 0 || n5 != 0 || n4 != 0)
                    {
                        if (n3 != 0 && (n2 == 0 && n1 == 0))
                        {
                            strcat(extenso, " e ");
                        }
                        else
                        {
                            strcat(extenso, ", "); //
                        }
                    }

                    // n3
                    if (n3 == 9)
                    {
                        strcat(extenso, "novecentos ");
                    }
                    if (n3 == 8)
                    {
                        strcat(extenso, "oitocentos ");
                    }
                    if (n3 == 7)
                    {
                        strcat(extenso, "setecentos ");
                    }
                    if (n3 == 6)
                    {
                        strcat(extenso, "seicentos ");
                    }
                    if (n3 == 5)
                    {
                        strcat(extenso, "quinhentos ");
                    }
                    if (n3 == 4)
                    {
                        strcat(extenso, "quatrocentos ");
                    }
                    if (n3 == 3)
                    {
                        strcat(extenso, "trezentos ");
                    }
                    if (n3 == 2)
                    {
                        strcat(extenso, "duzentos ");
                    }
                    if (n3 == 1)
                    {
                        if (n2 != 0 || n1 != 0)
                        {
                            strcat(extenso, "cento ");
                        }
                        else
                        {
                            strcat(extenso, "cem ");
                        }
                    }

                    // coloca o e
                    if (n7 != 0 || n6 != 0 || n5 != 0 || n4 != 0)
                    {
                        if (n3 != 0 && (n2 != 0 || n1 != 0))
                        {
                            strcat(extenso, " e ");
                        }
                    }

                    // n2
                    if (n2 == 9)
                    {
                        strcat(extenso, "noventa  ");
                    }
                    if (n2 == 8)
                    {
                        strcat(extenso, "oitenta  ");
                    }
                    if (n2 == 7)
                    {
                        strcat(extenso, "setenta  ");
                    }
                    if (n2 == 6)
                    {
                        strcat(extenso, "sessenta  ");
                    }
                    if (n2 == 5)
                    {
                        strcat(extenso, "cinquenta  ");
                    }
                    if (n2 == 4)
                    {
                        strcat(extenso, "quarenta  ");
                    }
                    if (n2 == 3)
                    {
                        strcat(extenso, "trinta  ");
                    }
                    if (n2 == 2)
                    {
                        strcat(extenso, "vinte  ");
                    }
                    if (n2 == 1)
                    {
                        if (n1 == 0)
                        {
                            strcat(extenso, "dez ");
                        }
                        if (n1 == 9)
                        {
                            strcat(extenso, "dezenove ");
                            n1 = 0;
                        }
                        if (n1 == 8)
                        {
                            strcat(extenso, "dezoito ");
                            n1 = 0;
                        }
                        if (n1 == 7)
                        {
                            strcat(extenso, "desessete ");
                            n1 = 0;
                        }
                        if (n1 == 6)
                        {
                            strcat(extenso, "desesseis ");
                            n1 = 0;
                        }
                        if (n1 == 5)
                        {
                            strcat(extenso, "quinze ");
                            n1 = 0;
                        }
                        if (n1 == 4)
                        {
                            strcat(extenso, "quatorze ");
                            n1 = 0;
                        }
                        if (n1 == 3)
                        {
                            strcat(extenso, "treze ");
                            n1 = 0;
                        }
                        if (n1 == 2)
                        {
                            strcat(extenso, "doze ");
                            n1 = 0;
                        }
                        if (n1 == 1)
                        {
                            strcat(extenso, "onze ");
                            n1 = 0;
                        }
                    }
                    // coloca o e
                    if (n2 != 0 && n1 != 0)
                    {
                        strcat(extenso, "e ");
                    }

                    // n1
                    if (n1 == 9)
                    {
                        strcat(extenso, "nove ");
                    }
                    if (n1 == 8)
                    {
                        strcat(extenso, "oito ");
                    }
                    if (n1 == 7)
                    {
                        strcat(extenso, "sete ");
                    }
                    if (n1 == 6)
                    {
                        strcat(extenso, "seis ");
                    }
                    if (n1 == 5)
                    {
                        strcat(extenso, "cinco ");
                    }
                    if (n1 == 4)
                    {
                        strcat(extenso, "quatro ");
                    }
                    if (n1 == 3)
                    {
                        strcat(extenso, "tres ");
                    }
                    if (n1 == 2)
                    {
                        strcat(extenso, "dois ");
                    }
                    if (n1 == 1)
                    {
                        strcat(extenso, "um ");
                    }

                    printf("\nO valor total sacado e %d", sacado);
                    printf("\nO valor total sacado em extenso e %s", extenso);
                    strcpy(extenso, "");
                }

                break;
            case 2:
                saldo = c1 + (c2 * 2) + (c5 * 5) + (c20 * 20) + (c50 * 50) + (c150 * 150) + (c300 * 300) + (c350 * 350);

                if (saldo == 0)
                {
                    printf("Nao ha saldo no caixa");
                }
                else
                {
                    n1 = saldo % 10;
                    n2 = (saldo / 10) % 10;
                    n3 = (saldo / 100) % 10;
                    n4 = (saldo / 1000) % 10;
                    n5 = (saldo / 10000) % 10;
                    n6 = (saldo / 100000) % 10;
                    n7 = (saldo / 1000000) % 10;

                    // o programa tem limite de 9 milhoes , ou 9999999
                    // n7
                    if (n7 == 9)
                    {
                        strcat(extenso, "nove milhoes ");
                    }
                    if (n7 == 8)
                    {
                        strcat(extenso, "oito milhoes ");
                    }
                    if (n7 == 7)
                    {
                        strcat(extenso, "sete milhoes ");
                    }
                    if (n7 == 6)
                    {
                        strcat(extenso, "seis milhoes ");
                    }
                    if (n7 == 5)
                    {
                        strcat(extenso, "cinco milhoes ");
                    }
                    if (n7 == 4)
                    {
                        strcat(extenso, "quatro milhoes ");
                    }
                    if (n7 == 3)
                    {
                        strcat(extenso, "tres milhoes ");
                    }
                    if (n7 == 2)
                    {
                        strcat(extenso, "dois milhoes ");
                    }
                    if (n7 == 1)
                    {
                        strcat(extenso, "um milhao ");
                    }

                    // coloca o e
                    if (n7 != 0)
                    {
                        if (n6 != 0 && n5 == 0 && n4 == 0 && n3 == 0 && n2 == 0 && n1 == 0)
                        {
                            strcat(extenso, " e ");
                        }
                        else
                        {
                            strcat(extenso, ", ");
                        }
                    }

                    // n6
                    if (n6 == 9)
                    {
                        strcat(extenso, "novecentos ");
                    }
                    if (n6 == 8)
                    {
                        strcat(extenso, "oitocentos ");
                    }
                    if (n6 == 7)
                    {
                        strcat(extenso, "setecentos ");
                    }
                    if (n6 == 6)
                    {
                        strcat(extenso, "seicentos ");
                    }
                    if (n6 == 5)
                    {
                        strcat(extenso, "quinhentos ");
                    }
                    if (n6 == 4)
                    {
                        strcat(extenso, "quatrocentos ");
                    }
                    if (n6 == 3)
                    {
                        strcat(extenso, "trezentos ");
                    }
                    if (n6 == 2)
                    {
                        strcat(extenso, "duzentos ");
                    }
                    if (n6 == 1)
                    {
                        if (n5 != 0 && n4 != 0)
                        {
                            strcat(extenso, "cento ");
                        }
                        else
                        {
                            strcat(extenso, "cem ");
                        }
                    }
                    // coloca o mil

                    if (n6 != 0 && n5 == 0 && n4 == 0)
                    {
                        strcat(extenso, " mil ");
                    }

                    // coloca o e
                    if (n6 != 0 && n5 != 0)
                    {
                        strcat(extenso, " e ");
                    }

                    // n5
                    if (n5 == 9)
                    {
                        strcat(extenso, "noventa ");
                    }
                    if (n5 == 8)
                    {
                        strcat(extenso, "oitenta ");
                    }
                    if (n5 == 7)
                    {
                        strcat(extenso, "setenta ");
                    }
                    if (n5 == 6)
                    {
                        strcat(extenso, "sessenta ");
                    }
                    if (n5 == 5)
                    {
                        strcat(extenso, "cinquenta ");
                    }
                    if (n5 == 4)
                    {
                        strcat(extenso, "quarenta ");
                    }
                    if (n5 == 3)
                    {
                        strcat(extenso, "trinta ");
                    }
                    if (n5 == 2)
                    {
                        strcat(extenso, "vinte ");
                    }
                    if (n5 == 1)
                    {
                        if (n4 == 0)
                        {
                            strcat(extenso, "dez ");
                        }
                        if (n4 == 9)
                        {
                            strcat(extenso, "dezenove ");
                            n4 = 0;
                        }
                        if (n4 == 8)
                        {
                            strcat(extenso, "dezoito ");
                            n4 = 0;
                        }
                        if (n4 == 7)
                        {
                            strcat(extenso, "desessete ");
                            n4 = 0;
                        }
                        if (n4 == 6)
                        {
                            strcat(extenso, "desesseis ");
                            n4 = 0;
                        }
                        if (n4 == 5)
                        {
                            strcat(extenso, "quinze ");
                            n4 = 0;
                        }
                        if (n4 == 4)
                        {
                            strcat(extenso, "quatorze ");
                            n4 = 0;
                        }
                        if (n4 == 3)
                        {
                            strcat(extenso, "treze ");
                            n4 = 0;
                        }
                        if (n4 == 2)
                        {
                            strcat(extenso, "doze ");
                            n4 = 0;
                        }
                        if (n4 == 1)
                        {
                            strcat(extenso, "onze ");
                            n4 = 0;
                        }
                    }

                    // coloca o mil
                    if (n5 != 0 && n4 == 0)
                    {
                        strcat(extenso, " mil ");
                    }

                    // coloca o e
                    if (n5 != 0 && (n4 != 0))
                    {
                        strcat(extenso, " e ");
                    }

                    // n4
                    if (n4 == 9)
                    {
                        strcat(extenso, "nove mil ");
                    }
                    if (n4 == 8)
                    {
                        strcat(extenso, "oito mil ");
                    }
                    if (n4 == 7)
                    {
                        strcat(extenso, "sete mil ");
                    }
                    if (n4 == 6)
                    {
                        strcat(extenso, "seis mil ");
                    }
                    if (n4 == 5)
                    {
                        strcat(extenso, "cinco mil ");
                    }
                    if (n4 == 4)
                    {
                        strcat(extenso, "quatro mil ");
                    }
                    if (n4 == 3)
                    {
                        strcat(extenso, "tres mil ");
                    }
                    if (n4 == 2)
                    {
                        strcat(extenso, "dois mil ");
                    }

                    if (n4 == 1)
                    {
                        if (n5 != 0)
                        {
                            strcat(extenso, " um mil ");
                        }
                        else
                        {
                            strcat(extenso, " mil ");
                        }
                    }

                    // coloca o e
                    if (n7 != 0 || n6 != 0 || n5 != 0 || n4 != 0)
                    {
                        if (n3 != 0 && (n2 == 0 && n1 == 0))
                        {
                            strcat(extenso, " e ");
                        }
                        else
                        {
                            strcat(extenso, ", "); //
                        }
                    }

                    // n3
                    if (n3 == 9)
                    {
                        strcat(extenso, "novecentos ");
                    }
                    if (n3 == 8)
                    {
                        strcat(extenso, "oitocentos ");
                    }
                    if (n3 == 7)
                    {
                        strcat(extenso, "setecentos ");
                    }
                    if (n3 == 6)
                    {
                        strcat(extenso, "seicentos ");
                    }
                    if (n3 == 5)
                    {
                        strcat(extenso, "quinhentos ");
                    }
                    if (n3 == 4)
                    {
                        strcat(extenso, "quatrocentos ");
                    }
                    if (n3 == 3)
                    {
                        strcat(extenso, "trezentos ");
                    }
                    if (n3 == 2)
                    {
                        strcat(extenso, "duzentos ");
                    }
                    if (n3 == 1)
                    {
                        if (n2 != 0 || n1 != 0)
                        {
                            strcat(extenso, "cento ");
                        }
                        else
                        {
                            strcat(extenso, "cem ");
                        }
                    }

                    // coloca o e
                    if (n7 != 0 || n6 != 0 || n5 != 0 || n4 != 0)
                    {
                        if (n3 != 0 && (n2 != 0 || n1 != 0))
                        {
                            strcat(extenso, " e ");
                        }
                    }

                    // n2
                    if (n2 == 9)
                    {
                        strcat(extenso, "noventa  ");
                    }
                    if (n2 == 8)
                    {
                        strcat(extenso, "oitenta  ");
                    }
                    if (n2 == 7)
                    {
                        strcat(extenso, "setenta  ");
                    }
                    if (n2 == 6)
                    {
                        strcat(extenso, "sessenta  ");
                    }
                    if (n2 == 5)
                    {
                        strcat(extenso, "cinquenta  ");
                    }
                    if (n2 == 4)
                    {
                        strcat(extenso, "quarenta  ");
                    }
                    if (n2 == 3)
                    {
                        strcat(extenso, "trinta  ");
                    }
                    if (n2 == 2)
                    {
                        strcat(extenso, "vinte  ");
                    }
                    if (n2 == 1)
                    {
                        if (n1 == 0)
                        {
                            strcat(extenso, "dez ");
                        }
                        if (n1 == 9)
                        {
                            strcat(extenso, "dezenove ");
                            n1 = 0;
                        }
                        if (n1 == 8)
                        {
                            strcat(extenso, "dezoito ");
                            n1 = 0;
                        }
                        if (n1 == 7)
                        {
                            strcat(extenso, "desessete ");
                            n1 = 0;
                        }
                        if (n1 == 6)
                        {
                            strcat(extenso, "desesseis ");
                            n1 = 0;
                        }
                        if (n1 == 5)
                        {
                            strcat(extenso, "quinze ");
                            n1 = 0;
                        }
                        if (n1 == 4)
                        {
                            strcat(extenso, "quatorze ");
                            n1 = 0;
                        }
                        if (n1 == 3)
                        {
                            strcat(extenso, "treze ");
                            n1 = 0;
                        }
                        if (n1 == 2)
                        {
                            strcat(extenso, "doze ");
                            n1 = 0;
                        }
                        if (n1 == 1)
                        {
                            strcat(extenso, "onze ");
                            n1 = 0;
                        }
                    }
                    // coloca o e
                    if (n2 != 0 && n1 != 0)
                    {
                        strcat(extenso, "e ");
                    }

                    // n1
                    if (n1 == 9)
                    {
                        strcat(extenso, "nove ");
                    }
                    if (n1 == 8)
                    {
                        strcat(extenso, "oito ");
                    }
                    if (n1 == 7)
                    {
                        strcat(extenso, "sete ");
                    }
                    if (n1 == 6)
                    {
                        strcat(extenso, "seis ");
                    }
                    if (n1 == 5)
                    {
                        strcat(extenso, "cinco ");
                    }
                    if (n1 == 4)
                    {
                        strcat(extenso, "quatro ");
                    }
                    if (n1 == 3)
                    {
                        strcat(extenso, "tres ");
                    }
                    if (n1 == 2)
                    {
                        strcat(extenso, "dois ");
                    }
                    if (n1 == 1)
                    {
                        strcat(extenso, "um ");
                    }

                    printf("\nO saldo total da maquina e %d", saldo);
                    printf("\nO saldo da maquina em extenso e %s", extenso);
                    strcpy(extenso, "");
                }
                break;

            case 3:
                cedulas = c1 + c2 + c5 + c20 + c50 + c150 + c300 + c350;

                if (cedulas == 0)
                {
                    printf("Nao ha mais cedulas no caixa");
                }
                else
                {
                    n1 = cedulas % 10;
                    n2 = (cedulas / 10) % 10;
                    n3 = (cedulas / 100) % 10;
                    n4 = (cedulas / 1000) % 10;
                    n5 = (cedulas / 10000) % 10;
                    n6 = (cedulas / 100000) % 10;
                    n7 = (cedulas / 1000000) % 10;

                    // o programa tem limite de 9 milhoes , ou 9999999
                    // n7
                    if (n7 == 9)
                    {
                        strcat(extenso, "nove milhoes ");
                    }
                    if (n7 == 8)
                    {
                        strcat(extenso, "oito milhoes ");
                    }
                    if (n7 == 7)
                    {
                        strcat(extenso, "sete milhoes ");
                    }
                    if (n7 == 6)
                    {
                        strcat(extenso, "seis milhoes ");
                    }
                    if (n7 == 5)
                    {
                        strcat(extenso, "cinco milhoes ");
                    }
                    if (n7 == 4)
                    {
                        strcat(extenso, "quatro milhoes ");
                    }
                    if (n7 == 3)
                    {
                        strcat(extenso, "tres milhoes ");
                    }
                    if (n7 == 2)
                    {
                        strcat(extenso, "dois milhoes ");
                    }
                    if (n7 == 1)
                    {
                        strcat(extenso, "um milhao ");
                    }

                    // coloca o e
                    if (n7 != 0)
                    {
                        if (n6 != 0 && n5 == 0 && n4 == 0 && n3 == 0 && n2 == 0 && n1 == 0)
                        {
                            strcat(extenso, " e ");
                        }
                        else
                        {
                            strcat(extenso, ", ");
                        }
                    }

                    // n6
                    if (n6 == 9)
                    {
                        strcat(extenso, "novecentos ");
                    }
                    if (n6 == 8)
                    {
                        strcat(extenso, "oitocentos ");
                    }
                    if (n6 == 7)
                    {
                        strcat(extenso, "setecentos ");
                    }
                    if (n6 == 6)
                    {
                        strcat(extenso, "seicentos ");
                    }
                    if (n6 == 5)
                    {
                        strcat(extenso, "quinhentos ");
                    }
                    if (n6 == 4)
                    {
                        strcat(extenso, "quatrocentos ");
                    }
                    if (n6 == 3)
                    {
                        strcat(extenso, "trezentos ");
                    }
                    if (n6 == 2)
                    {
                        strcat(extenso, "duzentos ");
                    }
                    if (n6 == 1)
                    {
                        if (n5 != 0 && n4 != 0)
                        {
                            strcat(extenso, "cento ");
                        }
                        else
                        {
                            strcat(extenso, "cem ");
                        }
                    }
                    // coloca o mil

                    if (n6 != 0 && n5 == 0 && n4 == 0)
                    {
                        strcat(extenso, " mil ");
                    }

                    // coloca o e
                    if (n6 != 0 && n5 != 0)
                    {
                        strcat(extenso, " e ");
                    }

                    // n5
                    if (n5 == 9)
                    {
                        strcat(extenso, "noventa ");
                    }
                    if (n5 == 8)
                    {
                        strcat(extenso, "oitenta ");
                    }
                    if (n5 == 7)
                    {
                        strcat(extenso, "setenta ");
                    }
                    if (n5 == 6)
                    {
                        strcat(extenso, "sessenta ");
                    }
                    if (n5 == 5)
                    {
                        strcat(extenso, "cinquenta ");
                    }
                    if (n5 == 4)
                    {
                        strcat(extenso, "quarenta ");
                    }
                    if (n5 == 3)
                    {
                        strcat(extenso, "trinta ");
                    }
                    if (n5 == 2)
                    {
                        strcat(extenso, "vinte ");
                    }
                    if (n5 == 1)
                    {
                        if (n4 == 0)
                        {
                            strcat(extenso, "dez ");
                        }
                        if (n4 == 9)
                        {
                            strcat(extenso, "dezenove ");
                            n4 = 0;
                        }
                        if (n4 == 8)
                        {
                            strcat(extenso, "dezoito ");
                            n4 = 0;
                        }
                        if (n4 == 7)
                        {
                            strcat(extenso, "desessete ");
                            n4 = 0;
                        }
                        if (n4 == 6)
                        {
                            strcat(extenso, "desesseis ");
                            n4 = 0;
                        }
                        if (n4 == 5)
                        {
                            strcat(extenso, "quinze ");
                            n4 = 0;
                        }
                        if (n4 == 4)
                        {
                            strcat(extenso, "quatorze ");
                            n4 = 0;
                        }
                        if (n4 == 3)
                        {
                            strcat(extenso, "treze ");
                            n4 = 0;
                        }
                        if (n4 == 2)
                        {
                            strcat(extenso, "doze ");
                            n4 = 0;
                        }
                        if (n4 == 1)
                        {
                            strcat(extenso, "onze ");
                            n4 = 0;
                        }
                    }

                    // coloca o mil
                    if (n5 != 0 && n4 == 0)
                    {
                        strcat(extenso, " mil ");
                    }

                    // coloca o e
                    if (n5 != 0 && (n4 != 0))
                    {
                        strcat(extenso, " e ");
                    }

                    // n4
                    if (n4 == 9)
                    {
                        strcat(extenso, "nove mil ");
                    }
                    if (n4 == 8)
                    {
                        strcat(extenso, "oito mil ");
                    }
                    if (n4 == 7)
                    {
                        strcat(extenso, "sete mil ");
                    }
                    if (n4 == 6)
                    {
                        strcat(extenso, "seis mil ");
                    }
                    if (n4 == 5)
                    {
                        strcat(extenso, "cinco mil ");
                    }
                    if (n4 == 4)
                    {
                        strcat(extenso, "quatro mil ");
                    }
                    if (n4 == 3)
                    {
                        strcat(extenso, "tres mil ");
                    }
                    if (n4 == 2)
                    {
                        strcat(extenso, "dois mil ");
                    }

                    if (n4 == 1)
                    {
                        if (n5 != 0)
                        {
                            strcat(extenso, " um mil ");
                        }
                        else
                        {
                            strcat(extenso, " mil ");
                        }
                    }

                    // coloca o e
                    if (n7 != 0 || n6 != 0 || n5 != 0 || n4 != 0)
                    {
                        if (n3 != 0 && (n2 == 0 && n1 == 0))
                        {
                            strcat(extenso, " e ");
                        }
                        else
                        {
                            strcat(extenso, ", "); //
                        }
                    }

                    // n3
                    if (n3 == 9)
                    {
                        strcat(extenso, "novecentos ");
                    }
                    if (n3 == 8)
                    {
                        strcat(extenso, "oitocentos ");
                    }
                    if (n3 == 7)
                    {
                        strcat(extenso, "setecentos ");
                    }
                    if (n3 == 6)
                    {
                        strcat(extenso, "seicentos ");
                    }
                    if (n3 == 5)
                    {
                        strcat(extenso, "quinhentos ");
                    }
                    if (n3 == 4)
                    {
                        strcat(extenso, "quatrocentos ");
                    }
                    if (n3 == 3)
                    {
                        strcat(extenso, "trezentos ");
                    }
                    if (n3 == 2)
                    {
                        strcat(extenso, "duzentos ");
                    }
                    if (n3 == 1)
                    {
                        if (n2 != 0 || n1 != 0)
                        {
                            strcat(extenso, "cento ");
                        }
                        else
                        {
                            strcat(extenso, "cem ");
                        }
                    }

                    // coloca o e
                    if (n7 != 0 || n6 != 0 || n5 != 0 || n4 != 0)
                    {
                        if (n3 != 0 && (n2 != 0 || n1 != 0))
                        {
                            strcat(extenso, " e ");
                        }
                    }

                    // n2
                    if (n2 == 9)
                    {
                        strcat(extenso, "noventa  ");
                    }
                    if (n2 == 8)
                    {
                        strcat(extenso, "oitenta  ");
                    }
                    if (n2 == 7)
                    {
                        strcat(extenso, "setenta  ");
                    }
                    if (n2 == 6)
                    {
                        strcat(extenso, "sessenta  ");
                    }
                    if (n2 == 5)
                    {
                        strcat(extenso, "cinquenta  ");
                    }
                    if (n2 == 4)
                    {
                        strcat(extenso, "quarenta  ");
                    }
                    if (n2 == 3)
                    {
                        strcat(extenso, "trinta  ");
                    }
                    if (n2 == 2)
                    {
                        strcat(extenso, "vinte  ");
                    }
                    if (n2 == 1)
                    {
                        if (n1 == 0)
                        {
                            strcat(extenso, "dez ");
                        }
                        if (n1 == 9)
                        {
                            strcat(extenso, "dezenove ");
                            n1 = 0;
                        }
                        if (n1 == 8)
                        {
                            strcat(extenso, "dezoito ");
                            n1 = 0;
                        }
                        if (n1 == 7)
                        {
                            strcat(extenso, "desessete ");
                            n1 = 0;
                        }
                        if (n1 == 6)
                        {
                            strcat(extenso, "desesseis ");
                            n1 = 0;
                        }
                        if (n1 == 5)
                        {
                            strcat(extenso, "quinze ");
                            n1 = 0;
                        }
                        if (n1 == 4)
                        {
                            strcat(extenso, "quatorze ");
                            n1 = 0;
                        }
                        if (n1 == 3)
                        {
                            strcat(extenso, "treze ");
                            n1 = 0;
                        }
                        if (n1 == 2)
                        {
                            strcat(extenso, "doze ");
                            n1 = 0;
                        }
                        if (n1 == 1)
                        {
                            strcat(extenso, "onze ");
                            n1 = 0;
                        }
                    }
                    // coloca o e
                    if (n2 != 0 && n1 != 0)
                    {
                        strcat(extenso, "e ");
                    }

                    // n1
                    if (n1 == 9)
                    {
                        strcat(extenso, "nove ");
                    }
                    if (n1 == 8)
                    {
                        strcat(extenso, "oito ");
                    }
                    if (n1 == 7)
                    {
                        strcat(extenso, "sete ");
                    }
                    if (n1 == 6)
                    {
                        strcat(extenso, "seis ");
                    }
                    if (n1 == 5)
                    {
                        strcat(extenso, "cinco ");
                    }
                    if (n1 == 4)
                    {
                        strcat(extenso, "quatro ");
                    }
                    if (n1 == 3)
                    {
                        strcat(extenso, "tres ");
                    }
                    if (n1 == 2)
                    {
                        strcat(extenso, "dois ");
                    }
                    if (n1 == 1)
                    {
                        strcat(extenso, "um ");
                    }

                    printf("\nA quantidade total de cedulas e %d", cedulas);
                    printf("\nA quantidade total de cedulas em extenso e %s", extenso);
                    strcpy(extenso, "");
                }

                break;

            case 4:
                menu = 2;
                break;

            case 5:
                menu = 0;
                break;

            default:
                printf("\nEntrada invalida.");
                break;
            }
        }

        if (menu == 2) // menu abastecer
        {
            printf("\n Bem vindo ao menu abastecer, pressione:\n 0 - Para voltar ao menu gerente \n Ou pressione o valor da cedula que voce quer inserir:\n");
            scanf("%d", &comando);

            switch (comando)
            {
            case 0:
                menu = 1;
                break;

            case 1:
                printf("\nDigite a quantidade de cedulas a serem inseridas: ");
                scanf("%d", &quant);

                if (quant <= 0)
                {
                    printf("\nQuantidade invalida");
                }
                else if ((c1 + quant) > 12800)
                {
                    printf("\nQuantidade acima do limite, o maximo de notas e 12800 e o sistema ja possui %d", c1);
                }
                else
                {
                    c1 += quant;
                    printf("\nAbastecimento concluido, agora o banco possui %d notas de 1", c1);
                }
                break;

            case 2:
                printf("\nDigite a quantidade de cedulas a serem inseridas: ");
                scanf("%d", &quant);

                if (quant <= 0)
                {
                    printf("\nQuantidade invalida");
                }
                else if ((c2 + quant) > 6400)
                {
                    printf("\nQuantidade acima do limite, o maximo de notas e 6400 e o sistema ja possui %d", c2);
                }
                else
                {
                    c2 += quant;
                    printf("\nAbastecimento concluido, agora o banco possui %d notas de 2", c2);
                }
                break;

            case 5:
                printf("\nDigite a quantidade de cedulas a serem inseridas: ");
                scanf("%d", &quant);
                if (quant <= 0)
                {
                    printf("\nQuantidade invalida");
                }
                else if ((c5 + quant) > 3200)
                {
                    printf("\nQuantidade acima do limite, o maximo de notas e 3200 e o sistema ja possui %d", c5);
                }
                else
                {
                    c5 += quant;
                    printf("\nAbastecimento concluido, agora o banco possui %d notas de 5", c5);
                }
                break;

            case 20:
                printf("\nDigite a quantidade de cedulas a serem inseridas: ");
                scanf("%d", &quant);
                if (quant <= 0)
                {
                    printf("\nQuantidade invalida");
                }
                else if ((c20 + quant) > 1600)
                {
                    printf("\nQuantidade acima do limite, o maximo de notas e 1600 e o sistema ja possui %d", c20);
                }
                else
                {
                    c20 += quant;
                    printf("\nAbastecimento concluido, agora o banco possui %d notas de 20", c20);
                }
                break;

            case 50:
                printf("\nDigite a quantidade de cedulas a serem inseridas: ");
                scanf("%d", &quant);
                if (quant <= 0)
                {
                    printf("\nQuantidade invalida");
                }
                else if ((c50 + quant) > 800)
                {
                    printf("\nQuantidade acima do limite, o maximo de notas e 800 e o sistema ja possui %d", c50);
                }
                else
                {
                    c50 += quant;
                    printf("\nAbastecimento concluido, agora o banco possui %d notas de 50", c50);
                }
                break;

            case 150:
                printf("\nDigite a quantidade de cedulas a serem inseridas: ");
                scanf("%d", &quant);
                if (quant <= 0)
                {
                    printf("\nQuantidade invalida");
                }
                else if ((c150 + quant) > 400)
                {
                    printf("\nQuantidade acima do limite, o maximo de notas e 400 e o sistema ja possui %d", c150);
                }
                else
                {
                    c150 += quant;
                    printf("\nAbastecimento concluido, agora o banco possui %d notas de 150", c150);
                }
                break;

            case 300:
                printf("\nDigite a quantidade de cedulas a serem inseridas: ");
                scanf("%d", &quant);
                if (quant <= 0)
                {
                    printf("\nQuantidade invalida");
                }
                else if ((c300 + quant) > 200)
                {
                    printf("\nQuantidade acima do limite, o maximo de notas e 200 e o sistema ja possui %d", c300);
                }
                else
                {
                    c300 += quant;
                    printf("\nAbastecimento concluido, agora o banco possui %d notas de 300", c300);
                }
                break;

            case 350:
                printf("\nDigite a quantidade de cedulas a serem inseridas: ");
                scanf("%d", &quant);
                if (quant <= 0)
                {
                    printf("\nQuantidade invalida");
                }
                else if ((c350 + quant) > 100)
                {
                    printf("\nQuantidade acima do limite, o maximo de notas e 100 e o sistema ja possui %d", c350);
                }
                else
                {
                    c350 += quant;
                    printf("\nAbastecimento concluido, agora o banco possui %d notas de 350", c350);
                }
                break;

            default:
                printf("\nEntrada invalida");
                break;
            }
        }
    }
}