#include<bits/stdc++.h>
using namespace std;
char grid[11][11];

void print()
{

    for(int i=0;i<10;i++)
    {

        for(int j=0;j<10;j++)
        {

            cout<<grid[i][j];
        }
        cout<<"\n";
    }
}

bool canplacehorizontal(string word,int i,int j)
{
    if(j-1>=0 && grid[i][j-1]!='+')
    return false;

   if(j+word.length()<10 && grid[i][j+word.length()]!='+')
    return false;

    for(int jj=0;jj<word.length();jj++)
    {
        if(j+jj>=10)
        return false;

        if(grid[i][j+jj]=='-'|| grid[i][j+jj]==word[jj])
        continue;
        else
        return false;
    }
    return true;
}
vector<bool>placehorizontal(string word,int i,int j)
{
    vector<bool>weplace(word.length(),false);
    for(int jj=0;jj<word.length();jj++)
    {
        if(grid[i][j+jj]=='-')
        {
        grid[i][j+jj]=word[jj];
        weplace[jj]=true;
        }
    }
    return weplace;
}
void unplacehorizontal(string word,vector<bool>weplace,int i,int j){
    for(int jj=0;jj<weplace.size();jj++)
    {
        if(weplace[jj])
        {
            grid[i][j+jj]='-';
          //  weplace[jj]=false;
        }
    }

}
void unplacevertical(string word,vector<bool>weplace,int i,int j){
    for(int ii=0;ii<weplace.size();ii++)
    {
        if(weplace[ii])
        {
            grid[i+ii][j]='-';
           // weplace[ii]=false;
        }
    }

}
vector<bool>placevertical(string word,int i,int j)
{
    vector<bool>weplace(word.length(),false);
    for(int ii=0;ii<word.length();ii++)
    {
        if(grid[i+ii][j]=='-')
        {
        grid[i+ii][j]=word[ii];
        weplace[ii]=true;
        }
    }
    return weplace;
}
bool canplacevertical(string word,int i,int j)
{
    if(i-1>=0 && grid[i-1][j]!='+')
    return false;

    if(i+word.length()<10 && grid[i+word.length()][j]!='+')
    return false;

    for(int ii=0;ii<word.length();ii++)
    {
        if(i+ii>=10)
        return false;

        if(grid[i+ii][j]=='-' || grid[i+ii][j]==word[ii])
        continue;
        else
        return false;
    }
    return true;
}
void fun(vector<string>words,int idx)
{
     //cout<<"f";
    if(idx==words.size())
    {

        print();
        return;

    }

    string word=words[idx];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(grid[i][j]=='-' || grid[i][j]==word[0])
           {
            if(canplacehorizontal(word,i,j))
            {
                vector<bool>weplace=placehorizontal(word,i,j);
                fun(words,idx+1);
                unplacehorizontal(word,weplace,i,j);
            }
             if(canplacevertical(word,i,j))
            {
                vector<bool>weplace=placevertical(word,i,j);
                fun(words,idx+1);
                unplacevertical(word,weplace,i,j);
            }
          }
        }
    }
}


int main(){
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>grid[i][j];
        }
    }
   // print();
    int n;
    cin>>n;
    vector<string>words(n);
    for(int i=0;i<n;i++)
    cin>>words[i];

    fun(words,0);
    return 0;
}
