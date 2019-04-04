#ifndef MYJUDGE_H
#define MYJUDGE_H

#include <fstream>
#include <string>

class Judge {

public:
	Judge();
	~Judge();

	enum Result {AC, WA, TLE, CE};

	Result judgeAll();
	
private:
	
	double TIME_LIMIT;
	int    NUMBER_OF_TESTS;
	int    timeElapsed;

	std::string   LINK;
	std::ofstream REPORT;
	std::ofstream STATS;

	std::string   testCase(int a);

	void   warmUp();	
	void   report(Result res, int indexTest = 0);
	bool   checker(std::string ans, std::string output, std::string input = "none");
	bool   compile(std::string filecpp);
	Result judgeTest(int i);
	
};


#endif