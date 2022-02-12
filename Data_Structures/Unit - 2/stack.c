#include"stack.h"

int main()
{
    stack_t st;
    int ch, key, k;

    printf("Enter the size: ");
    scanf("%d", &st.size);

    st.s = (int *)malloc(sizeof(int) * (st.size));
    st.top = -1;

    while(1)
    {
        printf("\n1) Push");
        printf("\n2) Pop");
        printf("\n3) Display");
        printf("\n4) Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the element: ");
            scanf("%d", &key);
            push(&st, key);
            break;
        
        case 2:
            k = pop(&st);
            if (k > 0) // this is to check if the stack is not empty
                printf("\nThe element popped: %d", k);
            break;

        case 3:
            display(&st);
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice");
            break;
        }
    }
}