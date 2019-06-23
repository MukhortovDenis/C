/*
 ============================================================================
 Name        : Work with stack.c
 Author      : Denis Muhortov
 Version     :
 Copyright   :
 Description : Файл чтения: 5 1 * 2 3 + | 2 4 +
               Файл вывода: Ответ: 0.00 -избавиться от пустого ответа не смог ):
                            Ответ: 6.00
                            Ответ: 5.00
                            Ответ: 5.00
               Читаемая запись калькулятором в input возможна только в виде польской нотации
               Знак | - означает переход на новую строку, т.к структура строк поддерживает всего 20 знаков
               Векторные операции отсутствуют
               Поддерживаются операции с числами: +, -, *, /, ^, !.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>


//Строчки
typedef struct operation {
    char command[20];
    struct operation *next;
}oper;


typedef struct stack {//Стек
    float elem;
    struct stack *end;
}stack;
stack *head_s = NULL;

//Функция с простыми числами
float numbers(char command, float number1, float number2){
    float q;
    float result;
    switch (command){
        case '+':
            result = number1 + number2;
            return result;
        case '-':
            result = number1 - number2;
            return result;
        case '*':
            result = number1 * number2;
            return result;
        case '^':
            result = number1;
            if (number2 != 0){
                for (int i = 1; i < number2; i++){
                    number1 = number1 * result;
                }
                return number1;
            } else{
                number1 = 1;
                return number1;
            }


        case '/':
            result = number1 / number2;
            return result;
        case '!':
            q = 1;
            for(int i = 1; i<=number1; i++){q = q * i;}
            result = q;
            return result;
    }return 0;

}

//Добавление списка
void add_element(oper *current, FILE *input){
    oper *temp_data = malloc(1 * sizeof(oper));
    fgets(temp_data->command, sizeof(temp_data->command), input);
    temp_data->next = NULL;
    current->next = temp_data;
}
//Функция поиска знаком операций
int check(char oper){
    char type_of_operation[5] = {'+', '*', '^', '/', '!'};
    for (int i = 0; i != 5; i++){
        if (oper == type_of_operation[i]){
            return 1;
        }
    }
    return 0;
}

//Функция добавления элементов в head`а стека
void add_in_stack(float element){
    stack *temp_s = malloc(1* sizeof(stack));
    temp_s->elem = element;
    if (head_s == NULL){
        temp_s->end = NULL;
        head_s = temp_s;
    } else{
        temp_s->end = head_s;
        head_s = temp_s;
    }
}
//Функция удаление элементов из head`а стека
float del_elem(){
    if(head_s != NULL) {
        stack *temp;
        float data;
        temp = head_s;
        head_s = head_s->end;
        data = temp->elem;
        free(temp);
        return data;
    }return 0;
}


int main() {
    FILE *input, *output;
    //Указатели для списка операций
    oper *head, *current;
    //Срез
    char *kick;
    float element, number1, number2;
    input = fopen("input.txt", "r");
    //Заполнение памяти из input
    if (!feof(input)){
        head_s = NULL;
        //Добавление строк
        head = malloc(1 * sizeof(oper));
        fgets(head->command, sizeof(head->command), input);
        head->next = NULL;
        current = head;
        while (!feof(input))
        {
            add_element(current, input);
            current = current->next;
        }
        current = head;
        while (current != NULL)
        {
            for(int i = 0; i < 20; i++)
                {
                if (current->command[i] == '|')
                {
                    puts("break");
                    break;
                }
                else
                {
                    if (check(current->command[i]) == 1)
                    {
                        if (current->command[i] != '!')
                        {
                            number2 = del_elem();
                            number1 = del_elem();
                        }
                        else
                        {
                            number1 = del_elem();
                        }
                        element = numbers(current->command[i], number1, number2);
                        add_in_stack(element);
                        i++;
                    }
                    else
                    {
                        if (current->command[i] == '-' and current->command[i + 1] == ' ')
                        {
                            number2 = del_elem();
                            number1 = del_elem();
                            element = numbers(current->command[i], number1, number2);
                            add_in_stack(element);
                            i++;
                        }
                        else
                        {
                            int k = i;
                            while (current->command[k] != ' ')
                            {
                                k++;
                            }
                            int len_arr = k - i;
                            k = i;
                            kick = malloc(len_arr * sizeof(char));
                            for (int p = 0; p < len_arr; p++)
                            {
                                kick[p] = current->command[k];
                                k++;
                            }
                            i = k;
                            element = atof(kick);
                            add_in_stack(element);
                        }
                    }
                }
            }
            current = current->next;
        }
        output = fopen("output.txt", "w");
        while (head_s != NULL)
        {
            element = del_elem();
            fprintf(output, "Ответ: %.2f\n", element);
        }
        return 1;
    }
    return 0;
}
