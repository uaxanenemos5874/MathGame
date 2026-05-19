// This is Math game.
// Date: 17/05/2025, Time: 21:50

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum enLevelGame {Easy = 1, Medium = 2, Hard = 3, Mix = 4};
enum enOperationType {Add = 1, Subtraction = 2, Multiplication = 3, Division = 4, MiX= 5};

struct stInfoGame {

    short Question = 0;
    short FirstNumber = 0;
    short SecondNumber = 0;
    short Sum = 0;
    short AnswerUser = 0;
    enLevelGame Level;
    enOperationType Operator;
    bool Answer;

};

struct stInfoResultGame {

    short NumberOfQuestion = 0;
    string NameQuestionLevel;
    string NameOpType;
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswer = 0;
    bool Pass;

};




// This Numbers Questions.
int HowToManyQus () { 

    int manyQus = 0;
    do {
    cout << "How Many Questions do you want to answer ?";
    cin >> manyQus;
    }
    while(!manyQus);

    return manyQus;

} 

enLevelGame ReadChiosUserLevel () {

    short Chios;

    do {

        cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?";
        cin >> Chios;
    
    }
    while (Chios < 1 || Chios > 4);

    return (enLevelGame)Chios;

}

enOperationType ReadChiosUserOperationType () {

    short Chios;

    do {

        cout << "Enter Question Level [1] Addition, [2] Subtraction, [3] Multiplication, [4] Division, [5] Mix ? ";
        cin >> Chios;
    
    }
    while (Chios < 1 || Chios > 5);

    return (enOperationType)Chios;

}

string LevelName (enLevelGame Chios) {

   string arrLevelGame[4] = {"Easy", "Medium", "Hard", "Mix"}; 

   return arrLevelGame[Chios - 1];

}

string OperatorTypeName (enOperationType Chios) {

    string arrOperationType[5] = {"Addition", "Subtraction", "Multiplication", "Division", "Mix"};
    
    return arrOperationType[Chios - 1];

}

int Random_Number (int From, int To) {

    int RandomNumber;
    RandomNumber = rand () % (To - From + 1) + From;

    return RandomNumber;

}

int NumberLevel (enLevelGame Chios) {



    switch (Chios) {

        case Easy:
        return Random_Number(1, 10);
        break;

        case Medium:
        return Random_Number(10, 50);
        break;

        case Hard:
        return Random_Number(50, 100);
        break;

        case Mix:
        return Random_Number(1, 100);
        break;
    
    }

    return 1;


}

void PrintQuestion (enOperationType OP, short FirstNumber, short SecondNumber) {

    char arrOP[4] = {'+', '-', '*', '/'};

    if (OP == enOperationType::Add) {

        cout << FirstNumber << endl << SecondNumber << " + " << endl;
        cout << endl << "________________" << endl;


    }
    else if (OP == enOperationType::Subtraction) {

        cout << FirstNumber << endl << SecondNumber << " - " << endl;
        cout << endl << "________________" << endl;


    }
    else if (OP == enOperationType::Multiplication) {

        cout << FirstNumber << endl << SecondNumber << " * " << endl;
        cout << endl << "________________" << endl;


    }
    else if (OP == enOperationType::Division) {

        cout << FirstNumber << endl << SecondNumber << " / " << endl;
        cout << endl << "________________" << endl;


    }
    else {
        
        cout << FirstNumber << endl << SecondNumber << arrOP[Random_Number(1, 4) - 1] << endl;
        cout << endl << "________________" << endl;

    
    }


}

bool PassOrFail (short NumberOfRight, short NumberOfWrong) {

    if (NumberOfRight > NumberOfWrong || NumberOfRight == NumberOfWrong)
    return true;
    else
    return false;

}

void PrintFinalResult (bool pass) {

    cout << "______________________________________\n";
    
    if(pass) {

        cout << "Final Result is Pass :-)\n";
    }
    else {

        cout << "Final Result is Fail :-(\n";
    
    }

}

void PrintFinalmRestlGame (stInfoResultGame InfoResultGame) {

    PrintFinalResult(InfoResultGame.Pass);

    cout << "Number Of Question: " << InfoResultGame.NumberOfQuestion << endl;
    cout << "Question Level: " << InfoResultGame.NameQuestionLevel << endl;
    cout << "OpType: " << InfoResultGame.NameOpType << endl;
    cout << "Number Of Right Answer: " << InfoResultGame.NumberOfRightAnswers << endl;
    cout << "Number Of Wrong answer: " << InfoResultGame.NumberOfWrongAnswer << endl << endl; 

    cout << "______________________________________\n";

}
bool TrueSum (short Sum, short AnswerUser) {

    return (Sum == AnswerUser);
 
}

void TrueAnswer (bool Answer) {

    if (Answer == true) {

        system("color 2F");

    }
    else {

         system("color 4F");
    
    }
}

int QuestionSum (enLevelGame Level ,enOperationType OperationType, short FirstNumber, short SecondNumber) {

    short Sum = 0;
    
    PrintQuestion(OperationType, FirstNumber, SecondNumber);
    cin >> Sum;

    return Sum;

}

int CalculationSum (enOperationType Op ,short FirstNumber, short SecondNumber) {

    short Sum = 0;

    switch (Op) {

        case Add:
        Sum = FirstNumber + SecondNumber;
        break;

        case Subtraction:
        Sum = FirstNumber - SecondNumber;
        break;

        case Multiplication:
        Sum = FirstNumber * SecondNumber;
        break;

        case Division:
        Sum = FirstNumber / SecondNumber;
        break;

    }

    return Sum;

}

stInfoResultGame StartQuestion() {

    short NumberOfRight = 0, NumberOfWrong = 0;

    stInfoGame InfoGame;
    stInfoResultGame InfoResultGame;

    InfoGame.Question = HowToManyQus();
    InfoGame.Level = ReadChiosUserLevel();
    InfoGame.Operator = ReadChiosUserOperationType();


    for (int QusNumber = 1; QusNumber <= InfoGame.Question; QusNumber++) {

        short RandomNum = Random_Number(1, 4);

        cout << "Question [" << QusNumber << "/" << InfoGame.Question << "]\n\n" << endl;
        
        InfoGame.FirstNumber = NumberLevel(InfoGame.Level);
        InfoGame.SecondNumber = NumberLevel(InfoGame.Level);


        

       if (InfoGame.Operator == enOperationType::MiX) {

        InfoGame.Sum = CalculationSum((enOperationType)RandomNum , InfoGame.FirstNumber, InfoGame.SecondNumber);
        cout << InfoGame.Sum << endl;
        InfoGame.AnswerUser =  QuestionSum(InfoGame.Level, (enOperationType)RandomNum, InfoGame.FirstNumber, InfoGame.SecondNumber);
        InfoGame.Answer = TrueSum(InfoGame.Sum, InfoGame.AnswerUser);
        TrueAnswer(InfoGame.Answer);

       }
       else {

        InfoGame.Sum = CalculationSum(InfoGame.Operator, InfoGame.FirstNumber, InfoGame.SecondNumber);
        cout << InfoGame.Sum << endl;
        InfoGame.AnswerUser =  QuestionSum(InfoGame.Level, InfoGame.Operator, InfoGame.FirstNumber, InfoGame.SecondNumber);
        InfoGame.Answer = TrueSum(InfoGame.Sum, InfoGame.AnswerUser);
        TrueAnswer(InfoGame.Answer);

    
       }
        

        if (InfoGame.Answer == true) {

            ++NumberOfRight;
        
        }
        else {

            ++NumberOfWrong;
        
        }

       
    InfoResultGame.NumberOfQuestion = InfoGame.Question;
    InfoResultGame.NameQuestionLevel = LevelName(InfoGame.Level);
    InfoResultGame.NameOpType = OperatorTypeName(InfoGame.Operator);
    InfoResultGame.NumberOfRightAnswers = NumberOfRight;
    InfoResultGame.NumberOfWrongAnswer = NumberOfWrong;
    InfoResultGame.Pass = PassOrFail(InfoResultGame.NumberOfRightAnswers, InfoResultGame.NumberOfWrongAnswer);

    }
    
    return InfoResultGame;

}

void RestScreen () {

    system("color 0F");
    system("cls");
    

}

void StartGame () {

    char Again = 'y';

    do {

        RestScreen();
        PrintFinalmRestlGame(StartQuestion());

        cout << "Do you want to play again? Y/N?";
        cin >> Again;  
    
    }
    while (Again == 'y' || Again == 'Y');

}


int main () {

    srand((unsigned)time(NULL));

    StartGame();

    return 0;

}
