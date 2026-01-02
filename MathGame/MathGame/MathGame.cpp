#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

enum enQuestionLevel { Easy = 1, Mid = 2, Hard = 3, Mix = 4 };
enum enOperationType { Sum = 1, Sub = 2, Mul = 3, Div = 4, mix = 5 };

struct stRoundsInfo
{
	int HowManyRound = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	int NumberOne = 0;
	int NumberTwo = 0;
	int Answer = 0;
	int PlayerAnswer;
	enOperationType OriginalOperationType;
	enQuestionLevel OriginalQuestionType;

};

struct stResultOfGame
{
	int HowManyRound = 0;
	string QuestionLevel;
	string OperationType;
	int HowManyRightAnswer = 0;
	int HowManyWrongAnswer = 0;



};

int Random(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

int ReadNumber()
{
	int Number = 0;

	cin >> Number;
	return Number;
}

int HowManyRound()
{
	int Rounds = 0;

	cout << "How Many Round Do you Want : ";
	cin >> Rounds;
	return Rounds;
}

void QuestionLevel(int& Level)
{


	do
	{
		cout << "Enter The Level Of Question 1[Easy], 2[Medium], 3[Hard], 4[Mix] : ";
		cin >> Level;

	} while (Level < 1 || Level >4);

	Level = (enQuestionLevel)Level;
}

void OperationType(int& Operation)
{


	do
	{
		cout << "Enter The Operation Type Of Question 1[Sum], 2[Sub], 3[Mul], 4[Div], 5[Mix] : ";
		cin >> Operation;

	} while (Operation < 1 || Operation > 5);

	Operation = (enOperationType)Operation;
}

enOperationType RandomOpiration(int OperationType)
{
	if (OperationType == enOperationType::Sum)
		return (enOperationType)1;

	else if (OperationType == enOperationType::Sub)
		return  (enOperationType)2;

	else if (OperationType == enOperationType::Mul)
		return  (enOperationType)3;
	else if (OperationType == enOperationType::Mul)
		return (enOperationType)4;
	else
		return (enOperationType)Random(1, 4);


}

void SetColorforRound(stRoundsInfo RoundInfo)
{
	if (RoundInfo.Answer == RoundInfo.PlayerAnswer)
		system("color 2F");

	else
	{
		cout << "\a";
		system("color 4F");
	}

}

enQuestionLevel RandomLevel(int QuestionLevel)
{
	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		return (enQuestionLevel)1;
		break;
	case enQuestionLevel::Mid:
		return (enQuestionLevel)2;
		break;
	case enQuestionLevel::Hard:
		return (enQuestionLevel)3;
		break;
	default:
		return (enQuestionLevel)Random(1, 3);
		break;


	}
}

int GetNumber(enQuestionLevel QuestionLevel)
{

	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		return Random(1, 10);
		break;
	case enQuestionLevel::Mid:
		return Random(11, 50);
		break;

	default:
		return Random(51, 100);
		break;

	}



}

void EnterSolution(stRoundsInfo& RoundInfo)
{


	if (RoundInfo.PlayerAnswer == RoundInfo.Answer)
	{

		cout << "Right Answer :)\n";
		SetColorforRound(RoundInfo);
	}
	else
	{

		cout << "Wrong Answer :(\n";
		SetColorforRound(RoundInfo);
	}

}

string GetOperationTypeWord(enOperationType OperationType)
{
	string arrOPType[5] = { "+", "-" , "*" , "/", "Mix" };
	return arrOPType[OperationType - 1];
}

void PrintRoudResult(stRoundsInfo& RoundInfo, int RoundNumber)
{

	cout << "\nQuestion [" << RoundNumber << "/" << RoundInfo.HowManyRound << "]\n";
	cout << RoundInfo.NumberOne << endl;
	cout << RoundInfo.NumberTwo << " " << GetOperationTypeWord(RoundInfo.OperationType) << endl;
	cout << "_____________________\n";
	RoundInfo.PlayerAnswer = ReadNumber();

	EnterSolution(RoundInfo);



}

int GetAnswer(stRoundsInfo RoundInfo)
{
	switch (RoundInfo.OperationType)
	{

	case enOperationType::Sum:
		return RoundInfo.NumberOne + RoundInfo.NumberTwo;
		break;
	case enOperationType::Sub:
		return RoundInfo.NumberOne - RoundInfo.NumberTwo;
		break;
	case enOperationType::Mul:
		return RoundInfo.NumberOne * RoundInfo.NumberTwo;
		break;
	default:
		return RoundInfo.NumberOne / RoundInfo.NumberTwo;
		break;

	}



}

string GetQuestionLevelName(enQuestionLevel QuestionLevel)
{
	string arrLevel[4] = { "[Easy]", "[Mid]", "[Hard]", "[Mix]" };
	return arrLevel[QuestionLevel - 1];

}

string Tape(int NumberOfTap)
{
	for (int i = 0; i < NumberOfTap; i++)
	{
		cout << "\t";
	}
	return "";
}

void ShowGameOver(stResultOfGame ResultOfGame)
{
	cout << "\n";
	cout << Tape(2) << "_____________________________________________________________\n\n";

	if (ResultOfGame.HowManyRightAnswer >= ResultOfGame.HowManyWrongAnswer)
	{
		system("color 2F");
		cout << Tape(2) << "                       YouPass :)                           \n";
	}
	else
	{

		system("color 4F");
		cout << Tape(2) << "                       YouFail :(                           \n";
	}
	cout << Tape(2) << "_____________________________________________________________\n";


}

void PrintAnswer(stResultOfGame ResultOfGame)
{
	ShowGameOver(ResultOfGame);
	cout << Tape(2) << "Round Number             : " << ResultOfGame.HowManyRound << endl;
	cout << Tape(2) << "The Level Of Question    : " << ResultOfGame.QuestionLevel << endl;
	cout << Tape(2) << "The Operation Type       : " << ResultOfGame.OperationType << endl;
	cout << Tape(2) << "Number Of Right Answer   : " << ResultOfGame.HowManyRightAnswer << endl;
	cout << Tape(2) << "Number OF Wrong Answer   : " << ResultOfGame.HowManyWrongAnswer << endl;
	cout << Tape(2) << "_____________________________________________________________\n";


}

stResultOfGame FillResultOFGame(stRoundsInfo RoundsInfo, int RightAnswer, int WrongAnswer)
{
	stResultOfGame ResultOfGame;

	ResultOfGame.HowManyRound = RoundsInfo.HowManyRound;
	ResultOfGame.OperationType = GetOperationTypeWord(RoundsInfo.OriginalOperationType);
	ResultOfGame.QuestionLevel = GetQuestionLevelName(RoundsInfo.OriginalQuestionType);
	ResultOfGame.HowManyRightAnswer = RightAnswer;
	ResultOfGame.HowManyWrongAnswer = WrongAnswer;
	PrintAnswer(ResultOfGame);
	return ResultOfGame;

}

stResultOfGame PlayGame()
{
	stRoundsInfo RoundsInfo;
	int RightAnswer = 0, WrongAnswer = 0;
	int Operation = 0;
	int Level = 0;

	RoundsInfo.HowManyRound = HowManyRound();


	QuestionLevel(Level);
	OperationType(Operation);
	RoundsInfo.OriginalQuestionType = (enQuestionLevel)Level;
	RoundsInfo.OriginalOperationType = (enOperationType)Operation;

	for (int GameRound = 1; GameRound <= RoundsInfo.HowManyRound; GameRound++)
	{

		RoundsInfo.QuestionLevel = RandomLevel(Level); ;
		RoundsInfo.OperationType = RandomOpiration(Operation);
		RoundsInfo.NumberOne = GetNumber(RoundsInfo.QuestionLevel);
		RoundsInfo.NumberTwo = GetNumber(RoundsInfo.QuestionLevel);
		RoundsInfo.Answer = GetAnswer(RoundsInfo);

		PrintRoudResult(RoundsInfo, GameRound);

		if (RoundsInfo.Answer == RoundsInfo.PlayerAnswer)
			RightAnswer += 1;
		else
			WrongAnswer += 1;

	}


	return FillResultOFGame(RoundsInfo, RightAnswer, WrongAnswer);


}

void Reset()
{
	system("color 0F");
	system("cls");

}

void Play()
{
	char PlayAgain = 'Y';
	do {

		Reset();
		stResultOfGame GameResult = PlayGame();
		cout << "Do you Wont Play Again Y(yes) N(No) : ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');




}

int main()
{
	srand((unsigned)time(NULL));
	Play();

	return 0;
}