/*
 ============================================================================
 Name        : Work with list.c
 Author      : Denis Muhortov
 Version     :
 Copyright   : 
 Description : Файл чтения: v + 2 1 1 -8 -2(input.txt)
               Файл записи: ( 1.00  1.00 ) + ( -8.00  -2.00 } = ( -7.00  -1.00 )(output.txt)
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



typedef struct list{
    char operation;
    char type_of_operation;
    int value;
    float *number1;
    float *number2;
    struct list *next;
} input_data;
typedef struct another_list{
    float *result;
    struct another_list *next_result;
}output_data;

float *vectors(char type_of_operation, int value, float *number1, float *number2)
{
float *result_v;
    switch (type_of_operation)
    {
    case '+':
        result_v = malloc(value * sizeof(float));
        for (int i = 0; i < value; i++)
        {
        result_v[i] = number1[i] + number2[i];
        }
        return result_v;
    case '-':
        result_v = malloc(value * sizeof(float));
        for (int i = 0; i < value; i++)
        {
        result_v[i] = number1[i] - number2[i];
        }
        return result_v;
    case '*':
        result_v = malloc(1 * sizeof(float));

        float q = 0;
        for (int i = 0; i < value; i++)
        {
        q = q + (number1[i] * number2[i]);
        }
    }
    return number1;
    return number2;
    free(number1);
    free(number2);
    free(result_v);
}


float *numbers(char type_of_operation, float *number1, float *number2)
{
float *result_n;
float q = 1;
result_n = malloc(1*sizeof(float));
    switch (type_of_operation)
    {
    case '+':
        result_n[0] = number1[0] + number2[0];
        return result_n;
    case '-':
        result_n[0] = number1[0] - number2[0];
        return result_n;
    case '*':
        result_n[0] = number1[0] * number2[0];
        return result_n;
    case '^':
        result_n[0] = number1[0];
        if (number2[0] != 0){
            for (int i = 1; i < number2[0]; i++)
            {
            number1[0] = number1[0] + result_n[0];
            }
            return number1;
        }
        else
        {
            number1[0] = 1;
            return number1;
        }
    case '/':
        result_n[0] = number1[0] / number2[0];
        return result_n;
    case '!':
        for(int i = 1; i<=number1[0]; i++){q = q * i;
        }
        result_n[0] = q;
        return result_n;
    }
    return number1;
    return number2;
    free(number1);
    free(number2);
    free(result_n);
}

float *addnumb(FILE *input, int value){ //Добавление числа
    float *numb;
    numb = malloc(value * sizeof(float));
    for(int i = 0;i < value;i++)
    {
        fscanf(input,"%f", &numb[i]);
    }
    return numb;
}

void addelement(input_data *current, FILE *input)
{
    input_data *tmp = malloc(1 * sizeof(input_data));
    //Добавление в структуру. Тут все правильно и работает. Честно
    fscanf(input, " %c %c", &tmp->operation, &tmp->type_of_operation);
    if (tmp->operation == 'v') { fscanf(input, " %i", &tmp->value);}
    else
    {
        tmp->value = 1;
    }
    if (tmp->operation != '!')
    {
        tmp->number1 = addnumb(input, tmp->value);
        tmp->number2 = addnumb(input, tmp->value);
    }
    else
    {
        tmp->number1 = addnumb(input, tmp->value);
        tmp->number2 = NULL;
    }
    tmp->next = NULL;
    current->next = tmp;
}

void addelement_res(output_data *current_res, input_data *current)
{
    output_data *tmp_res = malloc(1 * sizeof(output_data));
    if (current->operation == 'v')
    {
        tmp_res->result = vectors(current->type_of_operation, current->value, current->number1, current->number2 );
    }
    else
    {
        tmp_res->result = numbers(current->operation, current->number1, current->number2);
    }
    tmp_res->next_result = NULL;
    current_res->next_result = tmp_res;
}




int main()
{
    FILE *input, *output;
    input_data *head, *current; //Указатели для списка с данными. На начало и на текущий элемент
    output_data *head_result, *current_result; //Аналогично для списка с ответами
    input = fopen("input.txt", "r"); //Открываем файл, который находится в рабочей среде в папке сmake-build-debug
    if (!feof(input))
    {
        head = malloc(1 * sizeof(input_data)); //Выделяем память для головы списка(первого элемента)
        fscanf(input, " %c %c", &head->operation, &head->type_of_operation);
        //записываем отдельно данные для 1 элемента
        if (head->operation == 'v') { fscanf(input, " %i", &head->value);
        }
        else
        {
            head->value = 1;
        }
        if (head->type_of_operation != '!') {
            head->number1 = addnumb(input, head->value);
            head->number2 = addnumb(input, head->value);
        }
        else
        {
            head->number1 = addnumb(input, head->value);
            head->number2 = NULL;
        }
        //Копируем указатели и добавляем элементы до тех пор, пока файл не закочнится
        current = head;
        while (!feof(input))
        {
            addelement(current, input);
            current = current->next;
        }
        //Выделение памяти на список для вывода
        head_result = malloc(sizeof(output_data));
        current = head;
        //Выбор функции:
        if (current->operation == 'v')
        {
            head_result->result = vectors(current->type_of_operation, current->value, current->number1, current->number2);
        }
        else
        { head_result->result = numbers(current->type_of_operation, current->number1, current->number2); }
        head_result->next_result = NULL;
        current = current->next;
        current_result = head_result;
        while (current != NULL)
        {
            addelement_res(current_result, current);
            current = current->next;
            current_result = current_result->next_result;
        }
        current = head;
        current_result = head_result;
        fclose(input);
        output = fopen("output.txt", "w");
        while (current != NULL)//Запись ответа в output
        {
            if (current->operation == 'v')
            {
                fprintf(output, "Ответ: (");
                for (int i = 0; i < current->value; i++)
                {
                    fprintf(output, " %.2f ", current->number1[i]);
                }
                fprintf(output, ") %c (", current->type_of_operation);
                for (int i = 0; i < current->value; i++)
                {
                    fprintf(output, " %.2f ", current->number2[i]);
                }
                fprintf(output, ") = ");
                if (current->type_of_operation != '*')
                {
                    fprintf(output, "(");
                    for (int i = 0; i < current->value; i++) { fprintf(output, " %.2f ", current_result->result[i]);
                    }
                    fprintf(output, ")");
                }
                else
                {
                    fprintf(output, " %.2f", current_result->result[0]);
                }
            }
            else
            {
                fprintf(output, "Ответ: %.2f", current_result->result[0]);
           }
            current = current->next;
            current_result = current_result->next_result;
        }
        fclose(output);
    }
    return 0;
}

