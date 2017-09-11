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
void left(list <state> &p, list <state> &endstate, bool &solution, int size);
void right(list <state> &p, list <state> &endstate, bool &solution, int size);
bool isEndstate (state temp, list <state> endstate);
void print (list <state> p);

int main(int argc, char const *argv[]) {
  list <state> p;
  list <state> endstate;

 // create star point
  state start;
  setData(start, 3, 3, 0, 0, 0);
 // push it into state stack
  p.push_back (start);

//not solution found yet
  bool solution = false;
// check for boat size
  if (argc == 2){
    int size;
    sscanf (argv[1],"%d",&size);



 // start on the left
      left( p, endstate, solution, size);
  }
  else{
    cout << "please insert boat size" << endl;
  }
 
  return 0;
}


// deals with the boat on the left shore
void left(list <state> &p, list <state> &endstate, bool &solution, int size){
 // get the state
  state temp = p.back();

  if (solution != true){
  //docked on left
  // go through cannibals
  for (int c = size; c >= 0; c--){
    //and missonaries
    for (int m = size; m >= 0; m--){
       // check if this is and endstate or if mathmatically valid
        state endCheck;
        setData (endCheck, temp.left[0] - c, temp.left[1] - m, temp.right[0] + c, temp.right[1] + m, 1);
        if (checkArithmatic (temp.left[0], temp.right[0], c, temp.left [1], temp.right[1], m,size) && isEndstate(endCheck, endstate) && isEndstate (endCheck, p)){
          //check if cannibals will eat if this state occurs
          if (isEaten (temp.left[0], c, temp.left[1], m, 0) && isEaten (temp.right [0], c, temp.right [1], m, 1)){

	     // set the last known state
              state nextState;
              setData (nextState, temp.left[0] - c, temp.left[1] - m, temp.right[0] + c, temp.right[1] + m, 1);

	      // push on the stack
              p.push_back (nextState);
	     // move right
              right( p, endstate, solution, size);

	     // nothing found that direction, pop state from stack
              if (p.size() > 1){
                p.pop_back();
              }
            
          }
        }
      }
    }
    // nothing found in this state, consider it an endstate
    endstate.push_back (temp);

  }
}

void right( list <state> &p, list <state> &endstate, bool &solution, int size){
  // get last state
  state temp = p.back();

  //check for end condition
  if (temp.right[0]  == 3  && temp.right [1] == 3){
    //print out
    print(p);
    //it's solved
    solution = true;
  }
  else{
  //docked on right
   // go through cannibals
    for (int c = size; c >= 0; c--){
     // go through missonaries
      for (int m = size; m >= 0; m--){
	// check if endstate and if arithmatic is right
        state endCheck;
        setData (endCheck,temp.left[0] + c,temp.left[1] + m, temp.right[0] - c, temp.right[1] - m, 0);
        if (checkArithmatic (temp.right[0], temp.left[0], c, temp.right [1], temp.left[1], m,size) && isEndstate(endCheck, endstate) && isEndstate (endCheck, p)){
	// check if cannibals will eat
          if (isEaten (temp.left[0], c, temp.left[1], m, 1) && isEaten (temp.right [0], c, temp.right [1], m, 0)){
              state nextState;
              setData (nextState,temp.left[0] + c,temp.left[1] + m, temp.right[0] - c, temp.right[1] - m, 0);
	     // push state
              p.push_back (nextState);
	     // go left
              left( p, endstate, solution, size);
	    // nothing found, pop off stack
              if (size > 1){
                  p.pop_back();
              }
        
          }
        }
      }
    }
  // nothing found, endstate
  endstate.push_back (temp);
  }
}


// check if cannibals will eat missonary
bool isEaten (int lc, int c, int lm, int m, bool add){
   if (add == 0){
    if (lm - m != 0 ){
      if(lc - c > lm - m ){
        return false;
      }
    }
    else{
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
      return true;
    }
  }
}

// check for valid numbers
bool checkArithmatic (int lc, int rc, int c, int lm, int rm, int m, int size){
  bool check = true;
    if (lc - c < 0 && lm - m < 0){
      check = false;
    }
    else if (c + m <= 0){
      check = false;
    }
    else if (c + m > size){
      check = false;
    }
    else if (rc + c > 3){
      check = false;
    }
    else if (rm + m > 3){
      check = false;
    }
  return check;
}

// check if endstate
// also used to check for loop
bool isEndstate (state temp, list <state> endstate){
  for (list<state>::iterator it = endstate.begin(); it != endstate.end(); it++){
    if (temp.left [0] == it->left[0] && temp.left [1] == it->left[1]
        && temp.right [0] == it->right[0] && temp.right [1] == it->right[1]
        && temp.boat == it->boat){
          return false;
        }
  }
  return true;
}

// set data in the state struct
void setData( state &s, int lc, int lm, int rc, int rm, bool b){
  s.left [0] = lc;
  s.left [1] = lm;
  s.right [0] = rc;
  s.right [1] = rm;
  s.boat = b;
}

// print results
void print (list <state> p){
  string dir;
    cout << endl<< "    Left Shore " << " Right Shore" << endl;
    cout << "Boat" << "   C M" << "      C M" << endl;
  while (!p.empty()){
    state temp = p.front();
    if (temp.boat == 0){
      dir = "Left:  ";
    }
    else{
      dir = "Right: ";
    }
    cout << dir << temp.left[0] << " " << temp.left[1] << "      " << temp.right[0] << " " << temp.right[1] << " " << endl;
    p.pop_front();
  }
  cout << endl;
}
