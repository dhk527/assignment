#ifndef CALC_H
#define CALC_H
typedef double (*calc)(double, double);

double Add(double, double);
double Sub(double, double);
double Div(double, double);
double Mul(double, double);
double call_calc(calc, double, double);






#endif
