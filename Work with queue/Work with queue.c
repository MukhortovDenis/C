/*
 ============================================================================
 Name        : Work with stack.c
 Author      : Denis Muhortov
 Version     :
 Copyright   :
 Description : Файл чтения: 5 1 * 2 3 + |
                            2 4 +
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


//Структура для строчек(больше 20 символовов не поддерживает, для переноса необходим символ '|'
typedef struct operation {
    char command[20];
    struct operation *next;
}queue;
queue *head_q = NULL;
queue *end_queue = NULL;


typedef struct stack {//Стек , в котором будут добавляться и удаляться значения.
    float elem;
    struct stack *end;
}stack;
stack *head_s = NULL;

char *reading_queue(void){
    if(head_q != NULL) {
        char *data_q;
        data_q = head_q->command;
        head_q = head_q->next;
        return data_q;
    } else{return NULL;}
}

//Функция добавление элемента в очередь
int add_elem_queue(FILE *input){
    queue *temp = malloc(1 * sizeof(queue));
    fgets(temp->command, sizeof(temp->command), input);
    temp->next = NULL;
    if(end_queue != NULL){
        end_queue->next = temp;
        end_queue = temp;
    } else{
        head_q = temp;
        end_queue = temp;
    }
    return 1;
}

//Функция с простыми числами(ничего особенного)
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

//Функция поиска знаков операций
int check(char oper){
    char type_of_operation[5] = {'+', '*', '^', '/', '!'};
    for (int i = 0; i != 5; i++){
        if (oper == type_of_operation[i]){
            return 1;
        }
    }
    return 0;
}

//Функция добавления элементов в head стека
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


int main() {// Основная функция, работа с придаточными функциями
    FILE *input, *output;
    //Срез
    char *kick, *str;
    float element, number1, number2;
    input = fopen("input.txt", "r");
    //Заполнение памяти из input
    if (!feof(input))
    {
        while (!feof(input))
        {
            add_elem_queue(input);
        }
        str = reading_queue();
                while (str != NULL){
                    for(int i = 0; i < 30; i++) {
                        //Знак $ является символом окончания строки
                        if (str[i] == '|') {break;}
                        else{
                            //Проверка. если это операция, то берем два элемента и стэка, проводим операцию
                            //И записываем обратно в стэк
                            if (check(str[i]) == 1) {
                                if (str[i] != '!') {
                                    number2 = del_elem();
                                    number1 = del_elem();
                                } else {
                                    number1 = del_elem();
                                }
                                element = numbers(str[i], number1, number2);
                                add_in_stack(element);
                                i++;
                            } else {
                                if (str[i] == '-' and str[i + 1] == ' ') {
                                    number2 = del_elem();
                                    number1 = del_elem();
                                    element = numbers(str[i], number1, number2);
                                    add_in_stack(element);
                                    i++;
                                } else {
                                    //Установили, что это число. Находим его и добавляем в стэк
                                    //находим длинну среза
                                    int k = i;
                                    //Получаем длинну среза
                                    while (str[k] != ' ') { k++; }
                                    int len_arr = k - i;
                                    //Начинаем заполнение
                                    k = i;
                                    kick = malloc(len_arr * sizeof(char));
                                    for (int p = 0; p < len_arr; p++) {
                                        kick[p] = str[k];
                                        k++;
                                    }
                                    i = k;
                                    element = atof(kick);
                                    add_in_stack(element);}
                            }
                        }
                    }
                    //Читаем следующий элемент
                    str = reading_queue();
                }
                output = fopen("output.txt", "w");
                //записываем результаты
                while (head_s != NULL){
                    element = del_elem();
                    fprintf(output, "Ответ: %.2f\n", element);
                }
                return 1;
            }
            return 0;
        }
