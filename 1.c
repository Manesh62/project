// Project on parking system
// for including printf and scanf function and other standard library function
// for using getch() and unformatted output
//for system("cls")
//for strcmp, strcpy,etc.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//=======================
//declaring structure
//=======================
struct number{
	int nubu,num,nub,*bu_amount,*m_amount,*b_amount;
};
//====================================
//declaring global variables
//number of vehicles
//string used to store name of vehicle
//====================================
int count1=0,count2=0,count3=0,vehicle_no;
char name[10];
//==================
//function prototype
//==================
int options(int);
void tb(struct number n);
int bus(int,int *);
int micro(int,int *);
void fi();
int bike(int,int *);
void showdetail();
void Delete();
//==============
//main function
//==============
int main()
{
	//=============================================================
	//defining structure
	//local variable, sw for option,chk for checking default value.
	//=============================================================
	struct number n;
    int a,sw,chk=0;
	//=============================================
	//assigning integer 0 to prevent garbage value.
	//=============================================
	n.nubu=0;
	n.num=0;
	n.nub=0;
	n.bu_amount=0;
	n.m_amount=0;
	n.b_amount=0;
	//==========
	//goto label
	//==========
    top:
    printf("\n\t\t\t******welcome to the Parking System******\n\n\n");   
//===================================
//first tabel stored in this function
//===================================
	tb(n);	
//================================================================================
//chk is a checking variable in case of default, options are in options function;
//================================================================================
      sw = options(chk);	
//=======================================================================================================================================
//chk reassigned below function calling option due to value being passed for current function depends upon previous value of chk
//value changed to 1 if default option selected, chk reassigned value 1 so that previous instance of default doesnt hamper current rerun.
//========================================================================================================================================
	chk=0;
//================================================================================================================
//switch
	//*case 1: , *case 2: , *case 3: 
	//calling respective function using call by value and reference(pointer). number of bus and cost of bus.
	//*case 4:
	//calling a void function that reads from file and shows data in the file, rather than table in program of screen.
	//*case 5:
	//function to delete the content of created file.
	//*case 6:
	//ends the program
	//*default:
	//assigning a flag to indicate default function has run.
	//=================================================================================================================
	switch(sw)
	{
		case 1:
			n.nubu= bus(n.nubu,&n.bu_amount);
			break;
		case 2:
            n.num=micro(n.num,&n.m_amount);
			break;
		case 3:
            n.nub=bike(n.nub,&n.b_amount);
			break;	
		case 4:
			system("cls");
            showdetail();
			break;
		case 5:
		   system("cls");
           Delete();
		   break;	
		case 6:
		    system("cls");
            return 0;
		    break;
		 default:
            system("cls");
		    chk=1; 
		    break;		
	}
//===================================================================================================
//file specified to be created only when inputing value so it wont recreate a file after deleting it.
//if condition run i.e. first 3 cases are selected function dealing with file will run.
//===================================================================================================
	if (sw==1 || sw==2 || sw==3)
	{
		fi(n);
	}
//=====================================================================
//clears screens so that multiple options arent shown cause of goto top
//=====================================================================
    system("cls");
//===========================================================================
//unless exit option [6] is selected goto will not be letting the program end
//===========================================================================
    goto top;
    return 0;
}
//============================================
//options displayed are coded in this function
//============================================
int options(int chk)
{
	int opt;
        printf("\n [1] Enter Bus records ");
	printf("\n [2] Enter Micro records");
	printf("\n [3] Enter Bike records");
	printf("\n [4] View Details");
	printf("\n [5] Delete Data");
	printf("\n [6] Exit");
//==========================================================================
//if default option was selected chk would be 1 thus running this condition.
//==========================================================================
	if(chk==1)
	{
		printf("\nplease enter valid option");
	}	
//=============================================================================
//opt variable stores and passes value for sw which determines value for switch
//=============================================================================
	printf("\n\n --> ");
    scanf("%d",&opt);
    return opt;
}
//===========================================
// creating a log file to store data inputed.
//===========================================
void fi(struct number n)
{
	//===========================================
	//file pointer named 'file' declared
    //filename 'log.txt' stored in string.
    //required variables declared.-
    //===========================================
	FILE *file;
    char filename[] = "log.txt";
    int amount;
    
//======================================================================================
//a+:append+,read and write on already existing file, creates new if file doesnt exist
//in strcmp, name is global variable storing name of vehicle.
//if the string in name is either bus, micro or bike, the amount will be correspondingly
//declared later to be written in the file.
    //======================================================================================
    file = fopen(filename, "a+");
    if(strcmp(name,"Bus")==0)
    {
    	amount=1500;
	}
	if(strcmp(name,"Micro")==0)
    {
    	amount=1200;
	}
	if(strcmp(name,"Bike")==0)
    {
    	amount=1000;
	}
    
    //==================================
	//number	vehicle     cost";
	//writing the variables in the file.
	//closing the file
	//==================================
    fprintf(file, "%d\t%s\t%d\n",vehicle_no,name,amount);  
   	fclose(file);
}



void tb(struct number n)//function for the first table
{
	//=========================================
    //*editing spacing and gaps to design table
    //=========================================
    
    //===========
    //*first row,
    //===========
	printf("\n\t\t\t [1] BUS");
    printf("\t [2] MICRO");
    printf("\t [3] BIKE\n");
    
    //============
    //*second row,
    //============
    printf("\t\t\t ----------------------------------------\n");
    
    //===========
	//*third row,
	//===========
    printf("\tvehicle count:-\t     %d\t\t     %d\t\t     %d\n",n.nubu,n.num,n.nub);
    //=====================================================================================================================
    //*fourth row,
//has different conditional statesment to prevent uneven spacing when the number of digits change in table.
//count is a checking variable which counts when and how many times a function for specified vehicle ran.
//since all costs for individual vehicle are 4-digit, we can easily design table by counting how many times,
//the function ran i.e. how many times value is added.
//first condition is for default table where all costs are 0.
//further condtions run according to which which vehicle's value have been changed.
    //=====================================================================================================================
     if(count1==0 && count2==0 && count3==0)
    {
    	printf("\t         cost:-\t     %d\t\t     %d\t\t     %d\n",n.bu_amount,n.m_amount,n.b_amount);
	}
	if(count1>0 && count2==0 && count3==0)
	{
    	printf("\t         cost:-\t   %d\t\t     %d\t\t     %d\n",n.bu_amount,n.m_amount,n.b_amount);
	}
	if(count1==0 && count2>0 && count3==0)
	{
    	printf("\t         cost:-\t     %d\t\t   %d\t\t     %d\n",n.bu_amount,n.m_amount,n.b_amount);
	}
	if(count1==0 && count2==0 && count3>0)
	{
    	printf("\t         cost:-\t     %d\t\t   %d\t\t     %d\n",n.bu_amount,n.m_amount,n.b_amount);
	}
	if(count1>0 && count2>0)
	{
    	printf("\t         cost:-\t   %d\t\t    %d\t     %d\n",n.bu_amount,n.m_amount,n.b_amount);
	}
	printf("\n");
	
}

//================================================================================================================\
//case[1]:
//integer function named bus
//name string is assigned value 'Bus' using strcpy.
//pointer is used for amount1 as multiple values cant be returned, similarly vehicle_no is also pointer.
//because options are shown from function, multiple options will be shown unless cleared. so system("cls") is used
//number of bus is counted by nobu, increasing every time function runs. nobu is returned in the function.
//================================================================================================================
int bus(int nobu,int *amount1)
{    
	strcpy(name,"Bus");
	count1++;
	nobu++;
	*amount1=*amount1+1500;
	printf("\nEnter Vehicle number - ");
	scanf("%d",&vehicle_no);
	system("cls");
	return nobu;
}


//================================================================================================================
//case[2]:
//integer function named micro
//name string is assigned value 'Micro' using strcpy.
//pointer is used for amount2 as multiple values cant be returned, similarly vehicle_no is also pointer.
//because options are shown from function, multiple options will be shown unless cleared. so system("cls") is used
//number of micro is counted by nom, increasing every time function runs. nom is returned in the function.
//================================================================================================================
int micro(int nom,int *amount2)
{    
	strcpy(name,"Micro");
	count2++;
	nom++;
	*amount2=*amount2+1200;
	printf("Enter Vehicle number - ");
	scanf("%d",&vehicle_no);
	system("cls");
	return nom;
}


//================================================================================================================
//case[3]:
//integer function named bike
//name string is assigned value 'Bike' using strcpy.
//pointer is used for amount3 as multiple values cant be returned, similarly vehicle_no is also pointer.
//because options are shown from function, multiple options will be shown unless cleared. so system("cls") is used
//number of bus is counted by nob, increasing every time function runs. nob is returned in the function.
//================================================================================================================
int bike(int nob,int *amount3)
{    
	strcpy(name,"Bike");
	nob++;
	*amount3=*amount3+1000;
	printf("Enter Vehicle number - ");
	scanf("%d",&vehicle_no);
	system("cls");
	return nob;
}


//=====================================================
//case [4]:
//opens file in read mode,
//if file doesnt exist, informs user file doesnt exist.
//counter variable increases every time a line is read
//if no data exist on file counter will be 0
//if counter == 0, printing no records found.
//=====================================================
void showdetail()
{
	FILE *file;
	int nmb, amnt, counter=0;
	char veh[10], a;
	file = fopen("log.txt", "r");
	
	if(file==NULL)
	{
		printf("\n record file doesnt exist\n");
	}
	else
	{
		printf("\nVeh_num\tvehicle\tamount\n");
		printf("----------------------\n");
		while((fscanf(file,"%d%s%d",&nmb,&veh,&amnt))!=EOF)
			{
				printf("%d\t%s\t%d\n",nmb,veh,amnt);
				counter++;
			}
		if(counter==0)
		{
			printf("\n*******************************\n");
			printf("Sorry, no records found.\n");
		}
	}
	fclose(file);
	printf("\ncontinue?(press any button)");
	a=getch();
}


//=====================================================================================
//case [5]:
//deletes the record of the file.
//performs the action by opening the file in write mode, which rewrites the entire file
//i.e. creates a new file, replacing old one is name given is same.
//=====================================================================================
void Delete()
{
	char a;
	printf("Do you want to delete the records?(y/n) - ");
	a=getch();
	
	if(a=='y')
	{
		FILE *fp;
		fp=fopen("log.txt","w");	
        fclose(fp);
	}

}
