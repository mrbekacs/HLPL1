#include <stdio.h>

int is_monotone_decreasing(int* numbers, int length) {
    int result = 1;
    for(int i = 1; i < length; i++) {
        if (!(numbers[i] > numbers[i - 1])){
            return 0;
        }
    }
    return result;
}

int main() {
    while(1){
        int length;
        scanf("%d", &length);
        if (length == 0){
            break;
        }
        int numbers[length];
        for(int j = 0; j < length; j++){
            scanf("%d", &numbers[j]);
        }
        if (is_monotone_decreasing(numbers, length) == 0) {
            printf("False\n");
        } else {
            printf("True\n");
        }
    }
    return 0;
}