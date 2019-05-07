

/*
 ============================================================================
 Name        : Calc.c
 Author      : Denis Muhortov
 Version     :
 Copyright   :
 Description : Calculator
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
setvbuf(stdout, NULL, _IONBF, 0);
setvbuf(stderr, NULL, _IONBF, 0);

    float a, b, i;
    int s, n, o, j, g, x = 1, q = 0;
    int value ;
    int *v1;
    int *v2;
    int *v3;
    do
    {
        puts("Start? yes - 1/no - 0");/* Запуск программы*/
                scanf("%i", &o);

        switch(o)
        {
            case 0:
                printf("Vikluchenie");
                break;

            case 1:
                puts("Vvedite kod operacii.\n");/* 1 - Векторы, 2 - арифметика*/
                    scanf("%i", &s);
                           switch(s)
                           {
                               case 1:
                                   puts("Vektornie operacii. Vvedite kod operacii");/* Векторы: 1 - сложение, 2 - вычитание, 3 - скалярное произведение*/
                                   scanf("%i", &j);
                                       switch(j)
                                       {
                                           case 1:
                                               puts("Vi vibrali operaciyu 'slojenie'. ");
                                               puts("Vvedite kollichestvo edinichnih vectorov");
                                               scanf("%i", &value);
                                               v1 = malloc(value * sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati pervogo vectora");
                                               scanf("%i", &v1[r]);
                                               }
                                               v2 = malloc(value*sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati vtorogo vectora");
                                               scanf("%i", &v2[r]);
                                               }
                                               puts("Slojenie vectorov ravno:");
                                               for (int r = 0; r < value; r++)
                                               {
                                               printf("%i; ", v1[r] + v2[r]);
                                                }
                                               free(v1);
                                               free(v2);
                                               break;
                                           case 2:
                                               puts("Vi vibrali operaciyu 'vichetanie'. Pervyi vector - umenshaemyi, vtoroi - vichetaemyi.  ");
                                               puts("Vvedite kollichestvo edinichnih vectorov");
                                               scanf("%i", &value);
                                               v1 = malloc(value * sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati pervogo vectora");
                                               scanf("%i", &v1[r]);
                                               }
                                               v2 = malloc(value*sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati vtorogo vectora");
                                               scanf("%i", &v2[r]);
                                               }
                                               puts("Slojenie vectorov ravno:");
                                               for (int r = 0; r < value; r++)
                                               {
                                               printf("%i; ", v1[r] - v2[r]);
                                               }
                                               free(v1);
                                               free(v2);
                                               break;
                                           case 3:
                                               puts("Vi vibrali operaciyu 'skalyarnoe umnojenie'");
                                               puts("Vvedite kollichestvo edinichnih vectorov");
                                               scanf("%i", &value);
                                               v1 = malloc(value * sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati pervogo vectora");
                                               scanf("%i", &v1[r]);
                                               }
                                               v2 = malloc(value*sizeof(int));
                                               v3 = malloc(value*sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati vtorogo vectora");
                                               scanf("%i", &v2[r]);
                                               }
                                               for (int r = 0; r < value; r++)
                                               {
                                               v3[r] = v1[r] * v2[r];
                                               q = q + v3[r];
                                               }
                                               printf("Proizvedenie ravno: %i", q);
                                               free(v1);
                                               free(v2);
                                               free(v3);
                                       } break;
                               case 2:
                                   puts("Ariphmeticheskie operacii. Vvedite kod operacii");/* 1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - степень, 6 - факториал*/
                                   scanf("%i", &g);
                                       switch(g)
                                       {
                                           case 1:
                                               puts("Vi vibrali operaciyu 'slojenie'.");
                                               puts("Vvedite pervoe znachenie.");
                                               scanf("%f", &a);
                                               puts("Vvedite vtoroe znachenie.");
                                               scanf("%f", &b);
                                               printf("A + B = %f", a + b);
                                               break;
                                           case 2:
                                               puts("Vvedite pervoe znachenie 'Vichitanie'.");
                                               scanf("%f", &a);
                                               puts("Vvedite vtoroe znachenie.");
                                               scanf("%f", &b);
                                               printf("A - B = %f", a - b);
                                               break;
                                           case 3:
                                               puts("Vvedite pervoe znachenie 'Umnozhenie'.");
                                               scanf("%f", &a);
                                               puts("Vvedite vtoroe znachenie.");
                                               scanf("%f", &b);
                                               printf("A * B = %f", a * b);
                                               break;
                                           case 4:
                                               puts("Vvedite pervoe znachenie 'Delenie'.");
                                               scanf("%f", &a);
                                               puts("Vvedite vtoroe znachenie.");
                                               scanf("%f", &b);
                                               if (b == 0)
                                               {
                                                   puts("Error!");
                                               }
                                               else
                                               {
                                                   printf("A / B = %f", a / b);
                                               }
                                               break;
                                           case 5:
                                               puts("Vi vibrali operaciyu 'Vozvedenie v stepen'.");
                                               puts("Vvedite znachenie.");
                                               scanf("%f", &a);
                                               puts("Vvedite stepen znacheniya.");
                                               scanf("%i", &n);
                                               i = 1;
                                               for (; n > 0; n++)
                                               {
                                                   i = i * a;
                                               }
                                               printf("A ^ N = %f", i);
                                               break;
                                           case 6:
                                               puts("Vi vibrali operaciyu 'Factorial'.");
                                               puts("Vvedite znachenie.");
                                               scanf("%f", &a);
                                               if (a == 0)
                                               {
                                                   printf("A! = 1");
                                               }
                                               else
                                               {
                                                   i = 1;
                                                   for (n = 1; n <= a; --n)
                                                   {
                                                       i = i * n;
                                                   }
                                                   printf("A! = %f", i);
                                               }
                                               break;
                                           default:
                                               puts("Error!");
                                               break;

                                       }

                           }
        }
    } while (x > 0);
}

