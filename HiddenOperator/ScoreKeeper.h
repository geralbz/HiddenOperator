#pragma once
//Gerald Brown
class ScoreKeeper
{

private:
	int topScore = 0;

public:

	void GainScore(int score)
	{
		topScore += score;
	}
	void UpdateScore(int score)
	{

		topScore = score > topScore ? score : topScore;
	}

	int GetScore() { return topScore; }
	void Clear()
	{
		topScore = 0;
	}
};

