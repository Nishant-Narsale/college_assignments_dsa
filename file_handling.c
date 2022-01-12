#include <stdio.h>
#include <string.h>

struct Patient{
    int roomId;
    char name[20];
    int bill;
};

void takeInput(struct Patient p[], int n);
void writeFile(struct Patient p[], int n);
void displayMenu();
void display();
void search();

int main(){
    int n=0,input=1;
    printf("Enter number of patients :");
    scanf("%d",&n);
    struct Patient p[20];
    takeInput(p, n);
    writeFile(p,n);
    while(input!=0){
      displayMenu();
      printf("Enter valid option: ");
      scanf("%d",&input);
      switch (input) {
        case 0:
          break;
        case 1:
          display();
          break;
        case 2:
          printf("Enter number of patients :");
          scanf("%d",&n);
          takeInput(p, n);
          writeFile(p,n);          
          break;
        case 3:
          search();
        default:
          break;
      }
    }
    return 0;
}

void takeInput(struct Patient p[], int n){
    for(int i=0; i<n; i++){
        printf("Enter Room Id, Name, Bill respectively: ");
        scanf("%d %s %d", &p[i].roomId, p[i].name, &p[i].bill);
    }
}

void writeFile(struct Patient p[], int n){
    FILE *fp;
    fp = fopen("data.txt","a");

    if(fp==NULL){
        printf("Error");
    }else{
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%d %s %d", p[i].roomId, p[i].name, p[i].bill);
            fputs("\n",fp);
        } 
    }
    fclose(fp);
}

void display(){
  FILE *fp;
  char ch;
  fp = fopen("data.txt","r");
  if(fp == NULL){
    printf("Error");
  }else{
    printf("Id Name Bill\n");
    do 
    {
      ch = fgetc(fp);
      printf("%c",ch);
    } while(ch != EOF);
    fclose(fp);
  }
  
}

void displayMenu(){
  printf("***Menu**\n");
  printf("1) Display file data\n");
  printf("2) Enter more data\n");
  printf("3) Search for someone\n");
  printf("4) Delete a particular entry\n");
  printf("0) Enter 0 to exit\n");
}

void search(){
    char buffer[256];
	int id;
	
	FILE* fp;
	fp = fopen("data.txt", "r");

	printf("Enter room id of patient: ");
	scanf("%d",id);

	// the following loop the file fp line by line
	// each line is stored in buffer
	while (fgets(buffer, 256, fp) != NULL) {
        printf("%s\n",buffer);
	}

	fclose(fp);
}