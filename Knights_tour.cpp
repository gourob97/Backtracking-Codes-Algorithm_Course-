#include<iostream>
#define N 8
using namespace std;


bool issafe(int x,int y,int chess[N][N]);
bool  solve();
bool mainsol(int x,int y,int serial,int Xmove[],int Ymove[],int chess[N][N]);
void print(int chess[N][N]);




bool issafe(int x,int y,int chess[N][N])
{
    return(x>=0 && x<N && y>=0 && y<N && chess[x][y]==-1);

}

bool solve()
{

    int chess[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            chess[i][j]=-1;

        }
    }

    int Xmove[8]={  2, 1, -1, -2, -2, -1,  1,  2 };
   int Ymove[8]= {  1, 2,  2,  1, -1, -2, -2, -1 };

    chess[0][0]= 0;

    if(mainsol(0,0,1,Xmove,Ymove,chess)==false)
        {
           cout<<"Solution doesnot exist"<<endl;
           return false;
        }
    else{

        print(chess);
    }


}


bool mainsol(int x,int y,int serial,int Xmove[N],int Ymove[N],int chess[N][N])
{

    int x_co,y_co;

    if(serial == N*N)
        return true;



   for(int i=0;i<N;i++)
   {
       x_co=x+Xmove[i];
       y_co=y+Ymove[i];

       if(issafe(x_co,y_co,chess))
       {
           chess[x_co][y_co]=serial;

           if(mainsol(x_co,y_co,serial+1,Xmove,Ymove,chess))
               return true;


               else
            chess[x_co][y_co]=-1;

           }
       }


       return false;

   }




void print(int chess[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
}






int main()
{

    solve();
    return 0;

}
