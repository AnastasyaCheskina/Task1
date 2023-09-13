#include <stdio.h>
#include <math.h>
#include <malloc.h>

float* InputData(int number) //функция ввода данных для всех трех задач
{
	float* inputDataArray = calloc(6, sizeof(float));
	if (number == 1)
	{
		float a, b, c;
		printf("Введите коэффициенты a, b, c через пробел: ");
		scanf_s("%f %f %f",&a,&b,&c);
		inputDataArray[0] = a;
		inputDataArray[1] = b;
		inputDataArray[2] = c;
	}
	else if (number == 2)
	{
		float a1, b1, c1, a2, b2, c2;
		printf("Введите коэффициенты a1, b1, c1 через пробел: ");
		scanf_s("%f %f %f", &a1, &b1, &c1);
		printf("Введите коэффициенты a2, b2, c2 через пробел: ");
		scanf_s("%f %f %f", &a2, &b2, &c2);
		inputDataArray[0] = a1;
		inputDataArray[1] = b1;
		inputDataArray[2] = c1;
		inputDataArray[3] = a2;
		inputDataArray[4] = b2;
		inputDataArray[5] = c2;
	}
	else if (number == 3)
	{
		float n;
		printf("Введите значение n: ");
		scanf_s("%f", &n);
		inputDataArray[0] = n;
	}
	return inputDataArray;
}

void ShowResult(float* outputDataArray, int number) //вывод данных для всех трех задач
{
	if (number == 1)
	{
		printf("Ответ: x1 = %f, x2 = %f", outputDataArray[0], outputDataArray[1]);
	}
	else if (number == 2)
	{
		printf("Ответ: x = %f, y = %f", outputDataArray[0], outputDataArray[1]);
	}
	else if (number == 3)
	{
		printf("Ответ: P(n) = %f", outputDataArray[0]);
	}
}

void StartTask1(int number) //запуск первой задачи (квадратное уравнение)
{
	float* inputDataArray = InputData(number);
	float discriminant = (inputDataArray[1] * inputDataArray[1]) - (4 * inputDataArray[0] * inputDataArray[2]);
	if (discriminant > 0 || discriminant == 0)
	{
		float x1 = ((-1 * inputDataArray[1]) + sqrt(discriminant)) / (2 * inputDataArray[0]);
		float x2 = ((-1 * inputDataArray[1]) - sqrt(discriminant)) / (2 * inputDataArray[0]);
		float* answerArray = calloc(2, sizeof(float));
		answerArray[0] = x1;
		answerArray[1] = x2;
		ShowResult(answerArray, number);
	}
	else printf("Корней нет");
}

void StartTask2(int number) //запуск второй задачи (система двух линейных уравнений)
{
	float* inputDataArray = InputData(number);
	float x = (inputDataArray[2] * inputDataArray[4] - inputDataArray[1] * inputDataArray[5]) / (inputDataArray[0] * inputDataArray[4] - inputDataArray[1] * inputDataArray[3]);
	float y = (inputDataArray[0] * inputDataArray[5] - inputDataArray[3] * inputDataArray[2]) / (inputDataArray[0] * inputDataArray[4] - inputDataArray[1] * inputDataArray[3]);
	float* answerArray = calloc(2, sizeof(float));
	answerArray[0] = x;
	answerArray[1] = y;
	ShowResult(answerArray,number);
}

void StartTask3(int number) //запуск третьей задачи (перестановки)
{
	float* inputDataArray = InputData(number);
	float answer = 1;
	for (int i = 1; i <= inputDataArray[0]; i++)
	{
		answer *= i;
	}
	float* answerArray = calloc(1, sizeof(float));
	answerArray[0] = answer;
	ShowResult(answerArray, number);
}

int main()
{
	system("chcp 1251>nul");
	printf("1 - квадратное уравнение, 2 - система двух линейных уравнений, 3 - перестановки (факториал)\nВведите номер выбранной задачи: ");
	int number;
	scanf_s("%d", &number);
	switch (number)
	{
	case 1: StartTask1(number);
		break;
	case 2: StartTask2(number);
		break;
	case 3: StartTask3(number);
		break;
	default: printf("Такого номера задачи не существует");
		break;
	}
	return 0;
}