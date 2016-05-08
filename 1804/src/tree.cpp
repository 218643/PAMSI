#include "tree.hh"
#include "node.hh"
#include <iostream>




int tree::add(element el)
{
    node *temp1,*temp2;
    temp1=new node;
    temp1->el=el;
    temp1->left=&S;
    temp1->right=&S;
    temp1->up=root;
    //Jesli nie ostnieje korzen, to zamienia wezel na korzen.
    if(temp1->up==&S)
        {
        root=temp1;
        }
    else
        {
        while(1)
        {
        if(temp1->el.key < temp1->up->el.key)//porownanie kluczy korzenia i nowego elementu
            {
            if(temp1->up->left==&S)
            {
                temp1->up->left=temp1;//temp1 staje sie lewym lisciem
                break;
            }
            temp1->up=temp1->up->left;
            }
            else
            {
                if(temp1->up->right==&S)
                    {
                    temp1->up->right=temp1;//temp1 staje sie prawym lisciem
                    break;
                    }
                temp1->up=temp1->up->right;
                }
        }
        }

  //sprawdzanie spelnienia warunkow drzewa czerwono-czarnego

  temp1->black=0;//kolorujemy wstawiony wezel na czerwono
  while((temp1!=root) && (temp1->up->black==0))
    {
      if(temp1->up==temp1->up->up->left)
        {
        temp2=temp1->up->up->right;
      //przypadki "normalne", wujek jest prawym synem

            if(temp2->black==0)//Przypadek1,
            // wujek jest czerwony
            {
                temp1->up->black=1;
                temp2->black=1;
                temp1->up->up->black=0;
                temp1=temp1->up->up;
                continue;
            }

            if(temp1==temp1->up->right)//Przypadek2,
            // wujek jest czarny, a wstawiony wezel to prawy syn
            {
                temp1=temp1->up;
                leftRotate(temp1);
            }

            temp1->up->black=1;//Przypadek3,
            // wujek jest czarny, a wstawiony wezel to lewy syn
            temp1->up->up->black=0;
            rightRotate(temp1->up->up);
            break;
            }
    else//Przypadki lustrzane
	// wujek jest lewym synem
	{
	  temp2=temp1->up->up->left;

	  if(temp2->black=0)//Przypadek1
	    // wujek jest czarny, a wstawiony wezel to prawy syn
	    {
	      temp1->up->black=1;
	      temp2->black=1;
	      temp1->up->up->black=0;
	      temp1=temp1->up->up;
	      continue;
	    }

	  if(temp1==temp1->up->left)//Przypadek2
	    {
	      temp1=temp1->up;
	      rightRotate(temp1);
	    }

	  temp1->up->black=1;//Przypadek3
	  temp1->up->up->black=0;
	  leftRotate(temp1->up->up);
	  break;
	}
    }
    root->black=1;
    } ///zaKONCZENIE dodawania elelmetu

node* tree::find(int key)
{
  node* temp;
  temp=root;
  while((temp!=&S) && (temp->el.key!=key))
    if(key < temp->el.key)
      temp=temp->left;
    else
      temp=temp->right;
  if(temp==&S)
    return NULL;
  return temp;

}



void tree::leftRotate(node *A)
{
  node *C;
  node *B=A->right;
  if(B!=&S)
    {
      C=A->up;
      A->right=B->left;
      if(A->right!=&S)
	A->right->up=A;

      B->left=A;
      B->up=C;
      A->up=B;

      if(C!=&S)
	{
	  if(C->left==A)
	    C->left=B;
	  else
	    C->right=B;
	}
      else
	root=B;
    }
}



void tree::rightRotate(node *A)
{
  node *B,*C;

  B=A->left;
  if(B!=&S)
    {
      C=A->up;
      A->left=B->right;
      if(A->left!=&S)
	A->left->up=A;

      B->right=A;
      B->up=C;
      A->up=B;

      if(C!=&S)
	{
	  if(C->left==A)
	    C->left=B;
	  else
	    C->right=B;
	}
      else
	root=B;
    }
}
