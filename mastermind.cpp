#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<map>
using namespace std;
struct node{
	int index;
	int count;
};
int main(){
	int n,i,j,val,black,hint=0,hint_count=0;
	srand(time(0));
	cout<<"Rules be like:\n5 letter word will be given.\nBlack = correct place with correct letter\nwhite = incorrect place with correct letter\n";
	cout<<"Of course, if you get stuck you can take hint after minimum 5 five instances of trying\n";
	cout<<"1.single player\n2.2-player\n";
	cin>>n;
	switch(n){
		case 1:{
			cout<<"Welcome to play with computer\nA string has been chosen for you randomly.\n";
			string arr[38]={"house","apple","mango","witch","which","adore","agile","agree","dream","alive","allow","amaze","champ","ample","imply","charm","angel","drive",
			"eager","enjoy","faith","fancy","great","guide","grand","worth","hello","inner","jolly","magic","noble","lucky","loyal","logic","order","relax","renew","ready"};
			int index= rand()%38;
			string str=arr[index];
			cout<<str<<endl;
			map<char,node> m;
			for(i=0;i<5;i++){
				m[str[i]].index=i;
				m[str[i]].count++;
			}
			do{
			cout<<"1.Play\n2.hint\n3.Exit\n";
			cin>>val;
			switch(val){
			case 1:
				{
			string user;
			cout<<"enter your string\n";
			cin>>user;
			map<char,int> temp;
			for(i=0;i<5;i++){
				temp[str[i]]++;
			}
			black=0;
			int white=0,total=0;
			for(i=0;i<5;i++){
				if(temp[user[i]]>0 && m[user[i]].index==i){
					black++;
					temp[user[i]]--;
				}
				else if(temp[user[i]]>0 && m[user[i]].index!=i){
					white++;
					temp[user[i]]--;
				}
			}
			total=black+white;
			if(total>=3 && total<5){
				cout<<"Woah! you are near. You have "<<black<<" black and "<<white<<" whites"<<endl;
			}
			else if(total>=0 && total<3){
				cout<<"Keep trying! you can do it. You have "<<black<<" black and "<<white<<" whites"<<endl;
			}
	     	else if(black==5){
		  	cout<<"Yayyyy! you won! ";
		  	break;
	     	}
	     	hint++;
	     	if(hint==5){
	     		cout<<"you can now take hints!!!"<<endl;
	     		hint_count++;
			 }
	     	break;
	     }
	     	case 2:
	     	if(hint>=5){
	     		if(hint_count==1){
	     		cout<<"not to worry. your hints are "<<str[1]<<" at second place and "<<str[3]<<" at fourth place."<<endl;
	     		hint=0;
	     		break;
	     	}
	     	if(hint_count==2){
	     		cout<<"Its almost done!! Well trying. Your hints are "<<str[0]<<" at first place and "<<str[4]<<" at last place"<<endl;
	     		hint=0;
	     		break;
			 }
			 }else if(hint<5){
			 	cout<<"ayeee! read the rules again please xD"<<endl;
			 }
    }
	}while(val!=3 && black!=5);
	break;
}
	case 2:
		cout<<"Playing with friends is definitely awesome"<<endl;
		//can be done in similar manner
		break;
	}
	system("Pause");
	return 0;
}
