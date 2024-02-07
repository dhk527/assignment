#ifndef CALC_H
#define CALC_H
typedef double (*calc)(double, double);

extern double Add(double, double);
extern double Sub(double, double);
extern double Div(double, double);
extern double Mul(double, double);
//extern double call_calc(double (*calc)(double, double), double, double);
extern void call_calc(calc, double, double);

#endif
