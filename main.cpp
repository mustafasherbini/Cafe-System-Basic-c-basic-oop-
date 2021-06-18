#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;
void Spaces(int n){
    for (int i = 0; i <30-n ; ++i) {
        cout<<" ";
    }
}
class Emp{
private:
    double salary;
    double Bonus_month,Deduction_month;
    string FullNAME;
    int age;
    string job;// chef - big chef
    int monthSal[13]={1,1,1,1,1,0,0,0,0,0,0,0};// 12 Month salary if 0 did not take salary using
    // in Monthsal()
public:

    Emp(string name="",int a=0,string Job="",double sal=0){ //deflut constructor - parameterized constructor
        FullNAME = name;
        age = a;
        job = Job;
        salary=sal;
        Bonus_month=Deduction_month=0;

    }

// class methods :function - setters-getter
    void Set_salary(double sal){ salary=sal;}
    double Get_salary(){return salary;}
    void Set_Name(string name){ FullNAME=name;}
    string Get_Name(){return FullNAME;}
    void Set_Job(string j){ job=j;}
    string Get_Job(){return job;}
    void Set_age(int a){age=a;}
    int Get_age(){ return age;}


    void AddBonus(double Bonus){Bonus_month+=Bonus;}
    void AddDeduction(double Deduction){Deduction_month+=Deduction;}
    void pay_sal(int month){
        month--;
        if(monthSal[month]==1)cout<<"== Salary was paid ==";
        else{ //ZERO
            cout<<"Salary:"<<salary<<"\nBounse:"<<Bonus_month<<"\nDeduction:"<<Deduction_month<<"\nTotal:"<<(salary+Bonus_month)-Deduction_month<<endl;
            Bonus_month=Deduction_month=0;
            monthSal[month]=1;
        }
    }


};
class DeliveryMen: public Emp{
private:
    int Numofmoto;
     int num_of_orders;
public:
    DeliveryMen(){
        Numofmoto=0;
        num_of_orders=0;
    }
    void Set_Numofmoto(int num){Numofmoto=num;}
    int Get_Numofmoto(){return Numofmoto;}
   void addorder(){
        num_of_orders++;
    }
    int Get_OrderNum(){
        return num_of_orders;
    }

    ///////////////////////////////////
};
class item{
private:
    string name;
    double price,total;
    int quantity;

public:
    item(string n,double p,int q){
        name=n;
        price=p;
        quantity=q;
        total=(double) quantity*price;
    }
    string Get_name(){return name;}
    double Get_price(){return price;}
    double Get_total(){return total;}
    int Get_quantity(){return quantity;}


};
class Menu{
private:
    double P[12]={10,20,25,27,30,32,35,37,40,42};
    string c[12] ={ "Tea","Cappuccino","Nescafe","French coffee","Turkish coffee","Hazelnut coffee","Latte","Espresso","Mocha Espresso","Hot Chocolate"};
    vector <double>Prices;
    vector<string>names;
public:
    Menu(){
        for (int i = 0; i <10 ; ++i) {
            Prices.push_back(P[i]);
            names.push_back(c[i]);
        }
    }

//menuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu
    void Print_Menu(){

        cout<<"================================================\n\n";
        cout<<" Content";
        Spaces(7);
        cout<<" Price\n";

        for (int i = 0; i <names.size(); ++i) {
            cout<<i+1<<" ||"<<names[i];
            Spaces(names[i].size());
            cout<<Prices[i]<<"$"<<"\n";
        }
        cout<<"================================================\n\n";
    }

    double Get_price(int n){
        return Prices[n-1];
    }
    string Get_Name(int n){
        return names[n-1];
    }

    void Add_Product(string s,double p){
        Prices.push_back(p);
        names.push_back(s);

    }
    void Delete_Product(int num){
        num--;
        Prices.erase(Prices.begin()+num);
        names.erase(names.begin()+num);
    }
    void change_price(int num,double p){
        Prices[num-1]=p;
    }
};
class receipt{
private:
    string date,Cashername;
    vector<item>receiptContent;
    double Tax;
    double total;

public:
    receipt(string d,string n, const vector<item>&v){
        date=d;
        Cashername=n;
        receiptContent=v;
    }
    receipt(){

    }
    void Print_receipt(){
        ofstream  userfile;
        userfile.open("receipt.txt",ios::out|ios::app);
        userfile<<"Cashir Name:"<<Cashername<<"\n";
        for (int i = 0; i <receiptContent.size() ; ++i) {
            userfile<<"Name: "<<receiptContent[i].Get_name()<<"\nQuantity: "<<receiptContent[i].Get_quantity()<<"\nPrice=:"<<receiptContent[i].Get_price()*receiptContent[i].Get_quantity()<<endl;
            total+=receiptContent[i].Get_quantity()*receiptContent[i].Get_price();
        }
        userfile<<"\n\nPrice of products:"<<total<<endl;
        Tax=.14*total;
        userfile<<"Tax:"<<Tax<<endl;
        userfile<<"Total:"<<total+Tax<<"$\n\n\n";
        userfile.close();

    }
    void Print_receipt(string adress){
        ofstream  userfile;
        userfile.open("receipt.txt",ios::out|ios::app);
        userfile<<"Cashir Name:"<<Cashername<<"\n";
        for (int i = 0; i <receiptContent.size() ; ++i) {
            userfile<<"Name: "<<receiptContent[i].Get_name()<<"\nQuantity: "<<receiptContent[i].Get_quantity()<<"\nPrice=:"<<receiptContent[i].Get_price()*receiptContent[i].Get_quantity()<<endl;
            total+=receiptContent[i].Get_quantity()*receiptContent[i].Get_price();
        }
        userfile<<" Price of products:"<<total<<endl;
        Tax=.14*total;
        userfile<<"Tax:"<<Tax<<endl;
        userfile<<"Delving:"<<10<<"$\n";
        userfile<<"Total:"<<total+Tax+10<<"$\n";
        userfile<<"Adress:"<<adress<<"\n\n\n";



        userfile.close();

    }
    void ReadAllRecipts(){

        cout << "Enter one to print";
        int n;
        cin >> n;
        string line;
        ifstream myfile;
        myfile.open("receipt.txt");
        if (myfile.is_open()) {
            myfile.ignore();
            while (!myfile.eof()) {
                getline(myfile, line);
                cout << line << '\n';
            }
            myfile.close();
        } else cout << "Unable to open file";
    }



};
class Manger{
    Emp Chefs[100];int ChefsNum;
    Emp Waiters[100];int WaitersNum;
    DeliveryMen Deliver[100];int DeliverNum;
    Emp Cashers[100];int CashersNum;

public:
    Manger(){
        Chefs[0].Set_salary(4000);  Chefs[0].Set_age(30);Chefs[0].Set_Job("Chef");Chefs[0].Set_Name("Samir Ahmed");
        Chefs[1].Set_salary(6000);   Chefs[1].Set_age(35);Chefs[1].Set_Job("Big Chef");;Chefs[1].Set_Name("Ahmed mourad");
        Chefs[2].Set_salary(4500);Chefs[2].Set_age(31);Chefs[2].Set_Job("Chef");Chefs[2].Set_Name("Khald Sabry");
        Waiters[0].Set_salary(3500);  Waiters[0].Set_age(22);Waiters[0].Set_Job("Waiter");Waiters[0].Set_Name("Osama Ahmed");
        Waiters[1].Set_salary(3500);   Waiters[1].Set_age(21);Waiters[1].Set_Job("Waiter");;Waiters[1].Set_Name("Moaz Hassan ");
        Waiters[2].Set_salary(3500);Waiters[2].Set_age(25);Waiters[2].Set_Job("Waiter");Waiters[2].Set_Name("Adel Mousa");
        Cashers[0].Set_salary(3500);  Cashers[0].Set_age(30);Cashers[0].Set_Job("Casher");Cashers[0].Set_Name("Abdallh Omar");
        Cashers[1].Set_salary(3500);   Cashers[1].Set_age(31);Cashers[1].Set_Job("Casher");Cashers[1].Set_Name("Hasan Osama");
        Deliver[0].Set_salary(3000);  Deliver[0].Set_age(23);Deliver[0].Set_Job("Delivery");Deliver[0].Set_Name("Asem Abdallh");
        Deliver[1].Set_salary(3000);   Deliver[1].Set_age(25);Deliver[1].Set_Job("Delivery");;Deliver[1].Set_Name("Amir Teaima");
        Deliver[0].Set_Numofmoto(7566); Deliver[1].Set_Numofmoto(9654);
        ChefsNum=3;WaitersNum=3;DeliverNum=2;CashersNum=2;
    }
    void  AddEmployee(){
        string inputname,inputjop;
        int input,inputage,moto;
        double inputsalary;
        //************************************************************************************************2524





        cout<<"***| Please select the depratment |***\n" ;
        cout<<"(1)Chefs\n(2)Waiters\n(3)Cashers\n(4)Deliver\n ";
        cout<<"choise: ";
        cin>>input;

        cout<<"\n\n";

        cout<<"***| Please put Name,Salary,Age, jop |***\n";

        cout<<"Name: ";    cin>>inputname;
        cout<<"Salary: ";  cin>>inputsalary;
        cout<<"Age: ";     cin>>inputage;
        cout<<"jop: ";     cin>>inputjop;

        if(input==1){Chefs[ChefsNum].Set_Name(inputname);Chefs[ChefsNum].Set_salary(inputsalary);Chefs[ChefsNum].Set_age(inputage);Chefs[ChefsNum].Set_Job(inputjop);ChefsNum++;}
        if(input==2){Waiters[WaitersNum].Set_Name(inputname);Waiters[WaitersNum].Set_salary(inputsalary);Waiters[WaitersNum].Set_age(inputage);Waiters[WaitersNum].Set_Job(inputjop);WaitersNum++;}
        if(input==3){Cashers[CashersNum].Set_Name(inputname);Cashers[CashersNum].Set_salary(inputsalary);Cashers[CashersNum].Set_age(inputage);Cashers[CashersNum].Set_Job(inputjop);CashersNum++;}
        if(input==4){cout<<"***| Put Moto Number |***\n";cin>>moto;Deliver[DeliverNum].Set_Name(inputname);Deliver[DeliverNum].Set_salary(inputsalary);Deliver[DeliverNum].Set_age(inputage);Deliver[DeliverNum].Set_Job(inputjop);Deliver[DeliverNum].Set_Numofmoto(moto);DeliverNum++;}

    }

    void Complaints_and_suggestions(){
        cout<<"Enter one to print\n";
        int n;
        cin>>n;
        string line;
        ifstream myfile ;
        myfile.open("CustomersOpinions.txt");
        if (myfile.is_open())
        {
            cin.ignore();
            while (!myfile.eof())

            {
                getline(myfile,line);
                cout << line << '\n';
            }
            myfile.close();
        }

        else cout << "Unable to open file";

    }

    void EmployeeInformations(){
        int Informationsinput;
        cout<<"----------------------------------------------\n";
        cout<<"(1)Chefs\n(2)Waiters\n(3)Cashers\n(4)Deliver\n ";
        cout<<"----------------------------------------------\n";


        cout<<"***| Please select the depratment |***\n" ;
        cout<<"choise: ";cin>>Informationsinput;

        cout<<"\n Name";Spaces(4);     cout<<"Salary";Spaces(5);    cout<<"Age";Spaces(3);   cout<<"jop\n";
        cout<<"_________________________________________________________________________________________________\n";
        if(Informationsinput==1){
            for (int i = 0; i <ChefsNum ; ++i) {cout<<i+1<<"-"<<Chefs[i].Get_Name();Spaces(Chefs[i].Get_Name().size());cout<<Chefs[i].Get_salary(); Spaces(4);cout<<Chefs[i].Get_age();Spaces(2);cout<<Chefs[i].Get_Job()<<endl;
            }}
        if(Informationsinput==2){
            for (int i = 0; i <WaitersNum ; ++i) {cout<<i+1<<"-"<<Waiters[i].Get_Name();Spaces(Waiters[i].Get_Name().size());cout<<Waiters[i].Get_salary(); Spaces(4);cout<<Waiters[i].Get_age();Spaces(2);cout<<Waiters[i].Get_Job()<<endl;}}
        if(Informationsinput==3){
            for (int i = 0; i <CashersNum ; ++i) {cout<<i+1<<"-"<<Cashers[i].Get_Name();Spaces(Cashers[i].Get_Name().size());cout<<Cashers[i].Get_salary(); Spaces(4);cout<<Cashers[i].Get_age();Spaces(2);cout<<Cashers[i].Get_Job()<<endl;}}
        if(Informationsinput==4){
            for (int i = 0; i <DeliverNum ; ++i) {cout<<i+1<<"-"<<Deliver[i].Get_Name();Spaces(Deliver[i].Get_Name().size());cout<<Deliver[i].Get_salary(); Spaces(4);cout<<Deliver[i].Get_age();Spaces(2);cout<<Deliver[i].Get_Job()<<endl;}}
    }
    int EmployeeInformations(int n){
        int Informationsinput;
        cout<<"----------------------------------------------\n";
        cout<<"(1)Chefs\n(2)Waiters\n(3)Cashers\n(4)Deliver\n ";
        cout<<"----------------------------------------------\n";


        cout<<"***| Please select the depratment |***\n" ;
        cout<<"choise: ";cin>>Informationsinput;

        cout<<"\n Name";Spaces(4);     cout<<"Salary";Spaces(5);    cout<<"Age";Spaces(3);   cout<<"jop\n";
        cout<<"_________________________________________________________________________________________________\n";
        if(Informationsinput==1){
            for (int i = 0; i <ChefsNum ; ++i) {cout<<i+1<<"-"<<Chefs[i].Get_Name();Spaces(Chefs[i].Get_Name().size());cout<<Chefs[i].Get_salary(); Spaces(4);cout<<Chefs[i].Get_age();Spaces(2);cout<<Chefs[i].Get_Job()<<endl;
            }}
        if(Informationsinput==2){
            for (int i = 0; i <WaitersNum ; ++i) {cout<<i+1<<"-"<<Waiters[i].Get_Name();Spaces(Waiters[i].Get_Name().size());cout<<Waiters[i].Get_salary(); Spaces(4);cout<<Waiters[i].Get_age();Spaces(2);cout<<Waiters[i].Get_Job()<<endl;}}
        if(Informationsinput==3){
            for (int i = 0; i <CashersNum ; ++i) {cout<<i+1<<"-"<<Cashers[i].Get_Name();Spaces(Cashers[i].Get_Name().size());cout<<Cashers[i].Get_salary(); Spaces(4);cout<<Cashers[i].Get_age();Spaces(2);cout<<Cashers[i].Get_Job()<<endl;}}
        if(Informationsinput==4){
            for (int i = 0; i <DeliverNum ; ++i) {cout<<i+1<<"-"<<Deliver[i].Get_Name();Spaces(Deliver[i].Get_Name().size());cout<<Deliver[i].Get_salary(); Spaces(4);cout<<Deliver[i].Get_age();Spaces(2);cout<<Deliver[i].Get_Job()<<endl;}}
        return Informationsinput;
    }

    Emp* ChooseEmp(){
        int group,num;
        group=EmployeeInformations(1);
        cout<<"***| Please Select the employee |***";
        cin>>num;
        if(group==1) return &Chefs[num-1];
        if(group==2) return &Waiters[num-1];
        if(group==3) return &Cashers[num-1];
        if(group==4) return &Deliver[num-1];

    }



};
class login{
private:
    string MangerPass,CacherPass;
public:
    login(){
        MangerPass="man123";
        CacherPass="cash123";
    }
    string getMangerPass(){  return MangerPass; }
    string getCacherPass(){  return CacherPass; }


};


void Spaces(int n);


//mainnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
int main() {

    int Maininput;
    Menu menu1;
    string password,CasherName,today;
login log;
    cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
    cout<<"||||||||||                    welcome Dear                      |||||||||||\n";
    cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

    cout << "\n\n";

    Point:
    cout << " Please Select a Number of These Divisions  \n";
    cout << "---------------------------------------------\n";
    cout << "(1)Casher        (2)Manger        (3)Customer\n";
    cout << "---------------------------------------------\n";

    cout << "\n";
    cout << "Iput:";
    cin >> Maininput;
    cout << "\n";

    if(Maininput==1){

        cout << "***| Enter The Password |***\n";
        cout << "password:";cin>>password;
        cout << "\n";

        if(password!=log.getCacherPass()){cout<< " Wrong Password ! \n"; password="";goto Point;}

        cout << "***| Enter Your Full Name |***\n";
        cout << "Full Name:";cin.ignore();
        getline(cin,CasherName);
        cout << "\n";
        cout << "***| Enter Date >> (Day/Month/Year) |***\n";
        cout << "Date:";cin>>today;
        cout << "\n";



        cout << "                    Welcome: "<< CasherName << "     ^_^ " << endl;

        cashpoint:
        cout<<"   //////////////////////////////////////////////////////////////////////\n";
        cout<<"  /////  (1)MENU  (2)Inside Order  (3)Outside Order  (4)MainMenu   /////\n";
        cout<<" //////////////////////////////////////////////////////////////////////\n";

        cout << "input:"; cin >> Maininput;cout << "\n";

        if(Maininput==1){
            menu1.Print_Menu();
            cout<<"\n\n\n";
            goto cashpoint;
        }else if(Maininput==2||Maininput==3){

            vector<item>v;
            menu1.Print_Menu();
            bool c= true;
            while (c){

                int input,quantity,boolian;
                cout<<"***| Choose the product |*** \n";
                cout<<" product: "; cin>>input;
                cout<<"***| Enter the quantity |*** \n";

                cout<<" quantity: ";cin>>quantity;
                item product(menu1.Get_Name(input),menu1.Get_price(input),quantity);


                v.push_back(product);
                cout<<"***| Press (1) to End order |*** \n";
                cout<<"Input:";cin>>boolian;
                if(boolian==1)c= false;
            }

            receipt re (today,CasherName,v);
            if(Maininput==2) re.Print_receipt();
            else if(Maininput==3){
                string add;
                cout<<"Pleas Enter the Adress\n";
                cin.ignore();
                getline(cin,add);
                re.Print_receipt(add);
            }
//------------------------------------------------------------x
            cout<<"==Receipt Was Printed==\n";
        };



    }else if(Maininput==2){
        cout << "***| Enter The Password |***\n";
        cout<<"password: "; cin>>password;
        if(password!=log.getMangerPass()){cout<<"Wrong Password !\n";goto Point;}
        Manger Admin;
        cout<<"\n\n";
        mangerpoint:

        cout<<"°~°~°~°~°~°~°~°~°~°~°°~°~°~°~°~°~°~°~°~°~°°~°~\n";
        cout<<"(1)Employees Staff\n(2)Menu control\n(3)Analysis\n(4)Complaints and suggestions\n(5)MainMenu\n";
        cout<<"°~°~°~°~°~°~°~°~°~°~°°~°~°~°~°~°~°~°~°~°~°°~°~\n";

        cout<<"***| Choose a Number |*** \n";
        cout<<"Input: ";cin>>Maininput;

        cout<<"\n\n";

        if(Maininput==5)goto Point;
        if(Maininput==1){
            int inputemp;

            cout<<"_________________________________________________________ \n";
            cout<<"(1)Employees Informations \n(2)AddEmployee \n(3)AddPounse\n(4)Deduction from salary\n(5)Pay salary\n(6)Change Salary\n(7)Back\n";
            cout<<"_________________________________________________________ \n";

            cout<<"***| Choose a Number |*** \n";
            cout<<"choise: ";
            cin>>inputemp;
            if(inputemp==1)Admin.EmployeeInformations();
            if(inputemp==2)Admin.AddEmployee();
            if(inputemp==3||inputemp==4||inputemp==5||inputemp==6){
                Emp*ptr;
                int n;
                em:
                ptr=Admin.ChooseEmp();
                if(inputemp==3){
                    double pou;
                    cout<<"***| Please Put The amount |*** \n";
                    cin>>pou;
                    ptr->AddBonus(pou);
                    cout<<" ## Done ! ##\n";
                }
                if(inputemp==4){
                    double Dec;
                    cout<<"***| Please Put The amount |***\n";
                    cin>>Dec;
                    ptr->AddDeduction(Dec);
                    cout<<" ## Done ! ##\n";
                }
                if(inputemp==5){
                    int m;
                    cout<<"***| Enter the number of this month |***";
                    cin>>m;
                    ptr->pay_sal(m);
                }
                if(inputemp==6){
                    double newsal;
                    cout<<"***| Enter the new salary |***";
                    cin>>newsal;
                    ptr->Set_salary(newsal);
                }



                cout<<"***| if you want to Choose another Employee Enter one |***\n";
                cout<<"Choise:";cin>>n;

                if(n==1)goto em;

            }
            goto mangerpoint;


        }
        if(Maininput==2){
            cout<<"################################################################\n";
            cout<<"# (1)Add Product (2)Change Price (3)Delete Product (4)Back #\n";
            cout<<"################################################################\n";
            cout<<"Choise:";cin>>Maininput;
            ppoint:

            if(Maininput==1){
                string s;
                double n;
                cout<<"***| Enter The Product Name |***\n";

                cout<<"Name: ";cin>>s;
                cout<<"\n";

                cout<<"***| Enter The Product Price |***\n";


                cout<<"Price: ";cin>>n;
                cout<<"\n";

                menu1.Add_Product(s,n);
                cout<<"\n == Done !==";
                goto mangerpoint;
            }else if(Maininput==2||Maininput==3){
                menu1.Print_Menu();
                cout<<"***| Enter The Number of The Product |***\n";
                int n;

                cout<<"Input: ";cin>>n;

                if(Maininput==2){
                    double p;
                    cout<<"\n";

                    cout<<"***| Enter New Price |***\n";

                    cin>>p;

                    menu1.change_price(n,p);
                    cout<<"== Done !==\n";

                }
                if(Maininput==3){
                    int n;
                    cin>>n;
                    menu1.Delete_Product(n);
                    cout<<"== Done !==\n";
                }

            } else goto mangerpoint;
            int bb;
            cout<<"***| if you want to do it again enter (1) |***\n";
            cout<<"Input: ";cin>>bb;

            if(bb==1) goto ppoint;
            else goto mangerpoint;
        }

        if(Maininput==3){
            cout<<"(1)Read All Receipt\n(2)Back\n";
            cout<<"Input: ";
            int input;
            cin>>input;

            if(input==1){
                receipt t;
                t.ReadAllRecipts();
            }




            cout<<"\n\n\n\n";
            goto mangerpoint;

        }
        if(Maininput==4){
            Admin.Complaints_and_suggestions();
            goto mangerpoint;
        }



    }else if(Maininput==3){


        cout<<"  //////////////////////////////////////////////////////\n";
        cout<<" ///// (1)Complaints & suggestions  (2)MainMenu   /////\n";
        cout<<"//////////////////////////////////////////////////////\n";

        cout<<"Input: ";cin>>Maininput;
        if(Maininput==1){
            string n,phone,txt;
            cout<<"***| Please Enter Your Full Name |***\n";

            cout<<"Name: ";
            cin.ignore();
            getline(cin,n);
            cout<<"\n";

            cout<<"***| Please Enter Your Number |***\n";
            cout<<"Number: ";cin>>phone;

            cout<<"\n";
            cout<<"***| Write your Complaints or Suggestions |***\n";

            cout<<"Suggestions:\n";

            cin.ignore();
            getline(cin,txt);
                ofstream  userfile;
                userfile.open("CustomersOpinions.txt",ios::out|ios::app);

            userfile<<"Name: "<<n<<"\nPhone Number: "<<phone<<"\nText: "<<txt<<"\n\n\n\n";

            userfile.close();

            cout<<"***| Done, Thank you |***\n";
            goto Point ;
        }else goto Point;

    }else{
        cout<<"***| Wrong Input Try Again ! |***\n";

    }


    return 0;
}