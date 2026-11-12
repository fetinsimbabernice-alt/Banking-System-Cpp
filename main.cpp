#include <iostream>

using namespace std;

//Declared Variables
string name[3] = {"Bernice", "Jeriel", "Oralee"};
int accountNumbers[3] = {101, 102, 103};
double balance[3] = {6000, 12000, 18000};
//Deposit
void deposit()
{
    int account, confirm;
    double depositAmount;
    bool found = false;

    cout<<"Enter account number:"<<endl;
    cin>>account;
    for(int i = 0; i < 3; i++)
    {
       if(account == accountNumbers[i])
       {
           found = true;
           cout<<"Please confirm account details:"<<endl;
           cout<<"Account holder:"<<name[i]<<endl;
           cout<<"Account number:"<<accountNumbers[i]<<endl;

           cout<<"Enter 1 to Continue."<<endl;
           cout<<"Enter 2 to Cancel."<<endl;
           cin>>confirm;

           if(confirm == 1)
           {
               cout<<"Enter amount to deposit: R"<<endl;
               cin>>depositAmount;
           }


       if(depositAmount > 0)
       {
           balance[i] = balance[i] + depositAmount;
           cout<<"Deposit successful!"<<endl;
           cout<<"R"<<depositAmount<<"was deposited into"<<name[i]<<"'s account."<<endl;
           cout<<"New balance: R"<<balance[i]<<endl;
       }
        else
           {
               cout<<"Deposit unsuccessful!"<<endl;
               cout<<"Invalid deposit amount."<<endl;
           }
           break;
       }
    }

    if(found == false)
    {
        cout<<"Deposit unsuccessful!"<<endl;
        cout<<"Account number not found."<<endl;
    }
}
//Withdraw
void withdraw()
{
    int account;
    double withdrawalAmount;
    bool found = false;

    cout<<"Enter account number:"<<endl;
    cin>>account;
    for(int i = 0; i < 3; i++)
    {
       if(account == accountNumbers[i])
       {
           found = true;
           cout<<"Account verified!"<<endl;
           cout<<"Welcome, " << name[i] <<endl;
           cout<<"Enter amount to withdraw: R"<<endl;
           cin>>withdrawalAmount;

       if(withdrawalAmount > 0 && withdrawalAmount <= balance[i])
       {
           balance[i] = balance[i] - withdrawalAmount;
           cout<<"Withdrawal successful!"<<endl;
           cout<<"R"<<withdrawalAmount<<"withdrawn from"<<name[i]<<"'s account."<<endl;
           cout<<"remaining balance: R" <<balance[i] <<endl;
       }
           else
           {
               cout<<"Withdrawal unsuccessful!"<<endl;
               cout<<"Insufficient funds."<<endl;
           }
           break;
       }
    }


    if(found == false)
    {
        cout<<"Withdrawal unsuccessful!"<<endl;
        cout<<"Account number not found."<<endl;
    }
}
//Send Cash
void sendcash()
{
    int senderAccount, receiverAccount;
    int senderIndex = -1, receiverIndex;
    int confirm;
    double sendAmount;

    cout<<"Enter sender's account number:"<<endl;
    cin>>senderAccount;

    for(int i = 0; i < 3; i++)
    {
        if(senderAccount == accountNumbers[i])
        {
            senderIndex = i;
        }
    }
    if(senderIndex != -1)
    {
        cout<<"Sender account verified!"<<endl;
        cout<<"Sender:"<<name[senderIndex]<<endl;
        cout<<"Enter receiver's account number:"<<endl;
        cin>>receiverAccount;

        for(int i = 0; i < 3; i++)
        {
            if(receiverAccount == accountNumbers[i])
            {
                receiverIndex = i;
            }
        }
        if(receiverIndex != -1 && receiverIndex != senderIndex)
        {
            cout<<"Please confirm receiver details:"<<endl;
            cout<<"Receiver:"<< name[receiverIndex] <<endl;
            cout<<"Account number:"<< accountNumbers[receiverIndex] <<endl;
            cout<<"Enter 1 to Continue."<<endl;
            cout<<"Enter 2 to Cancel."<<endl;
            cin>>confirm;

            if(confirm == 1)
            {
                cout<<"Enter amount to send: R"<<endl;
                cin>>sendAmount;
            }

            if(sendAmount > 0 && sendAmount <= balance[senderIndex])
            {
                balance[senderIndex] = balance[senderIndex] - sendAmount;
                balance[receiverIndex] = balance[receiverIndex] + sendAmount;

                cout<<"Transfer successful!"<<endl;
                cout<< name[senderIndex] <<"sent R" <<sendAmount <<"to " << name[receiverIndex] <<"."<<endl;
                cout<<"Sender's remaining balance: R" <<balance[senderIndex] << endl;
                cout<<"Receiver's new balance: R"<< balance[receiverIndex] <<endl;
            }
            else
            {
                cout<<"Insufficient funds or invalid amount!"<<endl;
            }
        }
    }
}
//Balance
void checkBalance()
{
    int account;
    bool found = false;

    cout<<"Enter account number:"<<endl;
    cin>>account;

    for(int i = 0; i < 3; i++)
    {
        if(account == accountNumbers[i])
        {
            found = true;
            cout<<"Account holder:"<<name[i]<<endl;
            cout<<"Account number:"<<accountNumbers[i]<<endl;
            cout<<"Available balance: R"<<balance[i]<<endl;
            break;
        }
    }
    if(found == false)
    {
        cout<<"Account not found!"<<endl;
    }
}
//Menu
void menu()
{
    int choice;
    cout<<"Enter 1 to Deposit."<<endl;
    cout<<"Enter 2 to Withdraw."<<endl;
    cout<<"Enter 3 to Send Cash."<<endl;
    cout<<"Enter 4 to Check Balance ."<<endl;
    cout<<"Enter 5 to Exit."<<endl;
    cout<<"Enter your choice:"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
            deposit();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            sendcash();
            break;
        case 4:
            checkBalance();
            break;
        case 5:
            cout<<"Thank you for using our banking system!"<<endl;
            return;
        default:
            cout<<"Invalid choice. Please try again."<<endl;
    }

}
//Display of bank system
int main()
{
    menu();
    return 0;
}
