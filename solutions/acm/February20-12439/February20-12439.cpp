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
        if (((year % 100) == 0) && ((year % 400) == 0))
            isLeap = true;
        else {
            if ((year % 100) != 0)
                isLeap = true;
        }
    }
    return isLeap;
}

int main()
{
    int nCases = 0;
    char startMonth[15] = {'\0'};
    int startMonthNum = 0;
    int startMonthDay = 0;
    int startYear = 0;

    char endMonth[15] = {'\0'};
    int endMonthNum = 0;
    int endMonthDay = 0;
    int endYear = 0;

    int nLeapYears = 0;
    int nLeapDays = 0;

    scanf("%d", &nCases);
    for (int caseNum = 1; caseNum <= nCases; ++caseNum) {
        scanf("%s %d, %d", startMonth, &startMonthDay, &startYear);
        scanf("%s %d, %d", endMonth, &endMonthDay, &endYear);

        if ((startYear % 4) != 0) {
            for (int j = 1; j < 4; ++j) {
                startYear += j;
                if (startYear % 4 == 0) break;
            }
        }

        for (int year = startYear; year <= endYear; year += 4) {
            if (IsLeapYear(year)) ++nLeapYears;
        }

        startMonthNum = GetMonthNumber(startMonth);
        endMonthNum   = GetMonthNumber(endMonth);
        nLeapDays = 0;

        if (startYear == endYear && IsLeapYear(startYear)) {
            /// does the date range include feb 29?
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
                }
            }
        }
        else {
            nLeapDays = nLeapYears;
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
        printf("%d\n", nLeapDays);
    }

    return 0;
}

