#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char operation;
    float a, b, i;
    int n;
    do
    {
                    puts("Vvedite odnu iz operacii: +, -, *, /, ^, !\n Dlya vihoda nazhmite q");
                    scanf("%c", &operation);
                           switch(operation)
                           {
                               case '+':
                                   puts("Vi vibrali operaciyu 'slojenie'.");
                                   puts("Vvedite pervoe znachenie.");
                                   scanf("%f", &a);
                                   puts("Vvedite vtoroe znachenie.");
                                   scanf("%f", &b);
                                   printf("A + B = %f", a + b);
                                   break;
                               case '-':
                                   puts("Vvedite pervoe znachenie 'Vichitanie'.");
                                   scanf("%f", &a);
                                   puts("Vvedite vtoroe znachenie.");
                                   scanf("%f", &b);
                                   printf("A - B = %f", a - b);
                                   break;
                               case '*':
                                   puts("Vvedite pervoe znachenie 'Umnozhenie'.");
                                   scanf("%f", &a);
                                   puts("Vvedite vtoroe znachenie.");
                                   scanf("%f", &b);
                                   printf("A * B = %f", a * b);
                                   break;
                               case '/':
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
                               case '^':
                                   puts("Vi vibrali operaciyu 'Vozvedenie v stepen'.");
                                   puts("Vvedite znachenie.");
                                   scanf("%f", &a);
                                   puts("Vvedite stepen znacheniya.");
                                   scanf("%i", &n);
                                   i = 1;
                                   for (; n > 0; --n)
                                   {
                                       i = i * a;
                                   }
                                   printf("A ^ N = %f", i);
                                   break;
                               case '!':
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
                                           for (n = 1; n <= a; n++)
                                           {
                                               i = i * n;
                                           }
                                       printf("A! = %f", i);
                                       }
                                   break;
                               default:
                                   break;

        }



    } while (operation != 'q');
}
