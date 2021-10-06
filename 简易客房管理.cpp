
#include<iostream> 

#include<iomanip> 

#include<string> 

#include <fstream>

using namespace std; 

const int m=100; 

struct Room{  

int id;            //房间号  

int degree;        //客房等级  

int type;          //客房类型  

int floor;         //客房楼层  

int number;        //客房数目 

}; 

class Menu{  

public:    

int MainMenu();  

private:  

};   

int Menu::MainMenu(){  

system("cls");   

cout<<"                  ┌◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆┐"<<endl;      

cout<<"                  |      欢迎使用简明客户管理系统      |"<<endl;      

cout<<"                   ------------------------------------"<<endl;       

cout<<"                  |                                    |"<<endl;      

cout<<"                  |          1.客人入住信息录入        |"<<endl;   

cout<<"                  |                                    |"<<endl;     

cout<<"                  |          2.显示楼层客房信息        |"<<endl;      

cout<<"                  |                                    |"<<endl;      

cout<<"                  |          3.查询客人入住情况        |"<<endl;   

cout<<"                  |                                    |"<<endl;  

cout<<"                  |          4.修改房间押金            |"<<endl;   

cout<<"                  |                                    |"<<endl;   

cout<<"                  |          5.修改客人信息            |"<<endl;   

cout<<"                  |                                    |"<<endl;   

cout<<"                  |          6.统计并显示收入          |"<<endl;               

cout<<"                  |                                    |"<<endl;  

cout<<"                  |          7.客房入住量排序          |"<<endl;

cout<<"                  |                                    |"<<endl; 

cout<<"                  |          8.退出程序                |"<<endl;

cout<<"                  |                                    |"<<endl;

cout<<"                  └◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆┘"<<endl; 

cout<<"                                                        "<<endl;

cout<<"                             请选择(1-8)：              "<<endl;

int select;

cin>>select;   

while(select<1 || select>8){    

cout<<"选择错误！请重新选择(1-8)：";    

cin.clear();  //当输入字符，清空流错误状态    

cin.sync();  //清空数据流    

cin>>select;  

}   

return select; 

} 

class Customer{  

friend ostream &operator<<(ostream &os,Customer &cu); 

private:  

Menu myMenu;   

    string name;       //客人姓名  

int date;          //入住时间  

int day;           //入住期限  

int money;         //入住押金  

int everydaymoney; //每日租金  

Room room;   //客房信息 

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

void input();       //创建表单  

int readIn();       //文件读入  

void alter();       //修改信息  

void findByfloor(); //按楼层查找  

void changemoney(); //修改押金  

void show();        //显示客户入住情况  

void print();       //统计并显示收入 

void rank();        //客房类型入住量排序

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

void Customer::input(){                  //客户信息录入  

int n;  

cout<<"请输入入住人数"<<endl;  

cin>>room.number;  

cout<<endl;  

for(int i=0;i<room.number;i++){   

cout<<"这是第"<<i+1<<"个客户的信息"<<endl;   

cout<<"输入客人姓名：";   

cin>>customer[i].name;   

cout<<"入住时间(年/月/日)：";   

cin>>customer[i].date;   

cout<<"入住期限：";   

cin>>customer[i].day;   

cout<<"入住押金：";   

cin>>customer[i].money;   

cout<<"每日租金：";   

cin>>customer[i].everydaymoney;   

cout<<"房间号：";   

cin>>customer[i].room.id;   

cout<<"房间等级(1-经济 2-标准 3-豪华)：";   

cin>>customer[i].room.degree;   

cout<<"房间类型(1-单人 2-双人 3-三人)：";   

cin>>customer[i].room.type;   

cout<<"楼层：";   

cin>>customer[i].room.floor;   

cout<<endl; 

}  

cout<<"输入的信息为："<<endl;  

for(int i=0;i<room.number;i++){   

cout<<"客人姓名"<<customer[i].name;   

cout<<"\t入住时间："<<customer[i].date;   

cout<<"\t入住期限："<<customer[i].day;   

cout<<"\t入住押金："<<customer[i].money;   

cout<<"\t每日租金："<<customer[i].everydaymoney;   

cout<<"\t房间号："<<customer[i].room.id;   

cout<<"\t房间等级：";   

if(customer[i].room.degree==1)    

cout<<"经济间";   

else{    

if(customer[i].room.degree==2)     

cout<<"标准间";    

else{     

if(customer[i].room.degree==3)      

cout<<"豪华间";    

}   

}   

cout<<"\t房间类型：";   

if(customer[i].room.type==1)    

cout<<"单人间";   

else{    

if(customer[i].room.type==2)     

cout<<"双人间";    

else{     

if(customer[i].room.type==3)      

cout<<"三人间";    

}   

}   

cout<<"\t楼层："<<customer[i].room.floor;   

cout<<endl;  

}  

ofstream os("customer.txt",ios_base::out|ios_base::binary);  //创建、打开文件  

for(n=0;n<room.number;n++){   

os.write( reinterpret_cast<char*>(&(customer[n])),sizeof(Customer) );  //导出文件  

}  

os.close();  //关闭文件 

}  

int Customer::readIn(){                 //文件读入  

int i,n;  

ifstream is("customer.txt",ios_base::in|ios_base::binary);

if(!is){   

cout<<"打开失败"<<endl;   

return 0;  

}  

for(i=0;is.read( reinterpret_cast<char *>(customer+i) , sizeof(Customer) );i++)  

room.number=i;  

cout<<"导入的表单："<<endl;  

for(n=0;n<room.number;n++){  

cout<<"客人姓名"<<customer[i].name;   

cout<<"入住时间："<<customer[i].date;   

cout<<"入住期限："<<customer[i].day;   

cout<<"入住押金："<<customer[i].money;   

cout<<"每日租金："<<customer[i].everydaymoney;   

cout<<"房间号："<<customer[i].room.id;   

cout<<"房间等级："<<customer[i].room.degree;   

cout<<"房间类型："<<customer[i].room.type;   

cout<<"楼层："<<customer[i].room.floor;  

}  

return 1; 

}  

void Customer::alter(){               //修改客户信息  

int mark = 0;      //设置标记  

int i,m;  

string x;  

cout<<"请输入客户名:";  

do{   

cin>>x;   

cout<<endl;   

for(i=0;i<room.number;i++){    

if(customer[i].name==x){     

mark = 1;     

cout<<"客人姓名"<<customer[i].name;           

cout<<"\t入住时间："<<customer[i].date;           

cout<<"\t入住期限："<<customer[i].day;           

cout<<"\t入住押金："<<customer[i].money;           

cout<<"\t每日租金："<<customer[i].everydaymoney;           

cout<<"\t房间号："<<customer[i].room.id;           

cout<<"\t房间等级：";     

if(customer[i].room.degree==1)             

cout<<"经济间";           

else{            

if(customer[i].room.degree==2) 

cout<<"标准间";            

else{             

if(customer[i].room.degree==3)            

cout<<"豪华间";      

}     

}            

cout<<"\t房间类型：";     

if(customer[i].room.type==1)             

cout<<"单人间";           

else{            

if(customer[i].room.type==2)             

cout<<"双人间";            

else{             

if(customer[i].room.type==3)               

cout<<"三人间";      

}        

}            

cout<<"\t楼层："<<customer[i].room.floor;     

cout<<endl;       

cout<<"修改信息，请输入："<<endl;     

cout<<"输入客人姓名：";              

cin>>customer[i].name;              

cout<<"入住时间：";              

cin>>customer[i].date;              

cout<<"入住期限：";              

cin>>customer[i].day;              

cout<<"每日租金：";               

cin>>customer[i].everydaymoney;              

cout<<"房间号：";               

cin>>customer[i].room.id;               

cout<<"房间等级(1-经济2-标准3-豪华)：";              

cin>>customer[i].room.degree;               

cout<<"房间类型(1-单人2-双人3-三人)：";              

cin>>customer[i].room.type;              

cout<<"楼层：";               

cin>>customer[i].room.floor;              

cout<<endl;    

}    

else;   

}   

if (mark== 0)    

cout<<"输入错误，请重新输入:"<<endl;   

}

while(mark == 0);

ofstream os("customer.txt",ios_base::out|ios_base::binary);  //创建、打开文件  

for(m=0;m<room.number;m++){   

os.write( reinterpret_cast<char*>(&(customer[m])),sizeof(Customer));  //导出文件  

}  

os.close();  //关闭文件 

}  

void Customer::show(){                //客人入住情况查询  

int i;  

for(i=0;i<room.number;i++){   

cout<<"客人姓名"<<customer[i].name;   

cout<<"\t入住时间："<<customer[i].date;   

cout<<"\t入住期限："<<customer[i].day;   

cout<<"\t入住押金："<<customer[i].money;   

cout<<"\t每日租金："<<customer[i].everydaymoney;   

cout<<"\t房间号："<<customer[i].room.id;   

cout<<"\t房间等级：";   

if(customer[i].room.degree==1)    

cout<<"经济间";   

else{    

if(customer[i].room.degree==2)     

cout<<"标准间";    

else{     

if(customer[i].room.degree==3)      

cout<<"豪华间";    

}   

}   

cout<<"\t房间类型：";   

if(customer[i].room.type==1)    

cout<<"单人间";   

else{    

if(customer[i].room.type==2)     

cout<<"双人间";    

else{     

if(customer[i].room.type==3)      

cout<<"三人间";    

}   

}   

cout<<"\t楼层："<<customer[i].room.floor;   

cout<<endl;  

} 

}  

void Customer::findByfloor(){            //显示楼层信息  

int n;  

int mark = 0; //设置标记 

int i;   

cout<<"请输入楼层:";  

do{   

cin>>n;   

cout<<endl;   

for(i=0;i<room.number;i++){    

if(customer[i].room.floor==n){     

mark = 1;     

cout<<"信息如下："<<endl;     

cout<<"客人姓名："<<customer[i].name;           

cout<<"\t入住时间："<<customer[i].date;           

cout<<"\t入住期限："<<customer[i].day;           

cout<<"\t入住押金："<<customer[i].money;           

cout<<"\t每日租金："<<customer[i].everydaymoney;           

cout<<"\t房间号："<<customer[i].room.id;           

cout<<"\t房间等级：";     

if(customer[i].room.degree==1)cout<<"经济间";           

else{            

if(customer[i].room.degree==2)              

cout<<"标准间";            

else{             

if(customer[i].room.degree==3)            

cout<<"豪华间";      

}     

}           

cout<<"\t房间类型：";     

if(customer[i].room.type==1)             

cout<<"单人间";           

else{            

if(customer[i].room.type==2)             

cout<<"双人间";            

else{             

if(customer[i].room.type==3)               

cout<<"三人间";      

}        

}           

cout<<"\t楼层："<<customer[i].room.floor;         

}    

else;   

}   

if (mark== 0)    

cout<<"输入错误，请重新输入:"<<endl; 

}

while(mark == 0); 

}  

void Customer::changemoney(){          //押金修改  

int mark = 0;   //设置标记  

int i,m;  

string x;  

cout<<"请输入客户名:";  

do{   

cin>>x;   

cout<<endl;   

for(i=0;i<room.number;i++){    

if(customer[i].name==x){     

mark = 1;     

cout<<"客人姓名"<<customer[i].name;           

cout<<"\t入住时间："<<customer[i].date;           

cout<<"\t入住期限："<<customer[i].day;           

cout<<"\t入住押金："<<customer[i].money;           

cout<<"\t每日租金："<<customer[i].everydaymoney;           

cout<<"\t房间号："<<customer[i].room.id;           

cout<<"\t房间等级：";     

if(customer[i].room.degree==1)             

cout<<"经济间";           

else{            

if(customer[i].room.degree==2)              

cout<<"标准间";            

else{             

if(customer[i].room.degree==3)            

cout<<"豪华间";      

}     

}           

cout<<"\t房间类型：";     

if(customer[i].room.type==1)             

cout<<"单人间";           

else{            

if(customer[i].room.type==2)             

cout<<"双人间";           

else{          

if(customer[i].room.type==3)   

cout<<"三人间";    

} 

}

cout<<"\t楼层："<<customer[i].room.floor;

cout<<"修改押金，请输入："<<endl;     

cin>>customer[i].money;

cout<<endl;

}

else;

}

if (mark== 0) 

cout<<"输入错误，请重新输入:"<<endl;

}

while(mark == 0);  

ofstream os("customer.txt",ios_base::out|ios_base::binary);  //创建、打开文件 

for(m=0;m<room.number;m++){ 

os.write( reinterpret_cast<char*>(&(customer[m])),sizeof(Customer) );  //导出文件  

} 

os.close();  //关闭文件 

}  

void Customer::print(){              //统计收入  

int n=0; 

for(int i=0;i<room.number;i++){ 

n+=customer[i].everydaymoney*customer[i].day;     //每日租金*入住天数  

} 

cout<<"目前为止的收入为："<<n<<"元"<<endl;

} 

void Customer::rank(){         //客房类型入住量排序

int choose;

int m1=0,m2=0,m3=0;

int n1=0,n2=0,n3=0;

cout<<"1.按房间等级排序；"<<endl; 

cout<<"2.按房间人数排序；"<<endl; 

cout<<"输入你的选择："<<endl; 

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

cout<<"1.经济间"<<endl;

cout<<"2.标准间"<<endl;

cout<<"3.豪华间"<<endl;

if((n1>n2 && n1>n3) && (n3>n2))

cout<<"1.经济间"<<endl;

cout<<"2.豪华间"<<endl;

cout<<"3.标准间"<<endl;

if((n3>n1 && n3>n2) && (n1>n2))

cout<<"1.豪华间"<<endl;

cout<<"2.经济间"<<endl;

cout<<"3.标准间"<<endl;

        if((n3>n1 && n3>n2) && (n2>n1))

cout<<"1.豪华间"<<endl;

cout<<"2.标准间"<<endl;

cout<<"3.经济间"<<endl;

if((n2>n1 && n2>n3) && (n1>n3))

cout<<"1.标准间"<<endl;

cout<<"2.经济间"<<endl;

cout<<"3.豪华间"<<endl;

if((n2>n1 && n2>n3) && (n3>n1))

cout<<"1.标准间"<<endl;

cout<<"2.豪华间"<<endl;

cout<<"3.经济间"<<endl;

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

cout<<"1.单人间"<<endl;

cout<<"2.双人间"<<endl;

cout<<"3.三人间"<<endl;

if((m1>m2 && m1>m3) && (m3>m2))

cout<<"1.单人间"<<endl;

cout<<"2.三人间"<<endl;

cout<<"3.双人间"<<endl;

if((m3>m1 && m3>m2) && (m1>m2))

cout<<"1.三人间"<<endl;

cout<<"2.单人间"<<endl;

cout<<"3.双人间"<<endl;

        if((m3>m1 && m3>m2) && (m2>m1))

cout<<"1.三人间"<<endl;

cout<<"2.双人间"<<endl;

cout<<"3.单人间"<<endl;

if((m2>m1 && m2>m3) && (m1>m3))

cout<<"1.双人间"<<endl;

cout<<"2.单人间"<<endl;

cout<<"3.三人间"<<endl;

if((m2>m1 && m2>m3) && (m3>m1))

cout<<"1.双人间"<<endl;

cout<<"2.三人间"<<endl;

cout<<"3.单人间"<<endl;

break;

default:

cout<<"输入错误，请重新输入！"<<endl;

}

}

void Customer::run(){

bool userExited=false;   

while(!userExited){ 

int userSelection=myMenu.MainMenu();

switch(userSelection){  

case 1:             //客人信息录入    

input(); 

break;

case 2: //显示楼层信息   

findByfloor(); 

break;  

case 3:             //客人入住情况查询  

show(); 

break; 

case 4:             //押金修改   

changemoney();  

break;  

case 5:             //修改客人信息  

alter();  

break;  

case 6:             //统计收入

print(); 

   break;  

case 7:             //客房类型入住量排序

rank();

break;

case 8:             //退出系统   

userExited=true;  

}   

if(userSelection!=8){   

cout<<"流程将返回主界面，";  

system("pause");  

}   

else   

cout<<"你选择了退出功能，程序将结束运行！"; 

}

} 

int main(){ 

Customer myApp; 

myApp.run();

return 0;

}
