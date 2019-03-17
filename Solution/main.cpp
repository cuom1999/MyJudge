// Problem         : Inflation (NAIPC 2019)
// Author          : Darcy Best
// Expected Result : AC
// Complexity      : O( (y*c)^3 )

// Take log of all variables
// Use Guassian Elimination to determine everything.

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

const double EPS = 1e-10;

vector<double> solve(vector<vector<double> >& M){
  int rows = M.size(), cols = M[0].size();

  int rank = 0;
  for(int piv=0;piv<cols-1 && rank<rows;piv++){
    for(int i=rank;i<rows;i++)
      if(abs(M[i][piv]) >= EPS){
        M[rank].swap(M[i]);
        break;
      }
    if(abs(M[rank][piv]) < EPS) continue;

    double divide_me = M[rank][piv];
    for(int j=rank;j<cols;j++) M[rank][j] /= divide_me;

    for(int i=0;i<rows;i++){
      if(abs(M[i][piv]) < EPS || i == rank) continue;
      double multiplier = M[i][piv] / M[rank][piv];
      for(int j=rank;j<cols;j++)
        M[i][j] -= multiplier * M[rank][j];
    }
    rank++;
  }

  vector<double> ans(cols-1,-1);
  for(int i=0;i<rank;i++){
    int first = 0, last = cols-2;
    for(;first<cols;first++) if(abs(M[i][first]) >= EPS) break;
    for(;last>=0;last--)     if(abs(M[i][last ]) >= EPS) break;
    if(first != last) continue; // Undetermined
    ans[first] = exp(M[i][cols-1]);
  }

  return ans;
}

int main(){
  
  int y, c, q; cin >> y >> c >> q;

  vector<double> r(y-1);
  for(auto& x : r) cin >> x;
  
  vector<vector<double> > A(y, vector<double>(c));
  for(auto& v : A)
    for(auto& x : v)
      cin >> x;

  vector<vector<double> > matrix;

  // pr(A,x) =
  // pr(A,last)*infl(last)*infl(last+1)* ... *infl(x-1) * modif(A)^(last-x)
  for(int i=1;i<y;i++)
    for(int j=0;j<c;j++){
      vector<double> row(y*c+y+c+1);
      row[j*y + i] = -1;
      row[j*y + (i-1)] = 1;
      row[y*c + c + i-1] = 1;
      row[y*c + j] = 1;
      matrix.push_back(row);
    }

  // Add in the known information
  //  ... First, the prices...
  for(int i=0;i<y;i++)
    for(int j=0;j<c;j++)
      if(A[i][j] >= -0.5){
        vector<double> row(y*c+y+c+1);
        row[j*y + i] = 1;
        row.back() = log(A[i][j]);
        matrix.push_back(row);
      }

  // ... Second, the inflation rates
  for(int i=0;i<y-1;i++)
    if(r[i] >= -0.5){
      vector<double> row(y*c+y+c+1);
      row[y*c + c + i] = 1;
      row.back() = log(r[i]);
      matrix.push_back(row);
    }

  vector<double> ans = solve(matrix);

  while(q--){
    int a, b; cin >> a >> b; a--; b--;
    cout << fixed << setprecision(10) << ans[a*y+b] << endl;
  }
}
