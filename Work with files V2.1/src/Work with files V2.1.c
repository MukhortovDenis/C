/*
 ============================================================================
 Name        : 0.c
 Author      : Denis Muhortov
 Version     :
 Copyright   : 
 Description : Файл чтения: v + 2 1 1 -8 -2(input.txt)
               Файл записи: (1 1) + (-8 -2) = (-7 -1)(output.txt)
               Для выполнения операции необходимо знать порядок выполнения работы калькулятора,
               при вводе в input.txt имеются возможные варианты:
               v - операции с векторами,
               s - операции с простыми числами
               Дальше необходимо выбрать тип операции, где:
               + - cложение(для векторов и чисел)
               - - вычитание(для векторов и чисел)
               * - умножение(для вектором и чисел)
               / - деление(для чисел)
               ^ - возведение в степень(для чисел)
               ! - факториал(для чисел)
               Выбрав тип, для 2 векторов необходимо указать количество единичных векторов, после написать на сколько умножить каждый для этих векторов.
               Для чисел выбрать 2 числа.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int main(void) {//Обьявляем переменные и дескрипторы
    int n, r;
    float result;
    float number1;
    float number2;
    float q = 0;
    int *v1;
    int *v2;
    int *v3;
    int value = 0;
    char type_of_operation = 0;
    int x = 0;
    char type = 0;
    FILE *InFile;
    FILE *OutFile;
    do//Начало цикла
       {
                   InFile = fopen("input.txt", "r");//Указываем на работу с двумя файлами
                   OutFile = fopen("output.txt", "w");
                       fscanf(InFile ,"%c", &type);//Берем 1 значение из input, для этого предварительно вписываем значение v или s
                              switch(type)
                              {
                                  case 'v'://Векторы
                                      fscanf(InFile ," %c", &type_of_operation);
                                          switch(type_of_operation)//Тип операции предварительно вписываем в input
                                          {
                                              case '+'://Сложение
                                                  fscanf(InFile," %i", &value);//Количество единичных векторов указываем в input
                                                  v1 = malloc(value * sizeof(int));
                                                  fprintf(OutFile, "(");
                                                  for (r = 0; r < value; r++)
                                                  {
                                                  fscanf(InFile, " %i", &v1[r]);//Калькулятор читает значения длин первого вектора, записанных раннее в input
                                                  if ( r != value - 1){
                                                  fprintf(OutFile, "%i", v1[r]);
                                                  }
                                                  else {
                                                  fprintf(OutFile, " %i)", v1[r]);
                                                  }
                                                  }
                                                  fprintf(OutFile, " + ");
                                                  v2 = malloc(value*sizeof(int));//Калькулятор читает значения длин второго вектора, записанных раннее в input
                                                  fprintf(OutFile, "(");
                                                  for (r = 0; r < value; r++)
                                                  {
                                                  fscanf(InFile ," %i", &v2[r]);
                                                  if ( r != value - 1){
                                                  fprintf(OutFile, "%i", v2[r]);
                                                  }
                                                  else {
                                                  fprintf(OutFile, " %i)", v2[r]);
                                                  }
                                                  }
                                                  fprintf(OutFile, " = ");
                                                  puts("Proverte file");//Данные записаны в output
                                                  fprintf(OutFile, "(");
                                                  for (r = 0; r < value; r++)
                                                  {
                                                  if (r != value - 1){
                                                  fprintf(OutFile ,"%i", v1[r] + v2[r]);
                                                  }
                                                  else {
                                                  fprintf(OutFile ," %i)", v1[r] + v2[r]);
                                                      }
                                                   }
                                                  free(v1);
                                                  free(v2);
                                                  break;
                                              case '-'://Вычитание(Проходит аналогично сложению)
                                                  fscanf(InFile ," %i", &value);
                                                  v1 = malloc(value * sizeof(int));
                                                  fprintf(OutFile, "(");
                                                  for (r = 0; r < value; r++)
                                                  {
                                                  fscanf(InFile, " %i", &v1[r]);
                                                  if ( r != value - 1){
                                                  fprintf(OutFile, "%i", v1[r]);
                                                  }
                                                  else {
                                                  fprintf(OutFile, " %i)", v1[r]);
                                                  }
                                                  }
                                                  fprintf(OutFile, " - ");
                                                  v2 = malloc(value*sizeof(int));
                                                  fprintf(OutFile, "(");
                                                  for (r = 0; r < value; r++)
                                                  {
                                                  fscanf(InFile, " %i", &v2[r]);
                                                  if ( r != value - 1){
                                                  fprintf(OutFile, "%i", v2[r]);
                                                  }
                                                  else {
                                                  fprintf(OutFile, " %i)", v2[r]);
                                                  }
                                                  }
                                                  fprintf(OutFile, " = ");
                                                  fprintf(OutFile, "(");
                                                  puts("Proverte file");
                                                  for (r = 0; r < value; r++)
                                                  {
                                                  if (r != value - 1){
                                                  fprintf(OutFile ," %i", v1[r] - v2[r]);
                                                  }
                                                  else {
                                                  fprintf(OutFile ," %i)", v1[r] - v2[r]);
                                                  }
                                                  }
                                                  free(v1);
                                                  free(v2);
                                                  break;
                                              case '*'://Скалярное умножение
                                                  fscanf(InFile ," %i", &value);
                                                  v1 = malloc(value * sizeof(int));
                                                  fprintf(OutFile, "(");
                                                  for (r = 0; r < value; r++)
                                                  {
                                                  fscanf(InFile ," %i", &v1[r]);
                                                  if ( r != value - 1){
                                                  fprintf(OutFile, "%i", v1[r]);
                                                  }
                                                  else {
                                                  fprintf(OutFile, " %i)", v1[r]);
                                                  }
                                                  }
                                                  v2 = malloc(value*sizeof(int));
                                                  v3 = malloc(value*sizeof(int));
                                                  fprintf(OutFile, " * ");
                                                  fprintf(OutFile, "(");
                                                  for (r = 0; r < value; r++)
                                                  {
                                                  fscanf(InFile ," %i", &v2[r]);
                                                  if ( r != value - 1){
                                                  fprintf(OutFile, "%i", v2[r]);
                                                  }
                                                  else {
                                                  fprintf(OutFile, " %i)", v2[r]);
                                                  }
                                                  }
                                                  fprintf(OutFile, " = ");
                                                  for (r = 0; r < value; r++)
                                                  {
                                                  v3[r] = v1[r] * v2[r];
                                                  q = q + v3[r];
                                                  }
                                                  fprintf(OutFile,"%f", q);//Ответ будет в виде одного числа
                                                  puts("Proverte file");
                                                  free(v1);
                                                  free(v2);
                                                  free(v3);
                                                  break;
                                          } break;

                                  case 's'://простые числа
                                      fscanf(InFile ," %c", &type);
                                          switch(type)
                                          {
                                              case '+':
                                                  fscanf(InFile," %f", &number1);//пишим числа в input
                                                  fprintf(OutFile, "%f ", number1);
                                                  fscanf(InFile," %f", &number2);
                                                  fprintf(OutFile,"+ %f", number2);
                                                  fprintf(OutFile," = %f", number1 + number2);
                                                  puts("Proverte file");//проверяем output
                                                  break;
                                              case '-':
                                                  fscanf(InFile," %f", &number1);
                                                  fprintf(OutFile, "%f ", number1);
                                                  fscanf(InFile," %f", &number2);
                                                  fprintf(OutFile,"- %f", number2);
                                                  fprintf(OutFile," = %f", number1 - number2);
                                                  puts("Proverte file");
                                                  break;
                                              case '*':
                                                  fscanf(InFile," %f", &number1);
                                                  fprintf(OutFile, "%f ", number1);
                                                  fscanf(InFile," %f", &number2);
                                                  fprintf(OutFile,"* %f", number2);
                                                  fprintf(OutFile," = %f", number1 * number2);
                                                  puts("Proverte file");
                                                  break;
                                              case '/':
                                                  fscanf(InFile," %f", &number1);
                                                  fprintf(OutFile, "%f", number1);
                                                  fscanf(InFile," %f", &number2);
                                                  fprintf(OutFile," / %f ", number2);
                                                  puts("Proverte file");
                                                  if (number2 == 0)
                                                  {
                                                      puts("Error!");
                                                  }
                                                  else
                                                  {
                                                      fprintf(OutFile,"= %f", number1 / number2);
                                                  }
                                                  break;
                                              case '^':
                                                  fscanf(InFile," %f", &number1);
                                                  fprintf(OutFile, "%f", number1);
                                                  fscanf(InFile," %f", &number2);
                                                  fprintf(OutFile," ^ %f", number2);
                                                  result = 1;
                                                  for (; number2 > 0; number2++)
                                                  {
                                                      result = result * number1;
                                                  }
                                                  fprintf(OutFile," = %f", result);
                                                  puts("Proverte file");
                                                  break;
                                              case '!':
                                                  fscanf(InFile," %f", &number1);
                                                  fprintf(OutFile, "%f! =", number1);
                                                  if (number1 == 0)
                                                  {
                                                      fprintf(OutFile," 1");
                                                  }
                                                  else
                                                  {
                                                      result = 1;
                                                      for (n = 1; n <= number1; --n)
                                                      {
                                                          result = result * n;
                                                      }
                                                      fprintf(OutFile," %f", result);
                                                  }puts("Proverte file");
                                                  break;
                                              default:
                                                  puts("Error!");
                                                  break;}
                              }

           fclose(InFile);
           fclose(OutFile);
       } while (x > 0);
}
