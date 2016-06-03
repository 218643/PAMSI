#include "lista.hh"
#include "node.hh"
#include <iostream>
using namespace std;
List::List()
{
  Size=0;
}
int List::add(int element, int position)
{
  if(size()==0) //dodawanie do pustej listy
    {
      temp=new node;
      temp->element=element;
      temp->nastepny=0;
      head=temp;
    }else // dodawanie do niepustej listy
    {
      if(position<Size+2)//dodawanie tylko jesli pozycja jest na liscie lub jedno miejsce za lista
	{
	  if(position==1)//dodawanie na pierwsze miejsce
	    {
	      temp=new node;
	      temp->element=element;
	      temp->nastepny=head;
	      head=temp;
	    }else//dodawanie na miejsce rozne od pierwszego
	    {
	      temp=head;
	      for(int i=1;i<position;i++)
		{
		  temp2=temp;
		  temp=temp->nastepny;
		}
	      temp=new node;
	      temp->nastepny=temp2->nastepny;
	      temp2->nastepny=temp;
	      temp->element=element;
	    }
	}
    }
  Size++;
}
void List::remove(int position)
{
  if(position==1)
    {
      temp=head;
      head=head->nastepny;
      delete temp;
      temp=0;
    }else
    {
      temp=head;
      for(int i=1;i<position;i++)
	{
	  temp2=temp;
	  temp=temp->nastepny;
	}
      temp2->nastepny=temp->nastepny;
      delete temp;
      temp=0;
    }
  Size--;
}
int List::get(int position)
{
  if(position==1)
    {
      return head->element;
    }else
    {
      temp=head;
      for(int i=1;i<position;i++)
	{
	  temp=temp->nastepny;
	}
      return temp->element;
    }
}
int List::size()
    {
      return Size;
    }
