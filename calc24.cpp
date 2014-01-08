#include <cstdio>
#include <cmath>
#include <cstring>
typedef int logic;

int ss[]={1234,1243,1324,1342,1423,1432, 2134,2143,2314,2341,2413,2431,
    3124,3142,3214,3241,3412,3421, 4123,4132,4213,4231,4312,4321};

int complevel(char op1, char op2)
{
    if((op1=='+'||op1=='-')&&(op2=='+'||op2=='-'))return 0;
    else if((op1=='*'||op1=='/')&&(op2=='*'||op2=='/'))return 0;
    else if((op1=='+'||op1=='-')&&(op2=='*'||op2=='/'))return -1;
    else if((op1=='*'||op1=='/')&&(op2=='+'||op2=='-'||op2=='_'))return 1;
    return -9999;
}

logic ILL,SUC;
char oper;
double op(double x, int iop, double y)
{
    double op=-9999;
    oper=' ';ILL=1;
    switch(iop)
    {
        case -1: if(x){op=y/x;oper='\\';ILL=0;}break;
        case  1: if(y){op=x/y;oper='/'; ILL=0;}break;
        case  0: op=fabs(x-y);oper=(x<y?'_':'-');ILL=0;break;
        case  2: op=x+y;oper='+';ILL=0;break;
        case  3: op=x*y;oper='*';ILL=0;break;
    }
    return op;
}

char opers[10];
logic layer(int aa,int bb,int cc,int dd)
{
    int ii,jj,kk;char output[30];
    double a=aa,b=bb,c=cc,d=dd;
    for(ii=3;ii>=-1;ii--)
        for(jj=3;jj>= 0;jj--)
            for(kk=3;kk>= 0;kk--)
            {   
                double x;
                x=op(a,kk,b);
                if(oper=='_')continue;
                opers[1]=oper;
                x=op(x,jj,c);
                if(ILL)continue;
                if(jj%2 && ii==-1)continue;
                if(oper=='_'&&(kk==2||kk==0))continue;
                opers[2]=oper;
                x=op(x,ii,d);
                if(ILL)continue;
                opers[3]=oper;
                if(fabs(x-24)<1e-8)
                {
                    if(opers[2]=='_')
                        sprintf(output,"(%d-%d%c%d)",cc,aa,opers[1],bb);
                    else if(complevel(opers[1],opers[2])>=0)
                        sprintf(output,"(%d%c%d%c%d)",aa,opers[1],bb,opers[2],cc);
                    else
                        sprintf(output,"((%d%c%d)%c%d)",aa,opers[1],bb,opers[2],cc);
                    if(opers[3]=='\\')
                        printf("%d%c%s=24",dd,'/',output);
                    else if(opers[1]=='/'&&opers[2]=='*'&&opers[3]=='*')printf("%d*%d*%d/%d=24",aa,cc,dd,bb);
                    else if(opers[2]=='/'&&opers[1]=='*'&&opers[3]=='*')printf("%d*%d*%d/%d=24",aa,bb,dd,cc);
                    else if(opers[1]=='/'&&opers[2]=='*')printf( "%d*%d/%d%c%d=24" ,aa,cc,bb,opers[3],dd);
                    else if(opers[2]=='/'&&opers[3]=='*')printf("(%d%c%d)*%d/%d=24",aa,opers[1],bb,dd,cc);
                    else if(complevel(opers[2],opers[3])>=0)
                    {
                        int len=strlen(output);
                        output[len-1]='\0';
                        printf("%s%c%d=24",output+1,opers[3],dd);
                    }
                    else
                        printf("%s%c%d=24",output,opers[3],dd);
                    return 1;
                }
            }      
    return 0;
}

int group(int aa,int bb,int cc,int dd)
{
    int ii;
    double xy=0.0,a=aa,b=bb,c=cc,d=dd;
    for(ii=1;ii<10;ii++)
    {
        switch(ii)
        {
            case  1: xy= a*b + c*d ;strcpy(opers," *+*");break;
            case  2: xy= a*b - c*d ;strcpy(opers," *-*");break;
            case  3: xy= a*b + c/d ;strcpy(opers," *+/");break;
            case  4: xy= a*b - c/d ;strcpy(opers," *-/");break;
            case  5: xy= a*b /(c+d);strcpy(opers," */+");break;
            case  6: xy= a*b /(c-d);strcpy(opers," */-");break;
            case  7: xy=(a+b)*(c+d);strcpy(opers," +*+");break;
            case  8: xy=(a+b)*(c-d);strcpy(opers," +*-");break;
            case  9: if(a>b && c>d){
                         xy=(a-b)*(c-d);strcpy(opers," -*-");break;}
        }
        if(fabs(xy-24)<1e-8)
        {
            if(ii<=4)
                printf("%d%c%d%c%d%c%d=24",aa,opers[1],bb,opers[2],cc,opers[3],dd);
            else if(ii<=6)
                printf("%d%c%d%c(%d%c%d)=24",aa,opers[1],bb,opers[2],cc,opers[3],dd);
            else
                printf("(%d%c%d)%c(%d%c%d)=24",aa,opers[1],bb,opers[2],cc,opers[3],dd);
            return 1;
        }
    }
    return 0;
}

int main( void )
{
    int unsolve=0;
    int card[4],ir,aa,bb,cc,dd;
    for(card[0]=      1; card[0]<=10; card[0]++)
        for(card[1]=card[0]; card[1]<=10; card[1]++)
            for(card[2]=card[1]; card[2]<=10; card[2]++)
                for(card[3]=card[2]; card[3]<=10; card[3]++)
                {   SUC=0;
                    printf("%d %d %d %d ",card[0],card[1],card[2],card[3]);
                    for(ir=23;ir>=0;ir--)
                    {
                        unsigned s=ss[ir];
                        aa=card[s/1000-1];
                        bb=card[s/100%10-1];
                        cc=card[s/10%10-1];
                        dd=card[s%10-1];
                        if(group(aa,bb,cc,dd))
                        {
                            SUC=1;break;
                        }
                        else if(layer(aa,bb,cc,dd))
                        {
                            SUC=1;break;
                        }
                    }
                    // if(!SUC)printf("failure(%d)",++unsolve);
                    if(!SUC)
                        printf("NoSolution %d ", 0);
                    else
                        printf(" %d ", 1);
                    printf("\n");
                }
    return 0;
}
