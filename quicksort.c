#include <stdio.h>

struct Student
{
    int student_roll_no;
    char student_name[80];
    int student_marks;
};

void accept(struct Student list[], int s);
void display(struct Student list[], int s);
void quicksort(struct Student list[],int first,int last);
int count=0;
int main()
{
    struct Student data[20];
    int n;

    printf("Enter the number of students you want to insert : ");
    scanf("%d", &n);

    accept(data, n);
    quicksort(data,0,n-1);
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

void quicksort(struct Student list[25],int first,int last){
   int i, j, pivot;
struct Student temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(list[j].student_roll_no<=list[pivot].student_roll_no&&j<last)
         i++;
         while(list[j].student_roll_no>list[pivot].student_roll_no)
         j--;
         if(i<j){
            temp=list[i];
            list[i]=list[j];
            list[j]=temp;
            
         }
      }
      temp=list[pivot];
      list[pivot]=list[j];
      list[j]=temp;
      count=count+1;
      quicksort(list,first,j-1);
      quicksort(list,j+1,last);
   }
}
