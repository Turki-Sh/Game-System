/*
		+ Game system +

*/

#include <iostream> 
#include <fstream> 
#include <string> 
#include<ctime>
#include <chrono> //active if you want to see time altgough you might need to change compiler settings
using namespace std;

//Global variables

int count = 0;       //actual size of array last element 
bool clear = true;
string s;

void go(){
	
	if(clear){
string skip;
cout<<"\nEnter any key to continue: ";
cin>>skip;
}

}

//Structures Declaration
struct Date 
{  
    int day;
    int month;
    int year;
   
};//end of struct Date

struct Player
{
        string id;
        string name;
        string userName;
        char gender;
        Date dob;
        int level;
        string rank;   //computed by an internal function
        string inventory[20]; // max items to carried are 20
       
};

#include "FunctionCodeGame1.h"

//START of Main fun
int main()
{
	int SIZE = 20; //Normal
	cout<<"\n\t+\t\t\t GAME SYSTEM!! \t\t\t+\n\n\n"<<endl;
	
	ifstream sizein;
	sizein.open("SIZE.txt",ios::in);
	sizein >> SIZE;
	sizein.close();
	int restart = 0;
	cout<<"\nDo you want to change or set your SIZE? current size is [ "<<SIZE<<" ] (Warning: This will restart the whole program and might lead to loss of data) (1: Yes 2: No): ";
	cin>>restart;
	if(restart == 1)
	{
		cout<<"\nAre you sure? ";
		cin>>restart;
		if(restart == 1)
		{count = 0; SIZE = 0;
		cout<<"\nEnter the Size you want: ";
		cin>>SIZE;
		}
	}
	ofstream sizeout;
	sizeout.open("SIZE.txt",ios::out);
	sizeout << SIZE;
	sizeout.close();
	
	Player py[SIZE];
	int choice;
	
	if(restart != 1){
    int v = 0; 
	ifstream inFile;
	inFile.open("GameData.txt",ios::in);
   if(inFile.is_open())
    {
        inFile >> count; // >> SIZE;
        while(!inFile.eof()) //work while the array not (!) ended (eof)
        {
        inFile >> py[v].id >> py[v].name >> py[v].userName >> py[v].gender >> py[v].dob.day >> py[v].dob.month >>  py[v].dob.year >> py[v].level >> py[v].rank; 
        for(int x=0;x<20;x++)
        {inFile >> py[v].inventory[x];}
        v++;
    	}
        inFile.close();
    }
    else 
    {cout<<"\nUnable to open!! "<<endl;} 
     }//last}
  
       
       int cc = 0;
       cout<<"Do you want to clear the screen after every operation (1:YES OR 2:NO)? ";
       cin>>cc;
       switch(cc)
       {
       	case 1:
       		 clear = true;
       		break;
       	case 2:
       		 clear = false;
       		break;	
	   }
       
        do{
        	
        	if(clear){if(system("cls")){system("clear");}}
			
                choice=menu(py);
           
                switch (choice)
                {
                        case 1: //Add new player
                                        if (count<SIZE)
                                           add_record(py);
                                        else
                                           cout<<"\nERROR: The array is full. (You need to delete items first!) ";
                                        go();
                                        break;

                        case 2: //delete a player
                                        if (!emptyArray(py))
                                                delete_record(py);
                                        go();
                                        break;
                               
                        case 3: //update player's score
                                        if (!emptyArray(py))
                                           update_record(py); 
										go();             
                                        break;
                               
                        case 4: //print all records
                                        if (!emptyArray(py))
                                            print_records(py);
                                        go();
                                        break;

                        case 5: //find the max level
                                        if (!emptyArray(py))
                                        {
                                                int i=find_max(py);
                                                show_record(i,py);
                                        }//end if
										go();   
                                        break;
                                       
                        case 6: //find a player by ID
                                        if (!emptyArray(py))
                                    {
                                          int i=search(py);
                                          if (i>=0)
                                              show_record(i,py);
                                          else
                                              cout<<"\nNot found!!\n";
                                        }//end if
                                        go();
                                        break;
                                       
                        case 7: //sort records by levels
                                        if (!emptyArray(py))
                                            sort_records(py);
                                        go();
                                        break;
                                       
                        case 8: //Show player by rank
                                        if (!emptyArray(py))
                                        {
                                                string rank;
                                            do{cout<<"\nPlease enter a rank (SSS-SS-S-A-B-C-D-E): ";
                                                cin>>rank;} while(rank != "SSS" && rank != "SS"  && rank != "S" && rank != "A" && rank != "B" && rank != "C" && rank != "D" &&  rank != "E");
                                            print_records(rank,py);
                                    }//end if
                                    go();
                                        break;
                                       
                        case 9: //Show player by gender
                                        if (!emptyArray(py))
                                        {
                                                char gender;
                                                //add do-while to ensure input either M or F
                                                string tempG;
                                                do{cout<<"\nPlease enter the gender (M/F): ";
                                                cin>>tempG;}while(tempG != "M" && tempG != "F" );
                                                gender = tempG[0];
                                            search(gender,py);
                                    }//end if
                                    go();
                                        break;
                                       
                        case 10: //Show players born in the same month
                                        if (!emptyArray(py))
                                        {
                                                int month;
                                                //add do-while to ensure input in range 1 - 12
                                                do{cout<<"\nPlease enter a month (1 - 12): ";
                                                cin>>month;}while(month > 12 || month < 1);
                                            print_records(month,py);
                                    }//end if
                                    go();
                                        break;                                                                                                                                                                                         

                        case 11: cout<<"\nThanks for using our program!\n Enter any key to save your data (NOTE: Not saving will lead to lose of your data.): "; cin>>s;
                                         break; 
                               
                        default: cout<<"\nIncorrect menu option."; go();
                }//end switch
               
        }while(choice!=11);
       
       
        putToFile(0,py);
       	
       	if(true)
       	{
		ofstream report;
        report.open("report.txt");
        
        report<<"\t [This is a report of your last update] \n";
        report<<"\n [Number of records: "<<count<<" ]";
        auto givemetime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    	report<<"\n Last update time : "<< ctime(&givemetime) <<" ";
        report.close();
		}
       
       
        return 0;
}//end of main


