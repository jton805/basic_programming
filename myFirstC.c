#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void helloWorld(){
	printf("Hello World! in C.\n");
}

void passByValue(int i){
	i = i + i;
}

void passByReferance(int * i){
	*i = *i + *i;
}

void whatsTheDifferance(){
	int i= 5;
	printf("%d\n",i++);
	
	i=5;
	printf("%d\n",++i);
	
	
	//by the way you can also do this.
	i=15;
	printf("%x\n", i);
}

void readFile(char * name){
	FILE *f;
	char *line;
	line = (char *)calloc(256,1);
	//what you saw in lectures.
	f = fopen(name, "r");
	int i=0;
	while (fscanf(f, "%s", line)!=EOF){
		printf("%d:%s ", i++, line);
	}
	memset(line, 0 ,256);
	rewind(f); //rewind to the beginning of the file.
	printf("\n");

	//Alternatives.
	fscanf(f, "%s", line); //reads first token of something.txt.
	printf("1. %s\n", line);
	memset(line, 0 ,256);
	rewind(f);
	fgets(line, 128, (FILE*)f); //reads 128 bytes from file or until it hits \n or EOF into line.
	printf("2. %s\n", line);
	memset(line, 0 ,256);
	//read file char by char.
	rewind(f);

	i=0;
	char c = '\0';
	printf("3. ");
	while(c !=EOF && i<256){
		while((c=fgetc((FILE*)f)) != '\n' && c != EOF && i<256){
			line[i++] = c;
		}
		//do something with the line we just read in.
		if(i<256){
			line[i]='\n';
		}
		printf("%s", line);
		memset(line, 0 ,256);
		i=0;		
	}
	fclose(f); //please always close the resources you are finished with.
	free(line);
	//whats the difference between these?
}

void writeFile(){
	printf("Writing to file...\n");
	FILE *f;
	f = fopen("something else.txt", "w+"); //can use a+ for appending.
	fprintf(f, "Creating a writing to a file in C.\n"); //just like printf but output goes to file instead of std out.
	fputs("another line of text.\n", f);
	fclose(f);
	printf("Done.");
}

int main(int argc, char *argv[]) {
	//this is a comment.
	helloWorld();
	printf("\n");
	int i = 5;
	passByValue(i);
	printf("%d\n", i);
	printf("\n");
	passByReferance(&i);
	printf("%d\n", i);
	printf("\n");
	whatsTheDifferance();
	printf("\n");
	readFile(argv[1]);
	printf("\n");
	writeFile();
	printf("\n");
	return 0;
}