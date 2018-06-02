#include<stdio.h>
#include<conio.h>

int n;
int nod[100], cyc[100];
char mat[100][100];
int lc;


int nodeindex(int node)
{
    int i=0;
    while(node!=nod[i])
    i++;
    return i;
}

int nodedegree(int node)
{
    int i,grad=0;
    int j=nodeindex(node);
    for(i=0;i<n;i++)
      if(mat[j][i]=='y')
        grad++;

    return grad;
}

int cycletest()
{

     int i, ok=1;
     for(i=0;i<n;i++)
     {
        if((nodedegree(nod[i])%2)!=0)
        {
           ok=0;
           break;
        }
     }
return ok;
}


int nextnode(int node)
{
    int i=0;
    int j=nodeindex(node);

    for(i=0;i<n;i++)
    {
      if(mat[j][i]=='y')
      {

        if(!edge(nod[i]))
            return nod[i];
        else
            if(lastnode(nod[i]))
            return nod[i];
      }
    }
    return -1;
}

int edge(int node)
{
    if(nodedegree(node)==1)
      return 1;
    else
      return 0;
}

int lastnode(int node)

{
    int i=0,sum=0;
    for(i=0;i<n;i++)
    {
     sum=sum+nodedegree(nod[i]);
    }
    if(sum==2)
      return 1;
    else
      return 0;
}


int visited()
{
    int i=0;
    for(i=0;i<n;i++)
    {
        if(nodedegree(nod[i])>0)
             return 0;
    }
    return 1;
}

void deledge(root,next)
{
     int i=0, j=0;
     i=nodeindex(root);
     j=nodeindex(next);
     mat[i][j]='n';
     mat[j][i]='n';
}

void eulercycle(int root)
{
     int next;
     while(!visited())
     {
        next=nextnode(root);
        cyc[lc]=next;
        lc++;
        deledge(root,next);
        root=next;
     }
}

void printcycle()
{
     int i;
     for(i=0;i<lc;i++)
     {  if(i!=lc-1)
        printf("%d -> ",cyc[i]);
        else
            printf("%d;", cyc[i]);

     }
}



int main()
{
    char val;
    int i,j;
    printf("Enter the number of nodes in a graph\n");
    scanf("%d",&n);
    printf("Enter the value of the nodes\n");

    for(i=0;i<n;i++)
        scanf("%d",&nod[i]);

    printf("Enter the value in adjancency matrix like so\n");
    printf("\nIf there is an edge between the two nodes enter 'y' else 'n'\n");

    for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
     {
      printf("%c ",val=getch());
      if(i==j)
        mat[i][j]='n';
      else
        mat[i][j]=val;
     }
      printf("\n\n");
    }

    int root;

      if(cycletest()==1) {
      root=nod[0];
      printf("The eulerian cycle is: \n");
      cyc[0]=root;
      lc++;
      eulercycle(root);
      printcycle();}
      else printf("No cycle available!");

}
