#include<iostream>
#define V 4
using namespace std;


void print(int col[V])
{
	for (int i = 0; i < V; ++i)
	{
		cout<<col[i]<<" ";
	}

}


bool isSafe(bool graph[V][V],int v,int c,int col[V])
{
	for (int i = 0; i < V; ++i)
	{
		if(graph[v][i] && col[i]== c)
			return false;
	}

	return true;

}

bool  mainsolve(bool graph[V][V],int col[V],int m,int v)
{
    if(v==V)
    return true;

    for (int i = 1; i <= m; ++i)
       {
       	  if(isSafe(graph,v,i,col))
       	  {
       	  	col[v]=i;

       	  	if(mainsolve(graph,col,m,v+1))
       	  		return true;

           col[v]=0;
       	  }
       }
}
bool solve(bool graph[V][V],int m){

	int col[V];
	for (int i = 0; i < V; ++i)
	{
		col[i]=0;
	}



	if(mainsolve(graph,col,m,0)==false)
	{
		cout<<"Solution Does not exist";
		return false;
	}

        print(col);
		return true;

}








int main()
{
	bool graph[V][V]={{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

	int m=3;

	solve(graph,m);

}
