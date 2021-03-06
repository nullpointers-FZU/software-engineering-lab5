#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
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
    double ans = 0;
    int num1;
    int num2;
    int random_operation_index;
    string opChar[4] = {"+", "-", "*", "/"};
    if (grade == 1 || grade == 2)
    {
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        random_operation_index = (rand() % 2);
        switch (random_operation_index)
        {
        case 0:
            printf("%d + %d = ?\n", num1, num2);
            ans = num1 + num2;
            break;
        case 1:
            printf("%d - %d = ?\n", num1, num2);
            ans = num1 - num2;
            break;
        }
    }
    else if (grade == 3 || grade == 4)
    {
        num1 = rand();
        num2 = rand();
        random_operation_index = (rand() % 4);
        switch (random_operation_index)
        {
        case 0:
            printf("%d+%d = ?\n", num1, num2);
            ans = num1 + num2;
            break;
        case 1:
            printf("%d-%d = ?\n", num1, num2);
            ans = num1 - num2;
            break;
        case 2:
            printf("%d*%d = ?\n", num1, num2);
            ans = num1 * num2;
            break;
        case 3:
            printf("%d/%d = ?\n", num1, num2);
            ans = num1 / num2;
            break;
        }
    }
    else
    {
        double num1 = (double)(rand()) / RAND_MAX * INT_MAX;
        double num2 = (double)(rand()) / RAND_MAX * INT_MAX;
        random_operation_index = (rand() % 4);
        switch (random_operation_index)
        {
        case 0:
            printf("%lf+%lf = ?\n", num1, num2);
            ans = num1 + num2;
            break;
        case 1:
            printf("%lf-%lf = ?\n", num1, num2);
            ans = num1 - num2;
            break;
        case 2:
            printf("%lf*%lf = ?\n", num1, num2);
            ans = num1 * num2;
            break;
        case 3:
            printf("%lf/%lf = ?\n", num1, num2);
            ans = num1 / num2;
            break;
        }
    }
    return ans;
}

void read(string &grade, int &num_questions)
{
    cout << "Please enter your grade?" << endl;
    cin >> grade >> grade;
    //puts("");
    cout << "Please enter the number of questions?" << endl;
    cin >> num_questions;
}

void solve(string &grade, int &num_questions)
{
    int grade_num = extractGrade(grade);
    int num_correct = 0;
    int ans;
    for (int i = 0; i < num_questions; i++)
    {
        ans = floor(generateEquation(grade_num) * 100.0f + 0.5) / 100.0f;
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
