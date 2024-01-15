#ifndef RESTAURANT_H 
#define RESTAURANT_H
#include <iostream>
#include <string>
#include<sstream>
#include <cstdlib>												//for atoi
#include <algorithm> 											//for trimming

using namespace std;
bool onlyLetter(string na){										//function for checking string contains letter only
	int length = na.length();
	for (int i=0; i<length; i++){
		int n = na[i];
		if (!isalpha(n) && !isspace(n))
			return false;
	}
	return true;
}

bool onlyNum (string st){										//function for checking string contains number only
	int slength = st.length();
	for (int i=0; i<slength; i++){
		int s = st[i];
		if (!isdigit(s)) return false;
	}
	return true;
}

bool onlyDateNo (string da, string mth, string yr){				//function for checking string date contains number only
	int dlength = da.length();                                  //Check the string of day that contains number only
	for (int i=0; i<dlength; i++){
		int d = da[i];
		if (!isdigit(d))
			return false;
	}
	
	int mlength = mth.length();                                 //Check the string of month that contains number only
	for (int i=0; i<mlength; i++){
		int m = mth[i];
		if (!isdigit(m))
			return false;
	}
	
	int ylength = yr.length();                                  //Check the string of year that contains number only
	for (int i=0; i<ylength; i++){
		int y = yr[i];
		if (!isdigit(y))
			return false;
	}
	return true;
}

string trim(string s)  													//function for removing the spaces of the string
{
    s.erase(remove(s.begin(), s.end(), ' '), s.end()); 
    return s; 
}
	
bool leap(string y){													//function for checking the year is leap or not
	int yr = atoi(y.c_str());
if ((yr%400==0) || (yr%4==0 && yr%100!=0)) return true; 
} 

bool wrongDate(string d, string m, string y) {							//function for checking the date format is correct or not
	int da = atoi(d.c_str());                                           //Atoi can convert string value into integer value
	int mth = atoi(m.c_str());
	int yr = atoi(y.c_str());
	
    if (da<1 || da>31) return true;
    if (mth<1 || mth>12) return true;
	if (yr<1000 || yr>=10000) return true; 
    if (mth==2){
    	if (leap(y)) return (da>29);
    
		else return (da>28);
    } 
    if (mth==4 || mth==6 ||mth==9 || mth==11) return (da>30);
    return false; 
}

int countNum(int num){							          			  //function for counting the numbers
    int count = 0; 
    while (num != 0) { 
        num = num / 10; 
        ++count; 
    } 
    return count; 
}

struct record{														//create a structure called record as node
	string name;                                                    //declaration of the variables
	int pHead;
	int pTail; 
	string day; 
	string month;
	string year;
	int hour;
	int minute;
	string time;
	int numOfPax; 
	string refId;
	record *link;
}*head;

class reservation{													//create a class called reservation as linked list
	public:	
		int getCount(){     										 //function for counting the records
			int count = 0;
			record *current = head;
			while (current != NULL){
				count++;
				current = current->link;
			}
			return count;	
		}
		
		void bubbleSort(record *current){                       //function for sorting the reference id according to first come first serve
			int swapped, i;										//declaration of the variables
			string temp1;
			int temp2 ;
            int temp3;
            string temp4;
            string temp5;
            string temp6;
            int temp7;
            int temp8;
            string temp9;
            int temp10;
            string temp11;
			record *p;
			record *q = NULL;
			if (current == NULL)
				return;
			do{
				swapped = 0;
				p = current;
				while(p->link != NULL){
			
					if (atoll(p->refId.c_str()) < atoll(p->link->refId.c_str())){          //Compare the reference ID and sort the smallest to biggest
						temp1 = current->name;                                             //Atoll is to convert the string value to long long int value
						current->name = current->link->name;
						current->link->name = temp1;
						
						temp2 = current->pHead;
						current->pHead = current->link->pHead;
						current->link->pHead = temp2;
						
						temp3 = current->pTail;
						current->pTail = current->link->pTail;
						current->link->pTail = temp3;
						
						temp4 = current->day;
						current->day = current->link->day;
						current->link->day = temp4;
						
						temp5 = current->month;
						current->month = current->link->month;
						current->link->month = temp5;
												
						temp6 = current->year;
						current->year = current->link->year;
						current->link->year = temp6;
						
						temp7 = current->hour;
						current->hour = current->link->hour;
						current->link->hour = temp7;
						
						temp8 = current->minute;
						current->minute = current->link->minute;
						current->link->minute = temp8;
						
						temp9 = current->time;
						current->time = current->link->time;
						current->link->time = temp9;
						
						temp10 = current->numOfPax;
						current->numOfPax = current->link->numOfPax ;
						current->link->numOfPax = temp10;
						
						temp11 = current->refId;
						current->refId = current->link->refId;
						current->link->refId = temp11; 
						
						swapped = 1;
					}
					p = p->link;
				}
				p=q;
			}while(swapped);
		}
		
		void enRecord(string na, int pH, int pTa, string da, string mth, string yr, int hr, int min, string tim, int pax, string id){         //function for assigning the new record
			record *newNode = new record;
			newNode->name = na;
			newNode->pHead = pH;
			newNode->pTail = pTa;			
			newNode->day = da;
			newNode->month = mth;
			newNode->year = yr;			
			newNode->hour = hr;	
			newNode->minute = min;
			newNode->time = tim;			
			newNode->numOfPax = pax;
			newNode->refId = id;			
			newNode->link = head;
			head = newNode;
		}
		
		void deFirstRecord(){                 //function for deleting the very first record
			record *p = head;
			record *current = head;
			char ans;
			cout << "************************************************************************************************************************\n";
			cout<<"                                                    Records"<<endl<<endl;
			cout << "************************************************************************************************************************\n";
			cout<<"Name: "<<current->name<<endl<<                                  //Show the first record for the user
			"Phone Number: "<<"0"<<current->pHead<<"-"<<current->pTail<<endl<<
			"Date: "<<current->day<<"/"<<current->month<<"/"<<current->year<<endl<<
			"Time: "<<current->time<<endl<<
			"Number of Pax: "<<current->numOfPax<<endl;
			cout << "________________________________________________________________________________________________________________________\n";
			while(true){
				cout << "Are you sure you want to delete this record? (y/n): ";           //Give user to input y or n on the record deletion
				cin>>ans;
				if(ans!='y' && ans!='n' && ans!='Y' && ans!='N'){             //If user input anything else that is not y or n, it tells the user to key in again
					cout<<"Invalid input.\n";                                   
					cout<<"Please key in y or n to continue.\n";
				}
				else if (ans=='y'|| ans=='Y'){                                // if user key in y, it will delete the record
					head=head->link;
					delete p;
					cout << "Delete Successful" <<endl;
					cout << "________________________________________________________________________________________________________________________\n";
					break; 
				}
				else if (ans=='n'||ans=='N'){                               // if user key in n, it will break the loop, system will stop asking user to enter
					cout << "________________________________________________________________________________________________________________________\n";
					break;
				}	
			}
		}
			
		void deLastRecord(){               //function for deleting the record by following first come first serve
			record *p, *q;
			q=head;
			record *current = head;
			char ans;
			cout << "************************************************************************************************************************\n";
			cout<<"                                                     Records"<<endl<<endl;
			cout << "************************************************************************************************************************\n";
			while (current!=NULL){
				if (current->link == NULL){                                       //Show the first record for the user
					cout<<"Name: "<<current->name<<endl<<
					"Phone Number: "<<"0"<<current->pHead<<"-"<<current->pTail<<endl<<
					"Date: "<<current->day<<"/"<<current->month<<"/"<<current->year<<endl<<
					"Time: "<<current->time<<endl<<
					"Number of Pax: "<<current->numOfPax<<endl;
				cout << "________________________________________________________________________________________________________________________\n";
				}
				current = current->link;
			}
			while(true){
				cout << "Are you sure you want to delete this record? (y/n): ";            //Give user to input y or n on the record deletion
				cin>>ans;
				if(ans!='y' && ans!='n' && ans!='Y' && ans!='N'){               //If user input anything else that is not y or n, it tells the user to key in again
					cout<<"Invalid input.\n";                                   
					cout<<"Please key in y or n to continue.\n";
				}
				else if (ans=='y'|| ans=='Y'){                             // if user key in y, it will delete the record
				while(q->link != NULL){
					p=q;
					q=q->link;
				}
				p->link = NULL;
				delete q;
				cout << "Delete Successful" <<endl;
				cout << "________________________________________________________________________________________________________________________\n"; 	
				break;
				}
				else if (ans=='n'||ans=='N'){                           // if user key in n, it will break the loop, system will stop asking user to enter
					cout << "________________________________________________________________________________________________________________________\n";
					break;
				}	
			}
		}
		
		bool dupRecord(string na, int pH, int pTa){       //function for checking the duplicate records
			record *current = head;
			while (current != NULL){
				if (current->name == na && current->pHead == current->pHead && current->pTail == pTa){
					return false;
				}
				current=current->link;
			}
			return true;
		}
		
		void updateRecord(string na, int pH, int pTa){         //function for updating the record
			record *current = head;
			int count, rCount;
			char ans;
			string tempPH, tempPTa, tempHr, tempMin, tempPax, tempAns;
			while (current != NULL){
				if (current->name == na && current->pHead == current->pHead && current->pTail == pTa){
					cout << "************************************************************************************************************************\n";
					cout<<"                                                    Searched Records"<<endl<<endl;
					cout << "************************************************************************************************************************\n";
					cout<<"Name: "<<current->name<<endl<<                       //Show the searched record
					"Phone Number: "<<"0"<<current->pHead<<"-"<<current->pTail<<endl<<
					"Date: "<<current->day<<"/"<<current->month<<"/"<<current->year<<endl<<
					"Time: "<<current->time<<endl<<
					"Number of Pax: "<<current->numOfPax<<endl;
					cout << "________________________________________________________________________________________________________________________\n";                                                    
					while(true){                                                 //Give user to input y or n on the record updation
						cout << "________________________________________________________________________________________________________________________\n"; 
						cout << "Do you want to update this record? (y/n): ";
						cin>>ans;
						if(ans!='y' && ans!='n' && ans!='Y' && ans!='N'){           //If user input anything else that is not y or n, it tells the user to key in again
						cout<<"Invalid input.\n";                                   
						cout<<"Please key in y or n to continue.\n";                                              
					}
						else if (ans=='y'|| ans=='Y'){                         // if user key in y, it will let the user to update the record
						cout << "________________________________________________________________________________________________________________________\n";                                                     
						cout <<"                                                          | NAME |"<<endl;
						do{
							cin.ignore(1000,'\n');
							cout<<"Name: ";                                     //Let user to enter the name
							getline(cin, current->name);
							if (onlyLetter(current->name) == true){
							int length = current->name.length();
							for (int i=0; i<length; i++){
							int n = current->name[i];
							if (islower(n))
								current->name[i] = toupper(n);
							}
							current->name=trim(current->name);
							}
							else
							cout<<"Numbers and symbols are not allowed. Please try again!"<<endl<<endl;
						}while (onlyLetter(current->name) == false);
		
						cout <<"                                                      | PHONE NUMBER |"<<endl;
						while(true){ 
							cout<<"Country code: ";                                //Let user to enter the country code and phone number
							getline(cin,tempPH);
							tempPH= trim(tempPH);
							current->pHead = atoi(tempPH.c_str());
							count=countNum(current->pHead);
							if(count!=2 || current->pHead<10 || current->pHead>19 || !(onlyNum(tempPH))){
								cin.clear();
		    					cout << "\nInvalid input. Please try again" << endl;
		    					cout<<"Please follow the format: 01X"<<endl;
							}
						else break;
						}	                   
						while(true){
							cout<<"Phone number excluding the country code: ";
							getline(cin,tempPTa);
							tempPTa= trim(tempPTa);
							current->pTail = atoi(tempPTa.c_str());
							count=countNum(current->pTail);
							if(count!=7 || !onlyNum(tempPTa)){
								cin.clear();
							    cout << "\nInvalid input. Please try again." << endl;
							    cout<<"Please make sure it is a 7 digit number, excluding the country code."<<endl;
							}
							else break;
						}
	
						cout <<"                                                          | DATE |"<<endl;
						do{
							cout<<"Day: ";                                         //Let user to enter the day, month and year
							getline(cin, current->day);
							cout<<"Month: ";
							getline(cin, current->month);
							cout<<"Year: ";
							getline(cin, current->year);
							if (onlyDateNo (current->day, current->month, current->year) == false){
							cout << "Please key in numbers only." <<endl<<endl;
							}
							else if (wrongDate (current->day, current->month, current->year) == true){
								cout << "Please enter a valid date." <<endl<<endl;
 	  						}
						}while (wrongDate(current->day,current->month,current->year) == true || onlyDateNo (current->day, current->month, current->year) == false);
	
						cout <<"                                                          | TIME |"<<endl;
						while(true){
							cout<<"Hour: ";                                       //Let user to enter the hour and minute
	    					getline(cin,tempHr);   
							tempHr= trim(tempHr);
							current->hour = atoi(tempHr.c_str());
							if(current->hour>23 || current->hour<0 || !onlyNum(tempHr)){
								cin.clear();
							    cout << "\nInvalid input. Please try again." << endl;
							    cout<<"Please make sure the time is in 24 hours format."<<endl;
							}
							else break;
						}
						while(true){
							cout <<"Minute: ";
	    					getline(cin,tempMin);
							tempMin= trim(tempMin);
							current->minute = atoi(tempMin.c_str());
							if(current->minute<0 || current->minute>59 || !onlyNum(tempMin)){
								cin.clear();
		    					cout << "\nInvalid input. Please try again." << endl;
							}	
							else break;
						}
						stringstream hString; 							//To convert the hour and minutes to string called time, and showing the leading zero
						hString<<current->hour;
						string hStr;
						hString>>hStr;
						stringstream mString; 
						mString<<current->minute;
						string mStr;
						mString>>mStr;
						if(current->hour<=9) current->time= "0"+ hStr;
						else current->time = hStr;
						if(current->minute>=0 && current->minute<10) current->time =current->time+":0"+mStr;
						else current->time =current->time+":"+mStr;
		
						cout <<"                                                           | PAX |"<<endl;
						while(true){
							cout<<"Number of Pax: ";                                //Let user to enter the number of pax
							getline(cin,tempPax);
							tempPH= trim(tempPax);
							current->numOfPax = atoi(tempPax.c_str());
							if(current->numOfPax<1 || !onlyNum(tempPax)){
								cin.clear();                             
							    cout << "\nInvalid input. Please try again." << endl;	
							}
							else if(current->numOfPax>120 || !onlyNum(tempPax)) cout<<"The maximum of pax is 120."<<endl;
							else break;
						}
						if(current->month.length()==1) current->refId = current->year + "0" + current->month;
						else current->refId = current->year + current->month;
						if(current->day.length()==1) current->refId = current->refId + "0" + current->day + current->time;
						else current->refId = current->refId + current->day + current->time;
						cout << "________________________________________________________________________________________________________________________\n";
						rCount++;
						break;
						}
						else if (ans=='n'||ans=='N') break;                          // if user key in n, it will break the loop, system will stop asking user to enter          
					}
				}
				current = current->link;
			}
			if (rCount > 0){
				cout << "												 Update Successful!"<<endl;
				cout << "________________________________________________________________________________________________________________________\n";
			}
			else if (ans == 'n'){
				cout << "________________________________________________________________________________________________________________________\n";
			}
			else{
				cout << "________________________________________________________________________________________________________________________\n";
				cout << "											      No record founded."<<endl;
				cout << "________________________________________________________________________________________________________________________\n";
			}
		}			

		void printReverse(record *current){     //Print the first come first serve records
			if (current == NULL) {
    			return;  
    		}
    		else{
			printReverse(current->link);
    		cout<<"Name: "<<current->name<<endl<<
			"Phone Number: "<<"0"<<current->pHead<<"-"<<current->pTail<<endl<<
			"Date: "<<current->day<<"/"<<current->month<<"/"<<current->year<<endl<<
			"Time: "<<current->time<<endl<<
			"Number of Pax: "<<current->numOfPax<<endl;
			cout << "________________________________________________________________________________________________________________________\n"; 
			}
		}
};
#endif
