#include<iostream>
using namespace std;

void print(char o[][11]){//use print(o) to print present state
    cout<<endl<<endl<<endl;
    for(int i=0;i<11;i++){
        cout<<"   ";
        for(int j=0;j<11;j++){
            cout<<o[i][j]<<"    ";
        }
        cout<<endl<<endl;
    }
    cout<<endl<<endl<<endl;
}

void equate (char o[][11],char oo[][11]){
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            oo[i][j]=o[i][j];
        }
    }


}

int legal(char o[][11],int r,int c,int n){

if(o[r][c]!='-')return 0;
for(int i=1;i<10;i++){
    if(o[r][i]==n+48){return 0;}
}

for(int i=1;i<10;i++){
    if(o[i][c]==n+48){return 0;}
}
return 1;
}

void bita(char o[][11],int r,int c){

if(r==9&&c==9){
    for(int i=1;i<10;i++){
        if(legal(o,r,c,i)){
        char oo[11][11];
        equate(o,oo);
        oo[r][c]=i+48;
        print(oo);
        return ;
        }
    }
}
for(int i=1;i<10;i++){
    if(legal(o,r,c,i)){
        char oo[11][11];
        equate(o,oo);
        oo[r][c]=i+48;
        if(c==9)bita(oo,r+1,1);
        else bita(oo,r,c+1);
    }
}
if(o[r][c]!='-'){
    char oo[11][11];
        equate(o,oo);
        if(c==9)bita(oo,r+1,1);
        else bita(oo,r,c+1);
}



}


int main(){
char o[11][11];


for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
        o[i][j]='-';
    }
}

for(int i=0;i<11;i++){
    for(int j=0;j<11;j++){
        if(o[i][j]!='-')o[i][j]='#';
    }
}

for(int i=1;i<10;i++){
    for(int j=1;j<10;j++){
        cin>>o[i][j];
    }
}

char oo[11][11];
equate(o,oo);

bita(oo,1,1);



}
