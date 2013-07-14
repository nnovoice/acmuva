#define MAXCOURSES 5
#define MAXCOURSESARRLEN 16
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    map<string, int> coursesMap;
    vector<int> coursesScores;
    int nFrosh = 0;
    int courses[MAXCOURSES] = {0};
    char coursesArr[MAXCOURSESARRLEN] = {' '};
    char course[4];
    int numFroshTakingPopularCourses = 0;
    int mostPopularCourseScore = 0;

    freopen ("C:\\data\\personal\\programming\\acm\\input_files\\Conformity11286\\input.txt", "r", stdin);

    while (cin >> nFrosh) {
        if (nFrosh == 0) break;

        coursesMap.clear();
        numFroshTakingPopularCourses = 0;

        for (int i = 0; i < nFrosh; ++i) {
            memset (coursesArr, '\0', sizeof(char) * MAXCOURSESARRLEN);

            for (int j = 0; j < MAXCOURSES; ++j) {
                cin >> courses[j];
            }

            sort (courses, courses + MAXCOURSES);

            for (int j = 0; j < MAXCOURSES; ++j) {
                sprintf(course, "%d", courses[j]);
                strcat (coursesArr, course);
            }

            coursesMap[coursesArr] += 1;
        }

        coursesScores.clear();
        map<string, int>::iterator coursesMapIter = coursesMap.begin();
        map<string, int>::iterator coursesMapIterEnd = coursesMap.end();
        for (; coursesMapIter != coursesMapIterEnd; ++coursesMapIter) {
            coursesScores.push_back((*coursesMapIter).second);
        }

        sort (coursesScores.begin(), coursesScores.end());

        numFroshTakingPopularCourses = 0;
        mostPopularCourseScore = coursesScores[coursesScores.size() - 1];
        for (int i = coursesScores.size() - 1; i >= 0; --i) {
            if (coursesScores[i] == mostPopularCourseScore)
                numFroshTakingPopularCourses += mostPopularCourseScore;
            else
                break;
        }

        cout << numFroshTakingPopularCourses << endl;
    }

    return 0;
}
