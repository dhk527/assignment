#ifndef CALC_H
#define CALC_H
typedef double (*calc)(double, double);// 함수를 가리키는 포인터로, 동적으로 함수를 호출하거나 함수를 다루는 데 사용.
//만약, typedef 안할 시, double (*calc)(double, double)을 써야함.

double Add(double, double);
double Sub(double, double);
double Div(double, double);
double Mul(double, double);

//double call_calc(double (*calc)(double, double), double, double);
void call_calc(calc, double, double);

#endif
