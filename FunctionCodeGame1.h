#ifndef cs_H
#define cs_H

//Functions Prototypes
void putToFile(int i,Player py[]);
//compute:
int menu(Player py[]);
string compute_rank(int level,Player py[]);
//mangment:
void add_record(Player py[]);
void delete_record(Player py[]);
void update_record(Player py[]); 
void sort_records(Player py[]);
//practical:
bool emptyArray(Player py[]);
int find_max(Player py[]);
int search(Player py[]);
void search(char gender,Player py[]);
//print/show:
void show_record(int i,Player py[]);
void print_records(Player py[]);
void print_records(int month,Player py[]);
void print_records(string rank,Player py[]);

//Functions Definitions

int menu(Player py[]) //print the menu and receive the choice 
{
        int choice;
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++" << "\n +            -== MAIN MENU ==-             +"
                <<"\n ++++++++++++++++++++++++++++++++++++++++++++" << "\n | 1. Add a player                          |"
                 <<"\n | 2. Delete a player                       |"
                 <<"\n | 3. Update a player                       |"
                 <<"\n | 4. View all records                      |"
                 <<"\n | 5. Find the max level                    |"
                 <<"\n | 6. Find a player by ID                   |"
                 <<"\n | 7. Sort records by levels                |"
                 <<"\n | 8. Show players by rank                  |"
                 <<"\n | 9. Show players by gender                |"  
                 <<"\n | 10. Show players born in month ##        |"
                 <<"\n | 11. Exit                                 |"
                 <<"\n ++++++++++++++++++++++++++++++++++++++++++++"
                <<"\n\n>> ";   
        cin>>choice;
        return choice;
}//end of menu

string compute_rank(int level,Player py[]) // level --> rank 
{
        //Ranks are: (SSS-SS-S-A-B-C-D-E)
        
        if (level>=999)
            return "SSS";
        else if (level>=500)
            return "SS";
        else if (level>=300)
            return "S";
        else if (level>=100)
            return "A";
        else if (level>=75)
            return "B";
        else if (level>=50)
            return "C";
        else if (level>=25)
            return "D";
        else
            return "E";
           
}//end of compute_rank

void add_record(Player py[]) //Add the player you want 
{
    	char g;
        int items =0;
       
        for(int i=0;i<20;i++)
        {
        py[count].inventory[i]="?"; //fill with ? <- empty slot
        }
       
        cout<<"Please enter player info: ";
        cout<<"\nID: ";     cin>>py[count].id; 
        cout<<"Name: ";  cin>>py[count].name;
        cout<<"UserName: ";      cin>>py[count].userName;
        
       string genderTemp;
        do{                
        cout<<"Gender (M/F): ";     
        cin>>genderTemp;
        //check_gender(py[count].gender);  //by ref
        }while(genderTemp != "M" && genderTemp != "F" );
       
        py[count].gender = genderTemp[0]; 
        int d=0,m=0,y=0;                           
        cout<<"Date of birth (DD-MM-YYYY): ";  
       
        do{
        cout<<"\nDay: "; 
        cin>>d;
        }while((d > 31) || (d < 1));
        py[count].dob.day = d;
       
        do{
        cout<<"Month: ";
        cin>>m;
        }while((m > 12) || (m < 1));
        py[count].dob.month = m;
       
        do{
        cout<<"Year: " ; 
        cin>>y;
        }while(y > 2023 || y < 1900);
        py[count].dob.year = y;
        //check_dob(py[count].dob);  //by ref
                                               
        cout<<"Level (XP): ";     cin>>py[count].level;  
        //check_level(py[count].level);
        py[count].rank=compute_rank(py[count].level,py); 

        cout<<"Inventory ";
        cout<<"number of items you want to add: ";
        cin>>items;
       
        string it = "\n\t                => ITEM LIST <=\n\n\t +             SWORD               +          \n\n | 1. Common Sword (Weakest Sword Not sharp) \n | 2. Uncommon Sword (Can be used but not the best) \n | 3. Rare Sword (One of the best)  \n | 4. Epic Sword (Sword of hero's) \n | 5. Legendary Sword (Sword of Legends with stories to last)\n\n\t +             SHILED               +\n\n | 6. Common Shield (Weakest Shield Easily Broken) \n | 7. Uncommon Shield  (Can be used but not the best) \n | 8. Rare Shield (One of the best)\n | 9. Epic Shield (Shield of hero's)\n | 10. Legendary Shield  (Shield of Legends to defend you to the end)\n\n\t +             BOWS               + \n\n | 11. Common Bow (Weakest Bow Hard to aim) \n | 12. Uncommon Bow  (Can be used but not the best)  \n | 13. Rare Bow (One of the best) \n | 14. Epic Bow  (Bow of hero's)  \n | 15. Legendary Bow  (Bow of Legendary Archers) \n\n\t +             POTIONS              + \n\n | 16. Healing Potion (+10 HP/1 sec | 2 min) \n | 17. Poison Potion (-5 HP/1 sec | 6 min)\n | 18. Speed Potion (+20 SP | 4 min)\n\n\t +             CONSUMABLES              + \n\n | 19. Arrows (How would you use a bow without it?) \n | 20. Chest (Open it you might find something good!!)\n\n";
        int c;
        cout<<it;
        string tem = ",,,";
        for(int i=0;i<items;i++)
        {
        
        do {cout<<"\nitem #"<<i+1<<": ";
        cin>>c;}while(c > 20 || c < 1);
       
        switch (c)
        {
            case 1:
            tem = "Common-Sword";
            break;
            case 2:
            tem = "Uncommon-Sword";
            break;
            case 3:
            tem = "Rare-Sword";
            break;
            case 4:
            tem = "Epic-Sword";
            break;
            case 5:
            tem = "Legendary-Sword";
            break;
            case 6:
            tem = "Common-Shield";
            break;
            case 7:
            tem = "Uncommon-Shield";
            break;
            case 8:
            tem = "Rare-Shield";
            break;
             case 9:
            tem = "Epic-Shield";
            break;
             case 10:
            tem = "Legendary-Shield";
            break;
             case 11:
            tem = "Common-Bow";
            break;
            case 12:
            tem = "Uncommon-Bow";
            break;
            case 13:
            tem = "Rare-Bow";
            break;
            case 14:
            tem = "Epic-Bow";
            break;
            case 15:
            tem = "Legendary-Bow";
            break;
            case 16:
            tem = "Healing-Potion";
            break;
            case 17:
            tem = "Poison-Potion";
            break;
            case 18:
            tem = "Speed-Potion";
            break;
            case 19:
            tem = "Arrows";
            break;
            case 20:
            tem = "Chest";
            break;
			default: cout<<"\nIncorrect item.";  
        }
       
        py[count].inventory[i] = tem;     
        }
	count++;
}//end of add_record

void print_records(Player py[]) //loop over show_record function until the last actual size (count) (this is a "compo" function
{
        for (int i=0;i<count;i++)
             show_record(i,py);
}//end of print_records

void show_record(int i,Player py[]) //print a single record 
{                                                                                                                                                              //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++                                        
        cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<"\n+                                          -== Player ("<<(i+1)<<") ==-                                         +"<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
            <<"\n |ID: "<<py[i].id<<""
            <<"\n |Name: "<<py[i].name<<""
			<<"\n |UserName: "<<py[i].userName<<""
                <<"\n |Gender: "<<py[i].gender<<""
                <<"\n |Level: "<<py[i].level<<" ("<<py[i].rank<<")"<<""
                <<"\n |Date of Birth (DD-MM-YYYY): "<<py[i].dob.day<<"-"<<py[i].dob.month<<"-"<<py[i].dob.year<<"";
               
                cout<<"\n |Inventory: (";
                for(int j=0;j<20;j++)
                {
                cout<<py[i].inventory[j]<<"|";
                }
                cout<<")\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
}//end of show_record

void print_records(int month,Player py[]) //print the records for a single month
{
        for (int i=0;i<count;i++)
                if (py[i].dob.month==month)
                        show_record(i,py);
}//end of print records by month

void print_records(string rank,Player py[])
{
        for (int i=0;i<count;i++)
             if (py[i].rank==rank)
                 show_record(i,py);
}//end of print_records by rank

void delete_record(Player py[])
{
        int index=search(py);
        if (index<0)
        {
                cout<<"\nNot found!!\n";
                return;  //exit from the function
        }//end if
       
        //delete if found i.e. index>=0
        for (int j=index; j<count-1; j++) //shifting array
            py[j]=py[j+1];
                               
        count--; //Actual size decrease 
        cout<<"\nPlayer deleted successfully. \n";
}//end of delete_record

void update_record(Player py[])
{//update Player's level only
        int edit = 0;
        int items;     
        int index=search(py);
        
        if (index<0)
        {
                cout<<"\nNot found!!\n";
                return;  //exit from the function
        }//end if
        show_record(index,py);
        cout<<"\nDo you want to edit level? (1: YES | 0: NO): ";
        cin>>edit;
        if(edit)
		{
        //update if found i.e. index>=0
        cout<<"\nOld level: "<<py[index].level;
        cout<<"\nNew level: ";
        cin>>py[index].level;
		}
        //check_score(py[index].level);  //later                       
        py[index].rank=compute_rank(py[index].level,py);  //update player's rank
        /*}
        edit = false;*/
        edit = 0;
        cout<<"\nDo you want to edit UserName? (1: YES | 0: NO): ";
        cin>>edit;
        
        if(edit)
		{
        //update if found i.e. index>=0
        cout<< "\nOld UserName: "<< py[index].userName;
        cout<<"\nNew UserName: "; cin>>py[index].userName;
		}
       
        /*cout<<"\nDo you want to edit Inventory? (1: YES | 0: NO): ";
        cin>>edit;
       
        if(edit){
        for(int i=0;i<20;i++)
        {
        py[count].inventory[i]="?";
        }
       
        cout<<"Inventory ";
        cout<<"number of items you want to update: ";
        cin>>items;
        for(int i=0;i<items;i++)
        {
        cout<<"\nitem #"<<i+1<<": ";
        cin>>py[count].inventory[i];
        }
        } */
       
       
        cout<<"\nPlayer level updated successfully. \n";
}//end of update_record

bool emptyArray(Player py[])
{
        if (count==0)
        {
                cout<<"\nERROR: Array is empty!!\n";
                return true;
        }//end if
       
        return false;
}//end of empty Array

int find_max(Player py[])
{
        int max=py[0].level;
        int max_indx=0;
       
        for(int i=1;i<count;i++)
                if (py[i].level>max)
                {
                        max=py[i].level;
                        max_indx=i;
            }//end if
       
        return max_indx;
}//end of find_max

int search(Player py[])
{//classic search by ID
        string id;
       
        cout<<"\nPlease enter a player ID:";
        cin>>id;

        for (int i=0;i<count;i++)
                if (py[i].id==id)
                        return i;      
       
        return -1;  //i.e. not found
}//end of search by ID

void search(char gender,Player py[])
{
        for (int i=0;i<count;i++)
             if (py[i].gender==gender)
                 show_record(i,py);
}//end of search by gender

void sort_records(Player py[])
{//sort by levels descendingly max-to-min
        bool ordered=false;
        Player temp;
       
        if (count < 2)
        cout<<"\nNothing to sort!!";
               
    for(int i = 0; i < count-1 && ordered==false ; ++i)
    {   
                ordered=true;
                for(int j = 0; j < count-1;++j)
                   if(py[j].level < py[j+1].level)    
                  {       
                    ordered=false;
                    temp = py[j];
                    py[j] = py[j+1];
                    py[j+1] = temp;
                  }//end if
         }//end for
        
         cout<<"\nLevels in descending order:";
         print_records(py);       
}//end of sort_records

void putToFile(int i,Player py[]) {
        ofstream write;
        write.open("GameData.txt");
        for(int z=0;z<count;z++)
        {
        if(z < 1){write << count << '\n' ;} // << '\t' << SIZE << '\n' ;}
        write << py[z].id;
        write << '\t' << py[z].name ;
        write << '\t' << py[z].userName ;
        write << '\t' << py[z].gender ;
        write << '\t' << py[z].dob.day ;
        write << '\t' << py[z].dob.month ;
        write << '\t' << py[z].dob.year ;
        write << '\t' << py[z].level;
        write <<  '\t' << py[z].rank << "\t";
        for(int x=0;x<20;x++)
        {write << py[z].inventory[x] << '\t';} 
        write <<  endl;
    	}
        write.close();
    }


#endif
