#include<stdio.h>
#include<string.h>
#include<math.h>

enum gender{male, female};
struct student{
	int id_num;
	char name[20];
	enum gender sss;
}students[100];

void insert(int i){
	printf("\nplz input id(int), name(char) and gender(male:1,female:2):\n");
	int temp;
	scanf("%d%s%d", &students[i].id_num, students[i].name, &temp);
	if(temp==1) students[i].sss=male;
	else students[i].sss=female;
}

void display(int i){
	printf("name: %s\nid number: %d\ngender: ", students[i].name, students[i].id_num);
	if(students[i].sss==male) printf("male\n");
	else printf("female\n");
}

int main(){
  	int n;
  	printf("please input thr number of students: \n");
  	scanf("%d", &n);
  	for(int i=0;i<n;i++){
  		insert(i);
  		display(i);
  	}
 	return 0;
}