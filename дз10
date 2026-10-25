#include <stdio.h>


float area(float a, float h);
void draw(int h,char sim);
float get_h();
float get_a();

int main() {
    int choice;
    char sim;
    printf("--- дз ---\n");
    printf("1. площадь\n2. определение\n3. нарисовать\n");
    printf("выберите число от 1 до 3: ");
    scanf("%d", &choice);

    if (choice == 1) {
        float h = get_h();
        float a = get_a();
        printf("Площадь: %.2f\n", area(a, h));
    } 
    else if (choice == 2) {
        printf("равнобедренный треугольник — это треугольник, у которого две стороны равны.\n");
    } 
    else if (choice == 3) {
        printf("введите символ: ");
        scanf(" %c",&sim);
        draw((int)get_h(),sim);
    } 
    else {
        printf("неверный выбор.\n");
    }

    return 0;
}


float get_h() {
    float h;
    printf("введите высоту h: ");
    scanf("%f", &h);
    return h;
}

float get_a() {
    float a;
    printf("введите основание a: ");
    scanf("%f", &a);
    return a;
}

float area(float a, float h) {
    return 0.5f * a * h;
}

void draw(int h,char sim) {
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < h - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            if (j == 0 || j == 2 * i - 2 || i == h) {
                printf("%c",sim);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
