#include<iostream>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string.h>
#include<fstream>
using namespace std;
struct Receipt
{
    int product_code;
    int qty;//quantity
    int price;
    int product_cost;
}rec_1;
stack<float> Stack;
priority_queue<int> gq;
queue<int> product_list;
static int product_stock_qty[20];
class Warehouse
{
    protected:
    int size;
    public:
    void refill_stock()
    {
        int i;
        size=0;
        for(i=0;i<16;i++)
        {
            size++;
            product_stock_qty[i]=10;
        }
    }
};
class Receptionist: public Warehouse
{
    protected: 
    vector<Receipt> recobj;
    float total_cost;
    char name[20];
    public:
    Receptionist()
    {
        //cust_no++;
        total_cost=0;
        rec_1.product_cost=0;
        rec_1.qty=0;
        rec_1.price=0;
    }
    float calc_total_cost()
    {
        char ch1,ch2;
        int key,temp_var;
        do
        {
            cout<<"\n\t\tEnter Product Code(0-15)\t";
            cin>>rec_1.product_code;
            if(rec_1.product_code<0 && rec_1.product_code>15)
            {
                cout<<"Invalid Product Code\nTry Entering Again(1-15)";
            }
            cout<<"\n\t\tEnter Cost of the product\t";
            cin>>rec_1.price;
            cout<<"\n\t\tEnter Product Quantity\t";
            cin>>rec_1.qty;
                key=rec_1.product_code;
                for(int i=0;i<=size;i++)
                {
                    if(key==i)
                    {
                        product_stock_qty[i]=product_stock_qty[i]-rec_1.qty;
                        temp_var=i;
                        gq.push(product_stock_qty[temp_var]);
                        product_list.push(key);
                        break;
                    }
                }
            rec_1.product_cost=rec_1.price*rec_1.qty;
            recobj.push_back(rec_1);
            cout<<"\n\t\tAdd another product?(Y/N)\t";
            cin>>ch1;
        }while(ch1=='Y'||ch1=='y');
        for(int i=0;i<recobj.size();i++)
        {
            total_cost+=recobj[i].product_cost;
        }
        cout<<"\n\t\t**************Bill Info****************"<<endl;
        cout<<"\n\t\tProduct Code\t\tProduct Price\t\tQuantity of Products"<<endl;
        for(int i=0;i<recobj.size();i++)
        {
            cout<<"\n\t\t"<<recobj[i].product_code<<"\t\t\t\t"<<recobj[i].price<<"\t\t\t\t"<<recobj[i].qty<<endl;
        }
        //cust_no++;
        cout<<"\n\t\t\t\tTotal Cost:\t\t"<<total_cost;
        cout<<"\n\t\tCheck availability of products?(Y/N)\t";
        cin>>ch2;
        if(ch2=='Y'||ch2=='y')
        {
            cout<<"\n\t\tProduct Code"<<"\t"<<"Product Quantity"<<endl;
            rec_1.product_code=0;
            for(int i=0;i<size;i++)
            {
                cout<<"\n\t\t"<<rec_1.product_code<<"\t"<<product_stock_qty[i];
                rec_1.product_code++;
            }
            return total_cost;
        }
        else
        {
            return total_cost;
        }
    } 
    float tax_calc(float total_cost_temp,int if_no_disc)
    {
        float tax1,tax2;
        float tax_total;
        if(if_no_disc==1)
        {
            Stack.push(total_cost_temp);
        }
        tax1=0.05;
        tax2=0.12;
        if(total_cost_temp<=1000)
        {
            tax_total=(tax1*total_cost_temp)+total_cost_temp;
            cout<<"\n\t\tGrand Total:\t"<<tax_total<<endl;
            return tax_total;
        }
        else
        {
            tax_total=(tax2*total_cost_temp)+total_cost_temp;
            cout<<"\n\t\tGrand Total:\t"<<tax_total<<endl;
            return tax_total;
        }
    }
    void login_check_receptionist()
    {
        char username;
        int password;
        int loginAttempt;
        loginAttempt=0;
        cout<<"\n\t\tReceptionist Login\n";
        while (loginAttempt<5)
        {
            cout<<"\n\t\tPlease enter your user name: \t";
            cin>>username;
            cout<<"\n\t\tPlease enter your user password: \t";
            cin>>password;
            if(username=='a' && password == 12345)
            {   
                cout<<"\n\t\t*******Welcome Prathamesh!*******\n";
                break;
            }
            else if(username == 'b' && password == 12345)
            {   
                cout<<"\n\t\t*****Welcome Onkar!******\n";
                break;
            }
            else
            {
                cout << "\n\t\tInvalid login attempt. Please try again.\n" << "\n";
                loginAttempt++;
            }
        }
        if (loginAttempt == 5)
        {
            cout << "Too many login attempts! \nThe program will now terminate.";
            //return 0;
        }
        cout << "\n\t\tThank you for logging in.\n";
    }
    float discount_calc(float total_cost_bfdisc,float disc_rate)
    {
        disc_rate=disc_rate*0.01;
        float total_cost_afdisc;
        total_cost_afdisc=total_cost_bfdisc-(disc_rate*total_cost_bfdisc);
        Stack.push(total_cost_afdisc);
        return total_cost_afdisc;
    }
    void print_bill(float total_cost_cust,float grand_total,int cust_id)
    {
        char cust_name[20];
        long long int cust_phno;
        ofstream fob;
        fob.open("invoice.txt",ios::out);
        if(fob.fail())
        {
            cout<<"Error in Opening the file\n";
        }
        fob<<"\n\t\t**************Bill Info****************"<<endl;
        fob<<"---------------------------------------------------------------------------------"<<endl;
        cout<<"\n\t\tEnter name:\t\t";
        cin>>cust_name;
        cout<<"\n\t\tEnter Contact Info:\t\t";
        cin>>cust_phno;
        fob<<"\t\t"<<"Customer Name:\t\t"<<cust_name<<endl;
        fob<<"\t\t"<<"Customer Contact:\t\t"<<cust_phno<<endl;
        fob<<"\t\tCustomer Number:\t\t"<<cust_id<<endl;
        fob<<"--------------------------------------------------------------------------------"<<endl;
        fob<<"\n\t\tProduct Code\t\tProduct Price\t\tQuantity of Products"<<endl;
        for(int i=0;i<recobj.size();i++)
        {
            fob<<"\n\t\t"<<recobj[i].product_code<<"\t\t\t\t"<<recobj[i].price<<"\t\t\t\t"<<recobj[i].qty<<endl;
        }
        fob<<"\n\t\t\t\tTotal Cost:\t\t"<<total_cost_cust;
        fob<<"\n\t\t\t\tGrand Total(Total Cost+Tax):\t\t"<<grand_total;
        print_daily_billsheet(total_cost_cust,grand_total,cust_id,cust_name,cust_phno);
        fob.close();
    }
    void print_daily_billsheet(float total_cost_cust,float grand_total,int cust_id,char cust_name[],long long int cust_phno)
    {
        ofstream fob;
        fob.open("BillSheet.txt",ios::out|ios::app);
        if(fob.fail())
        {
            cout<<"Error in Opening the file\n";
        }
        fob<<"\n\t\t**************Bill Info****************"<<endl;
        fob<<"---------------------------------------------------------------------------------"<<endl;
        fob<<"\t\t"<<"Customer Name:\t\t"<<cust_name<<endl;
        fob<<"\t\t"<<"Customer Contact:\t\t"<<cust_phno<<endl;
        fob<<"\t\tCustomer Number:\t\t"<<cust_id<<endl;
        fob<<"--------------------------------------------------------------------------------"<<endl;
        fob<<"\n\t\tProduct Code\t\tProduct Price\t\tQuantity of Products"<<endl;
        for(int i=0;i<recobj.size();i++)
        {
            fob<<"\n\t\t"<<recobj[i].product_code<<"\t\t\t\t"<<recobj[i].price<<"\t\t\t\t"<<recobj[i].qty<<endl;
        }
        fob<<"\n\t\t\t\tTotal Cost:\t\t"<<total_cost_cust;
        fob<<"\n\t\t\t\tGrand Total(Total Cost+Tax):\t\t"<<grand_total<<endl;
        fob<<"--------------------------------------------------------------------------------"<<endl;
        fob.close();
    }
};
static float daily_total_expanse;
class Admin:public Receptionist
{
    public:
    void sales_analyses()
    {
        int min,temp_prod_code;
        //int product_codes_temp[product_list.size()];
        //int prod_analysis_operation_temp[gq.size()];
        cout<<"\n\t\t*******Products in High Demand*******\n\n";
        cout<<"\n\t\tProduct Code"<<"\t\t"<<"Product Quantity"<<endl;
        int i=0;
        while(!gq.empty())
        {
            cout<<"\n\t\t"<<product_list.front();
            //product_codes_temp[i]=product_list.front();
            product_list.pop();
            cout<<"\t\t"<<gq.top();
            //prod_analysis_operation_temp[i]=gq.top();
            gq.pop();
            //i++;
        }
        {
            cout<<"\n\t\tYour best product is about to be SoldOut\n";
            cout<<"\n\t\tPlease refill"<<endl;
        }
    }
    float calc_daily_expanses()
    {
        //float temp_var;
        daily_total_expanse=0;
        while(!Stack.empty())
        {
            daily_total_expanse+=Stack.top();
            Stack.pop();
        }
        print_daily_collection(daily_total_expanse);
        return daily_total_expanse;
        //cout<<"\n\t\tDaily Shop Collection:\t"<<daily_total_expanse;
    }
    void print_daily_collection(float daily_collection)
    {
        // Declaring argument for time() 
        time_t tt;  
        struct tm * ti;// Declaring variable to store return value of // localtime()  
        time (&tt); // Applying time() 
        ti = localtime(&tt); // Using localtime()
        //cout << "Current Day, Date and Time is = " << asctime(ti);   
        ofstream fob1;
        fob1.open("DailyCollection.txt",ios::out);
        if(fob1.fail())
        {
            cout<<"Error in Opening the file\n";
        }
        fob1<<"\n\t\t**************Daily Collection****************"<<endl;
        fob1<<"\n\tCollection for Day:"<<asctime(ti)<<"\t"<<"----"<<daily_collection<<endl;
        fob1.close();
    }
    void vendor_info()
    {
        ofstream fob;
        fob.open("vendor.csv",ios::out|ios::app);
        fob<<"Sr.No,First Name,Last Name,Payment Pending"<<endl;
        fob<<"1,Rupak,Ghanpathi,2000"<<endl;
        fob<<"2,Zaid,Inamdar,1000"<<endl;
        fob.close();
    }
    void stock_warehouse_update()
    {
        ofstream fob;
        fob.open("Warehouse.txt",ios::out);
        if(fob.fail())
        {
            cout<<"Error in Opening the file\n";
        }
        fob<<"*************Warehouse Status****************"<<endl;
        fob<<"\n\t\tProduct Code"<<"\t"<<"Product Quantity"<<endl;
        rec_1.product_code=0;
        for(int i=0;i<16;i++)
        {
            fob<<"\n\t\t\t"<<rec_1.product_code<<"\t\t"<<product_stock_qty[i];
            rec_1.product_code++;
        }
        fob.close();
    }
    void reminder_payment()
    {
        ifstream fin;
        string line;
        fin.open("vendor.csv",ios::in);
        if(fin.fail())
        {
            cout<<"Error in Opening the file\n";
        }
        cout<<"\n\t\t*****Data of Vendors with Pending Payment*****"<<endl;
        fin.seekg(0,ios::beg);
        while(fin)
        {
            getline(fin,line);
            cout<<line<<endl;
        }
        fin.close();
    }
    void login_check_admin()
    {
        char username;
        int password;
        int loginAttempt;
        loginAttempt=0;
        while(loginAttempt < 5)
        {   
            cout<<"\n\t\tPlease Enter Your UserName: \t";
            cin>>username;
            cout<<"\n\t\tPlease Enter Your Password: \t";
            cin>>password;
            if (username == 'p' && password == 1234)
            { 
                cout<<"\n\t\t*******Welcome Prathamesh!*******\n";
                break;
            }
            else if (username == 'o' && password == 1234)
            {  
                cout<<"\n\t\t*****Welcome Onkar!******\n";
                break;
            }
            else
            {
                loginAttempt++;
                cout << "\n\t\tInvalid login attempt. Please try again.\n" << "\n";
            }
        }
        if (loginAttempt == 5)
        {
            cout << "Too many login attempts! \nThe program will now terminate.";
            //return 0;
        }
        cout << "Thank you for logging in.\n";
    }
};
static int cust_no;
int main()
{
    int ch,cho,press_1,i;
    i=0;
    char ch1,ch2,ch3,ch4,discount_yn;
    float total_cost_cust;
    float grand_total;
    float daily_coll,disc_rate,total_cost_afdisc;
    int cust_id,if_no_disc;
    if_no_disc=0;
    daily_coll=0;
    Receptionist login_ob,customer[10];
    Warehouse stock1;
    Admin ob1;
    do
    {
        cout<<"\t\t**********Welcome**********"<<endl;
        cout<<endl;
        cout<<"\n\t\t1.Login as Admin\n\t\t2.Login as Receptionist\t";
        cin>>ch;
        switch(ch)
        {
            case 1: //Admin
                    ob1.login_check_admin();
                    cout<<"\t\t**********Greetings Admin*********\n\n";
                    cout<<"\t\t**********Hope You are having a good day**********\n";
                    do
                    {
                        cout<<"\t\t1.Daily Collection\n\t\t2.Daily Bill Sheet\n\t\t3.Stock Update\n\t\t4.Display Vendor Info(Pending Payments)\n\t\t5.Sales Analysis\t"<<endl;
                        cin>>cho;
                        switch(cho)
                        {
                            case 1:daily_coll=ob1.calc_daily_expanses();
                                    cout<<"\n\t\tDaily Collection:\t"<<daily_coll;
                                    break;
                            case 2:ob1.print_daily_collection(daily_coll);
                                    cout<<"---------------------------------"<<endl;
                                    cout<<"\n\t\tDaily Collection Sheet Printed"<<endl;
                                    break;
                            case 3:ob1.stock_warehouse_update();
                                    cout<<"\n\t\tWarehouse Stock Printed"<<endl;
                                    break;
                            case 4:ob1.reminder_payment();
                                    break;
                            case 5:ob1.sales_analyses();
                                    break;
                            default:cout<<"\n\t\tPlease Provide an valid input\n";
                                    break;
                        }cout<<"\n\t\tLookin for something else ,Admin?(Y/N)\t";
                        cin>>ch4;
                    }while(ch4=='Y'||ch4=='y');
                    break;
            case 2: login_ob.login_check_receptionist();
                    cout<<"\t\t**********Hey There Receptionist!*********\n\n";
                    cout<<"\n\t\t*********Hope You are having a good day**********\n";
                    if(i==0)
                    {
                        customer[i].refill_stock();
                    }
                        do
                        {
                            cout<<"\n\t\ta.Billing Window\t";
                            cin>>ch1;
                            switch(ch1)
                            {
                                case 'a':
                                        total_cost_cust=customer[i].calc_total_cost();
                                        cout<<"\n\t\tDiscount Applicable?(Y/N)\t";
                                        cin>>discount_yn;
                                        if(discount_yn=='Y'||discount_yn=='y')
                                        {
                                            cout<<"\n\t\tEnter Discount Percent\t";
                                            cin>>disc_rate;
                                            if_no_disc=0;
                                            total_cost_afdisc=customer[i].discount_calc(total_cost_cust,disc_rate);
                                            grand_total=customer[i].tax_calc(total_cost_afdisc,if_no_disc);
                                        }
                                        else
                                        {
                                            if_no_disc=1;
                                            grand_total=customer[i].tax_calc(total_cost_cust,if_no_disc);
                                        }
                                        cout<<"\n\t\tDo You Want to Print the Bill?Press 1.\t";
                                        cin>>press_1;
                                        if(press_1==1)
                                        {
                                            cust_no=i;
                                            customer[i].print_bill(total_cost_cust,grand_total,cust_no+1);
                                            //customer[i].print_daily_billsheet(total_cost_cust,grand_total,cust_no+1);
                                            i++;
                                            break;
                                        }
                                        else
                                        {
                                            cout<<"\n\t\tPlease Enter A Valid Input like 1\t";
                                        }
                                        break;
                                default:cout<<"\n\t\tPlease Provide an valid input\n";
                                        break;
                            }
                            cout<<"\n\t\tAdd another customer?(Y/N)\t";
                            cin>>ch2;
                        }while(ch2=='Y'||ch2=='y');
                    break;
            default:cout<<"\n\t\tSystem doesn't allow unauthorized users\n\t\tPlease Provide an valid input\n"<<endl;
        }cout<<"\n\t\tPerform another operation?(Y/N)\t";
        cin>>ch3;
    }while(ch3=='Y'||ch3=='y');
    return 0;
}