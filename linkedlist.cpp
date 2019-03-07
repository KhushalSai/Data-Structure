#include<iostream>

using namespace std;

class node
{
 public:
    int prn ;
    char name[21];
    node *next;
};

class club
{
  private:
     node *head,*tail,*temp;
  public:
    club()
      {
        head=NULL;
        tail=NULL;
        temp=NULL;
      }

    void recurssive_traversal(node *tmp)
        {
            if(tmp==NULL)
            return;
            recurssive_traversal(tmp->next);
            cout<<"\n"<<tmp->prn<<"name"<<tmp->name;
        }

    void addmember();
    void displaymember();
    void count();
    void deletemember();
    void mergemember(club );
    void reversemember();


};

void club::addmember()
{
    char ch;
    int cnt=0;

    node *tmp;
    node *newnode;
    tmp=head;

    newnode= new node;
    cout<<"\n enter PRN number";
    cin>>newnode->prn;

    cout<<"\n enter name";
    cin>>newnode->name;

    cout<<"\n add as President/Secretary/Member";
    cin>>ch;

    if(ch=='p')
    {
        if(head==NULL)
        {
            head=newnode;
            newnode->next=NULL;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }

    else if(ch=='s')
    {
        if(head==NULL)
         {
              cout<<"\n list does not exists";
              return;
         }

        else
         {
           tmp=head;
           while(tmp->next!=NULL)  //for finding last node
           tmp=tmp->next;

           tmp->next=newnode;
           newnode->next=NULL;
           }
    }
    else
    {
        if(head==NULL)
        cout<<"list does not exist";

        else
        {
         while(tmp!=NULL)  //for finding last node
           {
             cnt ++;
             tmp=tmp->next;
           }
         if(cnt<2)
           {
             cout<<"\n President and Secretary should exist";
           }
         else
          {
             tmp=head;
             while((tmp->next)->next!=NULL)
             tmp=tmp->next;

             newnode->next=tmp->next;
             tmp->next=newnode;
           }
        }
    }
}

void club::displaymember()
{
     node *r;
     r=head;

     cout<<"\n ************************ \n";
     while(r!=NULL)
      {
        cout<<"\n"<<r->prn<<"name"<<r->name;
         r=r->next;
      }
      cout<<"\n ************************ \n";
}

void club :: count()
{
    int count=1;
    node *ptr;
    ptr=head;

    cout<<"\n ************************ \n";
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        count++;
    }
    cout<<"total members in the club are :"<<count;
    cout<<"\n ************************ \n";
}

void club :: deletemember()
    {
      int ch;

      node *temp;
      node *curr;
      node *temp1;

      temp=head;
      curr=head;
      temp1=head;


      cout<<"enter PRN no of student to be deleted";
      cin>>ch;


      if(ch==temp1->prn)
      {
          head=temp1->next;
          delete(temp1);
      }
      else
      {
        while((temp->next)->prn!=ch)
         {
          temp=temp->next;
         }

         curr=temp->next;
         temp->next=curr->next;
         delete(curr);
      }
    }

void club::reversemember()
 {
    recurssive_traversal(head);
    cout<<endl;
 }

void club::mergemember(club c2)
{
node *temp;
    node *curr;

    temp=head;

    while(temp->next!=NULL)
        {
            temp=temp->next;
        }
      temp->next=c2.head;

      curr=head;
      while(curr!=NULL)
      {
          cout<<"\n"<<curr->prn<<"name"<<curr->name;
          curr=curr->next;
      }
}
int main()
{
   int ch;

    club c1;
    club c2;
    club c3;




do

    {
        cout<<"\n\n 1.add members for club1";
        cout<<"\n 2.add members for club2";
        cout<<"\n 3.delete members for club1";
        cout<<"\n 4.delete members for club2";
        cout<<"\n 5.count members for club1";
        cout<<"\n 6.count members for club2";
        cout<<"\n 7.display members";
        cout<<"\n 8.display reverse order of club 1";
        cout<<"\n 9.display reverse order of club 2";
        cout<<"\n 10.merge two clubs";
        cout<<"\n 0.exit";

        cout<<"select option";
        cin>>ch;



   switch(ch)
    {
        case 1:
          {
            cout<<"\n for club 1\n";
            c1.addmember();
            break;
          }

        case 2:
          {
             cout<<"\n for club 2\n";
             c2.addmember();
             break;
           }

        case 3:
           {
             cout<<"\n for club 1\n";
             c1.deletemember();
             break;
           }

        case 4:
          {
            cout<<"\n for club 2\n";
            c2.deletemember();
            break;
           }

        case 5:
           {
                cout<<"\n for club 1\n";
                c1.count();
                break;
           }

        case 6:
            {
                cout<<"\n for club 2\n";
                 c2.count();
                 break;
            }


        case 7:
          {
              cout<<"\n for club 1\n";
              c1.displaymember();
              cout<<"\n for club 2\n";
              c2.displaymember();
              break;
          }

        case 8:
           {
                   cout<<"\n for club 1\n";
                  c1.reversemember();
                   break;
           }

        case 9:
          {
                  cout<<"\n for club 2\n";
                  c2.reversemember();
                  break;
         }

        case 10:
           {
               c1.mergemember(c2);

               break;
           }

    }

}while(ch!=0);

}

