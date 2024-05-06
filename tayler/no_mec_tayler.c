//// 테일러 다항식을 사용하는 이유는 complecated 함수를 다항식의 합으로 근사할 수 있기 때문입니다.

#include <stdio.h>
#include <math.h>

// 함수 정의: f(x) = sin(x) 
float factorial(int n) 
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

float func(float x) {
    return sin(x);
}

// 수치 미분 함수 (1차 미분)
float first_derivative(float (*f)(float), float x, float dx) {
    return (f(x + dx) - f(x - dx)) / 2*dx; // Centered Divided Difference
}

// 수치 미분 함수 (2차 미분)
float second_derivative(float (*f)(float), float x, float dx) {
    return (f(x + dx) - 2 * f(x) + f(x - dx)) / (dx * dx); // Centered Divided Difference
}

// 수치 미분 함수 (3차 미분)
float third_derivative(float (*f)(float), float x, float dx) {
    return (f(x + 2 * dx) - 2 * f(x + dx) + 2 * f(x - dx) - f(x - 2 * dx)) / (2 * pow(dx, 3)); // Centered Divided Difference
}

int main() {
    float x, a; // 미분을 수행할 점
	printf("input x-value, Differentiation point: ");
	scanf("%f %f",&x, &a);
    float dx = 0.0001; // C 코드에서 너무 작은 값을 분모로 사용하면 반올림 오차(round-off error)가 발생할 가능성이 높아집니다. 특히, 부동 소수점 수를 다룰 때 발생하는 문제입니다.
					   // 반올림 오차는 부동 소수점 수를 사용하여 실수를 근사할 때 발생하는 오차를 의미합니다. 컴퓨터에서는 실수를 표현할 때 유한한 비트 수를 사용하므로, 실수 값을 정확하게 표현할 수 없습니다. 이로 인해 실제 값과 부동 소수점으로 표현된 값 사이에는 차이가 발생할 수 있습니다. 
					   // 가장 흔한 반올림 오차는 컴퓨터가 부동 소수점 수를 표현할 때 소수점 이하의 값을 근사하는 과정에서 발생합니다. 예를 들어, 소수점 이하 자리수가 제한된 경우, 더 정확한 값을 표현할 수 없기 때문에 실제 값에 가장 가까운 근사치를 선택합니다. 이 때 선택된 근사치가 원래 값과 다를 수 있으며, 이 차이를 반올림 오차라고 합니다. 
					   // 4byte(float)를 가지고 숫자 표현을 할 때, 자리수가 한정되어 있다보니 모든 실수를 다 연속적으로 표현할 수 없다. 따라서 컴퓨터가 표현할 수 없는 값을 반올림하여 사용하게 되어 생긴다. 
	
	float first_gradient, second_gradient, third_gradient; // 1, 2, 3차 미분값
	float y_floating = 0;

	// 1차 미분을 사용하여 함수를 미분
    first_gradient = first_derivative(func, a, dx);
	printf("1st derivative at %.10f: %.10f\n", a, first_gradient);

    // 2차 미분을 사용하여 함수를 미분
    second_gradient = second_derivative(func, a, dx);
	printf("2nd derivative at %.10f: %.10f\n", a, second_gradient);
	
	// 3rd order
    third_gradient = third_derivative(func, a, dx); 
	printf("3rd derivative at %.10f: %.10f\n", a, third_gradient);

	// Taylor 2차 차수를 이용한 근사값 계산
    y_floating = func(a) + first_gradient * (x - a) + second_gradient * pow((x - a), 2) / factorial(2) + third_gradient*pow(( x - a ), 3) / factorial(3);
    printf("\nsin(%.9f) ≈ %.9f\n", x, y_floating); // 부동 소수점 형식으로 출력
    printf("Error (sin(%.9f) - Taylor approximation): %.9f\n", x, sin(x) - y_floating); // 오차 출력
    return 0;
}
