/**
 * @author Hexin
 * @version 1.0
 */
#include <stdio.h>
int main(void) {
    int num;
    float n1,n2;
    char n3[10];

    scanf("%d",&num);
    printf("num = %d\n",num);
    scanf("%f %e",&n1,&n2);
    printf("n1 = %.2f, n2 = %.2e\n",n1,n2);
    scanf("%s",n3);
    printf("n3 = %s\n",n3);
    scanf("%s %d",n3,&num);
    printf("n3 = %s, num = %d\n",n3,num);
    scanf("catch %d",&n1);
    printf("n1 = %d\n",n1);
}