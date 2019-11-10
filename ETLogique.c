#include<stdio.h>

#define NrLigne 10
#define NrColune 7


int entres[NrLigne][NrColune] = { 
			{ 0,0 },
			{ 0,1 },
			{ 1,0 },
			{ 1,1 },

					 };
												  
int d[NrLigne] = { 0,1,1,1 };	

float wi[NrColune] = { 0,-1,0,-1 };	


void new_wi(int d,int o,int xi[]); 
float ac(int xi[]);

void training();
void test (int dep,int fin);

void new_wi(int d,int o,int xi[]){
	
	
	for(int i=0;i<NrColune;i++){
		wi[i]= wi[i] +((d-o)*xi[i]);
	}
	
	}

float ac(int xi[]){
	
	float a =0;
	
	for(int i= 0;i<NrColune;i++){a += wi[i]*xi[i];}
	     return a;
	}

void training(){
	
	float a = 0;
	int o = 0;
	int i=0 ;
	int err=0;
	
	while (i<NrLigne){

         a = ac(entres[i]);
         if(a>0)o=1;
         else o=0;

         if(o != d[i]){
              err = 1;
			 new_wi(d[i],o,entres[i]);

			 i--;

			 }
			 
			 i++;
		}
	
	if (err==1)training();
		
	}

void test (int dep,int fin){
	
	float a = 0;
	int o = 0;
	
	for (int i=dep ;i<fin+1;i++){
         a = ac(entres[i]);
         if(a>0)o=1;
         else o=0;
         printf("o ->%d",o);
        printf(" : d->(%d)\n",d[i]);

		}
	
	
	}

int main(int argc, char *argv[]){
				
	  training();
      test(0,0);
	
	}

