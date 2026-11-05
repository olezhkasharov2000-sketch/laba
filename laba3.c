#include <stdio.h>
#include <stdlib.h>

int is_integer_string(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
        start += 1;
    }
    
    if (str[start] == '\0') {
        return 0;
    }
    
    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int main(){
    char *N_str = NULL;
    char *M_str = NULL;
    int M, N;
    
    while (1){
        printf("Введите N: ");
        if (scanf("%ms", &N_str) != 1) {
            printf("Ошибка чтения.\n");
            free(N_str);
            continue;
        }
        if (is_integer_string(N_str) && atoi(N_str) > 0) {
            N = atoi(N_str);
            free(N_str);
            break;
        } else {
            free(N_str);
            printf("Число должно быть натуральным!\n");
        }
    }
    
    while (1){
        printf("Введите M: ");
        if (scanf("%ms", &M_str) != 1) {
            printf("Ошибка чтения.\n");
            free(M_str);
            continue;
        }
        if (is_integer_string(M_str) && atoi(M_str) > 0) {
            M = atoi(M_str);
            free(M_str);
            break;
        } else {
            printf("Число должно быть натуральным!\n");
            free(M_str);
        }
    }
    
    float *Matrix = malloc(M * N * sizeof(*Matrix));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char *element = NULL;
            float value;
            
            while (1) {
                printf("Введите элемент [%d][%d]: ", i, j);
                if (scanf("%ms", &element) != 1) {
                    printf("Ошибка чтения.\n");
                    free(element);
                    continue;
                }
                if (is_integer_string(element)) {
                    value = atof(element);
                    free(element);
                    break;
                } else {
                    free(element);
                    printf("Некорректный ввод\n");
                }
            }
            
            Matrix[i * M + j] = value;
        }
    }
    
    printf("\nВаша матрица:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%.2f\t", Matrix[i * M + j]);
        }
        printf("\n");
    }
    
    float sum_pub = 0;
    
    for (int i = 0; i < N; i++) {
        int j = N - 1 - i;
        if (Matrix[i * N + j] < 0){
            sum_pub = sum_pub + Matrix[i * N + j];
        }
    }
    printf("Сумма отрицательных элементов на побочной диагонали: %.2f\n", sum_pub);
    printf("\n");
    
    float max_el = -99999999;
    int num_string = 0;
    
    for (int i = 0; i < N; i++){
        int j = 1;

        if (Matrix[i * N + j] > max_el){
            max_el = Matrix[i * N + j];
            num_string = i;
        }
    }
    printf("Наибольший элемент %.2f второго столбца находится в %d строчке\n", max_el, num_string + 1);    

	
    printf("\nНовая матрица:\n");

    
    for (int i = 0; i < N; i++){
	    for (int j = 0; j < M; j++){
		    if (i == num_string && j == 1){
			Matrix[i * M + j] = sum_pub;
		    }

		    printf("%.2f\t", Matrix[i * M + j]);
	    }
	    printf("\n");
    }
}

