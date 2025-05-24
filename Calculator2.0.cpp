#include <cstdio>
#include <cmath>

int main() {
    float num1, num2, total;
    char op; // 用于存储操作符

    while (true) {
        printf("/Please enter the first expression: ");
        scanf("%f %s %f", &num1, &op, &num2); // 输入格式为：数字 操作符 数字
        // 根据操作符计算结果
        if (op == '+') {
            total = num1 + num2;
        } else if (op == '-') {
            total = num1 - num2;
        } else if (op == '*') {
            total = num1 * num2;
        } else if (op == '/') {
            total = num1 / num2;
        } else if (op == '%') {
            total = fmod(num1, num2);
        }else if(op == 'b'){
            return 0; // 退出程序
        }else if(op == '!'){
            for(int i = 1; i <= num1; i++){
                total *= i;
            }
        }else {
            printf("/Invalid operator!\n");
            continue; // 重新输入
        }
            while(true){
                printf("/Please enter the next expression: ");
                printf("%.2f",total);
                printf(" ");
                scanf("%s %f",&op,&num2); // 输入格式为：操作符 数字
                // 根据操作符计算结果
                if (op == '+') {
                    total = total + num2;
                } else if (op == '-') {
                    total = total - num2;
                } else if (op == '*') {
                    total = total * num2;
                } else if (op == '/') {
                    total = total / num2;
                } else if (op == '%') {
                    total = fmod(total, num2);
                } else if (op == 'b') {
                    return 0; // 退出程序
                } else if (op == 'e') {
                    break; // 退出循环
                } else {
                    printf("/Invalid operator!\n");
                    continue; // 重新输入
                }
            }
        }
    return 0;
}