#include "Quidditch.h"


int Quidditch::getpot(int k){
        if (role[k]==15)
                return (10* hit + 10*endu + 10 * agile);
        else if(role[k]==10)
                return (20 * hit + 5 * endu + 5 * agile);
        else if( role[k]==5 )
                return (5 * hit + 20 * endu + 5 * agile);
        else if( role[k]==20 )
                return (5 * hit + 5 * endu + 20 * agile);
}

string Quidditch::getfinalrole(int k){
        if (role[k]==15)
                return "守门员";
        else if(role[k]==10)
                return "追球手";
        else if(role[k]==5)
                return "击球手";
        else if(role[k]==20)
                return "找球手";
}
