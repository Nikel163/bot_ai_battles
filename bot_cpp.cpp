#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int SIZE = 5;
const int SIZE2 = SIZE*SIZE;

const string INIT ("init");
const string SHOOT ("shoot");

void fix_enemy_field(string &fleet)
{
    for(int i = 0; i<25; i++)
    {
        if(fleet[i] == '3')
        {
            switch (i)
            {
                case 0: fleet[i+1] = '1'; fleet[i+5] = '1'; fleet[i+6] = '1'; break;
                case 1 ... 3: fleet[i-1] = '1'; fleet[i+4] = '1'; fleet[i+1] = '1'; fleet[i+5] = '1'; fleet[i+6] = '1'; break;
                case 4: fleet[i-1] = '1'; fleet[i+4] = '1'; fleet[i+5] = '1'; break;
                case 5: case 10: case 15:
                    fleet[i-5] = '1'; fleet[i-4] = '1'; fleet[i+1] = '1'; fleet[i+5] = '1'; fleet[i+6] = '1'; break;
                case 6 ... 8: case 11 ... 13: case 16 ... 18:
                    fleet[i-6] = '1'; fleet[i-5] = '1'; fleet[i-4] = '1'; fleet[i-1] = '1';
                    fleet[i+1] = '1'; fleet[i+4] = '1'; fleet[i+5] = '1'; fleet[i+6] = '1'; break;
                case 20: fleet[i-5] = '1'; fleet[i-4] = '1'; fleet[i+1] = '1'; break;
                case 21 ... 23: fleet[i-6] = '1'; fleet[i-5] = '1'; fleet[i-4] = '1'; fleet[i-1] = '1'; fleet[i+1] = '1'; break;
                case 24: fleet[i-6] = '1'; fleet[i-5] = '1'; fleet[i-1] = '1'; break;
            }
        }
    }

}

void set_fleet() {
    int x = rand()%6;
    switch (x)
    {
        case 0: cout<<"0001000000002200000001010"<<endl; break;
        case 1: cout<<"0000010020000200100000001"<<endl; break;
        case 2: cout<<"0001001000000010220000000"<<endl; break;
        case 3: cout<<"0000001010000001002000020"<<endl; break;
        case 4: cout<<"0000001022000000100000010"<<endl; break;
        case 5: cout<<"0000000000001000000210102"<<endl; break;
    }
}


char get_letter(int num) {
    return num + 'a';
}

void set_code(int x, int y) {
    cout<<get_letter(x)<<y+1<<endl;
}

void shoot(string fleet) {
    if(fleet[0] == '0')
    {
        set_code(0,0); return;
    }
    if(fleet[6] == '0')
    {
        set_code(1,1); return;
    }
    if(fleet[12] == '0')
    {
        set_code(2,2); return;
    }
    if(fleet[18] == '0')
    {
        set_code(3,3); return;
    }
    if(fleet[24] == '0')
    {
        set_code(4,4); return;
    }

    for(int i = 0; i < SIZE2; ++i)
    {
        if(fleet[i] == '2')
        {
            switch (i)
            {
                case 0 ... 3: case 5 ... 8: case 10 ... 13: case 15 ... 18: case 20 ... 23:
                    set_code((i+5)%SIZE, (i+5)/SIZE); return;
            }
        }

        if(fleet[i] == '0')
        {
            set_code(i%SIZE, i/SIZE); return;
        }


    }
}

int main(int argc, const char* argv[]) {
    srand (time(NULL));

    string command (argv[1]);

    if (command.compare(INIT) == 0) {
        set_fleet();
    } else {
        if (command.compare(SHOOT) == 0) {
            string fleet (argv[2]);
            fix_enemy_field(fleet);
            shoot(fleet);
        }
    }
}