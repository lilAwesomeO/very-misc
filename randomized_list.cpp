#include<cstring>
#include<stdio.h>
#include<iostream>
#include<random>
using namespace std;

int copy_without_str(int count, char* str, char* cpy[], char* src[]){
	int n_index = 0;
	for(int index = 0; index < count; index++){
		if(strcmp(str,src[index]) != 0){
			cpy[n_index] = src[index];
			n_index++;
		}
	}
	return 0;
}


int main(int argc, char* args[]){	
	
	int n_count = argc-1;
	char* n_args[n_count];
	copy_without_str(argc,args[0],n_args,args);
	char* t_args[n_count];
	
	std::random_device rd;
	std::mt19937 eng(rd());

	printf("\n");

	for(int i = 0; i < n_count; i++){

		std::uniform_int_distribution<> distr(0,((n_count-1)-i));
		
		int r = distr(eng);
		char* rand_str = n_args[r];
		
		printf("\t%d:%s\n",i,rand_str);
		
		copy_without_str(n_count-i,rand_str,t_args,n_args);
		memcpy(n_args,t_args,sizeof(t_args));
	
	}

	printf("\n");

	return 0;
}
