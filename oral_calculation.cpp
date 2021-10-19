#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <set>
using namespace std;

int extractGrade(string &grade)
{
    string str1=grade.substr(grade.length()-1);
    int gradenum = stoi(str1);
    return gradenum;
}

double generateEquation(int grade)
{

}

void read(string &grade, int &num_questions)
{

}

void solve(string &grade, int &num_questions)
{
    int grade_num = extractGrade(grade);
    int num_correct = 0;
    int ans;
    for (int i = 0; i < num_questions; i++)
    {
        ans = floor(grade_num * 100.0f + 0.5) / 100.0f;
        int input;
        cin >> input;
        if (ans == input)
        {
            num_correct++;
        }
    }
    if (num_correct == num_questions)
    {
        cout << "end! All right, that's great! Your score is 100." << endl;
    }
    else
    {
        cout << "end! Wrong question, your score is " << (num_correct * 1.0 / num_questions) * 100 << endl;
    }
}

int main()
{
    int num_questions;
    string grade;

    read(grade, num_questions);

    solve(grade, num_questions);

    system("pause");

    return 0;
}
