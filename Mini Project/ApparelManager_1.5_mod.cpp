#include<iostream>
#include<apparelmanager.h>
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
        cout<<"\t\t********************Welcome*******************"<<endl;
        cout<<endl;
        cout<<"\t\t********************Apparel Manager*******************"<<endl;
        cout<<endl;
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
                        cout<<"\t\t1.Daily Collection\n\t\t2.Daily Bill Sheet\n\t\t3.Stock Update\n\t\t4.Display Vendor Info(Pending Payments)\n\t\t5.Sales Analysis\t";
                        cin>>cho;
                        cout<<endl;
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