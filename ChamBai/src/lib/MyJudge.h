#ifndef MYJUDGE_H
#define MYJUDGE_H

#include <bits/stdc++.h>

extern double TIME_LIMIT;
extern int TIME_ELAPSE;
extern int NUMBER_OF_TESTS;
extern std::ofstream REPORT;
extern std::string LINK;

void getLink();
void report();

void ce();
void ok();
void wrong(int iTest);
void tle(int iTest);

std::string numberToString(int a);
std::string testcase(int a);

int measureTime(clock_t t1, clock_t t2);

int compile(std::string filecpp);
void judge(int i);
bool checker(std::string input, std::string ans, std::string output);



#endif