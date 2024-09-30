#include <iostream>
using namespace std;
#include<algorithm>
#include<string>
#define INFINITY 99999;

class Graph
{
    int q[20][20],w[20][20],n;
    string city[20];
    public:
        void initalize()
        {
            cout<<"\nEnter number of cities: ";
            cin>>n;
            cout<<"\nEnter names of cities: ";
            for(int i=0;i<n;i++)
            {
                cin>>city[i];
            }
            cout<<"\nEnter weighted matrix:\n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<"\nEnter distance between "<<city[i]<<" to "<<city[j]<<": ";
                    cin>>w[i][j];
                }
            }
            
        }

        //=========================================
        void displayWeightedMatrix()
        {
            cout<<"\nWeighted Matrix: \n ";
            for(int i=0;i<n;i++)
            {
                cout<<" "<<city[i];
            }
            cout<<"\n";
            for(int i=0;i<n;i++)
            {    
                cout<<city[i];
                for(int j=0;j<n;j++)
                {
                   cout<<" "<<w[i][j];
                }
                cout<<"\n";
            }
            
        }

        //=========================================
        int index(string str)
        {
            int i;
            for(i=0;i<n;i++)
            {
                if(str==city[i])
                {
                    
                    break;
                }
            }
            return i;
        }

        //=========================================
        void dijkstra()
        {
            string source,dest;
            int ch,si,di;
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(w[i][j]==0)
                    {
                        q[i][j]=INFINITY;
                    }
                    else
                    {
                        q[i][j]=w[i][j];
                    }
                }
                
            }
            for(int k=0;k<n;k++)
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        q[i][j]=min(q[i][j],q[i][k]+q[k][j]);
                    }
                }
            }
            cout<<"\nShortest Path Matrix:\n ";
            for(int i=0;i<n;i++)
            {
                cout<<" "<<city[i];
            }
            cout<<"\n";
            for(int i=0;i<n;i++)
            {    
                cout<<city[i];
                for(int j=0;j<n;j++)
                {
                   cout<<" "<<q[i][j];
                }
                cout<<"\n";
            }
            do
            {
                cout<<"\n1.One source to one destination Path.";
                cout<<"\n2.One source to all destination.";
                cout<<"\n3.Exit.";
                cout<<"\nEnter your choice: ";
                
                cin>>ch;
                switch(ch)
                {
                    case 1:
                            cout<<"\nEnter source and destination: ";
                            cin>>source>>dest;
                            si=index(source);
                            di=index(dest);
                            for(int i=0;i<n;i++)
                            {
                                 for(int j=0;j<n;j++)
                                {
                                    if(i==si && j==di)
                                    {
                                        cout<<"\nShortest distance from "<<city[si]<<" to "<<city[di]<<" is: "<<q[i][j];
                                    }
                                }
                                cout<<"\n";
                            }
                            break;
                    case 2:
                            cout<<"\nEnter source: ";
                            cin>>source;
                            si=index(source);
                            for(int i=0;i<n;i++)
                            {
                                 for(int j=0;j<n;j++)
                                {
                                    if(i==si)
                                    {
                                        cout<<"\nShortest distance from "<<city[si]<<" to "<<city[j]<<" is: "<<q[i][j];
                                    }
                                }
                                cout<<"\n";
                            }
                            break;
                }
            }while(ch!=3);
        }
};

//=========================================
int main()
{
    Graph g;
    g.initalize();
    g.displayWeightedMatrix();
    g.dijsktra();

    return 0;
}
