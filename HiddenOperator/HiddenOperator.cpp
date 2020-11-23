// HiddenOperator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Gerald Brown

#include <iostream>
#include "ScoreKeeper.h"
#include "PuzzleMaker.h"
#include "HiddenOperator.h"
#include <string>


int main()
{
	ScoreKeeper sk;
	PuzzleMaker pm;
	std::shared_ptr<ScoreKeeper> skPtr = std::make_shared<ScoreKeeper>(sk);
	std::shared_ptr<PuzzleMaker> pmPtr = std::make_shared<PuzzleMaker>(pm);

	int numbers = 3;
	int currentStreak = 0;
	std::string userInput;
	int userInt;
	bool playing = false;
	std::vector<char> userAns;

	std::string howToPlayStr = "\n  How To Play \nTry to guess the missing operators in the equation shown."
		"The missing operator can be either addition (+), subtraction \n(-), or multiplication(*). Keep in mind that equations are solved left to right in all cases."
		"\nTo guess, list the missing symbols in order and press enter. \nHere is an example. \nQuestion: 2 { } 2 { } 1 = 3 \nInput: *- \n ";

	std::string controlsStr = "Commands(case sensitive): \nend or quit: this quits the program \nnext or n: diplays the next question breaking the streak. \n"
		"ans or answer or a: displays the answer breaking the streak and moving on to the next question. \nreset: delete record for highest streak. \nco: change number of operands in questions"
		"\nscore or s: see current streak. \nh or help: see these instructions again.\n";



	std::cout << "Welcome to Hidden Operator!\n";
	std::cout << "\n" << "Type help or h for instructions" << "\n";

	pmPtr->SetQuestion(numbers);
	pmPtr->PrintQuestion();

	playing = true;
	do
	{
		std::cin >> userInput;

		if (userInput == "h" || userInput == "help")
		{
			std::cout << howToPlayStr << "\n" << controlsStr;
		}
		else

			if (userInput == "end" || userInput == "quit")
			{
				delete& pmPtr;
				delete& skPtr;

				playing = false;
			}
			else

				if (userInput == "next" || userInput == "n")
				{
					pmPtr->SetUpandDisplay(numbers);
				}
		if (userInput == "reset")
		{
			skPtr->Clear();
			std::cout << "Record has been erased." << "\n";
		}

		if (userInput == "ans" || userInput == "a" || userInput == "answer")
		{
			pmPtr->ShowAnswer();
			skPtr->Clear();
		}
		if (userInput == "co")
		{
			std::cout << "Please enter a value between 3 and 6 inclusive." << "\n";
			std::cin >> userInt;
			if (userInt > 2 && userInt <= 6)
			{
				numbers = userInt;
				pmPtr->SetUpandDisplay(numbers);
				skPtr->UpdateScore(currentStreak);
				currentStreak = 0;

			}
			else
			{
				std::cout << "Please enter a value between 3 and 6 inclusive." << "\n";
			}

		}
		else

			if (userInput == "s" || userInput == "score")
			{

				std::cout << "Current Streak: " << currentStreak << " Record:" << sk.GetScore() << "\n";
			}
			else

				if (userInput.size() == numbers - 1)
				{

					if (pmPtr->CheckAnswer(userInput))
					{
						std::cout << "Correct!" << "\n";
						currentStreak++;
						skPtr->UpdateScore(currentStreak);
						std::cout << "Current Streak is " << currentStreak << " Highest Record: " << sk.GetScore() << "\n";
						pmPtr->SetUpandDisplay(numbers);
					}
					else
					{
						std::cout << "Incorrect." << "\n";
						currentStreak = 0;
					}


				}


	} while (playing);



}
