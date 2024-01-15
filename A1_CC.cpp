#include "Restaurant.h"                       //include header file called Restaurant

int main(){
	string na, tim, da, mth, yr, id;                   //declaration of the variable
	int pH, pTa, hr, min, pax, choice, count;
	reservation r;
	string tempChoice, tempPH, tempPTa, tempHr, tempMin, tempPax;
	
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n"; 
	cout << "                                     WELCOME TO RESTAURANT RESERVATION SYSTEM!!!\n\n";                                                  
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n";                                                                                  

	do{
		//Let user to choose the choices
		cout<<"Choice 1: Enter a new reservation."<<endl<<
		"Choice 2: Update the reservation record."<<endl<<
		"Choice 3: Display reservation record in order."<<endl<<
		"Choice 4: Delete the first record."<<endl<<
		"Choice 5: Quit the program."<<endl<<endl<<
		"Input: ";
		getline(cin,tempChoice);
		tempChoice= trim(tempChoice);
		choice = atoi(tempChoice.c_str());	
		cout <<"________________________________________________________________________________________________________________________\n"; 
		
		//Choice 1 is to let the user to enter a new reservation record
		if (choice == 1 && onlyNum(tempChoice)){
			cout <<"                                                          | NAME |"<<endl;
			do{
				//Enter the name
				cout<<"Name: ";
				getline(cin, na);
				
				// this is the if else statement that helps the system to check when the user's input is all letters it will store all the correct input into an array called n[i]
				if (onlyLetter(na) == true){
					int length = na.length();
					for (int i=0; i<length; i++){
						int n = na[i];
						if (islower(n))               //this is the if else statement that helps the system if the letters all is in lower case,then it will convert it all to the upper case  
							na[i] = toupper(n);
					}
					na=trim(na);
				}
				else cout<<"Numbers and symbols are not allowed. Please try again!"<<endl<<endl;
			}while (onlyLetter(na) == false);
		
			cout <<"                                                      | PHONE NUMBER |"<<endl;
			while(true){
				//Enter the country code and phone number
				cout<<"Country code: ";
				getline(cin,tempPH);
				tempPH= trim(tempPH);
				pH = atoi(tempPH.c_str());
				count=countNum(pH);
				
				//if count is not equal to digit 2 or pH is less than 10 or pH is more than 19,then the system will warn the user 
				if(count!=2 || pH<10 || pH>19 || !(onlyNum(tempPH))){
					cin.clear();
		    		cout << "\nInvalid input. Please try again" << endl;
		    		cout<<"Please follow the format: 01X"<<endl;
				}
				else break;
			}
			
			//if the program have checked the choice input is a digit 2 then it will allow the user input phone number 
			while(true){
				cout<<"Phone number excluding the country code: ";
				getline(cin,tempPTa);
				tempPTa= trim(tempPTa);
				pTa = atoi(tempPTa.c_str());
				count=countNum(pTa);
				
				//Check entered the phone number is in 7 number digit or not,if yes then the system will warn the user.
				if(count!=7 || !onlyNum(tempPTa)){
					cin.clear();
		    		cout << "\nInvalid input. Please try again." << endl;
		    		cout<<"Please make sure it is a 7 digit number, excluding the country code."<<endl;
				}
				else break;
			}
			
			//Check the same name and phone number 
			if (r.dupRecord(na, pH, pTa) == false){
				cout <<"________________________________________________________________________________________________________________________\n";
				cout <<"                                             Only 1 reservation per person"<<endl;
				cout <<"________________________________________________________________________________________________________________________\n";
				continue;
			}
			
			cout <<"                                                          | DATE |"<<endl;
			do{
				//Enter the day, month and year
				cout<<"Day: ";
				getline(cin, da);
				cout<<"Month: ";
				getline(cin, mth);
				cout<<"Year: ";
				getline(cin, yr);
				
				//Check the date is integer number or not 
				if (onlyDateNo (da, mth, yr) == false){
					cout << "Please key in numbers only." <<endl<<endl;
				}
				//Check the date range is correct or not 
				else if (wrongDate (da, mth, yr) == true){
					cout << "Please enter a valid date." <<endl<<endl;
 	  			}	
			}while (wrongDate(da,mth,yr) == true || onlyDateNo (da, mth, yr) == false);
			
			cout <<"                                                          | TIME |"<<endl;
			while(true){
				//Enter the hour and minute
				cout<<"Hour: ";
	    		getline(cin,tempHr); 
				tempHr= trim(tempHr);
				hr = atoi(tempHr.c_str());
				//Check the hour range is from 0 to 23 and the input is number only or not 
				if(hr>23 || hr<0 || !onlyNum(tempHr)){
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
				min = atoi(tempMin.c_str());
				if(min<0 || min>59 || !onlyNum(tempMin)){
					cin.clear();
		    		cout << "\nInvalid input. Please try again." << endl;
				}	
				else break;
			}
			
			//Convert the hour and minutes to string called time, and showing the leading zero
			stringstream hString;
			hString<<hr;
			
			string hStr;
			hString>>hStr;
			
			stringstream mString; 
			mString<<min;
	
			string mStr;
			mString>>mStr;
			
			if(hr<=9) tim= "0"+ hStr;
			else tim = hStr;
			if(min>=0 && min<10) tim =tim+"0"+mStr;
			else tim =tim+mStr;
		
			cout <<"                                                           | PAX |"<<endl;
			while(true){
				//Enter the number of pax
				cout<<"Number of Pax: ";
				getline(cin,tempPax);
				tempPH= trim(tempPax);
				pax = atoi(tempPax.c_str());
				if(pax<1 || !onlyNum(tempPax)){
					cin.clear();                             
		    		cout << "\nInvalid input. Please try again." << endl;	
				}
				else if(pax>120 || !onlyNum(tempPax)) cout<<"The maximum of pax is 120."<<endl;
				else break;
			}
			
			if(mth.length()==1) id= yr + "0" + mth;
			else id= yr+mth;
			if(da.length()==1) id=id+"0"+da+tim;
			else id=id+da+tim;
			
			r.enRecord(na, pH, pTa, da, mth, yr, hr, min, tim, pax, id);
			cout <<"________________________________________________________________________________________________________________________\n";  
		}
	
		//Choice 2 is to let the user to search and update the record
		else if (choice == 2 && onlyNum(tempChoice)){
			if (r.getCount() == 0){
				cout<<"                                       There is no records that can be updated."<<endl;
				cout << "________________________________________________________________________________________________________________________\n";
			}
			else {
				cout<<"Search the record you want to update. "<<endl;
				cout <<"                                                          | NAME |"<<endl;
				do{
					cout<<"Name: ";
					getline(cin, na);
					if (onlyLetter(na) == true){
						int length = na.length();
						for (int i=0; i<length; i++){
							int n = na[i];
							if (islower(n))
							na[i] = toupper(n);
						}
						na=trim(na);
					}
					else
						cout<<"Numbers and symbols are not allowed. Please try again!"<<endl<<endl;
				}while (onlyLetter(na) == false);
		
				cout <<"                                                      | PHONE NUMBER |"<<endl;
				while(true){ 
					cout<<"Country code: ";
					getline(cin,tempPH);
					tempPH= trim(tempPH);
					pH = atoi(tempPH.c_str());
					count=countNum(pH);
					if(count!=2 || pH<10 || pH>19 || !(onlyNum(tempPH))){
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
					pTa = atoi(tempPTa.c_str());
					count=countNum(pTa);
					if(count!=7 || !onlyNum(tempPTa)){
						cin.clear();
		    			cout << "\nInvalid input. Please try again." << endl;
		    			cout<<"Please make sure it is a 7 digit number, excluding the country code."<<endl;
					}
					else break;
				}
				r.updateRecord(na, pH, pTa);
				cin.ignore();
			}
		}
		
		//Choice 3 is to let the user to see the records according to date and time
		else if (choice == 3 && onlyNum(tempChoice)){
			if (r.getCount() == 0){
				cout<<"                                                There is no records."<<endl;
				cout <<"________________________________________________________________________________________________________________________\n";
			}
			else{
				cout <<"************************************************************************************************************************\n";
				cout<<"                                                Reservation Records"<<endl<<endl;
				cout <<"************************************************************************************************************************\n";\
				r.bubbleSort(head);
				r.printReverse(head);
				cout <<"Total of Records: " << r.getCount() << endl;
				cout <<"________________________________________________________________________________________________________________________\n";
			}
		}
		
		//Choice 4 is to let the user to delete the record 
		else if (choice == 4 && onlyNum(tempChoice)){
			if (r.getCount() == 0){                                 
				cout<<"                                        There is no records that can be deleted."<<endl;
				cout <<"________________________________________________________________________________________________________________________\n";
			}
			else if (r.getCount() == 1){    
				r.deFirstRecord();
				cin.ignore();
			}
			else{
				r.deLastRecord();
				cin.ignore();
			}
		}
		
		//Choice 5 is to let the user to quit the program 
		else if (choice == 5 && onlyNum(tempChoice)){
			cout <<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
			cout<<"                                                     HAVE A NICE DAY!!!"<<endl;
			cout <<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
		}
		
		//Wrong choice input will let the user to try again
		else{
			cin.clear();
			cout<<"                                              Invalid input. Please try again."<<endl;
			cout <<"________________________________________________________________________________________________________________________\n";
		}
		
	}while (choice != 5);
	system ("pause");
	return 0;
}
