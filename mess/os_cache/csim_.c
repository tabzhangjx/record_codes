/*
*/
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h> 
#include <unistd.h>
#include "cachelab.h"
#include <math.h>
#include <memory.h>
#include <limits.h>
#define HIT 1
#define MISS 3
#define EVICTION 5

int S,E,B;
int hit=0,miss=0,eviction=0;

typedef struct{
	int valid;
	long block_address;
	int time;											/*last hit time of this block */
}cache_line; 											/*structure of cache line/block*/

cache_line *cache; 										/*the address of my simulation of cache*/

int read_cache_line(char type,long addr);
void print_help();
int main(int argc, char *argv[])
{
	int flag_v=0;										/*whether to print trace info*/
	int command;										/*the number of command line params*/
	int flag_input=0,flag_miss=0,flag_hit=0,flag_eviction=0;
	char *file_path=NULL;
	FILE *file=NULL;
	char type;											/*I,L,S,M*/
	long address;
	int size;
	int param=0;										/*the number of valgrind instruction params*/
	int result=0;										/*return number of read_cache_line function
														indicates whether there exist any 
														hits/misses/evictions in an operation.*/
	opterr=0;											/*do not print any information of getopt error*/

	if(cache) free(cache);
	cache=NULL;											/*clear the cache*/

	while((command=getopt(argc,argv,"s:E:b:t:hv"))!=-1)
	{
		switch(command)
		{
			case 's':
				S=(int)pow(2,atoi(optarg));				/*set up sets number(necessary)*/
				flag_input++;
				break;
			case 'E':		
				E=atoi(optarg);							/*set up ways number(necessary)*/
				flag_input++;
				break;
			case 'b':
				B=(int)pow(2, atoi(optarg));			/*set up block size(necessary)*/
				flag_input++;
				break;
			case 't':
				file_path=optarg;						/*get the file path(necessary)*/
				flag_input++;
				break;
			case 'v':
				flag_v=1;								/*whether to print trace info(optional)*/
				break;
			default:
				print_help();
				break;
		}
	}
	if(flag_input!=4) 									/*haven't got enough necessary params*/
	{
		print_help();
		return 0;
	}
	file=fopen(file_path,"r");
	if(!file) 
	{
		printf("invalid path\n");
		return 0;
	}
	cache=(cache_line *)malloc(S*E*sizeof(cache_line));	/*allocate space for the cache*/
	if(!cache)
	{
		printf("failed to make cache\n");
		return 0;
	}
	memset(cache,0,S * E * sizeof(cache_line));			/*initialize the cache as empty*/
	while(!feof(file))									/*read instructions*/
	{
		result=0;										/*return number of read_cache_line function 
														indicates whether there exist any 
														hits/misses/evictions in an operation.*/
		flag_eviction=0;
		flag_hit=0;
		flag_miss=0;
		param=fscanf(file," %c %lx,%x",&type,&address,&size);	/*the number of valgrind instruction params*/
		if(param!=3) continue;							/*haven't got enough necessary params*/
		if(type=='I') continue;							/*ignore I instruction in part A*/
		result=read_cache_line(type,address);			/*read an instruction*/
		if(result>5)									/*result>5 iff there exists an eviction*/
		{
			flag_eviction=1;
			eviction++;
			result-=5;									/*eliminate the effect of eviction*/
		}
		if(result>=3)									/*if there doesn't exists an eviction, 
														result>=3 iff there exists a miss*/
		{
			flag_miss=1;
			miss++;
			result-=3;									/*eliminate the effect of miss*/
		}
		if(result>=1)									/*after eliminate possible effects of miss and eviction,
														result number indicates the number of hits and 
														possible results can be 1 or 2*/
		{
			flag_hit=result;							/*number of hits in this instruction*/
			hit+=result;
		}
		if(flag_v)
		{
			printf("%c %lx,%x",type,address,size);
			if(flag_miss) printf(" miss");
			if(flag_eviction) printf(" eviction");
			if(flag_hit==1) printf(" hit");
			if(flag_hit==2) printf(" hit hit");
			printf("\n");
		}

	}
	printSummary(hit, miss, eviction);
	
	free(cache);										/*clear the cache*/
	cache=NULL;
	fclose(file);
    return 0;
}
void print_help()
{
	printf("Usage: ./csim-wrc [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n"
                   "• -h: Optional help flag that prints usage info\n"
                   "• -v: Optional verbose flag that displays trace info\n"
                   "• -s <s>: Number of set index bits (S = 2^s is the number of sets)\n"
                   "• -E <E>: Associativity (number of lines per set)\n"
                   "• -b <b>: Number of block bits (B = 2^b is the block size)\n"
                   "• -t <tracefile>: Name of the valgrind trace to replay\n");
}
/*the return number can be 	1-> 1 hit
				2-> 2 hits
				3-> 1 miss
				4-> 1 miss + 1 hit (3+1)(M instruction)
				8-> 1 miss + 1 eviction (3+5)
				9-> 1 miss + 1 eviction + 1 hit (3+5+1) (M instruction)*/
int read_cache_line(char type,long addr)
{
	long block_addr=(addr/B);
	int set_index=(int)(block_addr%S);					/*get store index in cache*/
	int eviction_index=0,								/*the least recently used block index*/
	hit_index=-1,										/*if hit , the hit index*/
	invalid_index=-1;									/*the first empty block*/
	int min_time=INT_MAX,max_time=-1;
	int i;												/*iteration variable*/
	cache_line * cache_set=cache+set_index*E;			/*cache set to store*/
	cache_line * current=NULL;							/*pointer of line being operated*/
	int flag_hit=0;										/*whether hit*/
	for(i=0;i<E;i++)
	{
		current=cache_set+i;
		if(!current->valid)
		{
			if(invalid_index==-1) invalid_index=i;		/*find the first invalid block in the set
														prepare for possible insert if not hit*/
			continue;
		}
		if(current->block_address==block_addr)			/*hit! but can not exit loop, need to find the maximum time*/
		{
			hit_index=i;
			flag_hit=1;
		}
		if(min_time>current->time) 						/*find the minimum time 
														prepare for possible eviction*/
		{
			min_time=current->time;
			eviction_index=i;
		}
		if(max_time<current->time)						/*find the maximum time to record the operation time of this block*/
			max_time=current->time;
	}
	if(flag_hit)
	{
		current=cache_set+hit_index;
		current->time=max_time+1;
		if(type=='M') return HIT+HIT;/*2*/				/*M operation will write after read on the same block,
														the second time it refers to the block, it must be the hit condition*/
		return HIT;/*1*/
	}
	if(invalid_index!=-1)
	{
		current=cache_set+invalid_index;				/*not hit, but there exists an empty block, directly insert to avoid eviction*/
		current->time=max_time+1;
		current->valid=1;
		current->block_address=block_addr;
		if(type=='M') return MISS+HIT;/*4*/
		return MISS;/*3*/
	}
	current=cache_set+eviction_index;					/*evict the least recently used block*/
	current->block_address=block_addr;
	current->time=max_time+1;
	if(type=='M') return MISS+EVICTION+HIT;/*9*/
	return MISS+EVICTION;/*8*/
}