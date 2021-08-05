//
//  main.c
//  Linear congruential method
//
//  Created by Павел Гришутенко on 05.08.2021.
//

#include <stdio.h>

//нет смысла брать m за 2; по остатку вичислется минимальное значение
int getMinM(const int *priviosNumbers){
    int maxNum = 0;
    // с 1 потому что первое число может быть задано человеком
    for(int i = 1; i <4; i++){
        if (priviosNumbers[i] > maxNum){
            maxNum =priviosNumbers[i];
        }
    }
    return maxNum+1;
}
short getNextNumber(const int *priviosNumbers){
    short nextNumber = -1;
    int m, a = 0, c = 0;
    int c1, c2; //используются для записи с % m в проверочных функциях
    for (m = getMinM(priviosNumbers); m <= 65535; m++){
        for(a = 0; a < 1000; a++){
            //в c находится c mod m, а это константа, котороя поможет при проверке
            c = priviosNumbers[1] - (a * priviosNumbers[0]) % m;
            
            // m нужно прибавить к отрицательному значению, пример:
            // ax = 100, c = 21, m = 8;
            // ax % m = 4,  c % m = 5; next x = 4+5 % m = 1
            // если из 1 - 4 будет -3 это и есть наше с % m, но видно что оно != 5
            // поэтому -3+m == 5, справедливо только для отрицательных чисел
            if (c < 0) c+=m;
            
            c1 = priviosNumbers[2] - (a * priviosNumbers[1]) % m;
            if (c1 < 0) c1+=m;
            c2 = priviosNumbers[3] - (a * priviosNumbers[2]) % m;
            if (c1 < 0) c2+=m;
            
            // если все выражения дают одинаковое значение c % m, то мы нашли a, c, m.
            if (c1 == c && c2 == c)
            {
                nextNumber = ((a * priviosNumbers[3]) % m + c) % m;
                break;
            }
        }
        if (nextNumber > -1){
            break;
        }
    }
    printf("a = %d, c = %d, m = %d \n", a, c, m);
    return nextNumber;
}
int main(int argc, const char * argv[]) {
    const int privios4numbers[] = {157,  5054, 25789, 13214};
    int n = getNextNumber(privios4numbers); // ожидание 16605
    printf("%d \n", n);
    return 0;
}
