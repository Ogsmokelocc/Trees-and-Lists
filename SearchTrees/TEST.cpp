#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

vector<string> Read_File(const string& fileName, char delimiter)
{
    fstream file(fileName);
    vector<string>FileData;
    string token;

    if(file.is_open())
    {
        while(getline(file,token))
        {
            
            stringstream ss(token);
            string name;
            if(getline(ss, name, ','))
            {
                FileData.push_back(name);
            }
        }
    }

    return FileData;
};


//vector<string>ParseVector()


int main()
{
    
vector<string>FILE_DATA(Read_File("villagers",'$'));
FILE_DATA = Read_File("villagers.csv",'$');


     //cout<<FILE_DATA[1]<<" "<<endl;
    // cout<<FILE_DATA[2]<<" "<<endl;
    // cout<<FILE_DATA[3]<<" "<<endl;
    // cout<<FILE_DATA[392]<<" "<<endl;
    // cout<<FILE_DATA.size();

    // for(int i = 0; i < FILE_DATA.size(); i++)
    // {
    //     cout<<FILE_DATA[i]<<" ";
    // }


for(size_t i = 1; i<FILE_DATA.size(); i++)
{
    cout<<FILE_DATA[i]<<endl;
}

cout<<FILE_DATA.size();



    return 0;
}