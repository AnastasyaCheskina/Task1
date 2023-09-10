#include <stdio.h>
#include <math.h>
#include <malloc.h>

double* InputData(int number) //������� ����� ������ ��� ���� ���� �����
{
	double* inputDataArray = calloc(6, sizeof(double));
	if (number == 1)
	{
		double a, b, c;
		printf("������� ������������ a, b, c ����� ������: ");
		scanf_s("%f %f %f",&a,&b,&c);
		inputDataArray[0] = a;
		inputDataArray[1] = b;
		inputDataArray[2] = c;
	}
	else if (number == 2)
	{
		double a1, b1, c1, a2, b2, c2;
		printf("������� ������������ a1, b1, c1 ����� ������: ");
		scanf_s("%f %f %f", &a1, &b1, &c1);
		printf("������� ������������ a2, b2, c2 ����� ������: ");
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
		double n;
		printf("������� �������� n: ");
		scanf_s("%f", &n);
		inputDataArray[0] = n;
	}
	return inputDataArray;
}

void ShowResult(double* outputDataArray, int number) //����� ������ ��� ���� ���� �����
{
	if (number == 1)
	{
		printf("�����: x1 = %f, x2 = %f", outputDataArray[0], outputDataArray[1]);
	}
	else if (number == 2)
	{
		printf("�����: x = %f, y = %f", outputDataArray[0], outputDataArray[1]);
	}
	else if (number == 3)
	{
		printf("�����: P(n) = %f", outputDataArray[0]);
	}
}

void StartTask1(int number) //������ ������ ������ (���������� ���������)
{
	double* inputDataArray = InputData(number);
	double discriminant = (inputDataArray[1] * inputDataArray[1]) - (4 * inputDataArray[0] * inputDataArray[2]);
	if (discriminant > 0 || discriminant == 0)
	{
		double x1 = ((-1 * inputDataArray[1]) + sqrt(discriminant)) / (2 * inputDataArray[0]);
		double x2 = ((-1 * inputDataArray[1]) - sqrt(discriminant)) / (2 * inputDataArray[0]);
		double* answerArray = calloc(2, sizeof(double));
		answerArray[0] = x1;
		answerArray[1] = x2;
		ShowResult(answerArray, number);
	}
	else printf("������ ���");
}

void StartTask2(int number) //������ ������ ������ (������� ���� �������� ���������)
{
	double* inputDataArray = InputData(number);
	double x = (inputDataArray[2] * inputDataArray[4] - inputDataArray[1] * inputDataArray[5]) / (inputDataArray[0] * inputDataArray[4] - inputDataArray[1] * inputDataArray[3]);
	double y = (inputDataArray[0] * inputDataArray[5] - inputDataArray[3] * inputDataArray[2]) / (inputDataArray[0] * inputDataArray[4] - inputDataArray[1] * inputDataArray[3]);
	double* answerArray = calloc(2, sizeof(double));
	answerArray[0] = x;
	answerArray[1] = y;
	ShowResult(answerArray,number);
}

void StartTask3(int number) //������ ������� ������ (������������)
{
	double* inputDataArray = InputData(number);
	double answer = 1;
	for (int i = 1; i < inputDataArray[0]; i++)
	{
		answer *= i;
	}
	double* answerArray = calloc(1, sizeof(double));
	answerArray[0] = answer;
	ShowResult(answerArray, number);
}

int main()
{
	system("chcp 1251>nul");
	printf("1 - ���������� ���������, 2 - ������� ���� �������� ���������, 3 - ������������ (���������)\n������� ����� ��������� ������: ");
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
	default: printf("������ ������ ������ �� ����������");
		break;
	}
	return 0;
}