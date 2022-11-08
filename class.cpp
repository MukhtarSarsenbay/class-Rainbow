#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Rainbow{
    public:
    string color;
    vector<string> colors;

    Rainbow(){//default
    }

    
   void insert(string color){
    transform(color.begin(), color.end(), color.begin(), ::tolower);
    if(color=="red" || color=="orange" || color=="yellow" || color=="green" || color=="blue" || color=="indigo" || color=="violet" )
        colors.push_back(color);
   }

   void print(){
    for(int i=0;i<colors.size();i++){
    cout<<colors[i]<<endl;
    }
   }
   Rainbow addition(Rainbow b){
        //Rainbow c.colors(colors.size() + b.colors.size());
        Rainbow c;
        int n=colors.size();
        int m=b.colors.size();
        for(int i=0;i<n+m;i++){
            c.colors.push_back(colors[i]);
        }
        for(int i=0;i<n+m;i++){
            c.colors.push_back(b.colors[i]);
        }

       sort( c.colors.begin(), c.colors.end() );
        c.colors.erase( unique( c.colors.begin(), c.colors.end() ), c.colors.end() );
        
        return c;
   }
   Rainbow intersection(Rainbow b){
    Rainbow c;
        int n=colors.size();
        int m=b.colors.size();
        for(int i=0;i<n+m;i++){
            c.colors.push_back(colors[i]);
        }
        for(int i=0;i<n+m;i++){
            c.colors.push_back(b.colors[i]);
        }

        int count=0;
        Rainbow d;
        for(int i=0;i<n+m;i++){
            for(int j=i+1;j<n+m;j++){
            if(c.colors[i]==c.colors[j]){
               d.colors.push_back(c.colors[i]);
            }
            }
        }
    
    

        return d;
   }
   

};

int main(){

Rainbow a, b, c;
a.insert("red"); a.insert("Blue"); a.insert("GreeN"); a.insert("pink");
std::cout << "Content of a: "; a.print();
std::cout << std::endl;
b.insert("Red"); b.insert("orange");
std::cout << "Content of b: "; b.print();
std::cout << std::endl;
c = a.addition(b);
std::cout << "Content of c (addition): "; c.print();
std::cout << std::endl;
c = a.intersection(b);
std::cout << "Content of c (intersection): "; c.print();
std::cout << std::endl;

}