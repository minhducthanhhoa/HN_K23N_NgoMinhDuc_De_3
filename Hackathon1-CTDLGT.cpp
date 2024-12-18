#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;           
    struct Node* next;  
};

struct Stack {
    struct Node* top;   
    int size;           
};

void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

int isEmpty(Stack* stack) {
    return stack->size == 0;
}

void push(Stack* stack, int value) {
    struct Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
    printf("Ða them %d vao ngan xep.\n", value);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return poppedValue;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return -1;
    }
    return stack->top->data;
}

int size(Stack* stack) {
    return stack->size;
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return;
    }
    Node* current = stack->top;
    printf("Toan bo ngan xep: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void clear(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    printf("Ða xoa toan bo ngan xep.\n");
}

void reverse(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return;
    }

    Node* current = stack->top;
    int* arr = (int*)malloc(stack->size * sizeof(int));
    int i = 0;

    while (current != NULL) {
        arr[i++] = current->data;
        current = current->next;
    }

    printf("Cac phan tu theo thu tu nguoc lai: ");
    for (int j = stack->size - 1; j >= 0; j--) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    free(arr);
}

int main() {
    struct Stack stack;
    initStack(&stack);

    int choice, value;

    do {
        printf("==================MENU=================\n");
        printf("1. Them phan tu vao ngan xep (push)\n");
        printf("2. Lay phan tu khoi ngan xep (pop)\n");
        printf("3. Kiem tra phan tu tren cung ngan xep (peek/top)\n");
        printf("4. Kiem tra ngan xep co rong khong (isEmpty)\n");
        printf("5. Lay kich thuoc ngan xep (size)\n");
        printf("6. In toan bo ngan xep (display)\n");
        printf("7. Xoa toan bo ngan xep (clear)\n");
        printf("8. In cac phan tu theo thu tu nguoc lai (reverse)\n");
        printf("9. Thoat\n");
        printf("=========================================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri phan tu: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Phan tu bi lay ra: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Phan tu tren cung ngan xep: %d\n", value);
                }
                break;
            case 4:
                if (isEmpty(&stack)) {
                    printf("Ngan xep rong.\n");
                } else {
                    printf("Ngan xep khong rong.\n");
                }
                break;
            case 5:
                printf("Kich thuoc ngan xep: %d\n", size(&stack));
                break;
            case 6:
                display(&stack);
                break;
            case 7:
                clear(&stack);
                break;
            case 8:
                reverse(&stack);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }

    } while (choice != 9);

    return 0;
}

