#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>



FILE *f1,*f2,*f3;

char cname[20],cnum[20],cemail[30],cadd[20],crela[20],ename[20],ename1[20],enumb[20],eemail[20],eadd[20],erela[20];

int n,m,a=0,w=0,y,h=0;

int menu();

int regi();

int login();

int  addcontact();

int  searchcontact();

int  editcontact();

int  name_change();

int number_change();

int email_change();

int address_change();

int relation_change();

int delete_contact ();

int list_contact ();

int log_out ();



int main ()
{
    printf ("\n\n\n");
    printf ("\t\tWelcome To Contact Management\n");
    printf ("\t\t=============================\n\n\n");
    printf ("\t\t1.Register\n");
    printf ("\t\t2.Log In\n");
    printf ("\n");
    printf ("\t\tEnter Your Choice:");
    scanf ("%d",&n);
    if (n==1)
        regi();
    else if (n==2)
        login();
    else
        printf ("\t\tWrong Choice:");
}



              //This is registration part

   int regi ()
        {

        system("cls");
         printf ("\t\t======================\n");

        printf ("\t\t| Registration Page  |\n");
        printf ("\t\t======================");
        printf ("\n\n");
        char name[20],pass[20],name1[20],pass1[20];
        f1=fopen ("login.txt","r");
        printf ("\tEnter your name:");
        scanf ("%s",name);

        printf ("\tEnter your password:");
        scanf ("%s",pass);
        f1=fopen ("login.txt","a");
        fprintf (f1,"%s  %s\n",name,pass);
        printf ("\tThank you for registration\n");
        fclose(f1);
        printf ("\t\[1] Log In\n\t[2] Quit\n");
        printf ("\tEnter Your Choice");
        scanf ("%d",&m);
        if (m==1)
            login();
        else
        {
            printf ("\tThanks For Stay us\n");
            printf ("\tPress Anything For Quit This System.");

        }
            }








        //this is log in part
 int login ()
        {
             system("cls");
             printf ("\t\t============\n");

               printf ("\t\t|  Log In  |\n");
               printf ("\t\t============\n");
               printf ("\n\n");
            char nam[20],name[20],pass[20],pas[20];
            f1=(fopen ("login.txt","r"));
            printf ("\tEnter User ID(name):");
            scanf ("%s",nam);
            printf ("\tEnter User Password:");
            scanf ("%s",pas);
            while (fscanf(f1,"%s  %s\n",name,pass)!=EOF)
            {
                if ((strcmp(name,nam)==0)&&(strcmp(pass,pas)==0))
                {

                    a=1;
                    char q=menu();
                }
            }
            if (a==0){
                printf ("\tWrong ID or Password\n");
                printf ("\tTry Again\n");
                login ();
            }
        }




          //this is the main menu part
int menu()
{
     system("cls");

       printf ("\n\n\n");
       printf ("\t\t\t==========================\n");
    printf ("\t\t\t|  Welcome To Main Menu  |\n\n");
                    printf ("\t\t\t==========================\n\n\n");
                    printf ("\t\t\t1.Add Contact\n\t\t\t2.Search contact\n\t\t\t3.Edit Contact\n\t\t\t4.List Of All Contact\n\t\t\t5.Delete Contact\n\t\t\t6.Log Out\n\t\t\t7.Quit\n");
                    int p;
                    printf ("\n\n");
                    printf ("\t\t\tEnter your choice:");
                    scanf ("%d",&p);
                    if (p==1)
                        addcontact();
                    else if (p==2)
                        searchcontact();
                    else if (p==3)
                        editcontact();
                        else if (p==4)
                            list_contact ();
                            else if (p==5)
                            delete_contact ();
                            else if (p==6)
                            log_out ();

                            else
                                printf ("\t\tPress Anything For Quit\n");
}




               //this is the add contact part

int addcontact()
{
     system("cls");

       printf ("\n\n");
    int b=1;
    f2 =fopen("Contact.txt","a");
    printf ("\t\t\t__________________________________________\n");
    printf ("\t\t\t|  Welcome Here Now give us Information  |\n");
    printf ("\t\t\t__________________________________________\n");
    printf ("\n\n");
        while (b==1)
        {
            printf ("\tEnter Name:");
            scanf("%s", cname);
            printf ("\tEnter Number:");
            scanf ("%s",cnum);
            printf ("\tEnter Email:");
            scanf ("%s",cemail);
            printf ("\tEnter Address:");
            scanf ("%s",cadd);
            printf ("\tEnter Relation:");
            scanf ("%s",crela);
            fprintf (f2,"%s  %s  %s  %s  %s\n",cname,cnum,cemail,cadd,crela);
            fclose(f2);
            printf ("\tThis Contact Saved Successfully\n");
            printf ("\n\n\t[1] Add Contact\n\t[2] Search Contact\n\t[3] Main Menu\n\t[4] Quit");
            printf ("\n");
            printf ("\tEnter Your Choice:");
            scanf ("%d",&b);
        }
        if (b==2)
            searchcontact();
        else if(b==3)
            menu();
            else
                printf ("\tPress Anything For Quit\n");
}



        //this is the search contact part

int searchcontact()
{
     system("cls");
     printf ("\t\t____________________\n");
     printf ("\t\t|  Search Contact  |\n");
     printf ("\t\t____________________");

       printf ("\n\n\n");
    char name[10];
    f2=fopen("contact.txt","r");
    printf ("\tName\tNumber\t\tEmail\t\tAddress\tRelation\n");
    printf ("\t----\t------\t\t-----\t\t-------\t--------\n");
    while (fscanf(f2,"%s  %s  %s  %s  %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
    {
        printf ("\t%s\t%s %s\t%s\t%s\t\n\n",cname,cnum,cemail,cadd,crela);
    }
    fclose (f2);
    printf ("\n\n");
    printf ("\tEnter Search contact Name:");
    scanf ("%s",name);
    f2=fopen("contact.txt","r");
    while (fscanf(f2,"%s  %s  %s  %s  %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
    {
        if (strcmp(cname,name)==0)
        {
            system("cls");
            printf ("\tName\tNumber\t\tEmail\t\tAddress\tRelation\n");
            printf ("\t----\t------\t\t-----\t\t-------\t--------\n");
            printf ("\n\t%s  %s  %s  %s  %s\n",cname,cnum,cemail,cadd,crela);
            w=1;
        }
    }
   if (w==0)
            printf ("\tNot Found\n");
     printf ("\n\n\t\t[1]Main Menu\n\t\t[2] Search Again\n\t\t[3] Quit");
     printf ("\n\t\tEnter Your Choice");
     scanf ("%d",&y);
     if (y==1)
      menu();
      else if(y==2)
        searchcontact();
        else
            printf ("\tPress Anything For Quit\n");

       fclose(f2);
}



     //this is the edit contact part

int editcontact ()
{
     system("cls");
     printf ("\t\t__________________\n");
     printf ("\t\t|  Edit  Contact  |\n");
     printf ("\t\t __________________");
        printf ("\n\n\n");
    f2=fopen("contact.txt","r");

    printf ("\tName\tNumber\t\tEmail\t\tAddress\tRelation\n");
    printf ("\t----\t------\t\t-----\t\t-------\t--------\n");
    while (fscanf(f2,"%s  %s  %s  %s  %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
    {
        printf ("\t%s\t%s %s\t%s\t%s\t\n",cname,cnum,cemail,cadd,crela);
    }
    fclose (f2);
    printf ("\n\n\tEnter The Search Contact Name:");
    scanf ("%s",ename);
     system("cls");
    f2=fopen("contact.txt","r");
    while (fscanf(f2,"%s  %s  %s  %s  %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
    {
        if (strcmp(cname,ename)==0)
        {
            printf ("\tName\tNumber\t\tEmail\t\tAddress\tRelation\n");
            printf ("\t----\t------\t\t-----\t\t-------\t--------\n");
            printf ("\t%s\t%s %s %s\t%s\t\n",cname,cnum,cemail,cadd,crela);
            h=1;
            printf ("\n\n\tEnter What You Want To Change:\n");
            printf ("\t[1] Name\t[2] Number\t[3] Email\n\t[4] Address\t[5] Relation\n");
            scanf ("%d",&n);
            if (n==1)
               name_change();
            else if (n==2)
               number_change();
            else if (n==3)
               email_change();
            else if (n==4)
               address_change();
            else if (n==5)
               relation_change();

        }



    }


    fclose(f2);

}

        //this is the name change part

int name_change()
{

  system("cls");
  FILE *f3,*f2;
  printf ("\tPrevious Name :%s\n",ename);
    printf ("\tEnter New Name:");
   scanf ("%s",ename1);
   f2=fopen ("contact.txt","r");
   f3=fopen ("edit.txt","w+");
   while (fscanf(f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {

        fprintf (f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);

   f2=fopen ("contact.txt","w+");
   f3=fopen ("edit.txt","r");
   while (fscanf(f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {
       if (strcmp(cname,ename)==0)
       {

        fprintf (f2,"%s %s %s %s %s\n",ename1,cnum,cemail,cadd,crela);
        printf ("\t\tName Change Successfully\n");
         printf ("\t\t%s %s %s %s %s\n",ename1,cnum,cemail,cadd,crela);
       }
       else

        fprintf (f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);
   remove ("edit.txt");
   printf ("\n\n\t[1] Edit Contact Again\n\t[2] Main Menu\n\t[3] See All Contacts List\n\t[4] Quit\n");
   printf ("\tEnter Your Choice:");
   scanf ("%d",&n);
   if (n==1)
   editcontact ();
   else if (n==2)
    menu ();
    else if (n==3)
        list_contact ();
   else
    printf ("\tPress Anything For Quit\n");




}


       //this is the number change part
int number_change()
{

   system("cls");
  FILE *f3,*f2;
  printf ("\n\tPrevious Number is;%s\n",cnum);
    printf ("\tEnter New Number:");
   scanf ("%s",enumb);
   f2=fopen ("contact.txt","r");
   f3=fopen ("edit.txt","w+");
   while (fscanf(f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {

        fprintf (f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);

   f2=fopen ("contact.txt","w+");
   f3=fopen ("edit.txt","r");
   while (fscanf(f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {
       if (strcmp(cname,ename)==0)
       {

        fprintf (f2,"%s %s %s %s %s\n",cname,enumb,cemail,cadd,crela);
        printf ("\t\tNumber Change Successfully\n");
         printf ("\t\t%s %s %s %s %s\n",cname,enumb,cemail,cadd,crela);
       }
       else

        fprintf (f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);
   remove ("edit.txt");
   printf ("\n\n\t[1] Edit Contact Again\n\t[2] Main Menu\n\t[3] See All Contact List\n\t[4] Quit\n");
   printf ("\tEnter Your Choice:");
   scanf ("%d",&n);
   if (n==1)
   editcontact ();
   else if (n==2)
    menu ();
    else if (n==3)
        list_contact();
   else
    printf ("\tPress Anything For Quit\n");

}


 //this is the email change part
int  email_change()
{
  system("cls");
   printf ("\n\tPrevious Email is;%s\n",cemail);

    printf ("\tEnter New Email:");
   scanf ("%s",eemail);
   f2=fopen ("contact.txt","r");
   f3=fopen ("edit.txt","w+");
   while (fscanf(f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {

        fprintf (f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);

   f2=fopen ("contact.txt","w+");
   f3=fopen ("edit.txt","r");
   while (fscanf(f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {
       if (strcmp(cname,ename)==0)
       {

        fprintf (f2,"%s %s %s %s %s\n",cname,cnum,eemail,cadd,crela);
        printf ("\t\tEmail Change Successfully\n");
         printf ("\t\t%s %s %s %s %s\n",cname,cnum,eemail,cadd,crela);
       }
       else

        fprintf (f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);
   remove ("edit.txt");
   printf ("\n\n\t[1] Edit Contact Again\n\t[2] Main Menu\n\t[3] See All Contact List\n\t[4] Quit\n");
   printf ("\tEnter Your Choice:");
   scanf ("%d",&n);
   if (n==1)
   editcontact ();
   else if (n==2)
    menu ();
    else if (n==3)
        list_contact();
   else
    printf ("\tPress Anything For Quit\n");
}


    //this is the address change part
int  address_change()

{
   system("cls");
    printf ("Previous Address is;%s\n",cadd);

   printf ("Enter New Address:");
   scanf ("%s",eadd);
   f2=fopen ("contact.txt","r");
   f3=fopen ("edit.txt","w+");
   while (fscanf(f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {

        fprintf (f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);

   f2=fopen ("contact.txt","w+");
   f3=fopen ("edit.txt","r");
   while (fscanf(f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {
       if (strcmp(cname,ename)==0)
       {

        fprintf (f2,"%s %s %s %s %s\n",cname,cnum,cemail,eadd,crela);
        printf ("\t\tAddress Change Successfully\n");
         printf ("\t\t%s %s %s %s %s\n",cname,cnum,cemail,eadd,crela);
       }
       else

        fprintf (f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);
   remove ("edit.txt");
   printf ("\n\n\t[1] Edit Contact Again\n\t[2] Main Menu\n\t[3] See All Contact List\n\t[4] Quit\n");
   printf ("\tEnter Your Choice:");
   scanf ("%d",&n);
   if (n==1)
   editcontact ();
   else if (n==2)
    menu ();
    else if (n==3)
        list_contact();
   else
    printf ("\tPress Anything For Quit\n");

}


      //this is the relation change part
int relation_change()
{
   system("cls");
    printf ("Previous Relation is;%s\n",crela);

    printf ("Enter New Relation:");
   scanf ("%s",erela);
   f2=fopen ("contact.txt","r");
   f3=fopen ("edit.txt","w+");
   while (fscanf(f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {

        fprintf (f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);

   f2=fopen ("contact.txt","w+");
   f3=fopen ("edit.txt","r");
   while (fscanf(f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {
       if (strcmp(cname,ename)==0)
       {

        fprintf (f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,erela);
         printf ("\t\tRelation Change Successfully\n");
         printf ("\t\t%s %s %s %s %s\n",cname,cnum,cemail,cadd,erela);
       }
       else

        fprintf (f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);
   remove ("edit.txt");
   printf ("\n\n\t[1] Edit Contact Again\n\t[2] Main Menu\n\t[3] See All Contact List\n\t[4] Quit\n");
   printf ("\tEnter Your Choice:");
   scanf ("%d",&n);
   if (n==1)
   editcontact ();
   else if (n==2)
    menu ();
    else if (n==3)
        list_contact();
   else
    printf ("\tPress Anything For Quit\n");

}





//here show of all contacts
int list_contact ()
{
    system ("cls");
    printf ("\t\t=========================\n");
    printf ("\t\t|  List Of All Contact  |\n");
    printf ("\t\t=========================\n");
    printf ("\n\n");
    printf ("\tName\tNumber\t\tEmail\t\tAddress\tRelation\n");
    printf ("\t====\t======\t\t=====\t\t=======\t========\n");
    f2=fopen("contact.txt","r");
    while (fscanf(f2,"%s  %s  %s  %s  %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
    {
        printf ("\t%s\t%s %s\t%s\t%s\t\n\n",cname,cnum,cemail,cadd,crela);
    }
    fclose (f2);
    printf ("\n\t\t[1] Main Menu\n\t\t[2] Quit\n");
    printf ("\t\tEnter Your choice :");
    scanf ("%d",&n);
    if (n==1)
        menu();
    else
    {
        printf ("\n\tThanks For Stay Us\n");
        printf ("\tPress Anything For Quit\n\n");
    }



}





//Contact delete part
int delete_contact ()
{
    system ("cls");
    char dname[20];
     printf ("\t\t____________________\n");
     printf ("\t\t|  Delete  Contact  |\n");
     printf ("\t\t____________________\n");
    f2=fopen("contact.txt","r");
    printf ("\n\n");
    printf ("\tName\tNumber\t\tEmail\t\tAddress\tRelation\n");
    printf ("\t----\t------\t\t-----\t\t-------\t--------\n");
    while (fscanf(f2,"%s  %s  %s  %s  %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
    {
        printf ("\t%s\t%s %s\t%s\t%s\t\n\n",cname,cnum,cemail,cadd,crela);
    }
    fclose (f2);
    printf ("\n\tEnter Which Number You want To Delete:");
    scanf ("%s",dname);
    f2=fopen ("contact.txt","r");
   f3=fopen ("edit.txt","w+");
   while (fscanf(f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {

        fprintf (f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);
    f2=fopen ("contact.txt","w+");
   f3=fopen ("edit.txt","r");
   while (fscanf(f3,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela)!=EOF)
   {
       if (strcmp(cname,dname)==0)
       {

         printf ("\t\tDlete Contact Successfully\n");

       }
       else

        fprintf (f2,"%s %s %s %s %s\n",cname,cnum,cemail,cadd,crela);
   }
   fclose(f2);
   fclose(f3);
   remove ("edit.txt");
   printf ("\n\n\t[1] Delete Contact Again\n\t[2] Main Menu\n\t[3] See All Contact List\n\t[4] Quit\n");
   printf ("\tEnter Your Choice:");
   scanf ("%d",&n);
   if (n==1)
   delete_contact ();
   else if (n==2)
    menu ();
    else if (n==3)
        list_contact();
   else
    printf ("\tPress Anything For Quit\n");

}





//here log out function
int log_out ()
{
    system ("cls");
    printf ("\n");
    printf ("\t\t=============\n");
    printf ("\t\t|  Log Out  |\n");
    printf ("\t\t=============\n");
    printf ("\n\n\n");
    printf ("\t\tLog Out Successfully\n");
    printf ("\n\t\t[1] Log In Again\n\t\t[2] Quit\n");
    printf ("\t\tEnter Your Choice:");
    scanf ("%d",&n);
    if (n==1)
        login();
    else
        printf ("\tPress Anything for Quit This system\n");
}








