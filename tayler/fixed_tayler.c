// 테일러 다항식을 사용하는 이유는 complecated 함수를 다항식의 합으로 근사할 수 있기 때문입니다.
#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define PI 3.14159265358979323846

#define float_to_Fixed(x) (x * (float)(1<<Q_value))
#define Fixed_to_float(x) (x / (float)(1<<Q_value))
#define Q_value 15 // Q15 (Texas Instrumnets Notation) 1/2^15 resolution
#define K (1 << Q_value-1 ) // Rounding : mid valuese are rounded up

// 팩토리얼 계산 함수
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int16_t q_add(int16_t a, int16_t b)
{
	int16_t result;
	int32_t tmp;

	tmp = (int32_t)a + (int32_t)b;
	if(tmp > 0x7FFF)				
		tmp = 0x7FFF;
	if(tmp < -1 * 0x8000)
		tmp = -1 * 0x8000;

	result = (int16_t)tmp;
	return a+b;
}

int16_t q_sub(int16_t a, int16_t b)
{
	return a-b;
}

int16_t sat16(int32_t x)
{
	if (x > 0x7FFF)
		return 0x7FFF;
	else if (x < -0x8000)
		return -0x8000;
	else
		return (int16_t)x;
}

int16_t q_mul(int16_t a, int16_t b)
{
	int16_t result;
	int32_t temp;

	temp = (int32_t)a * (int32_t)b; //result type is operannd's type
									//Rounding: mid values are rounded up
	temp +=K;
	result = sat16(temp >> Q_value);
	return result;
}

int16_t q_div(int16_t a, int16_t b)
{
	//pre-multiply by the base (Upscale to Q16 so that the result will be in Q8 fomrat)
	int32_t temp = ((int32_t)a );
	//Rounding: mid values are rounded up (down for negative values).
	//Or Compare most significatnt bits i.e if (((temp >> 31 ) & 1) == ((b >> 15 ) & 1 ))
	if ((temp >= 0 && b >=0) || (temp < 0 && b < 0))
		temp += b/2;
	else
		temp -= b/2;
	
	return (int16_t)(temp/b);
}

int main() {
	
    float f = 0.707; // x 값을 (-PI/2, PI/2) 범위 내에서 선택 테일러 급수의 특수해인 멕클레린 급수를 이용
	int x = float_to_Fixed(f); // fixed - input
	printf("float_to_Fixed(%.9f) :  %.9d\n", f, x);
	printf("Fixed_to_float(%.9d) : %.9f\n",x,f);
	printf("(double)f : %.9f\n",(double)f);

    int y_fixed = 0; // fixed point
	float y_floating = 0; // float point 

	y_fixed = q_sub(x, q_div((q_mul(q_mul(x,x),x)), factorial(3)));
	y_floating = Fixed_to_float(y_fixed);
	
	printf("\n y_fixed %.16d",y_fixed);

    printf("\nsin(%.9f) ≈ %.9f\n",f, y_floating); // 부동 소수점 형식으로 출력
    printf("sin(%.9f) - sin(%.9f)= error : %.9f",f,f, y_floating - sin(f)); // print Error = [sin(x) of tayler Nth serise]-[sin(x)]
    return 0;
}




