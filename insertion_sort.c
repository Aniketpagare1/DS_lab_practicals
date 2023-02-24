#include <stdio.h>

struct Student
{
    int student_roll_no;
    char student_name[80];
    int student_marks;
};

void accept(struct Student list[], int s);
void display(struct Student list[], int s);
void insert(struct Student arr[20], int n);
 static int count=0;
int main()
{
    struct Student data[20];
    int n;

    printf("Enter the number of students you want to insert : ");
    scanf("%d", &n);

    accept(data, n);
    insert(data,n);
    printf("\n\nSorted Table is");
    display(data, n);
    printf("\n The number of swaps are:-%d",count);

    return 0;
} 

void accept(struct Student list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\nEnter data for student #%d", i + 1);
        
        printf("\nEnter rollno : ");
        scanf("%d", &list[i].student_roll_no);

        printf("Enter name : ");
        scanf("%s", list[i].student_name);

        printf("Enter marks : ");
        scanf("%d", &list[i].student_marks);
    } 
}

void display(struct Student list[80], int s)
{
    int i;
    
    printf("\n\nRollno\tName\tMarks\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", list[i].student_roll_no, list[i].student_name, list[i].student_marks);
    } 
}

void insert(struct Student arr[20], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i].student_roll_no;
        j = i - 1;
        while (j >= 0 && arr[j].student_roll_no > key)
        {
            arr[j + 1].student_roll_no = arr[j].student_roll_no;
            j = j - 1;
            count=count+1;
        }
        arr[j + 1].student_roll_no = key;
        count=count+1;
    }
}
Output
