#include <iostream>

class Calculator {
	public:
		    // 가상 함수로 선언된 연산 함수
		    virtual double calculate(double a, double b) const = 0;
};

class Add : public Calculator {
	public:
		    double calculate(double a, double b) const override {
				        return a + b;
						    }
};

class Subtract : public Calculator {
	public:
		    double calculate(double a, double b) const override {
				        return a - b;
						    }
};

class Multiply : public Calculator {
	public:
		    double calculate(double a, double b) const override {
				        return a * b;
						    }
};

class Divide : public Calculator {
	public:
		    double calculate(double a, double b) const override {
				        if (b != 0) {
							            return a / b;
										        } else {
													            std::cerr << "Error: Division by zero" << std::endl;
																            return 0.0;  // Handle division by zero
																			        }
						    }
};

int main() {
	    double operand1, operand2;
		    char operation;

			    // 사용자로부터 입력 받기
			    std::cout << "Enter first operand: ";
				    std::cin >> operand1;

					    std::cout << "Enter operation (+, -, *, /): ";
						    std::cin >> operation;

							    std::cout << "Enter second operand: ";
								    std::cin >> operand2;

									    // 사용자가 입력한 연산자에 따라 적절한 클래스 객체 생성
									    Calculator* calculator;
										    switch (operation) {
												        case '+':
															            calculator = new Add();
																		            break;
																					        case '-':
																					            calculator = new Subtract();
																								            break;
																											        case '*':
																											            calculator = new Multiply();
																														            break;
																																	        case '/':
																																	            calculator = new Divide();
																																				            break;
																																							        default:
																																							            std::cerr << "Error: Invalid operation" << std::endl;
																																										            return 1;
																																													    }

											    // 계산 결과 출력
											    double result = calculator->calculate(operand1, operand2);
												    std::cout << "Result: " << result << std::endl;

													    // 동적으로 할당한 객체 메모리 해제
													    delete calculator;

														    return 0;
}

