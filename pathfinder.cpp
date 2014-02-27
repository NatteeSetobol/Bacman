#include "pathfinder.h"

enum { left,right,up,down };

asa::asa()
{

}

pathfinder::pathfinder()
{
	lowestf= -1;
	openlist = new aslist;
	closelist = new aslist;
}

pathfinder::~pathfinder()
{
	

	delete openlist;
	delete closelist;

	openlist=NULL;
	closelist=NULL;	
}

aslist::aslist()
{
	head = NULL;
	tails = NULL;
	current = NULL;
	count=0;
}

int aslist::getf()
{

	return current->g+current->h;
}

int aslist::geth(int x,int y)
{
	
	return 10*(abs(x-targetx) + abs(y - targety));
}

int aslist::settarget(int tx,int ty)
{
	targetx = tx;
	targety = ty;
}

int aslist::add2lst(int x,int y, int cost)
{
	addnode();
	current->x=x;
	current->y=y;
	current->g = cost;
	current->h = geth(x,y);
	current->f = getf();
	//count++;
}

int aslist::print()
{
	node* start =head;
	//start = current;

	
	while(start != NULL)
	{
		printf("%i,%i\n",start->x,start->y);
		start = start->next;
	}

}

int lnklst::delall()
{
	node* deln=NULL;
	node* delme=NULL;


	deln = head;
	while(head != NULL)
	{
		delme = deln;		
		head = deln->next;
		deln = head;

		delme->next=NULL;
		delme->prev = NULL;
		delete delme;
		delme=NULL;
			
	}
	head=NULL;
	current = NULL;
	count =0;
	return 0;
}

lnklst::lnklst()
{

}

lnklst::~lnklst()
{	
	node* deln=NULL;
	node* delme=NULL;

	if (head != NULL)
	{
		deln = head;
		while(head != NULL)
		{
			delme = deln;
			head = deln->next;
			deln = head;
			delete delme;
			delme=NULL;
			
		}
	}
}

//1 2 3


int lnklst::delnodebyid(int id)
{
	node* deln=NULL;
	int countme=0;

	deln = head;

	while(deln != NULL)
	{
		countme++;
		if (id == deln->id)
		{
			delnode(countme);	
			break;
		}
		deln = deln->next;
		
	}
	
}

int lnklst::delnode(int nnum)
{
	node* deln=NULL;
	int tempcount=0;

	//node* delme=NULL;
	//node* temp=NULL;

	deln = head;
	if (deln == NULL)  return -1;



	while (deln->next != NULL)
	{
		tempcount++;
		if (tempcount == nnum)
		{
			if (deln == head && head->next == NULL)
			{
				head->next = NULL;
				head->prev = NULL;
				delete head;
				head = NULL;
				deln=NULL;
				
				return 1;
			} else 
			if (deln->next == NULL)
			{
				node* temp=deln->prev;
				deln->next = NULL;
				deln->prev=NULL;
				delete deln;
				deln = NULL;
				
				temp->next = NULL;
				current = temp;
				current->next = NULL;
				return 1;
			} else {
				node* temp = deln->prev;
				node* temp2 = deln->next;
				deln->prev = NULL;
				deln->next = NULL;
				delete deln;
				deln=NULL;

				temp->next = temp2;
				temp2->prev = temp;
				current = temp2;
				return 1;
			}
			break;
		}
		deln = deln->next;
	}

	return 0;
}

int lnklst::addnode()
{
	if (head == NULL)
	{
		
		head = current = new node;
		count++;
		head->id = count;
		head->prev = head;
		head->next = NULL;


	} else {
		node* tmp=head;
		node* pv=NULL;
		
		while(tmp->next)
		{
			tmp = tmp->next;
		}
		pv = tmp;
		tmp->next = new node;
		count++;
		tmp->next->id = count;
		tmp->next->prev = pv;
		tmp->next->next = NULL;
		current = tmp->next;
		
	}
	return  0;
}
