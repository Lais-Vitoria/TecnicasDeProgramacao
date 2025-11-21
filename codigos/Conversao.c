#include <stdio.h>
#include <locale.h>

float celsiusParaFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {

    setlocale(LC_ALL, "pt-BR.UTF-8");

    float celsius;

    printf("\nEntre com o graus em  celsius: ");
    scanf("%f", &celsius);

    printf("\n%.2f°C é igual a %.2f°F", celsius, celsiusParaFahrenheit(celsius));

}
