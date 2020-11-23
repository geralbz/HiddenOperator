#pragma once
#include <vector>
#include <list>
#include <ctime>
#include <string>
#include <iostream>
#include <random>
//Gerald Brown

class PuzzleMaker
{

private:

	int iRand = (rand() % 10) + 1;
	int answer = 0;
	int operands = 3;

	std::vector<int> numbers;
	enum  OPERATION { ADD = 0, SUBTRACT = 1, MULTIPLY = 2 };
	std::vector<OPERATION> operators;
	std::vector<OPERATION> answeredOperators;

	int GetRandInt()
	{
		int i = (rand() % 10);

		if ((rand() % 100) > 64)
		{
			i *= -1;
		}
		return i;

	}

	OPERATION GetRandOperation()
	{
		//roll between 1 and 3;
		int o = 0;
		o = (rand() % 4) + 1;

		switch (o)
		{
		case 1:

			return SUBTRACT;

		case 2:

			return MULTIPLY;

		default:

			return ADD;
		}
	}

	int PerformOperation(int a, int b, OPERATION op)
	{

		switch (op)
		{
		case ADD:
			return a + b;
			break;

		case SUBTRACT:
			return a - b;
			break;

		case MULTIPLY:
			return a * b;
			break;

		default:
			answer = -999;
			break;
		}
	}

	char OpToSign(OPERATION op)
	{

		switch (op)
		{
		case ADD:
			return '+';

		case SUBTRACT:
			return '-';

		case MULTIPLY:
			return '*';

		default:
			return 'z';
		}
	}

	OPERATION SignToOp(char c)
	{

		switch (c)
		{
		case '+':
			return ADD;

		case '-':
			return SUBTRACT;


		case '*':
			return MULTIPLY;

		default:
			return ADD;

		}
	}

	void SetAnswer()
	{

		for (size_t i = 0; i < operators.size(); i++)
		{
			answer = PerformOperation(answer, numbers[i + 1], operators[i]);
		}
	}



public:

	void ShowAnswer()
	{
		std::cout << "The answer was ";

		for (size_t i = 0; i < operators.size(); i++)
		{
			std::cout << numbers[i] << " {" << OpToSign(operators[i]) << "} ";
		}
		std::cout << numbers[numbers.size() - 1] << " = " << answer << "\n";
		SetUpandDisplay(operands);
	}

	std::vector<int> GetNumbs()
	{
		return numbers;
	}

	std::vector<char> GetSigns()
	{
		std::vector<char> signs;
		for (size_t i = 0; i < operators.size(); i++)
		{
			signs.push_back(OpToSign(operators[i]));
		}
		return signs;
	}

	void SetQuestion(int operands = 3)
	{
		srand((unsigned int)time(0));
		if (operands < 3)
		{
			operands = 3;
		}
		numbers.clear();


		for (int i = 0; i < operands; i++)
		{
			numbers.push_back(GetRandInt());
		}
		for (int i = 0; i < operands - 1; i++)
		{
			operators.push_back(GetRandOperation());
		}
		answer = numbers[0];

		SetAnswer();



	}
	void PrintQuestion()
	{
		for (size_t i = 0; i < numbers.size(); i++)
		{
			std::cout << numbers[i] << " ";
			if (i < operators.size())
			{

				std::cout << "{ } ";
			}
		}
		std::cout << " = " << answer << "\n";
	}
	int GetAnswer()
	{

		return answer;
	}

	int GetOperationsSize() { return operators.size(); }
	void Clear()
	{

		answer = 0;
		operators.clear();
		numbers.clear();

	}

	void SetUpandDisplay(int n)
	{
		operands = n;
		std::cout << "\n";
		Clear();
		SetQuestion(n);
		PrintQuestion();
	}

	bool CheckAnswer(std::string userInputs)
	{

		char c;
		answeredOperators.clear();
		int playerSum = numbers[0];

		for (size_t i = 0; i < userInputs.size(); i++)
		{
			c = userInputs[i];
			if (c == '+' || c == '-' || c == '*')
			{

				answeredOperators.push_back(SignToOp(userInputs[i]));

			}
			else
			{
				std::cout << "Please only enter a valid response.";
				return false;
			}
		}

		for (size_t i = 0; i < answeredOperators.size(); i++)
		{
			playerSum = PerformOperation(playerSum, numbers[i + 1], answeredOperators[i]);
		}
		std::cout << "Your answer is " << playerSum << "\n";
		return playerSum == answer;
	}
};

