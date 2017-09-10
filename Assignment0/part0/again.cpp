#include <iostream>
#include <stdio.h>
using namespace std;

struct data{
  int left [2];
  int right [2];
  bool side;
};


class state{
public:
  state(const data &s, state *n);
  void checkState(const data &s);
  bool sendBoat();

  data info;
  state *next;

};

class problem{
public:
  problem();
  void insert (const data &s);
  //bool remove (const state &d);
  void print();
  bool sendBoat();

  private:
  state *first;
  state *current;
};

void setData( data &s, int lc, int lm, int rc, int rm, bool side);

int main(int argc, char const *argv[]) {
  /* code */
  problem p;

  data start;
  setData(start, 3, 3, 0, 0, 0);
  p.insert (start);



  p.print();

  return 0;
}

void setData( data &s, int lc, int lm, int rc, int rm, bool side){
  s.left [0] = lc;
  s.left [1] = lm;
  s.right [0] = rc;
  s.right [1] = rm;
  s.side = side;
}

state::state(const data &s, state *n){
  info = s;
  next = n;
}

problem::problem(){
  first = NULL;
  current = NULL;
}

void problem::insert (const data &s){
  if (first == NULL){
    first = new state (s, NULL);
    current = first;
  }
  else{
    //checkState (s);
  }
}

bool problem::sendBoat(){
  if ( current->info.side == 0){
    sendRight();
  }
  else{
    sendLeft();
  }
}

void sendRight(){
  
}

void problem::print (){
  if (current != NULL){
    cout << current->info.left [0] << " " << current->info.left [1] << "    " << current->info.right [0] << " " << current->info.right [1] << endl;
    current = current->next;
  }
}
