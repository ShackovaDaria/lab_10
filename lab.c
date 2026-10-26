#include <stdio.h>
#include <math.h>

double fa(double x);
double fb(double x);
double sin_n(double x, int N);
double sin_eps(double x, double eps);

int main() {
    double x, eps;
    int choice, n;

    printf("--- Задание 1 ---\n");
    printf("Введите значение x: ");
    scanf("%lf", &x);

    double val_fa = fa(x);
    double val_fb = fb(x);

    printf("\n>>> Меню выбора расчета \n");
    printf("1. Вывести значения обеих функций\n");
    printf("2. Вывести произведение\n");
    printf("3. Вывести разность квадратов\n");
    printf("4. Вывести удвоенную сумму\n");
    printf("Выберите пункт (1-4): ");
    scanf("%d", &choice);

    if (choice == 1) {
        // значений функций
        printf("fa(x)=%lf, fb(x)=%lf\n", val_fa, val_fb);
    } 
    else if (choice == 2) {
        //произведения
        printf("произведение: %lf * %lf = %lf\n", val_fa, val_fb, val_fa * val_fb);
    } 
    else if (choice == 3) {
        //разности квадратов
        printf("разность квадратов: %lf^2 - %lf^2 = %lf\n", val_fa, val_fb, (val_fa * val_fa) - (val_fb * val_fb));
    } 
    else if (choice == 4) {
        //удвоенной суммы
        printf("удвоенная сумма:  %lf\n", 2.0 * (val_fa + val_fb));
    } 
    else {
        printf("введите число от 1 до 4 \n");
    }


printf("\n--- Задание 2 ---\n");
    printf("Введите x (|x| < 1): ");
    scanf("%lf", &x);

    if (fabs(x) >= 1.0) {
        printf("|x| должно быть меньше 1\n");
        return 1;
    }

    printf("Введите n: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Ошибка: n должно быть >= 1\n");
        return 1;
    }

    printf("Введите eps: ");
    scanf("%lf", &eps);
 if (eps <= 0) {
        printf("Ошибка: eps должно быть > 0\n");
        return 1;
    }
    
    double std_val = asin(x);
    printf("\nЭталон asin(%.4lf) = %.7lf\n", x, std_val);

    printf("\n n |     sin_n    |  отклонение \n");
    printf("--------------------------------\n");
    for (int i = 1; i <= n; i++) {
        double val = sin_n(x, i);
        printf("%2d | %11.7lf | %+11.4le\n", i, val, val - std_val);
    }

    double val_eps = sin_eps(x, eps);
    printf("\nsin_eps = %.7lf, отклонение = %+11.4le\n", val_eps, val_eps - std_val);

    return 0;
}

//1 ф-ция
double fa(double x) {
    double y;
    if (x <= 3.0) {
        y = x * x - 3 * x + 9;
    } else {
        y = 1.0 / (pow(x, 3) + 3);
    }
    return y;
}
//2 ф-ция
double fb(double x) {
    double y;
    y = x * exp(sin(x * x));
    return y;
}

double sin_n(double x, int N) {
    double sum = 0.0;
    double term = x;
    sum += term;

    for (int k = 2; k <= N; k++) {
        term = term * x * x * pow(2.0 * k - 3.0, 2.0) / ((2.0 * k - 2.0) * (2.0 * k - 1.0));
        sum += term;
    }
    return sum;
}

double sin_eps(double x, double eps) {
    double sum = 0.0;
    double term = x;
    sum += term;
    int k = 2;

    while (fabs(term) >= eps) {
        term = term * x * x * pow(2.0 * k - 3.0, 2.0) / ((2.0 * k - 2.0) * (2.0 * k - 1.0));
        sum += term;
        k++;
    }
    return sum;
}
