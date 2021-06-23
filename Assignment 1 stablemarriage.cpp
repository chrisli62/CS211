#include <iostream>
using namespace std;

//checks compatibility
bool ok(int p[], int col){

    int mp[3][3] = {{0 , 2 , 1}, {0 , 2 , 1}, {1 , 2 , 0}};
    int wp[3][3] = {{2 , 1 , 0}, {0 , 1 , 2}, {2 , 0 , 1}};

    for(int i = 0; i < col; i++){
        if(p[col] == p[i])
            return false;
        
        if((mp[col][p[i]] < mp[col][col]) && (wp[p[i]][col] < wp[p[i]][i]))
            return false;
        
        if((mp[i][p[col]] < mp[i][p[i]]) && (wp[p[col]][i] < wp[p[col]][col]))
            return false;
    }
    return true;
}

void backtrack(int &col){
    col--;
    if(col == -1) exit(1);
}

void print(int q[]){
    cout << "Man\tWoman" << endl;
    for(int i = 0; i < 3; i++){
        cout << i << "\t" << q[i] << endl;
    }
    cout << endl;
}

/*int main(){
  //variables
  int q[3], c = 1;
  q[0] = 0;
  bool reset = false;
  
  while(true){
    while(c < 3){
      if(!reset)
        q[c] = -1;
      while(q[c] < 3){
        q[c]++;
        if(q[c] == 3){
          reset = true;
          backtrack(c);
         break;
        }
        if(ok(q,c)){
          reset = false;
          c++;
          break;
        }
      }
    }
    print(q);
    reset = true;
    backtrack(c);
  }
  return 0;
}*/

int main(){
  int q[3] = {0}, r = 0, c = 0;
  while(c >= 0){
    c++;

    if(c > 2){ 
      print(q);
      c--;
      r = q[c];
    }
    
    else r = -1;
    
    //checks row
    while(c >= 0){
      r++;
      q[c] = r;
    
      if(r > 2){  
        c--;
        r = q[c];
      } 
    
      else if(ok(q,c)) break;
    }
  }
  return 0;
}