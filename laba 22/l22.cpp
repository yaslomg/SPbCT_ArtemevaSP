/*8. Определить в программе глобальную переменную х со значением, равным 5.
Переопределить стандартный вывод и родительского, и дочернего процессов в один и тот же файл. 
До выполнения разветвления увеличить на 1 переменную х, причем вывести ее значение, как до увеличения, так и после. 
В родительском процессе увеличить значение переменной на 2, а в дочернем уменьшить на 3. 
Вывести значение переменной до увеличения и после него внутри каждого из процессов.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <locale>

int main()
{
setlocale(LC_ALL, "rus");
int x = 5, pid;
FILE *File;
File = fopen("output.txt", "w");
fprintf(File, "Вначале x = %d\n",x);
printf("Вначале x = %d\n",x);
x++;
fprintf(File, "x после +1, x = %d\n",x);
printf("x после +1, x = %d\n",x);
pid=fork();
if (pid == 0){
fprintf(File, "\nПотомок до преобразования, x = %d\n",x);
printf("\nПотомок до преобразования, x = %d\n",x);
x-=3;
fprintf(File, "Потомок после преобразования, x = %d\n",x);//Потомок
printf("Потомок после преобразования, x = %d\n",x);
}
else if(pid > 0){ //Родитель
fprintf(File, "\nРодитель до преобразования, x = %d, pid = %d\n",x,pid);
printf("\nРодитель до преобразования, x = %d, pid = %d\n",x,pid);
x+=2;
fprintf(File, "родитель после преобразования, x = %d\n",x);
printf("родитель  после преобразования, x = %d\n",x);
sleep(5);
waitpid(pid, NULL, NULL);
}
else {
perror("Fork error ");
return -1;
}   
return 0;
}
