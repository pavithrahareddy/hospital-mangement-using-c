#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void add();
void view();
void edit();
void del();
typedef struct hospital
{
    char dis[200];
    char name[30];
    char test[200];
    char date[50];
    char pno[15];
    int tsfee,age,dfee,cno,pdfee;
    struct hospital *next;
}node;
node* search();
node *head=0;
node *prev;
int main()
{
     int c;
    printf("     *** WELCOME TO ***\n");
    printf("  DAYANANDA SAGAR HOSPITAL  \n");
    do
    {
        printf("\n______________________________\n\nEnter your choice please:\n\n1. Add new patient record\n2. View all records\n3. Search a patient record \n4. Edit a patient record\n5. Delete a patient record\n6. Exit\n\nOption=");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                {
                    add();
                }
            break;
            case 2:
                {
                    view();
                }
            break;
            case 3:
                {
                    node *t;
                    t=search();
                }
            break;
            case 4:
                {
                    edit();
                }
            break;
            case 5:
                {
                    del();
                }
            break;
            default:
                {printf("\nInvalid choice entered\n");
                }
        }
    }while(c>=1 && c<=5);
    printf("\n\n******* HOPE YOU HAD A GOOD DAY *******");
    return 0;
}
void add()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\n------- ENTER DETAILS ------ \n\nPatient name : ");
    scanf("%s",newnode->name);
    printf("Age : ");
    scanf("%d",&newnode->age);
    printf("Date(dd/mm/yyyy) : ");
    scanf("%s",newnode->date);
    printf("Mobile number : ");
    scanf("%s",newnode->pno);
    printf("Cabin Number : ");
    scanf("%d",&newnode->cno);
    printf("Disease : ");
    scanf("%s",newnode->dis);
    printf("Tests conducted : ");
    scanf("%s",newnode->test);
    printf("Test fee : ");
    scanf("%d",&newnode->tsfee);
    printf("Doctor fee : ");
    scanf("%d",&newnode->dfee);
    printf("Paid fee : ");
    scanf("%d",&newnode->pdfee);
    newnode->next=0;
    if(head==0)
    {
            head=newnode;
            prev=newnode;
    }
    else
    {
        prev->next=newnode;
        prev=newnode;
    }
}
void view()
{
    if(head==0)
        printf("\nNo records present\n");
    else
    {
        node *temp=head;
        printf("\n\n^^^ RECORDS PRESENT ^^^\n---------------\n");
        while(temp!=0)
        {
            printf("Name : %s\n",temp->name);
            printf("Age : %d\n",temp->age);
            printf("Date : %s\n",temp->date);
            printf("Mobile number : %s\n",temp->pno);
            printf("Cabin number : %d\n",temp->cno);
            printf("Disease : %s\n",temp->dis);
            printf("Tests Conducted : %s\n",temp->test);
            printf("Tests fee : Rs %d\n",temp->tsfee);
            printf("Doctor fee : Rs %d\n",temp->dfee);
            printf("Total fee : Rs %d\n",(temp->tsfee)+(temp->dfee));
            printf("Paid fee : Rs %d\n",temp->pdfee);
            printf("Balance fee : Rs %d\n---------------\n",(temp->tsfee)+(temp->dfee)-(temp->pdfee));
            temp=temp->next;
        }
    }
}
node* search()
{
    if(head==0)
    {
        printf("\nRecords empty!!!!\n");
        return 0;
    }
    else
    {
        int ch;
        printf("\nSearch patient deatails by :\n1. Name\n2. Age\n3. Cabin number\n4. Disease\n\nEnter your choice of search : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                char n[30];
                int i=0;
                node *temp=head;
                printf("\nEnter name : ");
                scanf("%s",n);
                while(temp!=0)
                {
                    int r;
                    r=strcmp(n,temp->name);
                    if(r==0)
                    {
                        printf("\n..................\nName : %s\n",temp->name);
                        printf("Age : %d\n",temp->age);
                        printf("Date : %s\n",temp->date);
                        printf("Mobile number : %s\n",temp->pno);
                        printf("Cabin number : %d\n",temp->cno);
                        printf("Disease : %s\n",temp->dis);
                        printf("Tests Conducted : %s\n",temp->test);
                        printf("Tests fee : Rs %d\n",temp->tsfee);
                        printf("Doctor fee : Rs %d\n",temp->dfee);
                        printf("Total fee : Rs %d\n",(temp->tsfee)+(temp->dfee));
                        printf("Paid fee : Rs %d\n",temp->pdfee);
                        printf("Balance fee : Rs %d\n..................\n",(temp->tsfee)+(temp->dfee)-(temp->pdfee));
                        i=1+1;
                        return temp;
                    }
                    temp=temp->next;
                }
                 if(i==0)
                 {
                     printf("\nRecord not found \n");
                     return 0;
                 }
            }
            break;
        case 2:
            {
                int n;
                int i=0;
                printf("\nEnter age : ");
                scanf("%d",&n);
                node *temp=head;
                while(temp!=0)
                {
                    if(temp->age==n)
                    {
                        printf("\n..................\nName : %s\n",temp->name);
                        printf("Age : %d\n",temp->age);
                        printf("Date : %s\n",temp->date);
                        printf("Mobile number : %s\n",temp->pno);
                        printf("Cabin number : %d\n",temp->cno);
                        printf("Disease : %s\n",temp->dis);
                        printf("Tests Conducted : %s\n",temp->test);
                        printf("Tests fee : Rs %d\n",temp->tsfee);
                        printf("Doctor fee : Rs %d\n",temp->dfee);
                        printf("Total fee : Rs %d\n",(temp->tsfee)+(temp->dfee));
                        printf("Paid fee : Rs %d\n",temp->pdfee);
                        printf("Balance fee : Rs %d\n..................\n",(temp->tsfee)+(temp->dfee)-(temp->pdfee));
                        i=i+1;
                        return temp;

                    }
                    temp=temp->next;
                }
                 if(i==0)
                 {
                        printf("\nRecord not found \n");
                        return 0;
                 }
            }
            break;
        case 3:
            {
                int n;
                int i=0;
                node *temp=head;
                printf("\nEnter cabin number : ");
                scanf("%d",&n);
                while(temp!=0)
                {
                    if((temp->cno)==n)
                    {
                        printf("\n..................\nName : %s\n",temp->name);
                        printf("Age : %d\n",temp->age);
                        printf("Date : %s\n",temp->date);
                        printf("Mobile number : %s\n",temp->pno);
                        printf("Cabin number : %d\n",temp->cno);
                        printf("Disease : %s\n",temp->dis);
                        printf("Tests Conducted : %s\n",temp->test);
                        printf("Tests fee : Rs %d\n",temp->tsfee);
                        printf("Doctor fee : Rs %d\n",temp->dfee);
                        printf("Total fee : Rs %d\n",(temp->tsfee)+(temp->dfee));
                        printf("Paid fee : Rs %d\n",temp->pdfee);
                        printf("Balance fee : Rs %d\n..................\n",(temp->tsfee)+(temp->dfee)-(temp->pdfee));
                        i=i+1;
                        return temp;

                    }
                    temp=temp->next;
                }
                 if(i==0)
                 {
                        return 0;
                        printf("\nRecord not found \n");
                 }
            }
            break;
        case 4:
            {
                char d[200];
                int i=0;
                node* temp=head;
                printf("\nEnter disease : ");
                scanf("%s",d);
                while(temp!=0)
                {
                    int r=strcmp(temp->dis,d);
                    if(r==0)
                    {
                        printf("\n..................\nName : %s\n",temp->name);
                        printf("Age : %d\n",temp->age);
                        printf("Date : %s\n",temp->date);
                        printf("Mobile number : %s\n",temp->pno);
                        printf("Cabin number : %d\n",temp->cno);
                        printf("Disease : %s\n",temp->dis);
                        printf("Tests Conducted : %s\n",temp->test);
                        printf("Tests fee : Rs %d\n",temp->tsfee);
                        printf("Doctor fee : Rs %d\n",temp->dfee);
                        printf("Total fee : Rs %d\n",(temp->tsfee)+(temp->dfee));
                        printf("Paid fee : Rs %d\n",temp->pdfee);
                        printf("Balance fee : Rs %d\n..................\n",(temp->tsfee)+(temp->dfee)-(temp->pdfee));
                        i=i+1;
                        return temp;
                    }
                    temp=temp->next;
                }
                 if(i==0)
                 {
                        printf("\nRecord not found \n");
                        return 0;
                 }
            }
            break;
        default:
            printf("\nInvalid choice entered \n");
        }
    }
}
void edit()
{
    node *temp=search();
    if(temp!=0)
    {
    int chh,i=0;
    do
    {
    printf("\nDetails that can be edited of the above patient:\n1. Name\n2. Age\n3. Date\n4. Cabin number\n5. Disease\n6. Tests\n7. Test fee\n8. Doctor fee\n9. Paid fee \n10. To exit\n\nEnter your choice : ");
    scanf("%d",&chh);
    switch(chh)
    {
    case 1:
        {
            printf("Previous name : %s\n",temp->name);
            printf("New name : ");
            scanf("%s",temp->name);
        }
        break;
    case 2:
        {
            printf("Previous age : %d\n",temp->age);
            printf("New age : ");
            scanf("%d",&temp->age);
        }
        break;
    case 3:
        {
            printf("Previous date : %s\n",temp->date);
            printf("New date : ");
            scanf("%s",temp->date);
        }
        break;
    case 4:
        {
            printf("Previous cabin number : %d\n",temp->cno);
            printf("New cabin number : ");
            scanf("%d",&temp->cno);
        }
        break;
    case 5:
        {
            printf("Previous disease : %s\n",temp->dis);
            printf("New disease : ");
            scanf("%s",temp->dis);
        }
        break;
    case 6:
        {
            printf("Previous Tests : %s\n",temp->test);
            printf("New Tests : ");
            scanf("%s",temp->test);
        }
        break;
    case 7:
        {
            printf("Previous Test fee : Rs %d\n",temp->tsfee);
            printf("New Test fee : ");
            scanf("%d",&temp->tsfee);
        }
        break;
    case 8:
        {
            printf("Previous Doctor fee : Rs %d\n",temp->dfee);
            printf("New Doctor fee : ");
            scanf("%d",&temp->dfee);
        }
        break;
    case 9:
        {
            printf("Previous Paid fee : Rs %d\n",temp->pdfee);
            printf("New Paid fee : ");
            scanf("%d",&temp->pdfee);
        }
    default:
        printf("Invalid choice entered\n");
    }
    }while(chh>=1 && chh<=9);
 }
}
void del()
{
   node *temp=search();
   if(temp!=0)
   {
       int choice;

       do
       {
       printf("\nDo you want to\n1. Delete whole record\n2. Delete name\n3. Delete Age\n4. Delete date\n5. Mobile number\n6. Cabin number\n7. Tests\n8. Disease\n9. Test fee\n10. Doctor fee\n11. Paid fee\n12.Stop \n\nEnter choice : ");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:
           {
               if(temp==head)
               {
                   if(temp->next==0)
                    {
                            head=0;
                            prev=0;
                        free(temp);
                    }
                    else
                        {
                        head=head->next;
                        free(temp);
                    }
               }
               else
               {
                   node *p=head;
                   while(p->next!=temp)
                   {
                       p=p->next;
                   }
                   if(temp->next==0)
                   {
                       p->next=0;
                       prev=p;
                       free(temp);
                   }
                   else
                    {
                        p->next=temp->next;
                   free(temp);

                   }

               }

           }
           break;
           case 2:
           {
               strcpy(temp->name,"--");
           }
           break;
           case 3:
           {
               temp->age=0;
           }
           break;
           case 4:
           {
               strcpy(temp->date,"--");
           }
           break;
           case 5:
           {
               strcpy(temp->pno,"--");
           }
           break;
           case 6:
           {
               temp->cno=0;
           }
           break;
           case 7:
           {
               strcpy(temp->test,"--");
           }
           break;
           case 8:
           {
               strcpy(temp->dis,"--");
           }
           break;
           case 9:
           {
               temp->tsfee=0;
           }
           break;
           case 10:
           {
               temp->dfee=0;
           }
           break;
           case 11:
           {
               temp->pdfee=0;
           }
           break;
           default:
           printf("Invalid choice entered");
       }
       }while(choice>=2 && choice<=11);
   }
}

