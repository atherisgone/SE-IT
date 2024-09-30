#include <iostream>
#define HIGH 99999
using namespace std;
#include<cstring>

class MST
{
    int g[10][10],n;
    int v_array[10];
    string dept[10];
    public:
        void initialize()
        {
            cout<<"\nEnter total department: ";
            cin>>n;
            cout<<"\nEnter department names: ";
            for(int i=0;i<n;i++)
            {
                cin>>dept[i];
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<"\nEnter distance between "<<dept[i]<<" and "<<dept[j]<<": ";
                    cin>>g[i][j];
                }
            }
        }
        void display()
        {
            cout<<" ";
            for(int i=0;i<n;i++)
            {
                cout<<dept[i]<<"\t";
            }
            for(int i=0;i<n;i++)
            {
                cout<<"\n"<<dept[i];
                for(int j=0;j<n;j++)
                {
                    cout<<g[i][j]<<"\t";
                }
            }
        }
        void prims()
        {
            int cost=0;
            memset(v_array,false,sizeof(v_array));
            v_array[0]=true;
            cout<<"========================";
            cout<<"\nEdge:Weight\n";
            int n_edges=0;
            while(n_edges<n-1)
            {
                int min=HIGH;
                int r=0;
                int c=0;
                for(int i=0;i<n;i++)
                {
                    if(v_array[i])
                    {
                        for(int j=0;j<n;j++)
                        {
                            if(min>g[i][j])
                            {
                                if(!v_array[j]&&g[i][j])
                                {
                                    min=g[i][j];
                                    r=i;
                                    c=j;
                                }
                            }
                        }
                    }
                }
                cout<<"\n "<<dept[r]<<"-"<<dept[c]<<":"<<g[r][c];
                cost=cost+g[r][c];
            v_array[c]=true;
            n_edges++;
            }
            cout<<"\nCost of minimum spanning tree using Prim's: "<<cost<<"\n";
            
        }
};

int main()
{
    MST g;
    g.initialize();
    g.display();
    g.prims();


    return 0;
}
