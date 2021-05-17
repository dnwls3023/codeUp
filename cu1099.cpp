#include <iostream>
using namespace std;

/*
  코드업 1099번 : 성실한 개미 [기초-2차원배열]
  
  1차 접근 : bfs알고리즘을 사용하여 구현하려고 했으나 그렇게 하면 문제에서 말한 이동한 경로를 9로 표현하는 과정을 구현하기가 어려움.(사실 내가 구현을 못하는 것)
  
  따라서 다시 문제를 읽어봤더니 이런 조건이 있었음.
  
  개미는 오른쪽으로 움직이다가 벽을 만나면 아래쪽으로 움직여 가장 빠른 길로 움직였다.
  
  이 조건을 충실하게 지키면 풀릴 것 같아서 해봤음
  
*/

int arr[10][10];

int main(void){
  for(int i = 0 ; i<10;++i)
      for(int j =0;j<10;++j)
        cin>>arr[i][j];
  int sy = 1,sx=1;
  while(true){
    
    if(arr[sy][sx]==2) {arr[sy][sx]=9;break; }
    arr[sy][sx] = 9;
    // 오른쪽이 벽이면 아래가 벽인지 확인하고 벽이 아니면 아래로 이동함
    if(arr[sy][sx+1] == 1){
      if(arr[sy+1][sx] == 1)
        break;
      else{
        if(arr[sy+1][sx] == 2) {arr[sy+1][sx]=9;break; }
        sy++;
      }
    }
    // 오른쪽이 벽이 아니라면 오른쪽으로 이동
    else{
      if(arr[sy][sx+1]==2){arr[sy][sx+1]=9;break; }
      sx++;
    }
        
  }
    
  
  for(int i = 0 ; i<10;++i){
      for(int j =0;j<10;++j)
        cout<<arr[i][j]<<" ";
    cout<<"\n";
  }
  return 0;
}
