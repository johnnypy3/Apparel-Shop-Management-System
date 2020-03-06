# Apparel-Shop-Management-System
Implemented an Apparel Shop Manager which performs basic functionalities such as bill calculation,daily bill sheet generation,
sales analysis,warehouse updates,stock updates,vendor information etc.
Tried to utilize C++ programming to its core potential by using STL,File Handling etc.

Functions used:-
	1. Class Warehouse:
A. void refill_stock()- For refilling product stock.
			2. Class Receptionist: Inherits Warehouse
•	float calc_total_cost()-
Calculates total amount of bill,product stock available and gives final amount after call to functions of tax_calc() and discount_calc().
•	void login_check_receptionist()- username and password check for receptionist.
•	float tax_calc()- Calculates and returns tax added amount(GST).
•	float discount_calc()- Calculates and returns discounted final amount,if any discount has been provided.
•	void print_bill()-Uses File-Handling concept to print bill of individual customer into text file format.
•	void print_daily_billsheet()- Uses File-Handling concept to print bill of all the customers for each day. Maintains bill records. 
3. Class Admin: Inherits Receptionist(also Warehouse)
•	void print_daily_collection()-Prints daily tallied amount for the shop.
•	void sales_analysis()- Analyses sales of the shop and shows which products are in more demand.
•	float calc_daily_expanse()-Shows daily expanse for the shop.
•	void login_check_admin()-username and password check for admin.
•	void reminder_payment()- Reminds admin of pending dues of vendors(if any)
•	void vendor_info()- Prints “.CSV”file to record all the vendor information.
•	void stock_warehouse_update()-Updates the current product availability with that of warehouse.
4. int main()- object creation for classes and menu driven programming used effectively.

Data Structures Used:
	1.Array—Widely used for,
•	character arrays
•	array of objects-Customers
•	product_stock_qty—Stores initial value of quantity of products.
•	Array of structures.
2.  Stack---  Used for maintain records of various bill amounts(tax and discount too)
Maintaining vector(STL) in stack.
Push(),pop(),top() operations performed widely.
3. Queue:
•	Deque- Maintaining Product IDs
o	Enqueuef(),dequeuer(),front() widely used.
•	Priority Queues- Arranging Product IDs according to the Product Quantities.

OOP Concepts Used:
•	OOP features(Class and Objects) 
o	Data Abstraction 
o	Encapsulation 
o	Inheritance (Multi-Level)
•	File Handling 
•	Standard Template Library 
•	Vector 
•	Templates 
•	Structures 


5	RESULT

-------------------------Tasks Performed--------------------------------------

1.	Login 
a.	Admin(Secured) 
b.	Receptionist(Secured---Accessible to Admin) 
2.	Billing System(Discount Suggestion + GST Rates Added) 
3.	Stock Updates/Report 
4.	Warehouse Updates 
5.	Daily Collection/Monthly Collection(Updated at Runtime) 
6.	Daily Bill Sheet (To keep record of Customer Bills) 
7.	Vendor Information(including Payment reminders, if any) 




6	CONCLUSION:
All the fore-mentioned tasks are performed by the program efficiently, thus the solution of our problem statement is implemented successfully.

