#include <iostream>
#include <string>
#include <stdlib.h>
/*
karada
mansour
harthiya
zayona
*/
#include "dqueue.h"
#include <fstream>
#include <string>
using namespace std;
struct rides {
	long int a,b,x,y; //Start Pos. End Pos.
	unsigned long int	s,f; //Start time finish time.
	bool t; //Taken
	long int dis; //Distance
	bool c; 
	long int i; //row
};
struct cars {
	long int a , b; //Start Pos.
	bool t; //Taken
	int n; //number of rides
	unsigned long int s;//current time
};

int main() {
	ifstream iFile("karada.in");
	ofstream oFile("harthiyaV4.out");
	dqueue <int> q;
	long int R,C,F,N,B;
	unsigned long int	T;
	iFile>>R>>C>>F>>N>>B>>T;
	rides * ride = new rides[N];
	rides * tempride = new rides[N]; //?
	int* sort = new int[N]; //?
while (!iFile.eof())
{	for (int i = 0 ; i < N ; i++){
		iFile>>ride[i].a>>ride[i].b>>ride[i].x>>ride[i].y>>ride[i].s>>ride[i].f;
		ride[i].t=false;
		ride[i].dis = abs(ride[i].a-ride[i].x)+abs(ride[i].b-ride[i].y);
		ride[i].i = i;
		ride[i].c = false;
	}
}
for (int i = 0 ; i < N ; i++){
		tempride[i] = ride[i];
	}
	cars * car = new cars[F];
	for (int i = 0 ; i<F ; i++){
		car[i].a = 0;
		car[i].b = 0;
		car[i].t = false;
		car[i].s = -1;
		car[i].n = 0;
	}
	for (int i = 0 ; i<N ; i++){
		//for(int j = i ; j<N; j++){
		//	if(//tempride[i].s<tempride[j].s&&
		//		//tempride[i].dis>tempride[j].dis&&
		//		//tempride[i].f<tempride[j].f&&
		//		//tempride[i].a<tempride[j].a&&
		//		//tempride[i].b<tempride[j].b&&
		//		//tempride[i].x<tempride[j].x&&
		//		//tempride[i].y<tempride[j].y&&
		//		!tempride[i].c&&!tempride[j].c){
		//			rides temp = tempride[i];
		//			tempride[i] = tempride[j];
		//		tempride[j] = temp;
		//	}
		//}
		sort[i] = tempride[i].i;
		//ride[sort[i]].c = true;
		//cout<<ride[i].s<<endl;
	}
	//int count = 0;
	//for (int i = 0 ; i<25 ; i++){
	//	//sort[i]=i;
	//	for(int j = i ; j<N; j+=25){
	//			sort[count] = tempride[j].i;
	//			//cout<<ride[sort[count]].f<<endl;
	//			count++;
	//	}
	//}
	//cout<<count<<endl;
	/*for(int i = 0 ; i<N ; i++){
		if(ride[i].x>2000||ride[i].y>2000||ride[i].a>2000||ride[i].b>2000)
			ride[i].t = true;
	}*/
	int min = abs(car[0].a-ride[sort[0]].a)+abs(car[0].b-ride[sort[0]].b);
	int r = 0; //?
	bool flag = true;
	bool flag2 = false;
	bool flag4 = false;
	int prevx = car[0].a; int prevy = car[0].b;
	//Search for Valid from O
	for( int f = 0 ; f<F ; f++){
		////Minimum
		//for(int j = 0 ; j<N ; j++){
		//		if( //((abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<min)&&
		//			!ride[sort[j]].t&&
		//			(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))+ride[sort[j]].dis+1<=ride[sort[j]].f)
		//			){
		//				if ((car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<ride[sort[j]].s)){
		//			long int dif =ride[sort[j]].s-(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b)));
		//			if( 
		//				!ride[sort[j]].t&&
		//				(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))+ride[sort[j]].dis+dif<=ride[sort[j]].f)
		//				){
		//				//cout<<dif<<endl;
		//				r = sort[j];
		//				min = abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b);
		//				//j=N+1;
		//				
		//			}}
		//				else {
		//					min = abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b);
		//			r = sort[j]; //j=N+1;
		//				}
		//		}
		//	}
		////Minimum End
		while(flag){
			if(!flag2)
			for ( int j = 0 ; j<N ; j++){
				if(
					!ride[sort[j]].t 
					&&( prevx == ride[sort[j]].a )&&( prevy == ride[sort[j]].b) && (car[f].s>=ride[sort[j]].s) ){//Ride at current Pos
					//cout<<(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<<endl;
				if(//check
					!ride[sort[j]].t&&
					(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))+ride[sort[j]].dis<=ride[sort[j]].f) //Time to get there + to deliver
					){
						//cout<<(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<<endl;
					r = sort[j];
					flag4 = true;
					//j=N+1;
					
				}}
				else	if( //((abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<min)&&
					!ride[sort[j]].t&&
					(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))+ride[sort[j]].dis+1<=ride[sort[j]].f)
					){
						if ((car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<ride[sort[j]].s)){
					long int dif =ride[sort[j]].s-(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b)));
					if( 
						!ride[sort[j]].t&&
						(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))+ride[sort[j]].dis+dif<=ride[sort[j]].f)
						){
						//cout<<dif<<endl;
						r = sort[j];
						min = abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b);
						//j=N+1;
						
					}}
						else {
							min = abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b);
					r = sort[j]; //j=N+1;
						}
				}
			}
			
			//found a valid ride
			
			flag2 = false;
			if(ride[r].t){
				break;
			}
			ride[r].t = true;
			
			bool flag3 = false;
			car[f].s += (abs(car[f].a-ride[r].a)+abs(car[f].b-ride[r].b));
			if(car[f].s<ride[r].s){car[f].s = ride[r].s;flag3=true;}
			car[f].n++;
			q.ins(r);
			prevx = ride[r].x; prevy= ride[r].y;
			if(flag3||flag4){
				car[f].s += ride[r].dis;flag4 = false;}
			else{car[f].s+=ride[r].dis+1;}
			car[f].a = ride[r].x; car[f].b = ride[r].y;
			if(car[f].s>=T){break;}
		//	//Minimum
		//for(int j = 0 ; j<N ; j++){
		//		if( //((abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<min)&&
		//			!ride[sort[j]].t&&
		//			(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))+ride[sort[j]].dis+1<=ride[sort[j]].f)
		//			){
		//				if ((car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<ride[sort[j]].s)){
		//			long int dif =ride[sort[j]].s-(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b)));
		//			if( 
		//				!ride[sort[j]].t&&
		//				(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))+ride[sort[j]].dis+dif<=ride[sort[j]].f)
		//				){
		//				//cout<<dif<<endl;
		//				r = sort[j];
		//				min = abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b);
		//				//j=N+1;
		//				
		//			}}
		//				else {
		//					min = abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b);
		//			r = sort[j]; //j=N+1;
		//				}
		//		}
		//	}
		////Minimum End
			//look for another one
			for ( int j = 0 ; j<N ; j++){
				if(!ride[sort[j]].t && ( prevx == ride[sort[j]].a )&&( prevy == ride[sort[j]].b) && (car[f].s>=ride[sort[j]].s) ){
					//cout<<(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<<endl;
				if(
					!ride[sort[j]].t&&
					(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))+ride[sort[j]].dis<=ride[sort[j]].f)
					){
					r = sort[j];
					flag2 = true;
					flag4 = true;
					//j=N+1;

				}}
				else
					if( //((abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<min)&&
					!ride[sort[j]].t&&
					(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))+ride[sort[j]].dis+1<=ride[sort[j]].f)
					){
						if (!ride[sort[j]].t && (car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))<ride[sort[j]].s)){
					long int dif =ride[sort[j]].s-(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b)));
					if(
						!ride[sort[j]].t&&
						(car[f].s+(abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b))+ride[sort[j]].dis+dif<=ride[sort[j]].f)
						){
						r = sort[j];flag2 = true;//j=N+1;
						min = abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b);
					}}
						else{
					r = sort[j];flag2 = true;//j=N+1;
					min = abs(car[f].a-ride[sort[j]].a)+abs(car[f].b-ride[sort[j]].b);
						}
				}
			}
			if(flag2){
				continue; }
			break;
		}
		if(car[f].n!=0)
			oFile<<car[f].n<<",";
		while(!q.empty_next() && !q.empty())
			oFile<<q.del()<<",";
		if(!q.empty())
			oFile<<q.del();
		if(car[f].n!=0)
			oFile<<endl;
		
	}

}
