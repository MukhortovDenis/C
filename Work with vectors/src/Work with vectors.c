#include <stdio.h>
#include <stdlib.h>

int main(void)//Для выбора работы с векторами введите v, c числами - s;
              //Команды для векторов: 1 - сложение, 2 - вычитание; 3 - скалярное умножение
{             //Комнады для чисел: 1 - сложение, 2 -вычитание, 3 - умножение, 4 - деление,
              // 5 - возведение в степень, 6 - факториал;
              //Для выхода выполните до конца операцию и введите q
    char operation;
    float a, b, i, e;
    int n, v, s;
    int value ;
    float *v1;
    float *v2;
    float *v3;
    do{

                puts("Vvedite kod operacii.\n");/* v - Векторы, s - арифметика, q -выход*/
                    scanf("%c", &operation);
                           switch(operation)
                           {
                               case 'v':
                                   puts("Vektornie operacii. Vvedite kod operacii");/* Векторы: + - сложение, - - вычитание, * - скалярное произведение*/
                                   scanf("%i", &v);
                                       switch(v)
                                       {
                                           case 1:
                                               puts("Vi vibrali operaciyu 'slojenie'. ");
                                               puts("Vvedite kollichestvo edinichnih vectorov");
                                               scanf("%i", &value);
                                               v1 = malloc(value * sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati pervogo vectora");
                                               scanf("%f", &v1[r]);
                                               }
                                               v2 = malloc(value*sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati vtorogo vectora");
                                               scanf("%f", &v2[r]);
                                               }
                                               puts("Slojenie vectorov ravno:");
                                               for (int r = 0; r < value; r++)
                                               {
                                               printf("%f; ", v1[r] + v2[r]);
                                                }
                                               free(v1);
                                               free(v2);
                                               break;
                                           case '2':
                                               puts("Vi vibrali operaciyu 'vichetanie'. Pervyi vector - umenshaemyi, vtoroi - vichetaemyi.  ");
                                               puts("Vvedite kollichestvo edinichnih vectorov");
                                               scanf("%i", &value);
                                               v1 = malloc(value * sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati pervogo vectora");
                                               scanf("%f", &v1[r]);
                                               }
                                               v2 = malloc(value*sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati vtorogo vectora");
                                               scanf("%f", &v2[r]);
                                               }
                                               puts("Slojenie vectorov ravno:");
                                               for (int r = 0; r < value; r++)
                                               {
                                               printf("%f; ", v1[r] - v2[r]);
                                               }
                                               free(v1);
                                               free(v2);
                                       }break;
                                           case 3:{
                                               puts("Vi vibrali operaciyu 'skalyarnoe umnojenie'");
                                               puts("Vvedite kollichestvo edinichnih vectorov");
                                               scanf("%i", &value);
                                               v1 = malloc(value * sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati pervogo vectora");
                                               scanf("%f", &v1[r]);
                                               }
                                               v2 = malloc(value*sizeof(int));
                                               v3 = malloc(value*sizeof(int));
                                               for (int r = 0; r < value; r++)
                                               {
                                               puts("Vvedite koordinati vtorogo vectora");
                                               scanf("%f", &v2[r]);
                                               }
                                               for (int r = 0; r < value; r++)
                                               {
                                               v3[r] = v1[r] * v2[r];
                                               e = e + v3[r];
                                               }
                                               printf("Proizvedenie ravno: %f", e);
                                               free(v1);
                                               free(v2);
                                               free(v3);
                                           }break;
                               case 's':
                                   puts("Ariphmeticheskie operacii. Vvedite kod operacii");/* 1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - степень, 6 - факториал*/
                                   scanf("%i", &s);
                                       switch(s)
                                       {
                                           case 1 :
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
                                                   for (n = 1; n <= a; ++n)
                                                   {
                                                       i = i * n;
                                                   }
                                                   printf("A! = %f", i);
                                               }
                                               break;

                                       }

                           }

    }while ( operation != 'q');

}
