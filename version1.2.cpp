#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

void admin();//administrator
void recep();//receptionist
void doc();//doctor
void ward();//ward in charge
void cashier();//cashier
void docdispcato();//display information of doctors

//catogories of doctors//
void audiologist();
void cardiologist();
void dentist();
void dermatologist();
void neurologist();
void ent();
void psy();

void bdate();//booking another date
void vbdate();//view booked dates

//warden
void room();//assigning rooms
void wardroom();
void warddoc();
void roomassign();

//doctor login
void medical();
void wards();
void docselect();
void reportmed();
void reportward();

void logind();//login details
void cashd();//cashier details

//cashier
void calmed();
void calward();

void rec(struct patient);

//about
void about();

//hold process
void delay();

void load(); 





//Data Structure//
struct patient
{
char p_id[10];
char name[20];
char sex[10];
char age[4];
char address[50];
char diagnosis[200];
char bloodgroup[10];
char test[200];
char *doc;
};

//Data structure2//
struct uppatient
{
char date[20];
char doccato[40];
char p_id[10];
char name[20];
char sex[10];
char age[4];
char address[50];
char diagnosis[200];
char bloodgroup[10];
char test[200];
};

//structure room
struct room
{
char room[5];
char doctor[30];
char p_id[10];
char name[20];
char sex[10];
char age[4];
char address[50];
char diagnosis[200];
char bloodgroup[10];
char test[200];
};

//medical report
struct report
{
char pid[5];
char scans[30];
char medicine[100];
char ward[20];
char other[10];
};


//global variables
static float wtot=0,mtot=0;//used in the cashier function to calculate the ward total and medical total
int mc=0,wc=0; // used in cashier function to count the ward & medical patients

int main()
{
char ch;
static int start=0;
system("cls");

	time_t mytime;
    mytime = time(NULL);
/*
	printf("******************** Hospital Management System ********************");
	sleep(3); //hold the screen
	system("cls");
	printf("\n\n========== LOGIN MENU ==========");
	printf("\n1.Receptionist");
	printf("\n2.Doctor");
	printf("\n3.Ward In Charge");
	printf("\n4.Cashier");
	printf("\n5.Exit from program");
	
	printf("\n\nplease Enter your choice to log in to System");
	scanf("%d",&ch);
*/	

if(start==0)
load();

sleep(0.6);
		
	while(1)
		{
		
				system("cls");
				printf("\n\n========== LOGIN MENU ==========\t\t\t\t\t\t\t      ");
				printf(ctime(&mytime));// displaying the time on screen
				printf("\n\n1.Admin");
				printf("\n2.Receptionist");
				printf("\n3.Doctor");
				printf("\n4.Ward In Charge");
				printf("\n5.Cashier");
				printf("\n6.About Program");
				printf("\n7.Exit from program");
				
				printf("\n\nplease Enter your choice to log in to System - ");
				scanf("%s",&ch);
		
			switch(ch)
				{	
					system("cls");
					int a;
					
					case '1':
							{
								start++;
								admin();
							} break;
					
					
					case '2': 
							{	
								start++;
								system("cls");
								printf("\n\nYou Selected to Login as Receptionist");
								printf("\n\nTo change Login mode please press - '2' \nTo continue login plese press \t  - '1' ");
								printf("\n\nEnter your Choice - ");
								scanf("%d",&a);
								if(a==2) break;
								recep(); 
							}break;
					case '3': 
							{	
								start++;
								system("cls");
								printf("\n\nYou Selected to Login as Doctor");
								printf("\n\nTo change Login mode please press - '2' \nTo continue login plese press \t  - '1' ");
								printf("\n\nEnter your Choice - ");
								scanf("%d",&a);
								if(a==2) break;
								doc();
							} break;
					case '4':
							{	
								start++;
								system("cls");
								printf("\n\nYou Selected to Login as Ward in Charge");
								printf("\n\nTo change Login mode please press - '2' \nTo continue login plese press \t  - '1' ");
								printf("\n\nEnter your Choice - ");
								scanf("%d",&a);
								if(a==2) break;
								ward();
							} break;
					case '5':
							{	
								start++;
								system("cls");
								printf("\n\nYou Selected to Login as Ward in Cashier");
								printf("\n\nTo change Login mode please press - '2' \nTo continue login plese press \t  - '1' ");
								printf("\n\nEnter your Choice - ");
								scanf("%d",&a);
								if(a==2) break;
								cashier();
							} break;
					
					case '6': about(); break;	
							
					case '7':
						{
							printf("\nNow exiting from the Program");
							sleep(3);
							exit(0); 
						} break;
					default: 
							{
								printf("Invalid choice please try again");
								getch();
							}
											
					
				}
		}	
		
	
}


void admin()
{
	char userid[]="adm123",password[]="123",p[15],u[15],c=' ';//' ' for space
	   int n=1,a,b,i=0;
	   char ch;
	   printf("\nEnter USER ID and PASSWORD below (You have only three chances to enter)");
	   getch();
		   while(n<=3)
		   {
		      system("cls");
		      printf("\nUSER ID: ");
		      scanf("%s",u);
		      printf("\nPASSWORD: ");
		      //scanf("%s",p);
		      	while (i<=10)
				  {
				    p[i]=getch(); //getting a character and store in the p array
				    c=p[i];
				    if(c==13) break; // 31 is the ASCII character value of the Enter key
				    else printf("*");//getting a value and instantly shows the * mark
				    i++;
				  }
		      
		      p[i]='\0';// null termination (last characer termination)
		      i=0;
		      system("cls");
		       
		      a=strcmp(u,userid);//comparing stings
		      b=strcmp(p,password);//comparing strings
		      if(a==0&&b==0)//checking whether they are equal
		      {
		      	 
				
				 while(1)
				 	{
				 		system("cls");
				 		printf("\n\n\t\t***||WELCOME||***");
				        printf("\n\nYou have logged in successfully.");
				        printf("\n\n========== ADMIN MENU ==========\t\t\t\t\t\t\t      ");
				        printf("\n1.View Login details");
				        printf("\n2.View total Settled amount");
				        printf("\n3.Login menu");
				        printf("\n4.Exit");
				 		printf("\n\nEnter your choice - ");
				 		scanf("%c",&ch);
					 
							switch(ch)
							{
							case '1': logind(); break;
							case '2': cashd(); break;
							case '3': main(); break;
							case '4': exit(0); break;
							default: printf("invalid choice");
			 	
							} 
					}
						 /*	while(ch==1)
						 	{
							
							}
							
				        if(ch==2)
				        {
				        	exit(0);
						}
						*/
				      }
				      else
				      {
				         printf("\nWrong PASSWORD and/or USER ID. Now you have % d more chance/s.",3-n);
				         sleep(2);
				         system("cls");
				      }
				      getch();
				      n++;
				   }
			   if(n==4)
			   	{
			   		printf("\nYou can't log in.");
					delay();	
				}
	
	
}

void recep()
{
		   
	char userid[]="recep123",password[]="123",p[15],u[15],c=' ';
	   int n=1,a,b,i=0;
	   char ch;
	   time_t current_time;
		FILE* file;

    current_time = time(NULL);
	   printf("\nEnter USER ID and PASSWORD below (You have only three chances to enter)");
	   getch();
		   while(n<=3)
		   {
		      system("cls");
		      printf("\nUSER ID: ");
		      scanf("%s",u);
		      printf("\nPASSWORD: ");
		      //scanf("%s",p);
		      	while (i<=10)
				  {
				    p[i]=getch();
				    c=p[i];
				    if(c==13) break;
				    else printf("*");
				    i++;
				}
		      
		      p[i]='\0';
		      i=0;
		      system("cls");
		       
		      a=strcmp(u,userid);//comparing stings
		      b=strcmp(p,password);//comparing strings
		      int lg=1; //login file write times
		      if(a==0&&b==0)//checking whether they are equal
		      {
		      	 
				
				 while(1)
				 	{
				 		if(lg==1)
				 		{
				 			file = fopen("userlog.txt", "a+");

   							fprintf(file, "\nLogin ID : Receptionist\t\tTime: %s\n", ctime(&current_time));	// opening a txt file & store user login information
   							fclose(file);
						}
				 		
				 		system("cls");
				 		printf("\n\n\t\t***||WELCOME||***");
				        printf("\n\nYou have logged in successfully.");
				        printf("\n\nTo register Medical patient press - 1 \nTo exit and re login press\t  - 2");
				 		printf("\nEnter your choice - ");
				 		scanf("%c",&ch);
				 		lg++; // modify login file write times
					 
							switch(ch)
							{
							case '1':
									{
									system("cls"); 
						 			docdispcato();		
									} break;
							case '2': exit(0); break;
							default: printf("invalid choice - ");
			 	
							} 
					}
						 	while(ch==1)
						 	{
							
							}
							
				        if(ch==2)
				        {
				        	exit(0);
						}
						
				      }
				      else
				      {
				         printf("\nWrong PASSWORD and/or USER ID. Now you have % d more chance/s.",3-n);
				         sleep(2);
				         system("cls");
				      }
				      getch();
				      n++;
				   }
			   if(n==4)
			   	{
			   		printf("\nYou can't log in.");
					delay();	
				}
	      
		




}

void doc()
	{
		char userid[]="doc123",password[]="123",p[15],u[15],c=' ';
	   int n=1,a,b,i=0;
	   char ch;
	   printf("\nEnter USER ID and PASSWORD below (You have only three chances to enter)");
	   getch();
		   while(n<=3)
		   {
		      system("cls");
		      printf("\nUSER ID: ");
		      scanf("%s",u);
		      printf("\nPASSWORD: ");
		      //scanf("%s",p);
		      	while (i<=10)
				  {
				    p[i]=getch();
				    c=p[i];
				    if(c==13) break; // ASCII value of the ENTER key
				    else printf("*");
				    i++;
				}
		      
		      p[i]='\0';
		      i=0;
		      system("cls");
		      a=strcmp(u,userid);
		      b=strcmp(p,password);
		      if(a==0&&b==0)
		      {
		         printf("\n\n\t\t***||WELCOME DOCTOR||***");
		         printf("\n\nYou have logged in successfully.");
		         sleep(2);
		         
		        while(1)
		        {
				
			         system("cls");
			         	printf("\n\n========== MENU ==========");
			         	printf("\n1.Medical Doctor");
			         	printf("\n2.Ward Doctor");
			         	printf("\n3.Exit");
			         	
			         	printf("\n\nEnter your choice - ");
			         	scanf("%c",&ch);
			         	
			         		switch(ch)
			         			{
			         			case '1': medical(); break;
			         			
			         			case '2': wards(); break;
			         			
			         			case '3': exit(0);
			         			
			         			default: printf("\nInvalid Choice");
	
								}
		         	
		         	
		    	}
		         
		         break;
		      }
		      else
		      {
		         printf("\nWrong PASSWORD and/or USER ID. Now you have % d more chance/s.",3-n);
		         sleep(2);
		         system("cls");
		      }
		      getch();
		      n++;
		   }
	   if(n==4)
	   	{
	   		printf("\nYou can't log in.");
			delay();	
		}
		
	}

void ward()
	{
		char userid[]="ward123",password[]="123",p[15],u[15],c=' ';
	   int n=1,a,b,i=0;
	   time_t current_time;
    	FILE* file;
    	current_time = time(NULL);
	   printf("\nEnter USER ID and PASSWORD below (You have only three chances to enter)");
	   getch();
		   while(n<=3)
		   {
		      system("cls");
		      printf("\nUSER ID: ");
		      scanf("%s",u);
		      printf("\nPASSWORD: ");
		      //scanf("%s",p);
		      	while (i<=10)
				  {
				    p[i]=getch();
				    c=p[i];
				    if(c==13) break;
				    else printf("*");
				    i++;
				}
		      
		      p[i]='\0';
		      i=0;
		      system("cls");
		      a=strcmp(u,userid);
		      b=strcmp(p,password);
		      int lg=1;
		      if(a==0&&b==0)
		      {
		      	 if(lg==1)
		      	 {
		      	 	file = fopen("userlog.txt", "ab");

   					fprintf(file, "Login ID : Warden\t\tTime: %s\n", ctime(&current_time));
   					fclose(file);
				 }
		         printf("\n\n\t\t***||WELCOME||***");
		         printf("\n\nYou have logged in successfully.");
		         lg++;
		         room();
		         break;
		      }
		      else
		      {
		         printf("\nWrong PASSWORD and/or USER ID. Now you have % d more chance/s.",3-n);
		         sleep(2);
		         system("cls");
		      }
		      getch();
		      n++;
		   }
	   if(n==4)
	   	{
	   		printf("\nYou can't log in.");
			delay();	
		}
		
		
	}

void cashier()
{
		char userid[]="cash123",password[]="123",p[15],u[15],c=' ';
	   int n=1,a,b,i=0;
	   char ch;
	   time_t current_time;
		FILE* file;

   		 current_time = time(NULL);
	   printf("\nEnter USER ID and PASSWORD below (You have only three chances to enter)");
	   getch();
		   while(n<=3)
		   {
		      system("cls");
		      printf("\nUSER ID: ");
		      scanf("%s",u);
		      printf("\nPASSWORD: ");
		      //scanf("%s",p);
		      	while (i<=10)
				  {
				    p[i]=getch();
				    c=p[i];
				    if(c==13) break;
				    else printf("*");
				    i++;
				}
		      
		      p[i]='\0';
		      i=0;
		      system("cls");
		      a=strcmp(u,userid);
		      b=strcmp(p,password);
		      int lg=1;
		      if(a==0&&b==0)
		      {
		      	if(lg==1)
		      		{
		      			file = fopen("userlog.txt", "ab");

   						fprintf(file, "Login ID : Cashier\t\tTime: %s\n", ctime(&current_time));
   						fclose(file);	
					}
		         printf("\n\n\t\t***||WELCOME||***");
		         printf("\n\nYou have logged in successfully.");
		         sleep(1);
		         lg++;
		         system("cls");
		         
		         	while(1)
		         		{
		         			system("cls");
		         			printf("\n========== MENU ==========");
		         			printf("\n1.Medical");
						 	printf("\n2.Ward");
						 	printf("\n3.Login Menu");
						 	printf("\n4.Exit");
						 	
						 		printf("\n\nPlease select your choice - ");
						 		scanf("%c",&ch);
						 		
						 		switch(ch)
						 			{
						 				case '1':	 calmed(); break;
						 				
						 				case '2':	 calward(); break;
						 				
						 				case '3':	 
										 			 {
														printf("Logging out....");
														sleep(2);
														main();
													 }
						 				
						 				case '4': exit(0); break;
						 				
						 				default: printf("\n1Invalid Choice");
										 
										
						 				
									}
						 	
						}
		         
		         
		         break;
		      }
		      else
		      {
		         printf("\nWrong PASSWORD and/or USER ID. Now you have % d more chance/s.",3-n);
		         sleep(2);
		         system("cls");
		      }
		      getch();
		      n++;
		   }
	   if(n==4)
	   	{
	   		printf("\nYou can't log in.");
			delay();	
		}
	
	
}

void docdispcato()
{
	
while(1)
	{
		system("cls");
		char choice;
		printf("\n========== SELECTION ==========");
		printf("\n\nA.Audiologist");
		printf("\nB.Cardiologist");
		printf("\nC.Dentist");
		printf("\nD.Dermatologist");
		printf("\nE.Neurologist");
		printf("\nF.ENT Specialist");
		printf("\nG.Psychiatrist");
		printf("\nH.Book a Date");
		printf("\nI.View Upcoming Booked Dates");
		printf("\nJ.Logout from Receptionist");
		printf("\nX.Exit");
		
		printf("\n\nPlease Select the Catogory that you want to register patient with (use lowercase) - ");
		scanf("%s",&choice);
		
		/*	while(choice !=1||choice!=2||choice !=3||choice !=4||choice !=5||choice !=6||choice !=7||choice !=8||choice !=9)
			{
			
			printf("Invalid Choice Please re-Enter your choice");
			scanf("%d",&choice);
			
			}
			
		*/

			
			    
	//		    if(scanf("%d", &choice) == 0) /* If scanf failed */
	//		    {
	//		        printf("Invalid input found!");
	//		        scanf("%*s"); /* Get rid of the invalid input (a word) */
	//		    }/
			
		
			switch(choice)
				{
					case 'a': 
							{	
								int ch;
								printf("\n****patients who suffer from issues related to allergies, such as hay, fever, or asthma.**");
								getch();
								printf("\n\nTo change the catogory please press 2 continue further plese press 1 - ");
								scanf("%d",&ch);
									
									if(ch==1)
										{
										audiologist();	
											
										}
										
									if(ch==2) break;
								
							};break;
							
					case 'b': 
							{
								int ch;
								printf("\n****treatment of the heart and the many diseases and issues related to it.**");
								getch();
								printf("\n\nTo change the catogory please press 2 continue further plese press 1 - ");
								scanf("%d",&ch);
									
									if(ch==1)
										{
										cardiologist();	
											
										}
										
									if(ch==2) break;
							} break;
							
					case 'c':
							{
								int ch;
								printf("\n****work with the human mouth, examining teeth and gum health and preventing and detecting various different issues.**");
								getch();
								printf("\n\nTo change the catogory please press 2 continue further plese press 1 - ");
								scanf("%d",&ch);
									
									if(ch==1)
										{
										dentist(); 	
											
										}
										
									if(ch==2) break;
								
							} break;
							
					case 'd':
							{
									int ch;
									printf("\n****skin and the structures, functions and diseases related to it.**");
									getch();
									printf("\n\nTo change the catogory please press 2 continue further plese press 1 - ");
									scanf("%d",&ch);
										
										if(ch==1)
											{
											dermatologist();	
												
											}
											
										if(ch==2) break;	
			
							} break;
							
					case 'e': 
							{
								int ch;
								printf("\n****work with human brain to determine causes and treatments for illnesses as Alzheimer’s, Parkinson’s, Dementia, and many others.**");
								getch();
								printf("\n\nTo change the catogory please press 2 continue further plese press 1 - ");
								scanf("%d",&ch);
									
									if(ch==1)
										{
										neurologist();	
											
										}
										
									if(ch==2) break;	
							} break;
							
					case 'f': 
							{
								int ch;
								printf("\n****concentrate in areas related to the Ear, Nose, and Throat, and sometimes even ailments related to the neck or the head.**");
								getch();
								printf("\n\nTo change the catogory please press 2 continue further plese press 1 - ");
								scanf("%d",&ch);
									
									if(ch==1)
										{
										ent();	
											
										}
										
									if(ch==2) break;	
							} break;
					case 'g': 
							{
								int ch;
								printf("\n****study behavior and mental processes.**");
								getch();
								printf("\n\nTo change the catogory please press 2 continue further plese press 1 - ");
								scanf("%d",&ch);
										
									if(ch==1)
										{
										psy();		
												
										}
											
									if(ch==2) break;	
							} break;
					
					case 'h': bdate(); break;
					
					case 'i': vbdate(); break;
					
					case 'j': 
								{	
									system("cls");
									printf("Loging Out.....");
									sleep(2);
									main();
								}break;
						
					case 'x': exit(0); break;
					
					default: printf("\n7catogory you selected is invalid");
					
				}
	}


	
}

void audiologist()
{

	char ch;
	
		
		while(1)
		{
			system("cls");
			
				printf("\nAvailable Doctors to the Specified Catogory are as below");
	
				printf("\n\n1.Dr.D.K.Padmakumara (at 9.00 a.m)");
				printf("\n2.Dr.D.R.Kuruppu (at 7.00 p.m)");
				printf("\n3.Return to Selection Menu");
				printf("\n4.exit");
				
				printf("\n\nPlease Enter your choice - ");
				scanf("%c",&ch);
			
				switch(ch)
					{
						case '1':
								{	static int i=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("dkpadmakumara.dat","ab");//creating and opening the file specified
									
										if(i==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
								
											if(i<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="D.K.Padmakumara";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();													
												i++;										
											}
									
									getch();
																		
							} break;
								
						case '2':
								{
								
									static int j=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("drkuruppu.dat","ab");//creating and opening the file specified
									
										if(j==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
								
											if(j<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="D.R.Kuruppu";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												j++;
											}
									getch();	
									
								} break;
						case '3': docdispcato(); break;
						case '4': exit(0); break;
						default: printf("\nInvalid Choice Please try again");
						
					}
		
		}
	
}

void cardiologist()
{

	char ch;
	
		
		while(1)
		{
			system("cls");
			
				printf("\nAvailable Doctors to the Specified Catogory are as below");
	
				printf("\n\n1.Dr.D.C.Premarathne (at 9.00 a.m)");
				printf("\n2.Dr.D.P.Pushpakumara (at 7.00 p.m)");
				printf("\n3.Return to Selection Menu");
				printf("\n4.exit");
				
				printf("\n\nPlease Enter your choice - ");
				scanf("%c",&ch);
			
				switch(ch)
					{
						case '1':
								{
									static int i=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("dcpremarathne.dat","ab");//creating and opening the file specified
									
									
										if(i==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
										
											if(i<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="D.C.Premarathne";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												i++;
											}
									getch();		
									
								} break;
								
						case '2':
								{
									static int j=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("dppushpakumara.dat","ab");//creating and opening the file specified
									
										if(j==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
								
											if(j<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="D.P.Pushpakumara";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												j++;
											}
									getch();
									
									
								} break;
						
						case '3':docdispcato(); break;		
						case '4': exit(0); break;
						default: printf("\nInvalid Choice Please try again");
						
					}
		
		}		

}

void dentist()
{

	char ch;
	
		
		while(1)
		{
			system("cls");
			
				printf("\nAvailable Doctors to the Specified Catogory are as below");
	
				printf("\n\n1.Dr.B.Nanayakkara (at 9.00 a.m)");
				printf("\n2.Dr.C.P.Perera (at 7.00 p.m)");
				printf("\n3.Return to Selection Menu");
				printf("\n4.exit");
				
				printf("\n\nPlease Enter your choice - ");
				scanf("%c",&ch);
			
				switch(ch)
					{
						case '1':
								{
									static int i=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("bnanayakkara.dat","ab");//creating and opening the file specified
									
									
										if(i==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
										
											if(i<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="B.Nanayakkara";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												i++;
											}
									getch();
	
								} break;
								
						case '2':
								{
									
									static int j=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("cpperera.dat","ab");//creating and opening the file specified
									
									
										if(j==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
										
											if(j<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="C.P.Perera";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												j++;
											}
									getch();
									
								} break;
						
						case '3':docdispcato(); break;		
						case '4': exit(0); break;
						default: printf("\nInvalid Choice Please try again");
						
					}
		
		}	
	
}

void dermatologist()
{

	char ch;
	
		
		while(1)
		{
			system("cls");
			
				printf("\nAvailable Doctors to the Specified Catogory are as below");
	
				printf("\n\n1.Dr.A.P.Ranawaka (at 9.00 a.m)");
				printf("\n2.Dr.S.Supun Perera (at 7.00 p.m)");
				printf("\n3.Return to Selection Menu");
				printf("\n4.exit");
				
				printf("\n\nPlease Enter your choice - ");
				scanf("%c",&ch);
			
				switch(ch)
					{
						case '1':
								{
									
									static int i=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("apranawaka.dat","ab");//creating and opening the file specified
									
									
										if(i==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
										
											if(i<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="A.P.Ranawaka";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												i++;
											}
									getch();
									
								} break;
								
						case '2':
								{
								
									static int j=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("ssupunperera.dat","ab");//creating and opening the file specified
									
									
										if(j==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
										
											if(j<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="S.Supun Perera";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												j++;
											}
									getch();	
									
								} break;
								
						case '3':docdispcato(); break;
						case '4': exit(0); break;
						default: printf("\nInvalid Choice Please try again");
						
					}
		
		}

}

void neurologist()
{

	char ch;
	
		
		while(1)
		{
			system("cls");
			
				printf("\nAvailable Doctors to the Specified Catogory are as below");
	
				printf("\n\n1.Dr.S.S.Senarathne (at 9.00 a.m)");
				printf("\n2.Dr.A.S.Silva (at 7.00 p.m)");
				printf("\n3.Return to Selection Menu");
				printf("\n4.exit");
				
				printf("\n\nPlease Enter your choice - ");
				scanf("%c",&ch);
			
				switch(ch)
					{
						case '1':
								{
									
									static int i=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("sssenarathne.dat","ab");//creating and opening the file specified
									
									
										if(i==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
										
											if(i<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="S.S.Senarathne";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												i++;
											}
									getch();
									
									
								} break;
						case '2':
								{
									
									static int j=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("assilva.dat","ab");//creating and opening the file specified
									
									
										if(j==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
										
											if(j<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="A.S.Silva";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												j++;
											}
									getch();
	
								} break;
						
						case '3':docdispcato(); break;		
						case '4': exit(0); break;
						default: printf("\nInvalid Choice Please try again");
						
					}
		
		}	
	
}

void ent()
{

	char ch;
	
		
		while(1)
		{
			system("cls");
			
				printf("\nAvailable Doctors to the Specified Catogory are as below");
	
				printf("\n\n1.Dr.D.M.Silva (at 9.00 a.m)");
				printf("\n2.Dr.F.K.Fonseka (at 7.00 p.m)");
				printf("\n3.Return to Selection Menu");
				printf("\n4.exit");
				
				printf("\n\nPlease Enter your choice - ");
				scanf("%c",&ch);
			
				switch(ch)
					{
						case '1':
								{
									
									static int i=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("dmsilva.dat","ab");//creating and opening the file specified
									
									
										if(i==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
																	
											if(i<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="D.M.Silva";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												i++;
											}
									getch();
									
									
								} break;
						case '2':
								{
									
									static int j=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("fkfonseka.dat","ab");//creating and opening the file specified
									
									
										if(j==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
										
											if(j<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="F.K.Fonseka";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												j++;
											}
									getch();
									
									
								} break;
								
						case '3':docdispcato(); break;
						case '4': exit(0); break;
						default: printf("\nInvalid Choice Please try again");
						
					}
		
		}	
	
}

void psy()
{

	char ch;
	
		
		while(1)
		{
			system("cls");
			
				printf("\nAvailable Doctors to the Specified Catogory are as below");
	
				printf("\n\n1.Dr.L.A.Demiyan (at 9.00 a.m)");
				printf("\n2.Dr.N.A.Senaratne (at 7.00 p.m)");
				printf("\n3.Return to Selection Menu");
				printf("\n4.exit");
				
				printf("\n\nPlease Enter your choice - ");
				scanf("%c",&ch);
			
				switch(ch)
					{
						case '1':
								{
								
									static int i=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									source=fopen("lademiyan.dat","ab");//creating and opening the file specified
									
									
										if(i==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
											if(i<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="L.A.Damiyan";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												i++;
											}
									getch();	
									
								} break;
						case '2':
								{
									
									static int j=1;
									FILE *source; //file name source
									//char another='y';
									struct patient detail; //importing data structure to variable detail
									
									source=fopen("nasenarathne.dat","ab");//creating and opening the file specified
									
									
										if(j==11)
										printf("\n\nMaximum number of patients for this doctor is reached or Invalid Choice (max 10)");
										
											while(j<=10)
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												detail.doc="N.A.Senarathna";
												rec(detail);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												//printf("\n Add another record (y/n) :");
												//another=getche();
												j++;
											}
									getch();
									
								} break;
								
						case '3':docdispcato(); break;
						case '4': exit(0); break;
						default: printf("\nInvalid Choice Please try again");
						
					}
		
		}
	
}

void bdate()
{

									FILE *source; //file name source
									char another='y';
									struct uppatient detail; //importing data structure to variable detail
									
									source=fopen("uppatient.dat","ab");//creating and opening the file specified
									
									
								
											while(another=='y')
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Date to be Channeled : ");
												fflush(stdin);
												gets(detail.date);
												printf("\n Catogory you need to assign Patient : ");
												fflush(stdin);
												gets(detail.doccato);
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.p_id);
												printf("\n Name : ");
												fflush(stdin);
												gets(detail.name);
												printf("\n Sex : ");
												fflush(stdin);
												gets(detail.sex);
												printf("\n Age : ");
												gets(detail.age);
												printf("\n Bloodgroup : ");
												fflush(stdin);
												gets(detail.bloodgroup);
												printf("\n Address : ");
												fflush(stdin);
												gets(detail.address);
												printf("\n Diagnosis : ");
												fflush(stdin);
												gets(detail.diagnosis);
												printf("\n Test : ");
												fflush(stdin);
												gets(detail.test);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												printf("\n Add another record (y/n) :");
												another=getche();
												
											}	
	
}

void vbdate()
{
	system("cls");
								//printf("\nRoom\tDoctor\tPID\tName\tAddress\tBgrp\tDiag\tSex\tTest\tAge\n");
								FILE *target;
								struct uppatient detail;
								//char ch;
								target=fopen("uppatient.dat","rb");
								if(target==NULL)
								{
								printf("\n Can not open file Please check whether there are any upcoming patient entries");
								getch();
								}
								else
								{
									while(fread(&detail,sizeof(struct uppatient),1,target)==1)
									{
									printf("\nDate:%s\nCatogory:%s\nPatient ID:%s\nPatient Name:%s\nSex:%s\nAge:%s\nBloodgroup:%s\nAddress:%s\nDiagnosis:%s\nTest:%s\n\n",detail.date,detail.doccato,detail.p_id,detail.name,detail.sex,detail.age,detail.bloodgroup,detail.address,detail.diagnosis,detail.test);
									}
								 
								fclose(target);
								getch();
								}	
	
}


void room()
{	system("cls");
	char ch;			
			
		while(1)
			{
					
			
			printf("\n========== MENU ==========");
			printf("\n1.Information of Rooms");
			printf("\n2.Information of Doctors");
			printf("\n3.View Assigned Rooms");
			printf("\n4.Assign rooms for patients");
			printf("\n5.Log Out");
			printf("\n6.Exit from the program");
			
			printf("\n\nPlease Enter Your Choice - ");
			scanf("%c",&ch);
			system("cls");
			
				switch(ch)
					{
						case '1': wardroom();	break;
						
						case '2':	warddoc();  break;
						
						case '3':
							{	
								system("cls");
								//printf("\nRoom\tDoctor\tPID\tName\tAddress\tBgrp\tDiag\tSex\tTest\tAge\n");
								FILE *target;
								struct room detail;
								//char ch;
								target=fopen("room.dat","rb");
								if(target==NULL)
								{
								printf("\n Can not open file");
								}
								else
								{
									while(fread(&detail,sizeof(struct room),1,target)==1)
									{
									printf("\nRoom:%s\nDoctor:%s\nPatient ID:%s\nPatient Name:%s\nAddress:%s\nBloodgroup:%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.room,detail.doctor,detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
									}
								 
								fclose(target);
								getch();
								}	
							}	break;
							
						case '4':	roomassign(); break;
						
						case '5':
								{
									system("cls");
									printf("Logging Out....");
									main();
								}	
						case '6':
							 {
							 	printf("Now Exiting from the program");
							 	sleep(2);
								exit(0);
							 } break;
							 
						
						
					}
			}
				
	
}

void wardroom()
{
	
	printf("\n\nRoom No1 - Non A/C");	
	printf("\n\nRoom No2 - with A/C");
	printf("\n\nRoom No3 - with A/C & TV");
	printf("\n\nRoom No4 - with A/C & another Seperate Bed ");
	printf("\n\nRoom No5 - Luxary");
	getch();
	
}

void warddoc()
{
	printf("\n\n1.Dr.E.N.Premasiri - Audiologist");	
	printf("\n\n2.Dr.A.S.P.Sampath - Dermatologist");
	printf("\n\n3.Dr.R.T.Atthanayake - Neurologist");
	printf("\n\n4.Dr.D.D.Fernando - ENT Specialist ");
	printf("\n\n5.Dr.A.T.Priyanthi - Psychiatrist");	
	getch();
	
}

void roomassign()
{
	
	char ch;
	
		while(1)
			{
			
				system("cls");
				printf("========== MENU ==========");
				printf("\n1.List of Doctors");
				printf("\n2.List of Rooms");
				printf("\n3.Assign Rooms");
				printf("\n4.Back");
				printf("\n5.Exit");
				
				printf("\n\nPlease Enter Your Choice - ");
				scanf("%c",&ch);
				
					switch(ch)
						{
							case '1': warddoc(); break;
							
							case '2': wardroom(); break;
							
							case '3':
								{
									int i;
									
									printf("\nPlese Select your ROOM number");	
									printf("\n\n===== ROOM MENU =====");
									printf("\n1.Room 1:");
									printf("\n2.Room 2:");	
									printf("\n3.Room 3:");	
									printf("\n4.Room 4:");	
									printf("\n5.Room 5:");
									
									printf("\n\nEnter your choice - ");
									scanf("%d",&i);
									
										switch(i)
											{
											
												case 1:
													{
														static int r1=1;
														FILE *source; //file name source
														struct room detail; //importing data structure to variable detail
														
														source=fopen("room.dat","ab");//creating and opening the file specified
												
												
											
														while(r1<2)
														{
															printf("\n Enter Details of a patient --\n");
															printf("\n Enter the Room No. : ");
															fflush(stdin);
															gets(detail.room);
															printf("\n Doctor you need to Assign : ");
															fflush(stdin);
															gets(detail.doctor);
															printf("\n Patient ID : ");
															fflush(stdin);//avoid the strings between spaces
															gets(detail.p_id);
															printf("\n Name : ");
															fflush(stdin);
															gets(detail.name);
															printf("\n Sex : ");
															fflush(stdin);
															gets(detail.sex);
															printf("\n Age : ");
															gets(detail.age);
															printf("\n Bloodgroup : ");
															fflush(stdin);
															gets(detail.bloodgroup);
															printf("\n Address : ");
															fflush(stdin);
															gets(detail.address);
															printf("\n Diagnosis : ");
															fflush(stdin);
															gets(detail.diagnosis);
															printf("\n Test : ");
															fflush(stdin);
															gets(detail.test);
															if(source==NULL)
															{
															printf("\n Can not open file.");
															}
															else
															{
															fwrite(&detail,sizeof(detail),1,source);
															fclose(source);
															}
															r1++;
															
														}
														if(r1==2)
															printf("The Room Number 1 is done booking");
															getch();		
														
													} break;
												
												case 2:
													{
														
														static int r2=1;
														FILE *source; //file name source
														struct room detail; //importing data structure to variable detail
														
														source=fopen("room.dat","ab");//creating and opening the file specified
												
												
											
														while(r2<2)
														{
															printf("\n Enter Details of a patient --\n");
															printf("\n Enter the Room No. : ");
															fflush(stdin);
															gets(detail.room);
															printf("\n Doctor you need to Assign : ");
															fflush(stdin);
															gets(detail.doctor);
															printf("\n Patient ID : ");
															fflush(stdin);//avoid the strings between spaces
															gets(detail.p_id);
															printf("\n Name : ");
															fflush(stdin);
															gets(detail.name);
															printf("\n Sex : ");
															fflush(stdin);
															gets(detail.sex);
															printf("\n Age : ");
															gets(detail.age);
															printf("\n Bloodgroup : ");
															fflush(stdin);
															gets(detail.bloodgroup);
															printf("\n Address : ");
															fflush(stdin);
															gets(detail.address);
															printf("\n Diagnosis : ");
															fflush(stdin);
															gets(detail.diagnosis);
															printf("\n Test : ");
															fflush(stdin);
															gets(detail.test);
															if(source==NULL)
															{
															printf("\n Can not open file.");
															}
															else
															{
															fwrite(&detail,sizeof(detail),1,source);
															fclose(source);
															}
															r2++;
															
														}
														if(r2==2)
															printf("The Room Number 2 is done booking");
															getch();
														
														
													} break;
												
												case 3:
													{
														
														static int r3=1;
														FILE *source; //file name source
														struct room detail; //importing data structure to variable detail
														
														source=fopen("room.dat","ab");//creating and opening the file specified
												
												
											
														while(r3<2)
														{
															printf("\n Enter Details of a patient --\n");
															printf("\n Enter the Room No. : ");
															fflush(stdin);
															gets(detail.room);
															printf("\n Doctor you need to Assign : ");
															fflush(stdin);
															gets(detail.doctor);
															printf("\n Patient ID : ");
															fflush(stdin);//avoid the strings between spaces
															gets(detail.p_id);
															printf("\n Name : ");
															fflush(stdin);
															gets(detail.name);
															printf("\n Sex : ");
															fflush(stdin);
															gets(detail.sex);
															printf("\n Age : ");
															gets(detail.age);
															printf("\n Bloodgroup : ");
															fflush(stdin);
															gets(detail.bloodgroup);
															printf("\n Address : ");
															fflush(stdin);
															gets(detail.address);
															printf("\n Diagnosis : ");
															fflush(stdin);
															gets(detail.diagnosis);
															printf("\n Test : ");
															fflush(stdin);
															gets(detail.test);
															if(source==NULL)
															{
															printf("\n Can not open file.");
															}
															else
															{
															fwrite(&detail,sizeof(detail),1,source);
															fclose(source);
															}
															r3++;
															
														}
														if(r3==2)
															printf("The Room Number 3 is done booking");
															getch();
														
														
													} break;
													
												case 4:
													{
														
														static int r4=1;
														FILE *source; //file name source
														struct room detail; //importing data structure to variable detail
														
														source=fopen("room.dat","ab");//creating and opening the file specified
												
												
											
														while(r4<2)
														{
															printf("\n Enter Details of a patient --\n");
															printf("\n Enter the Room No. : ");
															fflush(stdin);
															gets(detail.room);
															printf("\n Doctor you need to Assign : ");
															fflush(stdin);
															gets(detail.doctor);
															printf("\n Patient ID : ");
															fflush(stdin);//avoid the strings between spaces
															gets(detail.p_id);
															printf("\n Name : ");
															fflush(stdin);
															gets(detail.name);
															printf("\n Sex : ");
															fflush(stdin);
															gets(detail.sex);
															printf("\n Age : ");
															gets(detail.age);
															printf("\n Bloodgroup : ");
															fflush(stdin);
															gets(detail.bloodgroup);
															printf("\n Address : ");
															fflush(stdin);
															gets(detail.address);
															printf("\n Diagnosis : ");
															fflush(stdin);
															gets(detail.diagnosis);
															printf("\n Test : ");
															fflush(stdin);
															gets(detail.test);
															if(source==NULL)
															{
															printf("\n Can not open file.");
															}
															else
															{
															fwrite(&detail,sizeof(detail),1,source);
															fclose(source);
															}
															r4++;
															
														}
														if(r4==2)
															printf("The Room Number 4 is done booking");
															getch();
															
														
													} break;
													
												case 5:
													{
														
														static int r5=1;
														FILE *source; //file name source
														struct room detail; //importing data structure to variable detail
														
														source=fopen("room.dat","ab");//creating and opening the file specified
												
												
											
														while(r5<2)
														{
															printf("\n Enter Details of a patient --\n");
															printf("\n Enter the Room No. : ");
															fflush(stdin);
															gets(detail.room);
															printf("\n Doctor you need to Assign : ");
															fflush(stdin);
															gets(detail.doctor);
															printf("\n Patient ID : ");
															fflush(stdin);//avoid the strings between spaces
															gets(detail.p_id);
															printf("\n Name : ");
															fflush(stdin);
															gets(detail.name);
															printf("\n Sex : ");
															fflush(stdin);
															gets(detail.sex);
															printf("\n Age : ");
															gets(detail.age);
															printf("\n Bloodgroup : ");
															fflush(stdin);
															gets(detail.bloodgroup);
															printf("\n Address : ");
															fflush(stdin);
															gets(detail.address);
															printf("\n Diagnosis : ");
															fflush(stdin);
															gets(detail.diagnosis);
															printf("\n Test : ");
															fflush(stdin);
															gets(detail.test);
															if(source==NULL)
															{
															printf("\n Can not open file.");
															}
															else
															{
															fwrite(&detail,sizeof(detail),1,source);
															fclose(source);
															}
															r5++;
															
														}
														if(r5==2)
															printf("The Room Number 5 is done booking");
															getch();	
														
													} break;
													
												default:
													{
												 	printf("Invalid Room Number");
												 	getch(); 
													}	 
											
											
											
											}		
									
									
									
									
									
									
								}	break;
								
							case '4': room(); break;
							
							case '5':	
								{
									printf("Now exiting from the program");
									sleep(2);
									exit(0);
								 } break;
										 
							default : printf("Invalid choice");
						}
			}
	
}

void medical()
{
char ch;

	while(1)
		{
		
				system("cls");
				printf("\n\n========== MENU ==========");
				printf("\n\n1.View patient Details");
				printf("\n2.Create a Report of the patient");
				printf("\n3.Back");
				printf("\n4.Login Menu");
				printf("\n5.Exit");
				
				printf("\nplease enter your choice - ");
				scanf("%c",&ch);
				
					switch(ch)
						{
							
							case '1': docselect(); break;
							
							case '2': reportmed(); break;
							
							case '3': doc(); break;
							
							case '4':
									{
										system("cls");
										printf("Logging Out....");
										main();
									}
							case '5': exit(0); break;
							
							default:
								{
								printf("\nInvalid Choioce");
								getch();
								} 
							
							
							
						}
		}
	
	
	
}

void wards()
{

char ch;

	while(1)
		{
		
			system("cls");
			printf("\n\n========== MENU ==========");
			printf("\n\n1.View patient Details");
			printf("\n2.Create a Report of the patient");
			printf("\n3.Back");
			printf("\n4.Log Out");
			printf("\n5.Exit");
			
			printf("\nplease enter your choice - ");
			scanf("%c",&ch);
			
				switch(ch)
					{
						
						case '1':
							{
								
								system("cls");
								//printf("\nRoom\tDoctor\tPID\tName\tAddress\tBgrp\tDiag\tSex\tTest\tAge\n");
								FILE *target;
								struct room detail;	
								target=fopen("room.dat","rb");
								if(target==NULL)
									{
										printf("\n Can not open file");
									}
								else
									{
										while(fread(&detail,sizeof(struct room),1,target)==1)
										{
										printf("\nRoom:%s\nDoctor:%s\nPatient ID:%s\nName:%s\nAddress:%s\nBloodgroup:%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.room,detail.doctor,detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
										}
										 
									fclose(target);
									getch();
		
									} 
							} break;
						case '2':
							{
								reportward();	
								
							} break;
							
						case '3': doc(); break;
							
						case '4':
								{
									system("cls");
									printf("Logging Out....");
									main();
								}
							
						case '5': exit(0); break;
							
						default: printf("Invalid Choice");
								
						
					}	
		}
}


void docselect()
{
	
	char ch,c;
	FILE *source;
	
	while(1)
		{
		
	
				system("cls");
				printf("\n========== Selection MENU ==========");
				printf("\n\nA.Dr.D.K.padmakumara");
				printf("\nB.Dr.D.R.Kuruppu");
				printf("\nC.Dr.D.C.Premarathne");
				printf("\nD.Dr.D.P.Pushpakumara");
				printf("\nE.Dr.B.Nanayakkara");
				printf("\nF.Dr.C.P.Perera");
				printf("\nG.Dr.A.P.Ranawaka");
				printf("\nH.Dr.S.Supun Perera");
				printf("\nI.Dr.S.S.Senarathne");
				printf("\nJ.Dr.A.S.Silva");
				printf("\nK.Dr.D.M.Silva");
				printf("\nL.Dr.F.K.Fonseka");
				printf("\nM.Dr.L.A.Demiyan");
				printf("\nN.Dr.N.A.Senarathne");
				printf("\nO.Back");
				printf("\nP.Logout");
				printf("\nX.Exit");
				
				printf("\n\nPlease Enter Your Choice (use lowercase) - ");
				scanf("%c",&ch);
				
					switch(ch)
						{
							
							case 'a':
								{
													
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("dkpadmakumara.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > dkpadmakumara.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}	
										}
										
										
								} break;
								
							case 'b':
								{
									
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("drkuruppu.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > drkuruppu.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
								} break;
								
							case 'c':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("dcpremarathne.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > dcpremarathne.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}	
									
								} break;
								
								
							case 'd':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("dppushpakumara.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > dppushpakumara.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
								
								
							case 'e':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("bnanayakkara.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > bnanayakkara.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
								
							case 'f':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("cpperera.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > cpperera.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
								
								
							case 'g':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("apranawaka.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > apranawaka.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
								
								
							case 'h':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("ssupunperera.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > ssupunperera.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
								
								
							case 'i':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("sssenarathne.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > sssenarathne.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
								
								
							case 'j':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("assilva.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > assilva.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
								
								
							case 'k':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("dmsilva.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > dmsilva.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
								
								
							case 'l':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("fkfonseka.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > fkfonseka.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
								
								
							case 'm':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("lademiyan.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > lademiyan.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
								
								
							case 'n':
								{
									printf("\n1.View Patients");
									printf("\n2.Finalize the day");
									
									printf("\n\nEnter your choice - ");
									scanf("%s",&c);
									
										switch(c)
										{
											case '1':
												{
												
														system("cls");
														printf("Welcome Doctor");
														sleep(1);
														//printf("\nPID\tName\tAddress\t\tBgrp\tDiag\tSex\tTest\tAge\n");
														FILE *target;
														struct patient detail;
														char ch;
														target=fopen("nasenarathne.dat","rb");
														if(target==NULL)
														{
														printf("\nSorry can not open file or You have no patients Doctor");
														}
														else
														{
														while(fread(&detail,sizeof(struct patient),1,target)==1)
														{
														printf("\nPatient ID:%s\nPAtient Name:%s\nAddress:%s\nBloodgroup%s\nDiagnosis:%s\nSex:%s\nTest:%s\nAge:%s\n\n",detail.p_id,detail.name,detail.address,detail.bloodgroup,detail.diagnosis,detail.sex,detail.test,detail.age);
														}
														fclose(target);	
														}	
														getch();
												} break;
												
											case '2': system("cat/dev/null > nasenarathne.dat"); break;
												
											default : 
												{
													printf("Invalid choice");
													getch();
												}
												
												
										}
									
									
								} break;
							
							case 'o': medical(); break;	
																
							case 'p':
									{
										system("cls");
										printf("Logging Out....");
										main();
									}
								
							case 'x':
								{
									printf("Thank you Doctor ");
									sleep(2);
									exit(0);
									
								} break;
								
							default:	printf("Invalid choice");
												
									
							
							
						}
		}
	
}

void reportmed()
{
									FILE *source; //file name source
									char another='y';
									struct report detail; //importing data structure to variable detail
									
									source=fopen("reportmed.dat","ab");//creating and opening the file specified
									
									
								
											while(another=='y')
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.pid);
												printf("\n Scans : ");
												fflush(stdin);
												gets(detail.scans);
												printf("\n Medicine : ");
												fflush(stdin);
												gets(detail.medicine);
												printf("\n Ward (put 'N' if not Available) : ");
												fflush(stdin);
												gets(detail.ward);
												printf("\n Other (put 'N' if not Available) : ");
												fflush(stdin);
												gets(detail.other);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												printf("\n Add another record (y/n) :");
												another=getche();
												
											}		
	
}


void reportward()
{
									FILE *source; //file name source
									char another='y';
									struct report detail; //importing data structure to variable detail
									
									source=fopen("reportward.dat","ab");//creating and opening the file specified
									
									
								
											while(another=='y')
											{
												printf("\n Enter Details of a patient --\n");
												printf("\n Patient ID : ");
												fflush(stdin);//avoid the strings between spaces
												gets(detail.pid);
												printf("\n Scans : ");
												fflush(stdin);
												gets(detail.scans);
												printf("\n Medicine : ");
												fflush(stdin);
												gets(detail.medicine);
												printf("\n Ward (put 'N' if not Available) : ");
												fflush(stdin);
												gets(detail.ward);
												printf("\n Other (put 'N' if not Available) : ");
												fflush(stdin);
												gets(detail.other);
												if(source==NULL)
												{
												printf("\n Can not open file.");
												}
												else
												{
												fwrite(&detail,sizeof(detail),1,source);
												fclose(source);
												}
												printf("\n Add another record (y/n) :");
												another=getche();
												
											}		
	
}

void calmed()
{
	int c=1;
	char id[100];
	float cf=0,sc=0,med=0,wd=0,oth=0,tot=0;
	
						system("cls");
						//printf("\nPID\tScans\tMedicine\n");
						FILE *target;
						struct report detail;
						char ch;
						target=fopen("reportmed.dat","rb");
						if(target==NULL)
						{
						printf("\nSorry can not open file or no Reports for this section");
						}
						else
						{
						while(fread(&detail,sizeof(struct report),1,target)==1)
						{
						printf("\nPatient ID:%s\nScans:%s\nMedicine:%s\nWard:%s\nOther:%s\n\n",detail.pid,detail.scans,detail.medicine,detail.ward,detail.other);
						}
						fclose(target);	
						}	
						printf("\nPress any key to start calculating bill");
						getch();
						
						
							while(c==1)
								{
									printf("\n______________________________________________________");
									printf("\nEnter patient ID - ");
									scanf("%s",&id);
									printf("\nEnter Channel Fee - ");
									scanf("%f",&cf);
									printf("\nEnter Amount for the Scans - ");
									scanf("%f",&sc);
									printf("\nEnter Amount for the Medicine - ");
									scanf("%f",&med);
									printf("\nEnter Amount for the Ward charges - ");
									scanf("%f",&wd);
									printf("\nEnter Amount for Others - ");
									scanf("%f",&oth);
									
									tot=cf+sc+med+wd+oth;
									mtot=mtot+tot;
									mc++;
									
									printf("\nTotal Amount for the Patient ID %s is %.2f - ",id,tot);
									printf("\n______________________________________________________");
									
									printf("\n\nTo calculate another bill Press 1 - ");
									scanf("%d",&c);
							
									
								}
							
		
	
}

void calward()
{
	int c=1;
	char id;
	float cf=0,sc=0,med=0,wd=0,oth=0,tot=0;
	
						system("cls");
						//printf("\nPID\tScans\tMedicine\n");
						FILE *target;
						struct report detail;
						char ch;
						target=fopen("reportward.dat","rb");
						if(target==NULL)
						{
						printf("\nSorry can not open file or no Reports for this section");
						}
						else
						{
						while(fread(&detail,sizeof(struct report),1,target)==1)
						{
						printf("\nPatient ID:%s\nScans:%s\nMedicine:%s\nWard:%s\nOther:%s\n\n",detail.pid,detail.scans,detail.medicine,detail.ward,detail.other);
						}
						fclose(target);	
						}	
						getch();
						
						
							while(c==1)
									{
										printf("\n______________________________________________________");
										printf("\nEnter patient ID - ");
										scanf("%s",&id);
										printf("\nEnter Channel Fee - ");
										scanf("%f",&cf);
										printf("\nEnter Amount for the Scans - ");
										scanf("%f",&sc);
										printf("\nEnter Amount for the Medicine - ");
										scanf("%f",&med);
										printf("\nEnter Amount for the Ward charges - ");
										scanf("%f",&wd);
										printf("\nEnter Amount for Others - ");
										scanf("%f",&oth);
										
										tot=cf+sc+med+wd+sc;
										wtot=wtot+tot;
										wc++;
										
										printf("\nTotal Amount for the Patient ID %d is %.2f - ",id,tot);
										printf("\n______________________________________________________");
										
										printf("\n\nTo calculate another bill Press 1 -");
										scanf("%d",&c);
								
										
									}
	
	
}

void delay()
{
	for(int c=10;c>0;c--)
		{
			system("cls");
			printf("Please wait %d Seconds before login",c);
			sleep(1);
		}
	
}

void rec(struct patient p)
{
	printf("\n\n========== RECIEPT ==========");
	printf("\nDoctor : %s",p.doc);
	printf("\nNo : %s",p.p_id);
	printf("\nPatient Name : %s",p.name);
	printf("\nTest : %s",p.test);
	printf("\n==============================");
}

void logind()
{
	FILE *f;
	char c;
	
	f = fopen("userlog.txt", "r");
    if (f == NULL)
    printf("Cannot open file or No user login Info \n");
    
    else
    	{
    		 c = fgetc(f);
    			while (c != EOF)
    				{
        				printf ("%c", c);
        				c = fgetc(f);
   					}
    		fclose(f);
		}

    getch();
	
}

void cashd()
{
	printf("========== TOTAL AMOUNTS ==========");
	printf("\n\nMedical Patients count : %d Total Amount : %.2f",mc,mtot);
	printf("\n\nWard Patients count : %d Total Amount : %.2f",wc,wtot);
	getch();
	
}

void about()
{
	system("cls");
	printf("\n**********Hospital Management System**********");
	printf("\n****************Version 1.0.0*****************");
	printf("\n********** DCSC 16.2 Group Number 7 **********");
	printf("\n\t**********HishD**********");
	getch();
	
}

void load()
{
	printf("\n\n");
				printf("\t\t       ===========================================================================");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\tHOSPITAL MANAGEMENT SYSTEM\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t      Developed By DCSD 16.2 Group 7\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\tVersion 1.0\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ===========================================================================");
				printf("\n\n\n||||||||||||||||||||||||||||||");
				printf("\n\t\t\t\t\t\t\tLoading(25)");
				sleep(1);
				system("cls");
				printf("\n\n");
				printf("\t\t       ===========================================================================");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\tHOSPITAL MANAGEMENT SYSTEM\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t      Developed By DCSD 16.2 Group 7\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\tVersion 1.0\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ===========================================================================");
				printf("\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
				printf("\n\t\t\t\t\t\t\tLoading(55)");
				sleep(1);
				system("cls");
				printf("\n\n");
				printf("\t\t       ===========================================================================");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\tHOSPITAL MANAGEMENT SYSTEM\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t      Developed By DCSD 16.2 Group 7\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\tVersion 1.0\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ===========================================================================");
				printf("\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
				printf("\n\t\t\t\t\t\t\tLoading(78)");
				sleep(1);
				system("cls");
				printf("\n\n");
				printf("\t\t       ===========================================================================");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\tHOSPITAL MANAGEMENT SYSTEM\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t      Developed By DCSD 16.2 Group 7\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\tVersion 1.0\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ===========================================================================");
				printf("\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
				printf("\n\t\t\t\t\t\t\tLoading(92)");
				sleep(1);
				system("cls");
				printf("\n\n");
				printf("\t\t       ===========================================================================");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\tHOSPITAL MANAGEMENT SYSTEM\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t      Developed By DCSD 16.2 Group 7\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\tVersion 1.0\t\t\t\t||");
				printf("\n\t\t       ||\t\t\t\t\t\t\t\t\t||");
				printf("\n\t\t       ===========================================================================");
				printf("\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
				printf("\n\t\t\t\t\t\t\tLoading(99)");
				sleep(1);
				system("cls");
}
