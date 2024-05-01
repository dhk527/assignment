// 테일러 다항식을 사용하는 이유는 complecated 함수를 다항식의 합으로 근사할 수 있기 때문입니다.
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

// 팩토리얼 계산 함수
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    float x = 0.3; // x 값을 (-PI/2, PI/2) 범위 내에서 선택 테일러 급수의 특수해인 멕클레린 급수를 이용.
    int n = 3 ; // 테일러 3rd 다항식의 차수
    float y_floating = 0; // 부동 소수점 형식으로 계산된 결과

	//scanf("%d",&n);

    // 3차 테일러 다항식을 이용하여 sin(x) 근사 
	// Let f(x)=sin(x), x=0
    for (int i = 0; i < (n+1)/2; i++) {
			y_floating += pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
    printf("sin(%.9f) ≈ %.9f\n",pow(-1,i)*x, y_floating); // 부동 소수점 형식으로 출력
    }

    printf("\nsin(%.9f) ≈ %.9f\n",x, y_floating); // 부동 소수점 형식으로 출력
    printf("sin(%.9f) - sin(%.9f)= error : %.9f",x,x, y_floating - sin(x)); // print Error = [sin(x) of tayler Nth serise]-[sin(x)]
    return 0;
}




