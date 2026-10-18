#include <stdio.h>
#include <string.h>

char zamena(char x){
    	if (x == '(') return ')';
    	if (x == ')') return '(';
    	if (x == '{') return '}';
    	if (x == '}') return '{';
    	if (x == '[') return ']';
    	if (x == ']') return '[';
}

void perevorot(char* copy, char* orig, int index) {
    	if (index < 10) {
        	copy[index] = zamena(orig[9-index]);
        	perevorot(copy, orig, index + 1);
    	} else {
        	copy[10] = '\0';
    	}
}

int main(){
    	char skobki[11];
    	
	do {
        	printf("Введите последовательность из 10 скобок: ");
        	scanf("%10s", skobki);
        
        	if (strlen(skobki) != 10){
            		printf("Нет-нет, давай ка ты введешь 10 скобок\n");
        	}
    	} 
	while (strlen(skobki) != 10);

    	char copy[11];
    	perevorot(copy, skobki, 0);

    	if (strcmp(skobki, copy) == 0){
        	printf("Скобки правильно вложены друг в друга\n");
    	} else {
        	printf("Скобки неправильно вложены друг в друга \t:(\n");
    	}
    	return 0;
}
