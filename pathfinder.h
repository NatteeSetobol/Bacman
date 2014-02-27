#ifndef pathfinder_H
#define pathfinder_H

#include <stdio.h>
#include <stdlib.h>

class asa
{
	public:
		bool skip;
		int id;
		int x;
		int y;
		int h;
		int g;
		int f;		
		bool is_parent;
		int parent_id;
		int direction;
		asa();

};

class node: public asa
{
	public:
		node* next;
		node* prev;
		node();
};

node::node()
{
	parent_id=0;
	is_parent=false;
	skip = false;
	direction = -1;	
}

class lnklst
{
	public:
	node* head;
	node* tails;
	node* current;
	lnklst();
	~lnklst();
	
	int delall();
	int addnode(); 
	int delnode(int nnum);
	int delnodebyid(int id);
	int count;
	
};



class aslist : public lnklst
{
	public:
	int add2lst(int x,int y, int cost);
	int print();
	int settarget(int tx,int ty);
	

	int g;
	int targetx;
	int targety;

	int geth(int x, int y);
	int getf();
	
	aslist();
		
};


class pathfinder
{
	public:
		int g;
		int h;
		int x;
		int y;
		int lowestf;
		int lowestnodeid;
		int pdirection;
		aslist* openlist;
		aslist* closelist;
		pathfinder();
		~pathfinder();			
};



#include "pathfinder.cpp"

#endif
