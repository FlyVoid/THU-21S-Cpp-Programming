#ifndef QUIDDITCH_H
#define QUIDDITCH_H


#include<cstring>
using namespace std;

class Quidditch{
        protected:
                int hit;     //����
                int endu;    //����
                int agile;   //����
                int role[420];
                string finalrole;
        public:
                Quidditch(){}
                Quidditch(int a,int b,int c,string d): hit(a),endu(b),agile(c), name(d){}
                ~Quidditch(){}


                void setrole(int k,int _role){ role[k]=_role;}
                int getrole(int k){ return role[k];}


                string getfinalrole(int k);   //������ս�ɫ
                int getpot(int k);  	       //�������Ч��
};


#endif // QUIDDITCH_H
