
#include<iostream> 

#include<iomanip> 

#include<string> 

#include <fstream>

using namespace std; 

const int m=100; 

struct Room{  

int id;            //�����  

int degree;        //�ͷ��ȼ�  

int type;          //�ͷ�����  

int floor;         //�ͷ�¥��  

int number;        //�ͷ���Ŀ 

}; 

class Menu{  

public:    

int MainMenu();  

private:  

};   

int Menu::MainMenu(){  

system("cls");   

cout<<"                  ��������������������������������������"<<endl;      

cout<<"                  |      ��ӭʹ�ü����ͻ�����ϵͳ      |"<<endl;      

cout<<"                   ------------------------------------"<<endl;       

cout<<"                  |                                    |"<<endl;      

cout<<"                  |          1.������ס��Ϣ¼��        |"<<endl;   

cout<<"                  |                                    |"<<endl;     

cout<<"                  |          2.��ʾ¥��ͷ���Ϣ        |"<<endl;      

cout<<"                  |                                    |"<<endl;      

cout<<"                  |          3.��ѯ������ס���        |"<<endl;   

cout<<"                  |                                    |"<<endl;  

cout<<"                  |          4.�޸ķ���Ѻ��            |"<<endl;   

cout<<"                  |                                    |"<<endl;   

cout<<"                  |          5.�޸Ŀ�����Ϣ            |"<<endl;   

cout<<"                  |                                    |"<<endl;   

cout<<"                  |          6.ͳ�Ʋ���ʾ����          |"<<endl;               

cout<<"                  |                                    |"<<endl;  

cout<<"                  |          7.�ͷ���ס������          |"<<endl;

cout<<"                  |                                    |"<<endl; 

cout<<"                  |          8.�˳�����                |"<<endl;

cout<<"                  |                                    |"<<endl;

cout<<"                  ��������������������������������������"<<endl; 

cout<<"                                                        "<<endl;

cout<<"                             ��ѡ��(1-8)��              "<<endl;

int select;

cin>>select;   

while(select<1 || select>8){    

cout<<"ѡ�����������ѡ��(1-8)��";    

cin.clear();  //�������ַ������������״̬    

cin.sync();  //���������    

cin>>select;  

}   

return select; 

} 

class Customer{  

friend ostream &operator<<(ostream &os,Customer &cu); 

private:  

Menu myMenu;   

    string name;       //��������  

int date;          //��סʱ��  

int day;           //��ס����  

int money;         //��סѺ��  

int everydaymoney; //ÿ�����  

Room room;   //�ͷ���Ϣ 

public:  

Customer();  

Customer(string na, int dat, int da, int mo, int emon, int idn, int deg, int ty, int fl, int nu);  

string getname(){   

return name;  

}  

void setname(string na){   

name=na;  

}  

int getdate(){   

return date;  

}  

void setdate(int dat){   

date=dat;  

}  

int getday(){   

return day;  

} 

void setday(int da){   

day=da;  

}  

int getmoney(){   

return money;  

}  

void setmoney(int mon){   

money=mon;  

}  

int geteverydaymoney(){   

return everydaymoney;  

}  

void seteverdaymoney(int emon){   

everydaymoney=emon;  

}  

Room setroom(){   

return room;  

}  

void getroom(Room ro){   

room=ro;  

}  

void run();  

void input();       //������  

int readIn();       //�ļ�����  

void alter();       //�޸���Ϣ  

void findByfloor(); //��¥�����  

void changemoney(); //�޸�Ѻ��  

void show();        //��ʾ�ͻ���ס���  

void print();       //ͳ�Ʋ���ʾ���� 

void rank();        //�ͷ�������ס������

}

customer[m];  

Customer::Customer(){  

name="#";  

date=0;  

day=0;  

money=0;  

everydaymoney=0;  

room.id=0;  

room.floor=0;  

room.degree=0;  

room.number=0;  

room.type=0; 

}  

Customer::Customer(string na, int dat, int da, int mo, int emon, int idn, int deg, int ty, int fl, int nu){  

name=na;

date=dat;  

day=da;  

money=mo;  

everydaymoney=emon;  

room.id=idn;  

room.degree=deg;  

room.type=ty;  

room.floor=fl;  

room.number=nu; 

}    

void Customer::input(){                  //�ͻ���Ϣ¼��  

int n;  

cout<<"��������ס����"<<endl;  

cin>>room.number;  

cout<<endl;  

for(int i=0;i<room.number;i++){   

cout<<"���ǵ�"<<i+1<<"���ͻ�����Ϣ"<<endl;   

cout<<"�������������";   

cin>>customer[i].name;   

cout<<"��סʱ��(��/��/��)��";   

cin>>customer[i].date;   

cout<<"��ס���ޣ�";   

cin>>customer[i].day;   

cout<<"��סѺ��";   

cin>>customer[i].money;   

cout<<"ÿ�����";   

cin>>customer[i].everydaymoney;   

cout<<"����ţ�";   

cin>>customer[i].room.id;   

cout<<"����ȼ�(1-���� 2-��׼ 3-����)��";   

cin>>customer[i].room.degree;   

cout<<"��������(1-���� 2-˫�� 3-����)��";   

cin>>customer[i].room.type;   

cout<<"¥�㣺";   

cin>>customer[i].room.floor;   

cout<<endl; 

}  

cout<<"�������ϢΪ��"<<endl;  

for(int i=0;i<room.number;i++){   

cout<<"��������"<<customer[i].name;   

cout<<"\t��סʱ�䣺"<<customer[i].date;   

cout<<"\t��ס���ޣ�"<<customer[i].day;   

cout<<"\t��סѺ��"<<customer[i].money;   

cout<<"\tÿ�����"<<customer[i].everydaymoney;   

cout<<"\t����ţ�"<<customer[i].room.id;   

cout<<"\t����ȼ���";   

if(customer[i].room.degree==1)    

cout<<"���ü�";   

else{    

if(customer[i].room.degree==2)     

cout<<"��׼��";    

else{     

if(customer[i].room.degree==3)      

cout<<"������";    

}   

}   

cout<<"\t�������ͣ�";   

if(customer[i].room.type==1)    

cout<<"���˼�";   

else{    

if(customer[i].room.type==2)     

cout<<"˫�˼�";    

else{     

if(customer[i].room.type==3)      

cout<<"���˼�";    

}   

}   

cout<<"\t¥�㣺"<<customer[i].room.floor;   

cout<<endl;  

}  

ofstream os("customer.txt",ios_base::out|ios_base::binary);  //���������ļ�  

for(n=0;n<room.number;n++){   

os.write( reinterpret_cast<char*>(&(customer[n])),sizeof(Customer) );  //�����ļ�  

}  

os.close();  //�ر��ļ� 

}  

int Customer::readIn(){                 //�ļ�����  

int i,n;  

ifstream is("customer.txt",ios_base::in|ios_base::binary);

if(!is){   

cout<<"��ʧ��"<<endl;   

return 0;  

}  

for(i=0;is.read( reinterpret_cast<char *>(customer+i) , sizeof(Customer) );i++)  

room.number=i;  

cout<<"����ı���"<<endl;  

for(n=0;n<room.number;n++){  

cout<<"��������"<<customer[i].name;   

cout<<"��סʱ�䣺"<<customer[i].date;   

cout<<"��ס���ޣ�"<<customer[i].day;   

cout<<"��סѺ��"<<customer[i].money;   

cout<<"ÿ�����"<<customer[i].everydaymoney;   

cout<<"����ţ�"<<customer[i].room.id;   

cout<<"����ȼ���"<<customer[i].room.degree;   

cout<<"�������ͣ�"<<customer[i].room.type;   

cout<<"¥�㣺"<<customer[i].room.floor;  

}  

return 1; 

}  

void Customer::alter(){               //�޸Ŀͻ���Ϣ  

int mark = 0;      //���ñ��  

int i,m;  

string x;  

cout<<"������ͻ���:";  

do{   

cin>>x;   

cout<<endl;   

for(i=0;i<room.number;i++){    

if(customer[i].name==x){     

mark = 1;     

cout<<"��������"<<customer[i].name;           

cout<<"\t��סʱ�䣺"<<customer[i].date;           

cout<<"\t��ס���ޣ�"<<customer[i].day;           

cout<<"\t��סѺ��"<<customer[i].money;           

cout<<"\tÿ�����"<<customer[i].everydaymoney;           

cout<<"\t����ţ�"<<customer[i].room.id;           

cout<<"\t����ȼ���";     

if(customer[i].room.degree==1)             

cout<<"���ü�";           

else{            

if(customer[i].room.degree==2) 

cout<<"��׼��";            

else{             

if(customer[i].room.degree==3)            

cout<<"������";      

}     

}            

cout<<"\t�������ͣ�";     

if(customer[i].room.type==1)             

cout<<"���˼�";           

else{            

if(customer[i].room.type==2)             

cout<<"˫�˼�";            

else{             

if(customer[i].room.type==3)               

cout<<"���˼�";      

}        

}            

cout<<"\t¥�㣺"<<customer[i].room.floor;     

cout<<endl;       

cout<<"�޸���Ϣ�������룺"<<endl;     

cout<<"�������������";              

cin>>customer[i].name;              

cout<<"��סʱ�䣺";              

cin>>customer[i].date;              

cout<<"��ס���ޣ�";              

cin>>customer[i].day;              

cout<<"ÿ�����";               

cin>>customer[i].everydaymoney;              

cout<<"����ţ�";               

cin>>customer[i].room.id;               

cout<<"����ȼ�(1-����2-��׼3-����)��";              

cin>>customer[i].room.degree;               

cout<<"��������(1-����2-˫��3-����)��";              

cin>>customer[i].room.type;              

cout<<"¥�㣺";               

cin>>customer[i].room.floor;              

cout<<endl;    

}    

else;   

}   

if (mark== 0)    

cout<<"�����������������:"<<endl;   

}

while(mark == 0);

ofstream os("customer.txt",ios_base::out|ios_base::binary);  //���������ļ�  

for(m=0;m<room.number;m++){   

os.write( reinterpret_cast<char*>(&(customer[m])),sizeof(Customer));  //�����ļ�  

}  

os.close();  //�ر��ļ� 

}  

void Customer::show(){                //������ס�����ѯ  

int i;  

for(i=0;i<room.number;i++){   

cout<<"��������"<<customer[i].name;   

cout<<"\t��סʱ�䣺"<<customer[i].date;   

cout<<"\t��ס���ޣ�"<<customer[i].day;   

cout<<"\t��סѺ��"<<customer[i].money;   

cout<<"\tÿ�����"<<customer[i].everydaymoney;   

cout<<"\t����ţ�"<<customer[i].room.id;   

cout<<"\t����ȼ���";   

if(customer[i].room.degree==1)    

cout<<"���ü�";   

else{    

if(customer[i].room.degree==2)     

cout<<"��׼��";    

else{     

if(customer[i].room.degree==3)      

cout<<"������";    

}   

}   

cout<<"\t�������ͣ�";   

if(customer[i].room.type==1)    

cout<<"���˼�";   

else{    

if(customer[i].room.type==2)     

cout<<"˫�˼�";    

else{     

if(customer[i].room.type==3)      

cout<<"���˼�";    

}   

}   

cout<<"\t¥�㣺"<<customer[i].room.floor;   

cout<<endl;  

} 

}  

void Customer::findByfloor(){            //��ʾ¥����Ϣ  

int n;  

int mark = 0; //���ñ�� 

int i;   

cout<<"������¥��:";  

do{   

cin>>n;   

cout<<endl;   

for(i=0;i<room.number;i++){    

if(customer[i].room.floor==n){     

mark = 1;     

cout<<"��Ϣ���£�"<<endl;     

cout<<"����������"<<customer[i].name;           

cout<<"\t��סʱ�䣺"<<customer[i].date;           

cout<<"\t��ס���ޣ�"<<customer[i].day;           

cout<<"\t��סѺ��"<<customer[i].money;           

cout<<"\tÿ�����"<<customer[i].everydaymoney;           

cout<<"\t����ţ�"<<customer[i].room.id;           

cout<<"\t����ȼ���";     

if(customer[i].room.degree==1)cout<<"���ü�";           

else{            

if(customer[i].room.degree==2)              

cout<<"��׼��";            

else{             

if(customer[i].room.degree==3)            

cout<<"������";      

}     

}           

cout<<"\t�������ͣ�";     

if(customer[i].room.type==1)             

cout<<"���˼�";           

else{            

if(customer[i].room.type==2)             

cout<<"˫�˼�";            

else{             

if(customer[i].room.type==3)               

cout<<"���˼�";      

}        

}           

cout<<"\t¥�㣺"<<customer[i].room.floor;         

}    

else;   

}   

if (mark== 0)    

cout<<"�����������������:"<<endl; 

}

while(mark == 0); 

}  

void Customer::changemoney(){          //Ѻ���޸�  

int mark = 0;   //���ñ��  

int i,m;  

string x;  

cout<<"������ͻ���:";  

do{   

cin>>x;   

cout<<endl;   

for(i=0;i<room.number;i++){    

if(customer[i].name==x){     

mark = 1;     

cout<<"��������"<<customer[i].name;           

cout<<"\t��סʱ�䣺"<<customer[i].date;           

cout<<"\t��ס���ޣ�"<<customer[i].day;           

cout<<"\t��סѺ��"<<customer[i].money;           

cout<<"\tÿ�����"<<customer[i].everydaymoney;           

cout<<"\t����ţ�"<<customer[i].room.id;           

cout<<"\t����ȼ���";     

if(customer[i].room.degree==1)             

cout<<"���ü�";           

else{            

if(customer[i].room.degree==2)              

cout<<"��׼��";            

else{             

if(customer[i].room.degree==3)            

cout<<"������";      

}     

}           

cout<<"\t�������ͣ�";     

if(customer[i].room.type==1)             

cout<<"���˼�";           

else{            

if(customer[i].room.type==2)             

cout<<"˫�˼�";           

else{          

if(customer[i].room.type==3)   

cout<<"���˼�";    

} 

}

cout<<"\t¥�㣺"<<customer[i].room.floor;

cout<<"�޸�Ѻ�������룺"<<endl;     

cin>>customer[i].money;

cout<<endl;

}

else;

}

if (mark== 0) 

cout<<"�����������������:"<<endl;

}

while(mark == 0);  

ofstream os("customer.txt",ios_base::out|ios_base::binary);  //���������ļ� 

for(m=0;m<room.number;m++){ 

os.write( reinterpret_cast<char*>(&(customer[m])),sizeof(Customer) );  //�����ļ�  

} 

os.close();  //�ر��ļ� 

}  

void Customer::print(){              //ͳ������  

int n=0; 

for(int i=0;i<room.number;i++){ 

n+=customer[i].everydaymoney*customer[i].day;     //ÿ�����*��ס����  

} 

cout<<"ĿǰΪֹ������Ϊ��"<<n<<"Ԫ"<<endl;

} 

void Customer::rank(){         //�ͷ�������ס������

int choose;

int m1=0,m2=0,m3=0;

int n1=0,n2=0,n3=0;

cout<<"1.������ȼ�����"<<endl; 

cout<<"2.��������������"<<endl; 

cout<<"�������ѡ��"<<endl; 

cin>>choose;

switch(choose){

case 1:

for(int i=0;i<room.number;i++){ 

if(customer[i].room.degree==1){

n1+=customer[i].room.degree;

}

if(customer[i].room.degree==2){

n2+=customer[i].room.degree;

}

if(customer[i].room.degree==3){

n3+=customer[i].room.degree;

}

} 

if((n1>n2 && n1>n3) && (n2>n3))

cout<<"1.���ü�"<<endl;

cout<<"2.��׼��"<<endl;

cout<<"3.������"<<endl;

if((n1>n2 && n1>n3) && (n3>n2))

cout<<"1.���ü�"<<endl;

cout<<"2.������"<<endl;

cout<<"3.��׼��"<<endl;

if((n3>n1 && n3>n2) && (n1>n2))

cout<<"1.������"<<endl;

cout<<"2.���ü�"<<endl;

cout<<"3.��׼��"<<endl;

        if((n3>n1 && n3>n2) && (n2>n1))

cout<<"1.������"<<endl;

cout<<"2.��׼��"<<endl;

cout<<"3.���ü�"<<endl;

if((n2>n1 && n2>n3) && (n1>n3))

cout<<"1.��׼��"<<endl;

cout<<"2.���ü�"<<endl;

cout<<"3.������"<<endl;

if((n2>n1 && n2>n3) && (n3>n1))

cout<<"1.��׼��"<<endl;

cout<<"2.������"<<endl;

cout<<"3.���ü�"<<endl;

break;

case 2:  

for(int i=0;i<room.number;i++){ 

if(customer[i].room.type==1){

m1+=customer[i].room.degree;

}

if(customer[i].room.type==2){

m2+=customer[i].room.degree;

}

if(customer[i].room.type==3){

m3+=customer[i].room.degree;

}

} 

if((m1>m2 && m1>m3) && (m2>m3))

cout<<"1.���˼�"<<endl;

cout<<"2.˫�˼�"<<endl;

cout<<"3.���˼�"<<endl;

if((m1>m2 && m1>m3) && (m3>m2))

cout<<"1.���˼�"<<endl;

cout<<"2.���˼�"<<endl;

cout<<"3.˫�˼�"<<endl;

if((m3>m1 && m3>m2) && (m1>m2))

cout<<"1.���˼�"<<endl;

cout<<"2.���˼�"<<endl;

cout<<"3.˫�˼�"<<endl;

        if((m3>m1 && m3>m2) && (m2>m1))

cout<<"1.���˼�"<<endl;

cout<<"2.˫�˼�"<<endl;

cout<<"3.���˼�"<<endl;

if((m2>m1 && m2>m3) && (m1>m3))

cout<<"1.˫�˼�"<<endl;

cout<<"2.���˼�"<<endl;

cout<<"3.���˼�"<<endl;

if((m2>m1 && m2>m3) && (m3>m1))

cout<<"1.˫�˼�"<<endl;

cout<<"2.���˼�"<<endl;

cout<<"3.���˼�"<<endl;

break;

default:

cout<<"����������������룡"<<endl;

}

}

void Customer::run(){

bool userExited=false;   

while(!userExited){ 

int userSelection=myMenu.MainMenu();

switch(userSelection){  

case 1:             //������Ϣ¼��    

input(); 

break;

case 2: //��ʾ¥����Ϣ   

findByfloor(); 

break;  

case 3:             //������ס�����ѯ  

show(); 

break; 

case 4:             //Ѻ���޸�   

changemoney();  

break;  

case 5:             //�޸Ŀ�����Ϣ  

alter();  

break;  

case 6:             //ͳ������

print(); 

   break;  

case 7:             //�ͷ�������ס������

rank();

break;

case 8:             //�˳�ϵͳ   

userExited=true;  

}   

if(userSelection!=8){   

cout<<"���̽����������棬";  

system("pause");  

}   

else   

cout<<"��ѡ�����˳����ܣ����򽫽������У�"; 

}

} 

int main(){ 

Customer myApp; 

myApp.run();

return 0;

}
