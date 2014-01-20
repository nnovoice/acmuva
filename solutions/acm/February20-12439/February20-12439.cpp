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

int GetNumberOfYearsMultipleOf(int multiple, int startYear, int endYear)
{
    int nNearestStartMultipleYear = 0;
    int nNearestEndMultipleYear = 0;
    int nMultipleYears = 0;
    if ((startYear % multiple) != 0)
        nNearestStartMultipleYear = startYear + (multiple - (startYear % multiple));
    else
        nNearestStartMultipleYear = startYear;

    if ((endYear % multiple) != 0)
        nNearestEndMultipleYear = endYear - (multiple - (endYear % multiple));
    else
        nNearestEndMultipleYear = endYear;

    if (nNearestStartMultipleYear < nNearestEndMultipleYear)
        nMultipleYears = (nNearestEndMultipleYear - nNearestStartMultipleYear) / multiple;

    return nMultipleYears;
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

        startMonthNum = GetMonthNumber(startMonthName);
        endMonthNum   = GetMonthNumber(endMonthName);

        nLeapDays = ((endYear - startYear) / 4);
        if (IsLeapYear(startYear) || IsLeapYear(endYear))
            ++nLeapDays;

        nLeapDays -= GetNumberOfYearsMultipleOf(100, startYear, endYear);
        nLeapDays += GetNumberOfYearsMultipleOf(400, startYear, endYear);

        /// does the date range include or exclude feb 29?
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
        printf("Case %d: %d\n", caseNum, nLeapDays);
    }
    return 0;
}

