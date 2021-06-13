#include "snowman.hpp"
#include <iostream>
#include <string>
#include <array>


using namespace std;


const int MaxD = 8;
const int maxDig = 4;
const int minDig = 1;
const int dev = 10;
const int RA = 5;
const int T = 6;
const int B = 7;
const int TheMin = 11111111;
const int TheMax = 44444444;



bool check_num(int a)
{
    bool flage = true;
    int help = a;
    while (help > 0)
    {
        if (help % dev > maxDig || help % dev < minDig)
        {
            return !flage;
        }

        help = help / dev;
    }

    return flage;
}



string Bulid_snow(int a)
{
    string snowmanB;
    const array<string,4> hat = {" _===_", "  ___\n .....", "   _\n  /_\\", "  ___\n (_*_)"};
    const array<string,4> NoseAndMouth = {",",".","_"," "};
    const array<string,4> LeftEye = {"(.","(o","(O","(-"};
    const array<string,4> RightEye = {".)","o)","O)","-)"};
    const array<string,4> LeftArm_up = {" ","\\"," "," "};
    const array<string,4> LeftArm_under ={"<"," ","/"," "};
    const array<string,4> RightArm_up = {"","/"," "," "};
    const array<string,4> RightArm_under ={">"," ","\\"," "};
    const array<string,4> Torso = {"( : )","(] [)","(> <)","(   )"};
    const array<string,4> Base = {" ( : )"," (\" \")"," (___)"," (   )"};

    int help = a;
    array<int, MaxD> answer = {0};
    for (int i = MaxD - 1; i >= 0; i--)
    {
        answer.at(i) = help % dev;
        help = help / dev;
    }

    snowmanB += hat.at(answer[0] - 1);
    snowmanB += "\n";                                // X(LNR)Y
    snowmanB+= LeftArm_up.at(answer[4] - 1);        // Left Arm up
    snowmanB += LeftEye.at(answer[2] - 1);         // Left Eye
    snowmanB += NoseAndMouth.at(answer[1] - 1);   // NOSE\MOTH
    snowmanB += RightEye.at(answer[3]-1);        // Right Eye
    snowmanB += RightArm_up.at(answer[RA] - 1); // Right Arm up
    snowmanB+= "\n";                           // //X(TTT)Y
    snowmanB += LeftArm_under.at(answer[4] - 1); // Left Arm under
    snowmanB += Torso.at(answer[T] - 1);
    snowmanB += RightArm_under.at(answer[RA] - 1);  // Right Arm under
    snowmanB+= "\n";                                // (BBB)
    snowmanB += Base.at(answer[B] - 1);             // BSES
    return snowmanB;
}


string ariel::snowman(int a) 
{
    bool res = check_num(a);
    if (!res)
    {
        throw string("a not takeen" + to_string(a));
    }
    if ((a < TheMin) || (a > TheMax))
    {
        throw string("a not bhla" + to_string(a));
    }
    return Bulid_snow(a);
}
