#include <iostream>
#include <stdio.h>
#include <list>
#include <string>
#include <iterator>
using namespace std;

struct state{
  int left [2];
  int right [2];
  bool boat;
};

void setData( state &s, int lc, int lm, int rc, int rm, bool boat);
bool checkArithmatic (int lc, int rc, int c, int lr, int rm, int r, int size);
bool isEaten (int lc, int c, int lm, int m, bool add);
bool CheckForLoops (int lastc, int c, int lastm, int m );
void left(state &lastLeft, state &lastRight, list <state> &p, list <state> &endstate, bool &solution, int size);
void right(state &lastLeft, state &lastRight, list <state> &p, list <state> &endstate, bool &solution, int size);
bool isEndstate (state temp, list <state> endstate);
void print (list <state> p);

int main(int argc, char const *argv[]) {
  list <state> p;
  list <state> endstate;

  state start;
  setData(start, 3, 3, 0, 0, 0);
  p.push_back (start);

  bool solution = false;
  if (argc == 2){
    int size;
    sscanf (argv[1],"%d",&size);

    while (!solution){
      state lastLeft;
      setData(lastLeft, 3, 3, 0, 0, 0);
      state lastRight;
      setData(lastRight, 0, 0, 0, 0, 1);

      left(lastLeft, lastRight, p, endstate, solution, size);

      solution = true;
    }

  print(p);
  cout << "endstate" <<endl;
  print (endstate);
  }
  else{
    cout << "please insert boat size" << endl;
  }
  /* code */
  return 0;
}

void left(state &lastLeft, state &lastRight, list <state> &p, list <state> &endstate, bool &solution, int size){
  state temp = p.back();
  cout << "left:  " << temp.left[0] << " " << temp.left [1] <<endl;
  if (solution != true){
  //docked on left
  for (int c = 0; c <= size; c++){
    for (int m = 0; m <= size; m++){
        state endCheck;
        setData (endCheck, temp.left[0] - c, temp.left[1] - m, temp.right[0] + c, temp.right[1] + m, 1);
        if (checkArithmatic (temp.left[0], temp.right[0], c, temp.left [1], temp.right[1], m,size) && isEndstate(endCheck, endstate) && isEndstate (endCheck, p)){
          //cout <<  c  << " " << m << endl;
          if (isEaten (temp.left[0], c, temp.left[1], m, 0) && isEaten (temp.right [0], c, temp.right [1], m, 1)){
            //cout << "left eat: "<<  c  << " " << m << endl;
            //cout << temp.left[0] - c  << " " << temp.left[1] - m << endl;
            //cout << lastRight.right[0] << " "  << nextState.right[0] << " "  <<  lastRight.right[1] << " "  << nextState.right[1] <<endl;
            if (CheckForLoops (lastRight.right[0], temp.right[0] + c, lastRight.right [1], temp.right[1] + m )){
              //char t;
              //cin >> t;
            //  cout <<  c  << " " << m << endl;
              state nextState;
              state tempLastState;
              setData (tempLastState, lastLeft.left[0], lastLeft.left[1], lastLeft.right[0], lastLeft.right[1], 1);
              setData (nextState, temp.left[0] - c, temp.left[1] - m, temp.right[0] + c, temp.right[1] + m, 1);
              setData (lastLeft, temp.left[0], temp.left[1], temp.right[0], temp.right[1], 1);
              p.push_back (nextState);
              right(lastLeft, lastRight, p, endstate, solution, size);
              if (p.size() > 1){
                p.pop_back();
              }
              //cout << "returned" <<endl;
              setData (lastLeft,tempLastState.left[0],tempLastState.left[1], tempLastState.right[0], tempLastState.right[1], 1);
            }
          }
        }
      }
    }
  //  cout << "endstate made" <<endl;

    endstate.push_back (temp);

  //  cout << endl;
  }
}

void right(state &lastLeft, state &lastRight, list <state> &p, list <state> &endstate, bool &solution, int size){
  state temp = p.back();
  cout << "right: " << temp.right[0] << " " << temp.right [1] <<endl;
  //check for end condition
  if (temp.right[0]  == 3  && temp.right [1] == 3){
    cout << "solved" << endl;
    solution = true;
  }
  else{
  //docked on right
    for (int c = 0; c <= size; c++){
      for (int m = 0; m <= size; m++){
        state endCheck;
        setData (endCheck,temp.left[0] + c,temp.left[1] + m, temp.right[0] - c, temp.right[1] - m, 0);
        if (checkArithmatic (temp.right[0], temp.left[0], c, temp.right [1], temp.left[1], m,size) && isEndstate(endCheck, endstate) && isEndstate (endCheck, p)){
      //     cout <<  c  << " " << m << endl;
          if (isEaten (temp.left[0], c, temp.left[1], m, 1) && isEaten (temp.right [0], c, temp.right [1], m, 0)){
            //cout  << "right eat: "<<  c  << " " << m << endl;
            //cout << "loop:" << lastLeft.left[0] << " " << temp.left[0] + c << " "  << lastLeft.left [1] << " " << temp.left[1] + m << endl;
            if (CheckForLoops (lastLeft.left[0], temp.left[0] + c, lastLeft.left [1], temp.left[1] + m )){
              //char t;
              //cin >> t;
//              cout <<  c  << " " << m << endl;

              state nextState;
              state tempLastState;
              setData (tempLastState, lastRight.left[0], lastRight.left[1], lastRight.right[0], lastRight.right[1], 0);
              setData (nextState,temp.left[0] + c,temp.left[1] + m, temp.right[0] - c, temp.right[1] - m, 0);
              setData (lastRight, temp.left[0], temp.left[1], temp.right[0], temp.right[1], 0);
              p.push_back (nextState);
              left(lastLeft, lastRight, p, endstate, solution, size);
              if (size > 1){
                  p.pop_back();
              }
            //  cout << "returned" << endl;
              setData (lastRight,tempLastState.left[0],tempLastState.left[1], tempLastState.right[0], tempLastState.right[1], 0);
            }
          }
        }
      }
    }
  //  cout <<endl;
  //cout << "endstate made" <<endl;
  endstate.push_back (temp);
  }
}


bool CheckForLoops (int lastc, int c, int lastm, int m ){
  if (lastc == c && lastm == m){
    return false;
  }
  return true;
}

bool isEaten (int lc, int c, int lm, int m, bool add){
   if (add == 0){
    if (lm - m != 0 ){
      if(lc - c > lm - m ){
        return false;
      }
    }
    else{
    //  cout << "sub false"<< c << " " << m <<endl;
      return true;
    }
  }
  else {
    if (lm + m != 0){
      if (lc + c > lm + m ){
        return false;
      }
    }
    else{
    //  cout <<"add false" << c << " " << m << endl;
      return true;
    }
  }
}

bool checkArithmatic (int lc, int rc, int c, int lm, int rm, int m, int size){
  bool check = true;
    if (lc - c < 0 && lm - m < 0){
    //  cout << "77 false "  << c << " " << m <<endl;
      check = false;
    }
    else if (c + m <= 0){
      //cout << "181 false " << c << " " << m <<endl;
      check = false;
    }
    else if (c + m > size){
      //cout << "185 false " << c << " " << m <<endl;
      check = false;
    }
    else if (rc + c > 3){
    //  cout << "189 false " << c << " " << m <<endl;
      check = false;
    }
    else if (rm + m > 3){
    //  cout << "193 false " << c << " " << m <<endl;
      check = false;
    }
  //  cout << lm << " " << m << " " << lc << " " << c << endl;
  return check;
}

bool isEndstate (state temp, list <state> endstate){
  for (list<state>::iterator it = endstate.begin(); it != endstate.end(); it++){
    if (temp.left [0] == it->left[0] && temp.left [1] == it->left[1]
        && temp.right [0] == it->right[0] && temp.right [1] == it->right[1]
        && temp.boat == it->boat){
          //cout << "endstate" << temp.left [0] << " " << temp.left [1] << "    " <<temp.right [0] << " " << temp.right [1] <<endl;
          return false;
        }
  }
  return true;
}

void setData( state &s, int lc, int lm, int rc, int rm, bool b){
  s.left [0] = lc;
  s.left [1] = lm;
  s.right [0] = rc;
  s.right [1] = rm;
  s.boat = b;
}

void print (list <state> p){
  string dir;
  while (!p.empty()){
    state temp = p.front();
    if (temp.boat == 0){
      dir = "left:  ";
    }
    else{
      dir = "right: ";
    }
    cout << dir << temp.left[0] << " " << temp.left[1] << "      " << temp.right[0] << " " << temp.right[1] << " " << endl;
    p.pop_front();
  }
}
