#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cstring>
#include <QString>


//定义魁地奇类
class Quidditch{
        protected:
                int hit;     //命中
                int endu;    //耐力
                int agile;   //敏捷
                int role[420];
                QString name;
        public:
                Quidditch(){}
                Quidditch(int a,int b,int c,QString d): hit(a),endu(b),agile(c), name(d){}
                ~Quidditch(){}

                QString getname() { return name;	}
                void setname(QString _name){ name=_name;}

                void setrole(int k,int _role){ role[k]=_role;}
                int getrole(int k){ return role[k];}


                QString getfinalrole(int k);   //输出最终角色
                int getpot(int k);  	       //输出最终效力
};


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


QString Quidditch::getfinalrole(int k){
        if (role[k]==15){
            std::string keeper0 = "守门员";
            QString keeper = QString::fromLocal8Bit(keeper0.c_str());
            return keeper;
        }
        else if(role[k]==10){
            std::string chaser0 = "追球手";
            QString chaser = QString::fromLocal8Bit(chaser0.c_str());
            return chaser;
        }
        else if(role[k]==5){
            std::string beater0 = "击球手";
            QString beater = QString::fromLocal8Bit(beater0.c_str());
            return beater;
        }

        else if(role[k]==20){
            std::string seeker0 = "找球手";
            QString seeker = QString::fromLocal8Bit(seeker0.c_str());
            return seeker;
        }

}







//魁地奇类定义完毕，下面定义相关函数

int pot[420];      //储存总效力，可能性有7*6*C(5,2)=420种
int k=0;           //记录数组排列下标，pot[k]即为总效力
//是否交换
bool isSwap(int array[],int len,int index){
        for(int i=index+1;i<len;++i)
            if(array[index]==array[i])
                return false;
        return true;
}


//实现两数交换
void swap(int* o,int i,int j){
    int tmp = o[i];
    o[i] = o[j];
    o[j] = tmp;
}

//递归实现有重复元素的数组全排列
void permutation(int a[],int len,int index,Quidditch &q0,Quidditch &q1,Quidditch &q2,Quidditch &q3,Quidditch &q4,Quidditch &q5,Quidditch &q6){

    if(index==len){  //全排列结束
        q0.setrole(k,a[0]);
        q1.setrole(k,a[1]);
        q2.setrole(k,a[2]);
        q3.setrole(k,a[3]);
        q4.setrole(k,a[4]);
        q5.setrole(k,a[5]);
        q6.setrole(k,a[6]);
        pot[k]=q0.getpot(k)*a[0]+q1.getpot(k)*a[1]+q2.getpot(k)*a[2]+q3.getpot(k)*a[3]+q4.getpot(k)*a[4]+q5.getpot(k)*a[5]+q6.getpot(k)*a[6];
        k++;
    }
    else
        for(int i=index;i<len;++i){
            if(isSwap(a,len,i)){ //新增判断是否交换
                swap(a,index,i);  //将第i个元素交换至当前index下标处
                permutation(a,len,index+1,q0,q1,q2,q3,q4,q5,q6); //以递归的方式对剩下元素进行全排列
                swap(a,index,i); //将第i个元素交换回原处
            }
        }
}




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

    //输入姓名，命中，耐力，敏捷，并存储在类中

   Quidditch q0(ui->spinBoxq01->value(),ui->spinBoxq02->value(),ui->spinBoxq03->value(),ui->lineEditq0s->text());
   Quidditch q1(ui->spinBoxq11->value(),ui->spinBoxq12->value(),ui->spinBoxq13->value(),ui->lineEditq1s->text());
   Quidditch q2(ui->spinBoxq21->value(),ui->spinBoxq22->value(),ui->spinBoxq23->value(),ui->lineEditq2s->text());
   Quidditch q3(ui->spinBoxq31->value(),ui->spinBoxq32->value(),ui->spinBoxq33->value(),ui->lineEditq3s->text());
   Quidditch q4(ui->spinBoxq41->value(),ui->spinBoxq42->value(),ui->spinBoxq43->value(),ui->lineEditq4s->text());
   Quidditch q5(ui->spinBoxq51->value(),ui->spinBoxq52->value(),ui->spinBoxq53->value(),ui->lineEditq5s->text());
   Quidditch q6(ui->spinBoxq61->value(),ui->spinBoxq62->value(),ui->spinBoxq63->value(),ui->lineEditq6s->text());

   int a[7]={15,20,10,10,10,5,5};      //内部为赋权值*10，含有1个1.5，3个1, 2个0.5，1个2
   permutation(a,7,0,q0,q1,q2,q3,q4,q5,q6); //数组全排列

   int maxpot=pot[0];            //总效力
   int index=0;                  //pot[index]=总效力
   for(int n=0;n<420;n++){
           if(pot[n]>maxpot){
                   maxpot=pot[n];
                   index=n;
           }
   }

   //输出最大总效力
   double finalmaxpot=(double)maxpot*0.01;
   ui->lcdNumber_maxpot->display(finalmaxpot);

   //输出职位
   ui->lineEdit_r0->setText( q0.getfinalrole(index) );
   ui->lineEdit_r1->setText( q1.getfinalrole(index) );
   ui->lineEdit_r2->setText( q2.getfinalrole(index) );
   ui->lineEdit_r3->setText( q3.getfinalrole(index) );
   ui->lineEdit_r4->setText( q4.getfinalrole(index) );
   ui->lineEdit_r5->setText( q5.getfinalrole(index) );
   ui->lineEdit_r6->setText( q6.getfinalrole(index) );

   //输出效力
   ui->lcdNumber_pot0->display( (double)q0.getpot(index)*0.10);
   ui->lcdNumber_pot1->display( (double)q1.getpot(index)*0.10);
   ui->lcdNumber_pot2->display( (double)q2.getpot(index)*0.10);
   ui->lcdNumber_pot3->display( (double)q3.getpot(index)*0.10);
   ui->lcdNumber_pot4->display( (double)q4.getpot(index)*0.10);
   ui->lcdNumber_pot5->display( (double)q5.getpot(index)*0.10);
   ui->lcdNumber_pot6->display( (double)q6.getpot(index)*0.10);


}
