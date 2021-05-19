#include <iostream>
using namespace std;

int arr[10][10];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void solve(int y,int x){
  int size = arr[y][x];
  arr[y][x] = -2;
  for(int k = 0 ;k<4;++k){
    for(int i = 1 ; i<=size;++i){
      int ny = y + dy[k]*i;
      int nx = x + dx[k]*i;
      if(ny >= 10 || ny <0 || nx >= 10 || nx < 0) break;
      if(arr[ny][nx] == -1 ) break;
      if(!(arr[ny][nx]>0))
        arr[ny][nx]=-2;
    }
  }
  
  
}
int n;
pair<int,int> p[10];
int main(void){
  for(int i = 0 ; i<10;++i)
    for(int j = 0 ; j<10;++j)
       cin>>arr[i][j];
  
  cin>>n;
  for(int i = 0 ; i<n;++i){
    cin>>p[i].first>>p[i].second;
  }
  
  for(int i = 0 ; i<10;++i)
    for(int j = 0 ; j<10;++j)
       if(arr[i][j]>0) solve(i,j);
  
  for(int i = 0 ; i<n;++i){
    int& ref = arr[p[i].first-1][p[i].second-1];
    if(ref == 0)
      ref = i+1;
  }
  
  for(int i = 0 ; i<10;++i){
    for(int j = 0 ; j<10;++j){
       cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"Character Information"<<endl;
  for(int i = 0 ;i<n;++i){
    int& ref = arr[p[i].first-1][p[i].second-1];
    cout<<"player "<<i+1<<" ";
    if(ref == -2) cout<<"dead"<<"\n";
    else if(ref) cout<<"survive"<<"\n";
  }

  
  return 0;
}
