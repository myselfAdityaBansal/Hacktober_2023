#include<iostream>
#include<cstdlib>
using namespace std;
int turn=1,p1_power=0,p2_power=0;
void print(int ar[],int ary[]){
cout<<"Current array of the players are: \n";
cout<<"Player 1 ==>  |";
for(int i=0;i<5;i++){
    if(ar[i]<=0){
        continue;
    }
cout<<ar[i]<<"|";
}
cout<<endl<<"Player 2 ==>  |";
for(int i=0;i<5;i++){
    if(ary[i]<=0){
        continue;
    }
cout<<ary[i]<<"|";
}
cout<<endl;
}
bool isemptyarray(int ar[]){
int count =0;
    for(int i=0;i<5;i++){
        if(ar[i]<=0){
            count++;
        }
    }
    if(count==5){
        return false;
    }
    return true;
}
int action(){
    int a;
cout<<"Please define whether you want to attack another player or want to defend yourself . \n";
cout<<"Enter 1 for attack or 2 for defend or 3 to use powerup. \n";
cin>>a;
while ((p1_power>0&&turn%2!=0&&a==3)||((p2_power>0&&turn%2==0&&a==3)))
{
    cout<<"Powerup has been used once. Can't used power up again.\n";
    cout<<"Available Actions are attack(1 for attack) or defend(2 for defend)\n";
    cin>>a;
}

while (a!=1&&a!=2&&a!=3)
{
    cout<<"Wrong value entered. Only Option to select is 1 or 2 or 3\n";
    cin>>a;
}
if(a==3&&turn%2!=0){
    p1_power++;
}
else if (a==3&&turn%2==0)
{
    p2_power++;
}

return a;
}
int attack(int ar[]){
    int index , value;
    cout<<"Please enter the position where you want to perform the attack: \n";
        cin>>index;
        while(ar[index-1]<=0||index<=0||index>5){
            cout<<"This position no more exists as the opponent has turned the value to 0 or below \n";
            cin>>index;
        }
    cout<<"Please enter the value which you want to subtract from the opponent: \n";
        //cin>>value;
            value=(rand()%6+1);
        cout<<value<<endl;
        while(value>6||value<=0){
            cout<<"Invalid value. Please re enter: \n";
            cin>>value;
        }
    ar[index-1]=ar[index-1]-value;
   if(ar[index-1]<=0){
        int temp = ar[index-1];
            for(int i=index;i<5;i++){
            ar[i-1]=ar[i];
            }
            ar[4]=temp;
    }
}
int defend(int ar[]){
    int index , value;
    cout<<"Please enter the position which you want to defend: \n";
        cin>>index;
        while(ar[index-1]<=0||index<=0||index>5){
        cout<<"This position no more exists as the opponent has turned the value to 0 or below \n";
        cin>>index;
        }
    cout<<"Please enter the value which you want to add at the above position: \n";
        //cin>>value;
        value=(rand()%6+1);
        cout<<value<<endl;
        while(value>6||value<=0){
            cout<<"Invalid value. Please re enter: \n";
            cin>>value;
        }
    ar[index-1]=ar[index-1]+value;
    return ar[index-1];
}
int powerup(int ar[]){
    int index;
    cout<<"Please enter the position where you want to perform the special power: \n";
        cin>>index;
        while(ar[index-1]<=0||index<=0){
            cout<<"This position no more exists as the opponent has turned the value to 0 or below \n";
            cin>>index;
        }
    ar[index-1]=ar[index-1]-(ar[index-1]+1);
   if(ar[index-1]<=0){
        int temp = ar[index-1];
        while(ar[4]!=temp){
            for(int i=index;i<5;i++){
            ar[i-1]=ar[i];
            }
            ar[4]=temp;
        }
    }
}
int winnerdecide(int ar[],int ary[]){
if(isemptyarray(ar)){
    cout<<"Player 1 Wins.";
    exit(0);
}
else if (isemptyarray(ary)){
    cout<<"Player 2 Wins.";
    exit(0);
}
}
int main(){
    cout<<"Welcome to Game Array Battle : \n";
    cout<<"Each player gets an array of size 5 . \n";
    cout<<"You have to reduce all the elements of the opponents to 0 or below that . The first one to do that wins. \n";

int ar1[5],ar2[5];
cout<<"Roll the dice 5 times and Input 5 numbers to create the array.\n";
int i=0;
while(i<5){
    //cin>>ar1[i];
    ar1[i]=(rand()%6+1);
        cout<<ar1[i]<<endl;
    while(ar1[i]>6||ar1[i]<=0){
        cout<<"The number entered is either greater than 6 or less than 0. Please re enter correct value: \n";
        //cin>>ar1[i];
    }
    ar2[i]=ar1[i];
    i++;
}
print(ar1,ar2);
while(isemptyarray(ar1)&&isemptyarray(ar2)&&turn<20){
if(turn%2!=0){
cout<<"Player 1 Turn \n";
int act=action();
if(act==1){
    attack(ar2);
}
else if(act==2){
    defend(ar1);
    }
else if(act==3){
    powerup(ar2);
    }
}
else if (turn%2==0){
 cout<<"Player 2 Turn \n";
 int act=action();

 if(act==1){
        attack(ar1);   
 }  
 else if (act==2){
    defend(ar2);
 }
 else if(act==3){
    powerup(ar1);
    }
}
print(ar1,ar2);
turn++;
}
if (turn==20){
    int sum_player1=0,sum_player2=0;
    for(int k=0;k<5;k++){
        if(ar1[k]>0||ar2[k]>0){
        sum_player1=sum_player1+ar1[k];
        sum_player2=sum_player2+ar2[k];
        }
    }
    if(sum_player1>sum_player2){
        cout<<"Maximum number of turn exceeded\n Player 1 Wins.\n Sum of Player 1 nummbers is greater than of Player2";
    }
    else if (sum_player2>sum_player1)
    {
        cout<<"Maximum number of turn exceeded\n Player 2 Wins.\n Sum of Player 2 nummbers is greater than of Player1";
    }
    else if (sum_player1==sum_player2)
    {
        cout<<"Maximum number of turn exceeded\n Game Tied.\n Sum of Player 2 nummbers is equal to Player1";
    }
}
else
{
 winnerdecide(ar1,ar2);
}
return 0;
}