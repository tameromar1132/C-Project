#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum enSelect { Stone = 1, Paper = 2, Scissor = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enSelect PlayerSelect;
    enSelect ComputerSelect;
    enWinner WhoWinInRound;
    string WinnerName = "";
};

struct stResultOfGame
{
    short RoundNumber = 0;
    int NumberWinningforPlyer = 0;
    int NumberWinningforComputer = 0;
    int NumberWinningforDraw = 0;
    enWinner WhoWinInGame;
    string NameOfWinner = "";

};

int Random(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enSelect PlayerSelect()
{
    int Select = 0;
    do
    {
        cout << "Enter Your Choise 1(Stone), 2(Paper), 3(Scissor) : ";
        cin >> Select;


    } while (Select < 1 || Select >3);

    return (enSelect)Select;

}

void SetColor(enWinner Winner)
{
    if (Winner == enWinner::Player1)
        system("color 2F");

    else if (Winner == enWinner::Computer)
    {
        cout << "\a";
        system("color 4F");
    }
    else
        system("color 6F");

}

short RoundNumber()
{
    short Round;
    do
    {
        cout << "Enter Round Number From 1 To 10 : ";
        cin >> Round;
    } while (Round < 1 || Round>10);

    return Round;

}

enSelect ComputerSelect()
{
    return  (enSelect)Random(1, 3);
}

enWinner WinnerInRound(stRoundInfo RoundResult)
{

    if (RoundResult.ComputerSelect == RoundResult.PlayerSelect)
    {
        return enWinner::Draw;
    }

    switch (RoundResult.PlayerSelect)
    {
        //case1
    case enSelect::Stone:
        if (RoundResult.ComputerSelect == enSelect::Paper)
            return enWinner::Computer;
        break;
        //case2
    case enSelect::Paper:
        if (RoundResult.ComputerSelect == enSelect::Scissor)
            return enWinner::Computer;
        break;
        //case3
    case enSelect::Scissor:
        if (RoundResult.ComputerSelect == enSelect::Stone)
            return enWinner::Computer;
        break;
    }

    return enWinner::Player1;
}

string GetWinnerName(enWinner Winner)
{
    string arrWinner[3] = { "[Player1]", "[Computer]", "[Draw]" };
    return arrWinner[Winner - 1];

}

string GetSelectName(enSelect Select)
{
    string arrSelect[3] = { "[Stone]", "[ Paper]", "[Scissor]" };
    return arrSelect[Select - 1];

}

void PrintRoundResult(stRoundInfo RoundInfo, int Rounds)
{


    cout << "\n____________ Round [" << Rounds << "] ____________\n\n";

    cout << "Player Select   : " << GetSelectName(RoundInfo.PlayerSelect) << endl;
    cout << "Computer Select : " << GetSelectName(RoundInfo.ComputerSelect) << endl;
    cout << "Who Win         : " << RoundInfo.WinnerName << endl;
    cout << "\n__________________________________\n";
    SetColor(RoundInfo.WhoWinInRound);


}

enWinner WhoWinGame(int ComputerWins, int PlayerWins)
{
    if (ComputerWins == PlayerWins)
        return enWinner::Draw;


    else if (PlayerWins > ComputerWins)
        return enWinner::Player1;


    else
        return enWinner::Computer;




}

string Tape(int NumberOfTap)
{
    for (int i = 0; i < NumberOfTap; i++)
    {
        cout << "\t";
    }
    return "";
}

void ShowGameOver()
{
    cout << "\n";
    cout << Tape(2) << "_____________________________________________________________\n";
    cout << Tape(2) << "                       +GameOver+                            \n";
    cout << Tape(2) << "_____________________________________________________________\n";


}

void PrintGameResult(stResultOfGame GameResult)
{
    ShowGameOver();
    cout << Tape(2) << "Number Of Round  : " << GameResult.RoundNumber << endl;
    cout << Tape(2) << "Player1 Winning  : " << GameResult.NumberWinningforPlyer << endl;
    cout << Tape(2) << "Computer Winning : " << GameResult.NumberWinningforComputer << endl;
    cout << Tape(2) << "Draw Winning     : " << GameResult.NumberWinningforDraw << endl;
    cout << Tape(2) << "Who Win in Game  : " << GameResult.NameOfWinner << endl;

}

stResultOfGame FillGameResults(short RoundNumber, int ComputerWins, int PlayerWins, int Draws)
{

    stResultOfGame GameResult;
    GameResult.RoundNumber = RoundNumber;
    GameResult.NumberWinningforPlyer = PlayerWins;
    GameResult.NumberWinningforComputer = ComputerWins;
    GameResult.NumberWinningforDraw = Draws;
    GameResult.WhoWinInGame = WhoWinGame(ComputerWins, PlayerWins);
    GameResult.NameOfWinner = GetWinnerName(GameResult.WhoWinInGame);
    PrintGameResult(GameResult);
    return GameResult;
}







stResultOfGame PlayGame()
{
    stRoundInfo Round;
    int ComputerWins = 0, PlayerWins = 0, Draws = 0;

    Round.RoundNumber = RoundNumber();
    for (int i = 1; i <= Round.RoundNumber; i++)
    {
        Round.PlayerSelect = PlayerSelect();

        Round.ComputerSelect = ComputerSelect();

        Round.WhoWinInRound = WinnerInRound(Round);

        Round.WinnerName = GetWinnerName(Round.WhoWinInRound);

        if (Round.WhoWinInRound == enWinner::Computer)
            ComputerWins += 1;

        else if (Round.WhoWinInRound == enWinner::Player1)
            PlayerWins += 1;
        else
            Draws += 1;

        PrintRoundResult(Round, i);
    }

    return FillGameResults(Round.RoundNumber, ComputerWins, PlayerWins, Draws);

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