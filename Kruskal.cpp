/// God Help Me

  /*
      Minimum Spanning Tree
      Kruskal Algorithm
      Indrojit Mondal
     Dept. of CSE, University Of Barisal
   */

#include<bits/stdc++.h>
using namespace std;
int N, E;
int Count[100];
int Set[22005][22005];
vector< pair<int, pair<int, int> > >Edge;
string str[100];
int Set_Search(int x)
{
    for(int I=1; I<=E; I++)
    {
         for(int J=1; J<=Count[I]; J++){
             if(x==Set[I][J])
               {
                   return I;
               }
         }
    }
}
int strct=0;
 int search_index(string node)
 {
  int ck=0;
   for(int I=1; I<=strct; I++)
   {
       if(str[I]==node)
       {
           ck=1;
           return I;
       }
   }
   if(ck==0)
   {
        strct=strct+1;
       str[strct]=node;
       return strct;
   }
 }
 bool sortbye(const pair<int, pair<int, int> >&a, const pair<int, pair<int, int> >&b)
 {
     return a.second.second < b.second.second;
 }
int main()
{

    int Start, End,Cost;
    //freopen("Kruskal.txt","r",stdin);
    cin>>N>>E;
    int G[100][100];
    //int Edge[100];
    set<int>Sharbikset;
    set<int> :: iterator Itr;
   // set<string> :: iterator Str;

    for(int I=1; I<=N; I++)
    {
        for(int J=1; J<=N; J++)
        {
            G[I][J]=0;
        }
    }
    int A[100];
    int B[100];
    int Node1,Node2;
    string s1,s2;
    for(int I=1; I<=E; I++)
    {
        cin>>s1>>s2>>Cost;
        Node1 = search_index(s1);

        Node2 = search_index(s2);
        //cout<<Node1<<" -> "<<Node2<<endl;
       Sharbikset.insert(Node1);
       Sharbikset.insert(Node2);
        Edge.push_back(make_pair(Node1,make_pair(Node2,Cost)));
        G[Node1][Node2]=Cost;
        G[Node2][Node1]=Cost;
    }

    /// Excess of SharbikSet
    int U[100],ct=1;
    ///int Set[100][100];

    for(Itr = Sharbikset.begin(); Itr!=Sharbikset.end(); Itr++)
    {
        //cout<< *Itr <<endl;
        U[ct++]=*Itr;

    }



    /// Sort Edge in Increasing Order
    int Min=1e9,Loc;
    int S[100];
    int Index[100];

     sort(Edge.begin(),Edge.end(),sortbye);



    int Temp1,Temp2,Sum=0;




    for(int I=1; I<=N; I++)
    {
      // V[I][1]= U[I];
       Set[I][1]=U[I];
       Count[I]=1;
    }

    cout<<endl;
    int P,Q;
    for(int I=1; I<=E; I++)
    {
        /*Temp1=A[Index[I]];
        Temp2=B[Index[I]];*/
        Temp1 = Edge[I-1].first;
        Temp2 = Edge[I-1].second.first;
        P=Set_Search(Temp1);
        Q=Set_Search(Temp2);


        if(P!=Q)
        {
            Sum+=Edge[I-1].second.second;
            cout<<str[Edge[I-1].first]<<" -> "<<str[Edge[I-1].second.first]<<endl;
            for(int J=Count[P]+1, K=1; J<=Count[P]+Count[Q], K<=Count[Q]; J++,K++ )
            {
                Set[P][J]=Set[Q][K];
                Set[Q][K]=0;
            }
            Count[P]=Count[P]+Count[Q];
        }
    }

    cout<<endl;

   cout<<"MST = "<<Sum<<endl;



    return 0;
}




