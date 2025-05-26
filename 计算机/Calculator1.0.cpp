#include <cstdio>

int main(){
    int num1;
    char op;
    int num2;
    int total;
    int stop;
    scanf("%d %c %d",&num1,&op,&num2);
    if(op == '+'){
        total = num1 + num2;
        printf("%d",total);
        scanf("%d",&stop);
    }else if(op == '-'){
        total = num1 - num2;
        printf("%d",total);
        scanf("%d",&stop);
    }else if(op == '*'){
        total = num1 * num2;
        printf("%d",total);
        scanf("%d",&stop);
    }else if(op == '/'){
        total = num1 / num2;
        printf("%d",total);
        scanf("%d",&stop);
    }else{
        printf("Error");
        scanf("%d",&stop);
    }
    return 0;
}