#include<stdio.h>
#define max 5
int stack[max];
int  top=-1;
void push(){
	if(top==max-1){
		printf("Stack Overflow");
	}
	else{
		int value;
		printf("Enter Value");
		scanf("%d",&value);
		top++;
		stack[top]=value;
	printf("Value:%d",value);
	}
}
void pop(){
	if(top==-1){
		printf("Stack Underflow");
		
	}
	else{
		printf("Popped from Stack:%d",stack[top]);
		top--;
	}
}
void peek(){
	if(top=-1){
		printf("Stack is empty");
	}
	else{
		printf("Top element:%d",stack[top]);
	}
}
void display(){
	if(top==-1){
		printf("Stack is empty");
	}
	else{
		printf("Stack Elements:");
		for(int i=top;i>=0;i--){
			printf("%d",stack[i]);
		}
	}
}


int main() {
    int choice;

    do {
        printf("\n--- STACK MENU ---\n");
        printf("1. PUSH (Insert)\n");
        printf("2. POP (Remove)\n");
        printf("3. PEEK (View Top)\n");
        printf("4. DISPLAY (Show All)\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
