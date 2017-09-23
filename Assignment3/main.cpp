 #include <iosteam>

 using namespace std;

static const int LENGTH = 5;

 int int main(int argc, char const *argv[]) {
     if (argc > 1){
       int run;
       sscanf (argv[1],"%d",&run);
       srand (run);
       int vec[LENGTH];

       eval (vec);

       return 0;
     }
 }
