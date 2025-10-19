#include <iostream>
#include <cstring>
using namespace std;

class Bank
{
    private:
        string name;
        string account_number;
        double salary;

    public:
       void set_data()
       {
            cin.ignore();  
            cout<<"Enter Name: "<<endl;
            getline(cin, name);

            cout<<"Enter The Account Number: "<<endl;
            cin>>account_number;

            cout<<"Enter The Salary: "<<endl;
            cin>>salary;
            
       } 
 

        void deposit(double amount)
        {
            salary+=amount;
            cout<<"Amount Deposited. New Balance: "<<salary<<endl;
        }


        void withdraw(double amount)
        {
            if(amount>salary)
            {
                cout<<"Insufficient balance !"<<endl;
            }else{
                salary-=amount;
                cout<<"Amount Withdraw Remaining Balace: "<<salary<<endl;   
            }
        }    


        void display()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Accound Number: "<<account_number<<endl;
            cout<<"Salary: "<<salary<<endl;
        }

};


int main()
{
    Bank B1;
    int choice;
    double amount;

    do{

        cout<<"----Bank System----"<<endl;
        cout<<"1. Creat Account."<<endl;
        cout<<"2. Deposite The Money."<<endl;
        cout<<"3. Withdraw The Money."<<endl;
        cout<<"4. Display The Details."<<endl;
        cout<<"5. Exit Program"<<endl;

        cin>>choice;
        switch(choice)
        {
            case 1:
                B1.set_data();
                break;

            case 2:
                cout<<"Enter The Amount: "<<endl;
                cin>>amount;
                B1.deposit(amount);
                break;

            case 3:
                cout<<"Enter The Amount: "<<endl;
                cin>>amount;
                B1.withdraw(amount);
                break;

            case 4:
                B1.display();
                break;

            case 5:
                cout<<"Exiting Program GOOD BYE."<<endl;
                break;

            default:
                cout<<"Invalid Choice !, Try Again." <<endl;
       }
   }while(choice !=5);

   return 0;
}