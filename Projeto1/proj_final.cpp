#include <iostream>
#include <string.h>
#include <unordered_map>

#define min(x, y) (((x) < (y)) ? (x) : (y))
#define max(x, y) (((x) > (y)) ? (x) : (y))

using namespace std;

struct my_int128 {
    unsigned long long int first = 0;
    unsigned long long int second = 0;

    my_int128() {}

    my_int128(const short v[], const short n) { // O(n)
        short min_lim = min(n, 12);

        for (int i = 0; i < min_lim; i++) first = (first<<5) + v[i];

        if (n > 12) {
            second = first;
            first = 0;
            for (int i = 12; i < n; i++) first = (first<<5) + v[i];
        }
    }
};

template<>
struct std::equal_to<my_int128> { // O(1)
    constexpr bool operator()(const my_int128& lhs, const my_int128& rhs) const {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
};

template<>
struct std::hash<my_int128> { // O(1)
    int operator()(const my_int128 &var) const {
        return std::hash<unsigned long long int>{} (var.first ^ var.second);
    };
};

//Struct that holds all the global variables
struct _Sys_ {
    short n=0, m=0, max_l=0;    //n lines, m columns
    short * ladder; //array that stores the values of each line
    unordered_map<my_int128, unsigned long int> N;  //map where the keys are ladders and the values 
                                                    //are the number of slutions of that ladder
} sys;

unsigned long int compute_fillings(const short ladder[]);

int main() {
    string line;

    //Read the number of lines
    getline(cin, line); //O(1)
    sys.n = stoi(line);

    //Read the number of columns
    getline(cin, line); //O(1)
    sys.m = stoi(line); 
    
    //Initialize the ladder
    short ladder_ini[sys.n];
    sys.ladder = ladder_ini;
    for (short i = 0; i < sys.n; i++) { //O(n)
        getline(cin, line);
        sys.ladder[i] = stoi(line);
    }
    
    if (sys.ladder[sys.n - 1] == 0) cout << 0 << endl; //if the ladder is empty
    else {
        int line = 0;
        while (line < sys.n && sys.ladder[line] <= 1) line++; //O(n)

        //Only starts counting when the line is longer than 1 column
        sys.ladder += line; 
        sys.n -= line;

        if (sys.n <= 1) cout << 1 << endl; //if the ladder is only one line
        else {
            sys.N.insert({my_int128(), 1}); //O(1)

            sys.ladder[sys.n - 1] = sys.ladder[sys.n - 2];  //eliminates all the single squares in the last row

            //If the number of lines is bigger than the number of columns, swap them
            if (sys.n > sys.m) {
                short tmp = sys.n;
                sys.n = sys.m;
                sys.m = tmp;

                short * new_ladder = new short[sys.n];
                memset(new_ladder, 0, sys.n*sizeof(short));
                for (int i = 0; i < sys.m; i++) //ladder is upside down but it doesn't matter
                    for(int j = 0; j < sys.ladder[i]; j++)  //O(nm)
                        new_ladder[j]++;
                
                sys.ladder = new_ladder;
            }
            sys.max_l = min(sys.n, sys.m);

            cout << compute_fillings(sys.ladder) << endl; //O(???) FIXME
        }
    }

    return 0;
}


// h -> altura da escada
// l -> maxima largura da escada
unsigned long int compute_fillings(const short ladder[]) { //O(???) FIXME
    my_int128 ladder_i(ladder, sys.n); //O(h)

    auto pair = sys.N.find(ladder_i); //O(1)
    if (pair != sys.N.end()) return pair->second;


    //Find out where to start the tiling (where the top right square is)
    short max = ladder[0], line_ini = 0;
    for (short i=1; i < sys.n; i++) //O(h)
        if (ladder[i] > max) {
            line_ini = i;
            max = ladder[i];
        }

    short ladder_aux[sys.n];
    unsigned long int val = 0;
    for (short dim = 1; dim <= sys.max_l; dim++) { //O(h)
        if (line_ini + dim > sys.n || ladder[line_ini] < dim) break;
        bool over = false;
        for (short i = 0; i < sys.n; i++) { //O(h)
            if (i < line_ini || i >= line_ini + dim) ladder_aux[i] = ladder[i];
            else {
                if (ladder[i] < ladder[line_ini]) {
                    over = true;
                    break;
                }
                ladder_aux[i] = ladder[i] - dim;
            }
        }
        if (over) break;

        val += compute_fillings(ladder_aux);
    }

    sys.N.insert({ladder_i, val}); //O(1)

    return val;
}