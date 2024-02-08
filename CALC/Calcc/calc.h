#ifndef CALC_H
#define CALC_H
typedef double (*calc)(double, double);
//만약, typedef 안할 시, double (*calc)(double, double)을 써야함.

extern double Add(double, double);
extern double Sub(double, double);
extern double Div(double, double);
extern double Mul(double, double);
//extern double call_calc(double (*calc)(double, double), double, double);
extern void call_calc(calc, double, double);

#endif
