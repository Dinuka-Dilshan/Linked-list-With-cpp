#include <iostream>
#include <conio.h>

using namespace std;


struct node{
	
	int value;
	node *next;
	
};

void insert(int value, node *&head){
		
		
		if(head==NULL){
			head=new node();
			head->value=value;
			head->next=NULL;
		}else{
			
			node *check=head;
			while(check->next!=NULL){
				check=check->next;
			}
			node *temp=new node();
			temp->value=value;
			temp->next=NULL;
			check->next=temp;
			
		}
		
		
	}
	
void insert(int position,int value, node *&head){
	
	node *temp=head;
	for(int x=0;x<position-1;x++){
		temp=temp->next;
	}
	temp->value=value;
}	

void print(node* head){
		
		
		while(head->next!=NULL){
			cout<<head->value<<endl;
			head=head->next;
		}
	
		cout<<head->value<<endl;
	
	}	
	
int add(node* head){
	
	int sum=0;
	
	while(head->next!=NULL){
		sum=sum+(head->value);
		head=head->next;
	}
	
	return sum+head->value;
}

void deleteValue(int elementPosition, node *&head){
	
	node *temp=head;
	
	if(elementPosition==1)	{
		head=head->next;	
	}
	else if(elementPosition==0){
		
	}
	else{
		elementPosition-=2;
		
		for(int x=0;x<elementPosition;x++){
			temp=temp->next;
		}
		
		node *temp2=temp->next;
		temp->next=	temp2->next;
	}
	
	
}


void orderAcc(int listLength, node *&head){
	int temp;
	node *num;
	node *save=head;
	if(listLength==1||listLength==0){
		
	}
	else{
		
	for(int x=0;x<(listLength-1);x++){
		
		for(int y=0;y<listLength-1;y++){
			
				num=head->next;
				
				if(head->value>num->value){
					temp=head->value;
					head->value=num->value;
					num->value=temp;
				}
			head=head->next;
		}
		head=save;
	}
		head=save;		
	}
	
}

void orderDec(int listLength, node *&head){
	int temp;
	node *num;
	node *save=head;
	
	if(listLength==1||listLength==0){
		
	}else{
			for(int x=0;x<(listLength-1);x++){
				
				for(int y=0;y<listLength-1;y++){
			
						num=head->next;
				
						if(head->value<num->value){
						temp=head->value;
						head->value=num->value;
						num->value=temp;
						}
						head=head->next;
				}
						head=save;
			}
						head=save;
	}
	
}

int main(){
	
	node *head=NULL;
	int num,user,del;
	bool on=true;
	string input;
	bool listOk=false;
	
	while(on){
	
		system("cls");
		 cout<<"1.Create a List and Enter Numbers:\n2.Print\n3.print sum\n4.Accending order\n5.Decending Order\n6.Add Values To positions\n7.Add new Values(Automated)\n8.Delete \n9.exit"<<endl;
		 cin>>input;
		 system("cls");
		 if(input=="1"){
		 	if(listOk){
		 		cout<<"List Already created..! You can use add values to the list Using add menu..!";
			 }else{
		     cout<<"How much numbers do you want to add?"<<endl;
			 cin>>num;
			 for(int x=0;x<num;x++){
				cout<<"Enter: ";
				cin>>user;
				insert(user,head);
			} listOk=true;	
			system("cls");
			cout<<"Added Successfully..!\n Press any key to return to main menu."<<endl;
					 	
			 }

		 }
		 else if(input=="2"){
		 	if(listOk){
		 		cout<<"List: "<<endl;
		 		print(head);
			 }else{
			 	cout<<"Idiot..!Create A list first..!"<<endl;
			 }
		 }
		 else if(input=="3"){
		 	if(listOk){
		 		cout<<"sum is: "<<add(head);
			 }else{
			 	cout<<"Idiot..!Create A list first..!"<<endl;
			 }
		 }
		 else if(input=="4"){
		 	if(listOk){
		 		orderAcc(num,head);
		 		cout<<"Ordered Successfully..!"<<endl;
			 }else{
			 	cout<<"Idiot..!Create A list first..!"<<endl;
			 }
		 }
		  else if(input=="5"){
		 	if(listOk){
		 		orderDec(num,head);
		 		cout<<"Ordered Successfully..!"<<endl;
			 }else{
			 	cout<<"Idiot..!Create A list first..!"<<endl;
			 }
		 }
		 else if(input=="6"){
		 	if(listOk){
		 		cout<<"LIST HAS ONLY "<<num<<" ELEMENTS..!\n"<<endl;
		 		cout<<"Enter the Position You Want To Add.."<<endl;
		 		cin>>del;
		 		
		 		if(del>num||del<0){
		 			system("cls");
		 			cout<<"LIST HAS ONLY "<<num<<" ELEMENTS..!"<<endl;
		 			cout<<"Press Any Key To Return To Main Menu"<<endl;
				 }else{
				 		cout<<"Enter the Value You Want To Add.."<<endl;
		 				cin>>user;
				 		insert(del,user,head);
		 				system("cls");
		 				cout<<"Successfully Added..!"<<endl;
				 }
		 		
		 		
		 		
			 }else{
			 	cout<<"Idiot..!Create A list first..!"<<endl;
			 }
		 }
		 else if(input=="7"){
		 	if(listOk){
		 		cout<<"Enter the Value You Want To Add.."<<endl;
		 		cin>>user;
		 		insert(user,head);
		 		system("cls");
		 		num++;
		 		cout<<"Successfully Added..!"<<endl;
			 }else{
			 	cout<<"Idiot..!Create A list first..!"<<endl;
			 }
		 }
		 else if(input=="8"){
		 	if(listOk){
		 		cout<<"LIST HAS ONLY "<<num<<" ELEMENTS..!\n"<<endl;
		 		cout<<"Enter the element position that you want to delete:"<<endl;
				cin>>del;
				if(del>num||del<0){
					system("cls");
		 			cout<<"LIST HAS ONLY "<<num<<" ELEMENTS..!"<<endl;
		 			cout<<"Press Any Key To Return To Main Menu"<<endl;
				 }else{
				 	deleteValue(del,head);
				 	num--;
					system("cls");
					cout<<"Deleted Successfully"<<endl;
				 }
				
	
			 }else{
			 	cout<<"Idiot..!Create A list first..!"<<endl;
			 }
		 }
		 else if(input=="9"){
		 		on=false;
		 }
		 else {
		    	cout<<"Invalid Input..!"<<endl;
		 }
		 	getch();
	}
	
	
	
	return 0;
}
