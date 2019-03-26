#include "lib\MyJudge.h"

using namespace std;

int main() {
	ios::sync_with_stdio(0);

    Judge * judge = new Judge();

    judge->judgeAll();

    delete judge;
    
    return 0;
}