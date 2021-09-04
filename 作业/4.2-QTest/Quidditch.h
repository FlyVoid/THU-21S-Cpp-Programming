#ifndef QUIDDITCH_H
#define QUIDDITCH_H


#include<cstring>
using namespace std;

class Quidditch{
        protected:
                int hit;     //命中
                int endu;    //耐力
                int agile;   //敏捷
                int role[420];
                string finalrole;
        public:
                Quidditch(){}
                Quidditch(int a,int b,int c,string d): hit(a),endu(b),agile(c), name(d){}
                ~Quidditch(){}


                void setrole(int k,int _role){ role[k]=_role;}
                int getrole(int k){ return role[k];}


                string getfinalrole(int k);   //输出最终角色
                int getpot(int k);  	       //输出最终效力
};


#endif // QUIDDITCH_H
