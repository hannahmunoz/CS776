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
  //cout << "node: " << temp.left[0] << " " << temp.left [1] <<endl;
  bool del = true;
 if (solution != true){
  //docked on left
  for (int c = 0; c <= size; c++){
    for (int m = 0; m <= size; m++){

        if (temp.left[0] - c >= 0 && temp.left [1] - m >= 0
          &&  c + m > 0
          && c + m <= size
          && !isEndstate(temp, endstate)){

          bool check = true;
          if ((temp.left[0] - c > temp.left [1] - m && temp.left [1] - m != 0 )
              || (temp.right[0] + c > temp.right [1] + m && temp.right [1] - m != 0)){
                check = false;
          }

          if (check){

          //cout << temp.left[0] - c  << " " << temp.left[1] - m << endl;
          state nextState;
          state tempLastState;
          setData (tempLastState, lastLeft.left[0], lastLeft.left[1], lastLeft.right[0], lastLeft.right[1], 1);
          setData (nextState,temp.left[0] - c,temp.left[1] - m, temp.right[0] + c, temp.right[1] + m, 1);
        //  cout << lastLeft.right[0] << " "  << nextState.right[0] << " "  <<  lastLeft.right[1] << " "  << nextState.right[1] <<endl;
          if (lastLeft.right[0] != nextState.right[0] && lastLeft.right[1] != nextState.right[1]){
            //cout <<  c  << " " << m << endl;
            setData (lastLeft,temp.left[0] - c,temp.left[1] - m, temp.right[0] + c, temp.right[1] + m, 1);
            p.push_back (nextState);
            del = false;
            right(lastLeft, lastRight, p, endstate, solution, size);
            setData (lastLeft,tempLastState.left[0],tempLastState.left[1], tempLastState.right[0], tempLastState.right[1], 1);
          }
        }
        }
      }
      cout <<endl;
    }
    cout << endl;
    if (del){
      endstate.push_back (temp);
      p.pop_back();
    }
  }
}

void right(state &lastLeft, state &lastRight, list <state> &p, list <state> &endstate, bool &solution, int size){
  state temp = p.back();
  bool del = true;
  cout << "node: " << temp.right[0] << " " << temp.right [1] <<endl;
  //check for end condition
  if (temp.right[0]  == 3  && temp.right [1] == 3){
    solution = true;
  }
  else{

  //docked on right
  for (int c = 0; c <= size; c++){
    for (int m = 0; m <= size; m++){
      if (temp.right[0] - c >= 0 && temp.right [1] - m >= 0
         && c + m > 0
         && c + m <= size
         && !isEndstate(temp, endstate)){

        bool check = true;
        if ((temp.right[0] - c > temp.right [1] - m && temp.right [1] - m != 0 )
          || (temp.left[0] + c > temp.left [1] + m && temp.left [1] - m != 0)){
            cout <<  c  << " " << m << endl;

            check = false;
        }

        if (check){
        //cout << temp.right[0] - c  << " " << temp.right[1] - m << endl;
        state nextState;
        state tempLastState;
        setData (tempLastState, lastRight.left[0], lastRight.left[1], lastRight.right[0], lastRight.right[1], 0);
        setData (nextState,temp.left[0] + c,temp.left[1] + m, temp.right[0] - c, temp.right[1] - m, 0);
        if (lastRight.left[0] != nextState.left[0] && lastRight.left[1] != nextState.left[1]){
          cout <<  c  << " " << m << endl;

          setData (lastRight,temp.left[0] + c,temp.left[1] + m, temp.right[0] - c, temp.right[1] - m, 0);
          del = false;
          p.push_back (nextState);
          left(lastLeft, lastRight, p, endstate, solution, size);
          setData (lastRight,tempLastState.left[0],tempLastState.left[1], tempLastState.right[0], tempLastState.right[1], 0);

        }
      }
      }
    }
  //  cout <<endl;
  }
//  cout <<endl;
  if (del){
    endstate.push_back (temp);
    p.pop_back();
  }
}
}

bool isEndstate (state temp, list <state> endstate){
  for (list<state>::iterator it = endstate.begin(); it != endstate.end(); it++){
    if (temp.left [0] == it->left[0] && temp.left [1] == it->left[1]
        && temp.right [0] == it->right[0] && temp.right [1] == it->right[1]){
          return true;
        }
  }
  return false;
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
