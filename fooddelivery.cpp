#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <list>
using namespace std;
typedef struct food
{
    string foodname;
    int amount;
    int price;
}food;
int earnofmine = 0;
list <food> mystore;
list <food>::iterator it;
///storing all food in the linked list
void storeFoodList()
{
    food temp;
    string s;
    int p,n,stock;///taking all input price how many food and stock
    cout<<"How many food in my shop"<<endl;
    scanf("%d",&n);
    cout<<"We have "<<  n << " foods in our foodshop "<<endl;
    for(int i = 1; i<=n; i++)
    {///this portion is taking the 3 variable in the linked list
        cout<<"Name of the food"<<endl;
        cin>>s;
        cout<<"Price of the food"<<endl;
        cin>>p;
        cout<<"Amount of that food"<<endl;
        cin>>stock;
        temp.foodname=s;
        temp.price =p;
        temp.amount = stock;
        mystore.push_back(temp);///this is main transfering the price amount and foodname in the linked list
    }
}
/// this is for searching and this working when i am pressing 1
void searchTheFood()
{
    bool paisi = false;
    string wantedfood;
    cin>>wantedfood;
    for(it = mystore.begin(); it!=mystore.end(); it++)
    {///traversing the list
        if(it->foodname==wantedfood)
        {
            cout<<wantedfood<<"\nThis food is available in our shop"<<endl;
            paisi = true;
            break;
        }
    }
    if(!paisi)
    {
        cout<<wantedfood <<"\nThis food is not available in our shop"<<endl;
    }
}
///displaying my store information when i am pressing 2
void displaymystore()
{
    for(it = mystore.begin(); it!=mystore.end(); ++it)
    {
        cout<<"\nName of Food"<<endl<<it->foodname<<endl;
        cout<<"\nAmount of food"<<endl<<it->amount<<endl;
        cout<<"Price of the food"<<endl<<it->price<<endl;
    }
}
///serving food to the customer
void servingCustomer()
{
    int customer,count1 = 1;
    string nameofcustomer;
    cout<<"How many customer in the line??"<<endl;
    cin>>customer;
    cout<<"Enter the name please!"<<endl;
    ///stack for desired food
    ///queue for request list
    stack <string> namelist;
    queue <string> lineofcustomer;
    for(int i = 1; i<=customer; i++)
    {
        cin>>nameofcustomer;
        lineofcustomer.push(nameofcustomer);
    }
    while(!lineofcustomer.empty())
    {
        cout<<"Serving the number " << count1 <<  " customer " <<  lineofcustomer.front()  <<endl;
        int howmanyfood;
        cout<<"How Many food do u want??"<<endl;
        scanf("%d",&howmanyfood);
        string fodname;
        cout<<"Enter Your desired food"<<endl;
        for(int i = 1; i<=howmanyfood; i++)
        {
            cin>>fodname;
            namelist.push(fodname);
        }
        while(!namelist.empty())
        {
            bool marker= false;
            for(it=mystore.begin(); it!=mystore.end(); it++)
            {
                if(namelist.top()==it->foodname)
                {
                    marker = true;
                    int count;
                    cout << it->foodname << " is FOUND in the store\nHow many unit of " << it->foodname << " needed? : ";
                    cin>>count;
                    it->amount-=count;
                    if(it->amount >= 0)
                    {
                        cout << it->foodname << " has been served.\n";
                        earnofmine += count * it->price;
                        //break;
                    }
                    else
                    {
                        cout << "Sorry, " << it->foodname << " Wait some time its stock has finished.\n";
                        it->amount += count;
                    }
                    //marker = true;
                    //break;
                }
            }
            if(marker==false)
            {
                cout<<namelist.top()<<"it is not in the shop";
            //    namelist.pop();
            }
            count1++;
            namelist.pop();
        }

        lineofcustomer.pop();
    }
}
///shop earning
void myearning()
{
    if(earnofmine > 0)
        cout << "After selling foods, total earnings of my shop is : " << earnofmine << " taka.\n";
    else
        cout << "No food is sold yet.\n";
}
int main()
{
    int choice;
    storeFoodList();
    while(1)
    {
        cout<<"  \nPress 1 to know which food is in my shop\n";
        cout<<"  \nPress 2 to know my store  information\n";
        cout<<"  \nPress 3 to serve  food to the customer\n";
        cout<<"  \nPress 4 to know  my shop's earning\n";
        cout<<"  \nPress 5 to exit from my application\n";
        cout << "\nEnter your choice : ";
        cin >> choice;
        if(choice == 1)
            searchTheFood();
        else if(choice == 2) displaymystore();
        else if(choice == 3) servingCustomer();
        else if(choice == 4) myearning();
        else if(choice ==5)
           return 0;
    }
    return 0;
}
