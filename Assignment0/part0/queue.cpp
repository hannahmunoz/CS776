#include <iostream>
#include <stdio.h>
#include <list>
#include <iterator>
using namespace std;

struct state{
  int left [2];
  int right [2];
  bool boat;
};

void setData( state &s, int lc, int lm, int rc, int rm, bool boat);
void left(state &lastLeft, state &lastRight, list <state> &p, list <state> &endstate);
void right(state &lastLeft, state &lastRight, list <state> &p, list <state> &endstate);
bool isEndstate (state temp, list <state> endstate);
void print (list <state> p);

int main(int argc, char const *argv[]) {
  list <state> p;
  list <state> endstate;

  state start;
  setData(start, 3, 3, 0, 0, 0);
  p.push_back (start);

  bool solution = false;

  while (!solution){
    state lastLeft;
    setData(lastLeft, 3, 3, 0, 0, 0);
    state lastRight;
    setData(lastRight, 0, 0, 0, 0, 1);

    left(lastLeft, lastRight, p, endstate);


    solution = true;
  }

  print(p);

  /* code */
  return 0;
}

void left(state &lastLeft, state &lastRight, list <state> &p, list <state> &endstate){
  state temp = p.back();
  bool del = true;

  //docked on left
  for (int c = 0; c < 3; c++){
    for (int m = 0; m < 3; m++){
        if (temp.left[0] - c > 0 && temp.left [1] - m > 0 && !isEndstate(temp, endstate)){
          //cout << temp.left[0] - c  << " " << temp.left[1] - m << endl;
          state nextState;
          setData (nextState,temp.left[0] - c,temp.left[1] - m, temp.right[0] + c, temp.right[1] + m, 1);
          if (lastLeft.right[0] != nextState.right[0] && lastLeft.right[1] != nextState.right[1]){
            setData (lastLeft,temp.left[0] - c,temp.left[1] - m, temp.right[0] + c, temp.right[1] + m, 1);
            p.push_back (nextState);
            del = false;
            right(lastLeft, lastRight, p, endstate);
          }
        }
      }
    }
    if (del){
      endstate.push_back (temp);
      p.pop_back();
    }
}

void right(state &lastLeft, state &lastRight, list <state> &p, list <state> &endstate){
  state temp = p.back();
  bool del = true;

  //docked on right
  for (int c = 0; c < 3; c++){
    for (int m = 0; m < 3; m++){
      if (temp.right[0] - c > 0 && temp.right [1] - m > 0 && !isEndstate(temp, endstate)){
        state nextState;
        setData (nextState,temp.left[0] + c,temp.left[1] + m, temp.right[0] - c, temp.right[1] - m, 0);
        if (lastRight.left[0] != nextState.left[0] && lastRight.left[1] != nextState.left[1]){
          setData (lastRight,temp.left[0] + c,temp.left[1] + m, temp.right[0] - c, temp.right[1] - m, 0);
          del = false;
          p.push_back (nextState);
          left(lastLeft, lastRight, p, endstate);
        }
      }
    }
  }
  if (del){
    endstate.push_back (temp);
    p.pop_back();
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
  while (!p.empty()){
    state temp = p.front();
    cout << temp.left[0] << " " << temp.left[1] << "      " << temp.right[0] << " " << temp.right[1] << " " << endl;
    p.pop_front();
  }
}
