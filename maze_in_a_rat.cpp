#include <iostream>
#define N 4
using namespace std;

 void print(int sol[N][N])
 {
     for(int i=0;i<N;i++)
     {
         
         for(int j=0;j<N;j++){
         
        cout<<sol[i][j]<<" ";
             
         }
    cout<<endl;
     }
 }


bool isSafe(int x,int y,int maze[N][N])
{
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
    {
        return true;
    }
    return false;
}

bool solvemazeUtil(int maze[N][N],int x, int y, int sol[N][N])
{
    if(x==N-1 && y==N-1){
        
    sol[x][y]=1;
    return true;
    }
    
    if(isSafe(x,y,maze))
    {
        sol[x][y]=1;
        
        if(solvemazeUtil(maze,x,y+1,sol))
        return true;
        
        if(solvemazeUtil(maze,x+1,y,sol))
        return true;
        
        sol[x][y]=0;
        return false;
    }
    
    return false;
    
}


bool solvemaze(int maze[N][N])
{
       int sol[N][N]={
           {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0} 
       };
       
       if(solvemazeUtil(maze,0,0,sol)==false)
       {
           cout<<"Solution does not exist"<<endl;
           return false;
       }
       
       
       print(sol);
       return true;
}



int main()
{
    int maze[N][N]  =  { {1, 0, 0, 0}, 
        {1, 1, 1, 0}, 
        {1, 0, 0, 0}, 
        {1, 1, 1, 1} 
    }; 
  
    solvemaze(maze); 
    return 0; 
}
