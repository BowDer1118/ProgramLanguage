#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cases;
    int a,b,c,d,e,f,g,h,i,j;
    double average;
    int counter;
    scanf("%d",&cases);
    for(int x=1;x<=cases;x++){
        counter=0;
        scanf("%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
        average=(a+b+c+d+e+f+g+h+i+j)/10.0;
        if(a<average){
            counter++;
        }
        if(b<average){
            counter++;
        }
        if(c<average){
            counter++;
        }
        if(d<average){
            counter++;
        }
        if(e<average){
            counter++;
        }
        if(f<average){
            counter++;
        }
        if(g<average){
            counter++;
        }
        if(h<average){
            counter++;
        }
        if(i<average){
            counter++;
        }
        if(j<average){
            counter++;
        }
        printf("%d0.00%%\n",counter);
    }

    return 0;
}
