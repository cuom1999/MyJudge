#ifndef MYJUDGE_H_INCLUDED
#define MYJUDGE_H_INCLUDED


void report(){
    //cout<<"explorer "+Link+"Chambai\\report.txt"<<endl;
    //system(("explorer "+Link+"Chambai\\report.txt").c_str());
    system("explorer java "+Link+"ShowResult");
}

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

inline void ok(int iTest){
    cout << "Test " << iTest << ": CORRECT!\n";
}

inline void wrong(int iTest){
    cout << "Test " << iTest << ": WRONG!\n";
    exit(1);
}

string Number_To_String(int a){
    string s;
    while (a){
        int b=a%10;
        s+=b+'0';
        a/=10;
    }
    reverse(all(s));
    return s;
}

int measure_time (clock_t t1, clock_t t2){
    return (t2-t1)*1000/CLOCKS_PER_SEC;
}

void SoFile(){
    clock_t t1=clock();
    system("main.exe");
    clock_t t2=clock();

    clock_t t3=clock();
    system("trau.exe");
    clock_t t4=clock();

    if(system("fc output.txt ans.txt") != 0)
    {
        wrong();
    }
    ok();
    cout<<"TIME 1: "<<measure_time(t1,t2)<<endl;
    cout<<"TIME 2: "<<measure_time(t3,t4)<<endl;
}

string testcase(int a){
    string s="input";
    s+=Number_To_String(a);
    s+=".txt";
    return "bin\\"+s;
}





#endif // MYJUDGE_H_INCLUDED
