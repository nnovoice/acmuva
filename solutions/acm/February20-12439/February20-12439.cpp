#include <stdio.h>

int GetMonthNumber (char* month)
{
    switch (month[0]) {
    case 'J':
        if (month[1] == 'a') return 1;
        else if (month[2] == 'n') return 6;
        else return 7;
        break;
    case 'F':
        return 2;
        break;
    case 'M':
        if (month[2] == 'r')
            return 3;
        else return 5;
    case 'A':
        if (month[1] == 'p') return 4;
        else return 8;
        break;
    case 'S':
        return 9;
        break;
    case 'O':
        return 10;
        break;
    case 'N':
        return 11;
        break;
    case 'D':
        return 12;
        break;
    default:
        return -1;
        break;
    }
    return -1;
}

bool IsLeapYear (int year)
{
    bool isLeap = false;
    if (year % 4 == 0) {
        if ((year % 100) != 0) {
            isLeap = true;
        }
        else {
            if ((year % 400) == 0) {
                isLeap = true;
            }
        }
    }
    return isLeap;
}

int main()
{
    int nCases = 0;
    char startMonthName[15] = {'\0'};
    int startMonthNum = 0;
    int startMonthDay = 0;
    int startYear = 0;

    char endMonthName[15] = {'\0'};
    int endMonthNum = 0;
    int endMonthDay = 0;
    int endYear = 0;

    int nLeapDays = 0;

    scanf("%d", &nCases);
    for (int caseNum = 1; caseNum <= nCases; ++caseNum) {
        scanf("%s %d, %d", startMonthName, &startMonthDay, &startYear);
        scanf("%s %d, %d", endMonthName, &endMonthDay, &endYear);

        //printf("Debug: %s %d, %d\n", startMonthName, startMonthDay, startYear);
        //printf("Debug: %s %d, %d\n", endMonthName, endMonthDay, endYear);

        if ((startYear % 4) != 0) {
            for (int j = 1; j < 4; ++j) {
                startYear += j;
                if (startYear % 4 == 0) break;
            }
        }

        nLeapDays = 0;
        for (int year = startYear; year <= endYear; year += 4) {
            if ((year % 100) == 0) {
                if ((year % 400) == 0) {
                    ++nLeapDays;
                }
            }
            else {
                ++nLeapDays;
            }
        }

        startMonthNum = GetMonthNumber(startMonthName);
        endMonthNum   = GetMonthNumber(endMonthName);
        //printf("Debug: start month num= %d\n", startMonthNum);
        //printf("Debug: end month num= %d\n", endMonthNum);

        /// does the date range include feb 29?
        if (startYear == endYear && IsLeapYear(startYear) != 0) {
            if (startMonthNum < 2) {
                if (endMonthNum < 2) {
                    nLeapDays = 0;
                }
                else if (endMonthNum > 2) {
                    nLeapDays = 1;
                }
                else {
                    if (endMonthDay == 29)
                        nLeapDays = 1;
                    else
                        nLeapDays = 0;
                }
            }
            else if (startMonthNum > 2) {
                nLeapDays = 0;
            }
            else {
                if (endMonthNum < 2) {
                    nLeapDays = 0;
                }
                else if (endMonthNum > 2) {
                    nLeapDays = 1;
                }
                else {
                    if (endMonthDay == 29)
                        nLeapDays = 1;
                    else
                        nLeapDays = 0;
                }
            }
        }
        else {
            if (IsLeapYear(startYear)) {
                if (startMonthNum > 2)
                    --nLeapDays;
            }
            if (IsLeapYear(endYear)) {
                if (endMonthNum < 2)
                    --nLeapDays;
                else if (endMonthNum == 2) {
                    if (endMonthDay < 29)
                        --nLeapDays;
                }
            }
        }
        printf("Case %d: %d\n", caseNum, nLeapDays);
    }
    return 0;
}

